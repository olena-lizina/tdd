cmake_minimum_required (VERSION 3.0.2)

# project name
project(TDD)

# for VS folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# c++ standard 14 and other strange variables
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/../install")

if (MSVC)
 string (REPLACE "/MDd" "/MD" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W3 -EHsc -D_SCL_SECURE_NO_WARNINGS")
 set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
 set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} /MP")
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
endif (MSVC)

# includes other CMakeLists.txt
add_subdirectory (src)
add_subdirectory (ut)