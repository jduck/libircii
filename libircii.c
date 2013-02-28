/*
 * libircii.c
 *
 * parse lines from irc into some nice stuff..
 * 
 * by Joshua J. Drake <jdrake@qoop.org>
 * IRC: jduck@EFNet
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "libircii.h"

/*
 * this string array is for getting type->text
 */
char *ircii_str[IRCII_TM_END] = {
   IRCII_STR_PRIVMSG, 
   "CTCP",
   IRCII_STR_NOTICE,
   "CTCP REPLY",
   IRCII_STR_MODE,
   IRCII_STR_JOIN,
   IRCII_STR_PART,
   IRCII_STR_QUIT,
   IRCII_STR_ERROR,
   IRCII_STR_PING,
   IRCII_STR_PONG,
   IRCII_STR_NICK
};

/*
 * skip whitespace
 * 
 * return a pointer to the first occurance of non-whitespace
 * if the entire string is whitespace, return NULL
 */
char *
skip_space(char *s)
{
   char *p;
   
   for (p = s; p && *p; p++)
     if (!isspace(*p))
       return p;
   return NULL;
}

/*
 * skip to next after whitespace
 * 
 * a. look for a whitespace character... if we reach the end of the string before we find
 *    one, return NULL
 * b. place a \0 in the place of the first found whitespace character.
 * c. look for a non-whitespace character... if we find one, return a pointer to it.
 * d. if we reach the end of the string before we find some non-whitespace, return NULL
 * 
 */
char *
skip_to_next(char *s)
{
   char *p;
   
   /* look for whitespace */
   for (p = s; p && *p; p++)
     {
	if (isspace(*p))
	  {
	     *p++ = '\0';
	     break;
	  }
     }
   
   /* look for non-whitespace */
   if (p && *p)
     return skip_space(p);

   /* looks like we either didn't find any, or we didn't 
    * find anything after what we did find.
    */
   return NULL;
}

/*
 * convert a line supposedly from an ircII server into
 * some nice usable structured data
 * 
 * returns:
 * -1 on malformed data being passed in, and 1 on success
 */
int
ircii_convert(char *l, ircII *p)
{
   char *user, *host, *type, *to, *args, *q, *s, *t;
   
   if (!l)
     return 0;

   memset(p, 0, sizeof(ircII));

   if (!l || !*l || !(q = skip_space(l)))
     return -1;
   
   switch (*q)
     {
      case 'N':
	to = skip_to_next(q);
	if (!to || !*to)
	  return -1;
	if (strcmp(q, IRCII_STR_NOTICE) == 0)
	  {
	     if (!(args = skip_to_next(to)))
	       return -1;
	     p->type = IRCII_TM_NOTICE;
	     p->targ = to;
	     if (*args == ':')
	       p->msg = args + 1;
	     else
	       p->msg = args;
	     break;
	  }
	return -1;
	
      case 'E':
	args = skip_to_next(q);
	if (!args || !*args)
	  return -1;
	if (strcmp(q, IRCII_STR_ERROR) == 0)
	  {
	     p->type = IRCII_TM_ERROR;
	     if (args && *args == ':')
	       args++;
	     p->msg = args;
	     break;
	  }
	return -1;
	
      case 'P':
	args = skip_to_next(q);
	if (!args || !*args)
	  return -1;
	if (strcmp(q, IRCII_STR_PING) == 0)
	  {
	     p->type = IRCII_TM_PING;
	     if (args && *args == ':')
	       args++;
	     p->msg = args;
	     break;
	  }
	return -1;
	
      case ':':
	if (!(q+1) || !(*(q+1)))
	  return -1;
	p->from = q + 1;
	type = skip_to_next(p->from);
	user = index(q, '!');
	host = index(q, '@');
	if (user && *user && host && *host)
	  {
	     if (host <= user)
	       return -1;
	     *user++ = '\0';
	     *host++ = '\0';
	     p->user = user;
	     p->host = host;
	  }
	
	/* nasty string comparison stuff */
	to = skip_to_next(type);
	if (!to || !*to)
	  return -1;
	if (strcmp(type, IRCII_STR_PRIVMSG) == 0)
	  {
	     if (!(args = skip_to_next(to)))
	       return -1;
	     p->targ = to;
	     s = strchr(args, '\001');
	     t = strrchr(args, '\001');
	     if (s && t && s != t)
	       {
		  *t = '\0';
		  p->type = IRCII_TM_CTCP;
		  p->msg = s;
	       }
	     else if (*args == ':' && (args+1) && *(args+1))
	       {
		  p->type = IRCII_TM_PRIVMSG;
		  p->msg = args+1;
	       }
	     else
	       {
		  p->type = IRCII_TM_PRIVMSG;
		  p->msg = args;
	       }
	  }
	else if (strcmp(type, IRCII_STR_NOTICE) == 0)
	  {
	     if (!(args = skip_to_next(to)))
	       return -1;
	     p->targ = to;
	     s = strchr(args, '\001');
	     t = strrchr(args, '\001');
	     if (s && t && s != t)
	       {
		  *t = '\0';
		  p->type = IRCII_TM_CTCP_REPLY;
		  p->msg = s;
	       }
	     else
	       {
		  p->type = IRCII_TM_NOTICE;
		  if (*args == ':' && (args+1) && *(args+1))
		    args++;
		  p->msg = args;
	       }
	  }
	else if (strcmp(type, IRCII_STR_MODE) == 0)
	  {
	     if (!(args = skip_to_next(to)))
	       return -1;
	     p->targ = to;
	     p->type = IRCII_TM_MODE;
	     p->msg = args;
	  }
	else if (strcmp(type, IRCII_STR_JOIN) == 0)
	  {
	     p->type = IRCII_TM_JOIN;
	     p->targ = *to == ':' ? to+1 : to;
	  }
	else if (strcmp(type, IRCII_STR_PART) == 0)
	  {
	     p->type = IRCII_TM_PART;
	     p->targ = *to == ':' ? to+1 : to;
	  }
	else if (strcmp(type, IRCII_STR_QUIT) == 0)
	  {
	     p->type = IRCII_TM_QUIT;
	     p->msg = *to == ':' ? to+1 : to;
	  }
	else if (strcmp(type, IRCII_STR_PONG) == 0)
	  {
	     p->type = IRCII_TM_PONG;
	     p->msg = *to == ':' ? to+1 : to;
	  }
	else if (strcmp(type, IRCII_STR_NICK) == 0)
	  {
	     p->type = IRCII_TM_NICK;
	     p->msg = *to == ':' ? to+1 : to;
	  }
	else if (isdigit(*type) && atoi(type) > 0)
	  {
	     p->type = IRCII_TM_NUMERIC;
	     p->numeric = atoi(type);
	     if (!(args = skip_to_next(to)))
	       return -1;
	     if (*args == ':' && (args+1) && *(args+1))
	       args++;
	     p->msg = args;
	     p->targ = to;
	  }
	else
	  return -1;
	break;
	
      default:
	printf("Unknown message beginning: %s\n", q);
	return -1;
     }
   return 1;
}

#ifdef DEBUG
/*
 * print out the contents of an ircII struct
 */
void
ircii_print(ircII i)
{
   char tb[12], tb2[4096];
   int uh = 0;
   
   memset(tb, 0, sizeof(tb));
   switch (i.type)
     {
      case IRCII_TM_NUMERIC:
	sprintf(tb, "NUMERIC: %03d", i.numeric);
	break;
      default:
	if (i.type >= 0 && i.type < IRCII_TM_END)
	  strcpy(tb, ircii_str[i.type]);
	else
	  printf("Unknown type: 0x%x\n", i.type);
	break;
     }
   
   memset(tb2, 0, sizeof(tb2));
   if (i.user && i.host)
     uh = 1;
   snprintf(tb2, sizeof(tb2)-1, "%-12.12s%s%s%s%s%s%s%s%s%s%s%s", tb,
	    i.from ? " from " : "", i.from ? i.from : "",
	    uh ? " (" : "", uh ? i.user : "", uh ? "@" : "", uh ? i.host : "", uh ? ")" : "",
	    i.targ ? " to " : "", i.targ ? i.targ : "",
	    i.msg ? ": " : "", i.msg ? i.msg : "");
   puts(tb2);
}
#endif
