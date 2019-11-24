/*
*
*    This program is free software; you can redistribute it and/or modify it
*    under the terms of the GNU General Public License as published by the
*    Free Software Foundation; either version 2 of the License, or (at
*    your option) any later version.
*
*    This program is distributed in the hope that it will be useful, but
*    WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*    General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program; if not, write to the Free Software Foundation,
*    Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
*    In addition, as a special exception, the author gives permission to
*    link the code of this program with the Half-Life Game Engine ("HL
*    Engine") and Modified Game Libraries ("MODs") developed by Valve,
*    L.L.C ("Valve").  You must obey the GNU General Public License in all
*    respects for all of the code used other than the HL Engine and MODs
*    from Valve.  If you modify this file, you may extend this exception
*    to your version of the file, but you are not obligated to do so.  If
*    you do not wish to do so, delete this exception statement from your
*    version.
*
*/

#ifndef _OSCONFIG_H
#define _OSCONFIG_H

#ifdef _WIN32 // WINDOWS
	#pragma warning(disable : 4005)
#endif // _WIN32

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <setjmp.h>
#include <assert.h>

#include <algorithm>
#include <deque>
#include <functional>

#ifdef _WIN32 // WINDOWS
	#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
	#include <windows.h>
	#include <winsock.h>
	#include <wsipx.h> // for support IPX
	#define PSAPI_VERSION 1
	#include <psapi.h>
	#include <nmmintrin.h>
	#include <fcntl.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <io.h>
#endif // _WIN32

#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

// SSE
#include <smmintrin.h>
#include <xmmintrin.h>

#ifdef _WIN32 // WINDOWS
	// Define __func__ on VS less than 2015
	#if _MSC_VER < 1900
		#define __func__ __FUNCTION__
	#endif

	// We'll not use __func__ on windows because we want 'A::foo' instead of 'foo'
	#define __FUNC__ __FUNCTION__
	#define _CRT_SECURE_NO_WARNINGS
	#define WIN32_LEAN_AND_MEAN

	#define FASTCALL __fastcall
	#define STDCALL __stdcall
	#define HIDDEN
	#define FORCEINLINE __forceinline
	#define NOINLINE __declspec(noinline)
	#define ALIGN16 __declspec(align(16))
	#define NORETURN __declspec(noreturn)
	#define FORCE_STACK_ALIGN
	#define FUNC_TARGET(x)

	#define __builtin_bswap16 _byteswap_ushort
	#define __builtin_bswap32 _byteswap_ulong
	#define __builtin_bswap64 _byteswap_uint64

	//inline bool SOCKET_FIONBIO(SOCKET s, int m) { return (ioctlsocket(s, FIONBIO, (u_long*)&m) == 0); }
	//inline int SOCKET_MSGLEN(SOCKET s, u_long& r) { return ioctlsocket(s, FIONREAD, (u_long*)&r); }
	typedef int socklen_t;
	#define SOCKET_FIONBIO(s, m) ioctlsocket(s, FIONBIO, (u_long*)&m)
	#define SOCKET_MSGLEN(s, r) ioctlsocket(s, FIONREAD, (u_long*)&r)
	#define SIN_GET_ADDR(saddr, r) r = (saddr)->S_un.S_addr
	#define SIN_SET_ADDR(saddr, r) (saddr)->S_un.S_addr = (r)
	#define SOCKET_CLOSE(s) closesocket(s)
	#define SOCKET_AGAIN() (WSAGetLastError() == WSAEWOULDBLOCK)

	inline void* sys_allocmem(unsigned int size) {
		return VirtualAlloc(NULL, size, MEM_COMMIT, PAGE_READWRITE);
	}

	inline void sys_freemem(void* ptr, unsigned int size) {
		VirtualFree(ptr, 0, MEM_RELEASE);
	}
#endif // _WIN32

#define EXT_FUNC FORCE_STACK_ALIGN

// Used to obtain the string name of a variable.
#define nameof_variable(name) template_nameof_variable(name, #name)
template <typename T> const char* template_nameof_variable(const T& /*validate_type*/, const char* name) { return name; }

#endif // _OSCONFIG_H
