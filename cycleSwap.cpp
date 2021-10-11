#include <iostream>
#include "cycleSwap.h"
#include "cipher.h"


// Inputting cycleSwap.
void In(cycleSwap &r, std::ifstream stream) {
    stream.getline(r.encryptedScript, 10000);
    stream >> r.n;
}


// Creating random cycleSwap.
void InRnd(cycleSwap &r) {
    for (int i = 0; i < rand() % 10000; i++) {
        r.encryptedScript[i] = '!' + (rand() % ('a' - 'z'));
    }
    r.n = rand() % 100;
}


// Outputting cycleSwap.
void Out(cycleSwap &r, std::ofstream stream) {
    stream << "cycleSwap:" << "\n" <<  "encrypted:" << r.encryptedScript << "\n" << "N = " << r.n;
}
