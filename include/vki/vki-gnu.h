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
