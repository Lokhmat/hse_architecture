#include "container.h"
#include <fstream>
#include <iostream>

// Container initialization.
void Init(container &c) {
    c.len = 0;
}


// Cleaning non-used memory
void Clear(container &c) {
    for (int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
}


// Thread input into container.
void In(container &c, std::ifstream &stream) {
    while (!stream.eof()) {
        if ((c.cont[c.len] = In(stream)) != 0) {
            ++c.len;
        }
        else{
            std::cout << "Wrong input answer may not be correct\n";
            break;
        }
    }
}


// Random input into container.
void InRnd(container &c, int size) {
    while (c.len < size) {
        if ((c.cont[c.len] = InRnd()) != nullptr) {
            c.len++;
        }
    }
}


// Output from container.
void Out(container &c, std::ofstream &stream) {
    stream << "Container contains " << c.len << " elements.\n";
    for (int i = 0; i < c.len; i++) {
        stream << i << ":";
        Out(*(c.cont[i]), stream);
    }
}


// Cocktail sort implementation for container
void cocktailSort(container &c){
    bool flag = true;
    cipher temp;
    int n = c.len;
    int start = 0, end = n-1;
    while(flag){
        flag = false;
        for(int i = start; i<end; i++){ //scan from left to right as bubble sort
            if(c.cont[i]->comparable > c.cont[i+1]->comparable){
                temp = *c.cont[i];
                *c.cont[i] = *c.cont[i+1];
                *c.cont[i+1] = temp;
                flag = true;
            }
        }
        if(!flag){ //if nothing has changed simply break the loop
            break;
        }
        flag = false;
        end--; //decrease the end pointer
        for(int i = end - 1; i >= start; i--){ //scan from right to left
            if(c.cont[i]->comparable > c.cont[i+1]->comparable){
                temp = *c.cont[i];
                *c.cont[i] = *c.cont[i+1];
                *c.cont[i+1] = temp;
                flag = true;
            }
        }
        start++;
    }
}