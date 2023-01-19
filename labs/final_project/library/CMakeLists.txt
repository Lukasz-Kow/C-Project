cmake_minimum_required(VERSION 3.4)
project(Library)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        include/Book.h src/Book.cpp src/Client.cpp include/Client.h
        src/Student.cpp include/Student.h src/Teacher.cpp
        include/Teacher.h src/Guest.cpp include/Guest.h src/Library.cpp
        include/Library.h src/Request.cpp include/Request.h src/LibraryUI.cpp
        include/LibraryUI.h src/CLI.cpp include/CLI.h src/UnitTestUi.cpp include/UnitTestUi.h
        src/Encyclopedia.cpp include/Encyclopedia.h src/StudentBook.cpp include/StudentBook.h src/TeacherBook.cpp
        include/TeacherBook.h include/Genders.h include/Status.h src/Date.cpp include/Date.h src/BookFactory.cpp include/BookFactory.h include/ClientTypes.h)

add_library(Library ${SOURCE_FILES})

#add 'include' directory with header files from 'Library' project to paths
target_include_directories(Library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#Unit Tests section

# Check if generating Visual Studio 14 2015 project
if(MSVC)
    if(NOT BOOST_ROOT)
        set(BOOST_ROOT "C:/local/boost_1_60_0")
    endif()
    set(Boost_INCLUDE_DIR "${BOOST_ROOT}")
    set(Boost_LIBRARY_DIR "${BOOST_ROOT}/lib32-msvc-14.0")
    set(Boost_USE_STATIC_LIBS ON)
    set(Boost_USE_MULTITHREADED ON)

    if(NOT EXISTS ${Boost_LIBRARY_DIR})
        message(WARNING "Boost library requires manual installation in Windows")
        message("1) Browse: https://sourceforge.net/projects/boost/files/boost-binaries/1.60.0/")
        message("2) Download: boost_1_60_0-msvc-14.0-32.exe")
        message("3) Install into default directory: C:\\local")
        message("")
        message(FATAL_ERROR "Boost libraries not found at ${Boost_LIBRARY_DIR}")
    endif()

    find_package(Boost COMPONENTS unit_test_framework REQUIRED)


    include_directories(${Boost_INCLUDE_DIR})
    link_directories(${Boost_LIBRARY_DIR})

else()
    find_package(Boost COMPONENTS unit_test_framework REQUIRED)

endif()
#find_package(Boost COMPONENTS uuid REQUIRED)
#target_link_libraries(Library uuid)

set(SOURCE_TEST_FILES
        test/master.cpp
        test/BookTest.cpp
        src/Teacher.cpp
        include/Teacher.h
        src/Guest.cpp include/Guest.h src/Library.cpp include/Library.h src/Request.cpp include/Request.h
        src/LibraryUI.cpp include/LibraryUI.h src/CLI.cpp include/CLI.h src/UnitTestUi.cpp include/UnitTestUi.h
        src/Encyclopedia.cpp include/Encyclopedia.h src/StudentBook.cpp include/StudentBook.h src/TeacherBook.cpp
        include/TeacherBook.h include/Genders.h include/Student.h src/Student.cpp src/Client.cpp include/Client.h include/Status.h
        include/BookFactory.h src/BookFactory.cpp include/ClientTypes.h include/Book.h src/Book.cpp)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

add_executable (Test ${SOURCE_TEST_FILES} test/BookTest.cpp)

target_link_libraries (Test
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

target_link_libraries (Test
        Library
        ${Boost_DATE_TIME_LIBRARY}
        )
add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

enable_testing()
add_test(LibraryTest Test)