
#ifndef KKBASIC_PLATFORM_H 
#define KKBASIC_PLATFORM_H 

/*
 *  support cross-platform
 *  SOCKET : socket fd 
 *     linux   int32_t 
 *     windows SOCKET 
 *     
 *  read   : api
 *     linux   read
 *     windows _read 
 *
 *  write  : api 
 *     linux   write
 *     windows _write
 *
 *
 *  errno  : sys constant
 *     linux   : use errno directly
 *     windows : http://msdn.microsoft.com/en-us/library/windows/desktop/ms737828(v=vs.85).aspx
 *               use WSAGetLastError()
 *
 *
 *  EINPROGRESS : 
 *     linux   : EINPROGRESS
 *     windows : WSAEINPROGRESS  
 *
 *
 *  EAGAIN :
 *     linux   : EAGAIN
 *     windows : WSAEWOULDBLOCK
 *
 *
 *  ECONNRESET :
 *     linux   : ECONNRESET
 *     windows : WSAECONNRESET  
 *
 *  ENOBUFS : using in udp 
 *     linux   ENOBUFS 
 *     windows WSAENOBUFS  
 *
 *  dynamic load lib: LIB_HANDLER 
 *     linux   : void *
 *     windows : HMODULE   
 *
 *     #define LOAD_LIBRARY dlopen(file), (flags);
 *     #define LOAD_LIBRARY_FLAGS RTLD_NOW | RTLD_LOCAL // windows does not use it 
 *
 *  MSG_NOSIGNAL and SO_NOSIGPIPE 
 *     linux  : MSG_NOSIGNAL 
 *     apple  : SO_NOSIGPIPE 
 *
 *  getpid :
 *     linux   : getpid 
 *     windows : _getpid 
 *
 *  putenv :
 *     linux   : putenv 
 *     windows : _putenv 
 *
 *  tzset  :
 *     linux   : tzset 
 *     windows : _tzset 
 *
 *  Chmod  :
 *     linux   : chmod 
 *     windows : _chmod 
 *  
 *  fseek64 :
 *     linux   : fseek64 
 *     windows : _fseeki64
 *     freebsd : fseeko
 *  ftell64 :
 *     linux   : ftello64
 *     windows : _ftelli64
 *     freebsd : ftello 
 *
 */


#ifdef LINUX
#include <kkbasic/platform/linux/linuxplatform.h>
#endif /* LINUX */

#ifdef WIN32
// not support now
#endif /* WIN32 */

#endif // KKBASIC_PLATFORM_H
