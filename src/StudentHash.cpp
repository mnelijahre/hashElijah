//best hash in the whole world
#include <stdint.h>
#include <stdlib.h>
void StudentHash(const void * key, int len, uint32_t seed, void * out) {
    
    //some initialization stuff (some is usually done in preprocessor, but this is for smhasher)
    const uint8_t* data = (const uint8_t*) key; // data contains the input data to hash
    int CHUNK_SIZE = 4;


	// SAMPLE HASH FUNCTION BELOW HERE (please delete)

    srand(seed); // dummy 

    uint32_t dig = rand();

    int inc = 0; //how much should we increment the pointer?
    unsigned int reads = 0;
    while (reads * 4 < len) {
        inc = reads * 4;

        //xor the 4 bytes we read in
        int xor_result = dig; 
        for(int i = 0; i < CHUNK_SIZE; i++) {
            if (inc + i < len) {
                xor_result ^= data[inc + i];
            }
            //"padding"
            else if (inc + i >= len) {
                xor_result ^= 0;
            }
        }
        reads ++;
        srand(xor_result);

	}

    *(uint32_t*)out = dig;

	// SAMPLE HASH FUNCTION ABOVE HERE (please delete)
}

