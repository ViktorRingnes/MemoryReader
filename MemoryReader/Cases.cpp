#include <iostream>
#include <Windows.h>
#include <string>

int main() {
    DWORD pid = GetCurrentProcessId();
    std::cout << "The PID of this process is: " << pid << std::endl;

    int myInt = 12345;
    float myFloat = 123.456f;
    double myDouble = 12345.6789;
    char myChar = 'A';
    std::string myString = "Hello, World!";

    std::cout << "Integer: " << myInt << ", Address: " << &myInt << std::endl;

    std::cout << "Float: " << myFloat << ", Address: " << &myFloat << std::endl;

    std::cout << "Double: " << myDouble << ", Address: " << &myDouble << std::endl;

    std::cout << "Char: " << myChar << ", Address: " << (void*)&myChar << std::endl;

    std::cout << "String: " << myString << ", Address: " << &myString << std::endl;

    system("pause");
    return 0;
}
