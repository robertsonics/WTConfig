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
//[/Headers]

#include "MidiSettings.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MidiSettings::MidiSettings ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (labelChan = new Label ("new label",
                                              TRANS("Channel")));
    labelChan->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelChan->setJustificationType (Justification::centredLeft);
    labelChan->setEditable (false, false, false);
    labelChan->setColour (TextEditor::textColourId, Colours::black);
    labelChan->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (channelBox = new ComboBox ("channel combo box"));
    channelBox->setTooltip (TRANS("This specifies the MIDI Channel number that the WAV Trigger or Tsunami will respond to.\n"
    "\n"
    "When set to \"Omni\", all MIDI messages will be honored, regardless of channel number.\n"));
    channelBox->setEditableText (false);
    channelBox->setJustificationType (Justification::centredLeft);
    channelBox->setTextWhenNothingSelected (String());
    channelBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    channelBox->addListener (this);

    addAndMakeVisible (pitchBox = new ComboBox ("pitch combo box"));
    pitchBox->setTooltip (TRANS("The number of semi-tones up and down covered by the MIDI Pitch Bend message."));
    pitchBox->setEditableText (false);
    pitchBox->setJustificationType (Justification::centredLeft);
    pitchBox->setTextWhenNothingSelected (String());
    pitchBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    pitchBox->addListener (this);

    addAndMakeVisible (labelPitch = new Label ("new label",
                                               TRANS("Pitch Bend\n"
                                               "Semitones")));
    labelPitch->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelPitch->setJustificationType (Justification::centredLeft);
    labelPitch->setEditable (false, false, false);
    labelPitch->setColour (TextEditor::textColourId, Colours::black);
    labelPitch->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (releaseSlider = new Slider ("release slider"));
    releaseSlider->setTooltip (TRANS("This is the default release time, in milliseconds, for MIDI Note-Off events."));
    releaseSlider->setRange (0, 127, 1);
    releaseSlider->setSliderStyle (Slider::LinearBar);
    releaseSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    releaseSlider->addListener (this);

    addAndMakeVisible (labelRelease = new Label ("new label",
                                                 TRANS("Release Time")));
    labelRelease->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelRelease->setJustificationType (Justification::centredLeft);
    labelRelease->setEditable (false, false, false);
    labelRelease->setColour (TextEditor::textColourId, Colours::black);
    labelRelease->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (ignoreVelToggle = new ToggleButton ("ignore velocity toggle button"));
    ignoreVelToggle->setTooltip (TRANS("When checked, MIDI Note-On velocity will be ignored and audio will be played as if the volume is 127 (max)."));
    ignoreVelToggle->setButtonText (TRANS("Ignore Velocity"));
    ignoreVelToggle->addListener (this);

    addAndMakeVisible (ignoreOffToggle = new ToggleButton ("ignore off toggle button"));
    ignoreOffToggle->setTooltip (TRANS("When checked, MIDI Note-Off messages will be ignored."));
    ignoreOffToggle->setButtonText (TRANS("Ignore Note-Off Messages"));
    ignoreOffToggle->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

	channelBox->addItem("Omni", 1);
	channelBox->addItem("1", 2);
	channelBox->addItem("2", 3);
	channelBox->addItem("3", 4);
	channelBox->addItem("4", 5);
	channelBox->addItem("5", 6);
	channelBox->addItem("6", 7);
	channelBox->addItem("7", 8);
	channelBox->addItem("8", 9);
	channelBox->addItem("9", 10);
	channelBox->addItem("10", 11);
	channelBox->addItem("11", 12);
	channelBox->addItem("12", 13);
	channelBox->addItem("13", 14);
	channelBox->addItem("14", 15);
	channelBox->addItem("15", 16);
	channelBox->addItem("16", 17);

	pitchBox->addItem("1", 1);
	pitchBox->addItem("2", 2);
	pitchBox->addItem("3", 3);
	pitchBox->addItem("4", 4);
	pitchBox->addItem("5", 5);

	reset();

	m_Output = nullptr;
	m_mode = MODE_TSUNAMI_STEREO;

    //[/Constructor]
}

MidiSettings::~MidiSettings()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    labelChan = nullptr;
    channelBox = nullptr;
    pitchBox = nullptr;
    labelPitch = nullptr;
    releaseSlider = nullptr;
    labelRelease = nullptr;
    ignoreVelToggle = nullptr;
    ignoreOffToggle = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MidiSettings::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MidiSettings::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    labelChan->setBounds (96, 56, 64, 24);
    channelBox->setBounds (160, 56, 112, 24);
    pitchBox->setBounds (440, 56, 70, 24);
    labelPitch->setBounds (352, 52, 79, 32);
    releaseSlider->setBounds (160, 112, 144, 24);
    labelRelease->setBounds (64, 112, 96, 24);
    ignoreVelToggle->setBounds (128, 163, 136, 24);
    ignoreOffToggle->setBounds (328, 163, 200, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MidiSettings::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == channelBox)
    {
        //[UserComboBoxCode_channelBox] -- add your combo box handling code here..

		m_Output->setMidiChannel(channelBox->getSelectedId());

        //[/UserComboBoxCode_channelBox]
    }
    else if (comboBoxThatHasChanged == pitchBox)
    {
        //[UserComboBoxCode_pitchBox] -- add your combo box handling code here..

		m_Output->setMidiPitch(pitchBox->getSelectedId());

        //[/UserComboBoxCode_pitchBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void MidiSettings::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == releaseSlider)
    {
        //[UserSliderCode_releaseSlider] -- add your slider handling code here..

		m_Output->setMidiRelease((int)releaseSlider->getValue());

        //[/UserSliderCode_releaseSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void MidiSettings::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == ignoreVelToggle)
    {
        //[UserButtonCode_ignoreVelToggle] -- add your button handler code here..

		int m = 0;
		if (m_mode == MODE_WAV_TRIGGER)
			m = 1;
		if (ignoreVelToggle->getToggleState())
			m |= 0x02;
		if (ignoreOffToggle->getToggleState())
			m |= 0x04;
		m_Output->setMidiFlags(m);

        //[/UserButtonCode_ignoreVelToggle]
    }
    else if (buttonThatWasClicked == ignoreOffToggle)
    {
        //[UserButtonCode_ignoreOffToggle] -- add your button handler code here..

		int m = 0;
		if (m_mode == MODE_WAV_TRIGGER)
			m = 1;
		if (ignoreVelToggle->getToggleState())
			m |= 0x02;
		if (ignoreOffToggle->getToggleState())
			m |= 0x04;
		m_Output->setMidiFlags(m);

        //[/UserButtonCode_ignoreOffToggle]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

// **************************************************************************
// setOutputComponent
// **************************************************************************
void MidiSettings::setOutputComponent(OutputComponent * out) {

	m_Output = (OutputComponent *)out;
	if (m_Output != nullptr)
		m_Output->setMidiSettings(this);
}

// **************************************************************************
// reset
// **************************************************************************
void MidiSettings::reset(void) {

	channelBox->setSelectedId(1, dontSendNotification);
	releaseSlider->setValue(0.0, dontSendNotification);
	ignoreVelToggle->setToggleState(false, dontSendNotification);
	ignoreOffToggle->setToggleState(false, dontSendNotification);
	pitchBox->setSelectedId(2, dontSendNotification);
}

// **************************************************************************
// setMode
// **************************************************************************
void MidiSettings::setMode(int mode) {

	m_mode = mode;
	switch (m_mode) {
		case MODE_WAV_TRIGGER:
			labelChan->setEnabled(false);
			channelBox->setEnabled(false);
			labelPitch->setEnabled(false);
			pitchBox->setEnabled(false);
			labelRelease->setEnabled(false);
			releaseSlider->setEnabled(false);
			ignoreOffToggle->setEnabled(false);
			ignoreVelToggle->setEnabled(false);
			break;

		case MODE_TSUNAMI_STEREO:
			labelChan->setEnabled(true);
			channelBox->setEnabled(true);
			labelPitch->setEnabled(true);
			pitchBox->setEnabled(true);
			labelRelease->setEnabled(true);
			releaseSlider->setEnabled(true);
			ignoreOffToggle->setEnabled(true);
			ignoreVelToggle->setEnabled(true);
			break;

		case MODE_TSUNAMI_MONO:
			labelChan->setEnabled(true);
			channelBox->setEnabled(true);
			labelPitch->setEnabled(true);
			pitchBox->setEnabled(true);
			labelRelease->setEnabled(true);
			releaseSlider->setEnabled(true);
			ignoreOffToggle->setEnabled(true);
			ignoreVelToggle->setEnabled(true);
			break;
	}
}

// **************************************************************************
// enable
// **************************************************************************
void MidiSettings::enable(void) {

	if (m_mode == MODE_WAV_TRIGGER) {
		labelChan->setEnabled(true);
		channelBox->setEnabled(true);
		labelPitch->setEnabled(true);
		pitchBox->setEnabled(true);
		labelRelease->setEnabled(true);
		releaseSlider->setEnabled(true);
		ignoreOffToggle->setEnabled(true);
		ignoreVelToggle->setEnabled(true);
	}
}

// **************************************************************************
// disable
// **************************************************************************
void MidiSettings::disable(void) {

	if (m_mode == MODE_WAV_TRIGGER) {
		labelChan->setEnabled(false);
		channelBox->setEnabled(false);
		labelPitch->setEnabled(false);
		pitchBox->setEnabled(false);
		labelRelease->setEnabled(false);
		releaseSlider->setEnabled(false);
		ignoreOffToggle->setEnabled(false);
		ignoreVelToggle->setEnabled(false);
	}
}

// **************************************************************************
// setFlags
// **************************************************************************
bool MidiSettings::setFlags(int f) {

	if ((f & 0x02) == 0)
		ignoreVelToggle->setToggleState(false, dontSendNotification);
	else
		ignoreVelToggle->setToggleState(true, dontSendNotification);

	if ((f & 0x04) == 0)
		ignoreOffToggle->setToggleState(false, dontSendNotification);
	else
		ignoreOffToggle->setToggleState(true, dontSendNotification);

	return true;
}

// **************************************************************************
// getFlags
// **************************************************************************
int MidiSettings::getFlags(void) {

	int m = 0;
	if (ignoreVelToggle->getToggleState())
	m |= 0x02;
	if (ignoreOffToggle->getToggleState())
	m |= 0x04;
	return m;
}

// **************************************************************************
// setRelease
// **************************************************************************
bool MidiSettings::setRelease(int r) {

	releaseSlider->setValue((double)r, dontSendNotification);
	return true;
}

// **************************************************************************
// setChannel
// **************************************************************************
bool MidiSettings::setChannel(int c) {

	if (c < 17)
		channelBox->setSelectedId((c + 1), dontSendNotification);
	return true;
}

// **************************************************************************
// setBend
// **************************************************************************
bool MidiSettings::setBend(int b) {

	if (b < 6)
		pitchBox->setSelectedId(b, dontSendNotification);
	return true;
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MidiSettings" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <LABEL name="new label" id="e16014cb46640e06" memberName="labelChan"
         virtualName="" explicitFocusOrder="0" pos="96 56 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Channel" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="channel combo box" id="cf094937ff3dbeeb" memberName="channelBox"
            virtualName="" explicitFocusOrder="0" pos="160 56 112 24" tooltip="This specifies the MIDI Channel number that the WAV Trigger or Tsunami will respond to.&#10;&#10;When set to &quot;Omni&quot;, all MIDI messages will be honored, regardless of channel number.&#10;"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="pitch combo box" id="d0af2fa7a96ffab" memberName="pitchBox"
            virtualName="" explicitFocusOrder="0" pos="440 56 70 24" tooltip="The number of semi-tones up and down covered by the MIDI Pitch Bend message."
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="efbf1716483463b4" memberName="labelPitch"
         virtualName="" explicitFocusOrder="0" pos="352 52 79 32" edTextCol="ff000000"
         edBkgCol="0" labelText="Pitch Bend&#10;Semitones" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <SLIDER name="release slider" id="4b9884c187ca3df6" memberName="releaseSlider"
          virtualName="" explicitFocusOrder="0" pos="160 112 144 24" tooltip="This is the default release time, in milliseconds, for MIDI Note-Off events."
          min="0" max="127" int="1" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="new label" id="a933557e36752428" memberName="labelRelease"
         virtualName="" explicitFocusOrder="0" pos="64 112 96 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Release Time" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="ignore velocity toggle button" id="c585dad81e0ee63a" memberName="ignoreVelToggle"
                virtualName="" explicitFocusOrder="0" pos="128 163 136 24" tooltip="When checked, MIDI Note-On velocity will be ignored and audio will be played as if the volume is 127 (max)."
                buttonText="Ignore Velocity" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="ignore off toggle button" id="fe51d3cd8b45d25" memberName="ignoreOffToggle"
                virtualName="" explicitFocusOrder="0" pos="328 163 200 24" tooltip="When checked, MIDI Note-Off messages will be ignored."
                buttonText="Ignore Note-Off Messages" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
