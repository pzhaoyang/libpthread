/* Wait on a semaphore.  Generic version.
   Copyright (C) 2005-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If
   not, see <http://www.gnu.org/licenses/>.  */

#include <semaphore.h>
#include <pt-internal.h>

extern int __sem_timedwait_internal (sem_t *restrict sem,
				     const struct timespec *restrict timeout);

int
__sem_wait (sem_t *sem)
{
  return __sem_timedwait_internal (sem, 0);
}

strong_alias (__sem_wait, sem_wait);
