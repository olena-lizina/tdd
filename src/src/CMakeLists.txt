# Enable filters for Visual Studio
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Project name
project(test_tdd)

# Set headers/sources
file (GLOB SOURCE_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")
file (GLOB INCLUDE_FILES "${PROJECT_SOURCE_DIR}/inc/*.hpp")
find_package(Threads REQUIRED)

# include headers directories
include_directories(${PROJECT_SOURCE_DIR}/inc)

# Build sources as library
add_executable( ${PROJECT_NAME} ${SOURCE_FILES} ${INCLUDE_FILES} )

# Link libraries
target_link_libraries(${PROJECT_NAME} Threads::Threads)

INSTALL(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/test_tdd LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/test_tdd)