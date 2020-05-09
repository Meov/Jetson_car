cmake_minimum_required (VERSION 2.6)
project(serialLIB)
aux_source_directory(. DIR_LIB_SRCS)#查找当前目录下所有源文件并保存到变量 DIR_LIB_SRCS 
add_library(serial_port SHARED ${DIR_LIB_SRCS}) #生成seriallib的动态库
install(TARGETS serial_port LIBRARY DESTINATION lib)#/usr/local/lib/libserial_port.so
install(FILES serial_port.h DESTINATION include/serialLIB)#头文件保存到/usr/local/include/serialLIB/serial.h

