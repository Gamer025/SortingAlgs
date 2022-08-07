cmake_minimum_required (VERSION 3.8)

add_executable (SortingAlgs "src/SortingAlgs.cpp" "include/SortingAlgs.h" "src/MergeSort.cpp" "include/MergeSort.h" "src/Helpers.cpp" "include/Helpers.h")
include_directories ("include")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SortingAlgs PROPERTY CXX_STANDARD 20)
endif()

