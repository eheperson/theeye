# Window Module
option(USE_Window "Window Module" ON)
if(USE_Window)
    message(STATUS "Window module Found")
    add_definitions(-DUSE_Window)
    add_library(window_module Window/Window.h Window/Window.cxx)
    target_include_directories(window_module PUBLIC ${EXTRA_INCLUDE_DIRS} ${PROJECT_BINARY_DIR})
    target_link_directories(window_module PUBLIC ${EXTRA_LIB_DIRS})
    target_link_libraries(window_module PUBLIC ${EXTRA_LINKS})
    list(APPEND EXTRA_INCLUDE_DIRS "${MODULES_DIR}/Window")
    list(APPEND EXTRA_LIB_DIRS "window_module")
    list(APPEND EXTRA_LINKS window_module)
    set(EXTRA_INCLUDE_DIRS "${EXTRA_INCLUDE_DIRS}" PARENT_SCOPE)
    set(EXTRA_LIB_DIRS "${EXTRA_LIB_DIRS}" PARENT_SCOPE)
    set(EXTRA_LINKS "${EXTRA_LINKS}" PARENT_SCOPE)
    install(TARGETS window_module DESTINATION lib)
    install(FILES ${MODULES_DIR}/Window/Window.h DESTINATION include)
endif()

# Application Module
option(USE_Application "Application Module" ON)
if(USE_Application)
    message(STATUS "Application module Found")
    add_definitions(-DUSE_Application)
    add_library(application_module Application/Application.h Application/Application.cxx)
    target_include_directories(application_module PUBLIC ${EXTRA_INCLUDE_DIRS} ${PROJECT_BINARY_DIR})
    target_link_directories(application_module PUBLIC ${EXTRA_LIB_DIRS})
    target_link_libraries(application_module PUBLIC ${EXTRA_LINKS})
    list(APPEND EXTRA_INCLUDE_DIRS "${MODULES_DIR}/Application")
    list(APPEND EXTRA_LIB_DIRS "application_module")
    list(APPEND EXTRA_LINKS application_module)
    set(EXTRA_INCLUDE_DIRS "${EXTRA_INCLUDE_DIRS}" PARENT_SCOPE)
    set(EXTRA_LIB_DIRS "${EXTRA_LIB_DIRS}" PARENT_SCOPE)
    set(EXTRA_LINKS "${EXTRA_LINKS}" PARENT_SCOPE)
    install(TARGETS application_module DESTINATION lib)
    install(FILES ${MODULES_DIR}/Application/Application.h DESTINATION include)
endif()

# Shader Module
option(USE_Shader "Shader Module" ON)
if(USE_Shader)
    message(STATUS "Shader module Found")
    add_definitions(-DUSE_Shader)
    add_library(shader_module Shader/Shader.h Shader/Shader.cxx)
    target_include_directories(shader_module PUBLIC ${EXTRA_INCLUDE_DIRS} ${PROJECT_BINARY_DIR})
    target_link_directories(shader_module PUBLIC ${EXTRA_LIB_DIRS})
    target_link_libraries(shader_module PUBLIC ${EXTRA_LINKS})
    list(APPEND EXTRA_INCLUDE_DIRS "${MODULES_DIR}/Shader")
    list(APPEND EXTRA_LIB_DIRS "shader_module")
    list(APPEND EXTRA_LINKS shader_module)
    set(EXTRA_INCLUDE_DIRS "${EXTRA_INCLUDE_DIRS}" PARENT_SCOPE)
    set(EXTRA_LIB_DIRS "${EXTRA_LIB_DIRS}" PARENT_SCOPE)
    set(EXTRA_LINKS "${EXTRA_LINKS}" PARENT_SCOPE)
    install(TARGETS shader_module DESTINATION lib)
    install(FILES ${MODULES_DIR}/Shader/Shader.h DESTINATION include)
endif()

# Drawable Module
option(USE_Drawable "Drawable Module" ON)
if(USE_Drawable)
    message(STATUS "Drawable module Found")
    add_definitions(-DUSE_Drawable)
    add_library(drawable_module Drawable/Drawable.h Drawable/Drawable.cxx)
    target_include_directories(drawable_module PUBLIC ${EXTRA_INCLUDE_DIRS} ${PROJECT_BINARY_DIR})
    target_link_directories(drawable_module PUBLIC ${EXTRA_LIB_DIRS})
    target_link_libraries(drawable_module PUBLIC ${EXTRA_LINKS})
    list(APPEND EXTRA_INCLUDE_DIRS "${MODULES_DIR}/Drawable")
    list(APPEND EXTRA_LIB_DIRS "drawable_module")
    list(APPEND EXTRA_LINKS drawable_module)
    set(EXTRA_INCLUDE_DIRS "${EXTRA_INCLUDE_DIRS}" PARENT_SCOPE)
    set(EXTRA_LIB_DIRS "${EXTRA_LIB_DIRS}" PARENT_SCOPE)
    set(EXTRA_LINKS "${EXTRA_LINKS}" PARENT_SCOPE)
    install(TARGETS drawable_module DESTINATION lib)
    install(FILES ${MODULES_DIR}/Drawable/Drawable.h DESTINATION include)
endif()

# Camera Module
option(USE_Camera "Camera Module" ON)
if(USE_Camera)
    message(STATUS "Camera module Found")
    add_definitions(-DUSE_Camera)
    add_library(camera_module Camera/Camera.h Camera/Camera.cxx)
    target_include_directories(camera_module PUBLIC ${EXTRA_INCLUDE_DIRS} ${PROJECT_BINARY_DIR})
    target_link_directories(camera_module PUBLIC ${EXTRA_LIB_DIRS})
    target_link_libraries(camera_module PUBLIC ${EXTRA_LINKS})
    list(APPEND EXTRA_INCLUDE_DIRS "${MODULES_DIR}/Camera")
    list(APPEND EXTRA_LIB_DIRS "camera_module")
    list(APPEND EXTRA_LINKS camera_module)
    set(EXTRA_INCLUDE_DIRS "${EXTRA_INCLUDE_DIRS}" PARENT_SCOPE)
    set(EXTRA_LIB_DIRS "${EXTRA_LIB_DIRS}" PARENT_SCOPE)
    set(EXTRA_LINKS "${EXTRA_LINKS}" PARENT_SCOPE)
    install(TARGETS camera_module DESTINATION lib)
    install(FILES ${MODULES_DIR}/Camera/Camera.h DESTINATION include)
endif()

# ObjLoader Module
option(USE_ObjLoader "ObjLoader Module" ON)
if(USE_ObjLoader)
    message(STATUS "ObjLoader module Found")
    add_definitions(-DUSE_ObjLoader)
    add_library(objloader_module ObjLoader/ObjLoader.h ObjLoader/ObjLoader.cxx)
    target_include_directories(objloader_module PUBLIC ${EXTRA_INCLUDE_DIRS} ${PROJECT_BINARY_DIR})
    target_link_directories(objloader_module PUBLIC ${EXTRA_LIB_DIRS})
    target_link_libraries(objloader_module PUBLIC ${EXTRA_LINKS})
    list(APPEND EXTRA_INCLUDE_DIRS "${MODULES_DIR}/ObjLoader")
    list(APPEND EXTRA_LIB_DIRS "objloader_module")
    list(APPEND EXTRA_LINKS objloader_module)
    set(EXTRA_INCLUDE_DIRS "${EXTRA_INCLUDE_DIRS}" PARENT_SCOPE)
    set(EXTRA_LIB_DIRS "${EXTRA_LIB_DIRS}" PARENT_SCOPE)
    set(EXTRA_LINKS "${EXTRA_LINKS}" PARENT_SCOPE)
    install(TARGETS objloader_module DESTINATION lib)
    install(FILES ${MODULES_DIR}/ObjLoader/ObjLoader.h DESTINATION include)
endif()

# RoomCube Module
option(USE_RoomCube "RoomCube Module" ON)
if(USE_RoomCube)
    message(STATUS "RoomCube module Found")
    add_definitions(-DUSE_RoomCube)
    add_library(roomcube_module RoomCube/RoomCube.h RoomCube/RoomCube.cxx)
    target_include_directories(roomcube_module PUBLIC ${EXTRA_INCLUDE_DIRS} ${PROJECT_BINARY_DIR})
    target_link_directories(roomcube_module PUBLIC ${EXTRA_LIB_DIRS})
    target_link_libraries(roomcube_module PUBLIC ${EXTRA_LINKS})
    list(APPEND EXTRA_INCLUDE_DIRS "${MODULES_DIR}/RoomCube")
    list(APPEND EXTRA_LIB_DIRS "roomcube_module")
    list(APPEND EXTRA_LINKS roomcube_module)
    set(EXTRA_INCLUDE_DIRS "${EXTRA_INCLUDE_DIRS}" PARENT_SCOPE)
    set(EXTRA_LIB_DIRS "${EXTRA_LIB_DIRS}" PARENT_SCOPE)
    set(EXTRA_LINKS "${EXTRA_LINKS}" PARENT_SCOPE)
    install(TARGETS roomcube_module DESTINATION lib)
    install(FILES ${MODULES_DIR}/RoomCube/RoomCube.h DESTINATION include)
endif()

# TesterModule Module
option(USE_TesterModule "TesterModule Module" ON)
if(USE_TesterModule)
    message(STATUS "TesterModule module Found")
    add_definitions(-DUSE_TesterModule)
    add_library(testermodule_module TesterModule/TesterModule.h TesterModule/TesterModule.cxx)
    target_include_directories(testermodule_module PUBLIC ${EXTRA_INCLUDE_DIRS} ${PROJECT_BINARY_DIR})
    target_link_directories(testermodule_module PUBLIC ${EXTRA_LIB_DIRS})
    target_link_libraries(testermodule_module PUBLIC ${EXTRA_LINKS})
    list(APPEND EXTRA_INCLUDE_DIRS "${MODULES_DIR}/TesterModule")
    list(APPEND EXTRA_LIB_DIRS "testermodule_module")
    list(APPEND EXTRA_LINKS testermodule_module)
    set(EXTRA_INCLUDE_DIRS "${EXTRA_INCLUDE_DIRS}" PARENT_SCOPE)
    set(EXTRA_LIB_DIRS "${EXTRA_LIB_DIRS}" PARENT_SCOPE)
    set(EXTRA_LINKS "${EXTRA_LINKS}" PARENT_SCOPE)
    install(TARGETS testermodule_module DESTINATION lib)
    install(FILES ${MODULES_DIR}/TesterModule/TesterModule.h DESTINATION include)
endif()
