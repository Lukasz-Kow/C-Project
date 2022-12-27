cmake_minimum_required(VERSION 3.4)

project(Program)

#specify set of project's source files
set(SOURCE_FILES
        src/main.cpp
        ../library/include/LoadStrategy.h ../library/src/LoadStrategy.cpp ../library/include/CheckFreePlaceStrategy.h ../library/src/CheckFreePlaceStrategy.cpp ../library/include/CheckPlaceAndWeightStrategy.h ../library/src/CheckPlaceAndWeightStrategy.cpp)
#add following files to executable file 'Program'
add_executable(Program ${SOURCE_FILES} ../library/include/CheckFreePlaceStrategy.h)

#add libraries from 'Library' project
target_link_libraries(Program Library)

#add header files from 'include' directory of main project
target_include_directories(Program PUBLIC include)

enable_testing()