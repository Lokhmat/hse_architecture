#include "numberSwap.h"
#include "cipher.h"
#include <fstream>

// Inputting numberSwap.
void In(numberSwap &p, std::ifstream &stream) {
    int len;
    stream >> len;
    for(int i = 0; i < len; i++){
        stream >> p.encryptedScript[i];
    }
    for(int i = 0; i < 36; i++){
        stream >> p.table[i];
    }
}


// Creating random numberSwap.
void InRnd(numberSwap &p) {
    int temp;
    int len = rand() % 100 + 1;
    for (int i = 0; i < 36; i++) {
        p.table[i] = rand() % 1000 + 1;
    }
    for(int i = 0; i < len ; i++){
        p.encryptedScript[i] = p.table[rand() % 36];
    }
}


// Outputting numberSwap.
void Out(numberSwap &r, std::ofstream &stream) {
    stream << "numberSwap:" << "\n" <<  "encrypted: ";
    for(int i = 0; r.encryptedScript[i] != 0; i++){
        stream << r.encryptedScript[i] << ' ';
    }
    stream << "\n";
    stream << "table of intersection of symbols\n";
    for(int i = 0; i < 36; i++){
        if (i < 10){
            stream << (char)(i + 48) << " " << r.table[i] << "\n";
        } else {
            stream << (char) (i + 87) << " " << r.table[i] << "\n";
        }
    }
}
