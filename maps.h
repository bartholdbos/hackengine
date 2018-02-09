#ifndef HACKENGINE_MAPS_H
#define HACKENGINE_MAPS_H

#include <sys/types.h>

typedef enum {
    REGION_TYPE_MISC,
    REGION_TYPE_CODE,
    REGION_TYPE_EXE,
    REGION_TYPE_HEAP,
    REGION_TYPE_STACK
} region_type_t;

typedef struct {
    unsigned long start;
    unsigned long size;
    region_type_t type;
    char filename[1];
} region_t;

bool readmaps(pid_t target);

#endif //HACKENGINE_MAPS_H