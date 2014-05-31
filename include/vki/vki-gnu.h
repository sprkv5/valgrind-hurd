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


// Since there's no upper limit on the length of a path as is the
// case with GNU, VKI_PATH_MAX is set arbitrarily.

#define VKI_PATH_MAX 4096


//----------------------------------------------------------------------
// From /usr/include/i386-gnu/bits/stat.h
//  and /usr/include/i386-gnu/sys/stat.h
//----------------------------------------------------------------------

#define VKI_S_IFMT    0170000

#define VKI_S_IFDIR   0040000
#define VKI_S_IFCHR   0020000
#define VKI_S_IFBLK   0060000
#define VKI_S_IFREG   0100000
#define VKI_S_IFLNK   0120000
#define VKI_S_IFSOCK  0140000
#define VKI_S_IFIFO   0010000

#define VKI_S_ISTYPE(mode, mask)  (((mode) & VKI_S_IFMT) == (mask))

#define VKI_S_ISDIR(mode)    VKI_S_ISTYPE((mode), VKI_S_IFDIR)
#define VKI_S_ISCHR(mode)    VKI_S_ISTYPE((mode), VKI_S_IFCHR)
#define VKI_S_ISBLK(mode)    VKI_S_ISTYPE((mode), VKI_S_IFBLK)
#define VKI_S_ISREG(mode)    VKI_S_ISTYPE((mode), VKI_S_IFREG)
#define VKI_S_ISFIFO(mode)   VKI_S_ISTYPE((mode), VKI_S_IFIFO)
#define VKI_S_ISLNK(mode)    VKI_S_ISTYPE((mode), VKI_S_IFLNK)
#define VKI_S_ISSOCK(mode)   VKI_S_ISTYPE((mode), VKI_S_IFSOCK)

#define VKI_S_ISUID   04000
#define VKI_S_ISGID   02000
#define VKI_S_ISVTX   01000
#define VKI_S_IREAD   00400
#define VKI_S_IWRITE  00200
#define VKI_S_IEXEC   00100

#define VKI_S_IRUSR VKI_S_IREAD
#define VKI_S_IWUSR VKI_S_IWRITE
#define VKI_S_IXUSR VKI_S_IEXEC
#define VKI_S_IRWXU (VKI_S_IREAD|VKI_S_IWRITE|VKI_S_IEXEC)

#define VKI_S_IRGRP (VKI_S_IRUSR >> 3)
#define VKI_S_IWGRP (VKI_S_IWUSR >> 3)
#define VKI_S_IXGRP (VKI_S_IXUSR >> 3)
#define VKI_S_IRWXG (VKI_S_IRWXU >> 3)

#define VKI_S_IROTH (VKI_S_IRGRP >> 3)
#define VKI_S_IWOTH (VKI_S_IWGRP >> 3)
#define VKI_S_IXOTH (VKI_S_IXGRP >> 3)
#define VKI_S_IRWXO (VKI_S_IRWXG >> 3)

