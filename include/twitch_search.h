#ifndef TWITCH_SEARCH_H
#define TWITCH_SEARCH_H

#include "common.h"

/* Busca independente por nome de canal.
 * Usa conexao HTTP direta (independete de SDK da Twitch).
 * Na pratica, constroi URL de stream e faz parsing.
 */
int twitch_search(const char *query, TwitchChannel *out, int max);
void build_stream_url(const char *channel, char *url, int len);

#endif
