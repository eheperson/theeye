#------------------------------------------------------------------------------------------------------------
# -- Some Extra Settings For Maintainability
#
set(SOURCES_DIR "${EXTERNAL_DIR}/sources")
#
set(GLM_SOURCE_DIR "${SOURCES_DIR}/glm")
set(GLM_BINARY_DIR "${EXTERNAL_DIR}/glm")
#
set(GLFW_SOURCE_DIR "${SOURCES_DIR}/glfw")
set(GLFW_BINARY_DIR "${EXTERNAL_DIR}/glfw")
#
set(ASSIMP_SOURCE_DIR "${SOURCES_DIR}/assimp")
set(ASSIMP_BINARY_DIR "${EXTERNAL_DIR}/assimp")
#
set(GLAD_SOURCE_DIR "${SOURCES_DIR}/glad")
set(GLAD_LIBRARY_DIR "${EXTERNAL_DIR}/glad")
#
set(SDL2_SOURCE_DIR "${SOURCES_DIR}/SDL")
set(SDL2_BINARY_DIR "${EXTERNAL_DIR}/sdl2")
#
#------------------------------------------------------------------------------------------------------------
# download all git submodules of they do not downloaded
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()
#------------------------------------------------------------------------------------------------------------
# --- OpenGL
find_package(OpenGL REQUIRED)
if(OpenGL_FOUND)
    # pass
else()
    message(FATAL_ERROR "no OpenGL, sad day")
endif()
#
#------------------------------------------------------------------------------------------------------------
# --- GLM
# --- Check GLM
if(NOT EXISTS "${GLM_SOURCE_DIR}/CMakeLists.txt")
    message(FATAL_ERROR "The glm submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()
# --- Find GLM
find_package(glm REQUIRED PATHS "${GLM_BINARY_DIR}" NO_DEFAULT_PATH)
if(glm_FOUND)
    message(STATUS "GLM included at ${GLM_INCLUDE_DIRS}")
    # not required for now
else()
    message(FATAL_ERROR "no glm, sad day")
endif()
#
#------------------------------------------------------------------------------------------------------------
# --- GLFW
# --- Check GLFW
if(NOT EXISTS "${GLFW_SOURCE_DIR}/CMakeLists.txt")
    message(FATAL_ERROR "The glfw submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()
# --- Find GLFW
find_package(glfw3 REQUIRED PATHS "${GLFW_BINARY_DIR}" NO_DEFAULT_PATH)
if(glfw3_FOUND)
    message(STATUS "Found glfw3 in ${GLFW3_INCLUDE_DIR}")
    # not required for now
else()
    message(FATAL_ERROR "no glfw3, sad day")
endif()
#
#------------------------------------------------------------------------------------------------------------
# --- ASSIMP
# --- Check ASSIMP
if(NOT EXISTS "${ASSIMP_SOURCE_DIR}/CMakeLists.txt")
    message(FATAL_ERROR "The assimp submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()
# --- Find ASSIMP
find_package(assimp REQUIRED PATHS "${ASSIMP_BINARY_DIR}" NO_DEFAULT_PATH)
if(assimp_FOUND)
    message(STATUS "Found ASSIMP in ${ASSIMP_INCLUDE_DIR}")
    # not required for now
else()
    message(FATAL_ERROR "no assimp, sad day")
endif()
#
#------------------------------------------------------------------------------------------------------------
# --- Check GLAD Module
if(NOT EXISTS "${GLAD_SOURCE_DIR}/CMakeLists.txt")
    message(FATAL_ERROR "The sdl2 submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()
# --- set the glad module
add_library(glad ${GLAD_LIBRARY_DIR}/include/glad/glad.h ${GLAD_LIBRARY_DIR}/src/glad.c )
# target_link_libraries(glad  PUBLIC glfw OpenGL::GL ${CMAKE_DL_LIBS} )
target_link_libraries(glad PUBLIC ${CMAKE_DL_LIBS})
target_include_directories(glad PUBLIC ${GLAD_LIBRARY_DIR}/include/)
#
list(APPEND EXTRA_INCLUDE_DIRS ${GLAD_LIBRARY_DIR}/include/)
list(APPEND EXTRA_LINKS glad)
#
set(EXTRA_INCLUDE_DIRS "${EXTRA_INCLUDE_DIRS}" PARENT_SCOPE)
set(EXTRA_LINKS "${EXTRA_LINKS}" PARENT_SCOPE)
#
#------------------------------------------------------------------------------------------------------------
# --- Check SDL2 Module
if(NOT EXISTS "${SDL2_SOURCE_DIR}/CMakeLists.txt")
    message(FATAL_ERROR "The sdl2 submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()
# --- Find SDL2 Builded Binaries
find_package(SDL2 REQUIRED PATHS "${SDL2_BINARY_DIR}" NO_DEFAULT_PATH)
if(SDL2_FOUND)
    # append in local scope
    list(APPEND EXTRA_INCLUDE_DIRS ${SDL2_INCLUDE_DIRS})
    # list(APPEND EXTRA_LIB_DIRS ${xxxx})
    list(APPEND EXTRA_LINKS ${SDL2_LIBRARIES})
    # set in parent scope
    set(EXTRA_INCLUDE_DIRS "${EXTRA_INCLUDE_DIRS}" PARENT_SCOPE)
    # set(EXTRA_LIB_DIRS "${EXTRA_LIB_DIRS}" PARENT_SCOPE)
    set(EXTRA_LINKS "${EXTRA_LINKS}" PARENT_SCOPE)
    # status messages
    message(STATUS "SDL2 Libs : ${SDL2_LIBRARIES}")
    message(STATUS "SDL2 Include Dirs : ${SDL2_INCLUDE_DIRS}")
    # install 3Rd package
    install(FILES "${SDL2_BINARY_DIR}/bin/sdl2-config" DESTINATION bin)
    install(DIRECTORY "${SDL2_BINARY_DIR}/include/" DESTINATION include)
    install(DIRECTORY ${SDL2_BINARY_DIR}/lib/ DESTINATION lib
        REGEX "/cmake$" EXCLUDE
        REGEX "/pkgconfig$" EXCLUDE
    )    
else()
    message(FATAL_ERROR "no sdl2, sad day")
endif()
#
#------------------------------------------------------------------------------------------------------------