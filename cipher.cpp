#include <cstdlib>
#include <fstream>
#include "cipher.h"

// Inputting cipher.
cipher *In(std::ifstream &stream) {
    cipher *cf;
    int k;
    stream >> k;
    stream.get();
    switch (k) {
        case 1:
            cf = new cipher;
            cf->k = cipher::CYCLE;
            In(cf->a, stream);
            countCycleDecrypted(*cf);
            cf->comparable = getComparable(*cf);
            return cf;
        case 2:
            cf = new cipher;
            cf->k = cipher::NUMBER;
            In(cf->p, stream);
            countNumberDecrypted(*cf);
            cf->comparable = getComparable(*cf);
            return cf;
        case 3:
            cf = new cipher;
            cf->k = cipher::POINTER;
            In(cf->r, stream);
            countPointerDecrypted(*cf);
            cf->comparable = getComparable(*cf);
            return cf;
        default:
            return 0;
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
            countCycleDecrypted(*cf);
            cf->comparable = getComparable(*cf);
            return cf;
        case 2:
            cf->k = cipher::NUMBER;
            InRnd(cf->p);
            countNumberDecrypted(*cf);
            cf->comparable = getComparable(*cf);
            return cf;
        case 3:
            cf->k = cipher::POINTER;
            InRnd(cf->r);
            countPointerDecrypted(*cf);
            cf->comparable = getComparable(*cf);
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
            stream << "decrypted:"<< r.decryptedScript << "\n";
            break;
        case cipher::NUMBER:
            Out(r.p, stream);
            stream << "decrypted:"<< r.decryptedScript << "\n";
            break;
        case cipher::POINTER:
            Out(r.r, stream);
            stream << "decrypted:"<< r.decryptedScript << "\n";
            break;
    }
    stream << "Comparable value: " << r.comparable << "\n";
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

void countCycleDecrypted(cipher &r) {
    for (int i = 0; i < countLength(r.a.encryptedScript); i++) {
        if(48 <= r.a.encryptedScript[i] && r.a.encryptedScript[i] <=57) {
            r.decryptedScript[i] = (abs((r.a.encryptedScript[i] - 48) - r.a.n) % 10) + 48;
        } else {
            r.decryptedScript[i] = (abs((r.a.encryptedScript[i] - 97) - r.a.n) % 26) + 97;
        }
    }
}

void countNumberDecrypted(cipher &r) {
    int temp;
    for (int i = 0; r.p.encryptedScript[i] > 0; i++) {
        temp = 0;
        for(int j = 0; j < 36; j++){
            if(r.p.table[j] == r.p.encryptedScript[i]){
                temp = j;
            }
        }
        if(temp < 10) {
            r.decryptedScript[i] = (char)(temp + 48);
        } else {
            r.decryptedScript[i] = (char)(temp - 10 + 97);
        }
    }
}

void countPointerDecrypted(cipher &r) {
    int temp = 0;
    for (int i = 0; i < countLength(r.r.encryptedSrypt); i++) {
        if(48 <= r.r.encryptedSrypt[i] && r.r.encryptedSrypt[i] <= 57) {
            temp = r.r.arr[r.r.encryptedSrypt[i] - 48];
            r.decryptedScript[i] = temp + (temp < 10 ? 48 : 87);
        } else {
            temp = r.r.arr[r.r.encryptedSrypt[i] - 87];
            r.decryptedScript[i] = temp + (temp < 10 ? 48 : 87);
        }
    }
}