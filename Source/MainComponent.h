/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

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
#include "MyLookAndFeel.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainContentComponent  : public Component,
                              public juce::ComboBox::Listener,
                              public juce::Button::Listener
{
public:
    //==============================================================================
    MainContentComponent ();
    ~MainContentComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	bool setBaud(int baud);
	int getBaud(void);
	bool setQwiic(int add);
	int getQwiic(void);
	void setMode(int mode);

    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* logo_png;
    static const int logo_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	TriggerSettings *trigSettings;
	MidiSettings *midiSettings;
	AudioSettings *audioSettings;
	RemoteControl *remoteControl;
	OutputComponent *output;

	Communicator *pCom;		// Our Communicator
	bool m_portOpenFlag;	// port open flag
	int m_portBoxItem;		// Current portBox item index
	int m_mode;				// Current mode

    MyLookAndFeel myLookAndFeel;

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::GroupComponent> groupComponent;
    std::unique_ptr<juce::TabbedComponent> tabbedComponent;
    std::unique_ptr<juce::ComboBox> modeBox;
    std::unique_ptr<HelpComponent> helpWindow;
    std::unique_ptr<juce::Label> label;
    std::unique_ptr<juce::ComboBox> portBox;
    std::unique_ptr<juce::Label> label2;
    std::unique_ptr<juce::ComboBox> baudBox;
    std::unique_ptr<juce::Label> label3;
    std::unique_ptr<juce::ComboBox> testBaudBox;
    std::unique_ptr<juce::Label> label4;
    std::unique_ptr<juce::Label> label5;
    std::unique_ptr<juce::TextButton> stopAllButton;
    std::unique_ptr<juce::Label> label7;
    std::unique_ptr<juce::ComboBox> qwiicBox;
    juce::Image cachedImage_logo_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

