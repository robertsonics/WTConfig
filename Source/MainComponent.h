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
#include "TriggerSettings.h"
#include "MidiSettings.h"
#include "AudioSettings.h"
#include "OutputComponent.h"
#include "RemoteControl.h"
#include "HelpComponent.h"
#include "Communicator.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainContentComponent  : public Component,
                              public ComboBox::Listener,
                              public Button::Listener
{
public:
    //==============================================================================
    MainContentComponent ();
    ~MainContentComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	bool setBaud(int baud);
	int getBaud(void);
	bool setQwiic(int add);
	int getQwiic(void);
	void setMode(int mode);

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	TriggerSettings *trigSettings;
	MidiSettings *midiSettings;
	AudioSettings *audioSettings;
	RemoteControl *remoteControl;

	Communicator *pCom;		// Our Communicator
	bool m_portOpenFlag;	// port open flag
	int m_portBoxItem;		// Current portBox item index
	int m_mode;				// Current mode

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<GroupComponent> groupComponent;
    ScopedPointer<TabbedComponent> tabbedComponent;
    ScopedPointer<OutputComponent> Output;
    ScopedPointer<ComboBox> modeBox;
    ScopedPointer<HelpComponent> helpWindow;
    ScopedPointer<Label> label;
    ScopedPointer<ComboBox> portBox;
    ScopedPointer<Label> label2;
    ScopedPointer<ComboBox> baudBox;
    ScopedPointer<Label> label3;
    ScopedPointer<ComboBox> testBaudBox;
    ScopedPointer<Label> label4;
    ScopedPointer<Label> label5;
    ScopedPointer<TextButton> stopAllButton;
    ScopedPointer<Label> label6;
    ScopedPointer<Label> label7;
    ScopedPointer<ComboBox> qwiicBox;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
