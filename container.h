#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - contains data type,
// describes normal data container
//------------------------------------------------------------------------------

#include "cipher.h"

//------------------------------------------------------------------------------
// ПSimple container with usual array
struct container {
    enum {max_len = 10000}; // максимальная длина
    int len; // текущая длина
    cipher *cont[max_len];
};

// Container initialization
void Init(container &c);

// Container clearance
void Clear(container &c);

// Container input from string
void In(container &c, std::ifstream &stream);

// Random input to container
void InRnd(container &c, int size);

// Output to stream
void Out(container &c, std::ofstream &stream);

// Container sorting with coctail sort
void cocktailSort(container &c);

#endif
