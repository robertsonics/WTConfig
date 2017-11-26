#pragma once

#define MODE_WAV_TRIGGER		0
#define MODE_TSUNAMI_STEREO		1
#define MODE_TSUNAMI_MONO		2

#define TRIG_FLAGS_TYPE			0x03
#define TRIG_FLAGS_INTERFACE	0x04
#define TRIG_FLAGS_INVERT		0x08
#define TRIG_FLAGS_RETRIGGER	0x10
#define TRIG_FLAGS_LOOP			0x20
#define TRIG_FLAGS_POLY			0x40
#define TRIG_FLAGS_LOCK			0x80

typedef struct {
	int num;
	juce::uint8 flags;
	int function;
	int low;
	int high;
	int gain;
	int output;
} TRIGGER_STRUCTURE;
