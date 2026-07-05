#pragma once

#include <cstdint>
#include <vector>

class Memory {
public:
    Memory();

    uint8_t Read8(uint32_t addr);
    void Write8(uint32_t addr, uint8_t value);

    uint32_t Read32(uint32_t addr);
    void Write32(uint32_t addr, uint32_t value);

private:
    std::vector<uint8_t> ram;
};
