#pragma once
#include <fstream>

char* findInts(int value, region_t region, std::string data){
	char search[4];
}

// char* findPointers(char* value, region_t region, char* data){
// 	unsigned address = atoi(value);
// 	char offsets[address];
//
// 	for(int i = address; i > address - 2048; i -=4){
// 		offsets.append( findInts( i, region, data ) );
// 	}
// 	return offsets;
// }
