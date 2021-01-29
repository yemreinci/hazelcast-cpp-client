cmake_minimum_required (VERSION 3.10)

FILE(GLOB_RECURSE HZ_TEST_SOURCES "./*cpp")
FILE(GLOB_RECURSE HZ_TEST_HEADERS "./*h")

set(GOOGLETEST_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/hazelcast/test/googletest/googletest/include)

add_executable(client_test ${HZ_TEST_SOURCES} ${HZ_TEST_HEADERS})

message(STATUS "${LIBRARY_FOR_TESTS} will be tested.")
target_link_libraries(client_test PRIVATE ${LIBRARY_FOR_TESTS} gtest)

find_package(Thrift)
if (Thrift_FOUND)
    target_link_libraries(client_test PRIVATE thrift::thrift)
else()
    IF (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
        set(THRIFT_INCLUDE_DIR /usr/include)
        set(THRIFT_LIB_DIR /usr/lib64)
        message(STATUS "Using THRIFT_INCLUDE_DIR: ${THRIFT_INCLUDE_DIR}")
        message(STATUS "Using THRIFT_LIB_DIR: ${THRIFT_LIB_DIR}")
        include_directories(${THRIFT_INCLUDE_DIR})
        target_link_directories(client_test PRIVATE ${THRIFT_LIB_DIR})
        target_link_libraries(client_test PRIVATE thrift)
    ENDIF (${CMAKE_SYSTEM_NAME} MATCHES "Linux")

    IF (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
        set(THRIFT_INCLUDE_DIR /usr/local/opt/thrift/include)
        set(THRIFT_LIB_DIR /usr/local/opt/thrift/lib)
        include_directories(${THRIFT_INCLUDE_DIR})
        target_link_directories(client_test PRIVATE ${THRIFT_LIB_DIR})
        target_link_libraries(client_test PRIVATE thrift)
        message(STATUS "Using THRIFT_INCLUDE_DIR: ${THRIFT_INCLUDE_DIR}")
        message(STATUS "Using THRIFT_LIB_DIR: ${THRIFT_LIB_DIR}")
    ENDIF (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

    IF (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
        message(FATAL_ERROR "This shouldn't happen!")
    ENDIF (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
endif()

target_include_directories(
    client_test
    PRIVATE ${CMAKE_SOURCE_DIR}/hazelcast/test/src
)

if (MSVC)
    target_compile_options(client_test PRIVATE /bigobj)
endif()

target_compile_definitions(client_test PRIVATE HAZELCAST_VERSION="${PROJECT_VERSION}")
