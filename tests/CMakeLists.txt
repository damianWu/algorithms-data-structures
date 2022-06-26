# Set TARGET(binary file) name for convenience
set(singly_linked_list_test ${PROJECT_NAME}_singly_linked_list_test)


# Executable that runs the tests.
add_executable(
        ${singly_linked_list_test}             # Executable tests file name
        main.test.cpp
        singly_linked_list.test.cpp
)


# Link the executable to needed libraries.
target_link_libraries(
        ${singly_linked_list_test}
        linked_lists_lib          # Library we are testing
        gtest_main              # GTest libraries
        gtest
        pthread
        # gmock_main
        # gmock
        # ${CONAN_LIBS}
)


# Add gtest to be able to run ctest.
add_test(
        NAME singly_linked_list_test                    # Test name
        COMMAND ${singly_linked_list_test} --gtest_color=1   # Executable tests file name
)