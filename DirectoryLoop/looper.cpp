#include <iostream>
#include <windows.h>
#include <filesystem>
#include <string>

#include <unordered_map>
#include <vector>
#include <map>

using dict_iterator = std::filesystem::recursive_directory_iterator;
namespace fs = std::filesystem;


std::vector <std::string> unresolved_paths;
std::vector <std::string> resolved_paths;

constexpr int NewSize = 1000000;




void forDictIterator(std::string path) {
	int index = 0;
	for (const auto& dirEntry : dict_iterator(path)) {
		

		std::string dirStr = dirEntry.path().string();
		
		unresolved_paths.push_back(dirStr);
		
		index++;
		
		
	}
}

void loopFiles(const char* drive) {
	
	std::string path = "D:/coding";
	forDictIterator(path);
	
	

	for (std::string a : unresolved_paths) {
		

		if (fs::is_directory(a)) {
			unresolved_paths.erase(std::remove(unresolved_paths.begin(), unresolved_paths.end(), a), unresolved_paths.end());
			
			forDictIterator(a);
			
		}
		else if(a.find(".") != std::string::npos) {
			
			resolved_paths.push_back(a);
		}
		
	}
  
  // print the files
  
  for (std::string a : resolved_paths){
    std::cout << a << std::endl;
  }



}
int main() {

	unresolved_paths.reserve(100000);
	resolved_paths.reserve(100000);
	loopFiles("D");



}
