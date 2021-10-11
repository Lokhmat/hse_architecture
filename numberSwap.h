#ifndef __proverb__
#define __proverb__

#include "cipher.h"
#include "stdio.h"
#include "pair.h"

// numberSwap structure.
struct numberSwap {
    int encryptedScript[10000];
    int table[26];
};


// Inputting numberSwap.
void In(numberSwap &p, std::ifstream stream);


// Creating random numberSwap.
void InRnd(numberSwap &p);


// Outputting numberSwap.
void Out(numberSwap &p, std::ofstream stream);



#endif // __proverb__