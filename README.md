# 🧮 Command-Line Calculator in C

A modular command-line calculator implemented in C, supporting both basic arithmetic and advanced mathematical operations. This project was developed as a practical application of key C programming features including argument parsing, modular code organization, function pointers, and robust input validation.

## 📌 Features

- **Basic Operations**: `+`, `-`, `x`, `/`, `^` (power), `min`, `max`
- **Trigonometric Functions**: `sin`, `cos`, `tan`, `cot`
- **Factorial Calculation**: `fact`
- **Color-coded terminal output** for results and errors
- **Robust input parsing** with detailed error messages
- **Modular design** with reusable and testable components

## 🧠 What This Project Demonstrates

This project showcases an application of various C language features:

- **Command-line Argument Parsing**: Handles input patterns like `calc 3 + 4` and `calc sin 0.5`.
- **Function Pointers**: Selects the right operation dynamically based on user input.
- **Header Files & Modularization**: Separates concerns into distinct `.h` and `.c` files.
- **ANSI Escape Codes**: Provides colored terminal output for better user experience.
- **Error Handling**: Detects invalid input, such as malformed numbers or math domain errors (e.g., `tan(π/2)` or division by zero).
- **Case-Insensitive Operators**: Supports uppercase or mixed-case operator inputs (`Sin`, `MAX`, etc.).
- **Floating Point Support**: Uses `strtod()` for safe double conversion.

## 🛠️ Build & Run
```bash
gcc main.c calculator.c math_functions.c -o calc -lm
