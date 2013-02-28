/*
 * NOTE:
 * libircii does not actually do anything with these values..
 * this is simply for code using libircii...
 */

#ifndef INCLUDED_numeric_h
#define INCLUDED_numeric_h

/*
 * Reserve numerics 000-099 for server-client connections where the client
 * is local to the server. If any server is passed a numeric in this range
 * from another server then it is remapped to 100-199. -avalon
 */
#define NUM_RPL_WELCOME          001
#define NUM_RPL_YOURHOST         002
#define NUM_RPL_CREATED          003
#define NUM_RPL_MYINFO           004

/*
 * Numeric replies from server commands.
 * These are currently in the range 200-399.
 */
#define NUM_RPL_TRACELINK        200
#define NUM_RPL_TRACECONNECTING  201
#define NUM_RPL_TRACEHANDSHAKE   202
#define NUM_RPL_TRACEUNKNOWN     203
#define NUM_RPL_TRACEOPERATOR    204
#define NUM_RPL_TRACEUSER        205
#define NUM_RPL_TRACESERVER      206
#define NUM_RPL_TRACENEWTYPE     208
#define NUM_RPL_TRACECLASS       209

#define NUM_RPL_STATSLINKINFO    211
#define NUM_RPL_STATSCOMMANDS    212
#define NUM_RPL_STATSCLINE       213
#define NUM_RPL_STATSNLINE       214
#define NUM_RPL_STATSILINE       215
#define NUM_RPL_STATSKLINE       216
#define NUM_RPL_STATSQLINE       217
#define NUM_RPL_STATSYLINE       218
#define NUM_RPL_ENDOFSTATS       219
/* note ircu uses 217 for STATSPLINE frip. conflict
 * as RPL_STATSQLINE was used in old 2.8 for Q line 
 * I'm going to steal 220 for now *sigh*
 * -Dianora
 */
#define NUM_RPL_STATSPLINE       220

#define NUM_RPL_UMODEIS          221

#define NUM_RPL_STATSFLINE       224
#define NUM_RPL_STATSDLINE       225

#define NUM_RPL_SERVLIST         234
#define NUM_RPL_SERVLISTEND      235

#define NUM_RPL_STATSLLINE       241
#define NUM_RPL_STATSUPTIME      242
#define NUM_RPL_STATSOLINE       243
#define NUM_RPL_STATSHLINE       244
#define NUM_RPL_STATSSLINE       245
#define NUM_RPL_STATSXLINE       247
#define NUM_RPL_STATSULINE       248
#define NUM_RPL_STATSDEBUG       249
#define NUM_RPL_STATSCONN        250
#define NUM_RPL_LUSERCLIENT      251
#define NUM_RPL_LUSEROP          252
#define NUM_RPL_LUSERUNKNOWN     253
#define NUM_RPL_LUSERCHANNELS    254
#define NUM_RPL_LUSERME          255
#define NUM_RPL_ADMINME          256
#define NUM_RPL_ADMINLOC1        257
#define NUM_RPL_ADMINLOC2        258
#define NUM_RPL_ADMINEMAIL       259

#define NUM_RPL_TRACELOG         261
#define NUM_RPL_ENDOFTRACE       262
#define NUM_RPL_LOAD2HI          263

#define NUM_RPL_LOCALUSERS       265
#define NUM_RPL_GLOBALUSERS      266

/* numeric_replies */

#define NUM_RPL_NONE             300
#define NUM_RPL_AWAY             301
#define NUM_RPL_USERHOST         302
#define NUM_RPL_ISON             303
#define NUM_RPL_TEXT             304
#define NUM_RPL_UNAWAY           305
#define NUM_RPL_NOWAWAY          306

#define NUM_RPL_WHOISUSER        311
#define NUM_RPL_WHOISSERVER      312
#define NUM_RPL_WHOISOPERATOR    313

#define NUM_RPL_WHOWASUSER       314
/* rpl_endofwho below (315) */
#define NUM_RPL_ENDOFWHOWAS      369

#define NUM_RPL_WHOISCHANOP      316 /* redundant and not needed but reserved */
#define NUM_RPL_WHOISIDLE        317

#define NUM_RPL_ENDOFWHOIS       318
#define NUM_RPL_WHOISCHANNELS    319

#define NUM_RPL_LISTSTART        321
#define NUM_RPL_LIST             322
#define NUM_RPL_LISTEND          323
#define NUM_RPL_CHANNELMODEIS    324

#define NUM_RPL_CREATIONTIME     329

#define NUM_RPL_NOTOPIC          331
#define NUM_RPL_TOPIC            332
#define NUM_RPL_TOPICWHOTIME     333

#define NUM_RPL_INVITING         341
#define NUM_RPL_SUMMONING        342

#define NUM_RPL_EXCEPTLIST       348
#define NUM_RPL_ENDOFEXCEPTLIST  349

#define NUM_RPL_VERSION          351

#define NUM_RPL_WHOREPLY         352
#define NUM_RPL_ENDOFWHO         315
#define NUM_RPL_NAMREPLY         353
#define NUM_RPL_ENDOFNAMES       366

#define NUM_RPL_KILLDONE         361
#define NUM_RPL_CLOSING          362
#define NUM_RPL_CLOSEEND         363
#define NUM_RPL_LINKS            364
#define NUM_RPL_ENDOFLINKS       365
/* rpl_endofnames above (366) */
#define NUM_RPL_BANLIST          367
#define NUM_RPL_ENDOFBANLIST     368
/* rpl_endofwhowas above (369) */

#define NUM_RPL_INFO             371
#define NUM_RPL_MOTD             372
#define NUM_RPL_INFOSTART        373
#define NUM_RPL_ENDOFINFO        374
#define NUM_RPL_MOTDSTART        375
#define NUM_RPL_ENDOFMOTD        376

#define NUM_RPL_YOUREOPER        381
#define NUM_RPL_REHASHING        382
#define NUM_RPL_MYPORTIS         384
#define NUM_RPL_NOTOPERANYMORE   385

#define NUM_RPL_TIME             391
#define NUM_RPL_USERSSTART       392
#define NUM_RPL_USERS            393
#define NUM_RPL_ENDOFUSERS       394
#define NUM_RPL_NOUSERS          395

/*
 * Errors are in the range from 400-599 currently and are grouped by what
 * commands they come from.
 */
#define NUM_ERR_NOSUCHNICK       401
#define NUM_ERR_NOSUCHSERVER     402
#define NUM_ERR_NOSUCHCHANNEL    403
#define NUM_ERR_CANNOTSENDTOCHAN 404
#define NUM_ERR_TOOMANYCHANNELS  405
#define NUM_ERR_WASNOSUCHNICK    406
#define NUM_ERR_TOOMANYTARGETS   407
#define NUM_ERR_NOORIGIN         409

#define NUM_ERR_NORECIPIENT      411
#define NUM_ERR_NOTEXTTOSEND     412
#define NUM_ERR_NOTOPLEVEL       413
#define NUM_ERR_WILDTOPLEVEL     414

#define NUM_ERR_UNKNOWNCOMMAND   421
#define NUM_ERR_NOMOTD           422
#define NUM_ERR_NOADMININFO      423
#define NUM_ERR_FILEERROR        424

#define NUM_ERR_NONICKNAMEGIVEN  431
#define NUM_ERR_ERRONEUSNICKNAME 432
#define NUM_ERR_NICKNAMEINUSE    433
#define NUM_ERR_NICKCOLLISION    436
#define NUM_ERR_UNAVAILRESOURCE  437
#define NUM_ERR_NICKTOOFAST	     438	/* We did it first Undernet! ;) db */

#define NUM_ERR_USERNOTINCHANNEL 441
#define NUM_ERR_NOTONCHANNEL     442
#define NUM_ERR_USERONCHANNEL    443
#define NUM_ERR_NOLOGIN          444
#define NUM_ERR_SUMMONDISABLED   445
#define NUM_ERR_USERSDISABLED    446

#define NUM_ERR_NOTREGISTERED    451

#define NUM_ERR_NEEDMOREPARAMS   461
#define NUM_ERR_ALREADYREGISTRED 462
#define NUM_ERR_NOPERMFORHOST    463
#define NUM_ERR_PASSWDMISMATCH   464
#define NUM_ERR_YOUREBANNEDCREEP 465
#define NUM_ERR_YOUWILLBEBANNED  466
#define NUM_ERR_KEYSET           467

#define NUM_ERR_CHANNELISFULL    471
#define NUM_ERR_UNKNOWNMODE      472
#define NUM_ERR_INVITEONLYCHAN   473
#define NUM_ERR_BANNEDFROMCHAN   474
#define NUM_ERR_BADCHANNELKEY    475
#define NUM_ERR_BADCHANMASK      476
#define NUM_ERR_MODELESS         477        /* ircu numeric -db */
#define NUM_ERR_BANLISTFULL      478        /* I stole the numeric from ircu -db */
#define NUM_ERR_BADCHANNAME      479

#define NUM_ERR_NOPRIVILEGES     481
#define NUM_ERR_CHANOPRIVSNEEDED 482
#define NUM_ERR_CANTKILLSERVER   483
#define NUM_ERR_DESYNC           484

#define NUM_ERR_NOOPERHOST       491

#define NUM_ERR_UMODEUNKNOWNFLAG 501
#define NUM_ERR_USERSDONTMATCH   502

#define NUM_ERR_GHOSTEDCLIENT    503
#define NUM_ERR_LAST_ERR_MSG     504

#endif /* INCLUDED_numeric_h */
