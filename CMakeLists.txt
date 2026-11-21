cmake_minimum_required(VERSION 3.16)

project(BlueFoxyyScreepsBot CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

#set(COMPILE_FLAGS --cache ${CMAKE_BINARY_DIR}/cache)
set(LINK_FLAGS -sASSERTIONS=0 -sMALLOC=emmalloc)
add_compile_options(${COMPILE_FLAGS})
add_link_options(${COMPILE_FLAGS} ${LINK_FLAGS})

add_subdirectory(lib)

# If you change TARGET_NAME, please, make corresponding changes in js/main.js.
set(TARGET_NAME loop)

add_executable(${TARGET_NAME})

add_subdirectory(src)

# Clean 'dist' directory
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ls ${CMAKE_SOURCE_DIR}/dist | xargs -I{} rm ${CMAKE_SOURCE_DIR}/dist/{})

# Collect all artifacts in 'dist' directory
# WASM-module and corresponding JS-module must have different base names in order to use them in Screeps, so we add suffixes.
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/${TARGET_NAME}.wasm ${CMAKE_SOURCE_DIR}/dist/${TARGET_NAME}.wasm)
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/${TARGET_NAME}.js ${CMAKE_SOURCE_DIR}/dist/${TARGET_NAME}_mod.js)
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/js/main.js ${CMAKE_SOURCE_DIR}/dist/main.js)

# Auto Upload via grunt (see Gruntfile.js)
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND npx grunt screeps --gruntfile ${CMAKE_SOURCE_DIR}/Gruntfile.js --base ${CMAKE_SOURCE_DIR})
