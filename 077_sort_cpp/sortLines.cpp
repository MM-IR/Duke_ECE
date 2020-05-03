#include <iostream>
#include <istream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>

void doSort(std::istream & ifs){
  std::string line;
  std::vector<std::string>lines;
  while (getline(ifs,line)){
    lines.push_back(line);
  }
  if (!ifs.eof() || !ifs){
    std::cerr<<"something bad happened!"<<std::endl;
    
  }
  std::sort(lines.begin(),lines.end());
  for(std::vector<std::string>::const_iterator it = lines.begin(); it != lines.end(); ++it){
    std::cout<<*it<<std::endl;
  }
}

int main(int argc, char **argv)
{
  if (argc < 2) {
    doSort(std::cin);
  } else {
    for (int i = 1; i < argc; i++) {
      std::ifstream ifs(argv[i]);
      if (!ifs) {
        std::cerr << "failed to open " << argv[i] << std::endl;
        exit(EXIT_FAILURE);
      }
      doSort(ifs);
    }
  }
  return 0;
}

// vim: ts=2:sw=2:et
