# BugSquash

A small C++ game. This README explains how to build and run the game locally using CMake.

> If this repository uses a specific game framework or library (SDL2, SFML, OpenGL, GLFW, etc.), install those libraries before building. If you're not sure which libraries are required, look for CMakeLists.txt or include statements in the `src/` directory.

## Prerequisites

- A C++ toolchain (GCC, Clang, or MSVC)
- CMake 3.15+ (older versions may work but 3.15+ recommended)
- A build tool: make, Ninja, or Visual Studio (on Windows)
- Any external libraries the project requires (example: SDL2, SFML). Install via your system package manager or from the library website.

Common package manager commands:

- Ubuntu / Debian:
  - sudo apt update && sudo apt install -y build-essential cmake pkg-config libglm-dev
  - Install framework-specific packages if required, e.g. `libsdl2-dev`, `libsdl2-image-dev`.

- Fedora / CentOS / RHEL:
  - sudo dnf install -y gcc-c++ cmake make pkgconfig
  - Install extras like `SDL2-devel` if needed.

- macOS (Homebrew):
  - brew install cmake pkg-config
  - brew install sdl2    # example if SDL2 is needed

- Windows:
  - Install Visual Studio (Desktop development with C++) or the Build Tools.
  - Install CMake for Windows: https://cmake.org/download/
  - Optionally install vcpkg or MSYS2 for dependencies.

## Build (recommended, out-of-source)

From the repository root:

1. Create a build directory and configure with CMake:

   - Unix / macOS (Bash / zsh):
     ```bash
     mkdir -p build
     cd build
     cmake -DCMAKE_BUILD_TYPE=Release ..
     ```

   - Use Ninja (faster parallel builds):
     ```bash
     mkdir -p build
     cd build
     cmake -G Ninja -DCMAKE_BUILD_TYPE=Release ..
     ```

   - Windows (Visual Studio generator):
     ```powershell
     mkdir build
     cd build
     cmake -G "Visual Studio 17 2022" ..
     # or choose the generator that matches your MSVC version
     ```

2. Build the project:

   - Unix / macOS with make:
     ```bash
     cmake --build . --config Release -- -j$(nproc)
     ```

   - With Ninja:
     ```bash
     cmake --build . --config Release
     ```

   - Windows (Visual Studio):
     ```powershell
     cmake --build . --config Release
     # or open the generated .sln in Visual Studio and build from the IDE
     ```

CMake will produce one or more executables in the build directory (often inside build/bin, build/src, or directly in build/). If you are unsure of the output binary name, list the build directory or inspect CMakeLists.txt for `add_executable(...)` lines.

## Run the game

From the build directory, run the produced executable. Example (replace `BugSquash` with the actual executable name if different):

- Unix / macOS:
  ```bash
  ./BugSquash
  # or
  ./bin/BugSquash
  ```

- Windows (PowerShell / CMD):
  ```powershell
  .\Release\BugSquash.exe
  # or if using Visual Studio debug build
  .\Debug\BugSquash.exe
  ```

If the game requires assets (images, sounds, levels), ensure they are located in the expected runtime path (often a top-level `assets/` or `data/` folder). If the executable cannot find assets, run it from the project root or copy the assets into the build output folder.

## Running with CTest (if available)

If the project includes tests and CTest support:

```bash
cd build
ctest --output-on-failure
```

## Troubleshooting

- Missing libraries: If the configure step fails complaining about missing packages, install the required development packages (e.g., `libsdl2-dev`) or point CMake to the correct locations with `-D` flags (for example, `-DSDL2_DIR=/path/to/sdl2`).
- Compiler errors: Ensure your compiler supports C++17/C++20 as required by the project. Pass `-DCMAKE_CXX_STANDARD=17` (or 20) if needed during configuration.
- Runtime asset errors: Check the README or the code for the path where assets are loaded, and run the executable from that directory or set the working directory accordingly.

## Project structure (expected)

A typical layout for a C++/CMake game project:

```
/CMakeLists.txt
/src/        # C++ source files
/include/    # Public headers
/assets/     # Images, sounds, levels
/build/      # (created by you) build output
/tests/      # optional tests
```

## Contributing

If you'd like to contribute, open an issue or a pull request. Please include build logs and platform information if you encounter build problems.

## Contact / Issues

Open an issue on this repository with details about the problem, OS, compiler, and steps to reproduce.

---

If you want, I can update this README to include exact build commands and the exact executable name once you confirm the output binary name or point me to the CMakeLists.txt and the source layout. I will now save this README.md into the repository.
