/*
 * Interface propria independente - nao usa SDK de UI oficial
 */
#include <stdio.h>
#include <string.h>
#include "ui.h"

void init_graphics(void)
{
    printf("[UI] Grafica inicializada (libimg/libfont referencia)\n");
}

void draw_background(void)
{
    printf("[UI] Fundo escuro desenhado\n");
}

void draw_title(void)
{
    printf("[UI] Titulo: %s - %s (GoldHEN 12.52)\n", APP_NAME, APP_VERSION);
}

void draw_channel_list(const TwitchChannel *channels, int count, int selected)
{
    printf("[UI] Lista de canais (selecionado %d):\n", selected);
    for (int i = 0; i < count; i++) {
        char marker = (i == selected) ? '>' : ' ';
        printf("  %c %s | %s | %d viewers | %s\n",
               marker,
               channels[i].name,
               channels[i].display_name,
               channels[i].viewers,
               channels[i].live ? "LIVE" : "OFF");
    }
}

void draw_error_screen(const char *message) {
    printf("[UI] Erro: %s\n", message ? message : "Desconhecido");
}
