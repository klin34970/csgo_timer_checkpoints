#if defined _timer_included
 #endinput
#endif
#define _timer_included

#pragma semicolon 1
#include <csgocolors>

#define PL_VERSION		"3.0.0.0"

/*** SETTINGS ***/
#define MAX_STYLES	32 //Max number of styles (default 32 ID:0-31)
#define MAX_TRACKS	6 // Normal+Bonus1-5

//Max. number of door/button based bhop blocks handled in a map
#define MAX_BHOPBLOCKS	1024

/*** DON'T CHANGE ***/

//Tracks
#define TRACK_NORMAL 				0
#define TRACK_BONUS 				1
#define TRACK_BONUS2 				2
#define TRACK_BONUS3 				3
#define TRACK_BONUS4 				4
#define TRACK_BONUS5 				5	

//Max-Length
#define PLUGIN_NAME_RESERVED_LENGTH 33
#define CONVAR_MAX_LEN 512

//Cstrike
#define CS_TEAMS_NUM 4
#define CS_SLOT_KNIFE 2
#define ITEMS_TYPES_NUM 10
#define ITEMS_STR_LEN 32
#define MAX_CASH 16000

//Specmodes
#define SPECMODE_NONE 					0
#define SPECMODE_FIRSTPERSON 			4
#define SPECMODE_3RDPERSON 				5
#define SPECMODE_FREELOOK	 			6

//Func_ Flags
#define SF_BUTTON_DONTMOVE				(1<<0)		//dont move when fired (func_button)
#define SF_BUTTON_TOUCH_ACTIVATES		(1<<8)		//button fires when touched (func_button)
#define SF_DOOR_PTOUCH					(1<<10)		//player touch opens (func_door)

//Jump Stamina, can reduce landing speed loss and increase max jump high to engine limit
#define STAMINA_DISABLED				-1.0
#define STAMINA_FULL					0.0

#define MAX_FILE_LEN 128

#define	DAMAGE_NO						0
#define DAMAGE_EVENTS_ONLY				1				// Call damage functions, but don't modify health
#define	DAMAGE_YES						2
#define	DAMAGE_AIM						3

#define COLLISION_GROUP_DEBRIS_TRIGGER	2		//Noblock
#define COLLISION_GROUP_PLAYER			5		//Block
#define COLLISION_GROUP_PUSHAWAY		17		//Push away collision

#define USE_PROFILING // Enable/disable profiling
#define MAX_PROFILERS 100// Maximum number of profiling log points
#define MAX_CONCURENT_PROFILERS 10// Maximum number of concurent profilers (nested)
#define MAX_PRFOILER_NAME 256 // Maximum length of a profiler's name

enum FX
{
	FxNone = 0,
	FxPulseFast,
	FxPulseSlowWide,
	FxPulseFastWide,
	FxFadeSlow,
	FxFadeFast,
	FxSolidSlow,
	FxSolidFast,
	FxStrobeSlow,
	FxStrobeFast,
	FxStrobeFaster,
	FxFlickerSlow,
	FxFlickerFast,
	FxNoDissipation,
	FxDistort,					// Distort/scale/translate flicker
	FxHologram,					// kRenderFxDistort + distance fade
	FxExplode,					// Scale up really big!
	FxGlowShell,				// Glowing Shell
	FxClampMinScale,			// Keep this sprite from getting very small (SPRITES only!)
	FxEnvRain,					// for environmental rendermode, make rain
	FxEnvSnow,					// for environmental rendermode, make snow
	FxSpotlight,
	FxRagdoll,
	FxPulseFastWider,
}

enum Render
{
	Normal = 0, 				// src
	TransColor, 				// c*a+dest*(1-a)
	TransTexture,				// src*a+dest*(1-a)
	Glow,						// src*a+dest -- No Z buffer checks -- Fixed size in screen space
	TransAlpha,					// src*srca+dest*(1-srca)
	TransAdd,					// src*a+dest
	Environmental,				// not drawn, used for environmental effects
	TransAddFrameBlend,			// use a fractional frame value to blend between animation frames
	TransAlphaAdd,				// src + dest*(1-a)
	WorldGlow,					// Same as kRenderGlow but not fixed size in screen space
	None,						// Don't render.
}

enum VelocityOverride {
	
	VelocityOvr_None = 0,
	VelocityOvr_Velocity,
	VelocityOvr_OnlyWhenNegative,
	VelocityOvr_InvertReuseVelocity
}

enum MCategory {
	
	MCategory_Ranked = 0,
	MCategory_Fun,
	MCategory_Practise
}

enum MapZone
{
    Id,
    MapZoneType:Type,
    String:Map[32],
    Float:Point1[3],
    Float:Point2[3],
    Level_Id,
	String:zName[32],
	NPC
}

/**
 * Called when a timer starts.
 *
 * @param client The owner of the timer.
 *
 * @noreturn
 */
forward OnTimerStarted(client);

/**
 * Called when a timer stops.
 *
 * @param client The owner of the timer.
 *
 * @noreturn
 */
forward OnTimerStopped(client);

/**
 * Called when a timer resets. (all timer data get lost).
 *
 * @param client The owner of the timer.
 *
 * @noreturn
 */
forward OnTimerReseted(client);

/**
 * Called when a timer restarts.
 *
 * @param client The owner of the timer.
 *
 * @noreturn
 */
forward OnTimerRestart(client);

/**
 * Called when a timer pauses.
 *
 * @param client The owner of the timer.
 *
 * @noreturn
 */
forward OnTimerPaused(client);

/**
 * Called when a timer continues.
 *
 * @param client The owner of the timer.
 *
 * @noreturn
 */
forward OnTimerResumed(client);

/**
 * Called when a round finishes as world record.
 *
 * @param client The client who finished the round.
 * @param track End zone type (0:normal 1:bonus 2:short)
 * @param style Style ID
 * @param time Float record time
 * @param lasttime Float last record time (0.0 if first record)
 * @param currentrank Old position of player.
 * @param newrank New position of player.
 * @noreturn
 */
forward OnTimerWorldRecord(client, track, style, Float:time, Float:lasttime, currentrank, newrank);

/**
 * Called when a round finishes as personal record.
 *
 * @param client The client who finished the round.
 * @param track End zone type (0:normal 1:bonus 2:short)
 * @param style Style ID
 * @param time Float record time
 * @param lasttime Float last record time (0.0 if first record)
 * @param currentrank Old position of player.
 * @param newrank New position of player.
 * @noreturn
 */
forward OnTimerPersonalRecord(client, track, style, Float:time, Float:lasttime, currentrank, newrank);

/**
 * Called when a round finishes as top 10 record.
 *
 * @param client The client who finished the round.
 * @param track End zone type (0:normal 1:bonus 2:short)
 * @param style Style ID
 * @param time Float record time
 * @param lasttime Float last record time (0.0 if first record)
 * @param currentrank Old position of player.
 * @param newrank New position of player.
 * @noreturn
 */
forward OnTimerTop10Record(client, track, style, Float:time, Float:lasttime, currentrank, newrank);

/**
 * Called when a round finishes first time.
 *
 * @param client The client who finished the round.
 * @param track End zone type (0:normal 1:bonus 2:short)
 * @param style Style ID
 * @param time Float record time
 * @param lasttime Float last record time (0.0 if first record)
 * @param currentrank Old position of player.
 * @param newrank New position of player.
 * @noreturn
 */
forward OnTimerFirstRecord(client, track, style, Float:time, Float:lasttime, currentrank, newrank);

/**
 * Called when a round finishes.
 *
 * @param client The client who finished the round.
 * @param track End zone type (0:normal 1:bonus 2:short)
 * @param style Style ID
 * @param time Float record time
 * @param lasttime Float last record time (0.0 if first record)
 * @param currentrank Old position of player.
 * @param newrank New position of player.
 * @noreturn
 */
forward OnTimerRecord(client, track, style, Float:time, Float:lasttime, currentrank, newrank);

/**
 * Called when a player changes his style.
 *
 * @param client The client who finished the round.
 * @param oldatyle Style before change
 * @param newstyle Selected Style
 * @noreturn
 */
forward OnClientChangeStyle(client, oldstyle, newstyle, bool:isnewstyle);


/**
 * Reset a timer. (clear all data)
 *
 * @param client
 * @return Bool success
 */
native bool:Timer_Reset(client);

/**
 * Start a player timer
 *
 * @param client
 * @return Bool success
 */
native bool:Timer_Start(client);

/**
 * Stop a player timer
 *
 * @param client
 * @param paused
 * @return Bool success
 */
native bool:Timer_Stop(client, bool:stopPaused = true);

/**
 * Resume a player timer
 *
 * @param client
 * @return Bool success
 */
native bool:Timer_Resume(client);

/**
 * Pause a player timer
 *
 * @param client
 * @return Bool success
 */
native bool:Timer_Pause(client);

/**
 * Restart a player timer
 *
 * @param client
 * @return Bool success
 */
native bool:Timer_Restart(client);

/**
 * Reset a player timer
 *
 * @param client
 * @param penaltytime Float time to add to timer
 * @return Bool success
 */
native bool:Timer_AddPenaltyTime(client, Float:penaltytime);


/**
 * Get a player timer
 *
 * @param client
 * @param enabled Bool to store running state in
 * @param time Float to store running time in
 * @param jumps Integer to store jump count in
 * @param fpsmax Integer to store fpsmax count in
 * @return Bool success
 */
native bool:Timer_GetClientTimer(client, &enabled, &Float:time, &jumps, &fpsmax);

/**
 * Finishes a round.
 *
 * @param client The client that finishes the round.
 * @param map The map of the round.
 * @param time The time of the round, in seconds.
 * @param jumps The count of the jumps in that round.
 * @param physicsDifficulty Style ID
 * @param fpsmax The fpsmax value of the client.
 * @param track The end zone type (0:normal 1:bonus 2:short).
 *
 * @noreturn
 */
native Timer_FinishRound(client, const String:map[], Float:time, jumps, track, fpsmax, bonus);

/**
 * Forces a player to a new track.
 *
 * @param client The target client
 * @param track The new track (0:normal 1:bonus 2:short)
 * 
 * @noreturn
 */
native Timer_SetTrack(client, track);

/**
 * Returns clients active style ID.
 *
 * @param client The target client
 * 
 * @return The style ID.
 */
native Timer_GetStyle(client);

/**
 * Forces a player to a new style and apply its physics.
 *
 * @param client The target client
 * @param style The Style Id to check
 * 
 * @noreturn
 */
native Timer_SetStyle(client, style);

/**
 * Returns true if the given style is configured as ranked.
 *
 * @param style The Style Id to check
 * 
 * @return Bool ranked or not.
 */
native Timer_IsStyleRanked(style);

/**
 * Returns true if the client timer is enabled and not paused.
 *
 * @param client The target client
 * 
 * @return Bool running or not.
 */
native Timer_GetStatus(client);

/**
 * Returns true if the client timer paused.
 *
 * @param client The target client
 * 
 * @return Bool paused or not.
 */
native Timer_GetPauseStatus(client);

/**
 * Returns clients active track. (0:normal 1:bonus 2:short)
 *
 * @param client The target client
 * 
 * @return The style ID.
 */
native Timer_GetTrack(client);

/**
 * Returns current replay path name for a client
 *
 * @param client
 * @param name A reference to the file path (256).
 *
 * @noreturn
 */
native Timer_GetClientActiveReplayPath(client, String:path[]);

/**
 * Returns current replay file path for a client
 *
 * @param client
 * @param name A reference to the file name (32).
 *
 * @noreturn
 */
native Timer_GetClientActiveReplayFileName(client, String:file[]);

/**
 * Register a new profiler with a set name
 * @param num1    name of the profiled object
 * @return        index of the profiler for this object
 */
native int Tim3r_RegisterProfiler(char[] path);
 
/**
 * Start timing a section of code with a registered profiler
 * @param num1    id of the profiled object
 * @return        nothing
 */
native void Tim3r_StartProfiling(int index);
 
/**
 * End timing a section of code with a registered profiler, and add to the profiler log
 * @param num1    id of the profiled object
 * @return        nothing
 */
native void Tim3r_EndProfiling(int index);


public SharedPlugin:__pl_timer = 
{
	name = "timer",
	file = "timer-core.smx",
#if defined REQUIRE_PLUGIN
	required = 1,
#else
	required = 0,
#endif
};

public __pl_timer_SetNTVOpt()
{
	MarkNativeAsOptional("Timer_Start");
	MarkNativeAsOptional("Timer_Stop");
	MarkNativeAsOptional("Timer_Resume");
	MarkNativeAsOptional("Timer_Pause");
	MarkNativeAsOptional("Timer_Restart");
	MarkNativeAsOptional("Timer_Reset");
	MarkNativeAsOptional("Timer_AddPenaltyTime");
	MarkNativeAsOptional("Timer_GetClientTimer");
	MarkNativeAsOptional("Timer_FinishRound");
	MarkNativeAsOptional("Timer_GetStatus");
	MarkNativeAsOptional("Timer_GetTrack");
	MarkNativeAsOptional("Timer_SetTrack");
	MarkNativeAsOptional("Timer_GetMapFinishCount");
	MarkNativeAsOptional("Timer_GetMapFinishBonusCount");
	MarkNativeAsOptional("Timer_GetStyle");
	MarkNativeAsOptional("Timer_IsStyleRanked");
	MarkNativeAsOptional("Timer_SetStyle");	
	MarkNativeAsOptional("Timer_GetClientActiveReplayPath");	
	MarkNativeAsOptional("Timer_GetClientActiveReplayFileName");	
	MarkNativeAsOptional("Tim3r_RegisterProfiler");
	MarkNativeAsOptional("Tim3r_StartProfiling");
	MarkNativeAsOptional("Tim3r_EndProfiling");
}