cmake_minimum_required(VERSION 3.4)

project(Program)

#specify set of project's source files
set(SOURCE_FILES
        src/main.cpp
        ../library/src/Teacher.cpp ../library/include/Teacher.h ../library/src/Guest.cpp ../library/include/Guest.h ../library/src/Library.cpp ../library/include/Library.h ../library/src/Request.cpp ../library/include/Request.h ../library/src/LibraryUI.cpp ../library/include/LibraryUI.h ../library/src/CLI.cpp ../library/include/CLI.h ../library/src/UnitTestUi.cpp ../library/include/UnitTestUi.h ../library/src/Encyclopedia.cpp ../library/include/Encyclopedia.h ../library/src/StudentBook.cpp ../library/include/StudentBook.h ../library/src/TeacherBook.cpp ../library/include/TeacherBook.h ../library/include/Genders.h ../library/include/Status.h)
#add following files to executable file 'Program'
add_executable(Program ${SOURCE_FILES})

#add libraries from 'Library' project
target_link_libraries(Program Library)

#add header files from 'include' directory of main project
target_include_directories(Program PUBLIC include)

enable_testing()