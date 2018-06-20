#pragma once
#include <fstream>

char* readMap(pid_t target, unsigned long start, unsigned long size, char *data) {
    std::ifstream mem;
    char name[128];

    sprintf(name, "/proc/%u/mem", target);

    mem.open(name);

    mem.seekg(start);
    mem.read(data, size);
    mem.close();
    return data;
}
