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

class OutputComponent;

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MidiSettings  : public Component,
                      public ComboBox::Listener,
                      public Slider::Listener,
                      public Button::Listener
{
public:
    //==============================================================================
    MidiSettings ();
    ~MidiSettings();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	void setOutputComponent(OutputComponent * out);
	void reset(void);
	void setMode(int mode);
	void enable(void);
	void disable(void);

	bool setFlags(int f);
	int getFlags(void);
	bool setRelease(int r);
	bool setChannel(int c);
	bool setBend(int b);

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	OutputComponent *m_Output;
	int m_mode;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> labelChan;
    ScopedPointer<ComboBox> channelBox;
    ScopedPointer<ComboBox> pitchBox;
    ScopedPointer<Label> labelPitch;
    ScopedPointer<Slider> releaseSlider;
    ScopedPointer<Label> labelRelease;
    ScopedPointer<ToggleButton> ignoreVelToggle;
    ScopedPointer<ToggleButton> ignoreOffToggle;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidiSettings)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
