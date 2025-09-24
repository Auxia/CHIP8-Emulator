add_executable(test_chip8
    test_memory.cpp
)
target_link_libraries(test_chip8 PRIVATE
    GTest::gtest_main
)
add_test(NAME cpu_tests COMMAND test_chip8)
