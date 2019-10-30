#include <iostream>
#include <map>

 int main(void){
 srand(time(NULL));
 std::map<char, int> map;
 std::map<int, char> sortedMap;


 for(char c = 'a'; c <= 'd'; c++){
 map[c] = rand() % 100 + 0;
 }


 std::cout << "unsorted numbers: " << std::endl;
 for(auto const numb: map){
 std::cout << numb.first << ": " << numb.second << std::endl;
sortedMap[numb.second] = numb.first;
 }

 std::cout <<std::endl <<"Sorted numbers: " << std::endl;
 for(auto const numb: sortedMap)
 std::cout << numb.second << ": " << numb.first << std::endl;


 return 0;
}