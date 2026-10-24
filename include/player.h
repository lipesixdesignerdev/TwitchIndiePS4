#ifndef PLAYER_H
#define PLAYER_H

#include "common.h"

void init_player(void);
void play_channel(const TwitchChannel *ch);
void stop_player(void);
void draw_player_screen(const TwitchChannel *ch);

#endif
