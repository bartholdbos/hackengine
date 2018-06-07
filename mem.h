#pragma once
#include <fstream>

char* readMap(pid_t target, unsigned long start, unsigned long size) {
    std::ifstream mem;
    char name[128];
    char *data = new char[size];

    sprintf(name, "/proc/%u/mem", target);

    mem.open(name);

    mem.seekg(start);
    mem.read(data, size);

    mem.close();
    return data;
}
