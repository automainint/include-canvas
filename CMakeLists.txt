cmake_minimum_required(VERSION 3.18)

project(
  IncludeCanvas
    VERSION 0.1.1
    LANGUAGES CXX
)

add_library(canvas INTERFACE)
add_executable(example)

target_compile_features(
  canvas INTERFACE cxx_std_20 
)

set_property(TARGET example PROPERTY CXX_STANDARD 20)

add_compile_definitions(UNICODE _UNICODE)

target_include_directories(
  canvas INTERFACE
    include
)

target_include_directories(
  example PUBLIC
    include
)

target_sources(
  example
    PRIVATE source/examples/example.cpp
)

include(GNUInstallDirs)

install(
  DIRECTORY ${PROJECT_SOURCE_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
  TARGETS example
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  COMPONENT IncludeCanvas_Example_Runtime
)
