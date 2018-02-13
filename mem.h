#pragma once
#include <fstream>

int readMem(pid_t target, unsigned long start, unsigned long size) {
    std::fstream mem;
    char name[128];
    char data[4];

    sprintf(name, "/proc/%u/mem", target);

    mem.open(name);

    mem.seekg(start);
    mem.read(data, 4);

    std::cout << data << std::endl;

    mem.close();
}
