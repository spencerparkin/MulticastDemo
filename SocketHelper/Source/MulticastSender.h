#pragma once

#include "MulticastUser.h"

namespace SocketHelper
{
	class SOCKET_HELPER_API MulticastSender : public MulticastUser
	{
	public:
		MulticastSender();
		virtual ~MulticastSender();

		virtual bool Setup() override;
		virtual bool Shutdown() override;

		bool Send(const uint8_t* buffer, uint32_t bufferSize);

	protected:
		sockaddr_in multicastAddr;
		WSADATA startupData;
		SOCKET socket;
	};
}