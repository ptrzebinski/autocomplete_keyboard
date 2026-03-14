cmake_minimum_required(VERSION 3.14)
project(AutocompleteKeyboard)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

include_directories(include)

include(FetchContent)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
  GIT_TAG v5.0.0
)
FetchContent_MakeAvailable(ftxui)

set(ENGINE_SOURCES
    src/Trie.cpp
    src/AutocompleteEngine.cpp
)

add_executable(autocomplete_keyboard src/main.cpp ${ENGINE_SOURCES})

target_link_libraries(autocomplete_keyboard
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)