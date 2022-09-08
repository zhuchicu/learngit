#include <iostream>
#include <string>

int main() {
    std::string s = "helloworld";
    for(int i=0; i<s.length(); i++)
        std::cout << s[i] << std::endl;
    s = "hi";
    std::cout << s << std::endl;
}