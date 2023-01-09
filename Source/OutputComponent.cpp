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

//[Headers] You can add your own extra header files here...
#include "TriggerSettings.h"
#include "MidiSettings.h"
#include "AudioSettings.h"
#include "MainComponent.h"
//[/Headers]

#include "OutputComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
OutputComponent::OutputComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    textEditor.reset (new juce::TextEditor ("new text editor"));
    addAndMakeVisible (textEditor.get());
    textEditor->setMultiLine (true);
    textEditor->setReturnKeyStartsNewLine (true);
    textEditor->setReadOnly (false);
    textEditor->setScrollbarsShown (true);
    textEditor->setCaretVisible (true);
    textEditor->setPopupMenuEnabled (true);
    textEditor->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    textEditor->setColour (juce::TextEditor::backgroundColourId, juce::Colours::white);
    textEditor->setText (juce::String());

    OpenButton.reset (new juce::TextButton ("openButton"));
    addAndMakeVisible (OpenButton.get());
    OpenButton->setTooltip (TRANS("Open an existing init file."));
    OpenButton->setButtonText (TRANS("Open"));
    OpenButton->setConnectedEdges (juce::Button::ConnectedOnLeft | juce::Button::ConnectedOnRight | juce::Button::ConnectedOnTop | juce::Button::ConnectedOnBottom);
    OpenButton->addListener (this);

    SaveButton.reset (new juce::TextButton ("saveButton"));
    addAndMakeVisible (SaveButton.get());
    SaveButton->setTooltip (TRANS("Save the current init file."));
    SaveButton->setButtonText (TRANS("Save"));
    SaveButton->setConnectedEdges (juce::Button::ConnectedOnLeft | juce::Button::ConnectedOnRight | juce::Button::ConnectedOnTop | juce::Button::ConnectedOnBottom);
    SaveButton->addListener (this);

    NewButton.reset (new juce::TextButton ("newButton"));
    addAndMakeVisible (NewButton.get());
    NewButton->setTooltip (TRANS("Discard all the current settings and reset to default.\n"
    "\n"
    "This won\'t affect any init file you\'ve saved, but you will lose all of your current settings."));
    NewButton->setButtonText (TRANS("New"));
    NewButton->setConnectedEdges (juce::Button::ConnectedOnLeft | juce::Button::ConnectedOnRight | juce::Button::ConnectedOnTop | juce::Button::ConnectedOnBottom);
    NewButton->addListener (this);

    HelpButton.reset (new juce::TextButton ("helpButton"));
    addAndMakeVisible (HelpButton.get());
    HelpButton->setTooltip (TRANS("Links to the on-line User Guide for the selected product."));
    HelpButton->setButtonText (TRANS("Help"));
    HelpButton->setConnectedEdges (juce::Button::ConnectedOnLeft | juce::Button::ConnectedOnRight | juce::Button::ConnectedOnTop | juce::Button::ConnectedOnBottom);
    HelpButton->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

	textEditor->setFont(Font(Font::getDefaultMonospacedFontName(), 12.0f, Font::plain));
	m_mode = MODE_TSUNAMI_STEREO;
	resetOutput();
    m_trigSettings = nullptr;
	m_midiSettings = nullptr;
	m_audioSettings = nullptr;
	m_globalSettings = nullptr;

    //[/Constructor]
}

OutputComponent::~OutputComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    textEditor = nullptr;
    OpenButton = nullptr;
    SaveButton = nullptr;
    NewButton = nullptr;
    HelpButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..

    m_trigSettings = nullptr;

    //[/Destructor]
}

//==============================================================================
void OutputComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void OutputComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    textEditor->setBounds (0, 0, proportionOfWidth (1.0000f), proportionOfHeight (0.8014f));
    OpenButton->setBounds (0, 0 + proportionOfHeight (0.8014f) - -41 - 24, 80, 24);
    SaveButton->setBounds (96, 0 + proportionOfHeight (0.8014f) - -41 - 24, 80, 24);
    NewButton->setBounds (192, 0 + proportionOfHeight (0.8014f) - -41 - 24, 80, 24);
    HelpButton->setBounds (getWidth() - 80, 0 + proportionOfHeight (0.8014f) - -41 - 24, 80, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void OutputComponent::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == OpenButton.get())
    {
        //[UserButtonCode_OpenButton] -- add your button handler code here..

		FileChooser fc("Choose a file to open...",
			File::getCurrentWorkingDirectory().getChildFile("*.ini"),
			"*.ini",
			true);
		if (fc.browseForFileToOpen()) {
			File file = fc.getResult();

			m_initStrings.clear();
			FileInputStream inStream(file);
			String line;
			do {
				line = inStream.readNextLine();
				if (line.length() > 0) {
					line += newLine;
					m_initStrings.add(line);
				}
			} while (line.length() > 0);
			updateInitWindow();
			m_trigSettings->resetTrigger();
			m_midiSettings->reset();
			m_audioSettings->reset();
			m_globalSettings->setBaud(6);
			m_globalSettings->setQwiic(20);
			refreshSettings();
		}

        //[/UserButtonCode_OpenButton]
    }
    else if (buttonThatWasClicked == SaveButton.get())
    {
        //[UserButtonCode_SaveButton] -- add your button handler code here..

		String s;
		if (m_mode == MODE_WAV_TRIGGER)
			s = "wavtrigr.ini";
		else
			s = "tsunami.ini";
		FileChooser fc("Choose a file to save...",
			File::getCurrentWorkingDirectory().getChildFile(s),
			"*.ini",
			true);
		if (fc.browseForFileToSave(true)) {
			File file = fc.getResult();
			if (file.exists())
				file.deleteFile();
			if (file.create()) {
				FileOutputStream outStream(file);
				outStream.writeText(textEditor->getText(), 0, 0, nullptr);
				outStream.writeText(newLine, 0, 0, nullptr);
			}
		}

        //[/UserButtonCode_SaveButton]
    }
    else if (buttonThatWasClicked == NewButton.get())
    {
        //[UserButtonCode_NewButton] -- add your button handler code here..

		resetOutput();
		m_trigSettings->resetTrigger();
		m_midiSettings->reset();
		m_audioSettings->reset();
		m_globalSettings->setBaud(6);
		m_globalSettings->setQwiic(20);

        //[/UserButtonCode_NewButton]
    }
    else if (buttonThatWasClicked == HelpButton.get())
    {
        //[UserButtonCode_HelpButton] -- add your button handler code here..
        //[/UserButtonCode_HelpButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

// **************************************************************************
// setTriggerSettings
// **************************************************************************
void OutputComponent::setTriggerSettings(TriggerSettings *ts) {

    m_trigSettings = ts;
}

// **************************************************************************
// setMidiSettings
// **************************************************************************
void OutputComponent::setMidiSettings(MidiSettings *ms) {

	m_midiSettings = ms;
}

// **************************************************************************
// setAudioSettings
// **************************************************************************
void OutputComponent::setAudioSettings(AudioSettings *as) {

	m_audioSettings = as;
}

// **************************************************************************
// setAudioSettings
// **************************************************************************
void OutputComponent::setGlobalSettings(MainContentComponent *gs) {

	m_globalSettings = gs;
}

// **************************************************************************
// resetOutput
// **************************************************************************
void OutputComponent::resetOutput(void) {

	switch (m_mode) {
		case MODE_WAV_TRIGGER:
			m_initStrings.clear();
			m_initStrings.add("******************************************************************");
			m_initStrings.add(newLine);
			m_initStrings.add("This file was generated by the Robertsonics Configurator v2.20");
			m_initStrings.add(newLine);
			m_initStrings.add("for use with the WAV Trigger firmware. It is only required if");
			m_initStrings.add(newLine);
			m_initStrings.add("you wish to over-ride default settings. You may add your own");
			m_initStrings.add(newLine);
			m_initStrings.add("comments below this line -->");
			break;
		case MODE_TSUNAMI_MONO:
			m_initStrings.clear();
			m_initStrings.add("#TSUM\n");
			m_initStrings.add("******************************************************************");
			m_initStrings.add(newLine);
			m_initStrings.add("This file was generated by the Robertsonics Configurator v2.20");
			m_initStrings.add(newLine);
			m_initStrings.add("for use with the Tsunami Mono firmware. It is only required if");
			m_initStrings.add(newLine);
			m_initStrings.add("you wish to over-ride default settings. You may add your own");
			m_initStrings.add(newLine);
			m_initStrings.add("comments below this line -->");
			break;
		case MODE_TSUNAMI_STEREO:
			m_initStrings.clear();
			m_initStrings.add("#TSUS\n");
			m_initStrings.add("******************************************************************");
			m_initStrings.add(newLine);
			m_initStrings.add("This file was generated by the Robertsonics Configurator v2.20");
			m_initStrings.add(newLine);
			m_initStrings.add("for use with the Tsunami Stereo firmware. It is only required if");
			m_initStrings.add(newLine);
			m_initStrings.add("you wish to over-ride default settings. You may add your own");
			m_initStrings.add(newLine);
			m_initStrings.add("comments below this line -->");
			break;
	}
	updateInitWindow();
}

// **************************************************************************
// setMode
// **************************************************************************
void OutputComponent::setMode(int m) {

	m_mode = m;
}


// **************************************************************************
// refreshSettings
// **************************************************************************
void OutputComponent::refreshSettings(void) {

	if (m_initStrings[0].startsWith("#TSUS"))
		m_globalSettings->setMode(MODE_TSUNAMI_STEREO);
	else if (m_initStrings[0].startsWith("#TSUM"))
		m_globalSettings->setMode(MODE_TSUNAMI_MONO);
	else
		m_globalSettings->setMode(MODE_WAV_TRIGGER);

	for (int n = 0; n < m_initStrings.size(); n++) {

		if (m_initStrings[n].startsWith("#BAUD")) {
			int b = getFirstValue(n);
			switch (b) {
				case 1200:
					m_globalSettings->setBaud(1);
					break;
				case 2400:
					m_globalSettings->setBaud(2);
					break;
				case 9600:
					m_globalSettings->setBaud(3);
					break;
				case 19200:
					m_globalSettings->setBaud(4);
					break;
				case 38400:
					m_globalSettings->setBaud(5);
					break;
			}
		}

		else if (m_initStrings[n].startsWith("#QWIC")) {
			int a = getFirstValue(n);
			if (a < 128)
				m_globalSettings->setQwiic(a + 1);
		}

		else if (m_initStrings[n].startsWith("#MIDI")) {
			m_midiSettings->setFlags(getFirstValue(n));
			m_midiSettings->enable();
			if (m_mode == MODE_WAV_TRIGGER)
				m_globalSettings->setBaud(7);
		}

		else if (m_initStrings[n].startsWith("#MREL")) {
			m_midiSettings->setRelease(getFirstValue(n));
		}

		else if (m_initStrings[n].startsWith("#MCHN")) {
			m_midiSettings->setChannel(getFirstValue(n));
		}

		else if (m_initStrings[n].startsWith("#BEND")) {
			m_midiSettings->setBend(getFirstValue(n));
		}

		else if (m_initStrings[n].startsWith("#VOL1")) {
			m_audioSettings->setVolume(0, getFirstValue(n));
		}
		else if (m_initStrings[n].startsWith("#VOL2")) {
			m_audioSettings->setVolume(1, getFirstValue(n));
		}
		else if (m_initStrings[n].startsWith("#VOL3")) {
			m_audioSettings->setVolume(2, getFirstValue(n));
		}
		else if (m_initStrings[n].startsWith("#VOL4")) {
			m_audioSettings->setVolume(3, getFirstValue(n));
		}
		else if (m_initStrings[n].startsWith("#VOL5")) {
			m_audioSettings->setVolume(4, getFirstValue(n));
		}
		else if (m_initStrings[n].startsWith("#VOL6")) {
			m_audioSettings->setVolume(5, getFirstValue(n));
		}
		else if (m_initStrings[n].startsWith("#VOL7")) {
			m_audioSettings->setVolume(6, getFirstValue(n));
		}
		else if (m_initStrings[n].startsWith("#VOL8")) {
			m_audioSettings->setVolume(7, getFirstValue(n));
		}

		else if (m_initStrings[n].startsWith("#IMIX")) {
			m_audioSettings->setInputMix(getFirstValue(n));
		}
	}
	m_trigSettings->refreshTrigger();
}

// **************************************************************************
// getFirstValue
// **************************************************************************
int OutputComponent::getFirstValue(int n) {

	String line = m_initStrings[n].substring(5);
	line = line.trimStart();
	return line.getIntValue();
}

// **************************************************************************
// setSerialBaud
// **************************************************************************
bool OutputComponent::setSerialBaud(int baud) {

	if (m_mode == MODE_WAV_TRIGGER) {
		// Look for and delete any existing BAUD, MIDI, MREL or BEND entries
		for (int n = 0; n < m_initStrings.size(); n++) {
			if (m_initStrings[n].startsWith("#BAUD"))
				m_initStrings.remove(n);
		}
		for (int n = 0; n < m_initStrings.size(); n++) {
			if (m_initStrings[n].startsWith("#MIDI"))
				m_initStrings.remove(n);
		}
		for (int n = 0; n < m_initStrings.size(); n++) {
			if (m_initStrings[n].startsWith("#MREL"))
				m_initStrings.remove(n);
		}
		for (int n = 0; n < m_initStrings.size(); n++) {
			if (m_initStrings[n].startsWith("#BEND"))
				m_initStrings.remove(n);
		}
		for (int n = 0; n < m_initStrings.size(); n++) {
			if (m_initStrings[n].startsWith("#MCHN"))
				m_initStrings.remove(n);
		}

		// Add a baud entry if not the default
		if (baud < 6) {
			String bStr = "#BAUD ";
			switch (baud) {
			case 1:
				bStr += "1200";
				break;
			case 2:
				bStr += "2400";
				break;
			case 3:
				bStr += "9600";
				break;
			case 4:
				bStr += "19200";
				break;
			case 5:
				bStr += "38400";
				break;
			}
			bStr += newLine;
			m_initStrings.insert(0, bStr);
		}
		// else if it's midi
		else if (baud == 7) {
			int f = m_midiSettings->getFlags();
			f |= 0x01;
			String bStr = "#MIDI ";
			bStr += f;
			bStr += newLine;
			m_initStrings.insert(0, bStr);
		}
	}
	else {
		// Look for and delete any existing BAUD entries
		for (int n = 0; n < m_initStrings.size(); n++) {
			if (m_initStrings[n].startsWith("#BAUD"))
				m_initStrings.remove(n);
		}

		// Add a baud entry if not the default
		if (baud < 6) {
			String bStr = "#BAUD ";
			switch (baud) {
			case 1:
				bStr += "1200";
				break;
			case 2:
				bStr += "2400";
				break;
			case 3:
				bStr += "9600";
				break;
			case 4:
				bStr += "19200";
				break;
			case 5:
				bStr += "38400";
				break;
			}
			bStr += newLine;
			m_initStrings.insert(1, bStr);
		}
	}
	updateInitWindow();
	return true;
}

// **************************************************************************
// setMidiPitch
// **************************************************************************
bool OutputComponent::setQwiicAddress(int add) {

	for (int n = 0; n < m_initStrings.size(); n++) {
		if (m_initStrings[n].startsWith("#QWIC"))
			m_initStrings.remove(n);
	}
	String bStr;
	if (add != 19) {
		bStr += "#QWIC ";
		bStr += add;
		bStr += newLine;
	}
	if (m_mode == MODE_WAV_TRIGGER)
		m_initStrings.insert(0, bStr);
	else
		m_initStrings.insert(1, bStr);
	updateInitWindow();
	return true;
}

// **************************************************************************
// setMidiPitch
// **************************************************************************
bool OutputComponent::setMidiPitch(int pitch) {

	for (int n = 0; n < m_initStrings.size(); n++) {
		if (m_initStrings[n].startsWith("#BEND"))
			m_initStrings.remove(n);
	}
	String bStr;
	switch (pitch) {
	case 1:
		bStr += "#BEND 1";
		bStr += newLine;
		break;
	case 3:
		bStr += "#BEND 3";
		bStr += newLine;
		break;
	case 4:
		bStr += "#BEND 4";
		bStr += newLine;
		break;
	case 5:
		bStr += "#BEND 5";
		bStr += newLine;
		break;
	}
	if (m_mode == MODE_WAV_TRIGGER)
		m_initStrings.insert(0, bStr);
	else
		m_initStrings.insert(1, bStr);
	updateInitWindow();
	return true;
}

// **************************************************************************
// setMidiChannel
// **************************************************************************
bool OutputComponent::setMidiChannel(int chan) {

	for (int n = 0; n < m_initStrings.size(); n++) {
		if (m_initStrings[n].startsWith("#MCHN"))
			m_initStrings.remove(n);
	}
	if (chan > 1) {
		String cStr;
		cStr += "#MCHN ";
		cStr += (chan - 1);
		cStr += newLine;
		if (m_mode == MODE_WAV_TRIGGER)
			m_initStrings.insert(0, cStr);
		else
			m_initStrings.insert(1, cStr);
	}
	updateInitWindow();
	return true;
}

// **************************************************************************
// setMidiRelease
// **************************************************************************
bool OutputComponent::setMidiRelease(int release) {

	// Look for and delete any existing MREL entry
	for (int n = 0; n < m_initStrings.size(); n++) {
		if (m_initStrings[n].startsWith("#MREL"))
			m_initStrings.remove(n);
	}

	// Add an entry if not the default
	if (release != 0) {
		String bStr = "#MREL ";
		bStr += release;
		bStr += newLine;
		if (m_mode == MODE_WAV_TRIGGER)
			m_initStrings.insert(0, bStr);
		else
			m_initStrings.insert(1, bStr);
	}
	updateInitWindow();
	return true;
}

// **************************************************************************
// setMidiFlags
// **************************************************************************
bool OutputComponent::setMidiFlags(int f) {

	// Look for and delete any existing MREL entry
	for (int n = 0; n < m_initStrings.size(); n++) {
		if (m_initStrings[n].startsWith("#MIDI"))
			m_initStrings.remove(n);
	}

	// Add an entry if not the default
	if (f != 0) {
		String bStr = "#MIDI ";
		bStr += f;
		bStr += newLine;
		if (m_mode == MODE_WAV_TRIGGER)
			m_initStrings.insert(0, bStr);
		else
			m_initStrings.insert(1, bStr);
	}
	updateInitWindow();
	return true;
}

// **************************************************************************
// setAudioVolume
// **************************************************************************
bool OutputComponent::setAudioVolume(int out, int vol) {

	String s = "#VOL";

	// Look for and delete any existing MREL entry
	for (int n = 0; n < m_initStrings.size(); n++) {
		if (m_initStrings[n].startsWith(s))
			m_initStrings.remove(n);
	}

	// Add an entry if not the default
	if (vol != 0) {

		if (m_mode == MODE_WAV_TRIGGER) {
			s += "M ";
			s += vol;
			s += newLine;
			m_initStrings.insert(0, s);
		}
		else {
			s += out;
			s += " ";
			s += vol;
			s += newLine;
			m_initStrings.insert(1, s);
		}
	}
	updateInitWindow();
	return true;
}

// **************************************************************************
// setAudioInputMix
// **************************************************************************
bool OutputComponent::setAudioInputMix(int mix) {

	for (int n = 0; n < m_initStrings.size(); n++) {
		if (m_initStrings[n].startsWith("#IMIX"))
			m_initStrings.remove(n);
	}
	String bStr = "#IMIX ";
	if (mix > 0) {
		bStr += mix;
		bStr += newLine;
		if (m_mode == MODE_WAV_TRIGGER)
			m_initStrings.insert(0, bStr);
		else
			m_initStrings.insert(1, bStr);
	}
	updateInitWindow();
	return true;
}

// **************************************************************************
// setAmpEnable
// **************************************************************************
bool OutputComponent::setAmpEnable(bool ena) {

	for (int n = 0; n < m_initStrings.size(); n++) {
		if (m_initStrings[n].startsWith("#SPKR"))
			m_initStrings.remove(n);
	}
	if (ena) {
		String bStr = "#SPKR 1";
		bStr += newLine;
		m_initStrings.insert(0, bStr);
	}
	updateInitWindow();
	return true;
}

// **************************************************************************
// addTrigger
// **************************************************************************
bool OutputComponent::addTrigger(TRIGGER_STRUCTURE * pTrig) {

int n = 0;
bool found = false;
String trigDesc;

	trigDesc = buildTriggerDesc(pTrig);
	if (trigDesc.length() == 0)
		return false;

	while ((n < m_initStrings.size()) && !found) {
		if (getTriggerNum(m_initStrings[n]) == pTrig->num)
			return false;
		else if (getTriggerNum(m_initStrings[n]) > pTrig->num)
			found = true;
		else if (m_initStrings[n].contains("*"))
			found = true;
		else
			n++;
	}

	if (found)
		m_initStrings.insert(n, trigDesc);
	else
		m_initStrings.add(trigDesc);

	updateInitWindow();
	return true;
}

// **************************************************************************
// getTrigger
// **************************************************************************
bool OutputComponent::getTrigger(int t, TRIGGER_STRUCTURE * pTrig) {

int n;

	n = findTrigger(t);
	if ((n >= 0) && (n < 128)) {
		parseTriggerDesc(m_initStrings[n], pTrig);
		return true;

	}
	return false;
}

// **************************************************************************
// deleteTrigger
// **************************************************************************
void OutputComponent::deleteTrigger(int n) {

	int m = findTrigger(n);
	if ((m >= 0) && (m < 128)) {
		if (m < m_initStrings.size())
			m_initStrings.remove(m);
	}
	updateInitWindow();
}

// **************************************************************************
// buildTriggerDesc(): Create a #TRIG NN line according to the current
//  settings.
//
// Tsunami:
// #TRIG NN, Flags, Gain, Output, Function, Low, High
// Flags:
// TRIG_FLAGS_TYPE			0x03
// TRIG_FLAGS_INTERFACE		0x04
// TRIG_FLAGS_INVERT		0x08
// TRIG_FLAGS_RETRIGGER		0x10
// TRIG_FLAGS_LOOP			0x20
// TRIG_FLAGS_POLY			0x40
// TRIG_FLAGS_LOCK			0x80
//
// WAV Trigger:
// #TRIG NN, Interface, bInvert, Type, Flags, bPoly, Function, Gain, Low, High
// Flags:
// TRIG_FLAGS_RETRIGGER		0x01
// TRIG_FLAGS_LOOP			0x02
// TRIG_FLAGS_LOCK			0x04
//
// **************************************************************************
String OutputComponent::buildTriggerDesc(TRIGGER_STRUCTURE * pTrig)
{

String tStr;
String subStr;
int i, j;

	// Trigger command and trigger number
	tStr = "#TRIG ";
	if (pTrig->num < 10)
		tStr += 0;
	tStr += pTrig->num;
	tStr += ", ";

	// If WAV Trigger
	if (m_mode == MODE_WAV_TRIGGER) {

		// Hardware interface
		if (pTrig->flags & TRIG_FLAGS_INTERFACE)
			tStr += "2, ";
		else
			tStr += "1, ";

		// Invert Flag
		if (pTrig->flags & TRIG_FLAGS_INVERT)
			tStr += "1, ";
		else
			tStr += "0, ";

		// Type
		tStr += (pTrig->flags & TRIG_FLAGS_TYPE) + 1;
		tStr += ", ";

		// Retrigger, Loop & Lock flags
		i = 0;
		if (pTrig->flags & TRIG_FLAGS_RETRIGGER)
			i |= 0x01;
		if (pTrig->flags & TRIG_FLAGS_LOOP)
			i |= 0x02;
		if (pTrig->flags & TRIG_FLAGS_LOCK)
			i |= 0x04;
		tStr += i;
		tStr += ", ";

		// Polyphonic Flag
		if (pTrig->flags & TRIG_FLAGS_POLY)
			tStr += "1, ";
		else
			tStr += "0, ";

		// Function
		tStr += pTrig->function;
		tStr += ", ";

		// Trigger volume
		tStr += pTrig->gain;
		tStr += ", ";
		}

	// Else Tsunami
	else {

		// Flags
		tStr += pTrig->flags;
		tStr += ", ";

		// Trigger volume
		tStr += pTrig->gain;
		tStr += ", ";

		// Output
		tStr += pTrig->output;
		tStr += ", ";

		// Function
		tStr += pTrig->function;
		tStr += ", ";
	}

	if (((pTrig->function > 1) && (pTrig->function < 8)) || pTrig->function == 14) {

		// Low range
		i = pTrig->low;
		if ((i > 0) && (i <= 2048)) {
			tStr += i;
			tStr += ", ";
		}
		else
			tStr = "";

		// High range
		j = pTrig->high;
		if ((j > 0) && (j <= 2048) && (j >= i)) {
			tStr += j;
		}
		else
			tStr = "";
	}
	else {
		tStr += ",";
	}
	tStr += newLine;
	return tStr;
}

// **************************************************************************
// findTrigger(): Look for a trigger entry in the string array
int OutputComponent::findTrigger(int t)
{
	for (int i = 0; i < m_initStrings.size(); i++) {
		if (getTriggerNum(m_initStrings[i]) == t)
			return i;
	}
	return -1;
}

// **************************************************************************
// getTrigger(): Look for a trigger number in this string
int OutputComponent::getTriggerNum(String tStr)
{

int t;
String subStr;

	if (!tStr.startsWith("#TRIG "))
		return -1;
	subStr = tStr.trimCharactersAtStart("#TRIG ");
	subStr = subStr.upToFirstOccurrenceOf(",", false, false);
	t = subStr.getIntValue();
	if ((t >= 1 || t <= 16))
		return t;
	return -1;
}

// **************************************************************************
// parseTriggerDesc()
//
// Tsunami:
// #TRIG NN, Flags, Gain, Output, Function, Low, High
// Flags:
// TRIG_FLAGS_TYPE			0x03
// TRIG_FLAGS_INTERFACE		0x04
// TRIG_FLAGS_INVERT		0x08
// TRIG_FLAGS_RETRIGGER		0x10
// TRIG_FLAGS_LOOP			0x20
// TRIG_FLAGS_POLY			0x40
// TRIG_FLAGS_LOCK			0x80
//
// WAV Trigger:
// #TRIG NN, Interface, bInvert, Type, Flags, bPoly, Function, Gain, Low, High
// Flags:
// TRIG_FLAGS_RETRIGGER		0x01
// TRIG_FLAGS_LOOP			0x02
// TRIG_FLAGS_LOCK			0x04
//
// **************************************************************************
bool OutputComponent::parseTriggerDesc(String tStr, TRIGGER_STRUCTURE * pTrig)
{

	int t, n;
	String subStr;
	StringArray tokens;

	if (!tStr.startsWith("#TRIG "))
		return false;

	// Parse the paramaters into a token string array
	subStr = tStr.trimCharactersAtStart("#TRIG ");
	tokens.addTokens(subStr, false);
	n = tokens.size();
	if (n == 0)
		return false;

	t = tokens[0].getIntValue();
	if ((t < 0) || (t > 16))
		return false;
	pTrig->num = t;

	if (m_mode == MODE_WAV_TRIGGER) {

		// Read the interface and set the flags
		if (n >= 1) {
			t = tokens[1].getIntValue();
			if (t == 1)
				pTrig->flags = 0x00;
			else
				pTrig->flags = 0x04;
		}

		// Read the invert flag and set the flags
		if (n >= 2) {
			t = tokens[2].getIntValue();
			if (t == 1)
				pTrig->flags |= 0x08;
		}

		// Read the type and set the flags
		if (n >= 3) {
			t = (tokens[3].getIntValue() - 1) & 0x03;
			pTrig->flags |= t;
		}

		// Read the flags and set the flags
		if (n >= 4) {
			t = tokens[4].getIntValue();
			if (t & 0x01)
				pTrig->flags |= 0x10;
			if (t & 0x02)
				pTrig->flags |= 0x20;
			if (t & 0x04)
				pTrig->flags |= 0x80;
		}

		// Read the poly flag and set the flags
		if (n >= 5) {
			t = tokens[5].getIntValue();
			if (t == 1)
				pTrig->flags |= 0x40;
		}

		// Read and set the trigger function
		if (n >= 6) {
			pTrig->function = tokens[6].getIntValue();
		}

		// Read and set the trigger volume
		if (n >= 7) {
			pTrig->gain = tokens[7].getIntValue();
		}

		// Read and fill in the track range
		if (n >= 8) {
			pTrig->low = tokens[8].getIntValue();
		}
		if (n >= 9) {
			pTrig->high = tokens[9].getIntValue();
		}

		pTrig->output = 1;
	}

	else {

		// Read and set the trigger flags
		if (n >= 1) {
			pTrig->flags = (juce::uint8)tokens[1].getIntValue();
		}

		// Read and set the trigger volume
		if (n >= 2) {
			pTrig->gain = tokens[2].getIntValue();
		}

		// Read and set the trigger output
		if (n >= 3) {
			pTrig->output = tokens[3].getIntValue();
		}

		// Read and set the trigger function
		if (n >= 4) {
			pTrig->function = tokens[4].getIntValue();
		}

		// Read and fill in the track range
		if (n >= 5) {
			pTrig->low = tokens[5].getIntValue();
		}
		if (n >= 6) {
			pTrig->high = tokens[6].getIntValue();
		}

	}
	return true;
}


// **************************************************************************
// updateInitWindow
// **************************************************************************
void OutputComponent::updateInitWindow(void)
{

int i;
String initStr;

	textEditor->clear();
	for (i = 0; i < m_initStrings.size(); i++) {
		initStr.append(m_initStrings[i], 1024);
	}
	textEditor->setText(initStr);
}

void OutputComponent::displayMsg(String msg) {

	textEditor->setText(msg, dontSendNotification);

}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="OutputComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TEXTEDITOR name="new text editor" id="53becc30770e98fb" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="0 0 100% 80.137%"
              textcol="ff000000" bkgcol="ffffffff" initialText="" multiline="1"
              retKeyStartsLine="1" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTBUTTON name="openButton" id="712853fb9fda4107" memberName="OpenButton"
              virtualName="" explicitFocusOrder="0" pos="0 -41Rr 80 24" posRelativeY="53becc30770e98fb"
              tooltip="Open an existing init file." buttonText="Open" connectedEdges="15"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="saveButton" id="3b6e799f0415c1cb" memberName="SaveButton"
              virtualName="" explicitFocusOrder="0" pos="96 -41Rr 80 24" posRelativeY="53becc30770e98fb"
              tooltip="Save the current init file." buttonText="Save" connectedEdges="15"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="newButton" id="2b29ef66442e0f61" memberName="NewButton"
              virtualName="" explicitFocusOrder="0" pos="192 -41Rr 80 24" posRelativeY="53becc30770e98fb"
              tooltip="Discard all the current settings and reset to default.&#10;&#10;This won't affect any init file you've saved, but you will lose all of your current settings."
              buttonText="New" connectedEdges="15" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="helpButton" id="abc1c2162703bd2b" memberName="HelpButton"
              virtualName="" explicitFocusOrder="0" pos="0Rr -41Rr 80 24" posRelativeY="53becc30770e98fb"
              tooltip="Links to the on-line User Guide for the selected product."
              buttonText="Help" connectedEdges="15" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

