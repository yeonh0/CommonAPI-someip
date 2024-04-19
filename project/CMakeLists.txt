cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++11")

include_directories(
    src-gen
    ~/COVESA/capicxx-core-runtime/include
    ~/COVESA/capicxx-someip-runtime/include
    ~/COVESA/vsomeip/interface
)
link_directories(
    ~/COVESA/lib
)

add_executable(HelloWorldClient
    src/HelloWorldClient.cpp
    src-gen/v1/commonapi/HelloWorldSomeIPProxy.cpp
    src-gen/v1/commonapi/HelloWorldSomeIPDeployment.cpp
)
target_link_libraries(HelloWorldClient CommonAPI CommonAPI-SomeIP vsomeip3)

add_executable(HelloWorldService
    src/HelloWorldService.cpp
    src/HelloWorldStubImpl.cpp
    src-gen/v1/commonapi/HelloWorldSomeIPStubAdapter.cpp
    #src-gen/v1/commonapi/HelloWorldStubDefault.cpp
    src-gen/v1/commonapi/HelloWorldSomeIPDeployment.cpp
)
target_link_libraries(HelloWorldService CommonAPI CommonAPI-SomeIP vsomeip3)

