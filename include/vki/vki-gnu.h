/*--------------------------------------------------------------------*/
/*--- GNU-specific kernel interface.                     vki-gnu.h ---*/
/*--------------------------------------------------------------------*/

/*
   This file is part of Valgrind, a dynamic binary instrumentation
   framework.

   Copyright (C) 2000-2013 Julian Seward
      jseward@acm.org

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307, USA.

   The GNU General Public License is contained in the file COPYING.
*/


#ifndef __VKI_GNU_H
#define __VKI_GNU_H


#include <stdint.h>

#define vki_int8_t int8_t
#define vki_uint8_t uint8_t
#define vki_int16_t int16_t
#define vki_uint16_t uint16_t
#define vki_int32_t int32_t
#define vki_uint32_t uint32_t
#define vki_int64_t int64_t
#define vki_uint64_t uint64_t
#define vki_intptr_t intptr_t
#define vki_uintptr_t uintptr_t


#include <i386-gnu/sys/types.h> //inc

#define vki_dev_t dev_t
#define vki_mode_t mode_t
#define vki_ino_t ino_t
#define vki_ino64_t ino64_t
#define vki_nlink_t nlink_t
#define vki_uid_t uid_t
#define vki_gid_t gid_t
#define vki_time_t time_t
#define vki_off_t off_t
#define vki_blkcnt_t blkcnt_t
#define vki_blksize_t blksize_t
//#define vki_size_t size_t
#define vki_ssize_t ssize_t
#define vki_pid_t pid_t
//#define vki_socklen_t socklen_t
#define vki_suseconds_t suseconds_t
#define vki_caddr_t caddr_t
#define vki_u_long u_long
#define vki_u_short u_short
#define vki_clock_t clock_t
#define vki_u_int32_t u_int32_t
#define vki_u_int16_t u_int16_t
//#define vki_pthread_t pthread_t


#include <malloc.h> //inc


#include <time.h>

#define vki_timeval timeval
#define vki_timespec timespec
#define vki_tm tm
#define vki_itimerspec itimerspec
#define vki_sigevent sigevent


#include <i386-gnu/sys/stat.h>

#define VKI_S_IFMT S_IFMT
#define VKI_S_IFDIR S_IFDIR
#define VKI_S_IFCHR S_IFCHR
#define VKI_S_IFBLK S_IFBLK
#define VKI_S_IFREG S_IFREG
#define VKI_S_IFIFO S_IFIFO
#define VKI_S_IFLNK S_IFLNK
#define VKI_S_IFSOCK S_IFSOCK

#define VKI_S_ISTYPE(md, ms)  __S_ISTYPE(md, ms)

#define VKI_S_ISDIR(m) S_ISDIR(m)
#define VKI_S_ISCHR(m) S_ISCHR(m)
#define VKI_S_ISBLK(m) S_ISBLK(m)
#define VKI_S_ISREG(m) S_ISREG(m)
#define VKI_S_ISFIFO(m) S_ISFIFO(m)
#define VKI_S_ISLNK(m) S_ISLNK(m)
#define VKI_S_ISSOCK(m) S_ISSOCK(m)

#define VKI_S_ISUID S_ISUID
#define VKI_S_ISGID S_ISGID
#define VKI_S_ISVTX S_ISVTX
#define VKI_S_IRUSR S_IRUSR
#define VKI_S_IWUSR S_IWUSR
#define VKI_S_IXUSR S_IXUSR
#define VKI_S_IRWXU S_IRWXU
#define VKI_S_IRGRP S_IRGRP
#define VKI_S_IWGRP S_IWGRP
#define VKI_S_IXGRP S_IXGRP
#define VKI_S_IRWXG S_IRWXG
#define VKI_S_IROTH S_IROTH
#define VKI_S_IWOTH S_IWOTH
#define VKI_S_IXOTH S_IXOTH
#define VKI_S_IRWXO S_IRWXO

/*
   #if defined __USE_BSD && !defined __S_IFLNK
   # define S_ISLNK(mode)  0
   #endif

   #if defined __USE_MISC && defined __USE_BSD
   # define S_IREAD    S_IRUSR
   # define S_IWRITE   S_IWUSR
   # define S_IEXEC    S_IXUSR
   #endif

   These are not required, I suppose.
*/

#define vki_stat stat
#define vki_stat64 stat64

//#define st_atime      st_atimespec.tv_sec
#define st_atime_nsec st_atimespec.tv_nsec
//#define st_mtime      st_mtimespec.tv_sec
#define st_mtime_nsec st_mtimespec.tv_nsec
//#define st_ctime      st_ctimespec.tv_sec
#define st_ctime_nsec st_ctimespec.tv_nsec


#include <dirent.h>

#define vki_dirent dirent
#define vki_dirent64 dirent64
#define VKI_MAXNAMLEN MAXNAMLEN


#include <i386-gnu/sys/socket.h>

//#define VKI_SOCKET_TYPE __socket_type
#define VKI_SOCK_STREAM SOCK_STREAM
#define	VKI_SOCK_DGRAM  SOCK_DGRAM
#define	VKI_SOCK_RAW	SOCK_RAW

#define	VKI_AF_UNIX		AF_UNIX
#define	VKI_AF_INET		AF_INET
#define	VKI_AF_INET6	AF_INET6

#define	VKI_SOL_SOCKET	SOL_SOCKET

#define VKI_SO_REUSEADDR SO_REUSEADDR

#define VKI_SO_SNDBUF 	SO_SNDBUF
#define VKI_SO_RCVBUF 	SO_RCVBUF
#define VKI_SO_SNDLOWAT SO_SNDLOWAT
#define VKI_SO_RCVLOWAT SO_RCVLOWAT
#define VKI_SO_SNDTIMEO SO_SNDTIMEO
#define VKI_SO_RCVTIMEO SO_RCVTIMEO
#define VKI_SO_ERROR 	SO_ERROR
#define VKI_SO_TYPE 	SO_TYPE

#define vki_sa_family_t sa_family_t
#define vki_sockaddr 	sockaddr
#define vki_iovec 		iovec
#define vki_msghdr 		msghdr
#define vki_cmsghdr 	cmsghdr


#include <i386-gnu/sys/un.h>

#define vki_sockaddr_un sockaddr_un


#include <netinet/in.h>

#define vki_in_addr_t in_addr_t
#define vki_in_port_t in_port_t
#define vki_in_addr in_addr
#define vki_sockaddr_in sockaddr_in

#define vki_in6_addr in6_addr
#define vki_sockaddr_in6 sockaddr_in6

#include <net/if.h>

#define VKI_IFNAMSIZ	IF_NAMESIZE

#define vki_ifreq 		ifreq
#define vki_ifr_name	ifr_name
#define vki_ifr_hwaddr	ifr_hwaddr
#define vki_ifr_addr	ifr_addr
#define vki_ifr_dstaddr	ifr_dstaddr
#define vki_ifr_broadaddr	ifr_broadaddr
#define vki_ifr_netmask	ifr_netmask
#define vki_ifr_flags	ifr_flags
#define vki_ifr_metric	ifr_metric
#define vki_ifr_mtu		ifr_mtu
#define vki_ifr_map		ifr_map
#define vki_ifr_slave	ifr_slave
#define vki_ifr_data	ifr_data
#define vki_ifr_ifindex	ifr_ifindex
#define vki_ifr_bandwidth	ifr_bandwidth
#define vki_ifr_qlen	ifr_qlen
#define vki_ifr_newname	ifr_newname

#define vki_ifconf 		ifconf
#define vki_ifc_buf 	ifc_buf
#define vki_ifc_req 	ifc_req


#include <fcntl.h>

#define VKI_O_RDONLY    	O_RDONLY
#define VKI_O_WRONLY    	O_WRONLY
#define VKI_O_RDWR      	O_RDWR
#define VKI_O_ACCMODE   	O_ACCMODE
#define VKI_O_READ			O_READ
#define VKI_O_WRITE			O_WRITE
#define VKI_O_EXEC			O_EXEC
#define VKI_O_NORW			O_NORW
#define VKI_O_LARGEFILE		O_LARGEFILE
#define	VKI_O_CREAT			O_CREAT
#define	VKI_O_EXCL			O_EXCL
#define VKI_O_NOLINK		O_NOLINK
#define VKI_O_NOTRANS		O_NOTRANS
#define VKI_O_NOFOLLOW		O_NOFOLLOW
#define VKI_O_DIRECTORY		O_DIRECTORY
#define	VKI_O_APPEND		O_APPEND
#define VKI_O_ASYNC			O_ASYNC
#define VKI_O_FSYNC			O_FSYNC
#define VKI_O_SYNC			O_SYNC
#define VKI_O_NOATIME		O_NOATIME
#define VKI_O_SHLOCK		O_SHLOCK
#define VKI_O_EXLOCK		O_EXLOCK
#define VKI_O_DSYNC			O_DSYNC
#define VKI_O_RSYNC			O_RSYNC
#define	VKI_O_NONBLOCK		O_NONBLOCK
#define VKI_O_NDELAY		O_NDELAY
#define VKI_O_HURD			O_HURD
#define	VKI_O_TRUNC			O_TRUNC
#define VKI_O_CLOEXEC		O_CLOEXEC
#define VKI_O_IGNORE_CTTY 	O_IGNORE_CTTY
#define	VKI_O_NOCTTY 		O_NOCTTY

#define VKI_F_DUPFD     F_DUPFD
#define VKI_F_GETFD     F_GETFD
#define VKI_F_SETFD     F_SETFD
#define VKI_F_GETFL     F_GETFL
#define VKI_F_SETFL     F_SETFL
#define VKI_F_GETOWN    F_GETOWN
#define VKI_F_SETOWN    F_SETOWN
#define VKI_F_GETLK     F_GETLK
#define VKI_F_SETLK     F_SETLK
#define VKI_F_SETLKW    F_SETLKW

#define VKI_F_DUPFD_CLOEXEC F_DUPFD_CLOEXEC
#define	VKI_FD_CLOEXEC	FD_CLOEXEC

#define	VKI_F_RDLCK		F_RDLCK
#define	VKI_F_WRLCK		F_WRLCK
#define	VKI_F_UNLCK		F_UNLCK


#include <i386-gnu/sys/mman.h>

#define	VKI_PROT_NONE	PROT_NONE
#define	VKI_PROT_READ	PROT_READ
#define	VKI_PROT_WRITE	PROT_WRITE
#define	VKI_PROT_EXEC	PROT_EXEC


#define VKI_MAP_FILE	 	MAP_FILE
#define VKI_MAP_ANON	 	MAP_ANON
#define VKI_MAP_TYPE	 	MAP_TYPE
#define VKI_MAP_ANONYMOUS	VKI_MAP_ANON

#define VKI_MAP_COPY	 	MAP_COPY
#define	VKI_MAP_SHARED	 	MAP_SHARED
#define	VKI_MAP_PRIVATE	 	MAP_PRIVATE
#define	VKI_MAP_FIXED	 	MAP_FIXED

#define VKI_MAP_NOEXTEND	MAP_NOEXTEND
#define VKI_MAP_HASSEMPHORE MAP_HASSEMPHORE
#define VKI_MAP_INHERIT	 	MAP_INHERIT

#define VKI_MAP_FAILED	MAP_FAILED


#include <i386-gnu/a.out.h>

#define VKI_PAGE_SIZE		PAGE_SIZE
#define VKI_MAX_PAGE_SIZE	VKI_PAGE_SIZE

// these 2 symbols were borrowed from gnumach/i386/include/mach/i386/vm_param.h

#define VKI_PAGE_SHIFT      12
#define VKI_MAX_PAGE_SHIFT  VKI_PAGE_SHIFT

// Since there's no upper limit on the length of a path as is the
// case with GNU, VKI_PATH_MAX is set arbitrarily.

#define VKI_PATH_MAX 	4096
#define VKI_MAXPATHLEN	VKI_PATH_MAX


#include <signal.h>

#define VKI_MINSIGSTKSZ	MINSIGSTKSZ

#define	VKI_SIG_BLOCK	SIG_BLOCK
#define	VKI_SIG_UNBLOCK	SIG_UNBLOCK
#define	VKI_SIG_SETMASK	SIG_SETMASK

#define	VKI_SIG_ERR	 SIG_ERR
#define	VKI_SIG_DFL	 SIG_DFL
#define	VKI_SIG_IGN	 SIG_IGN
#define VKI_SIG_HOLD SIG_HOLD

#define	_VKI_NSIG	33
#define _VKI_NSIG_BPW	33
#define _VKI_NSIG_WORDS	(_VKI_NSIG / _VKI_NSIG_BPW)

/*
   In GNU 'sigset_t', is defined as:
   // A `sigset_t' has a bit for each signal. //
   typedef unsigned long int __sigset_t;
   Just because it isn't an array, and the VG_(sig...set) functions
   assume it is, like darwin, instead of
   #define vki_sigset_t __sigset_t
   we do:
 */
typedef struct {
   unsigned long int sig[_VKI_NSIG_WORDS];
} vki_sigset_t;

#define	VKI_SIGHUP		SIGHUP
#define	VKI_SIGINT		SIGINT
#define	VKI_SIGQUIT		SIGQUIT
#define	VKI_SIGILL		SIGILL
#define	VKI_SIGTRAP		SIGTRAP
#define	VKI_SIGIOT		SIGIOT
#define	VKI_SIGABRT		VKI_SIGIOT
#define	VKI_SIGEMT		SIGEMT
#define	VKI_SIGFPE		SIGFPE
#define	VKI_SIGKILL		SIGKILL
#define	VKI_SIGBUS		SIGBUS
#define	VKI_SIGSEGV		SIGSEGV
#define	VKI_SIGSYS		SIGSYS
#define	VKI_SIGPIPE		SIGPIPE
#define	VKI_SIGALRM		SIGALRM
#define	VKI_SIGTERM		SIGTERM
#define	VKI_SIGURG		SIGURG
#define	VKI_SIGSTOP		SIGSTOP
#define	VKI_SIGTSTP		SIGTSTP
#define	VKI_SIGCONT		SIGCONT
#define	VKI_SIGCHLD		SIGCHLD
#define	VKI_SIGCLD		VKI_SIGCHLD
#define	VKI_SIGTTIN		SIGTTIN
#define	VKI_SIGTTOU		SIGTTOU
#define	VKI_SIGIO		SIGIO
#define	VKI_SIGPOLL		VKI_SIGIO
#define	VKI_SIGXCPU		SIGXCPU
#define	VKI_SIGXFSZ		SIGXFSZ
#define	VKI_SIGVTALRM	SIGVTALRM
#define	VKI_SIGPROF		SIGPROF
#define	VKI_SIGWINCH	SIGWINCH
#define VKI_SIGINFO		SIGINFO
#define	VKI_SIGUSR1		SIGUSR1
#define	VKI_SIGUSR2		SIGUSR2
#define VKI_SIGLOST		SIGLOST

#define VKI_SA_ONSTACK	 SA_ONSTACK
#define VKI_SA_RESTART	 SA_RESTART
#define VKI_SA_NODEFER	 SA_NODEFER
#define VKI_SA_RESETHAND SA_RESETHAND
#define VKI_SA_SIGINFO	 SA_SIGINFO
#define	VKI_SA_NOCLDSTOP SA_NOCLDSTOP
#define VKI_SA_INTERRUPT SA_INTERRUPT

#define VKI_SA_NOMASK	VKI_SA_NODEFER
#define VKI_SA_ONESHOT  VKI_SA_RESETHAND
#define VKI_SA_STACK    VKI_SA_ONSTACK

#define VKI_SS_ONSTACK   SS_ONSTACK
#define VKI_SS_DISABLE   SS_DISABLE


#define vki_siginfo_t siginfo_t


#define __vki_sighandler_t __sighandler_t

struct vki_sigaction_base
  {
    /* Signal handler.  */
#ifdef __USE_POSIX199309
    union
      {
    /* Used if SA_SIGINFO is not set.  */
    __vki_sighandler_t ksa_handler;
    /* Used if SA_SIGINFO is set.  */
    void (*ksa_sigaction) (int, vki_siginfo_t *, void *);
      } __vki_sigaction_handler;
# define ksa_handler    __vki_sigaction_handler.ksa_handler
# define ksa_sigaction   __vki_sigaction_handler.ksa_sigaction
#else
    __vki_sighandler_t ksa_handler;
#endif

    /* Additional set of signals to be blocked.  */
    vki_sigset_t sa_mask;

    /* Special flags.  */
    int sa_flags;
  };

//#define vki_sigaction_base sigaction
typedef  struct vki_sigaction_base  vki_sigaction_toK_t;
typedef  struct vki_sigaction_base  vki_sigaction_fromK_t;


#define vki_stack_t	stack_t
#define vki_sigcontext sigcontext


#define VKI_SI_ASYNCIO	SI_ASYNCIO
#define VKI_SI_MESGQ	SI_MESGQ
#define VKI_SI_TIMER	SI_TIMER
#define VKI_SI_QUEUE	SI_QUEUE
#define VKI_SI_USER		SI_USER

#define VKI_ILL_ILLOPC	ILL_ILLOPC
#define VKI_ILL_ILLOPN	ILL_ILLOPN
#define VKI_ILL_ILLADR	ILL_ILLADR
#define VKI_ILL_ILLTRP	ILL_ILLTRP
#define VKI_ILL_PRVOPC	ILL_PRVOPC
#define VKI_ILL_PRVREG	ILL_PRVREG
#define VKI_ILL_COPROC	ILL_COPROC
#define VKI_ILL_BADSTK	ILL_BADSTK

#define VKI_FPE_INTDIV	FPE_INTDIV
#define VKI_FPE_INTOVF	FPE_INTOVF
#define VKI_FPE_FLTDIV	FPE_FLTDIV
#define VKI_FPE_FLTOVF	FPE_FLTOVF
#define VKI_FPE_FLTUND	FPE_FLTUND
#define VKI_FPE_FLTRES	FPE_FLTRES
#define VKI_FPE_FLTINV	FPE_FLTINV
#define VKI_FPE_FLTSUB	FPE_FLTSUB

#define VKI_SEGV_MAPERR	SEGV_MAPERR
#define VKI_SEGV_ACCERR	SEGV_ACCERR

#define VKI_BUS_ADRALN	BUS_ADRALN
#define VKI_BUS_ADRERR	BUS_ADRERR
#define VKI_BUS_OBJERR	BUS_OBJERR

#define VKI_TRAP_BRKPT	TRAP_BRKPT
#define VKI_TRAP_TRACE	TRAP_TRACE

#define VKI_CLD_EXITED	CLD_EXITED
#define VKI_CLD_KILLED	CLD_KILLED
#define VKI_CLD_DUMPED	CLD_DUMPED
#define VKI_CLD_TRAPPED	CLD_TRAPPED
#define VKI_CLD_STOPPED	CLD_STOPPED
#define VKI_CLD_CONTINUED	CLD_CONTINUED

#define VKI_POLL_IN		POLL_IN
#define VKI_POLL_OUT	POLL_OUT
#define VKI_POLL_MSG	POLL_MSG
#define VKI_POLL_ERR	POLL_ERR
#define VKI_POLL_PRI	POLL_PRI
#define VKI_POLL_HUP	POLL_HUP

#include <errno.h>

#define	VKI_EPERM EPERM
#define	VKI_ENOENT ENOENT
#define	VKI_ESRCH ESRCH
#define	VKI_EINTR EINTR
#define	VKI_EIO EIO
#define	VKI_ENXIO ENXIO
#define	VKI_E2BIG E2BIG
#define	VKI_ENOEXEC ENOEXEC
#define	VKI_EBADF EBADF
#define	VKI_ECHILD ECHILD
#define	VKI_EDEADLK EDEADLK
#define	VKI_ENOMEM ENOMEM
#define	VKI_EACCES EACCES
#define	VKI_EFAULT EFAULT
#define	VKI_ENOTBL ENOTBLK
#define	VKI_EBUSY EBUSY
#define	VKI_EEXIST EEXIST
#define	VKI_EXDEV EXDEV
#define	VKI_ENODEV ENODEV
#define	VKI_ENOTDIR ENOTDIR
#define	VKI_EISDIR EISDIR
#define	VKI_EINVAL EINVAL
#define	VKI_EMFILE EMFILE
#define	VKI_ENFILE ENFILE
#define	VKI_ENOTTY ENOTTY
#define	VKI_ETXTBSY ETXTBSY
#define	VKI_EFBIG EFBIG
#define	VKI_ENOSPC ENOSPC
#define	VKI_ESPIPE ESPIPE
#define	VKI_EROFS EROFS
#define	VKI_EMLINK EMLINK
#define	VKI_EPIPE EPIPE
#define	VKI_EDOM EDOM
#define	VKI_ERANGE ERANGE
#define	VKI_EAGAIN EAGAIN
#define VKI_EWOULDBLOCK VKI_EAGAIN
#define	VKI_EINPROGRESS EINPROGRESS
#define	VKI_EALREADY EALREADY
#define	VKI_ENOTSOCK ENOTSOCK
#define	VKI_EMSGSIZE EMSGSIZE
#define	VKI_EPROTOTYPE EPROTOTYPE
#define	VKI_ENOPROTOOPT ENOPROTOOPT
#define	VKI_EPROTONOSUPPORT EPROTONOSUPPORT
#define	VKI_ESOCKTNOSUPPORT SOCKTNOSUPPORT
#define	VKI_EOPNOTSUPP EOPNOTSUPP
#define	VKI_EPFNOSUPPORT EPFNOSUPPORT
#define	VKI_EAFNOSUPPORT EAFNOSUPPORT
#define	VKI_EADDRINUSE EADDRINUSE
#define	VKI_EADDRNOTAVAIL EADDRNOTAVAIL
#define	VKI_ENETDOWN ENETDOWN
#define	VKI_ENETUNREACH ENETUNREACH
#define	VKI_ENETRESET ENETRESET
#define	VKI_ECONNABORTED ECONNABORTED
#define	VKI_ECONNRESET ECONNRESET
#define	VKI_ENOBUFS ENOBUFS
#define	VKI_EISCONN EISCONN
#define	VKI_ENOTCONN ENOTCONN
#define	VKI_EDESTADDRREQ EDESTADDRREQ
#define	VKI_ESHUTDOWN ESHUTDOWN
#define	VKI_ETOOMANYREFS ETOOMANYREFS
#define	VKI_ETIMEDOUT ETIMEDOUT
#define	VKI_ECONNREFUSED ECONNREFUSED
#define	VKI_ELOOP ELOOP
#define	VKI_ENAMETOOLONG ENAMETOOLONG
#define	VKI_EHOSTDOWN EHOSTDOWN
#define	VKI_EHOSTUNREACH EHOSTUNREACH
#define	VKI_ENOTEMPTY ENOTEMPTY
#define	VKI_EPROCLIM EPROCLIM
#define	VKI_EUSERS EUSERS
#define	VKI_EDQUOT EDQUOT
#define	VKI_ESTALE ESTALE
#define	VKI_EREMOTE EREMOTE
#define	VKI_EBADRPC EBADRPC
#define	VKI_ERPCMISMATCH ERPCMISMATCH
#define	VKI_EPROGUNAVAIL EPROGUNAVAIL
#define	VKI_EPROGMISMATCH EPROGMISMATCH
#define	VKI_EPROCUNAVAIL EPROCUNAVAIL
#define	VKI_ENOLCK ENOLCK
#define	VKI_EFTYPE EFTYPE
#define	VKI_EAUTH EAUTH
#define	VKI_ENEEDAUTH ENEEDAUTH
#define	VKI_ENOSYS ENOSYS
#define	VKI_ENOTSUP ENOTSUP
#define	VKI_EILSEQ EILSEQ
#define	VKI_EBACKGROUND EBACKGROUND
#define	VKI_EDIED EDIED
#define	VKI_ED ED
#define	VKI_EGREGIOUS EGREGIOUS
#define	VKI_EIEIO EIEIO
#define	VKI_EGRATUITOUS EGRATUITOUS
#define	VKI_EBADMSG EBADMSG
#define	VKI_EIDRM EIDRM
#define	VKI_EMULTIHOP EMULTIHOP
#define	VKI_ENODATA ENODATA
#define	VKI_ENOLINK ENOLINK
#define	VKI_ENOMSG ENOMSG
#define	VKI_ENOSR ENOSR
#define	VKI_ENOSTR ENOSTR
#define	VKI_EOVERFLOW EOVERFLOW
#define	VKI_EPROTO EPROTO
#define	VKI_ETIME ETIME
#define	VKI_ECANCELED ECANCELED


#include <i386-gnu/sys/resource.h>

//#define VKI_RLIMIT_RESOURCE __rlimit_resource

#define	VKI_RLIMIT_CPU		RLIMIT_CPU
#define	VKI_RLIMIT_FSIZE	RLIMIT_FSIZE
#define	VKI_RLIMIT_DATA		RLIMIT_DATA
#define	VKI_RLIMIT_STACK	RLIMIT_STACK
#define	VKI_RLIMIT_CORE		RLIMIT_CORE
#define	VKI_RLIMIT_RSS		RLIMIT_RSS
#define	VKI_RLIMIT_MEMLOCK	RLIMIT_MEMLOCK
#define	VKI_RLIMIT_NPROC	RLIMIT_NPROC
#define	VKI_RLIMIT_OFILE	RLIMIT_OFILE
#define	VKI_RLIMIT_NOFILE	RLIMIT_NOFILE
#define VKI_RLIMIT_SBSIZE	RLIMIT_SBSIZE
#define VKI_RLIMIT_AS		RLIMIT_AS
#define VKI_RLIMIT_VMEM		RLIMIT_AS
#define VKI_RLIMIT_NLIMITS	RLIMIT_NLIMITS
#define VKI_RLIM_NLIMITS	VKI_RLIMIT_NLIMITS

#define vki_rlim_t rlim_t
#define vki_rlim64_t rlim64_t
#define vki_rlimit rlimit
#define vki_rlimit64 rlimit64
#define vki_rusage rusage


#include <i386-gnu/sys/poll.h>

#define vki_pollfd pollfd

#define VKI_POLLIN	VKI_POLLIN
#define VKI_POLLPRI	POLLPRI
#define VKI_POLLOUT	POLLOUT

#define VKI_POLLRDNORM	VKI_POLLIN
#define VKI_POLLRDBAND	VKI_POLLPRI
#define VKI_POLLWRNORM	VKI_POLLOUT
#define VKI_POLLWRBAND	VKI_POLLOUT

#define VKI_POLLERR	POLLERR
#define VKI_POLLHUP	POLLHUP
#define VKI_POLLNVAL	POLLNVAL


#include <i386-gnu/sys/ipc.h>

#define	VKI_IPC_RMID	IPC_RMID
#define	VKI_IPC_SET		IPC_SET
#define	VKI_IPC_STAT	IPC_STAT
#define	VKI_IPC_INFO	IPC_INFO

#define vki_key_t key_t
#define vki_ipc_perm ipc_perm


#include <i386-gnu/sys/sem.h>

#define VKI_GETPID	GETPID
#define VKI_GETVAL	GETVAL
#define VKI_GETALL	GETALL
#define VKI_GETNCNT	GETNCNT
#define VKI_GETZCNT	GETZCNT
#define VKI_SETVAL	SETVAL
#define VKI_SETALL	SETALL

#define vki_sembuf sembuf
#define vki_semid_ds semid_ds
//#define vki_semun semun


#include <semaphore.h>

#define vki_sem_t sem_t


#include <rpcsvc/mount.h> //inc


#include <i386-gnu/sys/select.h>

#define vki_fd_set fd_set


#include <i386-gnu/sys/msg.h>

#define vki_msgbuf msgbuf


#include <i386-gnu/sys/shm.h>

#define VKI_SHM_RDONLY	SHM_RDONLY
#define VKI_SHM_RND		SHM_RND
#define VKI_SHM_REMAP	SHM_REMAP
#define VKI_SHMLBA		SHMLBA

#define vki_shmid_ds shmid_ds


#include <i386-gnu/sys/times.h>

#define vki_tms tms

#define _VKI_UTSNAME_SYSNAME_LENGTH 	_UTSNAME_SYSNAME_LENGTH
#define _VKI_UTSNAME_NODENAME_LENGTH 	_UTSNAME_NODENAME_LENGTH
#define _VKI_UTSNAME_RELEASE_LENGTH 	_UTSNAME_RELEASE_LENGTH
#define _VKI_UTSNAME_VERSION_LENGTH 	_UTSNAME_VERSION_LENGTH
#define _VKI_UTSNAME_MACHINE_LENGTH 	_UTSNAME_MACHINE_LENGTH

#define vki_new_utsname utsname


#include <unistd.h>

#define VKI_R_OK    R_OK
#define VKI_W_OK    W_OK
#define VKI_X_OK    X_OK
#define VKI_F_OK    F_OK

#include <i386-gnu/sys/ptrace.h>

#define VKI_PTRACE_TRACEME     PTRACE_TRACEME
#define VKI_PTRACE_PEEKTEXT    PTRACE_PEEKTEXT
#define VKI_PTRACE_PEEKDATA    PTRACE_PEEKDATA
#define VKI_PTRACE_PEEKUSER    PTRACE_PEEKUSER
#define VKI_PTRACE_POKETEXT    PTRACE_POKETEXT
#define VKI_PTRACE_POKEDATA    PTRACE_POKEDATA
#define VKI_PTRACE_POKEUSER    PTRACE_POKEUSER
#define VKI_PTRACE_CONT        PTRACE_CONT
#define VKI_PTRACE_KILL        PTRACE_KILL
#define VKI_PTRACE_SINGLESTEP  PTRACE_SINGLESTEP
#define VKI_PTRACE_ATTACH      PTRACE_ATTACH
#define VKI_PTRACE_DETACH      PTRACE_DETACH
#define VKI_PTRACE_GETREGS     PTRACE_GETREGS
#define VKI_PTRACE_SETREGS     PTRACE_SETREGS
#define VKI_PTRACE_GETFPREGS   PTRACE_GETFPREGS
#define VKI_PTRACE_SETFPREGS   PTRACE_SETFPREGS
#define VKI_PTRACE_READDATA    PTRACE_READDATA
#define VKI_PTRACE_WRITEDATA   PTRACE_WRITEDATA
#define VKI_PTRACE_READTEXT    PTRACE_READTEXT
#define VKI_PTRACE_WRITETEXT   PTRACE_WRITETEXT
#define VKI_PTRACE_GETFPAREGS  PTRACE_GETFPAREGS
#define VKI_PTRACE_SETFPAREGS  PTRACE_SETFPAREGS








#endif
