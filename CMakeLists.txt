cmake_minimum_required(VERSION 3.10)

project(gitty VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(vendor/FTXUI)
add_subdirectory(vendor/libgit2)

add_executable(gitty 
    src/gitty.cpp
    src/events/event.cpp
)

target_link_libraries(gitty
    PRIVATE ftxui::screen
    PRIVATE ftxui::dom
    PRIVATE ftxui::component
    PRIVATE git2
)

target_include_directories(gitty
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/src
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if (MSVC)
else()
  target_compile_options(git-tui
    PRIVATE "-Wall"
    PRIVATE "-Wextra"
    PRIVATE "-pedantic"
    PRIVATE "-Werror"
    PRIVATE "-Wdeprecated"
    )
endif()

install(TARGETS gitty RUNTIME DESTINATION "bin")