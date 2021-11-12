#include <cstdlib>
#include "pointerSwap.h"
#include "cipher.h"

// Inputting pointerSwap.
void In(pointerSwap &a,  std::ifstream &stream) {
    stream.getline(a.encryptedSrypt, 10000);
    for(int i = 0; i < 36; i++){
        char tmp;
        stream >> tmp;
        if (tmp >= 48 && tmp <= 57){
            a.arr[i] = tmp - 48;
        } else {
            a.arr[i] = tmp - 97;
        }
    }
}


// Creating random pointerSwap.
void InRnd(pointerSwap &a) {
    int temp;
    for (int i = 0; i < rand() % 100 + 1; i++) {
        temp = rand() % 2;
        if (temp == 1) {
            a.encryptedSrypt[i] = 'a' + rand() % 26;
        } else {
            a.encryptedSrypt[i] = '0' + rand() % 9;
        }
    }
    for(int i = 0; i< 36; i++){
        a.arr[i] = -1;
    }
    for (int i = 0; i < 36; i++) {
        for(int j = rand() % 36; ; j = (j + 1)%36 ) {
            if (a.arr[j] == -1) {
                a.arr[j] = i;
                break;
            }
        }
    }
}


// Outputting pointerSwap.
void Out(pointerSwap &a, std::ofstream &stream) {
    stream << "PointerSwap: \nencrypted:" << a.encryptedSrypt << "\n";
    for(int i = 0; i < 36; i++){
        if (a.arr[i] < 10){
            stream << (char)(a.arr[i] + 48) << " " << (char)(i + (i < 10 ? 48 : 87)) << "\n";
        } else{
            stream << (char)(a.arr[i] + 87) << " " << (char)(i + (i < 10 ? 48 : 87)) << "\n";
        }

    }
}
