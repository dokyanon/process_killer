/*
 * main.h
 * 
 * Copyright 2014 inn0va <inn0va@inn0va-G31T-M>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include "SDK/amx/amx.h"
#include "SDK/plugincommon.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

typedef void (*logprintf_t)(char* format, ...);
extern void *pAMXFunctions;
logprintf_t logprintf;

/*
 * 
 * name: get_process_id
 * @param const char* pname
 * @return (int) process id or -1 if process not found
 * 
 */


int get_process_id (const char* pname) {
   char buf [100] = "/bin/pidof ";
   char* p = &buf [0];
   strcat (buf, pname);
   
   FILE* f = popen (buf, "r");
   if (!f) {
      logprintf ("File /bin/pidof not found! LOL - , -");
      return -1;
   }
   
   while (!feof (f)) {
      *p++ = fgetc (f);
   }
   pclose (f);
   return (p > &buf [0]) ? atoi (buf) : -1;
}

/*EOF*/
