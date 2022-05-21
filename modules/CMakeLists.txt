option(USE_Window "Window Module" ON)
if(USE_Window)
    # To make use  of the new library we will add an add_subdirectory() call
    # add_subdirectory(${Window})
    message(STATUS "Window module Found")
    add_definitions(-DUSE_Window)
    #
    # set(Window TestLib)
    # set(Window Window/Window.cxx)
    #
    add_library(Window Window/Window.h Window/Window.cxx)
    # link test module to find 3Rd dependencies
    target_include_directories(Window PUBLIC ${EXTRA_INCLUDE_DIRS}) 
    target_link_directories(Window PUBLIC ${EXTRA_LIB_DIRS})
    target_link_libraries(Window PUBLIC ${EXTRA_LINKS})
    #
    # to find theeye.h
    target_include_directories(Window PUBLIC ${PROJECT_BINARY_DIR})
    #
    # append in local scope
    list(APPEND EXTRA_INCLUDE_DIRS "${MODULES_DIR}/Window")
    list(APPEND EXTRA_LIB_DIRS "Window")
    list(APPEND EXTRA_LINKS Window)
    # set in parent scope
    set(EXTRA_INCLUDE_DIRS "${EXTRA_INCLUDE_DIRS}" PARENT_SCOPE)
    set(EXTRA_LIB_DIRS "${EXTRA_LIB_DIRS}" PARENT_SCOPE)
    set(EXTRA_LINKS "${EXTRA_LINKS}" PARENT_SCOPE)
    #
    install(TARGETS ${Window} DESTINATION lib)
    install(FILES ${MODULES_DIR}/Window/Window.h DESTINATION include)
endif()

# ------------------------------------------------------------------------------------------

option(USE_Application "Application Module" ON)
if(USE_Application)
    # To make use  of the new library we will add an add_subdirectory() call
    # add_subdirectory(${Application})
    message(STATUS "Application module Found")
    add_definitions(-DUSE_Application)
    #
    # set(Application TestLib)
    # set(Application Application/Application.cxx)
    #
    add_library(Application Application/Application.h Application/Application.cxx)
    # link test module to find 3Rd dependencies
    target_include_directories(Application PUBLIC ${EXTRA_INCLUDE_DIRS}) 
    target_link_directories(Application PUBLIC ${EXTRA_LIB_DIRS})
    target_link_libraries(Application PUBLIC ${EXTRA_LINKS})
    #
    # to find theeye.h
    target_include_directories(Application PUBLIC ${PROJECT_BINARY_DIR})
    #
    # append in local scope
    list(APPEND EXTRA_INCLUDE_DIRS "${MODULES_DIR}/Application")
    list(APPEND EXTRA_LIB_DIRS "Application")
    list(APPEND EXTRA_LINKS Application)
    # set in parent scope
    set(EXTRA_INCLUDE_DIRS "${EXTRA_INCLUDE_DIRS}" PARENT_SCOPE)
    set(EXTRA_LIB_DIRS "${EXTRA_LIB_DIRS}" PARENT_SCOPE)
    set(EXTRA_LINKS "${EXTRA_LINKS}" PARENT_SCOPE)
    #
    install(TARGETS ${Application} DESTINATION lib)
    install(FILES ${MODULES_DIR}/Application/Application.h DESTINATION include)
endif()

# ------------------------------------------------------------------------------------------

option(USE_Shader "Shader Module" ON)
if(USE_Shader)
    # To make use  of the new library we will add an add_subdirectory() call
    # add_subdirectory(${Shader})
    message(STATUS "Shader module Found")
    add_definitions(-DUSE_Shader)
    #
    # set(Shader TestLib)
    # set(Shader Shader/Shader.cxx)
    #
    add_library(Shader Shader/Shader.h Shader/Shader.cxx)
    # link test module to find 3Rd dependencies
    target_include_directories(Shader PUBLIC ${EXTRA_INCLUDE_DIRS}) 
    target_link_directories(Shader PUBLIC ${EXTRA_LIB_DIRS})
    target_link_libraries(Shader PUBLIC ${EXTRA_LINKS})
    #
    # to find theeye.h
    target_include_directories(Shader PUBLIC ${PROJECT_BINARY_DIR})
    #
    # append in local scope
    list(APPEND EXTRA_INCLUDE_DIRS "${MODULES_DIR}/Shader")
    list(APPEND EXTRA_LIB_DIRS "Shader")
    list(APPEND EXTRA_LINKS Shader)
    # set in parent scope
    set(EXTRA_INCLUDE_DIRS "${EXTRA_INCLUDE_DIRS}" PARENT_SCOPE)
    set(EXTRA_LIB_DIRS "${EXTRA_LIB_DIRS}" PARENT_SCOPE)
    set(EXTRA_LINKS "${EXTRA_LINKS}" PARENT_SCOPE)
    #
    install(TARGETS ${Shader} DESTINATION lib)
    install(FILES ${MODULES_DIR}/Shader/Shader.h DESTINATION include)
endif()

# ------------------------------------------------------------------------------------------

option(USE_Drawable "Drawable Module" ON)
if(USE_Drawable)
    # To make use  of the new library we will add an add_subdirectory() call
    # add_subdirectory(${Drawable})
    message(STATUS "Drawable module Found")
    add_definitions(-DUSE_Drawable)
    #
    # set(Drawable TestLib)
    # set(Drawable Drawable/Drawable.cxx)
    #
    add_library(Drawable Drawable/Drawable.h Drawable/Drawable.cxx)
    # link test module to find 3Rd dependencies
    target_include_directories(Drawable PUBLIC ${EXTRA_INCLUDE_DIRS}) 
    target_link_directories(Drawable PUBLIC ${EXTRA_LIB_DIRS})
    target_link_libraries(Drawable PUBLIC ${EXTRA_LINKS})
    #
    # to find theeye.h
    target_include_directories(Drawable PUBLIC ${PROJECT_BINARY_DIR})
    #
    # append in local scope
    list(APPEND EXTRA_INCLUDE_DIRS "${MODULES_DIR}/Drawable")
    list(APPEND EXTRA_LIB_DIRS "Drawable")
    list(APPEND EXTRA_LINKS Drawable)
    # set in parent scope
    set(EXTRA_INCLUDE_DIRS "${EXTRA_INCLUDE_DIRS}" PARENT_SCOPE)
    set(EXTRA_LIB_DIRS "${EXTRA_LIB_DIRS}" PARENT_SCOPE)
    set(EXTRA_LINKS "${EXTRA_LINKS}" PARENT_SCOPE)
    #
    install(TARGETS ${Drawable} DESTINATION lib)
    install(FILES ${MODULES_DIR}/Drawable/Drawable.h DESTINATION include)
endif()

# ------------------------------------------------------------------------------------------

option(USE_Camera "Camera Module" ON)
if(USE_Camera)
    # To make use  of the new library we will add an add_subdirectory() call
    # add_subdirectory(${Camera})
    message(STATUS "Camera module Found")
    add_definitions(-DUSE_Camera)
    #
    # set(Camera TestLib)
    # set(Camera Camera/Camera.cxx)
    #
    add_library(Camera Camera/Camera.h Camera/Camera.cxx)
    # link test module to find 3Rd dependencies
    target_include_directories(Camera PUBLIC ${EXTRA_INCLUDE_DIRS}) 
    target_link_directories(Camera PUBLIC ${EXTRA_LIB_DIRS})
    target_link_libraries(Camera PUBLIC ${EXTRA_LINKS})
    #
    # to find theeye.h
    target_include_directories(Camera PUBLIC ${PROJECT_BINARY_DIR})
    #
    # append in local scope
    list(APPEND EXTRA_INCLUDE_DIRS "${MODULES_DIR}/Camera")
    list(APPEND EXTRA_LIB_DIRS "Camera")
    list(APPEND EXTRA_LINKS Camera)
    # set in parent scope
    set(EXTRA_INCLUDE_DIRS "${EXTRA_INCLUDE_DIRS}" PARENT_SCOPE)
    set(EXTRA_LIB_DIRS "${EXTRA_LIB_DIRS}" PARENT_SCOPE)
    set(EXTRA_LINKS "${EXTRA_LINKS}" PARENT_SCOPE)
    #
    install(TARGETS ${Camera} DESTINATION lib)
    install(FILES ${MODULES_DIR}/Camera/Camera.h DESTINATION include)
endif()

# ------------------------------------------------------------------------------------------

option(USE_RoomCube "RoomCube Module" ON)
if(USE_RoomCube)
    # To make use  of the new library we will add an add_subdirectory() call
    # add_subdirectory(${RoomCube})
    message(STATUS "RoomCube module Found")
    add_definitions(-DUSE_RoomCube)
    #
    # set(RoomCube TestLib)
    # set(RoomCube RoomCube/RoomCube.cxx)
    #
    add_library(RoomCube RoomCube/RoomCube.h RoomCube/RoomCube.cxx)
    # link test module to find 3Rd dependencies
    target_include_directories(RoomCube PUBLIC ${EXTRA_INCLUDE_DIRS}) 
    target_link_directories(RoomCube PUBLIC ${EXTRA_LIB_DIRS})
    target_link_libraries(RoomCube PUBLIC ${EXTRA_LINKS})
    #
    # to find theeye.h
    target_include_directories(RoomCube PUBLIC ${PROJECT_BINARY_DIR})
    #
    # append in local scope
    list(APPEND EXTRA_INCLUDE_DIRS "${MODULES_DIR}/RoomCube")
    list(APPEND EXTRA_LIB_DIRS "RoomCube")
    list(APPEND EXTRA_LINKS RoomCube)
    # set in parent scope
    set(EXTRA_INCLUDE_DIRS "${EXTRA_INCLUDE_DIRS}" PARENT_SCOPE)
    set(EXTRA_LIB_DIRS "${EXTRA_LIB_DIRS}" PARENT_SCOPE)
    set(EXTRA_LINKS "${EXTRA_LINKS}" PARENT_SCOPE)
    #
    install(TARGETS ${RoomCube} DESTINATION lib)
    install(FILES ${MODULES_DIR}/RoomCube/RoomCube.h DESTINATION include)
endif()

# ------------------------------------------------------------------------------------------

option(USE_TesterModule "TesterModule Module" ON)
if(USE_TesterModule)
    # To make use  of the new library we will add an add_subdirectory() call
    # add_subdirectory(${TesterModule})
    message(STATUS "TesterModule module Found")
    add_definitions(-DUSE_TesterModule)
    #
    # set(TesterModule TestLib)
    # set(TesterModule TesterModule/TesterModule.cxx)
    #
    add_library(TesterModule TesterModule/TesterModule.h TesterModule/TesterModule.cxx)
    # link test module to find 3Rd dependencies
    target_include_directories(TesterModule PUBLIC ${EXTRA_INCLUDE_DIRS}) 
    target_link_directories(TesterModule PUBLIC ${EXTRA_LIB_DIRS})
    target_link_libraries(TesterModule PUBLIC ${EXTRA_LINKS})
    #
    # to find theeye.h
    target_include_directories(TesterModule PUBLIC ${PROJECT_BINARY_DIR})
    #
    # append in local scope
    list(APPEND EXTRA_INCLUDE_DIRS "${MODULES_DIR}/TesterModule")
    list(APPEND EXTRA_LIB_DIRS "TesterModule")
    list(APPEND EXTRA_LINKS TesterModule)
    # set in parent scope
    set(EXTRA_INCLUDE_DIRS "${EXTRA_INCLUDE_DIRS}" PARENT_SCOPE)
    set(EXTRA_LIB_DIRS "${EXTRA_LIB_DIRS}" PARENT_SCOPE)
    set(EXTRA_LINKS "${EXTRA_LINKS}" PARENT_SCOPE)
    #
    install(TARGETS ${TesterModule} DESTINATION lib)
    install(FILES ${MODULES_DIR}/TesterModule/TesterModule.h DESTINATION include)
endif()

# ------------------------------------------------------------------------------------------
