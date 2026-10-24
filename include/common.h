/*
 * TwitchIndiePS4 - Homebrew independente
 * Compilado com orbisdev / ps4toolchain (free SDK)
 * GoldHEN 12.52 / FW 12.52 - compatibilidade declarada
 * Nao testado em console - arquivo de referencia
 */
#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include <string.h>

/* Configuracao de compilacao */
#define APP_NAME        "TwitchIndie"
#define APP_VERSION     "v1.00"
#define APP_AUTHOR      "IndieDev"
#define APP_TITLE_ID    "TWIN00001"

/* Limites */
#define MAX_CHANNELS    64
#define MAX_QUERY_LEN   256
#define MAX_URL_LEN     512
#define SCREEN_W        1920
#define SCREEN_H        1080

/* Estrutura de canal */
typedef struct {
    char name[64];
    char display_name[64];
    char stream_url[MAX_URL_LEN];
    int live;
    int viewers;
} TwitchChannel;

/* Utilitarios */
void sleep_millis(int ms);

#endif
