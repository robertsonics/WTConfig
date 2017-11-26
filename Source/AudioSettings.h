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
class AudioSettings  : public Component,
                       public Slider::Listener,
                       public Button::Listener
{
public:
    //==============================================================================
    AudioSettings ();
    ~AudioSettings();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	void setOutputComponent(OutputComponent * out);
	void setCommunicator(Communicator * com);
	void reset(void);
	void setMode(int mode);
	void enableLive(bool en);

	bool setVolume(int o, int v);
	bool setInputMix(int m);

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	int m_mode;
	bool liveEnabled;
	OutputComponent *m_Output;
	Communicator *m_Com;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> outSlider1;
    ScopedPointer<Label> labelVol1;
    ScopedPointer<Slider> outSlider2;
    ScopedPointer<Label> labelVol2;
    ScopedPointer<Slider> outSlider3;
    ScopedPointer<Label> labelVol3;
    ScopedPointer<Slider> outSlider4;
    ScopedPointer<Label> labelVol4;
    ScopedPointer<Slider> outSlider5;
    ScopedPointer<Label> labelVol5;
    ScopedPointer<Slider> outSlider6;
    ScopedPointer<Label> labelVol6;
    ScopedPointer<Slider> outSlider7;
    ScopedPointer<Label> labelVol7;
    ScopedPointer<Slider> outSlider8;
    ScopedPointer<Label> labelVol8;
    ScopedPointer<ToggleButton> i12Toggle;
    ScopedPointer<ToggleButton> i34Toggle;
    ScopedPointer<ToggleButton> i56Toggle;
    ScopedPointer<ToggleButton> i78Toggle;
    ScopedPointer<Label> labelInMix;
    ScopedPointer<ToggleButton> liveToggle;
    ScopedPointer<ToggleButton> ampToggle;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioSettings)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
