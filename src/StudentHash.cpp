//best hash in the whole world
#include <stdint.h>
#include <stdlib.h>
void StudentHash(const void * key, int len, uint32_t seed, void * out) {
    
    //some initialization stuff (some is usually done in preprocessor, but this is for smhasher)
    const uint8_t* data = (const uint8_t*) key;
    int CHUNK_SIZE = 4;
    srand(seed);
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

        /* Due to the way integers and rand work, the leading bit will almost always be zero, 
           because it's returning an integer that will always start with <= 2. Not to worry,
           this can be circumvented by taking the next random number and taking the last 2 bytes
           of each number. */
        //first number
        unsigned int num1 = rand();
        unsigned int num2 = rand();

        //zero last 16 bits
        /* printf("num1 was: %08x\n", num1); */
        num1 = num1 << 16;
        /* printf("num1 is: %08x\n", num1); */
        //zero the first 16 bits 
        num2 = num2 << 16;
        /* printf("num2 is: %08x\n", num2); */
        num2 = num2 >> 16; 
        /* printf("num2 is: %08x\n", num2); */
        //combine num1 and num2
        dig = num1 | num2;
        /* printf("dig  is: %08x\n", dig); */
        /* printf("Rand is: %i\n", dig); */
        /* printf("%s\n", chunk); */
    }
    *(uint32_t*)out = dig;
}

