#ifndef UI_H
#define UI_H

#include "common.h"

void init_graphics(void);
void draw_background(void);
void draw_title(void);
void draw_channel_list(const TwitchChannel *channels, int count, int selected);
void draw_error_screen(const char *message);

#endif
