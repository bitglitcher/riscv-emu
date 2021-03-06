#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <vector>
#include "../device/device.h"

//4KB for each block allocated
#define MEM_BYTES (4096)

typedef struct
{
    /* data */
    uint8_t* memory;
    size_t memory_region;
} MEM_BLOCK;


//std::map <size_t memory_region, uint8_t data>


class MEMORY : public device
{
    public:
        MEMORY(int initial_size, uint32_t min_address, uint32_t max_address);
        bool initalize(uint32_t addr, char* buff, size_t buff_size);
        uint8_t read(uint32_t addr);
        uint32_t read32(uint32_t addr); //read 32bits
        uint16_t read16(uint32_t addr); //read 16bits
        void write(uint8_t data, uint32_t addr);
        void write32(uint32_t data, uint32_t addr);
        void write16(uint16_t data, uint32_t addr);
        void test();
        ~MEMORY();
    private:
        /* data */
        std::vector<MEM_BLOCK> vector_mem; 
        MEM_BLOCK* last_used = nullptr;
        int mask;
        uint32_t* memory_block; 
};


#endif