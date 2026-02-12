cmake_minimum_required(VERSION 3.11)
project(dungeon_crawler)

set(CMAKE_C_STANDARD 99)

# 1. Fetch Raylib automatically
# This is the magic that makes it work on Windows/Linux/Mac seamlessly
include(FetchContent)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/master.tar.gz
)

# 2. Build Raylib
FetchContent_MakeAvailable(raylib)

# 3. Define our executable
add_executable(dungeon_crawler main.c)

# 4. Link Raylib to our game
target_link_libraries(dungeon_crawler raylib)

# Windows-specific: Hide console window in Release mode (optional)
if(WIN32)
    target_link_libraries(dungeon_crawler winmm)
endif()
