cmake_minimum_required(VERSION 3.10)
project(SkidToolSet)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
set(SOURCES
    func/DDos.cpp
    func/displayer.cpp
    main.cpp
)

# Add the header files
set(HEADERS
    include/DDos.hpp
    include/Displayer.hpp
)

# Create the executable
add_executable(SkidToolSet ${SOURCES})

# Add the header files to the include path
target_include_directories(SkidToolSet PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})