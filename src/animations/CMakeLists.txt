# Benjamin Michael Taylor (bentaylorhk)
# 2025

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(animations STATIC ${SOURCES})

target_include_directories(animations PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(animations PRIVATE ncurses)

