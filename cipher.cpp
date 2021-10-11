#include <cstdlib>
#include <fstream>
#include "cipher.h"



// Inputting cipher.
cipher *In(std::ifstream &stream) {
    cipher *cf;
    int k;
    stream >> k;
    char _[100];
    stream.getline(_, 100);
    switch (k) {
        case 1:
            cf = new cipher;
            cf->k = cipher::CYCLE;
            In(cf->a, stream);
            return cf;
        case 2:
            cf = new cipher;
            cf->k = cipher::NUMBER;
            In(cf->p, stream);
            return cf;
        case 3:
            cf = new cipher;
            cf->k = cipher::POINTER;
            In(cf->r, stream);
            return cf;
        default:
            throw std::invalid_argument("Error, try to import cipher again");
    }
}


// Creating random cipher.
cipher *InRnd() {
    cipher *cf = new cipher;
    int k = rand() % 3 + 1;
    switch (k) {
        case 1:
            cf->k = cipher::CYCLE;
            InRnd(cf->a);
            return cf;
        case 2:
            cf->k = cipher::NUMBER;
            InRnd(cf->p);
            return cf;
        case 3:
            cf->k = cipher::POINTER;
            InRnd(cf->r);
            return cf;
        default:
            return 0;
    }
}


// Outputting cipher.
void Out(cipher &r, std::ofstream &stream) {
    switch(r.k){
        case cipher::CYCLE:
            Out(r.a, stream);
            break;
        case cipher::NUMBER:
            Out(r.p, stream);
            break;
        case cipher::POINTER:
            Out(r.r, stream);
            break;
    }
}


// Get char[] actual length.
int countLength(const char line[]) {
    int length = 10000;
    for (int i = 9999; i >= 0; i--) {
        if (line[i] != '\000') {
            break;
        }
        length--;
    }
    return length;
}

// Count punctuation signs in char[].
int countSum(const char line[]) {
    int count = 0;
    for (int i = 0; i < countLength(line); i++) {
        count += line[i];
    }
    return count;
}

// Comparable value of cipher.
double getComparable(cipher &r) {
    int len = countLength(r.decryptedScript);
    int sum = countSum(r.decryptedScript);
    if (len == 0) {
        return 1;
    }
    return (double)sum / len;

}