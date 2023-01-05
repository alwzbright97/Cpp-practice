# /lib/CMakeLists.txt

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    $(CMAKE_CURRENT_SOURCE_DIR)/*.cc
)

# Static Library : shape
add_library(shape STATIC {SRC_FILES})

# Header file path when compiling
target_include_directories(shape PUBLIC ${CMAKE_SOURCE_DIR}/includes)

# Compile options
target_compile_options(shape PRIVATE -Wall -Werror)