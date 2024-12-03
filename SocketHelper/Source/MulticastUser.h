#pragma once

#include "SocketHelper.h"

namespace SocketHelper
{
	/**
	 * Note that to be involved in multicast, you do not necessarily need
	 * to join the multicast group.  Membership in the group is required
	 * for receiving messages, but not sending them.
	 */
	class SOCKET_HELPER_API MulticastUser
	{
	public:
		MulticastUser();
		virtual ~MulticastUser();

		void SetMulticastAddress(const std::string& multicastIPAddr, uint32_t multicastPort);

		virtual bool Setup() = 0;
		virtual bool Shutdown() = 0;

	protected:
		
		std::string multicastIPAddr;
		uint32_t multicastPort;
	};
}