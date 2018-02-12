#include <sys/types.h>
#include <cstdio>
#include <iostream>

#include "maps.h"

bool readmaps(pid_t target){
    FILE *maps;
    char name[128], *line = NULL;
    size_t len = 0;

    sprintf(name, "/proc/%u/maps", target);

    if ((maps = fopen(name, "r")) == NULL){
        std::cout << "Failed to open maps file" << std::endl;
        return false;
    }

    while (getline(&line, &len, maps) != -1){
        unsigned long start, end;
        char read, write, exec, cow, *filename;
        int offset, dev_major, dev_minor, inode;
        region_type_t type = REGION_TYPE_MISC;
        region_t *map = NULL;

        std::cout << line << std::endl;
        if (sscanf(line, "%lx-%lx %c%c%c%c %x %x:%x %u %[^\n]", &start, &end, &read,
                  &write, &exec, &cow, &offset, &dev_major, &dev_minor, &inode, filename) >= 6){
            std::cout << start << std::endl;
        }
    }
}