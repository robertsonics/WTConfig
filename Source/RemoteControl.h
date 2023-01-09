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

class Communicator;

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class RemoteControl  : public Component,
                       public ChangeListener,
                       public juce::Button::Listener
{
public:
    //==============================================================================
    RemoteControl ();
    ~RemoteControl() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	void setCommunicator(Communicator * com);
	void enableUI(bool en);
	void changeListenerCallback(ChangeBroadcaster *);

    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	Communicator * m_Com;

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextButton> getInfoButton;
    std::unique_ptr<juce::Label> versionLabel;
    std::unique_ptr<juce::Label> voicesLabel;
    std::unique_ptr<juce::Label> filesLabel;
    std::unique_ptr<juce::Label> label;
    std::unique_ptr<juce::Label> label2;
    std::unique_ptr<juce::Label> label3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RemoteControl)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

