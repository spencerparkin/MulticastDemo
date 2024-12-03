#include "MulticastUser.h"

using namespace SocketHelper;

MulticastUser::MulticastUser()
{
	this->multicastPort = 0;
}

/*virtual*/ MulticastUser::~MulticastUser()
{
}

void MulticastUser::SetMulticastAddress(const std::string& multicastIPAddr, uint32_t multicastPort)
{
	this->multicastIPAddr = multicastIPAddr;
	this->multicastPort = multicastPort;
}