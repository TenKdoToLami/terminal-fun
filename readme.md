# Terminal Effects Library

This project is a C++ library designed to manipulate terminal output with color and character effects. It provides tools to create, modify, and display colored text and symbols in the terminal, along with utilities to manage terminal size and appearance.

**Note:** This project is currently in progress.

## Features

-   **Color Management:**
    -      A `Color` struct to represent RGB colors with integer (0-255) and double representations.
    -      Predefined colors in the `Colors` namespace, categorized by hue.
    -      Color manipulation functions:
        -      Setting and retrieving RGB components.
        -      Inverting color components.
        -      Scaling and adjusting color components.
        -      Blending colors.
        -      Converting to grayscale.
-   **Symbol Representation:**
    -      The `OneSymbol` class to represent a single character with foreground and background colors.
    -      Output stream overloading for easy printing of `OneSymbol` objects.
    -   Inverting colors of `OneSymbol` object.
-   **Terminal Control:**
    -      The `TerminalControl` class to manage terminal size and output.
    -      Retrieving terminal size.
    -      Clearing the terminal screen.
    -      Resizing the terminal grid.
    -      Printing the terminal grid content.
    -   Conversion operator to retrieve terminal grid.
-   **Terminal Effects:**
    -      The `TerminalEffects` namespace provides functions to apply effects to the terminal grid:
        -      Changing background and foreground colors.
        -      Changing symbol characters.
        -      Inverting colors.
        -   Adjusting brightness by increment.
        -   Changing the whole terminal to one symbol and color.

## Usage

To use this library in your C++ project, include the necessary header files and compile the source files.
