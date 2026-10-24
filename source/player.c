/*
 * Player independente - interface de reproduçao
 * Nao usa SDK oficial de streaming; referencia HLS via URL
 */
#include <stdio.h>
#include <string.h>
#include "player.h"

void init_player(void)
{
    printf("[Player] Inicializado (HLS independente)\n");
}

void play_channel(const TwitchChannel *ch)
{
    if (ch == NULL) {
        printf("[Player] Erro: canal indisponivel (NULL)\n");
        return;
    }
    if (strlen(ch->stream_url) == 0) {
        printf("[Player] Erro: URL de transmissao vazia para %s\n", ch->display_name);
        return;
    }
    printf("[Player] Reproduzindo: %s (%s) - URL: %s\n",
           ch->display_name, ch->name, ch->stream_url);
    draw_player_screen(ch);
}

void stop_player(void)
{
    printf("[Player] Parado\n");
}

void draw_player_screen(const TwitchChannel *ch)
{
    /* Em build real: renderiza video via framebuffer / libimg */
    printf("[UI] Tela do player - Canal: %s | Live: %d | Views: %d\n",
           ch ? ch->display_name : "N/A", ch ? ch->live : 0, ch ? ch->viewers : 0);
}
