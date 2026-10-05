# Low-Latency Control Loop

Write a high-rate PID control loop in C designed for low latency. The loop computes a new output based on error, integral, and derivative terms, and clamps output to safe limits.

Constraints:
- dt fixed.
- Use float arithmetic.
- anti-windup on integral.
- output clamp.
- Function signature: float pid(float set, float meas).
- Must run fast (inline where possible).

## Test Case 1
```
Input: [10,8]
Output: ">0"
```
                    
## Test Case 2
```
Input: [5,5]
Output: "0"
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