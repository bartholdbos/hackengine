#pragma once
#include <fstream>

std::string findInts(int value, region_t region, std::string data){
	char search[4];
}

std::string findPointers(char* value, region_t region, std::string data){
	std::string offsets;
	unsigned address = atoi(value);

	for(int i = address; i > address - 2048; i -=4){
		offsets.append( findInts( (int)i, region, data ) );
	}
	return offsets;
}
