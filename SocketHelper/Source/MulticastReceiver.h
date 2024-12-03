#pragma once

#include "MulticastUser.h"

namespace SocketHelper
{
	class SOCKET_HELPER_API MulticastReceiver : public MulticastUser
	{
	public:
		MulticastReceiver();
		virtual ~MulticastReceiver();

		virtual bool Setup() override;
		virtual bool Shutdown() override;

		void SetLocalAddress(const std::string& localIPAddr, uint32_t localPort);

		/**
		 * Note that this is a blocking call, so you may want
		 * to do this on a thread.
		 */
		bool Receive(uint8_t* buffer, uint32_t& bufferSize);

	protected:
		ip_mreq mreq;
		sockaddr_in localAddr;
		std::string localIPAddr;
		uint32_t localPort;
		WSADATA startupData;
		SOCKET socket;
	};
}