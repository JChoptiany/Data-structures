cmake_minimum_required(VERSION 3.10)

project(data_structures)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")

set(LIBRARY_OUTPUT_PATH build/)
set(BINARY_OUTPUT_PATH build/)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

include(External_GTest.cmake)

# SRC
include_directories(Include)

# TEST
include_directories(Test)

add_executable(data_structures "main.cpp")

set(TEST_BINARY_FILES $<TARGET_OBJECTS:source_objects_lib>
                      ${TEST_FILES}
                      ${MAIN_TEST})

add_executable(data_structures_UT Test/singlyLinkedListTests.cpp)
target_link_libraries(data_structures_UT 	${GTEST_MAIN_LIBRARY}
                                            ${GTEST_LIBRARY}
                                            ${GMOCK_MAIN_LIBRARY}
                                            ${GMOCK_LIBRARY})