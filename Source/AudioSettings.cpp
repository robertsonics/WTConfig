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

//[Headers] You can add your own extra header files here...

#include "OutputComponent.h"
#include "Communicator.h"

//[/Headers]

#include "AudioSettings.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
AudioSettings::AudioSettings ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (outSlider1 = new Slider ("new slider"));
    outSlider1->setTooltip (TRANS("The gain (or attenuation) that will be applied to the audio mixed to this output or output pair."));
    outSlider1->setRange (-50, 10, 1);
    outSlider1->setSliderStyle (Slider::LinearBar);
    outSlider1->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    outSlider1->addListener (this);

    addAndMakeVisible (labelVol1 = new Label ("new label",
                                              TRANS("Output 1 Volume (dB)")));
    labelVol1->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelVol1->setJustificationType (Justification::centredLeft);
    labelVol1->setEditable (false, false, false);
    labelVol1->setColour (TextEditor::textColourId, Colours::black);
    labelVol1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (outSlider2 = new Slider ("new slider"));
    outSlider2->setTooltip (TRANS("The gain (or attenuation) that will be applied to the audio mixed to this output or output pair."));
    outSlider2->setRange (-50, 10, 1);
    outSlider2->setSliderStyle (Slider::LinearBar);
    outSlider2->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    outSlider2->addListener (this);

    addAndMakeVisible (labelVol2 = new Label ("new label",
                                              TRANS("Output 2 Volume (dB)")));
    labelVol2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelVol2->setJustificationType (Justification::centredLeft);
    labelVol2->setEditable (false, false, false);
    labelVol2->setColour (TextEditor::textColourId, Colours::black);
    labelVol2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (outSlider3 = new Slider ("new slider"));
    outSlider3->setTooltip (TRANS("The gain (or attenuation) that will be applied to the audio mixed to this output or output pair."));
    outSlider3->setRange (-50, 10, 1);
    outSlider3->setSliderStyle (Slider::LinearBar);
    outSlider3->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    outSlider3->addListener (this);

    addAndMakeVisible (labelVol3 = new Label ("new label",
                                              TRANS("Output 3 Volume (dB)")));
    labelVol3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelVol3->setJustificationType (Justification::centredLeft);
    labelVol3->setEditable (false, false, false);
    labelVol3->setColour (TextEditor::textColourId, Colours::black);
    labelVol3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (outSlider4 = new Slider ("new slider"));
    outSlider4->setTooltip (TRANS("The gain (or attenuation) that will be applied to the audio mixed to this output or output pair."));
    outSlider4->setRange (-50, 10, 1);
    outSlider4->setSliderStyle (Slider::LinearBar);
    outSlider4->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    outSlider4->addListener (this);

    addAndMakeVisible (labelVol4 = new Label ("new label",
                                              TRANS("Output 4 Volume (dB)")));
    labelVol4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelVol4->setJustificationType (Justification::centredLeft);
    labelVol4->setEditable (false, false, false);
    labelVol4->setColour (TextEditor::textColourId, Colours::black);
    labelVol4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (outSlider5 = new Slider ("new slider"));
    outSlider5->setTooltip (TRANS("The gain (or attenuation) that will be applied to the audio mixed to this output or output pair."));
    outSlider5->setRange (-50, 10, 1);
    outSlider5->setSliderStyle (Slider::LinearBar);
    outSlider5->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    outSlider5->addListener (this);

    addAndMakeVisible (labelVol5 = new Label ("new label",
                                              TRANS("Output 5 Volume (dB)")));
    labelVol5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelVol5->setJustificationType (Justification::centredLeft);
    labelVol5->setEditable (false, false, false);
    labelVol5->setColour (TextEditor::textColourId, Colours::black);
    labelVol5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (outSlider6 = new Slider ("new slider"));
    outSlider6->setTooltip (TRANS("The gain (or attenuation) that will be applied to the audio mixed to this output or output pair."));
    outSlider6->setRange (-50, 10, 1);
    outSlider6->setSliderStyle (Slider::LinearBar);
    outSlider6->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    outSlider6->addListener (this);

    addAndMakeVisible (labelVol6 = new Label ("new label",
                                              TRANS("Output 6 Volume (dB)")));
    labelVol6->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelVol6->setJustificationType (Justification::centredLeft);
    labelVol6->setEditable (false, false, false);
    labelVol6->setColour (TextEditor::textColourId, Colours::black);
    labelVol6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (outSlider7 = new Slider ("new slider"));
    outSlider7->setTooltip (TRANS("The gain (or attenuation) that will be applied to the audio mixed to this output or output pair."));
    outSlider7->setRange (-50, 10, 1);
    outSlider7->setSliderStyle (Slider::LinearBar);
    outSlider7->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    outSlider7->addListener (this);

    addAndMakeVisible (labelVol7 = new Label ("new label",
                                              TRANS("Output 7 Volume (dB)")));
    labelVol7->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelVol7->setJustificationType (Justification::centredLeft);
    labelVol7->setEditable (false, false, false);
    labelVol7->setColour (TextEditor::textColourId, Colours::black);
    labelVol7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (outSlider8 = new Slider ("new slider"));
    outSlider8->setTooltip (TRANS("The gain (or attenuation) that will be applied to the  audio mixed to this output or output pair."));
    outSlider8->setRange (-50, 10, 1);
    outSlider8->setSliderStyle (Slider::LinearBar);
    outSlider8->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    outSlider8->addListener (this);

    addAndMakeVisible (labelVol8 = new Label ("new label",
                                              TRANS("Output 8 Volume (dB)")));
    labelVol8->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelVol8->setJustificationType (Justification::centredLeft);
    labelVol8->setEditable (false, false, false);
    labelVol8->setColour (TextEditor::textColourId, Colours::black);
    labelVol8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (i12Toggle = new ToggleButton ("new toggle button"));
    i12Toggle->setTooltip (TRANS("Tsunami only.\n"
    "\n"
    "When checked, the audio input pair will be mixed into the output pair 1 and 2."));
    i12Toggle->setButtonText (TRANS("1/2"));
    i12Toggle->addListener (this);

    addAndMakeVisible (i34Toggle = new ToggleButton ("new toggle button"));
    i34Toggle->setTooltip (TRANS("Tsunami only.\n"
    "\n"
    "When checked, the audio input pair will be mixed into the output pair 3 and 4."));
    i34Toggle->setButtonText (TRANS("3/4"));
    i34Toggle->addListener (this);

    addAndMakeVisible (i56Toggle = new ToggleButton ("new toggle button"));
    i56Toggle->setTooltip (TRANS("Tsunami only.\n"
    "\n"
    "When checked, the audio input pair will be mixed into the output pair 5 and 6."));
    i56Toggle->setButtonText (TRANS("5/6"));
    i56Toggle->addListener (this);

    addAndMakeVisible (i78Toggle = new ToggleButton ("new toggle button"));
    i78Toggle->setTooltip (TRANS("Tsunami only.\n"
    "\n"
    "When checked, the audio input pair will be mixed into the output pair 7 and 8."));
    i78Toggle->setButtonText (TRANS("7/8"));
    i78Toggle->addListener (this);

    addAndMakeVisible (labelInMix = new Label ("new label",
                                               TRANS("Audio IN mixed to Out")));
    labelInMix->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelInMix->setJustificationType (Justification::centredLeft);
    labelInMix->setEditable (false, false, false);
    labelInMix->setColour (TextEditor::textColourId, Colours::black);
    labelInMix->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (liveToggle = new ToggleButton ("live toggle button"));
    liveToggle->setTooltip (TRANS("If a serial port is available and this box is checked, then all changes made on this tab will also be sent to the WAV Trigger or Tsunami and you will hear the results immediately.\n"
    "\n"
    "This toggle is not available if there is no active serial port open or available."));
    liveToggle->setButtonText (TRANS("Live Control"));
    liveToggle->addListener (this);

    addAndMakeVisible (ampToggle = new ToggleButton ("amp toggle button"));
    ampToggle->setTooltip (TRANS("WAV Trigger only!\n"
    "\n"
    "Use this toggle to enable power to the WAV Trigger\'s on-board mono audio amplifier.\n"
    "\n"
    "When using the WAV Trigger\'s audio amp, limit your power supply input voltage to 9V or less to avoid overheating the 5V regulator, or bypass the regulator by closing the solder jumper and providing 5V to the serial connector ."));
    ampToggle->setButtonText (TRANS("Amp Power"));
    ampToggle->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

	reset();

	m_Output = nullptr;
	m_Com = nullptr;
	m_mode = MODE_TSUNAMI_STEREO;
	setMode(m_mode);
	liveEnabled = false;
	liveToggle->setEnabled(false);

    //[/Constructor]
}

AudioSettings::~AudioSettings()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    outSlider1 = nullptr;
    labelVol1 = nullptr;
    outSlider2 = nullptr;
    labelVol2 = nullptr;
    outSlider3 = nullptr;
    labelVol3 = nullptr;
    outSlider4 = nullptr;
    labelVol4 = nullptr;
    outSlider5 = nullptr;
    labelVol5 = nullptr;
    outSlider6 = nullptr;
    labelVol6 = nullptr;
    outSlider7 = nullptr;
    labelVol7 = nullptr;
    outSlider8 = nullptr;
    labelVol8 = nullptr;
    i12Toggle = nullptr;
    i34Toggle = nullptr;
    i56Toggle = nullptr;
    i78Toggle = nullptr;
    labelInMix = nullptr;
    liveToggle = nullptr;
    ampToggle = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void AudioSettings::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AudioSettings::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    outSlider1->setBounds (173, 39, 176, 24);
    labelVol1->setBounds (169, 15, 150, 24);
    outSlider2->setBounds (173, 91, 176, 24);
    labelVol2->setBounds (169, 67, 150, 24);
    outSlider3->setBounds (173, 144, 176, 24);
    labelVol3->setBounds (167, 120, 150, 24);
    outSlider4->setBounds (173, 196, 176, 24);
    labelVol4->setBounds (168, 172, 150, 24);
    outSlider5->setBounds (417, 38, 176, 24);
    labelVol5->setBounds (413, 14, 150, 24);
    outSlider6->setBounds (417, 90, 176, 24);
    labelVol6->setBounds (413, 66, 150, 24);
    outSlider7->setBounds (417, 143, 176, 24);
    labelVol7->setBounds (411, 119, 150, 24);
    outSlider8->setBounds (417, 195, 176, 24);
    labelVol8->setBounds (412, 171, 150, 24);
    i12Toggle->setBounds (333, 236, 72, 24);
    i34Toggle->setBounds (405, 236, 72, 24);
    i56Toggle->setBounds (476, 236, 71, 24);
    i78Toggle->setBounds (544, 236, 71, 24);
    labelInMix->setBounds (170, 236, 160, 24);
    liveToggle->setBounds (32, 38, 112, 24);
    ampToggle->setBounds (32, 73, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void AudioSettings::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == outSlider1)
    {
        //[UserSliderCode_outSlider1] -- add your slider handling code here..

		m_Output->setAudioVolume(1, (int)outSlider1->getValue());
		if (liveEnabled) {
			m_Com->volume((int)outSlider1->getValue(), 0);
		}

        //[/UserSliderCode_outSlider1]
    }
    else if (sliderThatWasMoved == outSlider2)
    {
        //[UserSliderCode_outSlider2] -- add your slider handling code here..

		m_Output->setAudioVolume(2, (int)outSlider2->getValue());
		if (liveEnabled) {
			m_Com->volume((int)outSlider2->getValue(), 1);
		}

        //[/UserSliderCode_outSlider2]
    }
    else if (sliderThatWasMoved == outSlider3)
    {
        //[UserSliderCode_outSlider3] -- add your slider handling code here..

		m_Output->setAudioVolume(3, (int)outSlider3->getValue());
		if (liveEnabled) {
			m_Com->volume((int)outSlider3->getValue(), 2);
		}

        //[/UserSliderCode_outSlider3]
    }
    else if (sliderThatWasMoved == outSlider4)
    {
        //[UserSliderCode_outSlider4] -- add your slider handling code here..

		m_Output->setAudioVolume(4, (int)outSlider4->getValue());
		if (liveEnabled) {
			m_Com->volume((int)outSlider4->getValue(), 3);
		}

        //[/UserSliderCode_outSlider4]
    }
    else if (sliderThatWasMoved == outSlider5)
    {
        //[UserSliderCode_outSlider5] -- add your slider handling code here..

		m_Output->setAudioVolume(5, (int)outSlider5->getValue());
		if (liveEnabled) {
			m_Com->volume((int)outSlider5->getValue(), 4);
		}

        //[/UserSliderCode_outSlider5]
    }
    else if (sliderThatWasMoved == outSlider6)
    {
        //[UserSliderCode_outSlider6] -- add your slider handling code here..

		m_Output->setAudioVolume(6, (int)outSlider6->getValue());
		if (liveEnabled) {
			m_Com->volume((int)outSlider6->getValue(), 5);
		}

        //[/UserSliderCode_outSlider6]
    }
    else if (sliderThatWasMoved == outSlider7)
    {
        //[UserSliderCode_outSlider7] -- add your slider handling code here..

		m_Output->setAudioVolume(7, (int)outSlider7->getValue());
		if (liveEnabled) {
			m_Com->volume((int)outSlider7->getValue(), 6);
		}

        //[/UserSliderCode_outSlider7]
    }
    else if (sliderThatWasMoved == outSlider8)
    {
        //[UserSliderCode_outSlider8] -- add your slider handling code here..

		m_Output->setAudioVolume(8, (int)outSlider8->getValue());
		if (liveEnabled) {
			m_Com->volume((int)outSlider8->getValue(), 7);
		}

        //[/UserSliderCode_outSlider8]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void AudioSettings::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == i12Toggle)
    {
        //[UserButtonCode_i12Toggle] -- add your button handler code here..

		int m = 0;
		if (i12Toggle->getToggleState())
			m |= 0x01;
		if (i34Toggle->getToggleState())
			m |= 0x02;
		if (i56Toggle->getToggleState())
			m |= 0x04;
		if (i78Toggle->getToggleState())
			m |= 0x08;
		m_Output->setAudioInputMix(m);
		if (liveEnabled)
			m_Com->setInputMix(m);

        //[/UserButtonCode_i12Toggle]
    }
    else if (buttonThatWasClicked == i34Toggle)
    {
        //[UserButtonCode_i34Toggle] -- add your button handler code here..

		int m = 0;
		if (i12Toggle->getToggleState())
			m |= 0x01;
		if (i34Toggle->getToggleState())
			m |= 0x02;
		if (i56Toggle->getToggleState())
			m |= 0x04;
		if (i78Toggle->getToggleState())
			m |= 0x08;
		m_Output->setAudioInputMix(m);
		if (liveEnabled)
			m_Com->setInputMix(m);

        //[/UserButtonCode_i34Toggle]
    }
    else if (buttonThatWasClicked == i56Toggle)
    {
        //[UserButtonCode_i56Toggle] -- add your button handler code here..

		int m = 0;
		if (i12Toggle->getToggleState())
			m |= 0x01;
		if (i34Toggle->getToggleState())
			m |= 0x02;
		if (i56Toggle->getToggleState())
			m |= 0x04;
		if (i78Toggle->getToggleState())
			m |= 0x08;
		m_Output->setAudioInputMix(m);
		if (liveEnabled)
			m_Com->setInputMix(m);

        //[/UserButtonCode_i56Toggle]
    }
    else if (buttonThatWasClicked == i78Toggle)
    {
        //[UserButtonCode_i78Toggle] -- add your button handler code here..

		int m = 0;
		if (i12Toggle->getToggleState())
			m |= 0x01;
		if (i34Toggle->getToggleState())
			m |= 0x02;
		if (i56Toggle->getToggleState())
			m |= 0x04;
		if (i78Toggle->getToggleState())
			m |= 0x08;
		m_Output->setAudioInputMix(m);
		if (liveEnabled)
			m_Com->setInputMix(m);

        //[/UserButtonCode_i78Toggle]
    }
    else if (buttonThatWasClicked == liveToggle)
    {
        //[UserButtonCode_liveToggle] -- add your button handler code here..

		if (liveToggle->getToggleState())
			liveEnabled = true;
		else
			liveEnabled = false;

        //[/UserButtonCode_liveToggle]
    }
    else if (buttonThatWasClicked == ampToggle)
    {
        //[UserButtonCode_ampToggle] -- add your button handler code here..

		if (ampToggle->getToggleState()) {
			m_Output->setAmpEnable(true);
			if (liveEnabled)
				m_Com->setAmpEnable(true);
		}
		else {
			m_Output->setAmpEnable(false);
			if (liveEnabled)
				m_Com->setAmpEnable(false);
		}
        //[/UserButtonCode_ampToggle]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

// **************************************************************************
// setOutputComponent
// **************************************************************************
void AudioSettings::setOutputComponent(OutputComponent * out) {

	m_Output = (OutputComponent *)out;
	if (m_Output != nullptr)
		m_Output->setAudioSettings(this);
}

// **************************************************************************
// setCommunicator
// **************************************************************************
void AudioSettings::setCommunicator(Communicator * com) {

	m_Com = (Communicator *)com;
}

// **************************************************************************
// enableLive
// **************************************************************************
void AudioSettings::enableLive(bool en) {

	if (en)
		liveToggle->setEnabled(true);
	else
		liveToggle->setEnabled(false);
}

// **************************************************************************
// reset
// **************************************************************************
void AudioSettings::reset(void) {

	outSlider1->setValue(0.0, dontSendNotification);
	outSlider2->setValue(0.0, dontSendNotification);
	outSlider3->setValue(0.0, dontSendNotification);
	outSlider4->setValue(0.0, dontSendNotification);
	outSlider5->setValue(0.0, dontSendNotification);
	outSlider6->setValue(0.0, dontSendNotification);
	outSlider7->setValue(0.0, dontSendNotification);
	outSlider8->setValue(0.0, dontSendNotification);

	i12Toggle->setToggleState(false, dontSendNotification);
	i34Toggle->setToggleState(false, dontSendNotification);
	i56Toggle->setToggleState(false, dontSendNotification);
	i78Toggle->setToggleState(false, dontSendNotification);

	liveToggle->setToggleState(false, dontSendNotification);
	liveEnabled = false;
}

// **************************************************************************
// setMode
// **************************************************************************
void AudioSettings::setMode(int mode) {

	m_mode = mode;
	switch (m_mode) {

	case MODE_WAV_TRIGGER:
		outSlider1->setEnabled(true);
		outSlider2->setEnabled(false);
		outSlider3->setEnabled(false);
		outSlider4->setEnabled(false);
		outSlider5->setEnabled(false);
		outSlider6->setEnabled(false);
		outSlider7->setEnabled(false);
		outSlider8->setEnabled(false);
		labelVol1->setEnabled(true);
		labelVol2->setEnabled(false);
		labelVol3->setEnabled(false);
		labelVol4->setEnabled(false);
		labelVol5->setEnabled(false);
		labelVol6->setEnabled(false);
		labelVol7->setEnabled(false);
		labelVol8->setEnabled(false);
		i12Toggle->setEnabled(false);
		i34Toggle->setEnabled(false);
		i56Toggle->setEnabled(false);
		i78Toggle->setEnabled(false);
		labelInMix->setEnabled(false);
		ampToggle->setEnabled(true);
		break;

	case MODE_TSUNAMI_STEREO:
		outSlider1->setEnabled(true);
		outSlider2->setEnabled(true);
		outSlider3->setEnabled(true);
		outSlider4->setEnabled(true);
		outSlider5->setEnabled(false);
		outSlider6->setEnabled(false);
		outSlider7->setEnabled(false);
		outSlider8->setEnabled(false);
		labelVol1->setEnabled(true);
		labelVol2->setEnabled(true);
		labelVol3->setEnabled(true);
		labelVol4->setEnabled(true);
		labelVol5->setEnabled(false);
		labelVol6->setEnabled(false);
		labelVol7->setEnabled(false);
		labelVol8->setEnabled(false);
		i12Toggle->setEnabled(true);
		i34Toggle->setEnabled(true);
		i56Toggle->setEnabled(true);
		i78Toggle->setEnabled(true);
		labelInMix->setEnabled(true);
		ampToggle->setEnabled(false);
		break;

	case MODE_TSUNAMI_MONO:
		outSlider1->setEnabled(true);
		outSlider2->setEnabled(true);
		outSlider3->setEnabled(true);
		outSlider4->setEnabled(true);
		outSlider5->setEnabled(true);
		outSlider6->setEnabled(true);
		outSlider7->setEnabled(true);
		outSlider8->setEnabled(true);
		labelVol1->setEnabled(true);
		labelVol2->setEnabled(true);
		labelVol3->setEnabled(true);
		labelVol4->setEnabled(true);
		labelVol5->setEnabled(true);
		labelVol6->setEnabled(true);
		labelVol7->setEnabled(true);
		labelVol8->setEnabled(true);
		i12Toggle->setEnabled(true);
		i34Toggle->setEnabled(true);
		i56Toggle->setEnabled(true);
		i78Toggle->setEnabled(true);
		labelInMix->setEnabled(true);
		ampToggle->setEnabled(false);
		break;
	}
}

// **************************************************************************
// setVol
// **************************************************************************
bool AudioSettings::setVolume(int o, int v) {

	switch(o) {
		case 0:
			outSlider1->setValue((float)v, dontSendNotification);
			break;
		case 1:
			outSlider2->setValue((float)v, dontSendNotification);
			break;
		case 2:
			outSlider3->setValue((float)v, dontSendNotification);
			break;
		case 3:
			outSlider4->setValue((float)v, dontSendNotification);
			break;
		case 4:
			outSlider5->setValue((float)v, dontSendNotification);
			break;
		case 5:
			outSlider6->setValue((float)v, dontSendNotification);
			break;
		case 6:
			outSlider7->setValue((float)v, dontSendNotification);
			break;
		case 7:
			outSlider8->setValue((float)v, dontSendNotification);
			break;
	}
	return true;
}

// **************************************************************************
// setInputMix
// **************************************************************************
bool AudioSettings::setInputMix(int m) {

	if ((m & 0x01) == 0)
		i12Toggle->setToggleState(false, dontSendNotification);
	else
		i12Toggle->setToggleState(true, dontSendNotification);

	if ((m & 0x02) == 0)
		i34Toggle->setToggleState(false, dontSendNotification);
	else
		i34Toggle->setToggleState(true, dontSendNotification);

	if ((m & 0x04) == 0)
		i56Toggle->setToggleState(false, dontSendNotification);
	else
		i56Toggle->setToggleState(true, dontSendNotification);

	if ((m & 0x08) == 0)
		i78Toggle->setToggleState(false, dontSendNotification);
	else
		i78Toggle->setToggleState(true, dontSendNotification);

	return true;
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AudioSettings" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <SLIDER name="new slider" id="ba1eff1402f9fb48" memberName="outSlider1"
          virtualName="" explicitFocusOrder="0" pos="173 39 176 24" tooltip="The gain (or attenuation) that will be applied to the audio mixed to this output or output pair."
          min="-50" max="10" int="1" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="new label" id="6d1e8c15fbc0aea1" memberName="labelVol1"
         virtualName="" explicitFocusOrder="0" pos="169 15 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Output 1 Volume (dB)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="1ca95dedfc47098b" memberName="outSlider2"
          virtualName="" explicitFocusOrder="0" pos="173 91 176 24" tooltip="The gain (or attenuation) that will be applied to the audio mixed to this output or output pair."
          min="-50" max="10" int="1" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="new label" id="4ba87547add1526" memberName="labelVol2"
         virtualName="" explicitFocusOrder="0" pos="169 67 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Output 2 Volume (dB)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="28f3b9b5b42c829a" memberName="outSlider3"
          virtualName="" explicitFocusOrder="0" pos="173 144 176 24" tooltip="The gain (or attenuation) that will be applied to the audio mixed to this output or output pair."
          min="-50" max="10" int="1" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="new label" id="8eeee4ba16a2479a" memberName="labelVol3"
         virtualName="" explicitFocusOrder="0" pos="167 120 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Output 3 Volume (dB)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="d5f072351efdfd34" memberName="outSlider4"
          virtualName="" explicitFocusOrder="0" pos="173 196 176 24" tooltip="The gain (or attenuation) that will be applied to the audio mixed to this output or output pair."
          min="-50" max="10" int="1" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="new label" id="31f53dcf5fbddf03" memberName="labelVol4"
         virtualName="" explicitFocusOrder="0" pos="168 172 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Output 4 Volume (dB)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="27459b9c6129b6e9" memberName="outSlider5"
          virtualName="" explicitFocusOrder="0" pos="417 38 176 24" tooltip="The gain (or attenuation) that will be applied to the audio mixed to this output or output pair."
          min="-50" max="10" int="1" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="new label" id="1e931505dbda3d25" memberName="labelVol5"
         virtualName="" explicitFocusOrder="0" pos="413 14 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Output 5 Volume (dB)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="849caf59b131ef93" memberName="outSlider6"
          virtualName="" explicitFocusOrder="0" pos="417 90 176 24" tooltip="The gain (or attenuation) that will be applied to the audio mixed to this output or output pair."
          min="-50" max="10" int="1" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="new label" id="1c26b9b22c62a5e9" memberName="labelVol6"
         virtualName="" explicitFocusOrder="0" pos="413 66 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Output 6 Volume (dB)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="89cdd39033ec5620" memberName="outSlider7"
          virtualName="" explicitFocusOrder="0" pos="417 143 176 24" tooltip="The gain (or attenuation) that will be applied to the audio mixed to this output or output pair."
          min="-50" max="10" int="1" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="new label" id="eb67216c5e7d8c24" memberName="labelVol7"
         virtualName="" explicitFocusOrder="0" pos="411 119 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Output 7 Volume (dB)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="8af72a65a6d678b" memberName="outSlider8"
          virtualName="" explicitFocusOrder="0" pos="417 195 176 24" tooltip="The gain (or attenuation) that will be applied to the  audio mixed to this output or output pair."
          min="-50" max="10" int="1" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="new label" id="4a95bee29c999ab" memberName="labelVol8"
         virtualName="" explicitFocusOrder="0" pos="412 171 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Output 8 Volume (dB)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="9423ec6d9c9f3d07" memberName="i12Toggle"
                virtualName="" explicitFocusOrder="0" pos="333 236 72 24" tooltip="Tsunami only.&#10;&#10;When checked, the audio input pair will be mixed into the output pair 1 and 2."
                buttonText="1/2" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="fcf04c0a506cffd5" memberName="i34Toggle"
                virtualName="" explicitFocusOrder="0" pos="405 236 72 24" tooltip="Tsunami only.&#10;&#10;When checked, the audio input pair will be mixed into the output pair 3 and 4."
                buttonText="3/4" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="435b93b1353ac33" memberName="i56Toggle"
                virtualName="" explicitFocusOrder="0" pos="476 236 71 24" tooltip="Tsunami only.&#10;&#10;When checked, the audio input pair will be mixed into the output pair 5 and 6."
                buttonText="5/6" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="665c4a2a24e4cd63" memberName="i78Toggle"
                virtualName="" explicitFocusOrder="0" pos="544 236 71 24" tooltip="Tsunami only.&#10;&#10;When checked, the audio input pair will be mixed into the output pair 7 and 8."
                buttonText="7/8" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <LABEL name="new label" id="c25509a9cbfcf0b0" memberName="labelInMix"
         virtualName="" explicitFocusOrder="0" pos="170 236 160 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Audio IN mixed to Out" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="live toggle button" id="b78cebe038e49ac" memberName="liveToggle"
                virtualName="" explicitFocusOrder="0" pos="32 38 112 24" tooltip="If a serial port is available and this box is checked, then all changes made on this tab will also be sent to the WAV Trigger or Tsunami and you will hear the results immediately.&#10;&#10;This toggle is not available if there is no active serial port open or available."
                buttonText="Live Control" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="amp toggle button" id="d02a1176457fbbe2" memberName="ampToggle"
                virtualName="" explicitFocusOrder="0" pos="32 73 150 24" tooltip="WAV Trigger only!&#10;&#10;Use this toggle to enable power to the WAV Trigger's on-board mono audio amplifier.&#10;&#10;When using the WAV Trigger's audio amp, limit your power supply input voltage to 9V or less to avoid overheating the 5V regulator, or bypass the regulator by closing the solder jumper and providing 5V to the serial connector ."
                buttonText="Amp Power" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
