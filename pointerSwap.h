#ifndef __pointerSwap__
#define __pointerSwap__


#include <fstream>


// pointerSwap structure.
struct pointerSwap {
    char encryptedSrypt[10000];
    int arr[36];
};


// Inputting pointerSwap.
void In(pointerSwap &a, std::ifstream &stream);


// Creating pointerSwap.
void InRnd(pointerSwap &a);


// Outputting random pointerSwap.
void Out(pointerSwap &a, std::ofstream &stream);


#endif // __pointerSwap__