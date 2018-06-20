#include <sys/types.h>
#include <cstdio>
#include <iostream>
#include <string.h>

#include "maps.h"
#include "mem.h"
#include "findpointers.h"

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

        std::cout << line << std::endl;
        if (sscanf(line, "%lx-%lx %c%c%c%c %x %x:%x %u %[^\n]", &start, &end, &read,
        &write, &exec, &cow, &offset, &dev_major, &dev_minor, &inode, filename) >= 6){

            unsigned long size = end -start;

            if (!strcmp(filename, "[heap]"))
                type = REGION_TYPE_HEAP;
            else if (!strcmp(filename, "[stack]"))
                type = REGION_TYPE_STACK;

            region_t region = {start, size, type, filename};

            char data[size];
            readMap(target, start, size, data);

            findPointers("130ce50", region, data);

            std::cout << "Start is at: " << region.start << std::endl
            << "With size of: " << region.size << std::endl
            << "Type: " << region.type << std::endl
            << "And filename: " << region.filename << std::endl << std::endl;
        }
    }
    //release memory allocated
    free(line);
    fclose(maps);
}
