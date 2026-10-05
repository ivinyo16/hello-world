# LED Status FSM
Implement an embedded C FSM to control LED status based on system mode. The LED should remain OFF during IDLE, blink at 1 Hz in ACTIVE mode, and blink at 4 Hz in ERROR mode. The FSM must run per tick call.

Constraints:
- Mode enum: IDLE, ACTIVE, ERROR.
- tick() function toggles LED based on count thresholds.
- Blink periods: ACTIVE = 500 ms, ERROR = 125 ms.
- tick() is called every 125 ms.
- LED state persists across calls.
- Mode change immediately affects blinking.



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