#include <iostream>
#include <fstream>
#include <regex>

int main(int argc, char* argv[]) {
    if (argc != 2){
        exit(1);
    }

    std::string pid = argv[1];
    std::ifstream maps;
    maps.open("/proc/" + pid + "/maps");

    std::regex values("(\\S+)");
    std::string line;
    while(getline(maps, line)){
        std::smatch value;
        while(regex_search(line, value, values)){
            std::cout << value.str() << " ";
            std::cout << std::endl;
            line = value.suffix().str();
        }

    }

    return 0;
}