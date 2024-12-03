#include "ThreadedMulticastReceiver.h"

using namespace SocketHelper;

ThreadedMulticastReceiver::ThreadedMulticastReceiver()
{
	this->thread = nullptr;
}

/*virtual*/ ThreadedMulticastReceiver::~ThreadedMulticastReceiver()
{
}

/*virtual*/ bool ThreadedMulticastReceiver::Setup()
{
	if (!MulticastReceiver::Setup())
		return false;

	this->thread = new std::thread([=]() { this->ThreadRun(); });
	return true;
}

/*virtual*/ bool ThreadedMulticastReceiver::Shutdown()
{
	// Shutting down the socket will signal our thread to exit.
	MulticastReceiver::Shutdown();

	if (this->thread)
	{
		this->thread->join();
		delete this->thread;
		this->thread = nullptr;
	}

	return true;
}

void ThreadedMulticastReceiver::ThreadRun()
{
	while (true)
	{
		uint32_t bufferSize = 1024;		// TODO: Need a better way for this.
		std::unique_ptr<uint8_t> messageBuffer(new uint8_t[bufferSize]);
		if (!this->Receive(messageBuffer.get(), bufferSize))
			break;

		Message message;
		message.bufferSize = bufferSize;
		message.buffer = messageBuffer.release();
		{
			std::scoped_lock lock(this->messageListMutex);
			this->messageList.push_back(message);
		}
	}
}

bool ThreadedMulticastReceiver::ReceiveMessageFromThread(Message& message)
{
	if (this->messageList.size() > 0)
	{
		std::scoped_lock<std::mutex> lock(this->messageListMutex);
		message = *this->messageList.begin();
		this->messageList.pop_front();
		return true;
	}

	return false;
}