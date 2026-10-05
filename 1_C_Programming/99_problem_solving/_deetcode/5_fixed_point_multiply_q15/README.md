# Fixed-Point Multiply (Q15)

Implement a fixed-point multiplication for Q15 format in C. Inputs are signed 16-bit, output also Q15. Prevent overflow and maintain saturation.

Constraints:
- Inputs int16_t.
- Multiply produce 32-bit temp.
- Shift right 15.
- Clamp to [-32768, 32767].
- Return int16_t.

## Test Case 1
```
Input: [16384,16384]
Output: 8192
```
                    
## Test Case 2
```
Input: [32767,32767]
Output: 32767
```
                    
## Test Case 2
```
Input: [-32768,32767]
Output: -32768
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