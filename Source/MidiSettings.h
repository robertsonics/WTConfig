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
                      public juce::ComboBox::Listener,
                      public juce::Slider::Listener,
                      public juce::Button::Listener
{
public:
    //==============================================================================
    MidiSettings ();
    ~MidiSettings() override;

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

    void paint (juce::Graphics& g) override;
    void resized() override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	OutputComponent *m_Output;
	int m_mode;

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Label> labelChan;
    std::unique_ptr<juce::ComboBox> channelBox;
    std::unique_ptr<juce::ComboBox> pitchBox;
    std::unique_ptr<juce::Label> labelPitch;
    std::unique_ptr<juce::Slider> releaseSlider;
    std::unique_ptr<juce::Label> labelRelease;
    std::unique_ptr<juce::ToggleButton> ignoreVelToggle;
    std::unique_ptr<juce::ToggleButton> ignoreOffToggle;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidiSettings)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

