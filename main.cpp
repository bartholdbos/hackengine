#include <iostream>

#include "maps.h"

int main(int argc, char* argv[]) {
    if (argc != 2){
        exit(1);
    }

    readmaps(atoi(argv[1]));

    return 0;
}