//a példakód angol változata megtalálható a cppreference.com oldalon: https://en.cppreference.com/w/cpp/language/try_catch#Example
#include <iostream>
#include <vector>
 
int main() {
    try {
        std::cout << "int kivétel dobás...\n";
        throw 42;
    } catch (int i) {
        std::cout << " egy integer kivétel elkapva, ennek értéke: " << i << '\n';
    }
 
    try {
        std::cout << "egy vektort hozunk létre, amelyben 5 integer fér el... \n";
        std::vector<int> v(5);
        std::cout << "a vektor 11-dik helyét megpróbáljuk elérni...\n";
        std::cout << v.at(10); // vector::at() throws std::out_of_range
    } catch (const std::exception& e) { // caught by reference to base
        std::cout << " egy standard kivétel elkapva, a hibakezelő üzenete a következő: '"
                  << e.what() << "'\n";
    }
 
}
