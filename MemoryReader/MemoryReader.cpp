#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
#include <limits> 

enum DataType { INT_TYPE = 1, FLOAT_TYPE, DOUBLE_TYPE, CHAR_TYPE, STRING_TYPE };

void printMenu() {
    std::cout << "Select data type to read:\n";
    std::cout << "1 - Integer\n";
    std::cout << "2 - Float\n";
    std::cout << "3 - Double\n";
    std::cout << "4 - Char\n";
    std::cout << "5 - String (max 256 chars)\n";
    std::cout << "Enter choice: ";
}

template <typename T>
void readMemory(HANDLE hProcess, uintptr_t memoryAddress) {
    T value;
    SIZE_T bytesRead;
    if (ReadProcessMemory(hProcess, (LPVOID)memoryAddress, &value, sizeof(T), &bytesRead)) {
        std::cout << "Contents of memory: " << value << std::endl;
    }
    else {
        std::cerr << "ReadProcessMemory failed. Error: " << GetLastError() << std::endl;
    }
}

void readString(HANDLE hProcess, uintptr_t memoryAddress) {
    const size_t bufferSize = 256;
    char buffer[bufferSize] = { 0 };
    SIZE_T bytesRead;
    if (ReadProcessMemory(hProcess, (LPVOID)memoryAddress, buffer, bufferSize - 1, &bytesRead) && bytesRead > 0) {
        buffer[bytesRead] = '\0';
        std::cout << "Contents of memory: " << buffer << std::endl;
    }
    else {
        std::cerr << "ReadProcessMemory failed. Error: " << GetLastError() << std::endl;
    }
}

int main() {
    std::cout << "Memory Reader started...\n";

    while (true) {
        std::cout << "Enter PID of the target process (or 0 to exit): ";
        DWORD PID;
        std::cin >> PID;
        if (PID == 0) break;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please enter a numeric PID.\n";
            continue;
        }

        std::cout << "Enter memory address to read (in hex): ";
        uintptr_t memoryAddress;
        std::cin >> std::hex >> memoryAddress;
        std::cin >> std::dec;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please enter a valid hexadecimal address.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        printMenu();
        int dataType;
        std::cin >> dataType;
        if (std::cin.fail() || dataType < INT_TYPE || dataType > STRING_TYPE) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid data type selected. Please select a valid option.\n";
            continue;
        }

        HANDLE hProcess = OpenProcess(PROCESS_VM_READ, FALSE, PID);
        if (hProcess == NULL) {
            std::cerr << "OpenProcess failed. Error: " << GetLastError() << std::endl;
            continue;
        }

        switch (dataType) {
        case INT_TYPE:
            readMemory<int>(hProcess, memoryAddress);
            break;
        case FLOAT_TYPE:
            readMemory<float>(hProcess, memoryAddress);
            break;
        case DOUBLE_TYPE:
            readMemory<double>(hProcess, memoryAddress);
            break;
        case CHAR_TYPE:
            readMemory<char>(hProcess, memoryAddress);
            break;
        case STRING_TYPE:
            readString(hProcess, memoryAddress);
            break;
        default:
            std::cerr << "Invalid data type selected. This should never happen.\n";
            break;
        }
        CloseHandle(hProcess);
        std::cout << "Press ENTER to read another address or Ctrl+C to exit." << std::endl;
        std::cin.get();
    }

    std::cout << "Memory Reader exited.\n";
    return 0;
}
