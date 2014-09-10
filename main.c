/*
 * main.c
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
#include "main.h"

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()  {
    return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

/*
 * 
 * name: kill_proc
 * @param const char* process_name
 * @return 1 if successful, 0 if not
 * 
 */

cell AMX_NATIVE_CALL kill_proc(AMX *amx, cell *params) {
	int len;
	cell *addr = NULL;
	amx_GetAddr(amx, params [1], &addr); 
    amx_StrLen(addr, &len);
	char* proc = malloc (++len);
	amx_GetString(proc, addr, 0, len);
	int pid = get_process_id (proc);
	if (pid == 0) {
		logprintf ("Process %s not found!", proc);
		free (proc);
		return 0;
	}
	
	logprintf ("Process %s | ID: %d", proc, pid);
	kill (pid, SIGKILL) != 0 ? logprintf ("Need root access for kill %s!", proc) : logprintf ("Process %s <%d> was successfully killed!", proc, pid);
	free (proc);
	return 1;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData)  {
    pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
    logprintf = (logprintf_t) ppData[PLUGIN_DATA_LOGPRINTF];
    logprintf("######################################");
    logprintf("#	Process Killer by IIeJIbMeHb	#");
    logprintf("#		 Success Loaded				#");
    logprintf("######################################\n");
    return 1;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload() {
    logprintf("Process Killer Unloaded") ;
}

AMX_NATIVE_INFO PluginNatives[] = {
	{"kill_proc", kill_proc },
    {0, 0}
};

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *amx) {
    return amx_Register( amx, PluginNatives, -1 ) ;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx) {
    return AMX_ERR_NONE ;
}

/*EOF*/
