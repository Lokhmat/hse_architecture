#ifndef __numberSwap__
#define __numberSwap__

#include <fstream>

// numberSwap structure.
struct numberSwap {
    int encryptedScript[10000];
    int table[36];
};


// Inputting numberSwap.
void In(numberSwap &p, std::ifstream &stream);


// Creating random numberSwap.
void InRnd(numberSwap &p);


// Outputting numberSwap.
void Out(numberSwap &p, std::ofstream &stream);



#endif // __numberSwap__