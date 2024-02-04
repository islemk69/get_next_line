# get_next_line - Custom C Function for Reading Lines

Welcome to the `get_next_line` project, a custom C function designed to read lines from a file descriptor. This project focuses on the core functionality of reading lines from input, providing an efficient and reliable solution for handling text files.

## Key Features

- Reads lines from a file descriptor, one line at a time.
- Supports reading from multiple file descriptors simultaneously.
- Handles dynamic memory allocation to avoid buffer overflows.
- Compatible with UNIX-like systems, making it versatile for various environments.
- Simplifies reading and processing of text data from files.

## Getting Started

1. Clone this repository into your project directory.
2. Include the `get_next_line.c` and `get_next_line.h` files in your project.
3. Call the `get_next_line` function to read lines from a file descriptor.
4. Handle the returned line(s) and free memory as needed.

## Example Usage

```c
#include "get_next_line.h"

int main() {
    int fd = open("sample.txt", O_RDONLY);
    char *line;
    
    while (get_next_line(fd, &line) > 0) {
        // Process and use the read line as needed.
        printf("Read Line: %s\n", line);
        free(line); // Don't forget to free the allocated memory.
    }
    
    close(fd);
    return 0;
}
