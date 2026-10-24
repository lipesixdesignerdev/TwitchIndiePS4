# TwitchIndiePS4 - Homebrew Independente para PS4

**Versao:** 1.00  
**Target:** GoldHEN 12.52 (referencia)  
**Status:** Arquivos reais entregues. **Nao testado em console.** Nenhuma afirmacao de funcionamento no hardware.

---

## Sobre

App independente (nao oficial) para acesso a canais e player de streams. Usa interface propria, busca por nome e referencia de URL HLS. Compilacao direcionada ao SDK gratuito `orbisdev` / `ps4toolchain`.

---

## Estrutura

```
TwitchIndiePS4/
  assets/         # icon0.png (gerado)
  include/        # Headers (common.h, twitch_search.h, player.h, ui.h)
  source/         # C de referencia (main.c, twitch_search.c, player.c, ui.c)
  scripts/        # gen_sfo.py (param.sfo de referencia)
  Makefile        # Referencia de build com orbisdev
  param.sfo       # Gerado pelo script (referencia)
  docs/
```

---

## Compilacao (referencia)

Requer instalacao do `ps4toolchain` / `orbisdev` (SDK gratuito).

```bash
export PS4SDK=/caminho/ps4sdk/bin
export ORBI_SDK=/caminho/orbisdev/lib
make
make pkg  # Gera TwitchIndiePS4.pkg (se pkg_build disponivel)
```

Se nao tiver o SDK instalado, **os arquivos C ainda sao entregues** como referencia para compilacao posterior.

---

## Limitacoes Reais

- **Nao foi testado no console PS4** (GoldHEN 12.52 ou qualquer outro).
- `param.sfo` gerado pelo script Python e uma referencia; para PKG oficial (instalavel) e necessario o SDK completo com ferramentas da Sony/ou orbisdev.
- `twitch_search.c` usa dados locais de exemplo; uma implementacao real exigiria conexao de rede no console e tratamento de tokens HLS.
- `player.c` e uma interface de referencia; reproduzir stream real exige integracao com libvideo/libnet no SDK.

---

## Arquivos Entregues (reais)

- `assets/icon0.png` - gerado com Python PIL (128x128)
- `source/*.c` - implementacoes de referencia
- `include/*.h` - cabecalhos
- `Makefile` - script de build
- `param.sfo` - arquivo binario de referencia
- `scripts/gen_sfo.py` - gerador do param.sfo
- `docs/README.md` - esta documentacao

---

## Aviso Importante

Este projeto nao afirma compatibilidade garantida com GoldHEN 12.52, nem com qualquer firmware PS4. Os arquivos sao uma base tecnica de referencia para desenvolvimento de homebrew independente.
