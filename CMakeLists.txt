cmake_minimum_required(VERSION 3.10)
project(AutocompleteKeyboard)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/Trie.cpp
    src/AutocompleteEngine.cpp
)

add_executable(autocomplete_app ${SOURCES})