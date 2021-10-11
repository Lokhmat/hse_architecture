#ifndef __cipher__
#define __cipher__


#include <stdio.h>
#include <fstream>
#include "cycleSwap.h"
#include "numberSwap.h"
#include "pointerSwap.h"



// Cipher structure.
struct cipher {
    char decryptedScript[10000];
    enum key {
        CYCLE, NUMBER, POINTER
    };
    key k;
    union {
        cycleSwap a;
        numberSwap p;
        pointerSwap r;
    };
};



// Inputting Cipher.
cipher *In(std::ifstream &stream);


// Creating Cipher.
cipher *InRnd();


// Outputting Cipher.
void Out(cipher &r, std::ofstream stream);


// Comparable value of Cipher.
double getComparable(cipher &r);


int countLength(const char line[]);


int countSum(const char line[]);

#endif // __riddle__