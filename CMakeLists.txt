cmake_minimum_required(VERSION 3.10)
project(SkidToolSet)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    func/DDos.cpp
    func/displayer.cpp
    func/ipaddrlkup.cpp
    func/doxcreator.cpp
    func/randipgen.cpp
    main.cpp
)

set(HEADERS
    include/DDos.hpp
    helpers/Displayer.hpp
    include/ipaddrlkup.hpp
    include/doxcreator.hpp
    include/randipgen.hpp
)

# Include CPR using FetchContent
include(FetchContent)
FetchContent_Declare(cpr
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG bb01c8db702fb41e5497aee9c0559ddf4bf13749)  
FetchContent_MakeAvailable(cpr)

add_executable(SkidToolSet ${SOURCES})

target_link_libraries(SkidToolSet PRIVATE cpr::cpr)

target_include_directories(SkidToolSet PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} include)
