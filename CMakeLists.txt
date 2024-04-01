cmake_minimum_required(VERSION 3.22.2 FATAL_ERROR)

# Set the project name with version
project(rppp VERSION 1.0.0)

# Specify C++ standards
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify C standards
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_EXTENSIONS OFF)

# Compiler-specific options
# if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
#     add_compile_options(-Wno-declaration-after-statement) # Adjust as needed
# endif()

# ObjectiveC Standards
if(APPLE)
    enable_language(OBJC)
endif()

# RPATH Settings
set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(INSTALL_RPATH_USE_LINK_PATH TRUE)

list(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/lib" isSystemDir)
if("${isSystemDir}" STREQUAL "-1")
    set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
endif("${isSystemDir}" STREQUAL "-1")

# Configure the header file to pass the version number to the source code
configure_file(theeyeConfig.h.in theeyeConfig.h)

# Add the executable
add_executable(${PROJECT_NAME} src/main.cpp)

# Find and link external dependencies
set(EXTERNAL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../rpp-dev")
set(SDL3_BINARY_DIR "${EXTERNAL_DIR}/SDL")
set(GLM_BINARY_DIR "${EXTERNAL_DIR}/glm")
set(GLFW_BINARY_DIR "${EXTERNAL_DIR}/glfw")
set(ASSIMP_BINARY_DIR "${EXTERNAL_DIR}/assimp")
set(GLAD_LIBRARY_DIR "${EXTERNAL_DIR}/glad")

find_package(glm REQUIRED PATHS "${GLM_BINARY_DIR}" NO_DEFAULT_PATH)
find_package(glfw3 REQUIRED PATHS "${GLFW_BINARY_DIR}" NO_DEFAULT_PATH)
find_package(assimp REQUIRED PATHS "${ASSIMP_BINARY_DIR}" NO_DEFAULT_PATH)

list(APPEND CMAKE_PREFIX_PATH "${SDL3_BINARY_DIR}")
find_package(SDL3 REQUIRED)

target_link_libraries(${PROJECT_NAME}  SDL3::SDL3)

add_library(glad ${GLAD_LIBRARY_DIR}/include/glad/glad.h ${GLAD_LIBRARY_DIR}/src/glad.c)
target_include_directories(glad PUBLIC ${GLAD_LIBRARY_DIR}/include)

target_link_libraries(glad PUBLIC ${CMAKE_DL_LIBS})

include_directories("${SDL3_BINARY_DIR}/include")
link_directories("${SDL3_BINARY_DIR}/lib")

set(EXTRA_INCLUDE_DIRS ${GLAD_LIBRARY_DIR}/include)
set(EXTRA_LIB_DIRS ${SDL3_BINARY_DIR}/lib)
set(EXTRA_LINKS glad)

set(MODULES_DIR ${CMAKE_SOURCE_DIR}/src)
add_subdirectory(${MODULES_DIR})

target_include_directories(${PROJECT_NAME} PUBLIC ${EXTRA_INCLUDE_DIRS})
target_link_directories(${PROJECT_NAME} PUBLIC ${EXTRA_LIB_DIRS})
# Make sure to link the actual SDL3 library, replace 'SDL3' with the correct target name if it's different
target_link_libraries(${PROJECT_NAME} ${EXTRA_LINKS} SDL3)

# Install targets
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/theeyeConfig.h" DESTINATION include)
# Packing options
set(PACK_PACKAGE_VENDOR "eheperson")
set(CPACK_SYSTEM_NAME "enivicivokki")
set(PACKAGE_DIR "${CMAKE_SOURCE_DIR}/out/package")
set(CPACK_PACKAGE_DIRECTORY "${PACKAGE_DIR}")

include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "My funky project")
set(CPACK_PACKAGE_VENDOR ${CPACK_PACKAGE_VENDOR})
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_NAME_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_NAME_VERSION_MINOR}")
set(CPACK_SOURCE_GENERATOR "TGZ")
include(CPack)
