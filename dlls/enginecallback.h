/*
*
*   This program is free software; you can redistribute it and/or modify it
*   under the terms of the GNU General Public License as published by the
*   Free Software Foundation; either version 2 of the License, or (at
*   your option) any later version.
*
*   This program is distributed in the hope that it will be useful, but
*   WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*   General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program; if not, write to the Free Software Foundation,
*   Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
*   In addition, as a special exception, the author gives permission to
*   link the code of this program with the Half-Life Game Engine ("HL
*   Engine") and Modified Game Libraries ("MODs") developed by Valve,
*   L.L.C ("Valve").  You must obey the GNU General Public License in all
*   respects for all of the code used other than the HL Engine and MODs
*   from Valve.  If you modify this file, you may extend this exception
*   to your version of the file, but you are not obligated to do so.  If
*   you do not wish to do so, delete this exception statement from your
*   version.
*
*/

#pragma once

#include "event_flags.h"

// Must be provided by user of this code
extern enginefuncs_t gEnginefuncs;

// The actual engine callbacks
#define GETPLAYERUSERID					(*gEnginefuncs.pfnGetPlayerUserId)
#define PRECACHE_MODEL					(*gEnginefuncs.pfnPrecacheModel)
#define PRECACHE_SOUND					(*gEnginefuncs.pfnPrecacheSound)
#define PRECACHE_GENERIC				(*gEnginefuncs.pfnPrecacheGeneric)
#define SET_MODEL						(*gEnginefuncs.pfnSetModel)
#define MODEL_INDEX						(*gEnginefuncs.pfnModelIndex)
#define MODEL_FRAMES					(*gEnginefuncs.pfnModelFrames)
#define SET_SIZE						(*gEnginefuncs.pfnSetSize)
#define CHANGE_LEVEL					(*gEnginefuncs.pfnChangeLevel)
#define GET_SPAWN_PARMS					(*gEnginefuncs.pfnGetSpawnParms)
#define SAVE_SPAWN_PARMS				(*gEnginefuncs.pfnSaveSpawnParms)
#define VEC_TO_YAW						(*gEnginefuncs.pfnVecToYaw)
#define VEC_TO_ANGLES					(*gEnginefuncs.pfnVecToAngles)
#define MOVE_TO_ORIGIN					(*gEnginefuncs.pfnMoveToOrigin)
#define oldCHANGE_YAW					(*gEnginefuncs.pfnChangeYaw)
#define CHANGE_PITCH					(*gEnginefuncs.pfnChangePitch)
#define MAKE_VECTORS					(*gEnginefuncs.pfnMakeVectors)
#define CREATE_ENTITY					(*gEnginefuncs.pfnCreateEntity)
#define REMOVE_ENTITY					(*gEnginefuncs.pfnRemoveEntity)
#define CREATE_NAMED_ENTITY				(*gEnginefuncs.pfnCreateNamedEntity)
#define MAKE_STATIC						(*gEnginefuncs.pfnMakeStatic)
#define ENT_IS_ON_FLOOR					(*gEnginefuncs.pfnEntIsOnFloor)
#define DROP_TO_FLOOR					(*gEnginefuncs.pfnDropToFloor)
#define WALK_MOVE						(*gEnginefuncs.pfnWalkMove)
#define SET_ORIGIN						(*gEnginefuncs.pfnSetOrigin)
#define EMIT_SOUND_DYN2					(*gEnginefuncs.pfnEmitSound)
#define BUILD_SOUND_MSG					(*gEnginefuncs.pfnBuildSoundMsg)
#define TRACE_LINE						(*gEnginefuncs.pfnTraceLine)
#define TRACE_TOSS						(*gEnginefuncs.pfnTraceToss)
#define TRACE_MONSTER_HULL				(*gEnginefuncs.pfnTraceMonsterHull)
#define TRACE_HULL						(*gEnginefuncs.pfnTraceHull)
#define TRACE_MODEL						(*gEnginefuncs.pfnTraceModel)
#define GET_AIM_VECTOR					(*gEnginefuncs.pfnGetAimVector)
#define SERVER_COMMAND					(*gEnginefuncs.pfnServerCommand)
#define SERVER_EXECUTE					(*gEnginefuncs.pfnServerExecute)
#define CLIENT_COMMAND					(*gEnginefuncs.pfnClientCommand)
#define PARTICLE_EFFECT					(*gEnginefuncs.pfnParticleEffect)
#define LIGHT_STYLE						(*gEnginefuncs.pfnLightStyle)
#define DECAL_INDEX						(*gEnginefuncs.pfnDecalIndex)
#define POINT_CONTENTS					(*gEnginefuncs.pfnPointContents)
#define CRC32_INIT						(*gEnginefuncs.pfnCRC32_Init)
#define CRC32_PROCESS_BUFFER			(*gEnginefuncs.pfnCRC32_ProcessBuffer)
#define CRC32_PROCESS_BYTE				(*gEnginefuncs.pfnCRC32_ProcessByte)
#define CRC32_FINAL						(*gEnginefuncs.pfnCRC32_Final)
#define RANDOM_LONG						(*gEnginefuncs.pfnRandomLong)
#define RANDOM_FLOAT					(*gEnginefuncs.pfnRandomFloat)
#define ADD_SERVER_COMMAND				(*gEnginefuncs.pfnAddServerCommand)
#define SET_CLIENT_LISTENING			(*gEnginefuncs.pfnVoice_SetClientListening)
#define GETPLAYERAUTHID					(*gEnginefuncs.pfnGetPlayerAuthId)
#define GET_FILE_SIZE					(*gEnginefuncs.pfnGetFileSize)
#define GET_APPROX_WAVE_PLAY_LEN		(*gEnginefuncs.pfnGetApproxWavePlayLen)
#define IS_CAREER_MATCH					(*gEnginefuncs.pfnIsCareerMatch)
#define GET_LOCALIZED_STRING_LENGTH		(*gEnginefuncs.pfnGetLocalizedStringLength)
#define REGISTER_TUTOR_MESSAGE_SHOWN	(*gEnginefuncs.pfnRegisterTutorMessageShown)
#define GET_TIMES_TUTOR_MESSAGE_SHOWN	(*gEnginefuncs.pfnGetTimesTutorMessageShown)
#define ENG_CHECK_PARM					(*gEnginefuncs.pfnEngCheckParm)

inline void MESSAGE_BEGIN(int msg_dest, int msg_type, const float *pOrigin = nullptr, edict_t *ed = nullptr)
{
	(*gEnginefuncs.pfnMessageBegin)(msg_dest, msg_type, pOrigin, ed);
}

template <typename T = void>
inline T *GET_PRIVATE(edict_t *pEdict)
{
	if (pEdict)
	{
		return static_cast<T *>(pEdict->pvPrivateData);
	}

	return nullptr;
}

#define MESSAGE_END					(*gEnginefuncs.pfnMessageEnd)
#define WRITE_BYTE					(*gEnginefuncs.pfnWriteByte)
#define WRITE_CHAR					(*gEnginefuncs.pfnWriteChar)
#define WRITE_SHORT					(*gEnginefuncs.pfnWriteShort)
#define WRITE_LONG					(*gEnginefuncs.pfnWriteLong)
#define WRITE_ANGLE					(*gEnginefuncs.pfnWriteAngle)
#define WRITE_COORD					(*gEnginefuncs.pfnWriteCoord)
#define WRITE_STRING				(*gEnginefuncs.pfnWriteString)
#define WRITE_ENTITY				(*gEnginefuncs.pfnWriteEntity)
#define CVAR_REGISTER				(*gEnginefuncs.pfnCVarRegister)
#define CVAR_GET_FLOAT				(*gEnginefuncs.pfnCVarGetFloat)
#define CVAR_GET_STRING				(*gEnginefuncs.pfnCVarGetString)
#define CVAR_SET_FLOAT				(*gEnginefuncs.pfnCVarSetFloat)
#define CVAR_SET_STRING				(*gEnginefuncs.pfnCVarSetString)
#define CVAR_GET_POINTER			(*gEnginefuncs.pfnCVarGetPointer)
#define ALERT						(*gEnginefuncs.pfnAlertMessage)
#define ENGINE_FPRINTF				(*gEnginefuncs.pfnEngineFprintf)
#define ALLOC_PRIVATE				(*gEnginefuncs.pfnPvAllocEntPrivateData)
#define FREE_PRIVATE				(*gEnginefuncs.pfnFreeEntPrivateData)
//#define STRING					(*gEnginefuncs.pfnSzFromIndex)
#define ALLOC_STRING				(*gEnginefuncs.pfnAllocString)
#define FIND_ENTITY_BY_STRING		(*gEnginefuncs.pfnFindEntityByString)
#define GETENTITYILLUM				(*gEnginefuncs.pfnGetEntityIllum)
#define FIND_ENTITY_IN_SPHERE		(*gEnginefuncs.pfnFindEntityInSphere)
#define FIND_CLIENT_IN_PVS			(*gEnginefuncs.pfnFindClientInPVS)
#define FIND_ENTITY_IN_PVS			(*gEnginefuncs.pfnEntitiesInPVS)
#define EMIT_AMBIENT_SOUND			(*gEnginefuncs.pfnEmitAmbientSound)
#define GET_MODEL_PTR				(*gEnginefuncs.pfnGetModelPtr)
#define REG_USER_MSG				(*gEnginefuncs.pfnRegUserMsg)
#define GET_BONE_POSITION			(*gEnginefuncs.pfnGetBonePosition)
#define FUNCTION_FROM_NAME			(*gEnginefuncs.pfnFunctionFromName)
#define NAME_FOR_FUNCTION			(*gEnginefuncs.pfnNameForFunction)
#define TRACE_TEXTURE				(*gEnginefuncs.pfnTraceTexture)
#define CLIENT_PRINTF				(*gEnginefuncs.pfnClientPrintf)
#define SERVER_PRINT				(*gEnginefuncs.pfnServerPrint)
#define CMD_ARGS					(*gEnginefuncs.pfnCmd_Args)
#define CMD_ARGC					(*gEnginefuncs.pfnCmd_Argc)
#define CMD_ARGV					(*gEnginefuncs.pfnCmd_Argv)
#define GET_ATTACHMENT				(*gEnginefuncs.pfnGetAttachment)
#define SET_VIEW					(*gEnginefuncs.pfnSetView)
#define SET_CROSSHAIRANGLE			(*gEnginefuncs.pfnCrosshairAngle)
#define LOAD_FILE_FOR_ME			(*gEnginefuncs.pfnLoadFileForMe)
#define FREE_FILE					(*gEnginefuncs.pfnFreeFile)
#define END_SECTION					(*gEnginefuncs.pfnEndSection)
#define COMPARE_FILE_TIME			(*gEnginefuncs.pfnCompareFileTime)
#define GET_GAME_DIR				(*gEnginefuncs.pfnGetGameDir)
#define SET_CLIENT_MAXSPEED			(*gEnginefuncs.pfnSetClientMaxspeed)
#define CREATE_FAKE_CLIENT			(*gEnginefuncs.pfnCreateFakeClient)
#define PLAYER_RUN_MOVE				(*gEnginefuncs.pfnRunPlayerMove)
#define NUMBER_OF_ENTITIES			(*gEnginefuncs.pfnNumberOfEntities)
#define GET_INFO_BUFFER				(*gEnginefuncs.pfnGetInfoKeyBuffer)
#define GET_KEY_VALUE				(*gEnginefuncs.pfnInfoKeyValue)
#define SET_KEY_VALUE				(*gEnginefuncs.pfnSetKeyValue)
#define SET_CLIENT_KEY_VALUE		(*gEnginefuncs.pfnSetClientKeyValue)
#define IS_MAP_VALID				(*gEnginefuncs.pfnIsMapValid)
#define STATIC_DECAL				(*gEnginefuncs.pfnStaticDecal)
#define IS_DEDICATED_SERVER			(*gEnginefuncs.pfnIsDedicatedServer)
#define PRECACHE_EVENT				(*gEnginefuncs.pfnPrecacheEvent)
#define PLAYBACK_EVENT_FULL			(*gEnginefuncs.pfnPlaybackEvent)
#define ENGINE_SET_PVS				(*gEnginefuncs.pfnSetFatPVS)
#define ENGINE_SET_PAS				(*gEnginefuncs.pfnSetFatPAS)
#define ENGINE_CHECK_VISIBILITY		(*gEnginefuncs.pfnCheckVisibility)
#define DELTA_SET					(*gEnginefuncs.pfnDeltaSetField)
#define DELTA_UNSET					(*gEnginefuncs.pfnDeltaUnsetField)
#define DELTA_ADDENCODER			(*gEnginefuncs.pfnDeltaAddEncoder)
#define ENGINE_CURRENT_PLAYER		(*gEnginefuncs.pfnGetCurrentPlayer)
#define ENGINE_CANSKIP				(*gEnginefuncs.pfnCanSkipPlayer)
#define DELTA_FINDFIELD				(*gEnginefuncs.pfnDeltaFindField)
#define DELTA_SETBYINDEX			(*gEnginefuncs.pfnDeltaSetFieldByIndex)
#define DELTA_UNSETBYINDEX			(*gEnginefuncs.pfnDeltaUnsetFieldByIndex)
#define REMOVE_KEY_VALUE			(*gEnginefuncs.pfnInfo_RemoveKey)
#define SET_PHYSICS_KEY_VALUE		(*gEnginefuncs.pfnSetPhysicsKeyValue)
#define ENGINE_GETPHYSINFO			(*gEnginefuncs.pfnGetPhysicsInfoString)
#define ENGINE_SETGROUPMASK			(*gEnginefuncs.pfnSetGroupMask)
#define ENGINE_INSTANCE_BASELINE	(*gEnginefuncs.pfnCreateInstancedBaseline)
#define ENGINE_FORCE_UNMODIFIED		(*gEnginefuncs.pfnForceUnmodified)
#define PLAYER_CNX_STATS			(*gEnginefuncs.pfnGetPlayerStats)
