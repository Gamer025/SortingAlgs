cmake_minimum_required (VERSION 3.8)

add_executable (SortingAlgs "src/SortingAlgs.cpp" "include/SortingAlgs.h" "src/MergeSort.cpp" "include/MergeSort.h" "src/Helpers.cpp" "include/Helpers.h" "src/xmalloc.cpp" "include/xmalloc.h" "../tracy/TracyClient.cpp")
include_directories ("include")
include_directories ("../tracy/")
add_compile_definitions("TRACY_ENABLE")
#add_compile_definitions("TRACY_NO_EXIT")
add_compile_definitions("TRACY_TIMER_FALLBACK")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SortingAlgs PROPERTY CXX_STANDARD 20)
endif()

