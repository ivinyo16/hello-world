# Circular Buffer for UART RX

Implement a circular buffer for UART receive data. The buffer must support push and pop operations and detect full/empty conditions.

Constraints:
- Buffer size is fixed at 16 bytes.
- Use indices (not dynamic memory).
- push returns 0 on success, -1 if full.
- pop returns byte on success, -1 if empty.
- Data type is uint8_t.

## Test Case 1
```
Input: [1,2,3]
Output: [1,2,3]
```
                    
## Test Case 2


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
