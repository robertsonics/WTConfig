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

#include "TriggerSettings.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...

#pragma warning( push )
#pragma warning( disable : 4800)

//[/MiscUserDefs]

//==============================================================================
TriggerSettings::TriggerSettings ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (triggerBox = new ComboBox ("trigger combo box"));
    triggerBox->setTooltip (TRANS("This is the trigger number you are editing.\n"
    "\n"
    "If you select a trigger that already has an entry in the init file, it will show the current settings.\n"
    "\n"
    "If you select a trigger with no existing entry, the settings will be the default.\n"
    "\n"
    "Triggers that use the default settings don\'t need an entry in the init file.\n"));
    triggerBox->setEditableText (false);
    triggerBox->setJustificationType (Justification::centredLeft);
    triggerBox->setTextWhenNothingSelected (String());
    triggerBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    triggerBox->addListener (this);

    addAndMakeVisible (interfaceBox = new ComboBox ("interface combo box"));
    interfaceBox->setTooltip (TRANS("Contact Closure: Use this when connecting the trigger to buttons and switches.\n"
    "\n"
    "Active: Use this when connecting the trigger to a digital output."));
    interfaceBox->setEditableText (false);
    interfaceBox->setJustificationType (Justification::centredLeft);
    interfaceBox->setTextWhenNothingSelected (String());
    interfaceBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    interfaceBox->addListener (this);

    addAndMakeVisible (typeBox = new ComboBox ("type combo box"));
    typeBox->setTooltip (TRANS("Edge: Trigger activates on a level change. High-to-low if \"Invert\" is not selected, low-to-high if \"Invert\" is checked.\n"
    "\n"
    "Level: Trigger remains active as long as level is maintained. Low if \"Invert\" is not selected, high if \"Invert\" is checked.\n"
    "\n"
    "Latched: Same as Edge, but remains active until something else stops the triggered event.\n"));
    typeBox->setEditableText (false);
    typeBox->setJustificationType (Justification::centredLeft);
    typeBox->setTextWhenNothingSelected (String());
    typeBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    typeBox->addListener (this);

    addAndMakeVisible (functionBox = new ComboBox ("function combo box"));
    functionBox->setTooltip (TRANS("This selects which function the trigger performs. Please see the User Guide for a description of the available functions."));
    functionBox->setEditableText (false);
    functionBox->setJustificationType (Justification::centredLeft);
    functionBox->setTextWhenNothingSelected (String());
    functionBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    functionBox->addListener (this);

    addAndMakeVisible (invertToggle = new ToggleButton ("invert toggle button"));
    invertToggle->setTooltip (TRANS("This inverts the logic level of the trigger input.\n"
    "\n"
    "Normal active level is \"low\", so that connecting a trigger input through a push-button to ground causes the trigger to be active when the button is pushed.\n"
    "\n"
    "Checking this causes the active level to be \"high\"."));
    invertToggle->setButtonText (TRANS("Invert"));
    invertToggle->addListener (this);

    addAndMakeVisible (retriggerToggle = new ToggleButton ("retrigger toggle button"));
    retriggerToggle->setTooltip (TRANS("Checking this allows the trigger to restart an event if the previously triggered event is not finished.\n"
    "\n"
    "For example, unchecking this prevents the trigger from restarting a track if that track is still playing."));
    retriggerToggle->setButtonText (TRANS("Re-Trigger"));
    retriggerToggle->addListener (this);

    addAndMakeVisible (polyToggle = new ToggleButton ("poly toggle button"));
    polyToggle->setTooltip (TRANS("When checked, this causes tracks to be mixed with tracks that are already playing.\n"
    "\n"
    "Unchecking this will cause the trigger to stop all other tracks when starting a new track.\n"));
    polyToggle->setButtonText (TRANS("Polyphonic"));
    polyToggle->addListener (this);

    addAndMakeVisible (loopToggle = new ToggleButton ("loop toggle button"));
    loopToggle->setTooltip (TRANS("When checked, this causes the track to loop continuously until stopped by some other event.\n"
    "\n"
    "Note that Tsunami will loop seamlessly from the last sample in the track to the first, whereas the WAV Trigger will always have a very small gap at the loop point."));
    loopToggle->setButtonText (TRANS("Loop"));
    loopToggle->addListener (this);

    addAndMakeVisible (lockToggle = new ToggleButton ("lock toggle button"));
    lockToggle->setTooltip (TRANS("When checked, the voice used for this trigger will not be \"stolen\" if all voices are being used and a new track needs to be played."));
    lockToggle->setButtonText (TRANS("Lock Voice"));
    lockToggle->addListener (this);

    addAndMakeVisible (trigVolSlider = new Slider ("trigger volume slider"));
    trigVolSlider->setTooltip (TRANS("Tracks started by this trigger will have this gain applied to them. This is in addition to, and prior to, any gain applied to the specified output."));
    trigVolSlider->setRange (-20, 10, 1);
    trigVolSlider->setSliderStyle (Slider::LinearBar);
    trigVolSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    trigVolSlider->addListener (this);

    addAndMakeVisible (outputBox = new ComboBox ("output combo box"));
    outputBox->setTooltip (TRANS("For trigger functions that play audio, this is the output to which the audio will be routed.\n"
    "\n"
    "The WAV Trigger only has one stereo output, so it will always be 1.\n"
    "\n"
    "Tsunami Mono has 8 mono outputs, while Tsunami Stereo has 4 stereo output pairs.\n"));
    outputBox->setEditableText (false);
    outputBox->setJustificationType (Justification::centredLeft);
    outputBox->setTextWhenNothingSelected (String());
    outputBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    outputBox->addListener (this);

    addAndMakeVisible (resetButton = new TextButton ("reset button"));
    resetButton->setTooltip (TRANS("This resets the trigger options to default."));
    resetButton->setButtonText (TRANS("Reset"));
    resetButton->addListener (this);

    addAndMakeVisible (addButton = new TextButton ("add button"));
    addButton->setTooltip (TRANS("This adds the trigger, with the current settings, to the init file below."));
    addButton->setButtonText (TRANS("Add"));
    addButton->addListener (this);

    addAndMakeVisible (lowText = new TextEditor ("low text editor"));
    lowText->setTooltip (TRANS("The lowest track number in the range affected by the trigger."));
    lowText->setMultiLine (false);
    lowText->setReturnKeyStartsNewLine (false);
    lowText->setReadOnly (false);
    lowText->setScrollbarsShown (true);
    lowText->setCaretVisible (true);
    lowText->setPopupMenuEnabled (true);
    lowText->setText (String());

    addAndMakeVisible (highText = new TextEditor ("high text editor"));
    highText->setTooltip (TRANS("The highest track number in the range affected by the trigger."));
    highText->setMultiLine (false);
    highText->setReturnKeyStartsNewLine (false);
    highText->setReadOnly (false);
    highText->setScrollbarsShown (true);
    highText->setCaretVisible (true);
    highText->setPopupMenuEnabled (true);
    highText->setText (String());

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Trigger")));
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Hardware Interface")));
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("Type")));
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label4 = new Label ("new label",
                                           TRANS("Function")));
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (volLabel = new Label ("new label",
                                             TRANS("Trigger Volume (dB)")));
    volLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    volLabel->setJustificationType (Justification::centredLeft);
    volLabel->setEditable (false, false, false);
    volLabel->setColour (TextEditor::textColourId, Colours::black);
    volLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (rangeLabel1 = new Label ("new label",
                                                TRANS("Track Range")));
    rangeLabel1->setTooltip (TRANS("Many trigger functions operate over a range of tracks. When using such a function, these fields allow you to specify the range."));
    rangeLabel1->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    rangeLabel1->setJustificationType (Justification::centredLeft);
    rangeLabel1->setEditable (false, false, false);
    rangeLabel1->setColour (TextEditor::textColourId, Colours::black);
    rangeLabel1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (rangeLabel2 = new Label ("new label",
                                                TRANS("to")));
    rangeLabel2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    rangeLabel2->setJustificationType (Justification::centredLeft);
    rangeLabel2->setEditable (false, false, false);
    rangeLabel2->setColour (TextEditor::textColourId, Colours::black);
    rangeLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (outLabel = new Label ("out label",
                                             TRANS("Stereo Output")));
    outLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outLabel->setJustificationType (Justification::centredLeft);
    outLabel->setEditable (false, false, false);
    outLabel->setColour (TextEditor::textColourId, Colours::black);
    outLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (updateButton = new TextButton ("update button"));
    updateButton->setTooltip (TRANS("If the trigger already has an entry in the init file below, this button updates the entry with the currently displayed options.\n"));
    updateButton->setButtonText (TRANS("Update"));
    updateButton->addListener (this);

    addAndMakeVisible (deleteButton = new TextButton ("delete button"));
    deleteButton->setTooltip (TRANS("This removes the current trigger from the init file below."));
    deleteButton->setButtonText (TRANS("Delete"));
    deleteButton->addListener (this);

    addAndMakeVisible (copyButton = new TextButton ("copy button"));
    copyButton->setTooltip (TRANS("This copies the current trigger settings to the next sequential trigger number and adds a corresponding entry to the init file below.\n"));
    copyButton->setButtonText (TRANS("Copy"));
    copyButton->addListener (this);

    addAndMakeVisible (testButton = new TextButton ("test button"));
    testButton->setTooltip (TRANS("When serial communication is active, this will send the settings for the currently selected trigger to the WAV Tirgger or Tsunami. The settings for this trigger become active immediately.\n"
    "\n"
    "This allows you to try out the effect of different trigger options without have to write and swap a microSD card.\n"
    "\n"
    "This button is not active when there is no serial device selected.\n"));
    testButton->setButtonText (TRANS("Test"));
    testButton->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

	triggerBox->addItem("1", 1);
	triggerBox->addItem("2", 2);
	triggerBox->addItem("3", 3);
	triggerBox->addItem("4", 4);
	triggerBox->addItem("5", 5);
	triggerBox->addItem("6", 6);
	triggerBox->addItem("7", 7);
	triggerBox->addItem("8", 8);
	triggerBox->addItem("9", 9);
	triggerBox->addItem("10", 10);
	triggerBox->addItem("11", 11);
	triggerBox->addItem("12", 12);
	triggerBox->addItem("13", 13);
	triggerBox->addItem("14", 14);
	triggerBox->addItem("15", 15);
	triggerBox->addItem("16", 16);
	triggerBox->setSelectedId(1, dontSendNotification);

	interfaceBox->addItem("Contact Closure", 1);
	interfaceBox->addItem("Active", 2);

	typeBox->addItem("Edge", 1);
	typeBox->addItem("Level", 2);
	typeBox->addItem("Latch", 3);

	functionBox->addItem("Normal", 1);
	functionBox->addItem("Next", 2);
	functionBox->addItem("Previous", 3);
	functionBox->addItem("Random", 4);
	functionBox->addItem("Pause", 5);
	functionBox->addItem("Resume", 6);
	functionBox->addItem("Stop", 7);
	functionBox->addItem("Volume Up", 8);
	functionBox->addItem("Volume Dn", 9);
	functionBox->addItem("MIDI Bank Up", 10);
	functionBox->addItem("MIDI Bank Dn", 11);
	functionBox->addItem("Trig Bank Up", 12);
	functionBox->addItem("Trig Bank Dn", 13);
	functionBox->addItem("Synced Set", 14);

	outputBox->addItem("1", 1);
	outputBox->addItem("2", 2);
	outputBox->addItem("3", 3);
	outputBox->addItem("4", 4);
	outputBox->addItem("5", 5);
	outputBox->addItem("6", 6);
	outputBox->addItem("7", 7);
	outputBox->addItem("8", 8);
	outputBox->addItem("All", 9);
	outputBox->setItemEnabled(9, false);

	lowText->setInputRestrictions(4, "0123456789");
	highText->setInputRestrictions(4, "0123456789");

	addButton->setEnabled(true);
	updateButton->setEnabled(false);
	deleteButton->setEnabled(false);
	copyButton->setEnabled(false);
	testButton->setEnabled(false);

	m_mode = MODE_TSUNAMI_STEREO;
	resetTrigger();
	m_Output = nullptr;
	m_Com = nullptr;
	m_testEnable = false;

    //[/Constructor]
}

TriggerSettings::~TriggerSettings()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    triggerBox = nullptr;
    interfaceBox = nullptr;
    typeBox = nullptr;
    functionBox = nullptr;
    invertToggle = nullptr;
    retriggerToggle = nullptr;
    polyToggle = nullptr;
    loopToggle = nullptr;
    lockToggle = nullptr;
    trigVolSlider = nullptr;
    outputBox = nullptr;
    resetButton = nullptr;
    addButton = nullptr;
    lowText = nullptr;
    highText = nullptr;
    label = nullptr;
    label2 = nullptr;
    label3 = nullptr;
    label4 = nullptr;
    volLabel = nullptr;
    rangeLabel1 = nullptr;
    rangeLabel2 = nullptr;
    outLabel = nullptr;
    updateButton = nullptr;
    deleteButton = nullptr;
    copyButton = nullptr;
    testButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..

    m_Output = nullptr;

    //[/Destructor]
}

//==============================================================================
void TriggerSettings::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TriggerSettings::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    triggerBox->setBounds (40, 40, 72, 24);
    interfaceBox->setBounds (136, 40, 160, 24);
    typeBox->setBounds (320, 40, 96, 24);
    functionBox->setBounds (440, 40, 160, 24);
    invertToggle->setBounds (37, 88, 80, 24);
    retriggerToggle->setBounds (128, 88, 104, 24);
    polyToggle->setBounds (248, 88, 104, 24);
    loopToggle->setBounds (368, 88, 72, 24);
    lockToggle->setBounds (36, 129, 104, 24);
    trigVolSlider->setBounds (176, 172, 150, 24);
    outputBox->setBounds (512, 172, 86, 24);
    resetButton->setBounds (40, 232, 80, 24);
    addButton->setBounds (136, 232, 80, 24);
    lowText->setBounds (464, 112, 48, 24);
    highText->setBounds (552, 112, 48, 24);
    label->setBounds (36, 16, 55, 24);
    label2->setBounds (130, 16, 135, 24);
    label3->setBounds (315, 16, 47, 24);
    label4->setBounds (435, 16, 63, 24);
    volLabel->setBounds (36, 172, 143, 24);
    rangeLabel1->setBounds (460, 88, 95, 24);
    rangeLabel2->setBounds (520, 112, 23, 24);
    outLabel->setBounds (408, 171, 103, 24);
    updateButton->setBounds (232, 232, 80, 24);
    deleteButton->setBounds (328, 232, 80, 24);
    copyButton->setBounds (424, 232, 80, 24);
    testButton->setBounds (520, 232, 80, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TriggerSettings::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == triggerBox)
    {
        //[UserComboBoxCode_triggerBox] -- add your combo box handling code here..

		int t = triggerBox->getSelectedId();

		if (m_Output != nullptr) {

			// If the trigger already has an entry, update all settings
			if (m_Output->getTrigger(t, &m_Trigger)) {
				expandTrigger(&m_Trigger);
				enableDisableUI();
				addButton->setEnabled(false);
				updateButton->setEnabled(true);
				deleteButton->setEnabled(true);
				if (t < 16)
					copyButton->setEnabled(true);
				else
					copyButton->setEnabled(false);
				if (m_testEnable)
					testButton->setEnabled(true);
				else
					testButton->setEnabled(false);
			}
			// Otherwise, reset
			else {
				resetTrigger();
				addButton->setEnabled(true);
				updateButton->setEnabled(false);
				deleteButton->setEnabled(false);
				copyButton->setEnabled(false);
				testButton->setEnabled(false);
			}
		}

        //[/UserComboBoxCode_triggerBox]
    }
    else if (comboBoxThatHasChanged == interfaceBox)
    {
        //[UserComboBoxCode_interfaceBox] -- add your combo box handling code here..

		int i = interfaceBox->getSelectedId();
		switch (i) {
		case 1:	// Contact Closure
			invertToggle->setToggleState(false, dontSendNotification);
			break;
		default: // Active
			invertToggle->setToggleState(true, dontSendNotification);
			break;
		}

        //[/UserComboBoxCode_interfaceBox]
    }
    else if (comboBoxThatHasChanged == typeBox)
    {
        //[UserComboBoxCode_typeBox] -- add your combo box handling code here..

		int t = typeBox->getSelectedId();
		switch (t) {
		case 1: // Edge
			if (functionBox->getSelectedId() < 5)
				retriggerToggle->setToggleState(true, dontSendNotification);
			else
				retriggerToggle->setToggleState(false, dontSendNotification);
			loopToggle->setToggleState(false, dontSendNotification);
			break;
		case 2: // Level
			retriggerToggle->setToggleState(false, dontSendNotification);
			loopToggle->setToggleState(false, dontSendNotification);
			break;
		case 3: // Latched
			retriggerToggle->setToggleState(false, dontSendNotification);
			loopToggle->setToggleState(false, dontSendNotification);
			break;
		default:
			break;
		}
		enableDisableUI();

        //[/UserComboBoxCode_typeBox]
    }
    else if (comboBoxThatHasChanged == functionBox)
    {
        //[UserComboBoxCode_functionBox] -- add your combo box handling code here..

		switch (functionBox->getSelectedId()) {
			case 1: // Normal
				outputBox->setItemEnabled(9, false);
				lowText->setText("", dontSendNotification);
				highText->setText("", dontSendNotification);
				polyToggle->setToggleState(true, dontSendNotification);
				trigVolSlider->setValue(0);
				outputBox->setSelectedId(1);
				lockToggle->setToggleState(false, dontSendNotification);
				loopToggle->setToggleState(false, dontSendNotification);
				switch (typeBox->getSelectedId()) {
					case 1:
					case 3:
						retriggerToggle->setToggleState(true, dontSendNotification);
						break;
					case 2:
						retriggerToggle->setToggleState(false, dontSendNotification);
						break;
				}
				break;
			case 2: // Next
			case 3: // Previous
			case 4: // Random
				outputBox->setItemEnabled(9, false);
				lowText->setText("1", dontSendNotification);
				highText->setText("16", dontSendNotification);
				polyToggle->setToggleState(true, dontSendNotification);
				trigVolSlider->setValue(0);
				outputBox->setSelectedId(1);
				lockToggle->setToggleState(false, dontSendNotification);
				loopToggle->setToggleState(false, dontSendNotification);
				switch (typeBox->getSelectedId()) {
					case 1:
					case 3:
						retriggerToggle->setToggleState(true, dontSendNotification);
						break;
					case 2:
						retriggerToggle->setToggleState(false, dontSendNotification);
						break;
				}
				break;
			case 5:	// Pause
			case 6: // Resume
				outputBox->setItemEnabled(9, false);
				lowText->setText("1", dontSendNotification);
				highText->setText("16", dontSendNotification);
				polyToggle->setToggleState(false, dontSendNotification);
				trigVolSlider->setValue(0);
				outputBox->setSelectedId(1);
				outputBox->setSelectedId(1);
				lockToggle->setToggleState(false, dontSendNotification);
				loopToggle->setToggleState(false, dontSendNotification);
				retriggerToggle->setToggleState(false, dontSendNotification);
				break;
			case 7:	// Stop
				outputBox->setItemEnabled(9, false);
				lowText->setText("1", dontSendNotification);
				highText->setText("16", dontSendNotification);
				polyToggle->setToggleState(false, dontSendNotification);
				trigVolSlider->setValue(0);
				outputBox->setSelectedId(1);
				lockToggle->setToggleState(false, dontSendNotification);
				loopToggle->setToggleState(false, dontSendNotification);
				retriggerToggle->setToggleState(false, dontSendNotification);
				break;
			case 8:	// Volume Up
			case 9: // Volume Down
				if (m_mode != MODE_WAV_TRIGGER)
					outputBox->setItemEnabled(9, true);
				lowText->setText("", dontSendNotification);
				highText->setText("", dontSendNotification);
				polyToggle->setToggleState(false, dontSendNotification);
				trigVolSlider->setValue(0);
				outputBox->setSelectedId(1);
				lockToggle->setToggleState(false, dontSendNotification);
				loopToggle->setToggleState(false, dontSendNotification);
				retriggerToggle->setToggleState(false, dontSendNotification);
				break;
			case 10: // MIDI Bank up
			case 11: // MIDI Bank dn
			case 12: // Trigger Bank up
			case 13: // Trigger Bank dn
				outputBox->setItemEnabled(9, false);
				lowText->setText("", dontSendNotification);
				highText->setText("", dontSendNotification);
				polyToggle->setToggleState(false, dontSendNotification);
				trigVolSlider->setValue(0);
				outputBox->setSelectedId(1);
				lockToggle->setToggleState(false, dontSendNotification);
				loopToggle->setToggleState(false, dontSendNotification);
				retriggerToggle->setToggleState(false, dontSendNotification);
				break;
			case 14: // Synced Set
				outputBox->setItemEnabled(9, false);
				lowText->setText("1", dontSendNotification);
				highText->setText("8", dontSendNotification);
				polyToggle->setToggleState(true, dontSendNotification);
				trigVolSlider->setValue(0);
				outputBox->setSelectedId(1);
				lockToggle->setToggleState(false, dontSendNotification);
				loopToggle->setToggleState(false, dontSendNotification);
				switch (typeBox->getSelectedId()) {
				case 1:
				case 3:
					retriggerToggle->setToggleState(true, dontSendNotification);
					break;
				case 2:
					retriggerToggle->setToggleState(false, dontSendNotification);
					break;
				}
				break;

			default:
				break;
		}
		enableDisableUI();

        //[/UserComboBoxCode_functionBox]
    }
    else if (comboBoxThatHasChanged == outputBox)
    {
        //[UserComboBoxCode_outputBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_outputBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void TriggerSettings::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == invertToggle)
    {
        //[UserButtonCode_invertToggle] -- add your button handler code here..
        //[/UserButtonCode_invertToggle]
    }
    else if (buttonThatWasClicked == retriggerToggle)
    {
        //[UserButtonCode_retriggerToggle] -- add your button handler code here..
        //[/UserButtonCode_retriggerToggle]
    }
    else if (buttonThatWasClicked == polyToggle)
    {
        //[UserButtonCode_polyToggle] -- add your button handler code here..
        //[/UserButtonCode_polyToggle]
    }
    else if (buttonThatWasClicked == loopToggle)
    {
        //[UserButtonCode_loopToggle] -- add your button handler code here..
        //[/UserButtonCode_loopToggle]
    }
    else if (buttonThatWasClicked == lockToggle)
    {
        //[UserButtonCode_lockToggle] -- add your button handler code here..
        //[/UserButtonCode_lockToggle]
    }
    else if (buttonThatWasClicked == resetButton)
    {
        //[UserButtonCode_resetButton] -- add your button handler code here..

		resetTrigger();

        //[/UserButtonCode_resetButton]
    }
    else if (buttonThatWasClicked == addButton)
    {
        //[UserButtonCode_addButton] -- add your button handler code here..

		collapseTrigger(&m_Trigger);
		if (m_Output != nullptr) {
			if (m_Output->addTrigger(&m_Trigger)) {
				addButton->setEnabled(false);
				updateButton->setEnabled(true);
				deleteButton->setEnabled(true);
				copyButton->setEnabled(true);
				if (m_testEnable)
					testButton->setEnabled(true);
			}
		}

        //[/UserButtonCode_addButton]
    }
    else if (buttonThatWasClicked == updateButton)
    {
        //[UserButtonCode_updateButton] -- add your button handler code here..

		collapseTrigger(&m_Trigger);
		if (m_Output != nullptr) {
			m_Output->deleteTrigger(m_Trigger.num);
			m_Output->addTrigger(&m_Trigger);
			addButton->setEnabled(false);
			updateButton->setEnabled(true);
			deleteButton->setEnabled(true);
			copyButton->setEnabled(true);
			if (m_testEnable)
				testButton->setEnabled(true);
		}

        //[/UserButtonCode_updateButton]
    }
    else if (buttonThatWasClicked == deleteButton)
    {
        //[UserButtonCode_deleteButton] -- add your button handler code here..

		collapseTrigger(&m_Trigger);
		if (m_Output != nullptr) {
			m_Output->deleteTrigger(m_Trigger.num);
			resetTrigger();
			addButton->setEnabled(true);
			updateButton->setEnabled(false);
			deleteButton->setEnabled(false);
			copyButton->setEnabled(false);
			testButton->setEnabled(false);
		}

        //[/UserButtonCode_deleteButton]
    }
    else if (buttonThatWasClicked == copyButton)
    {
        //[UserButtonCode_copyButton] -- add your button handler code here..

		int ct = triggerBox->getSelectedId();
		if (ct < 16) {
			ct++;
			triggerBox->setSelectedId(ct, dontSendNotification);
			if (m_Output != nullptr) {
				collapseTrigger(&m_Trigger);
				m_Output->deleteTrigger(ct);
				m_Output->addTrigger(&m_Trigger);
				addButton->setEnabled(false);
				updateButton->setEnabled(true);
				deleteButton->setEnabled(true);
				if (ct < 16)
					copyButton->setEnabled(true);
				else
					copyButton->setEnabled(false);
				if (m_testEnable)
					testButton->setEnabled(true);
			}
		}
		else
			copyButton->setEnabled(false);

        //[/UserButtonCode_copyButton]
    }
    else if (buttonThatWasClicked == testButton)
    {
        //[UserButtonCode_testButton] -- add your button handler code here..

		collapseTrigger(&m_Trigger);
		m_Com->setTrigger(&m_Trigger);

        //[/UserButtonCode_testButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void TriggerSettings::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == trigVolSlider)
    {
        //[UserSliderCode_trigVolSlider] -- add your slider handling code here..
        //[/UserSliderCode_trigVolSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

// **************************************************************************
// setOutputComponent
// **************************************************************************
void TriggerSettings::setOutputComponent(OutputComponent * out) {

	m_Output = (OutputComponent *)out;
	if (m_Output != nullptr)
		m_Output->setTriggerSettings(this);
}

// **************************************************************************
// setCommunicator
// **************************************************************************
void TriggerSettings::setCommunicator(Communicator * com) {

	m_Com = (Communicator *)com;
}


// **************************************************************************
// setMode
// **************************************************************************
void TriggerSettings::setMode(int mode) {

	m_mode = mode;
	switch (m_mode) {

		case MODE_WAV_TRIGGER:
			outLabel->setText("Stereo Output", dontSendNotification);
			outputBox->setItemEnabled(1, true);
			outputBox->setItemEnabled(2, false);
			outputBox->setItemEnabled(3, false);
			outputBox->setItemEnabled(4, false);
			outputBox->setItemEnabled(5, false);
			outputBox->setItemEnabled(6, false);
			outputBox->setItemEnabled(7, false);
			outputBox->setItemEnabled(8, false);
			outputBox->setItemEnabled(9, false);
			functionBox->setItemEnabled(14, false);
			break;

		case MODE_TSUNAMI_STEREO:
			outLabel->setText("Stereo Output", dontSendNotification);
			outputBox->setItemEnabled(1, true);
			outputBox->setItemEnabled(2, true);
			outputBox->setItemEnabled(3, true);
			outputBox->setItemEnabled(4, true);
			outputBox->setItemEnabled(5, false);
			outputBox->setItemEnabled(6, false);
			outputBox->setItemEnabled(7, false);
			outputBox->setItemEnabled(8, false);
			outputBox->setItemEnabled(9, true);
			functionBox->setItemEnabled(14, false);
			break;

		case MODE_TSUNAMI_MONO:
			outLabel->setText("Mono Output", dontSendNotification);
			outputBox->setItemEnabled(1, true);
			outputBox->setItemEnabled(2, true);
			outputBox->setItemEnabled(3, true);
			outputBox->setItemEnabled(4, true);
			outputBox->setItemEnabled(5, true);
			outputBox->setItemEnabled(6, true);
			outputBox->setItemEnabled(7, true);
			outputBox->setItemEnabled(8, true);
			outputBox->setItemEnabled(9, true);
			functionBox->setItemEnabled(14, true);
			break;
	}
	addButton->setEnabled(true);
	updateButton->setEnabled(false);
	deleteButton->setEnabled(false);
	copyButton->setEnabled(false);
}

// **************************************************************************
// resetTrigger
// **************************************************************************
void TriggerSettings::resetTrigger(void) {

	interfaceBox->setSelectedId(1, dontSendNotification);
	functionBox->setSelectedId(1, dontSendNotification);
	typeBox->setSelectedId(1, dontSendNotification);
	outputBox->setSelectedId(1, dontSendNotification);
	invertToggle->setToggleState(false, dontSendNotification);
	retriggerToggle->setToggleState(true, dontSendNotification);
	loopToggle->setToggleState(false, dontSendNotification);
	polyToggle->setToggleState(true, dontSendNotification);
	lockToggle->setToggleState(false, dontSendNotification);
	trigVolSlider->setValue(0.0, dontSendNotification);
	lowText->setText("", dontSendNotification);
	highText->setText("", dontSendNotification);
	enableDisableUI();
}

// **************************************************************************
// resetTrigger
// **************************************************************************
void TriggerSettings::refreshTrigger(void) {

	int t = triggerBox->getSelectedId();

	if (m_Output != nullptr) {

		// If the trigger already has an entry, update all settings
		if (m_Output->getTrigger(t, &m_Trigger)) {
			expandTrigger(&m_Trigger);
			enableDisableUI();
			addButton->setEnabled(false);
			updateButton->setEnabled(true);
			deleteButton->setEnabled(true);
			if (t < 16)
				copyButton->setEnabled(true);
			else
				copyButton->setEnabled(false);
		}
		// Otherwise, reset
		else {
			resetTrigger();
			addButton->setEnabled(true);
			updateButton->setEnabled(false);
			deleteButton->setEnabled(false);
			copyButton->setEnabled(false);
		}
	}
}


// **************************************************************************
// expandTrigger
// **************************************************************************
void TriggerSettings::expandTrigger(TRIGGER_STRUCTURE * pTrig) {

int i;

	//triggerBox->setSelectedId(pTrig->num, dontSendNotification);

	i = (pTrig->flags & TRIG_FLAGS_TYPE) + 1;
	if (i <= typeBox->getNumItems())
		typeBox->setSelectedId(i, dontSendNotification);
	i = (pTrig->flags & TRIG_FLAGS_INTERFACE);
	if (i == 0)
		interfaceBox->setSelectedId(1, dontSendNotification);
	else
		interfaceBox->setSelectedId(2, dontSendNotification);

	invertToggle->setToggleState((pTrig->flags & TRIG_FLAGS_INVERT), dontSendNotification);
	retriggerToggle->setToggleState((pTrig->flags & TRIG_FLAGS_RETRIGGER), dontSendNotification);
	loopToggle->setToggleState((pTrig->flags & TRIG_FLAGS_LOOP), dontSendNotification);
	polyToggle->setToggleState((pTrig->flags & TRIG_FLAGS_POLY), dontSendNotification);
	lockToggle->setToggleState((pTrig->flags & TRIG_FLAGS_LOCK), dontSendNotification);

	if ((pTrig->gain >= -20) && (pTrig->gain <= 10))
		trigVolSlider->setValue(pTrig->gain, dontSendNotification);

	i = pTrig->output + 1;
	if (i <= outputBox->getNumItems())
		outputBox->setSelectedId(i, dontSendNotification);
	i = pTrig->function;
	if ((i > 0) && (i <= functionBox->getNumItems()))
		functionBox->setSelectedId(i, dontSendNotification);

	switch (pTrig->function) {
		case 2:
		case 3:
		case 4:
		case 5:
		case 7:
		case 14:
			lowText->setText(String(pTrig->low), dontSendNotification);
			highText->setText(String(pTrig->high), dontSendNotification);
			break;
		default:
			lowText->setText("", dontSendNotification);
			highText->setText("", dontSendNotification);
			break;
	}
}

// **************************************************************************
// collapseTrigger
// **************************************************************************
void TriggerSettings::collapseTrigger(TRIGGER_STRUCTURE * pTrig) {

	// Get the trigger number
	pTrig->num = triggerBox->getSelectedId();

	// Build the flags byte
	pTrig->flags = (typeBox->getSelectedId() - 1) & TRIG_FLAGS_TYPE;
	if (interfaceBox->getSelectedId() > 1)
		pTrig->flags |= TRIG_FLAGS_INTERFACE;
	if (invertToggle->getToggleState())
		pTrig->flags |= TRIG_FLAGS_INVERT;
	if (retriggerToggle->getToggleState())
		pTrig->flags |= TRIG_FLAGS_RETRIGGER;
	if (loopToggle->getToggleState())
		pTrig->flags |= TRIG_FLAGS_LOOP;
	if (polyToggle->getToggleState())
		pTrig->flags |= TRIG_FLAGS_POLY;
	if (lockToggle->getToggleState())
		pTrig->flags |= TRIG_FLAGS_LOCK;

	pTrig->gain = (int)trigVolSlider->getValue();
	pTrig->output = outputBox->getSelectedId() - 1;
	pTrig->function = functionBox->getSelectedId();

	pTrig->low = 0;
	pTrig->high = 0;
	if (((functionBox->getSelectedId() > 1) && (functionBox->getSelectedId() < 8)) || functionBox->getSelectedId() == 14) {

		String s;
		s = lowText->getText();
		pTrig->low = s.getIntValue();
		s = highText->getText();
		pTrig->high = s.getIntValue();
		if ((pTrig->low <= 0) || (pTrig->low > 4096) || (pTrig->high <= 0) || (pTrig->high > 4096)
			|| (pTrig->low > pTrig->high)) {
			AlertWindow::showMessageBoxAsync(AlertWindow::InfoIcon, "Track Range Error",
				"Track Range values for this Trigger Function type must be set to 1 - 4096, with HIGH >= LOW");
			return;
		}
	}
}

// **************************************************************************
// configTriggerUI
// **************************************************************************
void TriggerSettings::enableDisableUI(void) {

	switch (functionBox->getSelectedId()) {
		case 1: // Normal
			lowText->setEnabled(false);
			highText->setEnabled(false);
			rangeLabel2->setEnabled(false);
			rangeLabel1->setEnabled(false);
			polyToggle->setEnabled(true);
			typeBox->setEnabled(true);
			trigVolSlider->setEnabled(true);
			volLabel->setEnabled(true);
			outputBox->setEnabled(true);
			outLabel->setEnabled(true);
			lockToggle->setEnabled(true);
			switch (typeBox->getSelectedId()) {
				case 1: // Edge
					retriggerToggle->setEnabled(true);
					loopToggle->setEnabled(true);
					break;
				case 2: // Level
					retriggerToggle->setEnabled(false);
					loopToggle->setEnabled(false);
					break;
				case 3: // Latched
					retriggerToggle->setEnabled(true);
					loopToggle->setEnabled(true);
					break;
				default:
					break;
			}
			break;
		case 2: // Next
		case 3: // Previous
		case 4: // Random
		case 14: // Synced Set
			lowText->setEnabled(true);
			highText->setEnabled(true);
			rangeLabel2->setEnabled(true);
			rangeLabel1->setEnabled(true);
			retriggerToggle->setEnabled(true);
			polyToggle->setEnabled(true);
			typeBox->setEnabled(true);
			trigVolSlider->setEnabled(true);
			volLabel->setEnabled(true);
			outputBox->setEnabled(true);
			outLabel->setEnabled(true);
			lockToggle->setEnabled(true);
			switch (typeBox->getSelectedId()) {
			case 1: // Edge
				retriggerToggle->setEnabled(true);
				loopToggle->setEnabled(true);
				break;
			case 2: // Level
				retriggerToggle->setEnabled(false);
				loopToggle->setEnabled(false);
				break;
			case 3: // Latched
				retriggerToggle->setEnabled(true);
				loopToggle->setEnabled(true);
				break;
			default:
				break;
			}
			break;
		case 5:	// Pause
		case 6: // Resume
			lowText->setEnabled(true);
			highText->setEnabled(true);
			rangeLabel2->setEnabled(true);
			rangeLabel1->setEnabled(true);
			retriggerToggle->setEnabled(false);
			polyToggle->setEnabled(false);
			typeBox->setEnabled(true);
			trigVolSlider->setEnabled(false);
			volLabel->setEnabled(false);
			outputBox->setEnabled(false);
			outLabel->setEnabled(false);
			outputBox->setEnabled(false);
			outLabel->setEnabled(false);
			lockToggle->setEnabled(false);
			loopToggle->setEnabled(false);
			break;
		case 7:	// Stop
			lowText->setEnabled(true);
			highText->setEnabled(true);
			rangeLabel2->setEnabled(false);
			rangeLabel1->setEnabled(false);
			retriggerToggle->setEnabled(false);
			polyToggle->setEnabled(false);
			typeBox->setEnabled(true);
			trigVolSlider->setEnabled(false);
			volLabel->setEnabled(false);
			outputBox->setEnabled(false);
			outLabel->setEnabled(false);
			lockToggle->setEnabled(false);
			loopToggle->setEnabled(false);
			break;
		case 8:	// Volume Up
		case 9: // Volume Down
			lowText->setEnabled(false);
			highText->setEnabled(false);
			rangeLabel2->setEnabled(false);
			rangeLabel1->setEnabled(false);
			retriggerToggle->setEnabled(false);
			polyToggle->setEnabled(false);
			typeBox->setEnabled(false);
			trigVolSlider->setEnabled(false);
			volLabel->setEnabled(false);
			outputBox->setEnabled(true);
			outLabel->setEnabled(true);
			lockToggle->setEnabled(false);
			loopToggle->setEnabled(false);
			break;
		case 10: // MIDI Bank up
		case 11: // MIDI Bank dn
		case 12: // Trigger Bank up
		case 13: // Trigger Bank dn
			lowText->setEnabled(false);
			highText->setEnabled(false);
			rangeLabel2->setEnabled(false);
			rangeLabel1->setEnabled(false);
			retriggerToggle->setEnabled(false);
			polyToggle->setEnabled(false);
			typeBox->setEnabled(false);
			trigVolSlider->setEnabled(false);
			volLabel->setEnabled(false);
			outputBox->setEnabled(false);
			outLabel->setEnabled(false);
			lockToggle->setEnabled(false);
			loopToggle->setEnabled(false);
			break;
		default:
			break;
	}
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TriggerSettings" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <COMBOBOX name="trigger combo box" id="7e4241a79e1222cd" memberName="triggerBox"
            virtualName="" explicitFocusOrder="0" pos="40 40 72 24" tooltip="This is the trigger number you are editing.&#10;&#10;If you select a trigger that already has an entry in the init file, it will show the current settings.&#10;&#10;If you select a trigger with no existing entry, the settings will be the default.&#10;&#10;Triggers that use the default settings don't need an entry in the init file.&#10;"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="interface combo box" id="57968956be87b2cc" memberName="interfaceBox"
            virtualName="" explicitFocusOrder="0" pos="136 40 160 24" tooltip="Contact Closure: Use this when connecting the trigger to buttons and switches.&#10;&#10;Active: Use this when connecting the trigger to a digital output."
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="type combo box" id="f71459d4e1d303c1" memberName="typeBox"
            virtualName="" explicitFocusOrder="0" pos="320 40 96 24" tooltip="Edge: Trigger activates on a level change. High-to-low if &quot;Invert&quot; is not selected, low-to-high if &quot;Invert&quot; is checked.&#10;&#10;Level: Trigger remains active as long as level is maintained. Low if &quot;Invert&quot; is not selected, high if &quot;Invert&quot; is checked.&#10;&#10;Latched: Same as Edge, but remains active until something else stops the triggered event.&#10;"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="function combo box" id="9420dab4b4d9c54a" memberName="functionBox"
            virtualName="" explicitFocusOrder="0" pos="440 40 160 24" tooltip="This selects which function the trigger performs. Please see the User Guide for a description of the available functions."
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TOGGLEBUTTON name="invert toggle button" id="589aa53046c6e67e" memberName="invertToggle"
                virtualName="" explicitFocusOrder="0" pos="37 88 80 24" tooltip="This inverts the logic level of the trigger input.&#10;&#10;Normal active level is &quot;low&quot;, so that connecting a trigger input through a push-button to ground causes the trigger to be active when the button is pushed.&#10;&#10;Checking this causes the active level to be &quot;high&quot;."
                buttonText="Invert" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="retrigger toggle button" id="ea428919b8f2cdde" memberName="retriggerToggle"
                virtualName="" explicitFocusOrder="0" pos="128 88 104 24" tooltip="Checking this allows the trigger to restart an event if the previously triggered event is not finished.&#10;&#10;For example, unchecking this prevents the trigger from restarting a track if that track is still playing."
                buttonText="Re-Trigger" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="poly toggle button" id="7948e61cc1ed7314" memberName="polyToggle"
                virtualName="" explicitFocusOrder="0" pos="248 88 104 24" tooltip="When checked, this causes tracks to be mixed with tracks that are already playing.&#10;&#10;Unchecking this will cause the trigger to stop all other tracks when starting a new track.&#10;"
                buttonText="Polyphonic" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="loop toggle button" id="fec919ed42dc8c44" memberName="loopToggle"
                virtualName="" explicitFocusOrder="0" pos="368 88 72 24" tooltip="When checked, this causes the track to loop continuously until stopped by some other event.&#10;&#10;Note that Tsunami will loop seamlessly from the last sample in the track to the first, whereas the WAV Trigger will always have a very small gap at the loop point."
                buttonText="Loop" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="lock toggle button" id="29671449348b9bdd" memberName="lockToggle"
                virtualName="" explicitFocusOrder="0" pos="36 129 104 24" tooltip="When checked, the voice used for this trigger will not be &quot;stolen&quot; if all voices are being used and a new track needs to be played."
                buttonText="Lock Voice" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
  <SLIDER name="trigger volume slider" id="8032589c2a49d56" memberName="trigVolSlider"
          virtualName="" explicitFocusOrder="0" pos="176 172 150 24" tooltip="Tracks started by this trigger will have this gain applied to them. This is in addition to, and prior to, any gain applied to the specified output."
          min="-20" max="10" int="1" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <COMBOBOX name="output combo box" id="54bcceb309d9f156" memberName="outputBox"
            virtualName="" explicitFocusOrder="0" pos="512 172 86 24" tooltip="For trigger functions that play audio, this is the output to which the audio will be routed.&#10;&#10;The WAV Trigger only has one stereo output, so it will always be 1.&#10;&#10;Tsunami Mono has 8 mono outputs, while Tsunami Stereo has 4 stereo output pairs.&#10;"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="reset button" id="5834a73e118659da" memberName="resetButton"
              virtualName="" explicitFocusOrder="0" pos="40 232 80 24" tooltip="This resets the trigger options to default."
              buttonText="Reset" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="add button" id="c60c541c67cc4602" memberName="addButton"
              virtualName="" explicitFocusOrder="0" pos="136 232 80 24" tooltip="This adds the trigger, with the current settings, to the init file below."
              buttonText="Add" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="low text editor" id="b0e426b80f885628" memberName="lowText"
              virtualName="" explicitFocusOrder="0" pos="464 112 48 24" tooltip="The lowest track number in the range affected by the trigger."
              initialText="" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="high text editor" id="c00793887805fce" memberName="highText"
              virtualName="" explicitFocusOrder="0" pos="552 112 48 24" tooltip="The highest track number in the range affected by the trigger."
              initialText="" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
  <LABEL name="new label" id="56dcd8347f4032db" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="36 16 55 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Trigger" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="c820293b78e3f85c" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="130 16 135 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Hardware Interface" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="c076b6b0ab3b71fa" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="315 16 47 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Type" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="68c5b9f533a193a6" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="435 16 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Function" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="15663c134920e4fd" memberName="volLabel"
         virtualName="" explicitFocusOrder="0" pos="36 172 143 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Trigger Volume (dB)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="a7c91b8ca6e74d62" memberName="rangeLabel1"
         virtualName="" explicitFocusOrder="0" pos="460 88 95 24" tooltip="Many trigger functions operate over a range of tracks. When using such a function, these fields allow you to specify the range."
         edTextCol="ff000000" edBkgCol="0" labelText="Track Range" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="fb4a2374b9f9fa31" memberName="rangeLabel2"
         virtualName="" explicitFocusOrder="0" pos="520 112 23 24" edTextCol="ff000000"
         edBkgCol="0" labelText="to" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="out label" id="a93404467a4f24d2" memberName="outLabel"
         virtualName="" explicitFocusOrder="0" pos="408 171 103 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Stereo Output" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="update button" id="428f68e12e66a9d2" memberName="updateButton"
              virtualName="" explicitFocusOrder="0" pos="232 232 80 24" tooltip="If the trigger already has an entry in the init file below, this button updates the entry with the currently displayed options.&#10;"
              buttonText="Update" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="delete button" id="2e77cb0ee7bc8a" memberName="deleteButton"
              virtualName="" explicitFocusOrder="0" pos="328 232 80 24" tooltip="This removes the current trigger from the init file below."
              buttonText="Delete" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="copy button" id="c53740b5632fb6eb" memberName="copyButton"
              virtualName="" explicitFocusOrder="0" pos="424 232 80 24" tooltip="This copies the current trigger settings to the next sequential trigger number and adds a corresponding entry to the init file below.&#10;"
              buttonText="Copy" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="test button" id="58dda2a715e27b0f" memberName="testButton"
              virtualName="" explicitFocusOrder="0" pos="520 232 80 24" tooltip="When serial communication is active, this will send the settings for the currently selected trigger to the WAV Tirgger or Tsunami. The settings for this trigger become active immediately.&#10;&#10;This allows you to try out the effect of different trigger options without have to write and swap a microSD card.&#10;&#10;This button is not active when there is no serial device selected.&#10;"
              buttonText="Test" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...

#pragma warning( pop )

//[/EndFile]
