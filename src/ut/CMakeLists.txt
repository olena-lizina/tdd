# Enable filters for Visual Studio
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Project name
project(ut)

####### for building GTEST
set(GTEST_ROOT "${CMAKE_SOURCE_DIR}/../libs/GTEST")
set(GTEST_HEADER_DIRS "${GTEST_ROOT}/include" CACHE INTERNAL "GTEST header folder")
set(GTEST_LIBS ${GTEST_ROOT}/lib/gmock${CMAKE_STATIC_LIBRARY_SUFFIX}
		${GTEST_ROOT}/lib/gtest${CMAKE_STATIC_LIBRARY_SUFFIX}
		${GTEST_ROOT}/lib/gmock_main${CMAKE_STATIC_LIBRARY_SUFFIX}
		${GTEST_ROOT}/lib/gtest_main${CMAKE_STATIC_LIBRARY_SUFFIX}
		CACHE INTERNAL "${GTEST_LIBRARY_NAME} libraries")
####### 

# Set headers/sources
file (GLOB SOURCE_FILES "${PROJECT_SOURCE_DIR}/*.cpp")
file (GLOB INCLUDE_FILES "${PROJECT_SOURCE_DIR}/*.hpp")
file (GLOB EXTERNAL_SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/src/inc" "${CMAKE_SOURCE_DIR}/src/src/src")
source_group("test_files" FILES ${EXTERNAL_SOURCE_FILES})
find_package(Threads REQUIRED)

# include headers directories
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/../src/inc)
include_directories(${GTEST_HEADER_DIRS})
                         
# Build sources as library
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${INCLUDE_FILES} ${EXTERNAL_SOURCE_FILES})

# Link libraries
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBS} Threads::Threads)

add_test(${PROJECT_NAME} ${PROJECT_NAME})

INSTALL(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/tests LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/tests)