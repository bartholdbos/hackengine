#include <sys/types.h>
#include <fstream>
#include <iostream>

#include "maps.h"

bool readmaps(pid_t target){
    std::ifstream maps;
    char name[128], *line = NULL;
    size_t len = 0;

    sprintf(name, "/proc/%u/maps", target);

    maps.open(name);
    while (maps.getline(line, len)){
        std::cout << "asdf" << std::endl;
        unsigned long start, end;
        char read, write, exec, cow, *filename;
        int offset, dev_major, dev_minor, inode;
        region_type_t type = REGION_TYPE_MISC;
        region_t *map = NULL;

        if (scanf(line, "%lx-%lx %c%c%c%c %x %x:%x %u %[^\\n]", &start, &end, &read,
                  &write, &exec, &cow, &offset, &dev_major, &dev_minor, &inode, filename) >= 6){
            std::cout << start << std::endl;
        }
    }
}