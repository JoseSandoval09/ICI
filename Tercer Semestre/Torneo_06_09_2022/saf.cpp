#include <iostream>
#include <string>

using std::cout; using std::cin;
using std::endl; using std::string;

int main(){
    string str = "  Arbitrary   str ing with lots of spaces to be removed   .";

    cout << str << endl;

    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

    cout << str << endl;

    return EXIT_SUCCESS;
}
