cmake_minimum_required(VERSION 3.10)
project(SkidToolSet)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
set(SOURCES
    func/DDos.cpp
    func/displayer.cpp
    func/ipaddrlkup.cpp
    main.cpp
)

set(HEADERS
    include/DDos.hpp
    include/Displayer.hpp
    include/ipaddrlkup.hpp
)

# Include CPR using FetchContent
include(FetchContent)
FetchContent_Declare(cpr
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG bb01c8db702fb41e5497aee9c0559ddf4bf13749)  # Replace with your desired git commit from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

# Create the executable
add_executable(SkidToolSet ${SOURCES})

# Link CPR to the executable
target_link_libraries(SkidToolSet PRIVATE cpr::cpr)

# Add the header files to the include path
target_include_directories(SkidToolSet PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} include)
