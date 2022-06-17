add_library(sut_factorial STATIC factorial.cc)
target_include_directories(sut_factorial PUBLIC .)

add_library(sut_my_string STATIC my_string.cc)
target_include_directories(sut_my_string PUBLIC .)

add_library(sut_queue STATIC queue.cc)
target_include_directories(sut_queue PUBLIC .)
