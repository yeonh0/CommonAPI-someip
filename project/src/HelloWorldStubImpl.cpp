// HelloWorldStubImpl.cpp
#include "HelloWorldStubImpl.hpp"

HelloWorldStubImpl::HelloWorldStubImpl() { }
HelloWorldStubImpl::~HelloWorldStubImpl() { }

void HelloWorldStubImpl::sayHello(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name, sayHelloReply_t _reply) {
  // stringstream 인스턴스에 문자열 추가
  std::stringstream messageStream;
  messageStream << "Hello" << _name << "!";
  std::cout << "sayHello('" << _name << "'): " << messageStream.str() << "'\n";

  _reply(messageStream.str());
};