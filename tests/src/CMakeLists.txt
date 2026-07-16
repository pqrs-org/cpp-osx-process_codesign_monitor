cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 23)

add_compile_options(-Wall)
add_compile_options(-Werror)
add_compile_options(-O2)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

include_directories(${CMAKE_CURRENT_LIST_DIR}/../../include)
include_directories(SYSTEM ${CMAKE_CURRENT_LIST_DIR}/../../vendor/vendor/include)

project(test)

add_executable(
  test
  test.cpp
)

add_executable(
  integration_test
  integration_test.cpp
)

target_compile_definitions(
  integration_test
  PRIVATE
  PROCESS_CODESIGN_TEST_FIXTURES_DIR="${CMAKE_CURRENT_LIST_DIR}/../app/dist"
)

target_link_libraries(
  test
  pthread
  "-framework CoreFoundation"
  "-framework Security"
)

target_link_libraries(
  integration_test
  pthread
  "-framework CoreFoundation"
  "-framework Security"
)
