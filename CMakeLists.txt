project(project)
cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)

option(BUILD_TESTS "Build test programs" OFF)

file(GLOB_RECURSE Driver_Headers "Driver/*.h")
file(GLOB_RECURSE Driver_Sources "Driver/*.cpp")

file(GLOB_RECURSE Manipulation_Headers "Manipulation/*.h")
file(GLOB_RECURSE Manipulation_Sources "Manipulation/*.cpp")

file(GLOB_RECURSE Creation_Headers "Creation/*.h")
file(GLOB_RECURSE Creation_Sources "Creation/*.cpp")

add_executable(Project ${Driver_Headers} ${Driver_Sources} ${Manipulation_Headers} ${Manipulation_Sources}  ${Creation_Headers} ${Creation_Sources})

if(BUILD_TESTS)
        add_subdirectory(GoogleTests)
        include_directories(GoogleTests/include)

        file(GLOB_RECURSE Tests "Tests/*.cpp")
        set(Testing_Sources ${Driver_Sources})
        list(REMOVE_ITEM Testing_Sources ${CMAKE_CURRENT_SOURCE_DIR}/Driver/private/main.cpp)

        add_executable(Testing ${Testing_Sources} ${Driver_Headers} ${Tests} ${Manipulation_Headers} ${Manipulation_Sources} ${Creation_Headers} ${Creation_Sources})
        target_link_libraries(Testing PRIVATE gtest)
endif(BUILD_TESTS)