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
class Communicator;

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TriggerSettings  : public Component,
                         public juce::ComboBox::Listener,
                         public juce::Button::Listener,
                         public juce::Slider::Listener
{
public:
    //==============================================================================
    TriggerSettings ();
    ~TriggerSettings() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	//void setOutputComponent(OutputComponent * out);
    void setOutputComponent(OutputComponent * out);
    void setCommunicator(Communicator * com);
	void resetTrigger(void);
	void setMode(int mode);
	void refreshTrigger(void);

	void expandTrigger(TRIGGER_STRUCTURE * pTrig);
	void collapseTrigger(TRIGGER_STRUCTURE * pTrig);
	void setTestEnable(bool tf)							{ m_testEnable = tf; }
	void enableDisableUI(void);

    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	int m_mode;
	bool m_testEnable;
	OutputComponent *m_Output;
	Communicator *m_Com;
	TRIGGER_STRUCTURE m_Trigger;

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::ComboBox> triggerBox;
    std::unique_ptr<juce::ComboBox> interfaceBox;
    std::unique_ptr<juce::ComboBox> typeBox;
    std::unique_ptr<juce::ComboBox> functionBox;
    std::unique_ptr<juce::ToggleButton> invertToggle;
    std::unique_ptr<juce::ToggleButton> retriggerToggle;
    std::unique_ptr<juce::ToggleButton> polyToggle;
    std::unique_ptr<juce::ToggleButton> loopToggle;
    std::unique_ptr<juce::ToggleButton> lockToggle;
    std::unique_ptr<juce::Slider> trigVolSlider;
    std::unique_ptr<juce::ComboBox> outputBox;
    std::unique_ptr<juce::TextButton> resetButton;
    std::unique_ptr<juce::TextButton> addButton;
    std::unique_ptr<juce::TextEditor> lowText;
    std::unique_ptr<juce::TextEditor> highText;
    std::unique_ptr<juce::Label> label;
    std::unique_ptr<juce::Label> label2;
    std::unique_ptr<juce::Label> label3;
    std::unique_ptr<juce::Label> label4;
    std::unique_ptr<juce::Label> volLabel;
    std::unique_ptr<juce::Label> rangeLabel1;
    std::unique_ptr<juce::Label> rangeLabel2;
    std::unique_ptr<juce::Label> outLabel;
    std::unique_ptr<juce::TextButton> updateButton;
    std::unique_ptr<juce::TextButton> deleteButton;
    std::unique_ptr<juce::TextButton> copyButton;
    std::unique_ptr<juce::TextButton> testButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TriggerSettings)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

