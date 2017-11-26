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
                         public ComboBox::Listener,
                         public Button::Listener,
                         public Slider::Listener
{
public:
    //==============================================================================
    TriggerSettings ();
    ~TriggerSettings();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

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

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	int m_mode;
	bool m_testEnable;
	OutputComponent *m_Output;
	Communicator *m_Com;
	TRIGGER_STRUCTURE m_Trigger;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ComboBox> triggerBox;
    ScopedPointer<ComboBox> interfaceBox;
    ScopedPointer<ComboBox> typeBox;
    ScopedPointer<ComboBox> functionBox;
    ScopedPointer<ToggleButton> invertToggle;
    ScopedPointer<ToggleButton> retriggerToggle;
    ScopedPointer<ToggleButton> polyToggle;
    ScopedPointer<ToggleButton> loopToggle;
    ScopedPointer<ToggleButton> lockToggle;
    ScopedPointer<Slider> trigVolSlider;
    ScopedPointer<ComboBox> outputBox;
    ScopedPointer<TextButton> resetButton;
    ScopedPointer<TextButton> addButton;
    ScopedPointer<TextEditor> lowText;
    ScopedPointer<TextEditor> highText;
    ScopedPointer<Label> label;
    ScopedPointer<Label> label2;
    ScopedPointer<Label> label3;
    ScopedPointer<Label> label4;
    ScopedPointer<Label> volLabel;
    ScopedPointer<Label> rangeLabel1;
    ScopedPointer<Label> rangeLabel2;
    ScopedPointer<Label> outLabel;
    ScopedPointer<TextButton> updateButton;
    ScopedPointer<TextButton> deleteButton;
    ScopedPointer<TextButton> copyButton;
    ScopedPointer<TextButton> testButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TriggerSettings)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
