#include <cstdlib>
#include "pointerSwap.h"
#include "cipher.h"


// Inputting pointerSwap.
void In(pointerSwap &a,  std::ifstream stream) {
    stream.getline(a.encryptedSrypt, 10000);
    for(int i = 0; i < 26; i++){
        stream >> a.arr[i];
    }
}


// Creating random pointerSwap.
void InRnd(pointerSwap &a) {
    for (int i = 0; i < rand() % 10000; i++) {
        a.encryptedSrypt[i] = '!' + (rand() % ('a' - 'z'));
    }
    for (int i = 0; i < 26; i++) {
        a.arr[i] = rand() % 26;
    }
}


// Outputting pointerSwap.
void Out(pointerSwap &a, std::ofstream stream) {
    stream << "PointerSwap: \n" << a.encryptedSrypt << "\n";
    for(int i = 0; i < 26; i++){
        stream << (char)(i+48) << " " << (char)(a.arr[i]+48) << "\n";
    }
}
