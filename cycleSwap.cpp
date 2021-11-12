#include <fstream>
#include "cycleSwap.h"


// Inputting cycleSwap.
void In(cycleSwap &r, std::ifstream &stream) {
    char temp[10000];
    stream.getline(r.encryptedScript, 10000);
    stream.getline(temp, 10000);
    r.n = std::stoi(temp);
}


// Creating random cycleSwap.
void InRnd(cycleSwap &r) {
    r.n = rand() % 100;
    int temp;
    for (int i = 0; i < rand() % 100 + 1; i++) {
        temp = rand() % 2;
        if (temp == 1) {
            r.encryptedScript[i] = 'a' + rand() % 26;
        } else {
            r.encryptedScript[i] = '0' + rand() % 9;
        }
    }

}


// Outputting cycleSwap.
void Out(cycleSwap &r, std::ofstream& stream) {
    stream << "cycleSwap:" << "\n" <<  "encrypted:" << r.encryptedScript << "\n" << "N = " << r.n << std::endl;
}
