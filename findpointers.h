#pragma once
#include <fstream>

unsigned* findValue(char* value, region_t region, char* data){
	// char* offsets;
	for(int i = 0; i < sizeof(data); i += sizeof(value)){
		for(int j = 0; j < sizeof(value); j++){
			if(data[i+j] != value[j]){
				goto Outer;
			}
		}
		// offsets[i] = ...;
		Outer:;
	}
	// return offsets;
}


unsigned findInts(int value, region_t region, char* data){
	char search[4];
	//littleandy(search, (unsigned)value)

	// return findValue(search, mapping, data);
}

unsigned* findPointers(char* value, region_t region, char* data){
	unsigned address = atoi(value);
	unsigned offsets[address];

	for(int i = address; i > address - 2048; i -=4){
		offsets[i] = findInts( i, region, data ) ;
	}
	return offsets;
}
