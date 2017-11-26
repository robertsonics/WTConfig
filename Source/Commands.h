// **************************************************************************
//     Filename: COMMANDS.H
// Date Created: 8/23/2013
//      Version: 0.01
//
//
//  COPYRIGHT (c) Robertsonics 2013. All Rights Reserved
//
// **************************************************************************

#ifndef COMMANDS_H_INCLUDED
#define COMMANDS_H_INCLUDED


enum {
	TRACK_CONTROL_PLAY_SOLO,
	TRACK_CONTROL_PLAY_POLY,
	TRACK_CONTROL_PAUSE,
	TRACK_CONTROL_RESUME,
	TRACK_CONTROL_STOP,
	TRACK_CONTROL_LOOP_ON,
	TRACK_CONTROL_LOOP_OFF
};

#define CMD_GET_VERSION				1
#define CMD_GET_SYS_INFO			2
#define CMD_TRACK_CONTROL			3
#define CMD_STOP_ALL				4
#define CMD_MASTER_VOLUME			5
#define CMD_TRACK_VOLUME			8
#define CMD_AMP_POWER				9
#define CMD_TRACK_FADE				10
#define CMD_RESUME_ALL_SYNC			11
#define CMD_SAMPLERATE_OFFSET		12
#define	CMD_SET_REPORTING			13
#define CMD_SET_TRIGGER_BANK		14
#define CMD_SET_INPUT_MIX			15

enum {
	GET_VERSION = 0x01,
    GET_SYS_INFO,
	CONTROL_TRACK,
	STOP_ALL,
	VOLUME,
	TRIGGER_SET
};

enum {
	VERSION_STRING = 0x81,
	SYSTEM_INFO
};


#endif  // COMMANDS_H_INCLUDED
