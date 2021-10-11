#include "numberSwap.h"
#include "cipher.h"
#include <fstream>

// Inputting numberSwap.
void In(numberSwap &p, std::ifstream stream) {
    char inputStr[10000];
    char inp[2];
    stream.getline(inputStr, 10000);
    for(int i = 0; i < countLength(inputStr); i++){
        p.encryptedScript[i] = inputStr[i] - 48;
    }
    for(int i = 0; i < 26; i++){
        stream >> inp;
        p.table[i] = inp[0];
    }
}


// Creating random numberSwap.
void InRnd(numberSwap &p) {
    for (int i = 0; i < rand() % 1000; i++) {
        p.encryptedScript[i] = rand() % 200;
    }
    for (int i = 0; i < 26; i++) {
        p.table[i] = rand() % 1000;
    }
}


// Outputting numberSwap.
void Out(numberSwap &r, std::ofstream stream) {
    stream << "numberSwap:" << "\n" <<  "encrypted:" << r.encryptedScript << "\n" ;
    stream << "table of intersection of symbols\n";
    for(int i = 0; i < 30; i++){
        stream << (char)(i + 48) << " " << r.table[i] << "\n";
    }
}
