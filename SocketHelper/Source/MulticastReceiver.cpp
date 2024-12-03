#include "MulticastReceiver.h"

using namespace SocketHelper;

MulticastReceiver::MulticastReceiver()
{
	this->socket = INVALID_SOCKET;
	this->localPort = 0;

	::memset(&this->startupData, 0, sizeof(this->startupData));
	::memset(&this->localAddr, 0, sizeof(this->localAddr));
	::memset(&this->mreq, 0, sizeof(this->mreq));
}

/*virtual*/ MulticastReceiver::~MulticastReceiver()
{
}

void MulticastReceiver::SetLocalAddress(const std::string& localIPAddr, uint32_t localPort)
{
	this->localIPAddr = localIPAddr;
	this->localPort = localPort;
}

/*virtual*/ bool MulticastReceiver::Setup()
{
	if (this->socket != INVALID_SOCKET)
		return false;

	DWORD version = MAKEWORD(2, 2);
	if (WSAStartup(version, &this->startupData) != 0)
		return false;

	this->socket = ::socket(AF_INET, SOCK_DGRAM, 0);
	if (this->socket == INVALID_SOCKET)
		return false;

	::memset(&this->localAddr, 0, sizeof(localAddr));
	this->localAddr.sin_family = AF_INET;
	this->localAddr.sin_addr.S_un.S_addr = inet_addr(this->localIPAddr.c_str());
	this->localAddr.sin_port = htons(this->localPort);

	int error = ::bind(this->socket, (const sockaddr*)&this->localAddr, sizeof(this->localAddr));
	if (error < 0)
		return false;

	this->mreq.imr_multiaddr.S_un.S_addr = inet_addr(this->multicastIPAddr.c_str());
	this->mreq.imr_interface = this->localAddr.sin_addr;
	error = ::setsockopt(this->socket, IPPROTO_IP, IP_ADD_MEMBERSHIP, (const char*)&this->mreq, sizeof(this->mreq));
	if (error == SOCKET_ERROR)
		return false;

	return true;
}

/*virtual*/ bool MulticastReceiver::Shutdown()
{
	if (this->socket != INVALID_SOCKET)
	{
		::setsockopt(this->socket, IPPROTO_IP, IP_DROP_MEMBERSHIP, (const char*)&this->mreq, sizeof(this->mreq));
		::closesocket(this->socket);
		this->socket = INVALID_SOCKET;
	}

	WSACleanup();

	return true;
}

bool MulticastReceiver::Receive(uint8_t* buffer, uint32_t& bufferSize)
{
	int numBytes = ::recvfrom(this->socket, (char*)buffer, (int)bufferSize, 0, nullptr, nullptr);
	if (numBytes == 0)
		return false;

	if (numBytes == SOCKET_ERROR)
		return false;

	bufferSize = (uint32_t)numBytes;
	return true;
}