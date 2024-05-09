# Memory Management Utilities

This repository contains two separate C++ applications designed for demonstrating and testing memory reading capabilities in Windows environments. The two programs, `Cases.cpp` and `MemoryReader.cpp`, are engineered to interact with each other to showcase how data can be accessed across different processes securely and efficiently. 

## Overview

- **Cases.cpp**: This application prints the process ID and memory addresses of various data types initialized within the program. It is designed to serve as a target for memory inspection, providing a clear, static example of memory allocation for testing.
- **MemoryReader.cpp**: This tool reads memory content from another process using specified hexadecimal memory addresses. It is built to demonstrate low-level memory access, error handling, and process interaction in a Windows environment.

Each file contains a `main()` function and is intended to be compiled and run separately. The distinct functionalities catered by each program are detailed below.

## Cases.cpp

### Functionality

`Cases.cpp` serves as a diagnostic tool that:
- Prints the current process ID (`PID`).
- Initializes variables of several data types.
- Displays these variables along with their corresponding memory addresses.

### Data Types Demonstrated
- Integer
- Float
- Double
- Character
- String

This information is crucial for testing and debugging applications that need to interact with memory directly, providing a safe and predictable memory landscape for development and testing.

## MemoryReader.cpp

### Functionality

`MemoryReader.cpp` is a robust memory reading tool tailored for advanced users and developers, illustrating:
- Direct reading of memory from an external process using process ID and memory addresses.
- Handling of various data types through a user-friendly menu-driven interface.
- Comprehensive error checking, ensuring the tool robustly handles typical issues like invalid memory access, incorrect data types, or system permissions.

### Advanced Features
- **Dynamic Data Handling**: Users can select the type of data they wish to read from memory, such as integers, floats, doubles, characters, and strings.
- **Error Management**: Implements detailed error reporting that aids in diagnosing issues related to process access or memory reading operations.
- **User Interface**: Employs a simple command-line menu system, allowing for easy operation and clear output.

### Compilation and Execution
Both programs should be compiled with a C++ compiler that supports C++17 or later. For instance, using `g++`, the compilation commands would be:
```bash
g++ Cases.cpp -o Cases.exe
g++ MemoryReader.cpp -o MemoryReader.exe
