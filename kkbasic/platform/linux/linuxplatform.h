
#ifndef KKBASIC_LINUX_PLATFORM_H
#define KKBASIC_LINUX_PLATFORM_H

extern "C" {
#include <inttypes.h>
#include <arpa/inet.h>
#include <assert.h>
#include <cctype>
#include <dirent.h>
#include <dlfcn.h>
#include <errno.h>
#include <fcntl.h>
#include <glob.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <spawn.h>
#include <time.h>

//#include <sys/epoll.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/resource.h>
}


namespace kkbasic {
namespace platform {

#define WRITE_FD write 
#define READ_FD  read 

#define SOCKET int32_t
#define GET_LAST_SOCK_ERROR errno
#define SOCK_ERROR_EINPROGRESS  EINPROGRESS
#define SOCK_ERROR_EAGAIN       EAGAIN 
#define SOCK_ERROR_ECONNRESET   ECONNRESET 
#define SOCK_ERROR_ENOBUFS      ENOBUFS 
#define CLOSE_SOCKET(fd) if((fd)>=0) close((fd))

#define LIB_HANDLER void *
#define FREE_LIBRARY(libHandler) dlclose((libHandler))
#define LOAD_LIBRARY(file,flags) dlopen((file), (flags))
#define LOAD_LIBRARY_FLAGS RTLD_NOW | RTLD_LOCAL
#define OPEN_LIBRARY_ERROR ((string(dlerror())).c_str())
#define GET_PROC_ADDRESS(libHandler, procName) dlsym((libHandler), (procName))
#define LIBRARY_NAME_PATTERN "lib%s.so"
#define PATH_SEPARATOR '/'

#define GetPid getpid 
#define PutEnv putenv 
#define TzSet  tzset 
#define Chmod  chmod 
#define ftell64 ftello64
#define fseek64 fseeko64


} // namespace platform
} // namespace kkbasic


#endif // KKBASIC_LINUX_PLATFORM_H
