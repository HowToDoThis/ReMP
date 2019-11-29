// Due I dont want any macro or def about REGAMEDLL_XXX or XXX_XXX on here.... so we
// need to act like using those of them

#include "extdll.h"

#define VFUNC virtual

using VectorRef = Vector&;
using FloatRef = float&;

#include "archtypes.h"
#include "enginecallback.h"
#include "entity_state.h"
#include "screenfade.h"
#include "utlvector.h"

// SDK
#include "usercmd.h"
#include "weaponinfo.h"
#include "customentity.h"

// Globals vars
#include "globals.h"
#include "saverestore.h"

// GameInit
#include "game.h"

// PM
#include "pm_defs.h"
#include "pm_materials.h"
#include "pm_movevars.h"
#include "pm_debug.h"
#include "pm_shared.h"
#include "pm_math.h"

#include "decals.h"
#include "hltv.h"
#include "cbase.h"

#include "sound.h"
#include "basemonster.h"
#include "monsters.h"
#include "unisignals.h"
#include "maprules.h"
#include "ammo.h"
#include "mortar.h"
#include "effects.h"
#include "lights.h"
#include "healthkit.h"
#include "vehicle.h"
#include "func_tank.h"
#include "func_break.h"
#include "doors.h"
#include "bmodels.h"

#include "debug.h"
#include "observer.h"
#include "client.h"

#include "trains.h"
#include "pathcorner.h"
#include "plats.h"
#include "buttons.h"

// CSBOT and Nav
// Hostage
// why regamedll need write this ugly thingy?
// we will using csbot_dll.h instead using this ugly thingy
// Game event enum used by career mode, tutor system, and bots
#include "csbot_dll.h"

#include "airtank.h"
#include "h_cycler.h"
#include "h_battery.h"

// Addons
#include "addons/item_airbox.h"
#include "addons/trigger_setorigin.h"
#include "addons/trigger_random.h"
#include "addons/point_command.h"

// Tutor
#include "tutor.h"
#include "tutor_base_states.h"
#include "tutor_base_tutor.h"
#include "tutor_cs_states.h"
#include "tutor_cs_tutor.h"

#include "revert_saved.h"
#include "triggers.h"
#include "subs.h"
#include "doors.h"
#include "explode.h"
#include "gamerules.h"
#include "mapinfo.h"
#include "career_tasks.h"
#include "training_gamerules.h"
#include "maprules.h"
#include "monsterevent.h"
#include "skill.h"
#include "soundent.h"
#include "spectator.h"
#include "talkmonster.h"
#include "animation.h"

#include "com_model.h"
#include "studio.h"
#include "r_studioint.h"

#include "shake.h"
