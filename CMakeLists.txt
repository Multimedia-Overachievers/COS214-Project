cmake_minimum_required(VERSION 3.22.0)

project(project VERSION 1.1.2)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SFML_VERSION "2.5.1")

option(BUILD_TESTS "Build test programs" OFF)

file(GLOB_RECURSE Driver_Headers "Driver/*.h")
file(GLOB_RECURSE Driver_Sources "Driver/*.cpp")

file(GLOB_RECURSE Manipulation_Headers "Manipulation/*.h")
file(GLOB_RECURSE Manipulation_Sources "Manipulation/*.cpp")

file(GLOB_RECURSE Creation_Headers "Creation/*.h")
file(GLOB_RECURSE Creation_Sources "Creation/*.cpp")

include(FetchContent)

set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
        sfml GIT_REPOSITORY 
        GIT_REPOSITORY "https://github.com/SFML/SFML.git"
        GIT_TAG        "${SFML_VERSION}"
)

FetchContent_GetProperties(sfml)
if(NOT sfml_POPULATED)
    FetchContent_Populate(sfml)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()

add_executable(Project ${Driver_Headers} ${Driver_Sources} ${Manipulation_Headers} ${Manipulation_Sources}  ${Creation_Headers} ${Creation_Sources})


target_link_libraries(Project PRIVATE
        sfml-audio
        sfml-graphics
        sfml-system
        sfml-window
)

target_compile_options(Project PRIVATE -Wall)

if(BUILD_TESTS)
        add_subdirectory(GoogleTests)
        include_directories(GoogleTests/include)

        file(GLOB_RECURSE Tests "Tests/*.cpp")
        set(Testing_Sources ${Driver_Sources})
        list(REMOVE_ITEM Testing_Sources ${CMAKE_CURRENT_SOURCE_DIR}/Driver/private/main.cpp)

        add_executable(Testing ${Testing_Sources} ${Driver_Headers} ${Tests} ${Manipulation_Headers} ${Manipulation_Sources} ${Creation_Headers} ${Creation_Sources})
        target_link_libraries(Testing PRIVATE gtest)
endif(BUILD_TESTS)
unset(BUILD_TESTS CACHE)



