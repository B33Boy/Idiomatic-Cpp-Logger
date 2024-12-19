# ========================= GoogleTest ================================
include(FetchContent)
FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# ========================= GoogleTest ================================


# ========================= Test Executable ===========================
# Test Executable & Linking
add_executable(Tests
    LoggerTests.cpp
)

target_link_libraries(Tests PRIVATE 
    Logger
    GTest::gtest_main
    GTest::gmock_main
)

target_include_directories(Tests PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

# Register tests
include(GoogleTest)
gtest_discover_tests(Tests)

# ========================= Test Executable ===========================