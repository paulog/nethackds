
#ifndef DS_GFX_H
#define DS_GFX_H

#include "hack.h"

/*#include "tiles_bin.h"
#include "subfont_rgb_bin.h"
#include "subfont_bgr_bin.h"*/

#define C_RED		0x1
#define C_GREEN		0x2
#define C_BLUE		0x4
#define C_BRIGHT	0x8

extern u16* tiles_bin; // rambank A + BG2(96k) + event queue(1k)
	// tiles_bin extends thru most of rambank B
	// the subscreen uses up all of rambank C
extern u16* subfont_rgb_bin;	// rambank D
extern u16* subfont_bgr_bin;	// rambank D + font_rgb(16k)

extern int total_tiles_used;
// y + 32 = draw on subscreen
void draw_tile(u8 x, u8 y, u16 tile);
void draw_char(u8 x, u8 y, u8 c);
void draw_color_char(u8 x, u8 y, u8 c, u8 clr);
void draw_curs(u8 x, u8 y);
void draw_win_string(winid win, const char* s);
void render_window(winid win);
void render_all_windows();
void nds_init_fonts();
bool nds_load_kbd();	// now this is just kbd gfx
bool nds_load_tiles();
void swap_font(bool bottom);
void nds_fatal_err(const char* msg);


#endif

