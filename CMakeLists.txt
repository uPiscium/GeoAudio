cmake_minimum_required(VERSION 3.10)
project(
    GeoAudio
    VERSION 1.0.0
    DESCRIPTION "A library for audio processing"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE source RELATIVE ${PROJECT_SOURCE_DIR} "../src/*.cpp"})

add_library(GeoAudio SHARED ${source})

target_include_directories(GeoAudio INTERFACE "../includes/")

if (WIN32)
    target_link_libraries(GeoAudio PRIVATE "../resources/libs/OpenAL32")
endif(WIN32)

set_target_properties(
    GeoAudio
    PROPERTIES
    VERSION ${PROJECT_VERSION}
)

