cmake_minimum_required(VERSION 3.16)
project(GravitySim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include paths (for glad/glfw headers, etc.)
include_directories(dependencies/include)
include_directories(include)

# You only need to link to actual libraries, not header folders
link_directories(dependencies/library)

# Find all .cpp files under src/ (excluding main.cpp)
file(GLOB_RECURSE SOURCES "src/*.c*")
list(FILTER SOURCES EXCLUDE REGEX ".*main\\.cpp$")

# Add executable from main.cpp + the other sources
add_executable(gravity_sim src/main.cpp  ${SOURCES})

# Link against GLFW + system frameworks (macOS style)
target_link_libraries(gravity_sim
    ${CMAKE_SOURCE_DIR}/dependencies/library/libglfw.3.4.dylib
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
    "-framework CoreFoundation"
)
