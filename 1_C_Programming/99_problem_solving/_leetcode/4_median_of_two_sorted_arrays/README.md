# c-project/c-project/README.md

This project implements a C program that calculates the sum of the even-valued terms in the Fibonacci sequence whose values do not exceed four million.

## Prerequisites
- [Cmake](https://cmake.org/)
- Compiler: [Mingw](https://www.mingw-w64.org/getting-started/msys2/)

## Files

- `src/code.c`: Contains the template C source code

## Initialize the Project

To initialize the project using preset, navigate to the project directory and run the following command:

```
cmake --preset ucrt_mingw_gcc -B build
```

## Build the project

```
cmake --build build
```

## Running the Project

After building the project, you can run the executable with the following command:

```
./code
```

This will execute the program and display the sum of the even-valued terms in the Fibonacci sequence.