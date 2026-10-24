# Makefile ajustado para Linux x86-64 (OpenOrbis v0.5.4)
# Referencia de compilacao apenas — nao afirma teste no console

PS4SDK ?= $(OO_PS4_TOOLCHAIN)
ORBI_SDK ?= $(PS4SDK)

TARGET := TwitchIndiePS4.elf
PKG_NAME := TwitchIndiePS4.pkg

CC = clang
CXX = clang++
LD = lld
STRIP = llvm-strip
PKG_TOOL = $(PS4SDK)/bin/linux/PkgTool.Core

CFLAGS = -Iinclude -I$(ORBI_SDK)/include -D__PS4__ -O2 -Wall -Wextra
LDFLAGS = -L$(ORBI_SDK)/lib

OBJS = source/main.o \
       source/twitch_search.o \
       source/player.o \
       source/ui.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(TARGET)
	$(STRIP) $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

pkg: $(TARGET)
@echo "Nota: PkgTool.Core (Linux x86_64 SDK) requer arquivo .gp4; nao testado"
	mkdir -p pkg_output
	$(PKG_TOOL) pkg_build TwitchIndiePS4.gp4 pkg_output/ || echo "Falha: verifique .gp4"

clean:
	rm -f $(OBJS) $(TARGET) $(PKG_NAME)

.PHONY: all pkg clean
