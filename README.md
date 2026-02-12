# How to Build (Windows & Linux)

This project uses **CMake** and **Raylib**.
You do NOT need to install libraries manually. CMake will download Raylib automatically.

## Prerequisites

1.  **CMake**: Download from [cmake.org](https://cmake.org/download/).
2.  **C Compiler**:
    *   **Windows**: Visual Studio Community (with "Desktop development with C++") OR MinGW.
    *   **Linux**: `sudo apt install build-essential git cmake libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev`

## Building on Windows (Visual Studio Code)

1.  Open this folder in VS Code.
2.  Install the "CMake Tools" extension.
3.  Press `Ctrl+Shift+P` -> "CMake: Configure". Select your compiler (e.g., "Visual Studio Community 2022 Release - x64").
4.  Press `F7` (Build) or click "Build" in the status bar.
5.  Press `F5` (Run).

## Building on Windows (Command Line)

```powershell
mkdir build
cd build
cmake ..
cmake --build .
./Debug/dungeon_crawler.exe
```

## Building on Linux

```bash
mkdir build
cd build
cmake ..
make
./dungeon_crawler
```
