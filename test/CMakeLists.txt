cmake_minimum_required(VERSION 3.0)

add_executable(Hierarchy "oop/hierarchy/VirtualTest.cpp")

enable_testing()
string(TIMESTAMP CURRENTTIME "%y%m%d_%H-%M-%S")

add_test(Hierarchy Hierarchy -o "Hierarchy_{CURRENTTIME}.xml" -r "xml")