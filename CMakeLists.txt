cmake_minimum_required(VERSION 3.8)
project(CppTest)

set(CMAKE_CXX_STANDARD 11)


################## Custom Env Setting value ##################
### 작업 환경마다 환경변수를 잘 못불러오는 경우가 있어서 여기서 각 작업환경에 맞게 세팅한다.
set(CATCH_HOME "/home/yoonsung/OpenSources/Catch")
set(BOOST_ROOT "/home/yoonsung/PO7Development/libraries/boost_1_58_0")
set(BOOST_LIBRARY_DIR "/usr/lib/x86_64-linux-gnu") #Boost library는  apt-get을 통해서 설치해야함
#------------------------------------------------------------#


################## CATCH Testing Framwork Settings ##################
set(CATCH "${CATCH_HOME}/include")
include_directories(${CATCH})
#-------------------------------------------------------------------#


################## Sub Directories ##################
add_subdirectory(src)
add_subdirectory(test)
#---------------------------------------------------#


################## Testing Settings ##################
option(BUILD_TEST "Build the unit tests" ON)
enable_testing()