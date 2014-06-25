
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

typedef int		boolean_t;
typedef unsigned long mach_port_t
typedef int		kern_return_t

#define MACH_PORT_NULL			((mach_port_t) 0)
#define KERN_INVALID_ARGUMENT	4

mach_port_t	null_port()
{
	if (kern_invalid_debug) printf("Debugger invoked: null_port mach trap\n");
	//SoftDebugger("null_port mach trap");
	return(MACH_PORT_NULL);
}

kern_return_t	kern_invalid()
{
	if (kern_invalid_debug) printf("Debugger invoked: kern_invalid mach trap\n");
	//SoftDebugger("kern_invalid mach trap");
	return(KERN_INVALID_ARGUMENT);
}

extern	kern_return_t	syscall_vm_map();
extern	kern_return_t	syscall_vm_allocate();
extern	kern_return_t	syscall_vm_deallocate();

extern  kern_return_t	syscall_task_create();
extern  kern_return_t	syscall_task_terminate();
extern  kern_return_t	syscall_task_suspend();
extern  kern_return_t	syscall_task_set_special_port();

extern	kern_return_t	syscall_mach_port_allocate();
extern	kern_return_t	syscall_mach_port_deallocate();
extern	kern_return_t	syscall_mach_port_insert_right();
extern	kern_return_t	syscall_mach_port_allocate_name();

extern	kern_return_t	syscall_thread_depress_abort();
extern	kern_return_t	evc_wait();
extern	kern_return_t	evc_wait_clear();

extern	kern_return_t	syscall_device_write_request();
extern	kern_return_t	syscall_device_writev_request();


typedef struct {
	int		mach_trap_arg_count;
	int		(*mach_trap_function)();
	boolean_t	mach_trap_stack;
	int		mach_trap_unused;
} mach_trap_t;


#define	MACH_TRAP(name, arg_count)		\
		{ (arg_count), (int (*)()) (name), FALSE, 0 }
#define	MACH_TRAP_STACK(name, arg_count)	\
		{ (arg_count), (int (*)()) (name), TRUE, 0 }


mach_trap_t	mach_trap_table[] = {
	MACH_TRAP(kern_invalid, 0),		/* 0 */		/* Unix */
	MACH_TRAP(kern_invalid, 0),		/* 1 */		/* Unix */
	MACH_TRAP(kern_invalid, 0),		/* 2 */		/* Unix */
	MACH_TRAP(kern_invalid, 0),		/* 3 */		/* Unix */
	MACH_TRAP(kern_invalid, 0),		/* 4 */		/* Unix */
	MACH_TRAP(kern_invalid, 0),		/* 5 */		/* Unix */
	MACH_TRAP(kern_invalid, 0),		/* 6 */		/* Unix */
	MACH_TRAP(kern_invalid, 0),		/* 7 */		/* Unix */
	MACH_TRAP(kern_invalid, 0),		/* 8 */		/* Unix */
	MACH_TRAP(kern_invalid, 0),		/* 9 */		/* Unix */
	MACH_TRAP(null_port, 0),		/* 10 */
	MACH_TRAP(null_port, 0),		/* 11 */
	MACH_TRAP(null_port, 0),		/* 12 */
	MACH_TRAP(null_port, 0),		/* 13 */
	MACH_TRAP(kern_invalid, 0),		/* 14 */
	MACH_TRAP(kern_invalid, 0),		/* 15 */
	MACH_TRAP(kern_invalid, 0),		/* 16 */
	MACH_TRAP_STACK(evc_wait, 1),		/* 17 */
	MACH_TRAP_STACK(evc_wait_clear, 1),	/* 18 */
	MACH_TRAP(kern_invalid, 0),		/* 19 */
	MACH_TRAP(kern_invalid, 0),		/* 20 */
	MACH_TRAP(kern_invalid, 0),		/* 21 */
	MACH_TRAP(kern_invalid, 0),		/* 22 */
	MACH_TRAP(kern_invalid, 0),		/* 23 */
	MACH_TRAP(kern_invalid, 0),		/* 24 */
	MACH_TRAP_STACK(mach_msg_trap, 7),	/* 25 */
	MACH_TRAP(mach_reply_port, 0),		/* 26 */
	MACH_TRAP(mach_thread_self, 0),		/* 27 */
	MACH_TRAP(mach_task_self, 0),		/* 28 */
	MACH_TRAP(mach_host_self, 0),		/* 29 */
#ifdef MACH_KDB
	MACH_TRAP_STACK(mach_print, 1),		/* 30 */
#else /* MACH_KDB */
	MACH_TRAP_STACK(kern_invalid, 0),	/* 30 */
#endif /* MACH_KDB */

	MACH_TRAP(kern_invalid, 0),		/* 31 */
	MACH_TRAP(kern_invalid, 0),		/* 32 */
	MACH_TRAP(kern_invalid, 0),		/* 33 emul: task_by_pid */
	MACH_TRAP(kern_invalid, 0),		/* 34 emul: pid_by_task */
	MACH_TRAP(kern_invalid, 0),		/* 35 */
	MACH_TRAP(kern_invalid, 0),		/* 36 */
	MACH_TRAP(kern_invalid, 0),		/* 37 */
	MACH_TRAP(kern_invalid, 0),		/* 38 */

 	MACH_TRAP(syscall_device_writev_request, 6),	/* 39 */
 	MACH_TRAP(syscall_device_write_request, 6),	/* 40 */

	MACH_TRAP(kern_invalid, 0),		/* 41 emul: init_process */
	MACH_TRAP(kern_invalid, 0),		/* 42 */
	MACH_TRAP(kern_invalid, 0),		/* 43 emul: map_fd */
	MACH_TRAP(kern_invalid, 0),		/* 44 emul: rfs_make_symlink */
	MACH_TRAP(kern_invalid, 0),		/* 45 */
	MACH_TRAP(kern_invalid, 0),		/* 46 */
	MACH_TRAP(kern_invalid, 0),		/* 47 */
	MACH_TRAP(kern_invalid, 0),		/* 48 */
	MACH_TRAP(kern_invalid, 0),		/* 49 */

	MACH_TRAP(kern_invalid, 0),		/* 50 */
	MACH_TRAP(kern_invalid, 0),		/* 51 */
	MACH_TRAP(kern_invalid, 0),		/* 52 emul: htg_syscall */
	MACH_TRAP(kern_invalid, 0),	        /* 53 emul: set_ras_address */
	MACH_TRAP(kern_invalid, 0),	        /* 54 */
	MACH_TRAP(null_port, 0),		/* 55 */
	MACH_TRAP(null_port, 0),		/* 56 */
	MACH_TRAP(kern_invalid, 0),		/* 57 */
	MACH_TRAP(kern_invalid, 0),		/* 58 */
 	MACH_TRAP_STACK(swtch_pri, 1),		/* 59 */

	MACH_TRAP_STACK(swtch, 0),		/* 60 */
	MACH_TRAP_STACK(thread_switch, 3),	/* 61 */
	MACH_TRAP(kern_invalid, 0),		/* 62 */
	MACH_TRAP(kern_invalid, 0),		/* 63 */
	MACH_TRAP(syscall_vm_map, 11),			/* 64 */
	MACH_TRAP(syscall_vm_allocate, 4),		/* 65 */
	MACH_TRAP(syscall_vm_deallocate, 3),		/* 66 */
	MACH_TRAP(kern_invalid, 0),			/* 67 */
	MACH_TRAP(syscall_task_create, 3),		/* 68 */
	MACH_TRAP(syscall_task_terminate, 1),		/* 69 */

	MACH_TRAP(syscall_task_suspend, 1),		/* 70 */
	MACH_TRAP(syscall_task_set_special_port, 3),	/* 71 */
	MACH_TRAP(syscall_mach_port_allocate, 3),	/* 72 */
	MACH_TRAP(syscall_mach_port_deallocate, 2),	/* 73 */
	MACH_TRAP(syscall_mach_port_insert_right, 4),	/* 74 */
	MACH_TRAP(syscall_mach_port_allocate_name, 3),	/* 75 */
	MACH_TRAP(syscall_thread_depress_abort, 1),	/* 76 */
	MACH_TRAP(kern_invalid, 0),		/* 77 */
	MACH_TRAP(kern_invalid, 0),		/* 78 */
	MACH_TRAP(kern_invalid, 0),		/* 79 */

	MACH_TRAP(kern_invalid, 0),                   /* 80 */
	MACH_TRAP(kern_invalid, 0),                   /* 81 */
	MACH_TRAP(kern_invalid, 0),		      /* 82 */
	MACH_TRAP(kern_invalid, 0),		      /* 83 */
	MACH_TRAP(kern_invalid, 0),	              /* 84 */
	MACH_TRAP(kern_invalid, 0),		      /* 85 */
	MACH_TRAP(kern_invalid, 0),	              /* 86 */
	MACH_TRAP(kern_invalid, 0),		      /* 87 */
	MACH_TRAP(kern_invalid, 0),		      /* 88 */
	MACH_TRAP(kern_invalid, 0),		      /* 89 */
	MACH_TRAP(kern_invalid, 0),		      /* 90 */
	MACH_TRAP(kern_invalid, 0),	              /* 91 */
	MACH_TRAP(kern_invalid, 0),                   /* 92 */
	MACH_TRAP(kern_invalid, 0),	              /* 93 */
	MACH_TRAP(kern_invalid, 0),                   /* 94 */
	MACH_TRAP(kern_invalid, 0),                   /* 95 */

	MACH_TRAP(kern_invalid, 0),		      /* 96 */
	MACH_TRAP(kern_invalid, 0),		      /* 97 */

	MACH_TRAP(kern_invalid, 0),		      /* 98 */
	MACH_TRAP(kern_invalid, 0),		      /* 99 */

	MACH_TRAP(kern_invalid, 0),		/* 100 */
	MACH_TRAP(kern_invalid, 0),		/* 101 */
	MACH_TRAP(kern_invalid, 0),		/* 102 */
	MACH_TRAP(kern_invalid, 0),		/* 103 */
	MACH_TRAP(kern_invalid, 0),		/* 104 */
	MACH_TRAP(kern_invalid, 0),		/* 105 */
	MACH_TRAP(kern_invalid, 0),		/* 106 */
	MACH_TRAP(kern_invalid, 0),		/* 107 */
	MACH_TRAP(kern_invalid, 0),		/* 108 */
	MACH_TRAP(kern_invalid, 0),		/* 109 */

	MACH_TRAP(kern_invalid, 0),		/* 110 */
	MACH_TRAP(kern_invalid, 0),		/* 111 */
	MACH_TRAP(kern_invalid, 0),		/* 112 */
	MACH_TRAP(kern_invalid, 0),		/* 113 */
	MACH_TRAP(kern_invalid, 0),		/* 114 */
	MACH_TRAP(kern_invalid, 0),		/* 115 */
	MACH_TRAP(kern_invalid, 0),		/* 116 */
	MACH_TRAP(kern_invalid, 0),		/* 117 */
	MACH_TRAP(kern_invalid, 0),		/* 118 */
	MACH_TRAP(kern_invalid, 0),		/* 119 */

	MACH_TRAP(kern_invalid, 0),		/* 120 */
	MACH_TRAP(kern_invalid, 0),		/* 121 */
	MACH_TRAP(kern_invalid, 0),		/* 122 */
	MACH_TRAP(kern_invalid, 0),		/* 123 */
	MACH_TRAP(kern_invalid, 0),		/* 124 */
	MACH_TRAP(kern_invalid, 0),		/* 125 */
	MACH_TRAP(kern_invalid, 0),		/* 126 */
	MACH_TRAP(kern_invalid, 0),		/* 127 */
	MACH_TRAP(kern_invalid, 0),		/* 128 */
	MACH_TRAP(kern_invalid, 0),		/* 129 */
};

int mach_trap_count = (sizeof(mach_trap_table) / sizeof(mach_trap_table[0]));


#define VG_GNUMACH_TRAP(n) mach_trap_table[n]

#define __NR_evc_wait 							VG_GNUMACH_TRAP(17)
#define __NR_evc_wait_clear						VG_GNUMACH_TRAP(18)
#define __NR_mach_msg_trap						VG_GNUMACH_TRAP(25)
#define __NR_mach_reply_port					VG_GNUMACH_TRAP(26)
#define __NR_mach_thread_self					VG_GNUMACH_TRAP(27)
#define __NR_mach_task_self						VG_GNUMACH_TRAP(28)
#define __NR_mach_host_self						VG_GNUMACH_TRAP(29)
#define __NR_mach_print							VG_GNUMACH_TRAP(30)
#define __NR_syscall_device_writev_request		VG_GNUMACH_TRAP(39)
#define __NR_syscall_device_write_request		VG_GNUMACH_TRAP(40)
#define __NR_swtch_pri							VG_GNUMACH_TRAP(59)
#define __NR_swtch								VG_GNUMACH_TRAP(60)
#define __NR_thread_switch						VG_GNUMACH_TRAP(61)
#define __NR_syscall_vm_map						VG_GNUMACH_TRAP(64)
#define __NR_syscall_vm_allocate				VG_GNUMACH_TRAP(65)
#define __NR_syscall_vm_deallocate				VG_GNUMACH_TRAP(66)
#define __NR_syscall_task_create				VG_GNUMACH_TRAP(68)
#define __NR_syscall_task_terminate				VG_GNUMACH_TRAP(69)
#define __NR_syscall_task_suspend				VG_GNUMACH_TRAP(70)
#define __NR_syscall_task_set_special_port		VG_GNUMACH_TRAP(71)
#define __NR_syscall_mach_port_allocate			VG_GNUMACH_TRAP(72)
#define __NR_syscall_mach_port_deallocate		VG_GNUMACH_TRAP(73)
#define __NR_syscall_mach_port_insert_right		VG_GNUMACH_TRAP(74)
#define __NR_syscall_mach_port_allocate_name	VG_GNUMACH_TRAP(75)
#define __NR_syscall_thread_depress_abort		VG_GNUMACH_TRAP(76)

#endif /*__VKI_SCNUMS_X86_GNU_H*/
