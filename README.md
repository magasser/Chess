### Prerequisites

Before building the project, ensure you have the following installed:

1. **CMake**: Version 3.16 or higher

   - You can download it from the [CMake website](https://cmake.org/download/) or install it via package managers.

2. **Ninja Build System**: Required for the build process.

   - Install using a package manager or download from [Ninja's GitHub releases](https://github.com/ninja-build/ninja/releases).

3. **Compiler**: A compatible C compiler.
   - Install [Visual Studio](https://visualstudio.microsoft.com/de/downloads/) with the "Desktop development with C++" workload, which includes the MSVC compiler.
   - Alternatively, you can use [MSYS2](https://www.msys2.org/) to install MinGW GCC on Windows.

With these prerequisites in place, you can proceed with the configuration and building the project using CMake.

### Build the Project

To build the project using CMake and Ninja, follow these steps:

1. **Generate Build Files**: Run the following command to configure the project and generate build files using the Ninja build system:

   `cmake -G Ninja -S . -B build -DCMAKE_BUILD_TYPE=Release`

2. **Build the Project**: Use the following command to compile the project:

   `cmake --build build --config Release`

After running these commands, the compiled binaries will be located in the `build` directory.
