#pragma once
#include <fstream>

char* readMem(pid_t target, unsigned long start, unsigned long size){
  char name[128];

  sprintf(name, "/proc/%u/mem", target);

  std::fstream memory (name, std::ifstream::binary);
  
  if(memory){
    char * buffer;
    memory.seekg(start);
    memory.read(buffer, size);
    memory.close();
    std::cout.write (buffer,size);
  }



}
