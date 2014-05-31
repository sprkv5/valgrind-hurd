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


// #include <malloc.h>
// tbd (to be done)


#include <time.h>

#define vki_timespec timespec
#define vki_tm tm
#define vki_itimerspec itimerspec
#define vki_sigevent sigevent


// Since there's no upper limit on the length of a path as is the
// case with GNU, VKI_PATH_MAX is set arbitrarily.

#define VKI_PATH_MAX 4096


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


#include <i386-gnu/bits/resource.h>

#define vki_rlimit rlimit
#define vki_rlimit64 rlimit64
#define vki_rusage rusage


#endif
