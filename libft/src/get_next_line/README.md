# Project: get_next_line

## Overview
The `get_next_line` project is a function designed to read a line from a file descriptor and return it with each function call. It ensures seamless retrieval of successive lines from the input source.

## Features
- Retrieves and returns the next line from a given file descriptor.
- Handles multiple file descriptors simultaneously for enhanced versatility.
- Provides a simple and efficient way to read lines from various sources.

## Usage
1. Include the `get_next_line.h` header file in your project.
2. Call the `get_next_line` function, passing the file descriptor as an argument.
3. The function will return the next line from the file descriptor on each invocation.

## Bonus Feature
The bonus part of the project allows the function to handle multiple file descriptors concurrently. This means you can efficiently read lines from different sources in a single program.

## Implementation
The implementation ensures robust handling of file descriptors, managing memory efficiently, and providing a seamless experience for the user.

## Example
```c
#include "get_next_line.h"

int main(void) {
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);

    char *line1 = get_next_line(fd1);
    char *line2 = get_next_line(fd2);

    // Process lines as needed...

    // Remember to free allocated memory when done.
    free(line1);
    free(line2);

    return 0;
}
```

## Notes
- Make sure to check for errors and handle them appropriately.
- Free allocated memory when you are done using the lines.

Feel free to contribute, report issues, or suggest improvements!