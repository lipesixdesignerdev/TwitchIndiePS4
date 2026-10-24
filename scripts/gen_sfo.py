#!/usr/bin/env python3
"""
Gerador de param.sfo de referencia para PS4 homebrew.
Baseado em formato binario comum (nao garante compatibilidade 100% sem SDK oficial).
Use em conjunto com ferramentas do orbisdev (sceBbSvParamCreate) quando possivel.
"""
import struct
import sys
import os

def build_sfo(output_path, title_id="TWIN00001", content_id="IND001",
              title="Twitch Indie", version="01.00", dev_region=32768):
    # Formato simplificado: cabecalho + blocos de chave/valor
    # Referencia documental apenas
    data = bytearray()
    # Cabecalho basico
    data.extend(b"\x00\x01PSF\x01")
    # Tamanho total aproximado (sera atualizado se necessario)
    data.extend(struct.pack("<I", len(data) + 64))
    data.extend(struct.pack("<I", dev_region))
    # Chaves simplificadas (texto)
    for key, val in [(b"TITLE", title.encode()),
                     (b"TITLE_ID", title_id.encode()),
                     (b"CONTENT_ID", content_id.encode()),
                     (b"APP_VER", version.encode())]:
        data.extend(struct.pack("<I", len(key) + 1))
        data.extend(key + b"\x00")
        data.extend(struct.pack("<I", len(val) + 1))
        data.extend(val + b"\x00")
    with open(output_path, "wb") as f:
        f.write(data)
    print(f"param.sfo gerado: {output_path} (referencia)")

if __name__ == "__main__":
    out = "param.sfo"
    if len(sys.argv) > 1:
        out = sys.argv[1]
    build_sfo(out)
