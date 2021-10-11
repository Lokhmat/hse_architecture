//------------------------------------------------------------------------------
// main.cpp - главная функция для задания поведения программы
//------------------------------------------------------------------------------

#include <fstream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <cstring>
#include <stdio.h>
#include "container.h"

void errMessage1() {
    printf("incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if(argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start\n");
    container c;
    Init(c);

    if(!strcmp(argv[1], "-f")) {
        std::ifstream stream(argv[1]);
        In(c, stream);
    }
    else if(!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) {
            printf("incorrect numer of objects = %d. Set 0 < number <= 10000\n", size);
            return 3;
        }
        // системные часы в качестве инициализатора
        srand((unsigned int)(time(0)));
        // Заполнение контейнера генератором случайных чисел
        InRnd(c, size);
    }
    else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл

    std::ofstream outStream1(argv[3]);
    outStream1 << "Filled container:\n";
    Out(c, outStream1);

    // The 2nd part of task
    std::ofstream outStream2(argv[4]);
    Sorting(c);
    outStream2 << "Sorted container:" << "\n";
    Out(c, outStream2);

    printf("Stop\n");
    return 0;
}
