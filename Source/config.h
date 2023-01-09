#pragma once

#define MY_BG_COLOUR            Colour(0xff181818)
#define MY_TAB_COLOUR           Colour(0xff252525)
#define MY_BUTTON_COLOUR        Colours::royalblue
#define MY_TEXT_COLOUR          Colours::white
#define MY_KNOB_COLOUR          Colours::springgreen
#define MY_ALARM_COLOUR         Colour(0xffb45ba0)

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
