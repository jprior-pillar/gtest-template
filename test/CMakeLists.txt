include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

add_executable(factorial_tests factorial_test.cc)
target_link_libraries(factorial_tests PRIVATE sut_factorial gtest_main)
gtest_discover_tests(factorial_tests)

add_executable(my_string_tests my_string_test.cc)
target_link_libraries(my_string_tests PRIVATE sut_my_string gtest_main)
gtest_discover_tests(my_string_tests)

