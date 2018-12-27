#include <iostream>
#include "tm1280.h"
#include "utilities.h"

std::array<uint64_t, 4> shiftRegister;
std::string txData = "LDPC is a parity check code relying on sparse parity-check matrices. Parity check codes add parity bits to the outgoing message.";
//std::array<uint8_t, 128> txData = { 0xff };
std::array<uint64_t, 4> parityBits = { 0, 0, 0, 0 }; // Parity bit accumulator



bool dataBit(uint64_t bit) {
    return txData[bit/8] >> (7-(bit%8)) & 1 == 1;
}

int main() {
//    txData.fill(0xff);
//    txData[4] = 0x08;

    for (unsigned int i = 0; i < 1024; i++) {
        if (i % 32 == 0) {
            // Load the circulant
            for (unsigned int j = 0; j < shiftRegister.size(); j++) {
                shiftRegister[j] = TM1280_G[i/32*4 + j];
            }
        }

        if (dataBit(i)) {
            // Add the circulant to the accumulator
            for (unsigned int j = 0; j < parityBits.size(); j++) {
                parityBits[j] ^= shiftRegister[j];
            }
        }

        for (unsigned int j = 0; j < shiftRegister.size(); j++) {
            // Split the left and right parts
            uint32_t upper = (shiftRegister[j] >> 32) & 0xffffffff;
            uint32_t lower = shiftRegister[j] & 0xffffffff;

            upper = rotr32(upper, 1);
            lower = rotr32(lower, 1);


            shiftRegister[j] = (static_cast<uint64_t>(upper) << 32) | lower;
        }
    }

    std::cout << "Parity bits: ";
    printarr(parityBits);
    std::cout << std::endl;

    return 0;
}

