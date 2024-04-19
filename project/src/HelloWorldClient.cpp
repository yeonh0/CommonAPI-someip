//HelloWorldClient.cpp
#include <iostream>
#include <string>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/HelloWorldProxy.hpp>

using namespace v1_0::commonapi;

int main() {
  // Runtime Instance 가져오기
  std::shared_ptr <CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
  // Proxy 생성 - 위치: "local", 이름: "test"
  std::shared_ptr <HelloWorldProxy<>> myProxy = runtime->buildProxy<HelloWorldProxy>("local", "test");
  // Checking availability (Proxy) : 생성을 기다림 
  std::cout << "Checking availability!" << std::endl;
  while (!myProxy->isAvailable()) {
    usleep(10);
  }
  std::cout << "Available ..." << std::endl;

  // 메서드 호출 상태 나타내는 Enum type 변수 선언
  CommonAPI::CallStatus callStatus;
  std::string returnMessage;
  // CommonAPI의 Proxy 인스턴스인 myProxy로 sayHello 메서드 호출
  myProxy->sayHello("Cho", callStatus, returnMessage);
  // 반환 메시지 출력
  std::cout << "Got message: '" << returnMessage << "'\n";

  return 0;
}