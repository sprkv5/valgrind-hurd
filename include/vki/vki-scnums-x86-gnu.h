/*--------------------------------------------------------------------*/
/*--- System call numbers for x86-gnu.        vki-scnums-x86-gnu.h ---*/
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

#ifndef __VKI_SCNUMS_X86_GNU_H
#define __VKI_SCNUMS_X86_GNU_H

#define __NR_evc_wait 				17
#define __NR_evc_wait_clear			18
#define __NR_mach_msg_trap			25
#define __NR_mach_reply_port			26
#define __NR_mach_thread_self			27
#define __NR_mach_task_self			28
#define __NR_mach_host_self			29
#define __NR_mach_print				30
#define __NR_syscall_device_writev_request	39
#define __NR_syscall_device_write_request	40
#define __NR_swtch_pri				59
#define __NR_swtch				60
#define __NR_thread_switch			61
#define __NR_syscall_vm_map			64
#define __NR_syscall_vm_allocate		65
#define __NR_syscall_vm_deallocate		66
#define __NR_syscall_task_create		68
#define __NR_syscall_task_terminate		69
#define __NR_syscall_task_suspend		70
#define __NR_syscall_task_set_special_port	71
#define __NR_syscall_mach_port_allocate		72
#define __NR_syscall_mach_port_deallocate	73
#define __NR_syscall_mach_port_insert_right	74
#define __NR_syscall_mach_port_allocate_name	75
#define __NR_syscall_thread_depress_abort	76

#endif /*__VKI_SCNUMS_X86_GNU_H*/