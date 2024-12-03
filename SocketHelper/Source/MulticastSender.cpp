#include "MulticastSender.h"

using namespace SocketHelper;

MulticastSender::MulticastSender()
{
	this->socket = INVALID_SOCKET;

	::memset(&this->startupData, 0, sizeof(this->startupData));
	::memset(&this->multicastAddr, 0, sizeof(this->multicastAddr));
}

/*virtual*/ MulticastSender::~MulticastSender()
{
}

/*virtual*/ bool MulticastSender::Setup()
{
	if (this->socket != INVALID_SOCKET)
		return false;

	DWORD version = MAKEWORD(2, 2);
	if (WSAStartup(version, &this->startupData) != 0)
		return false;

	this->socket = ::socket(AF_INET, SOCK_DGRAM, 0);
	if (this->socket == INVALID_SOCKET)
		return false;

	::memset(&this->multicastAddr, 0, sizeof(this->multicastAddr));
	this->multicastAddr.sin_family = AF_INET;
	this->multicastAddr.sin_addr.S_un.S_addr = inet_addr(this->multicastIPAddr.c_str());
	this->multicastAddr.sin_port = this->multicastPort;

	return true;
}

/*virtual*/ bool MulticastSender::Shutdown()
{
	if (this->socket != INVALID_SOCKET)
	{
		::closesocket(this->socket);
		this->socket = INVALID_SOCKET;
	}

	WSACleanup();

	return true;
}

bool MulticastSender::Send(const uint8_t* buffer, uint32_t bufferSize)
{
	int error = sendto(this->socket, (const char*)buffer, (int)bufferSize, 0, (const sockaddr*)&this->multicastAddr, sizeof(this->multicastAddr));
	if (error < 0)
		return false;

	return true;
}