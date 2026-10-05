# Debounce Input Signal

Debounce a digital input signal using a simple counter method.

Constraints:
- Function prototype: int debounce(int raw).
- Stabilization time: 5 samples.
- Output state stored statically.
- Count increments only on consistent reads.
Test Case 1

## Test Case 1
```
Input: [1,1,1]
Output: 0
```
                    
## Test Case 2
```
Input: [1,0,1,1,1,1]
Output: 0
```
                    
## Test Case 2
```
Input: [1,0,1,1,1,1,1]
Output: 1
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