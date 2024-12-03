#pragma once

#include "MulticastReceiver.h"
#include <thread>
#include <mutex>
#include <list>

namespace SocketHelper
{
	class SOCKET_HELPER_API ThreadedMulticastReceiver : public MulticastReceiver
	{
	public:
		ThreadedMulticastReceiver();
		virtual ~ThreadedMulticastReceiver();

		virtual bool Setup() override;
		virtual bool Shutdown() override;

		struct Message
		{
			uint8_t* buffer;
			uint32_t bufferSize;
		};

		bool ReceiveMessageFromThread(Message& message);

	protected:
		void ThreadRun();

		std::thread* thread;
		std::mutex messageListMutex;
		std::list<Message> messageList;
	};
}