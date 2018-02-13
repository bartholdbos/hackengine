#pragma once

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
    char * filename;
} region_t;

bool readmaps(pid_t target);
