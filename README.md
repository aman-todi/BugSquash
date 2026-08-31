# BugSquash

A desktop bug-squashing game built with C++ and [wxWidgets](https://www.wxwidgets.org/). Bugs of different types (features, garbage, redundancy, viruses, and more) crawl across the screen and the player clicks to squash them and rack up points, tracked on a scoreboard. Levels are defined declaratively in XML files.

## Project layout

```
CMakeLists.txt      # top-level build: executable "BugSquash"
main.cpp             # entry point (wxIMPLEMENT_APP)
GameApp.cpp / .h     # application bootstrap (wxApp)
pch.h                # precompiled header
GameLib/              # core game library (Game, Bug variants, GameView, Scoreboard, LevelLoader, ...)
data/                 # level definitions (level0.xml - level3.xml)
images/               # sprite and splat art assets
tests/                # GoogleTest unit tests (Tests_run)
```

`data/` and `images/` are copied into the build output directory automatically by CMake.

## Prerequisites

- A C++17 toolchain (GCC, Clang, or MSVC)
- CMake 3.24+
- [wxWidgets](https://www.wxwidgets.org/) development libraries (`core base xrc html xml` components)
- Internet access on first configure (GoogleTest is fetched automatically via `FetchContent` for the test target)

Installing wxWidgets:

- Ubuntu / Debian: `sudo apt install -y build-essential cmake libwxgtk3.2-dev`
- Fedora: `sudo dnf install -y gcc-c++ cmake wxGTK-devel`
- macOS (Homebrew): `brew install cmake wxwidgets`
- Windows: install wxWidgets from https://www.wxwidgets.org/downloads/ or via [vcpkg](https://vcpkg.io) (`vcpkg install wxwidgets`), plus Visual Studio with the Desktop C++ workload.

## Building

From the repository root:

```bash
mkdir -p build
cd build
cmake ..
cmake --build . -j
```

This produces the `BugSquash` executable (on Windows/macOS it's built as a `WIN32`/`MACOSX_BUNDLE` app) along with copies of `data/` and `images/` alongside it.

## Running the game

From the build directory:

```bash
./BugSquash        # Unix / macOS
```

```powershell
.\BugSquash.exe     # Windows
```

Run it from the build directory (or ensure `data/` and `images/` sit next to the executable) so level and image assets load correctly.

## Running tests

The `tests/` directory builds a `Tests_run` target using GoogleTest:

```bash
cd build
./tests/Tests_run
```

## Contributing

Open an issue or pull request. Please include your OS, compiler, and build logs for any build problems.
