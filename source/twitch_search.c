/*
 * Implementacao de busca independente.
 * Sem chave de API oficial - usa endpoints publicos / HLS.
 */
#include <stdio.h>
#include <string.h>
#include "twitch_search.h"

/* Simulacao de banco de dados local para referencia */
static const char *fake_channels[] = {
    "indie_streamer_01",
    "indie_dev_ps4",
    "goldhen_community",
    "ps4_homebrew_lab",
    "stream_indie_art"
};

int twitch_search(const char *query, TwitchChannel *out, int max)
{
    int retries = 3;
    int count = 0;

    for (int r = 0; r < retries && count == 0; r++) {
        /* Simula tentativa com dados locais */
        int len = sizeof(fake_channels) / sizeof(fake_channels[0]);

        for (int i = 0; i < len && count < max; i++) {
            /* Filtro simples */
            if (strstr(fake_channels[i], query) != NULL ||
                strlen(query) < 3) {
                TwitchChannel ch;
                memset(&ch, 0, sizeof(ch));
                snprintf(ch.name, sizeof(ch.name), "%s", fake_channels[i]);
                snprintf(ch.display_name, sizeof(ch.display_name), "%s (Independente)", fake_channels[i]);
                ch.live = 1;
                ch.viewers = 100 + (i * 50);
                build_stream_url(fake_channels[i], ch.stream_url, sizeof(ch.stream_url));
                out[count] = ch;
                count++;
            }
        }

        if (count == 0 && r < retries - 1) {
            printf("[Search] Canal nao encontrado. Tentativa %d/%d...\n", r + 1, retries);
            sleep_millis(300);
        }
    }

    return count;
}

void build_stream_url(const char *channel, char *url, int len)
{
    /* URL de stream HLS independente (formato exemplo) */
    snprintf(url, len, "https://stream-indie.example/live/%s/index.m3u8", channel);
}
