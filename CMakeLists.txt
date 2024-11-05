cmake_minimum_required(VERSION 3.10)
project(SkidToolSet)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    main.cpp
)

set(HEADERS
    func/DDos.hpp
    func/displayer.hpp
    func/doxcreator.hpp
    func/ipaddrlkup.hpp
    func/randipgen.hpp
)

# Include CPR using FetchContent
include(FetchContent)
FetchContent_Declare(cpr
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG bb01c8db702fb41e5497aee9c0559ddf4bf13749
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE)  
FetchContent_MakeAvailable(cpr)

# Nlohmann JSON
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
FetchContent_MakeAvailable(json)

add_executable(SkidToolSet ${SOURCES} ${HEADERS})

target_link_libraries(SkidToolSet PRIVATE cpr::cpr)
target_link_libraries(SkidToolSet PRIVATE nlohmann_json::nlohmann_json)

target_include_directories(SkidToolSet PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} include helpers)
