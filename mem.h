#pragma once

char* readMem(pid_t target, unsigned long memLocation){
  FILE *mem;
  char name[32], *line = NULL;
  size_t len = 0;

  sprintf(name, "/proc/%u/mem", target);

  if ((mem = fopen(name, "r")) == NULL){
      return 0;
  }

  int lineCount = 0;

  while (getline(&line, &len, mem) != -1){
    if(lineCount == memLocation){
      std::cout << line << std::endl;
    }else{
      lineCount++;
    }
  }

  fclose(mem);
}
