/*
 * libircii.h
 * 
 * miscellaneous stuff that defines what types/etc of ircII messages
 * 
 * by Joshua J. Drake <jdrake@qoop.org>
 * IRC: jduck@EFNet
 */

#ifndef __LIBIRCII_H
#define __LIBIRCII_H

/* define the numerics */
#include "numeric.h"

#define IRCII_LIB_VERSION	"0.11"
#define IRCII_MAX_ARGS		32

/* structure for messages */
typedef struct __ircII_line_str {
   short type;
   char *from;			/* where this came from, if it is said */
   char *user, *host;		/* for clients only */
   char *targ;                  /* client, channel, or something ;) */
   unsigned short numeric;      /* numerics */
   char *msg;                   /* the payload */
} ircII;

/*
 * currently two different classes of messages
 */
#define IRCII_MT_TO_NICK	0x1000
#define IRCII_MT_TO_CHAN	0x2000

/*
 * these are the textual ircII messages
 * PRIVMSG, CTCP, NOTICE, CTCP_REPLY, MODE, JOIN, PART, QUIT, ERROR,
 * PING, PONG, NICK
 */
#define IRCII_TM_PRIVMSG	0x0000
#define IRCII_TM_CTCP		0x0001
#define IRCII_TM_NOTICE		0x0002
#define IRCII_TM_CTCP_REPLY	0x0003
#define IRCII_TM_MODE		0x0004
#define IRCII_TM_JOIN		0x0005
#define IRCII_TM_PART		0x0006
#define IRCII_TM_QUIT		0x0007
#define IRCII_TM_ERROR		0x0008
#define IRCII_TM_PING		0x0009
#define IRCII_TM_PONG		0x000a
#define IRCII_TM_NICK		0x000b
#define IRCII_TM_TOPIC		0x000c
/* update this if you add anything above it... */
#define IRCII_TM_END		0x000d

/* not to mention various numerics (%03.3d) */
#define IRCII_TM_NUMERIC	0x0800


/* strings for comparisons */
#define IRCII_STR_PRIVMSG	"PRIVMSG"
/* IRCII_STR_CTCP is an encoded PRIVMSG */
#define IRCII_STR_NOTICE	"NOTICE"
/* IRCII_STR_CTCP_REPLY is an encoded NOTICE */
#define IRCII_STR_MODE		"MODE"
#define IRCII_STR_JOIN		"JOIN"
#define IRCII_STR_PART		"PART"
#define IRCII_STR_QUIT		"QUIT"
#define IRCII_STR_ERROR		"ERROR"
#define IRCII_STR_PING		"PING"
#define IRCII_STR_PONG		"PONG"
#define IRCII_STR_NICK		"NICK"
#define IRCII_STR_TOPIC		"TOPIC"

extern char *ircii_str[];

/* prototype(s) */
int ircii_convert(char *l, ircII *p);
#ifdef DEBUG
void ircii_print(ircII i);
#endif

#endif /* __LIBIRCII_H_ */

/*
 * notes for me..
 *
 * all lines begin w/: except ERROR and PING
 *

#define IRCII_MT_PMSG         0x00000001      :nick!user@host privmsg nick :msg
#define IRCII_MT_PNOTICE      0x00000002      :nick!user@host notice nick :msg
#define IRCII_MT_PACTION      0x00000004      :nick!user@host privmsg nick :^AACTION msg^A
#define IRCII_MT_PCTCP        0x00000008      :nick!user@host privmsg nick :^Amsg^A
#define IRCII_MT_UMODE        0x00000010      :nick!user@host privmsg nick :msg
#define IRCII_MT_CMSG         0x00000020      :nick!user@host privmsg #/&chan :msg
#define IRCII_MT_CNOTICE      0x00000040      :nick!user@host notice #/&chan :msg
#define IRCII_MT_CACTION      0x00000080      :nick!user@host privmsg #/&chan :^AACTION msg^A
#define IRCII_MT_CCTCP        0x00000100      :nick!user@host privmsg #/&chan :^Amsg^A
#define IRCII_MT_JOIN         0x00000200      :nick!user@host join :#/&chan
#define IRCII_MT_PART         0x00000400      :nick!user@host part :#/&chan
#define IRCII_MT_CMODE        0x00000800      :nick!user@host mode #/&chan :msg
#define IRCII_MT_SIGNOFF      0x00001000      :nick!user@host quit :msg
#define IRCII_MT_SNOTICE      0x00002000      :server.name notice target :msg NOTICE target :msg
#define IRCII_MT_NUMERIC      0x00004000      :server.name numeric target msg
#define IRCII_MT_PONG		.........	:irc.emory.edu PONG irc.emory.edu :t3zt3r
#define IRCII_MT_ERROR        0x00008000      ERROR :msg
#define IRCII_MT_PING         0x00010000      PING :server.name
#define IRCII_MT_TOPIC	      0x00020000      :nick!user@host TOPIC #/&chan :topic
 * 
 * 
 */
