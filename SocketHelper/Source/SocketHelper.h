#pragma once

#if defined SOCKET_HELPER_EXPORT
#	define SOCKET_HELPER_API		__declspec(dllexport)
#elif defined SOCKET_HELPER_IMPORT
#	define SOCKET_HELPER_API		__declspec(dllimport)
#else
#	define SOCKET_HELPER_API
#endif

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdint.h>
#include <string>

namespace SocketHelper
{
}