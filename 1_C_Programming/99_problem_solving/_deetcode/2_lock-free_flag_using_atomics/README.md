# Lock-free Flag Using Atomics

Implement a lock-free flag in C using C11 atomics. The flag supports set, clear, and test operations, ensuring atomicity.

Constraints:
- Use atomic_flag or atomic_bool.
- set() => true.
- clear() => false.
- test() returns bool.
- No locks allowed.


## Test Case 1
```
Input: ["set"]
Output: true
```
                    
## Test Case 2
```
Input: ["clear"]
Output: false
```
                    


## Files

- `src/code.c`: Contains the C source code for the Fibonacci sequence and the function to calculate the sum of even-valued terms.
- `Makefile`: Automates the build process for compiling the C source code into an executable.

## Building the Project

To build the project, navigate to the project directory and run the following command:

```
make
```

This will compile the `code.c` file and create an executable.

## Running the Project

After building the project, you can run the executable with the following command:

```
./code
```

This will execute the program and display the sum of the even-valued terms in the Fibonacci sequence.