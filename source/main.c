/*
 * TwitchIndiePS4 - Homebrew independente para PS4 GoldHEN 12.52
 * Uso de SDK gratuito (orbisdev / ps4toolchain)
 */

/* APIs SDK gratuitas (orbisdev) - referencia */
/* #include <orbis/libpad.h> */
/* #include <orbis/libnet.h> */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "twitch_search.h"
#include "player.h"
#include "ui.h"

void process_input(int *selected, int *running, int count);
void init_network(void);
void cleanup_network(void);
void sleep_millis(int ms);

/*
 * Notas de compatibilidade:
 * - GoldHEN 12.52: requer compilacao com SDK atualizado para FW 12.52
 * - Este app nao usa servicos proprietarios nao disponiveis no console
 * - Nenhuma afirmacao de teste real no hardware
 */

int main(int argc, char *argv[])
{
    /* Inicializacao basica */
    init_graphics();
    init_network();

    printf("[TwitchIndie] %s %s iniciado (GoldHEN 12.52 compat)\n", APP_NAME, APP_VERSION);

    TwitchChannel channels[MAX_CHANNELS];
    memset(channels, 0, sizeof(channels));

    char query[MAX_QUERY_LEN];
    snprintf(query, sizeof(query), "indie");

    int count = twitch_search(query, channels, MAX_CHANNELS);
    printf("[Search] Encontrados %d canais para '%s'\n", count, query);

    /* Renderizacao inicial */
    draw_background();
    draw_title();

    int selected = 0;
    int running = 1;

    while (running) {
        draw_channel_list(channels, count, selected);

        /* Entrada DualShock 4 */
        process_input(&selected, &running, count);

        /* Simulacao de selecao automatica (se nenhuma entrada) */
        if (count > 0) {
            selected = (selected + 1) % count;
        }

        /* Tratamento de erro de rede / canal indisponivel */
        if (count == 0) {
            printf("[Error] Nenhum canal disponivel (rede/consulta falhou)\n");
        }

        sleep_millis(500);
    }

    cleanup_network();
    return 0;
}

/* Entrada DualShock 4 (stub de referencia) */
void process_input(int *selected, int *running, int count) {
    /* Em build real: scePadReadState() + mapear para navegacao */
    (void)selected; (void)running; (void)count;
}

void init_network(void) {
    printf("[Net] Inicializado (libnet referencia)\n");
}
void cleanup_network(void) {
    printf("[Net] Finalizado\n");
}

/* Funcoes de tempo auxiliares */
void sleep_millis(int ms) {
    /* Em compilacao orbisdev: usleep((ms) * 1000); */
    (void)ms;
}
