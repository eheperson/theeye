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


