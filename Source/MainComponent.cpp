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
//[/Headers]

#include "MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainContentComponent::MainContentComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (groupComponent = new GroupComponent ("new group",
                                                            TRANS("Serial Com - Optional")));

    addAndMakeVisible (tabbedComponent = new TabbedComponent (TabbedButtonBar::TabsAtTop));
    tabbedComponent->setTabBarDepth (30);
    tabbedComponent->addTab (TRANS("Trigger Settings"), Colours::lightgrey, new TriggerSettings(), true);
    tabbedComponent->addTab (TRANS("MIDI Settings"), Colours::lightgrey, new MidiSettings(), true);
    tabbedComponent->addTab (TRANS("Audio Settings"), Colours::lightgrey, new AudioSettings(), true);
    tabbedComponent->addTab (TRANS("Remote Control"), Colours::lightgrey, new RemoteControl(), true);
    tabbedComponent->setCurrentTabIndex (0);

    addAndMakeVisible (Output = new OutputComponent());
    Output->setName ("new component");

    addAndMakeVisible (modeBox = new ComboBox ("mode combo box"));
    modeBox->setTooltip (TRANS("Select the target product and firmware version here.\n"
    "\n"
    "This choice will be retained the next time you start the application.\n"));
    modeBox->setEditableText (false);
    modeBox->setJustificationType (Justification::centredLeft);
    modeBox->setTextWhenNothingSelected (String());
    modeBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    modeBox->addListener (this);

    addAndMakeVisible (helpWindow = new HelpComponent());
    helpWindow->setName ("help windoe");

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Product\n")));
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (portBox = new ComboBox ("port combo box"));
    portBox->setTooltip (TRANS("If you have a USB serial adaptor, such as an FTDI Basic, connected to the WAV Trigger or Tsunami, then selecting it here allows you to test trigger options directly, use the controls on the Remote Control tab and send live updates from the Audio Settings tab."));
    portBox->setEditableText (false);
    portBox->setJustificationType (Justification::centredLeft);
    portBox->setTextWhenNothingSelected (String());
    portBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    portBox->addListener (this);

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Port")));
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (baudBox = new ComboBox ("baud combo box"));
    baudBox->setTooltip (TRANS("This is the  baudrate to be used by the serial control port on the WAV Trigger or Tsunami.\n"
    "\n"
    "For the WAV Trigger, selecting MIDI activates the MIDI protocol and forces the baud rate to 31.25k.\n"
    "\n"
    "Tsunami has a dedicated MIDI port, so both the serial control port and MIDI are always active."));
    baudBox->setEditableText (false);
    baudBox->setJustificationType (Justification::centredLeft);
    baudBox->setTextWhenNothingSelected (String());
    baudBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    baudBox->addListener (this);

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("Baudrate")));
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (testBaudBox = new ComboBox ("testBaud combo box"));
    testBaudBox->setTooltip (TRANS("This baudrate must match the baudrate currently in use by the serial control port on the WAV Trigger or Tsunami"));
    testBaudBox->setEditableText (false);
    testBaudBox->setJustificationType (Justification::centredLeft);
    testBaudBox->setTextWhenNothingSelected (String());
    testBaudBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    testBaudBox->addListener (this);

    addAndMakeVisible (label4 = new Label ("new label",
                                           TRANS("Baudrate")));
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label5 = new Label ("new label",
                                           TRANS("v2.00 beta2")));
    label5->setFont (Font (18.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (Label::textColourId, Colour (0xff6e50f3));
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (stopAllButton = new TextButton ("stop all button"));
    stopAllButton->setTooltip (TRANS("When serial communication is active, this sends a \"Stop All\" command to silence all audio"));
    stopAllButton->setButtonText (TRANS("Stop All"));
    stopAllButton->addListener (this);

    addAndMakeVisible (label6 = new Label ("new label",
                                           TRANS("Robertsonics Unified Configurator")));
    label6->setFont (Font (20.00f, Font::plain).withTypefaceStyle ("Bold"));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (Label::textColourId, Colour (0xff6e50f3));
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1000, 650);


    //[Constructor] You can add your own custom stuff here..

	Output->setGlobalSettings((MainContentComponent *)this);

	trigSettings = (TriggerSettings *)tabbedComponent->getTabContentComponent(0);
	trigSettings->setOutputComponent((OutputComponent *)Output);
	trigSettings->setMode(1);
	trigSettings->resetTrigger();

	midiSettings = (MidiSettings *)tabbedComponent->getTabContentComponent(1);
	midiSettings->setOutputComponent((OutputComponent *)Output);
	midiSettings->reset();

	audioSettings = (AudioSettings *)tabbedComponent->getTabContentComponent(2);
	audioSettings->setOutputComponent((OutputComponent *)Output);
	audioSettings->reset();

	remoteControl = (RemoteControl *)tabbedComponent->getTabContentComponent(3);

	modeBox->addItem("WAV Trigger", 1);
	modeBox->addItem("Tsunami Stereo", 2);
	modeBox->addItem("Tsunami Mono", 3);
	modeBox->setSelectedId(2, dontSendNotification);

    helpWindow->setMultiLine (true);
    helpWindow->setColour (TextEditor::textColourId, Colour (0xff13d334));
    //helpWindow->setColour (TextEditor::backgroundColourId, Colours::white);

	baudBox->addItem("1200 bps", 1);
	baudBox->addItem("2400 bps", 2);
	baudBox->addItem("9600 bps", 3);
	baudBox->addItem("19.2 kbps", 4);
	baudBox->addItem("38.4 kbps", 5);
	baudBox->addItem("57.6 kbps", 6);
	baudBox->addItem("MIDI", 7);
	baudBox->setItemEnabled(7, false);
	baudBox->setSelectedId(6);

	testBaudBox->addItem("1200 bps", 1);
	testBaudBox->addItem("2400 bps", 2);
	testBaudBox->addItem("9600 bps", 3);
	testBaudBox->addItem("19.2 kbps", 4);
	testBaudBox->addItem("38.4 kbps", 5);
	testBaudBox->addItem("57.6 kbps", 6);
	testBaudBox->setSelectedId(6);

	pCom = new Communicator();

	//pCom->addChangeListener(this);

	StringPairArray portlist = SerialPort::getSerialPortPaths();
	int j = 0;
	if (portlist.size()) {
		for (int i = 0; i < portlist.size(); i++) {

#ifdef WIN32
			if (portlist.getAllKeys()[i].contains("COM")) {
				j++;
				portBox->addItem(portlist.getAllKeys()[i], j);
			}
#else
			if (portlist.getAllKeys()[i].contains("usbserial")) {
				j++;
				portBox->addItem(portlist.getAllValues()[i], j);
			}
#endif
		}
	}

	if (j > 0) {

		// Use the first port to create a Communicator
		// SerialPort * pSP = new SerialPort(portlist.getAllValues()[0], SerialPortConfig(9600, 8, SerialPortConfig::SERIALPORT_PARITY_NONE, SerialPortConfig::STOPBITS_1, SerialPortConfig::FLOWCONTROL_NONE));
		m_portBoxItem = 1;
		portBox->setSelectedId(m_portBoxItem);
		String pN = portBox->getText();
		if (pCom->openPort(pN)) {
			m_portOpenFlag = true;
			stopAllButton->setEnabled(true);
			trigSettings->setTestEnable(true);
			remoteControl->setCommunicator((Communicator *)pCom);
			remoteControl->enableUI(true);
			trigSettings->setCommunicator((Communicator *)pCom);
			audioSettings->setCommunicator((Communicator *)pCom);
			audioSettings->enableLive(true);
		}
		else {
			m_portOpenFlag = false;
			remoteControl->enableUI(false);
			audioSettings->enableLive(false);
			stopAllButton->setEnabled(false);
		}
	}
	else {
		portBox->addItem("No USB Serial Devices!", 1);
		m_portBoxItem = 1;
		portBox->setSelectedId(m_portBoxItem);
		m_portOpenFlag = false;
		stopAllButton->setEnabled(false);
	}

	XmlDocument initDoc(File::getCurrentWorkingDirectory().getChildFile("wttscfg.ini"));
	ScopedPointer<XmlElement> mainElement(initDoc.getDocumentElement());
	if (mainElement == nullptr)
		m_mode = MODE_TSUNAMI_STEREO;
	else {
		XmlElement * modeElement = mainElement->getChildByName("InitMode");
		if (modeElement != nullptr) {
			m_mode = modeElement->getIntAttribute("mode");
			if (m_mode < 3) {
				modeBox->setSelectedId(m_mode + 1, dontSendNotification);
				Output->setMode(m_mode);
				Output->resetOutput();
				trigSettings->setMode(m_mode);
				trigSettings->resetTrigger();
				midiSettings->setMode(m_mode);
				midiSettings->reset();
				audioSettings->setMode(m_mode);
				audioSettings->reset();
				pCom->setMode(m_mode);
				switch (m_mode) {
				case MODE_WAV_TRIGGER:
					midiSettings->disable();
					baudBox->setItemEnabled(7, true);
					break;
				case MODE_TSUNAMI_STEREO:
					baudBox->setItemEnabled(7, false);
					break;
				case MODE_TSUNAMI_MONO:
					baudBox->setItemEnabled(7, false);
					break;
				}
			}
		}
	}

    //[/Constructor]
}

MainContentComponent::~MainContentComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..

	ScopedPointer<XmlElement> initElement = new XmlElement("InitSettings");
	XmlElement * modeElement = new XmlElement("InitMode");
	modeElement->setAttribute("mode", m_mode);
	initElement->addChildElement(modeElement);
	initElement->writeToFile(File::getCurrentWorkingDirectory().getChildFile("wttscfg.ini"), String());

	if (pCom != nullptr) {
		pCom->closePort();
		//pCom->removeChangeListener(this);
		delete pCom;
	}

    //[/Destructor_pre]

    groupComponent = nullptr;
    tabbedComponent = nullptr;
    Output = nullptr;
    modeBox = nullptr;
    helpWindow = nullptr;
    label = nullptr;
    portBox = nullptr;
    label2 = nullptr;
    baudBox = nullptr;
    label3 = nullptr;
    testBaudBox = nullptr;
    label4 = nullptr;
    label5 = nullptr;
    stopAllButton = nullptr;
    label6 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainContentComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainContentComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    groupComponent->setBounds (25, 176, 284, 159);
    tabbedComponent->setBounds (getWidth() - 25 - 642, 20, 642, 316);
    Output->setBounds (getWidth() - 25 - 642, 20 + 316 - -16, 642, 296);
    modeBox->setBounds (120, 80, 161, 24);
    helpWindow->setBounds (27, 20 + 316 - -16, 280, 278);
    label->setBounds (56, 80, 63, 24);
    portBox->setBounds (88, 211, 192, 24);
    label2->setBounds (43, 211, 40, 24);
    baudBox->setBounds (171, 120, 110, 24);
    label3->setBounds (96, 120, 72, 24);
    testBaudBox->setBounds (170, 251, 110, 24);
    label4->setBounds (96, 251, 72, 24);
    label5->setBounds (22, 36, 106, 24);
    stopAllButton->setBounds (56, 291, 80, 24);
    label6->setBounds (21, 14, 288, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainContentComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == modeBox)
    {
        //[UserComboBoxCode_modeBox] -- add your combo box handling code here..

		bool d = AlertWindow::showOkCancelBox(AlertWindow::InfoIcon, "Warning!",
			"Changing the mode will reset everything to default");

		if (!d) {
			modeBox->setSelectedId(m_mode + 1, dontSendNotification);
		}

		else {
			m_mode = modeBox->getSelectedId() - 1;
			Output->setMode(m_mode);
			Output->resetOutput();
			trigSettings->setMode(m_mode);
			trigSettings->resetTrigger();
			midiSettings->setMode(m_mode);
			midiSettings->reset();
			audioSettings->setMode(m_mode);
			audioSettings->reset();
			pCom->setMode(m_mode);
			switch (m_mode) {
			case MODE_WAV_TRIGGER:
				midiSettings->disable();
				baudBox->setItemEnabled(7, true);
				AlertWindow::showMessageBoxAsync(AlertWindow::InfoIcon, "Mode Changed to WAV Trigger",
					"Make sure you're running the WAV Trigger firmware when using this init file.");
				break;
			case MODE_TSUNAMI_STEREO:
				baudBox->setItemEnabled(7, false);
				AlertWindow::showMessageBoxAsync(AlertWindow::InfoIcon, "Mode Changed to Tsunami Stereo",
					"Make sure you're running the Tsunami stereo firmware version when using this init file.");
				break;
			case MODE_TSUNAMI_MONO:
				baudBox->setItemEnabled(7, false);
				AlertWindow::showMessageBoxAsync(AlertWindow::InfoIcon, "Mode Changed to Tsunami Mono",
					"Make sure you're running the Tsunami mono firmware version when using this init file.");
				break;
			}
		}

        //[/UserComboBoxCode_modeBox]
    }
    else if (comboBoxThatHasChanged == portBox)
    {
        //[UserComboBoxCode_portBox] -- add your combo box handling code here..

		if (portBox->getSelectedId() != m_portBoxItem) {
			m_portBoxItem = portBox->getSelectedId();
			String pN = portBox->getText();
			if (pCom->isPortOpen())
				pCom->closePort();
			if (pCom->openPort(pN)) {
				m_portOpenFlag = true;
				remoteControl->enableUI(true);
				audioSettings->enableLive(true);
				stopAllButton->setEnabled(true);
			}
			else {
				m_portOpenFlag = false;
				remoteControl->enableUI(false);
				audioSettings->enableLive(false);
				stopAllButton->setEnabled(false);
				AlertWindow::showMessageBoxAsync(AlertWindow::InfoIcon, "USB Serial Error",
					"Problem opening this USB serial device.");
			}
		}

        //[/UserComboBoxCode_portBox]
    }
    else if (comboBoxThatHasChanged == baudBox)
    {
        //[UserComboBoxCode_baudBox] -- add your combo box handling code here..

		Output->setSerialBaud(baudBox->getSelectedId());
		if (m_mode == MODE_WAV_TRIGGER) {
			midiSettings->reset();
			if (baudBox->getSelectedId() == 7)
				midiSettings->enable();
			else
				midiSettings->disable();
		}

        //[/UserComboBoxCode_baudBox]
    }
    else if (comboBoxThatHasChanged == testBaudBox)
    {
        //[UserComboBoxCode_testBaudBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_testBaudBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void MainContentComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == stopAllButton)
    {
        //[UserButtonCode_stopAllButton] -- add your button handler code here..

		if (pCom->isPortOpen()) {
			pCom->stopAll();
		}

        //[/UserButtonCode_stopAllButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

// **************************************************************************
// setMode
// **************************************************************************
void MainContentComponent::setMode(int mode) {

	m_mode = mode;
	Output->setMode(m_mode);
	trigSettings->setMode(m_mode);
	trigSettings->resetTrigger();
	midiSettings->setMode(m_mode);
	midiSettings->reset();
	midiSettings->disable();
	audioSettings->setMode(m_mode);
	audioSettings->reset();
	pCom->setMode(m_mode);
	switch (m_mode) {
		case MODE_WAV_TRIGGER:
			modeBox->setSelectedId(1, dontSendNotification);
			baudBox->setItemEnabled(7, true);
			break;
		case MODE_TSUNAMI_STEREO:
			modeBox->setSelectedId(2, dontSendNotification);
			baudBox->setItemEnabled(7, false);
			break;
		case MODE_TSUNAMI_MONO:
			modeBox->setSelectedId(3, dontSendNotification);
			baudBox->setItemEnabled(7, false);
			break;
	}
}

// **************************************************************************
// setBaud
// **************************************************************************
bool MainContentComponent::setBaud(int b) {

	if (b <= baudBox->getNumItems())
		baudBox->setSelectedId(b, dontSendNotification);
	return true;
}

// **************************************************************************
// getBaud
// **************************************************************************
int MainContentComponent::getBaud(void) {

	return baudBox->getSelectedId();
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainContentComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1000" initialHeight="650">
  <BACKGROUND backgroundColour="ff323e44"/>
  <GROUPCOMPONENT name="new group" id="14c4978f91073b28" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="25 176 284 159" title="Serial Com - Optional"/>
  <TABBEDCOMPONENT name="new tabbed component" id="4f34a80be597580a" memberName="tabbedComponent"
                   virtualName="" explicitFocusOrder="0" pos="25Rr 20 642 316" orientation="top"
                   tabBarDepth="30" initialTab="0">
    <TAB name="Trigger Settings" colour="ffd3d3d3" useJucerComp="0" contentClassName="TriggerSettings"
         constructorParams="" jucerComponentFile=""/>
    <TAB name="MIDI Settings" colour="ffd3d3d3" useJucerComp="0" contentClassName="MidiSettings"
         constructorParams="" jucerComponentFile=""/>
    <TAB name="Audio Settings" colour="ffd3d3d3" useJucerComp="0" contentClassName="AudioSettings"
         constructorParams="" jucerComponentFile=""/>
    <TAB name="Remote Control" colour="ffd3d3d3" useJucerComp="0" contentClassName="RemoteControl"
         constructorParams="" jucerComponentFile=""/>
  </TABBEDCOMPONENT>
  <GENERICCOMPONENT name="new component" id="9666a20b76aa0b73" memberName="Output"
                    virtualName="" explicitFocusOrder="0" pos="25Rr -16R 642 296"
                    posRelativeY="4f34a80be597580a" class="OutputComponent" params=""/>
  <COMBOBOX name="mode combo box" id="e3c088efe12a9e2d" memberName="modeBox"
            virtualName="" explicitFocusOrder="0" pos="120 80 161 24" tooltip="Select the target product and firmware version here.&#10;&#10;This choice will be retained the next time you start the application.&#10;"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <GENERICCOMPONENT name="help windoe" id="1c1d2687ee1fe7b9" memberName="helpWindow"
                    virtualName="" explicitFocusOrder="0" pos="27 -16R 280 278" posRelativeY="4f34a80be597580a"
                    class="HelpComponent" params=""/>
  <LABEL name="new label" id="f921c4136acd3fe0" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="56 80 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Product&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="port combo box" id="5a63afb3bdb1eb76" memberName="portBox"
            virtualName="" explicitFocusOrder="0" pos="88 211 192 24" tooltip="If you have a USB serial adaptor, such as an FTDI Basic, connected to the WAV Trigger or Tsunami, then selecting it here allows you to test trigger options directly, use the controls on the Remote Control tab and send live updates from the Audio Settings tab."
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="63ced89023ffec60" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="43 211 40 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Port" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="baud combo box" id="46e2aa4abffad948" memberName="baudBox"
            virtualName="" explicitFocusOrder="0" pos="171 120 110 24" tooltip="This is the  baudrate to be used by the serial control port on the WAV Trigger or Tsunami.&#10;&#10;For the WAV Trigger, selecting MIDI activates the MIDI protocol and forces the baud rate to 31.25k.&#10;&#10;Tsunami has a dedicated MIDI port, so both the serial control port and MIDI are always active."
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="fbd34b4ee434fd5c" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="96 120 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Baudrate" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="testBaud combo box" id="2787c4d6ab343a2a" memberName="testBaudBox"
            virtualName="" explicitFocusOrder="0" pos="170 251 110 24" tooltip="This baudrate must match the baudrate currently in use by the serial control port on the WAV Trigger or Tsunami"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="d65667ae717c6adb" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="96 251 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Baudrate" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="c6eccef35ea83c0b" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="22 36 106 24" textCol="ff6e50f3"
         edTextCol="ff000000" edBkgCol="0" labelText="v2.00 beta2" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="18" kerning="0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="stop all button" id="5834a73e118659da" memberName="stopAllButton"
              virtualName="" explicitFocusOrder="0" pos="56 291 80 24" tooltip="When serial communication is active, this sends a &quot;Stop All&quot; command to silence all audio"
              buttonText="Stop All" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="17f23051607afa85" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="21 14 288 24" textCol="ff6e50f3"
         edTextCol="ff000000" edBkgCol="0" labelText="Robertsonics Unified Configurator"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="20" kerning="0" bold="1" italic="0"
         justification="33" typefaceStyle="Bold"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
