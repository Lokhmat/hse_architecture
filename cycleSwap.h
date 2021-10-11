#ifndef __cycleSwap__
#define __cycleSwap__


#include <fstream>



// cycleSwap structure.
struct cycleSwap {
    char encryptedScript[10000];
    int n;
};


// Inputting cycleSwap.
void In(cycleSwap &r, std::ifstream &stream);


// Creating random cycleSwap.
void InRnd(cycleSwap &p);


// Outputting cycleSwap.
void Out(cycleSwap &r, std::ofstream &stream);


#endif // __cycleSwap__