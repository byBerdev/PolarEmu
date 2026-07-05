#include "memory.h"

Memory::Memory() : ram(128 * 1024 * 1024, 0) {
}

uint8_t Memory::Read8(uint32_t addr) {
    if (addr < ram.size())
        return ram[addr];
    return 0;
}

void Memory::Write8(uint32_t addr, uint8_t value) {
    if (addr < ram.size())
        ram[addr] = value;
}

uint32_t Memory::Read32(uint32_t addr) {
    return Read8(addr) |
           (Read8(addr + 1) << 8) |
           (Read8(addr + 2) << 16) |
           (Read8(addr + 3) << 24);
}

void Memory::Write32(uint32_t addr, uint32_t value) {
    Write8(addr, value & 0xFF);
    Write8(addr + 1, (value >> 8) & 0xFF);
    Write8(addr + 2, (value >> 16) & 0xFF);
    Write8(addr + 3, (value >> 24) & 0xFF);
}
