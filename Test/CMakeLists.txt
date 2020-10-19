FILE(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/ ${CMAKE_CURRENT_SOURCE_DIR}/*)

FOREACH(child ${children})

IF(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${child})
    message(STATUS "TestCase: ${child}")
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${child}
    )
ENDIF()

ENDFOREACH()