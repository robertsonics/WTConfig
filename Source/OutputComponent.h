/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "config.h"

class TriggerSettings;
class MidiSettings;
class AudioSettings;
class MainContentComponent;

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class OutputComponent  : public Component,
                         public Button::Listener
{
public:
    //==============================================================================
    OutputComponent ();
    ~OutputComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    void setTriggerSettings(TriggerSettings *ts);
	void setMidiSettings(MidiSettings *ms);
	void setAudioSettings(AudioSettings *as);
	void setGlobalSettings(MainContentComponent *gs);
	void resetOutput(void);
	void setMode(int m);
	void updateInitWindow(void);
	void displayMsg(String msg);
	void refreshSettings(void);
	int getFirstValue(int n);

	bool setSerialBaud(int baud);
	bool setQwiicAddress(int add);
	bool setMidiPitch(int pitch);
	bool setMidiChannel(int chan);
	bool setMidiRelease(int release);
	bool setMidiFlags(int flags);

	bool setAudioVolume(int out, int vol);
	bool setAudioInputMix(int mix);
	bool setAmpEnable(bool ena);

	bool addTrigger(TRIGGER_STRUCTURE * pTrig);
	bool getTrigger(int t, TRIGGER_STRUCTURE * pTrig);
	void deleteTrigger(int n);

	String buildTriggerDesc(TRIGGER_STRUCTURE * pTrig);
	int findTrigger(int t);
	int getTriggerNum(String tStr);
	bool parseTriggerDesc(String tStr, TRIGGER_STRUCTURE * pTrig);

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	int m_mode;

	StringArray m_initStrings;
	TriggerSettings *m_trigSettings;
	MidiSettings *m_midiSettings;
	AudioSettings *m_audioSettings;
	MainContentComponent *m_globalSettings;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TextEditor> textEditor;
    ScopedPointer<TextButton> OpenButton;
    ScopedPointer<TextButton> SaveButton;
    ScopedPointer<TextButton> NewButton;
    ScopedPointer<TextButton> HelpButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OutputComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
