/*	SCCS Id: @(#)color.h	3.4	1992/02/02	*/
/* Copyright (c) Steve Linhart, Eric Raymond, 1989. */
/* NetHack may be freely redistributed.  See license for details. */

#ifndef COLOR_H
#define COLOR_H

#ifdef MENU_COLOR
# ifdef MENU_COLOR_REGEX
#  ifdef NDS
#   include <pcreposix.h>
#  else
#   include <regex.h>
#  endif
# endif
#endif

/*
 * The color scheme used is tailored for an IBM PC.  It consists of the
 * standard 8 colors, folowed by their bright counterparts.  There are
 * exceptions, these are listed below.	Bright black doesn't mean very
 * much, so it is used as the "default" foreground color of the screen.
 */
#define CLR_BLACK		0
#define CLR_RED			1
#define CLR_GREEN		2
#define CLR_BROWN		3 /* on IBM, low-intensity yellow is brown */
#define CLR_BLUE		4
#define CLR_MAGENTA		5
#define CLR_CYAN		6
#define CLR_GRAY		7 /* low-intensity white */
#define NO_COLOR		8
#define CLR_ORANGE		9
#define CLR_BRIGHT_GREEN	10
#define CLR_YELLOW		11
#define CLR_BRIGHT_BLUE		12
#define CLR_BRIGHT_MAGENTA	13
#define CLR_BRIGHT_CYAN		14
#define CLR_WHITE		15
#define CLR_MAX			16

/* The "half-way" point for tty based color systems.  This is used in */
/* the tty color setup code.  (IMHO, it should be removed - dean).    */
#define BRIGHT		8

/* these can be configured */
#define HI_OBJ		CLR_MAGENTA
#define HI_METAL	CLR_CYAN
#define HI_COPPER	CLR_YELLOW
#define HI_SILVER	CLR_GRAY
#define HI_GOLD		CLR_YELLOW
#define HI_LEATHER	CLR_BROWN
#define HI_CLOTH	CLR_BROWN
#define HI_ORGANIC	CLR_BROWN
#define HI_WOOD		CLR_BROWN
#define HI_PAPER	CLR_WHITE
#define HI_GLASS	CLR_BRIGHT_CYAN
#define HI_MINERAL	CLR_GRAY
#define DRAGON_SILVER	CLR_BRIGHT_CYAN
#define HI_ZAP		CLR_BRIGHT_BLUE

#ifdef MENU_COLOR
struct menucoloring {
# ifdef MENU_COLOR_REGEX
#  ifdef MENU_COLOR_REGEX_POSIX
    regex_t match;
#  else
    struct re_pattern_buffer match;
#  endif
# else
    char *match;
# endif
    int color, attr;
    struct menucoloring *next;
};
#endif /* MENU_COLOR */

#endif /* COLOR_H */
