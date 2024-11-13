# JYRO - A C++ Based Compiler

JYRO is a compiler for a custom programming language designed by me `.jj` files. It converts source code into assembly, builds an object file, links it, and runs it on Linux systems using GNU ld. This project represents `version 1.0` of the compiler, focusing on the core functionalities of parsing, tokenization, and assembly generation.

## Features

- **Parses `.jj` files**: Reads source code files with a `.jj` extension.
- **Tokenizes source code**: Breaks down the code into meaningful tokens.
- **Converts to assembly**: Transforms tokens into assembly language instructions.
- **Exports assembly output**: Creates an assembly file.
- **Builds object file**: Compiles the assembly file into an object file.
- **Links and executes**: Uses GNU ld for linking (Linux-only compatibility).

## Getting Started

### Prerequisites

- **Linux OS**: JYRO uses GNU ld for linking, so it is compatible with Linux systems only.
- **CMake**: For building the project.
- **C++ Compiler**: Required for compiling the source code.

### Installation

1. **Clone the repository**:

   ```bash
   git clone https://github.com/JeetChauhan17/JYRO-Compiler.git
   cd JYRO-Compiler
    ```
2. **Create a build directory**:

    ```bash
    mkdir build
    ```
3. **Build the project**:
    ```bash
    cmake -S . -B build/
    cmake --build build/
    ```
### Usage

1. Place a `.jj` file (e.g., test.jj) in the root directory.

2. Compile and execute:

  ```bash
    ./build/jyro test.jj
    ./build/out
  ```
3. DONE !

### Contributing
Contributions are welcome! Please submit a pull request for any enhancements or bug fixes.

### License
This project is licensed under the MIT License. See the LICENSE file for more information.
