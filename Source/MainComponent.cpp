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
//[/Headers]

#include "MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainContentComponent::MainContentComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    groupComponent.reset (new juce::GroupComponent ("new group",
                                                    TRANS("Remote Control - Optional")));
    addAndMakeVisible (groupComponent.get());

    groupComponent->setBounds (25, 176, 284, 159);

    tabbedComponent.reset (new juce::TabbedComponent (juce::TabbedButtonBar::TabsAtTop));
    addAndMakeVisible (tabbedComponent.get());
    tabbedComponent->setTabBarDepth (30);
    tabbedComponent->addTab (TRANS("Trigger Settings"), juce::Colours::lightgrey, new TriggerSettings(), true);
    tabbedComponent->addTab (TRANS("MIDI Settings"), juce::Colours::lightgrey, new MidiSettings(), true);
    tabbedComponent->addTab (TRANS("Audio Settings"), juce::Colours::lightgrey, new AudioSettings(), true);
    tabbedComponent->addTab (TRANS("Remote Control"), juce::Colours::lightgrey, new RemoteControl(), true);
    tabbedComponent->setCurrentTabIndex (0);

    modeBox.reset (new juce::ComboBox ("mode combo box"));
    addAndMakeVisible (modeBox.get());
    modeBox->setTooltip (TRANS("Select the target product and firmware version here.\n"
    "\n"
    "This choice will be retained the next time you start the application.\n"));
    modeBox->setEditableText (false);
    modeBox->setJustificationType (juce::Justification::centredLeft);
    modeBox->setTextWhenNothingSelected (juce::String());
    modeBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    modeBox->addListener (this);

    modeBox->setBounds (145, 68, 161, 24);

    helpWindow.reset (new HelpComponent());
    addAndMakeVisible (helpWindow.get());
    helpWindow->setName ("help windoe");

    label.reset (new juce::Label ("new label",
                                  TRANS("Product\n")));
    addAndMakeVisible (label.get());
    label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (juce::Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label->setBounds (81, 68, 63, 24);

    portBox.reset (new juce::ComboBox ("port combo box"));
    addAndMakeVisible (portBox.get());
    portBox->setTooltip (TRANS("If you have a USB serial adaptor, such as an FTDI Basic, connected to the WAV Trigger or Tsunami, then selecting it here allows you to test trigger options directly, use the controls on the Remote Control tab and send live updates from the Audio Settings tab."));
    portBox->setEditableText (false);
    portBox->setJustificationType (juce::Justification::centredLeft);
    portBox->setTextWhenNothingSelected (juce::String());
    portBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    portBox->addListener (this);

    portBox->setBounds (88, 217, 192, 24);

    label2.reset (new juce::Label ("new label",
                                   TRANS("Port")));
    addAndMakeVisible (label2.get());
    label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (juce::Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label2->setBounds (43, 217, 40, 24);

    baudBox.reset (new juce::ComboBox ("baud combo box"));
    addAndMakeVisible (baudBox.get());
    baudBox->setTooltip (TRANS("This is the  baudrate to be used by the serial control port on the WAV Trigger or Tsunami.\n"
    "\n"
    "For the WAV Trigger, selecting MIDI activates the MIDI protocol and forces the baud rate to 31.25k.\n"
    "\n"
    "Tsunami has a dedicated MIDI port, so both the serial control port and MIDI are always active."));
    baudBox->setEditableText (false);
    baudBox->setJustificationType (juce::Justification::centredLeft);
    baudBox->setTextWhenNothingSelected (juce::String());
    baudBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    baudBox->addListener (this);

    baudBox->setBounds (196, 103, 110, 24);

    label3.reset (new juce::Label ("new label",
                                   TRANS("Baudrate")));
    addAndMakeVisible (label3.get());
    label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (juce::Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label3->setBounds (121, 103, 72, 24);

    testBaudBox.reset (new juce::ComboBox ("testBaud combo box"));
    addAndMakeVisible (testBaudBox.get());
    testBaudBox->setTooltip (TRANS("This baudrate must match the baudrate currently in use by the serial control port on the WAV Trigger or Tsunami"));
    testBaudBox->setEditableText (false);
    testBaudBox->setJustificationType (juce::Justification::centredLeft);
    testBaudBox->setTextWhenNothingSelected (juce::String());
    testBaudBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    testBaudBox->addListener (this);

    testBaudBox->setBounds (170, 253, 110, 24);

    label4.reset (new juce::Label ("new label",
                                   TRANS("Baudrate")));
    addAndMakeVisible (label4.get());
    label4->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (juce::Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label4->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label4->setBounds (96, 253, 72, 24);

    label5.reset (new juce::Label ("new label",
                                   TRANS("v2.21")));
    addAndMakeVisible (label5.get());
    label5->setFont (juce::Font (16.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (juce::Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (juce::Label::textColourId, juce::Colour (0xff6e50f3));
    label5->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label5->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label5->setBounds (22, 46, 58, 24);

    stopAllButton.reset (new juce::TextButton ("stop all button"));
    addAndMakeVisible (stopAllButton.get());
    stopAllButton->setTooltip (TRANS("When serial communication is active, this sends a \"Stop All\" command to silence all audio"));
    stopAllButton->setButtonText (TRANS("Stop All"));
    stopAllButton->addListener (this);

    stopAllButton->setBounds (55, 294, 80, 24);

    label7.reset (new juce::Label ("new label",
                                   TRANS("Qwiic Address")));
    addAndMakeVisible (label7.get());
    label7->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label7->setJustificationType (juce::Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label7->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label7->setBounds (130, 137, 104, 24);

    qwiicBox.reset (new juce::ComboBox ("baud combo box"));
    addAndMakeVisible (qwiicBox.get());
    qwiicBox->setTooltip (TRANS("This is the address assigned to Tsunami for the Qwiic bus"));
    qwiicBox->setEditableText (false);
    qwiicBox->setJustificationType (juce::Justification::centredLeft);
    qwiicBox->setTextWhenNothingSelected (juce::String());
    qwiicBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    qwiicBox->addListener (this);

    qwiicBox->setBounds (235, 138, 70, 24);

    cachedImage_logo_png_1 = juce::ImageCache::getFromMemory (logo_png, logo_pngSize);

    //[UserPreSize]
    addAndMakeVisible(output = new OutputComponent());
    //[/UserPreSize]

    setSize (1000, 650);


    //[Constructor] You can add your own custom stuff here..

    LookAndFeel::setDefaultLookAndFeel(&myLookAndFeel);

	output->setGlobalSettings((MainContentComponent *)this);

	trigSettings = (TriggerSettings *)tabbedComponent->getTabContentComponent(0);
    trigSettings->setOutputComponent((OutputComponent *)output);
	trigSettings->setMode(1);
	trigSettings->resetTrigger();

    midiSettings = (MidiSettings *)tabbedComponent->getTabContentComponent(1);
	midiSettings->setOutputComponent((OutputComponent*)output);
	midiSettings->reset();

	audioSettings = (AudioSettings *)tabbedComponent->getTabContentComponent(2);
	audioSettings->setOutputComponent((OutputComponent*)output);
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

	for (int a = 0; a < 128; a++) {
		qwiicBox->addItem(String(a), a + 1);
	}
	qwiicBox->setSelectedId(20);

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
	std::unique_ptr<XmlElement> mainElement(initDoc.getDocumentElement());
	if (mainElement == nullptr)
		m_mode = MODE_TSUNAMI_STEREO;
	else {
		XmlElement * modeElement = mainElement->getChildByName("InitMode");
		if (modeElement != nullptr) {
			m_mode = modeElement->getIntAttribute("mode");
			if (m_mode < 3) {
				modeBox->setSelectedId(m_mode + 1, dontSendNotification);
				output->setMode(m_mode);
				output->resetOutput();
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
					qwiicBox->setEnabled(false);
					break;
				case MODE_TSUNAMI_STEREO:
					baudBox->setItemEnabled(7, false);
					qwiicBox->setEnabled(true);
					break;
				case MODE_TSUNAMI_MONO:
					baudBox->setItemEnabled(7, false);
					qwiicBox->setEnabled(true);
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

    //[/Destructor_pre]

    groupComponent = nullptr;
    tabbedComponent = nullptr;
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
    label7 = nullptr;
    qwiicBox = nullptr;


    //[Destructor]. You can add your own custom destruction code here..

    if (pCom != nullptr) {
        pCom->closePort();
        //pCom->removeChangeListener(this);
        delete pCom;
    }
    delete output;

    //[/Destructor]
}

//==============================================================================
void MainContentComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        int x = 21, y = 3, width = 51, height = 53;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImageWithin (cachedImage_logo_png_1,
                           x, y, width, height,
                           juce::RectanglePlacement::centred,
                           false);
    }

    {
        int x = 73, y = 23, width = 135, height = 30;
        juce::String text (TRANS("robertsonics"));
        juce::Colour fillColour = juce::Colour (0xffe2e2e2);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Corbel", 28.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centredLeft, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainContentComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    tabbedComponent->setBounds (getWidth() - 25 - 642, 20, 642, 316);
    helpWindow->setBounds (27, 20 + 316 - -16, 280, 278);
    //[UserResized] Add your own custom resize handling here..
    output->setBounds (getWidth() - 25 - 642, 20 + 316 - -16, 642, 296);
    //[/UserResized]
}

void MainContentComponent::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == modeBox.get())
    {
        //[UserComboBoxCode_modeBox] -- add your combo box handling code here..

		bool d = AlertWindow::showOkCancelBox(AlertWindow::InfoIcon, "Warning!",
			"Changing the mode will reset everything to default");

		if (!d) {
			modeBox->setSelectedId(m_mode + 1, dontSendNotification);
		}

		else {
			m_mode = modeBox->getSelectedId() - 1;
			output->setMode(m_mode);
			output->resetOutput();
			trigSettings->setMode(m_mode);
			trigSettings->resetTrigger();
			midiSettings->setMode(m_mode);
			midiSettings->reset();
			audioSettings->setMode(m_mode);
			audioSettings->reset();
			pCom->setMode(m_mode);
			baudBox->setSelectedId(6);
			qwiicBox->setSelectedId(20);

			switch (m_mode) {
				case MODE_WAV_TRIGGER:
					midiSettings->disable();
					baudBox->setItemEnabled(7, true);
					qwiicBox->setEnabled(false);
					AlertWindow::showMessageBoxAsync(AlertWindow::InfoIcon, "Mode Changed to WAV Trigger",
						"Make sure you're running the WAV Trigger firmware when using this init file.");
					break;
				case MODE_TSUNAMI_STEREO:
					baudBox->setItemEnabled(7, false);
					qwiicBox->setEnabled(true);
					AlertWindow::showMessageBoxAsync(AlertWindow::InfoIcon, "Mode Changed to Tsunami Stereo",
						"Make sure you're running the Tsunami stereo firmware version when using this init file.");
					break;
				case MODE_TSUNAMI_MONO:
					baudBox->setItemEnabled(7, false);
					qwiicBox->setEnabled(true);
					AlertWindow::showMessageBoxAsync(AlertWindow::InfoIcon, "Mode Changed to Tsunami Mono",
						"Make sure you're running the Tsunami mono firmware version when using this init file.");
					break;
			}
		}

        //[/UserComboBoxCode_modeBox]
    }
    else if (comboBoxThatHasChanged == portBox.get())
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
    else if (comboBoxThatHasChanged == baudBox.get())
    {
        //[UserComboBoxCode_baudBox] -- add your combo box handling code here..

		output->setSerialBaud(baudBox->getSelectedId());
		if (m_mode == MODE_WAV_TRIGGER) {
			midiSettings->reset();
			if (baudBox->getSelectedId() == 7)
				midiSettings->enable();
			else
				midiSettings->disable();
		}

        //[/UserComboBoxCode_baudBox]
    }
    else if (comboBoxThatHasChanged == testBaudBox.get())
    {
        //[UserComboBoxCode_testBaudBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_testBaudBox]
    }
    else if (comboBoxThatHasChanged == qwiicBox.get())
    {
        //[UserComboBoxCode_qwiicBox] -- add your combo box handling code here..

		output->setQwiicAddress(qwiicBox->getSelectedId() - 1);

        //[/UserComboBoxCode_qwiicBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void MainContentComponent::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == stopAllButton.get())
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
	output->setMode(m_mode);
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
			qwiicBox->setSelectedId(20, dontSendNotification);
			qwiicBox->setEnabled(false);
			break;
		case MODE_TSUNAMI_STEREO:
			modeBox->setSelectedId(2, dontSendNotification);
			baudBox->setItemEnabled(7, false);
			qwiicBox->setSelectedId(20, dontSendNotification);
			qwiicBox->setEnabled(true);
			break;
		case MODE_TSUNAMI_MONO:
			modeBox->setSelectedId(3, dontSendNotification);
			baudBox->setItemEnabled(7, false);
			qwiicBox->setSelectedId(20, dontSendNotification);
			qwiicBox->setEnabled(true);
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

// **************************************************************************
// setQwiic
// **************************************************************************
bool MainContentComponent::setQwiic(int b) {

	if (b <= qwiicBox->getNumItems())
		qwiicBox->setSelectedId(b, dontSendNotification);
	return true;
}

// **************************************************************************
// getQwiic
// **************************************************************************
int MainContentComponent::getQwiic(void) {

	return qwiicBox->getSelectedId();
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
  <BACKGROUND backgroundColour="ff323e44">
    <IMAGE pos="21 3 51 53" resource="logo_png" opacity="1.0" mode="1"/>
    <TEXT pos="73 23 135 30" fill="solid: ffe2e2e2" hasStroke="0" text="robertsonics"
          fontname="Corbel" fontsize="28.0" kerning="0.0" bold="0" italic="0"
          justification="33"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="new group" id="14c4978f91073b28" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="25 176 284 159" title="Remote Control - Optional"/>
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
  <COMBOBOX name="mode combo box" id="e3c088efe12a9e2d" memberName="modeBox"
            virtualName="" explicitFocusOrder="0" pos="145 68 161 24" tooltip="Select the target product and firmware version here.&#10;&#10;This choice will be retained the next time you start the application.&#10;"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <GENERICCOMPONENT name="help windoe" id="1c1d2687ee1fe7b9" memberName="helpWindow"
                    virtualName="" explicitFocusOrder="0" pos="27 -16R 280 278" posRelativeY="4f34a80be597580a"
                    class="HelpComponent" params=""/>
  <LABEL name="new label" id="f921c4136acd3fe0" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="81 68 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Product&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="port combo box" id="5a63afb3bdb1eb76" memberName="portBox"
            virtualName="" explicitFocusOrder="0" pos="88 217 192 24" tooltip="If you have a USB serial adaptor, such as an FTDI Basic, connected to the WAV Trigger or Tsunami, then selecting it here allows you to test trigger options directly, use the controls on the Remote Control tab and send live updates from the Audio Settings tab."
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="63ced89023ffec60" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="43 217 40 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Port" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="baud combo box" id="46e2aa4abffad948" memberName="baudBox"
            virtualName="" explicitFocusOrder="0" pos="196 103 110 24" tooltip="This is the  baudrate to be used by the serial control port on the WAV Trigger or Tsunami.&#10;&#10;For the WAV Trigger, selecting MIDI activates the MIDI protocol and forces the baud rate to 31.25k.&#10;&#10;Tsunami has a dedicated MIDI port, so both the serial control port and MIDI are always active."
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="fbd34b4ee434fd5c" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="121 103 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Baudrate" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="testBaud combo box" id="2787c4d6ab343a2a" memberName="testBaudBox"
            virtualName="" explicitFocusOrder="0" pos="170 253 110 24" tooltip="This baudrate must match the baudrate currently in use by the serial control port on the WAV Trigger or Tsunami"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="d65667ae717c6adb" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="96 253 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Baudrate" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="c6eccef35ea83c0b" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="22 46 58 24" textCol="ff6e50f3" edTextCol="ff000000"
         edBkgCol="0" labelText="v2.21" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="16.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="stop all button" id="5834a73e118659da" memberName="stopAllButton"
              virtualName="" explicitFocusOrder="0" pos="55 294 80 24" tooltip="When serial communication is active, this sends a &quot;Stop All&quot; command to silence all audio"
              buttonText="Stop All" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="aeaa73cf290750d0" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="130 137 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Qwiic Address" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="baud combo box" id="5f3117ec1f650908" memberName="qwiicBox"
            virtualName="" explicitFocusOrder="0" pos="235 138 70 24" tooltip="This is the address assigned to Tsunami for the Qwiic bus"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: logo_png, 113759, "logo.png"
static const unsigned char resource_MainContentComponent_logo_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,7,208,0,0,6,229,8,6,0,0,0,104,248,89,211,0,0,32,0,73,68,65,84,120,94,236,221,93,
114,21,71,154,6,96,142,100,238,97,5,45,239,64,10,36,69,232,106,196,10,26,118,0,43,24,88,129,237,21,224,94,129,233,21,192,14,76,95,17,161,159,16,179,2,107,86,208,186,110,89,210,228,113,170,199,170,54,134,
115,148,85,149,127,15,17,14,123,102,170,42,191,124,190,143,186,121,39,235,44,30,248,67,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,60,88,48,32,64,128,0,1,2,4,8,16,
32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,30,8,208,13,1,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,88,10,56,129,110,14,8,16,32,64,128,0,1,2,4,
8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,12,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,
32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,
64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,12,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,
8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,
128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,
16,32,64,128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,128,0,221,12,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,2,116,51,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,
64,128,0,1,2,4,8,8,208,205,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,
8,16,32,32,64,55,3,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,
128,128,0,221,12,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,2,116,51,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,
8,208,205,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,32,64,55,
3,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,12,
16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,64,
128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,4,
8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,12,16,32,64,128,0,1,2,
4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,64,128,0,1,2,4,8,16,32,
64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,4,8,16,32,64,128,0,1,2,
4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,128,0,1,2,4,8,16,32,64,
128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,12,16,32,64,128,0,1,2,4,8,16,32,64,128,0,
1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,
16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,
32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,12,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,
128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,
64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,
4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,12,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,
32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,
136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,
129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,12,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,
4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,
38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,
8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,
128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,12,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,
16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,
1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,
32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,12,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,
128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,
4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,
16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,12,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,
64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,
128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,
4,8,16,32,64,128,128,0,221,12,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,
16,32,64,128,0,1,2,2,116,51,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,8,208,205,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,
32,64,55,3,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,
0,221,12,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,
116,51,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,
0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,
32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,12,16,32,64,
128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,4,8,16,32,
64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,128,0,1,2,
4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,12,16,32,64,128,0,1,2,4,8,16,
32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,
32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,12,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,
16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,
128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,
8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,12,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,
4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,
64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,
4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,
32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,12,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,
129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,
128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,
155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,
8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,12,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,
32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,
0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,
64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,12,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,
8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,
128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,
16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,12,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,
64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,
8,16,32,64,128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,
128,0,1,2,4,8,16,32,64,128,128,0,221,12,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,
16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,
1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,
32,64,128,128,0,221,12,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,
128,0,1,2,2,116,51,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,
4,8,8,208,205,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,32,64,
55,3,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,
12,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,
64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,
4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,
128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,12,16,32,64,128,0,
1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,64,128,0,1,2,4,8,
16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,128,0,1,2,4,215,56,
16,117,0,0,32,0,73,68,65,84,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,12,
16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,40,224,4,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,2,116,51,64,
128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,162,128,19,232,38,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,8,208,205,0,1,2,4,
8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,136,2,78,160,155,4,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,32,64,55,3,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,10,56,129,110,18,8,16,32,64,128,0,129,89,5,62,126,252,184,245,240,225,195,237,155,155,155,173,141,141,141,191,44,255,29,10,120,116,251,
207,178,150,187,255,61,107,109,157,46,118,17,246,253,255,255,44,22,139,139,235,235,235,255,13,125,57,15,255,125,190,183,183,247,161,83,23,219,38,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,160,67,
1,1,122,135,77,183,101,2,4,8,16,32,48,151,192,217,217,217,163,95,127,253,117,59,172,119,24,194,216,191,134,127,111,133,127,150,1,185,63,117,9,156,135,114,63,133,80,253,31,161,159,239,15,14,14,150,255,
179,63,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,104,78,64,128,222,92,75,109,136,0,1,2,4,8,228,21,88,158,48,255,230,155,111,94,8,204,243,246,97,226,213,47,66,127,223,135,147,234,127,119,66,
125,98,105,143,39,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,96,86,1,1,250,172,220,22,35,64,128,0,1,2,109,10,44,79,154,95,94,94,62,11,159,100,255,239,176,195,173,240,143,83,230,109,182,250,179,187,
10,97,250,143,87,87,87,127,223,223,223,255,212,209,182,109,149,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,6,5,4,232,13,54,213,150,8,16,32,64,128,192,92,2,199,199,199,135,33,52,255,107,248,180,
247,139,176,166,208,124,46,248,114,215,249,20,78,165,255,45,4,233,111,203,45,81,101,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,248,115,1,1,186,233,32,64,128,0,1,2,4,214,22,16,156,175,77,214,
219,13,231,33,72,255,65,144,222,91,219,237,151,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,253,2,2,244,250,123,104,7,4,8,16,32,64,96,54,129,163,163,163,237,112,226,252,77,88,240,112,182,69,45,84,
179,192,69,8,210,95,11,210,107,110,161,218,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,244,37,32,64,239,171,223,118,75,128,0,1,2,4,238,37,176,252,141,243,16,132,126,231,83,237,247,226,115,211,131,
7,203,79,187,191,244,27,233,70,129,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,210,5,4,232,165,119,72,125,4,8,16,32,64,32,179,192,242,115,237,139,197,226,167,80,198,86,230,82,44,95,185,64,152,
163,31,159,60,121,242,186,242,109,40,159,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,134,5,4,232,13,55,215,214,8,16,32,64,128,64,138,192,242,212,249,213,213,213,50,56,127,150,242,28,247,18,248,
15,129,139,240,63,191,220,221,221,125,79,134,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,165,9,8,208,75,235,136,122,8,16,32,64,128,64,1,2,78,157,23,208,132,198,75,112,26,189,241,6,219,30,1,2,4,
8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,74,5,4,232,149,54,78,217,4,8,16,32,64,96,42,129,16,158,191,10,225,230,119,225,249,143,166,90,195,115,9,220,10,124,186,188,188,124,126,112,112,112,78,132,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,37,8,8,208,75,232,130,26,8,16,32,64,128,64,1,2,62,217,94,64,19,250,44,225,226,230,230,230,249,222,222,222,135,62,183,111,215,4,8,16,32,64,128,0,1,2,4,8,
16,32,64,128,0,1,2,4,8,148,36,32,64,47,169,27,106,33,64,128,0,1,2,153,4,132,231,153,224,45,123,87,224,185,223,69,55,16,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,228,22,16,160,231,238,128,245,9,
16,32,64,128,64,102,129,143,31,63,110,61,124,248,240,93,40,99,59,115,41,150,239,92,32,156,68,127,29,78,162,255,216,57,131,237,19,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,144,81,64,128,158,17,223,
210,4,8,16,32,64,32,183,192,209,209,209,246,198,198,198,50,60,223,202,93,139,245,9,44,5,132,232,230,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,156,2,2,244,156,250,214,38,64,128,0,1,2,25,5,
110,79,158,255,28,74,216,202,88,134,165,9,252,65,224,250,250,250,229,254,254,254,91,52,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,152,91,64,128,62,183,184,245,8,16,32,64,128,64,1,2,183,191,121,
190,12,207,125,182,189,128,126,40,225,143,2,66,116,83,65,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,14,1,1,122,14,117,107,18,32,64,128,0,129,140,2,183,225,249,79,161,132,103,25,203,176,52,129,
175,10,132,207,185,63,13,191,137,254,225,171,23,186,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,35,9,8,208,71,130,244,24,2,4,8,16,32,80,139,192,201,201,201,242,55,207,133,231,181,52,172,243,
58,195,73,244,157,240,57,247,79,157,51,216,62,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,51,9,8,208,103,130,182,12,1,2,4,8,16,40,65,224,248,248,248,213,98,177,120,83,66,45,106,32,176,162,192,197,
238,238,238,227,21,175,117,25,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,146,4,4,232,73,124,110,38,64,128,0,1,2,245,8,132,240,252,48,132,231,203,211,231,143,234,169,90,165,4,126,19,248,16,66,
244,167,44,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,48,181,128,0,125,106,97,207,39,64,128,0,1,2,5,8,220,254,238,249,89,40,101,171,128,114,148,64,96,109,129,240,41,247,151,225,83,238,111,215,
190,209,13,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,88,67,64,128,190,6,150,75,9,16,32,64,128,64,173,2,126,247,188,214,206,169,251,174,128,223,67,55,15,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,76,45,32,64,159,90,216,243,9,16,32,64,128,64,102,1,191,123,158,185,1,150,31,83,224,60,124,202,253,219,49,31,232,89,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,184,43,32,64,55,15,4,8,
16,32,64,160,97,129,219,79,183,255,18,182,232,119,207,27,238,115,79,91,243,41,247,158,186,109,175,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,230,23,16,160,207,111,110,69,2,4,8,16,32,48,155,192,233,
233,233,155,155,155,155,87,179,45,104,33,2,211,11,92,92,94,94,238,28,28,28,156,79,191,148,21,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,232,77,64,128,222,91,199,237,151,0,1,2,4,186,17,8,159,110,
63,92,44,22,239,194,134,157,62,239,166,235,221,108,244,125,248,148,251,243,110,118,107,163,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,204,38,32,64,159,141,218,66,4,8,16,32,64,96,94,129,147,147,
147,159,195,138,135,243,174,106,53,2,243,8,132,83,232,223,58,133,62,143,181,85,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,244,36,32,64,239,169,219,246,74,128,0,1,2,221,8,220,158,62,95,6,232,254,16,
104,82,32,124,93,225,237,147,39,79,94,54,185,57,155,34,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,155,128,0,61,27,189,133,9,16,32,64,128,192,116,2,225,244,249,242,211,237,207,166,91,193,147,9,
228,23,112,10,61,127,15,84,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,160,53,1,1,122,107,29,181,31,2,4,8,16,232,94,224,232,232,104,123,99,99,227,172,123,8,0,205,11,56,133,222,124,139,109,144,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,192,236,2,2,244,217,201,45,72,128,0,1,2,4,166,21,56,61,61,253,233,230,230,230,197,180,171,120,58,129,50,4,156,66,47,163,15,170,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,208,138,128,0,189,149,78,218,7,1,2,4,8,16,8,2,103,103,103,143,174,174,174,126,9,255,249,8,8,129,30,4,194,255,179,200,235,189,189,189,31,123,216,171,61,18,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,48,189,128,0,125,122,99,43,16,32,64,128,0,129,217,4,142,143,143,95,133,207,90,191,153,109,65,11,17,200,47,112,177,187,187,251,56,127,25,42,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,
32,64,160,5,1,1,122,11,93,180,7,2,4,8,16,32,112,43,112,114,114,242,115,248,207,67,32,4,122,18,240,25,247,158,186,109,175,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,166,21,16,160,79,235,235,233,4,
8,16,32,64,96,54,129,163,163,163,237,141,141,141,179,217,22,180,16,129,66,4,194,87,23,222,62,121,242,228,101,33,229,40,131,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,138,5,4,232,21,55,79,233,
4,8,16,32,64,224,174,64,248,124,251,247,33,72,252,142,10,129,14,5,124,198,189,195,166,219,50,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,41,4,4,232,83,168,122,38,1,2,4,8,16,200,32,16,62,223,254,
75,88,118,43,195,210,150,36,144,93,224,230,230,230,233,222,222,222,135,236,133,40,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,170,5,4,232,85,183,79,241,4,8,16,32,64,32,10,156,157,157,61,186,
186,186,250,39,15,2,189,10,132,0,253,135,16,160,127,223,235,254,237,155,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,113,4,4,232,227,56,122,10,1,2,4,8,16,200,42,16,78,159,63,11,5,188,203,90,132,
197,9,228,21,120,191,187,187,251,60,111,9,86,39,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,160,118,1,1,122,237,29,84,63,1,2,4,8,16,8,2,167,167,167,63,133,19,184,47,96,16,232,89,96,115,115,243,241,
206,206,206,69,207,6,246,78,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,154,128,0,61,205,207,221,4,8,16,32,64,160,8,1,191,127,94,68,27,20,145,89,192,239,160,103,110,128,229,9,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,52,32,32,64,111,160,137,182,64,128,0,1,2,125,11,248,253,243,190,251,111,247,191,11,132,0,253,117,248,29,244,31,153,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,224,
190,2,2,244,251,202,185,143,0,1,2,4,8,20,34,112,116,116,180,189,177,177,113,86,72,57,202,32,144,83,192,239,160,231,212,183,54,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,6,4,4,232,13,52,209,22,8,
16,32,64,160,111,129,16,160,191,8,1,250,79,125,43,216,61,129,223,4,62,236,238,238,62,101,65,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,251,10,8,208,239,43,231,62,2,4,8,16,32,80,136,192,241,
241,241,171,197,98,241,166,144,114,148,65,32,167,192,69,8,208,31,231,44,192,218,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,212,45,32,64,175,187,127,170,39,64,128,0,1,2,15,78,78,78,222,5,134,103,
40,8,16,120,240,96,115,115,243,241,206,206,206,5,11,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,220,71,64,128,126,31,53,247,16,32,64,128,0,129,130,4,66,128,254,115,40,231,176,160,146,148,66,32,
155,192,245,245,245,206,254,254,254,167,108,5,88,152,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,170,5,4,232,85,183,79,241,4,8,16,32,64,224,193,242,4,250,89,112,216,102,65,128,192,131,7,55,55,
55,79,247,246,246,62,176,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,192,125,4,4,232,247,81,115,15,1,2,4,8,16,40,72,32,4,232,191,132,114,182,10,42,73,41,4,114,10,60,15,191,131,254,62,103,1,
214,38,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,160,94,1,1,122,189,189,83,57,1,2,4,8,16,248,77,64,128,110,16,8,252,46,16,62,225,254,50,124,194,253,45,19,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,220,71,64,128,126,31,53,247,16,32,64,128,0,129,130,4,66,128,126,83,80,57,74,33,144,85,32,124,194,253,117,248,132,251,143,89,139,176,56,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,213,10,
8,208,171,109,157,194,9,16,32,64,128,64,20,16,160,155,4,2,191,11,8,208,77,3,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,41,2,2,244,20,61,247,18,32,64,128,0,129,204,2,103,103,103,143,174,174,174,
254,153,185,12,203,19,40,70,64,128,94,76,43,20,66,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,160,74,1,1,122,149,109,83,52,1,2,4,8,16,136,2,2,116,147,64,96,40,32,64,55,17,4,8,16,32,64,128,0,1,2,4,8,
16,32,64,128,0,1,2,4,8,164,8,8,208,83,244,220,75,128,0,1,2,4,50,11,8,208,51,55,192,242,197,9,8,208,139,107,137,130,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,84,37,32,64,175,170,93,138,37,64,128,
0,1,2,67,1,1,186,137,32,48,20,16,160,155,8,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,82,4,4,232,41,122,238,37,64,128,0,1,2,153,5,4,232,153,27,96,249,226,4,4,232,197,181,68,65,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,4,170,18,16,160,87,213,46,197,18,32,64,128,0,129,161,128,0,221,68,16,24,10,8,208,77,4,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,41,2,2,244,20,61,247,18,32,64,128,0,
129,204,2,2,244,204,13,176,124,113,2,2,244,226,90,162,32,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,85,9,8,208,171,106,151,98,9,16,32,64,128,192,80,64,128,110,34,8,12,5,4,232,38,130,0,1,2,4,8,16,
32,64,128,0,1,2,4,8,16,32,64,128,0,129,20,1,1,122,138,158,123,9,16,32,64,128,64,102,1,1,122,230,6,88,190,56,1,1,122,113,45,81,16,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,170,4,4,232,85,181,75,
177,4,8,16,32,64,96,40,32,64,55,17,4,134,2,2,116,19,65,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,138,128,0,61,69,207,189,4,8,16,32,64,32,179,128,0,61,115,3,44,95,156,128,0,189,184,150,40,136,
0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,85,2,2,244,170,218,165,88,2,4,8,16,32,48,20,16,160,155,8,2,67,1,1,186,137,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,69,64,128,158,162,231,
94,2,4,8,16,32,144,89,64,128,158,185,1,150,47,78,64,128,94,92,75,20,68,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,160,42,1,1,122,85,237,82,44,1,2,4,8,16,24,10,8,208,77,4,129,161,128,0,221,68,16,32,
64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,144,34,32,64,79,209,115,47,1,2,4,8,16,200,44,32,64,207,220,0,203,23,39,32,64,47,174,37,10,34,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,80,149,128,0,189,
170,118,41,150,0,1,2,4,8,12,5,4,232,38,130,192,80,64,128,110,34,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,72,17,16,160,167,232,185,151,0,1,2,4,8,100,22,16,160,103,110,128,229,139,19,16,160,23,
215,18,5,17,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,168,74,64,128,94,85,187,20,75,128,0,1,2,4,134,2,2,116,19,65,96,40,32,64,55,17,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,164,8,8,208,83,
244,220,75,128,0,1,2,4,50,11,8,208,51,55,192,242,197,9,8,208,139,107,137,130,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,84,37,32,64,175,170,93,138,37,64,128,0,1,2,67,1,1,186,137,32,48,20,16,160,155,
8,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,82,4,4,232,41,122,238,37,64,128,0,1,2,153,5,4,232,153,27,96,249,226,4,4,232,197,181,68,65,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,170,18,16,
160,87,213,46,197,18,32,64,128,0,129,161,128,0,221,68,16,24,10,8,208,77,4,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,41,2,2,244,20,61,247,18,32,64,128,0,129,204,2,2,244,204,13,176,124,113,2,2,244,
226,90,162,32,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,85,9,8,208,171,106,151,98,9,16,32,64,128,192,80,64,128,110,34,8,12,5,4,232,38,130,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,20,1,
1,122,138,158,123,9,16,32,64,128,64,102,1,1,122,230,6,88,190,56,1,1,122,113,45,81,16,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,170,4,4,232,85,181,75,177,4,8,16,32,64,96,40,32,64,55,17,4,134,2,
2,116,19,65,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,138,128,0,61,69,207,189,4,8,16,32,64,32,179,128,0,61,115,3,44,95,156,128,0,189,184,150,40,136,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,
128,64,85,2,2,244,170,218,165,88,2,4,8,16,32,48,20,16,160,155,8,2,67,1,1,186,137,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,69,64,128,158,162,231,94,2,4,8,16,32,144,89,64,128,158,185,1,150,
47,78,64,128,94,92,75,20,68,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,160,42,1,1,122,85,237,82,44,1,2,4,8,16,24,10,8,208,77,4,129,161,128,0,221,68,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,
32,144,34,32,64,79,209,115,47,1,2,4,8,16,200,44,32,64,207,220,0,203,23,39,32,64,47,174,37,10,34,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,80,149,128,0,189,170,118,41,150,0,1,2,4,8,12,5,4,232,38,130,
192,80,64,128,110,34,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,72,17,16,160,167,232,185,151,0,1,2,4,8,100,22,16,160,103,110,128,229,139,19,16,160,23,215,18,5,17,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,168,74,64,128,94,85,187,20,75,128,0,1,2,4,134,2,2,116,19,65,96,40,32,64,55,17,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,164,8,8,208,83,244,220,75,128,0,1,2,4,50,11,8,208,51,55,192,
242,197,9,8,208,139,107,137,130,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,84,37,32,64,175,170,93,138,37,64,128,0,1,2,67,1,1,186,137,32,48,20,16,160,155,8,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,82,4,4,232,41,122,238,37,64,128,0,1,2,153,5,4,232,153,27,96,249,226,4,4,232,197,181,68,65,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,170,18,16,160,87,213,46,197,18,32,64,128,0,129,161,128,
0,221,68,16,24,10,8,208,77,4,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,41,2,2,244,20,61,247,18,32,64,128,0,129,204,2,2,244,204,13,176,124,113,2,2,244,226,90,162,32,2,4,8,16,32,64,128,0,1,2,4,8,
16,32,64,128,0,1,2,85,9,8,208,171,106,151,98,9,16,32,64,128,192,80,64,128,110,34,8,12,5,4,232,38,130,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,20,1,1,122,138,158,123,9,16,32,64,128,64,102,1,
1,122,230,6,88,190,56,1,1,122,113,45,81,16,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,170,4,4,232,85,181,75,177,4,8,16,32,64,96,40,32,64,55,17,4,134,2,2,116,19,65,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,64,138,128,0,61,69,207,189,4,8,16,32,64,32,179,128,0,61,115,3,44,95,156,128,0,189,184,150,40,136,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,85,2,2,244,170,218,165,88,2,4,8,16,
32,48,20,16,160,155,8,2,67,1,1,186,137,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,69,64,128,158,162,231,94,2,4,8,16,32,144,89,64,128,158,185,1,150,47,78,64,128,94,92,75,20,68,128,0,1,2,4,8,
16,32,64,128,0,1,2,4,8,16,32,64,160,42,1,1,122,85,237,82,44,1,2,4,8,16,24,10,8,208,77,4,129,161,128,0,221,68,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,144,34,32,64,79,209,115,47,1,2,4,8,16,200,
44,32,64,207,220,0,203,23,39,32,64,47,174,37,10,34,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,80,149,128,0,189,170,118,41,150,0,1,2,4,8,12,5,4,232,38,130,192,80,64,128,110,34,8,16,32,64,128,0,1,2,4,
8,16,32,64,128,0,1,2,4,8,16,72,17,16,160,167,232,185,151,0,1,2,4,8,100,22,16,160,103,110,128,229,139,19,16,160,23,215,18,5,17,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,168,74,64,128,94,85,187,20,75,
128,0,1,2,4,134,2,2,116,19,65,96,40,32,64,55,17,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,164,8,8,208,83,244,220,75,128,0,1,2,4,50,11,8,208,51,55,192,242,197,9,8,208,139,107,137,130,8,16,32,64,
128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,84,37,32,64,175,170,93,138,37,64,128,0,1,2,67,1,1,186,137,32,48,20,16,160,155,8,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,82,4,4,232,41,122,238,37,64,128,0,
1,2,153,5,4,232,153,27,96,249,226,4,4,232,197,181,68,65,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,170,18,16,160,87,213,46,197,18,32,64,128,0,129,161,128,0,221,68,16,24,10,8,208,77,4,1,2,4,8,16,32,
64,128,0,1,2,4,8,16,32,64,128,0,1,2,41,2,2,244,20,61,247,18,32,64,128,0,129,204,2,2,244,204,13,176,124,113,2,2,244,226,90,162,32,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,85,9,8,208,171,106,151,
98,9,16,32,64,128,192,80,64,128,110,34,8,12,5,4,232,38,130,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,20,1,1,122,138,158,123,9,16,32,64,128,64,102,1,1,122,230,6,88,190,56,1,1,122,113,45,81,16,
1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,170,4,4,232,85,181,75,177,4,8,16,32,64,96,40,32,64,55,17,4,134,2,2,116,19,65,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,138,128,0,61,69,207,
189,4,8,16,32,64,32,179,128,0,61,115,3,44,95,156,128,0,189,184,150,40,136,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,85,2,2,244,170,218,165,88,2,4,8,16,32,48,20,16,160,155,8,2,67,1,1,186,137,32,
64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,69,64,128,158,162,231,94,2,4,8,16,32,144,89,64,128,158,185,1,150,47,78,64,128,94,92,75,20,68,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,160,42,1,
1,122,85,237,82,44,1,2,4,8,16,24,10,8,208,77,4,129,161,128,0,221,68,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,144,34,32,64,79,209,115,47,1,2,4,8,16,200,44,32,64,207,220,0,203,23,39,32,64,47,
174,37,10,34,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,80,149,128,0,189,170,118,41,150,0,1,2,4,8,12,5,4,232,38,130,192,80,64,128,110,34,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,72,17,16,
160,167,232,185,151,0,1,2,4,8,100,22,16,160,103,110,128,229,139,19,16,160,23,215,18,5,17,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,168,74,64,128,94,85,187,20,75,128,0,1,2,4,134,2,2,116,19,65,96,40,
32,64,55,17,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,164,8,8,208,83,244,220,75,128,0,1,2,4,50,11,8,208,51,55,192,242,197,9,8,208,139,107,137,130,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,
8,84,37,32,64,175,170,93,138,37,64,128,0,1,2,67,1,1,186,137,32,48,20,16,160,155,8,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,82,4,4,232,41,122,238,37,64,128,0,1,2,153,5,4,232,153,27,96,249,226,
4,4,232,197,181,68,65,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,170,18,16,160,87,213,46,197,18,32,64,128,0,129,161,128,0,221,68,16,24,10,8,208,77,4,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,
1,2,41,2,2,244,20,61,247,18,32,64,128,0,129,204,2,2,244,204,13,176,124,113,2,2,244,226,90,162,32,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,85,9,8,208,171,106,151,98,9,16,32,64,128,192,80,64,128,
110,34,8,12,5,4,232,38,130,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,20,1,1,122,138,158,123,9,16,32,64,128,64,102,1,1,122,230,6,88,190,56,1,1,122,113,45,81,16,1,2,4,8,16,32,64,128,0,1,2,4,8,
16,32,64,128,0,129,170,4,4,232,85,181,75,177,4,8,16,32,64,96,40,32,64,55,17,4,134,2,2,116,19,65,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,138,128,0,61,69,207,189,4,8,16,32,64,32,179,128,0,61,
115,3,44,95,156,128,0,189,184,150,40,136,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,85,2,2,244,170,218,165,88,2,4,8,16,32,48,20,16,160,155,8,2,67,1,1,186,137,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,32,69,64,128,158,162,231,94,2,4,8,16,32,144,89,64,128,158,185,1,150,47,78,64,128,94,92,75,20,68,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,160,42,1,1,122,85,237,82,44,1,2,4,8,16,24,10,
8,208,77,4,129,161,128,0,221,68,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,144,34,32,64,79,209,115,47,1,2,4,8,16,200,44,32,64,207,220,0,203,23,39,32,64,47,174,37,10,34,64,128,0,1,2,4,8,16,32,
64,128,0,1,2,4,8,16,32,80,149,128,0,189,170,118,41,150,0,1,2,4,8,12,5,4,232,38,130,192,80,64,128,110,34,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,72,17,16,160,167,232,185,151,0,1,2,4,8,100,22,
16,160,103,110,128,229,139,19,16,160,23,215,146,228,130,150,239,185,95,127,253,117,59,244,118,107,177,88,60,218,216,216,248,203,237,67,31,133,255,221,163,240,223,203,127,252,153,86,224,98,249,248,224,
255,219,191,175,175,175,255,119,249,239,224,127,30,254,119,231,223,124,243,205,167,157,157,157,223,254,111,254,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,106,23,16,160,215,222,65,245,19,32,64,128,64,
215,2,2,244,174,219,111,243,159,17,16,160,215,61,22,183,239,180,195,16,202,254,87,232,229,97,216,205,86,248,71,64,94,79,91,223,47,67,246,16,176,255,79,8,213,223,10,213,235,105,156,74,9,16,32,64,128,0,
1,2,4,8,16,32,64,128,0,129,223,5,4,232,166,129,0,1,2,4,8,84,44,32,64,175,184,121,74,159,68,64,128,62,9,235,100,15,253,247,233,242,176,192,50,52,255,107,248,247,246,100,139,121,112,14,129,139,208,215,247,
87,87,87,255,216,223,223,127,155,163,0,107,18,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,214,21,16,160,175,43,230,122,2,4,8,16,32,80,144,128,0,189,160,102,40,165,8,1,1,122,17,109,248,106,17,199,199,199,
135,225,83,236,127,13,253,122,17,46,118,194,252,171,98,109,92,16,194,244,183,225,116,250,223,247,246,246,62,180,177,35,187,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,90,20,16,160,183,216,85,123,34,64,128,
0,129,110,4,4,232,221,180,218,70,87,20,16,160,175,8,149,225,178,219,211,230,175,156,52,207,128,95,222,146,203,147,233,111,255,245,175,127,253,237,224,224,224,188,188,242,84,68,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,244,44,32,64,239,185,251,246,78,128,0,1,2,213,11,8,208,171,111,161,13,140,44,32,64,31,25,116,132,199,45,223,83,225,212,241,119,78,155,143,128,217,224,35,66,144,254,163,32,189,193,198,218,18,
1,2,4,8,16,32,64,128,0,1,2,4,8,16,168,88,64,128,94,113,243,148,78,128,0,1,2,4,4,232,102,128,192,80,64,128,94,206,68,8,206,203,233,69,13,149,8,210,107,232,146,26,9,16,32,64,128,0,1,2,4,8,16,32,64,128,64,
31,2,2,244,62,250,108,151,4,8,16,32,208,168,128,0,189,209,198,218,214,189,5,4,232,247,166,27,237,198,229,123,233,242,242,242,89,248,141,243,55,225,161,126,223,124,52,217,62,30,180,12,210,159,60,121,242,
186,143,221,218,37,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,80,162,128,0,189,196,174,168,137,0,1,2,4,8,172,40,32,64,95,17,202,101,221,8,8,208,243,182,250,248,248,248,48,4,160,203,224,124,59,111,37,86,175,
92,224,34,124,246,255,245,254,254,254,219,202,247,161,124,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,160,66,1,1,122,133,77,83,50,1,2,4,8,16,248,183,128,0,221,44,16,24,10,8,208,243,76,132,207,181,231,113,239,
96,213,15,155,155,155,207,119,118,118,46,58,216,171,45,18,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,133,8,8,208,11,105,132,50,8,16,32,64,128,192,125,4,4,232,247,81,115,79,203,2,2,244,249,187,123,116,116,
180,29,62,215,254,83,88,217,169,243,249,249,123,88,241,34,252,189,126,190,183,183,247,161,135,205,218,35,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,144,95,64,128,158,191,7,42,32,64,128,0,1,2,247,22,16,160,223,
155,206,141,141,10,8,208,231,109,108,8,207,95,248,173,243,121,152,35,171,148,0,0,32,0,73,68,65,84,205,123,93,45,252,221,254,33,132,232,223,247,186,127,251,38,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,230,
19,16,160,207,103,109,37,2,4,8,16,32,48,186,128,0,125,116,82,15,172,92,64,128,62,79,3,239,124,178,253,213,60,43,90,133,192,111,2,159,194,39,221,159,250,164,187,105,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,166,20,16,160,79,169,235,217,4,8,16,32,64,96,98,1,1,250,196,192,30,95,157,128,0,125,250,150,221,190,119,150,159,108,127,54,253,106,86,32,240,7,129,79,151,151,151,207,15,14,14,206,217,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,4,166,16,16,160,79,161,234,153,4,8,16,32,64,96,38,1,1,250,76,208,150,169,70,64,128,62,109,171,132,231,211,250,122,250,202,2,23,215,215,215,79,247,247,247,63,173,124,135,11,
9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,43,10,8,208,87,132,114,25,1,2,4,8,16,40,81,64,128,94,98,87,212,148,83,64,128,62,157,254,199,143,31,183,30,62,124,248,115,88,97,107,186,85,60,153,192,202,2,23,
225,239,251,243,240,187,232,31,86,190,195,133,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,21,4,4,232,43,32,185,132,0,1,2,4,8,148,42,32,64,47,181,51,234,202,37,32,64,159,70,254,246,93,115,22,158,190,
53,205,10,158,74,224,126,2,225,36,250,142,147,232,247,179,115,23,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,240,121,1,1,186,201,32,64,128,0,1,2,21,11,8,208,43,110,158,210,39,17,16,160,143,207,122,251,158,121,
23,158,124,56,254,211,61,145,64,178,128,207,185,39,19,122,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,112,87,64,128,110,30,8,16,32,64,128,64,197,2,2,244,138,155,167,244,73,4,4,232,227,178,250,205,243,113,61,
61,109,50,129,139,203,203,203,157,131,131,131,243,201,86,240,96,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,160,27,1,1,122,55,173,182,81,2,4,8,16,104,81,64,128,222,98,87,237,41,69,64,128,158,162,247,199,123,
79,78,78,150,39,207,159,141,251,84,79,35,48,137,192,249,230,230,230,78,248,115,49,201,211,61,148,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,232,70,64,128,222,77,171,109,148,0,1,2,4,90,20,16,160,183,216,85,123,
74,17,16,160,167,232,13,239,61,62,62,126,181,88,44,222,140,247,68,79,34,48,185,192,135,221,221,221,167,147,175,98,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,160,105,1,1,122,211,237,181,57,2,4,8,16,104,93,
64,128,222,122,135,237,111,93,1,1,250,186,98,159,191,62,132,231,135,33,60,95,158,62,127,52,206,19,61,133,192,60,2,222,1,243,56,91,133,0,1,2,4,8,16,32,64,128,0,1,2,4,8,180,44,32,64,111,185,187,246,70,128,
0,1,2,205,11,8,208,155,111,177,13,174,41,32,60,91,19,236,51,151,223,190,87,206,194,255,105,43,253,105,158,64,96,126,129,235,235,235,157,253,253,253,79,243,175,108,69,2,4,8,16,32,64,128,0,1,2,4,8,16,32,
64,160,5,1,1,122,11,93,180,7,2,4,8,16,232,86,64,128,222,109,235,109,252,79,4,4,232,233,163,225,119,207,211,13,61,33,187,192,69,248,61,244,111,253,30,122,246,62,40,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,
84,41,32,64,175,178,109,138,38,64,128,0,1,2,81,64,128,110,18,8,12,5,4,232,105,19,225,119,207,211,252,220,93,148,192,251,240,123,232,207,139,170,72,49,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,21,2,2,
244,42,218,164,72,2,4,8,16,32,240,121,1,1,186,201,32,32,64,31,107,6,110,223,39,191,132,231,249,221,243,177,80,61,39,171,128,79,185,103,229,183,56,1,2,4,8,16,32,64,128,0,1,2,4,8,16,168,86,64,128,94,109,
235,20,78,128,0,1,2,4,156,64,55,3,4,254,83,192,9,244,251,207,196,233,233,233,155,224,247,234,254,79,112,39,129,226,4,206,195,41,244,111,139,171,74,65,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,209,2,2,
244,162,219,163,56,2,4,8,16,32,240,101,1,39,208,77,8,129,161,128,0,253,126,19,17,62,221,126,184,88,44,126,190,223,221,238,34,80,174,128,119,66,185,189,81,25,1,2,4,8,16,32,64,128,0,1,2,4,8,16,40,85,64,
128,94,106,103,212,69,128,0,1,2,4,86,16,16,160,175,128,228,146,174,4,132,101,247,107,247,201,201,201,50,60,63,188,223,221,238,34,80,180,192,197,229,229,229,206,193,193,193,121,209,85,42,142,0,1,2,4,8,
16,32,64,128,0,1,2,4,8,16,40,70,64,128,94,76,43,20,66,128,0,1,2,4,214,23,16,160,175,111,230,142,182,5,4,232,235,247,55,132,231,207,194,93,239,214,191,211,29,4,234,16,8,239,133,31,246,246,246,190,175,163,
90,85,18,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,185,5,4,232,185,59,96,125,2,4,8,16,32,144,32,32,64,79,192,115,107,147,2,2,244,245,219,234,244,249,250,102,238,168,78,224,34,252,22,250,227,234,170,86,48,
1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,144,69,64,128,158,133,221,162,4,8,16,32,64,96,28,1,1,250,56,142,158,210,142,128,0,125,189,94,250,237,243,245,188,92,93,175,128,83,232,245,246,78,229,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,96,110,1,1,250,220,226,214,35,64,128,0,1,2,35,10,8,208,71,196,244,168,38,4,4,232,235,181,209,233,243,245,188,92,93,181,128,83,232,85,183,79,241,4,8,16,32,64,128,0,1,2,4,8,16,32,64,96,
62,1,1,250,124,214,86,34,64,128,0,1,2,163,11,8,208,71,39,245,192,202,5,4,232,171,55,240,232,232,104,123,99,99,227,108,245,59,92,73,160,110,129,235,235,235,151,251,251,251,111,235,222,133,234,9,16,32,64,
128,0,1,2,4,8,16,32,64,128,0,129,169,5,4,232,83,11,123,62,1,2,4,8,16,152,80,64,128,62,33,174,71,87,41,32,64,95,189,109,225,243,237,223,47,22,139,239,86,191,195,149,4,170,23,248,20,126,11,125,167,250,93,
216,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,48,169,128,0,125,82,94,15,39,64,128,0,1,2,211,10,8,208,167,245,245,244,250,4,4,232,171,247,44,124,190,253,151,112,245,214,234,119,184,146,64,253,2,151,151,151,
223,30,28,28,156,215,191,19,59,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,166,18,16,160,79,37,235,185,4,8,16,32,64,96,6,1,1,250,12,200,150,168,74,64,128,190,90,187,66,120,254,44,92,249,110,181,171,93,69,
160,29,1,239,136,118,122,105,39,4,8,16,32,64,128,0,1,2,4,8,16,32,64,96,42,1,1,250,84,178,158,75,128,0,1,2,4,102,16,16,160,207,128,108,137,170,4,132,99,171,181,235,244,244,244,77,176,122,181,218,213,174,
34,208,148,192,69,248,140,251,227,166,118,100,51,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,192,168,2,2,244,81,57,61,140,0,1,2,4,8,204,43,32,64,159,215,219,106,229,11,8,208,87,235,145,207,183,175,230,228,
170,54,5,124,198,189,205,190,218,21,1,2,4,8,16,32,64,128,0,1,2,4,8,16,24,75,64,128,62,150,164,231,16,32,64,128,0,129,12,2,2,244,12,232,150,44,90,64,128,254,245,246,28,29,29,109,111,108,108,156,125,253,
74,87,16,104,83,192,123,162,205,190,218,21,1,2,4,8,16,32,64,128,0,1,2,4,8,16,24,75,64,128,62,150,164,231,16,32,64,128,0,129,12,2,2,244,12,232,150,44,90,64,48,246,245,246,28,31,31,191,90,44,22,111,190,
126,165,43,8,52,43,240,62,124,198,253,121,179,187,179,49,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,73,64,128,158,196,231,102,2,4,8,16,32,144,87,64,128,158,215,223,234,229,9,8,208,191,222,147,240,249,246,
119,225,170,103,95,191,210,21,4,154,21,240,59,232,205,182,214,198,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,186,128,0,61,221,208,19,8,16,32,64,128,64,54,1,1,122,54,122,11,23,42,32,64,255,122,99,252,254,
249,215,141,92,209,190,128,223,65,111,191,199,118,72,128,0,1,2,4,8,16,32,64,128,0,1,2,4,238,43,32,64,191,175,156,251,8,16,32,64,128,64,1,2,2,244,2,154,160,132,162,4,4,232,95,110,135,223,63,47,106,92,21,
147,81,192,187,34,35,190,165,9,16,32,64,128,0,1,2,4,8,16,32,64,128,64,225,2,2,244,194,27,164,60,2,4,8,16,32,240,37,1,1,186,249,32,48,20,16,138,125,121,34,194,233,243,229,167,219,151,159,112,247,135,64,
215,2,225,93,241,195,222,222,222,247,93,35,216,60,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,240,89,1,1,186,193,32,64,128,0,1,2,21,11,8,208,43,110,158,210,39,17,16,160,127,153,245,248,248,248,213,98,177,120,
51,9,190,135,18,168,75,224,253,238,238,238,243,186,74,86,45,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,48,135,128,0,125,14,101,107,16,32,64,128,0,129,137,4,4,232,19,193,122,108,181,2,2,244,47,183,238,244,244,
244,167,96,244,162,218,6,43,156,192,120,2,23,33,64,127,60,222,227,60,137,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,104,69,64,128,222,74,39,237,131,0,1,2,4,186,20,16,160,119,217,118,155,254,130,128,0,253,203,
227,17,62,225,190,252,124,251,242,51,238,254,16,232,94,96,115,115,243,241,206,206,206,69,247,16,0,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,129,128,0,221,64,16,32,64,128,0,129,138,5,4,232,21,55,79,233,
147,8,8,208,191,204,26,2,244,95,194,21,91,147,224,123,40,129,202,4,174,175,175,119,246,247,247,63,85,86,182,114,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,137,5,4,232,19,3,123,60,1,2,4,8,16,152,82,64,
128,62,165,174,103,215,40,32,64,255,114,215,66,128,254,207,112,197,163,26,123,171,102,2,99,11,132,247,197,211,189,189,189,15,99,63,215,243,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,186,5,4,232,117,247,
79,245,4,8,16,32,208,185,128,0,189,243,1,176,253,63,8,8,208,191,60,20,33,64,191,49,54,4,8,68,1,1,186,73,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,62,39,32,64,55,23,4,8,16,32,64,160,98,1,1,122,197,205,83,
250,36,2,2,244,63,103,245,190,152,100,228,60,180,110,129,231,187,187,187,239,235,222,130,234,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,177,5,4,232,99,139,122,30,1,2,4,8,16,152,81,64,32,54,35,182,165,
170,16,16,160,255,121,155,62,126,252,184,245,240,225,195,229,111,160,251,67,128,64,16,8,191,129,254,50,252,6,250,91,24,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,187,2,2,116,243,64,128,0,1,2,4,42,22,
16,160,87,220,60,165,79,34,32,64,255,115,214,163,163,163,237,141,141,141,179,73,224,61,148,64,133,2,222,23,21,54,77,201,4,8,16,32,64,128,0,1,2,4,8,16,32,64,96,6,1,1,250,12,200,150,32,64,128,0,1,2,83,9,
8,208,167,146,245,220,90,5,4,98,2,244,90,103,87,221,243,11,120,95,204,111,110,69,2,4,8,16,32,64,128,0,1,2,4,8,16,32,80,131,128,0,189,134,46,169,145,0,1,2,4,8,252,137,128,0,221,104,16,24,10,8,196,4,232,
254,78,16,88,85,192,251,98,85,41,215,17,32,64,128,0,1,2,4,8,16,32,64,128,0,129,190,4,4,232,125,245,219,110,9,16,32,64,160,49,1,1,122,99,13,181,157,100,1,129,152,0,61,121,136,60,160,27,1,239,139,110,90,
109,163,4,8,16,32,64,128,0,1,2,4,8,16,32,64,96,45,1,1,250,90,92,46,38,64,128,0,1,2,101,9,8,208,203,234,135,106,242,11,8,196,4,232,249,167,80,5,181,8,120,95,212,210,41,117,18,32,64,128,0,1,2,4,8,16,32,
64,128,0,129,121,5,4,232,243,122,91,141,0,1,2,4,8,140,42,32,64,31,149,211,195,26,16,16,136,9,208,27,24,99,91,152,73,192,251,98,38,104,203,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,202,4,4,232,149,53,76,
185,4,8,16,32,64,224,174,128,0,221,60,16,24,10,8,196,4,232,254,78,16,88,85,192,251,98,85,41,215,17,32,64,128,0,1,2,4,8,16,32,64,128,0,129,190,4,4,232,125,245,219,110,9,16,32,64,160,49,1,1,122,99,13,181,
157,100,1,129,152,0,61,121,136,60,160,27,1,239,139,110,90,109,163,4,8,16,32,64,128,0,1,2,4,8,16,32,64,96,45,1,1,250,90,92,46,38,64,128,0,1,2,101,9,8,208,203,234,135,106,242,11,8,196,4,232,249,167,80,5,
181,8,120,95,212,210,41,117,18,32,64,128,0,1,2,4,8,16,32,64,128,0,129,121,5,4,232,243,122,91,141,0,1,2,4,8,140,42,32,64,31,149,211,195,26,16,16,136,9,208,27,24,99,91,152,73,192,251,98,38,104,203,16,32,
64,128,0,1,2,4,8,16,32,64,128,0,129,202,4,4,232,149,53,76,185,4,8,16,32,64,224,174,128,0,221,60,16,24,10,8,196,4,232,254,78,16,88,85,192,251,98,85,41,215,17,32,64,128,0,1,2,4,8,16,32,64,128,0,129,190,
4,4,232,125,245,219,110,9,16,32,64,160,49,1,1,122,99,13,181,157,100,1,129,152,0,61,121,136,60,160,27,1,239,139,110,90,109,163,4,8,16,32,64,128,0,1,2,4,8,16,32,64,96,45,1,1,250,90,92,46,38,64,128,0,1,2,
101,9,8,208,203,234,135,106,242,11,8,196,4,232,249,167,80,5,181,8,120,95,212,210,41,117,18,32,64,128,0,1,2,4,8,16,32,64,128,0,129,121,5,4,232,243,122,91,141,0,1,2,4,8,140,42,32,64,31,149,211,195,26,16,
16,136,9,208,27,24,99,91,152,73,192,251,98,38,104,203,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,202,4,4,232,149,53,76,185,4,8,16,32,64,224,174,128,0,221,60,16,24,10,8,196,4,232,254,78,16,88,85,192,251,
98,85,41,215,17,32,64,128,0,1,2,4,8,16,32,64,128,0,129,190,4,4,232,125,245,219,110,9,16,32,64,160,49,1,1,122,99,13,181,157,100,1,129,152,0,61,121,136,60,160,27,1,239,139,110,90,109,163,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,96,45,1,1,250,90,92,46,38,64,128,0,1,2,101,9,8,208,203,234,135,106,242,11,8,196,4,232,249,167,80,5,181,8,120,95,212,210,41,117,18,32,64,128,0,1,2,4,8,16,32,64,128,0,129,121,5,4,232,
243,122,91,141,0,1,2,4,8,140,42,32,64,31,149,211,195,26,16,16,136,9,208,27,24,99,91,152,73,192,251,98,38,104,203,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,202,4,4,232,149,53,76,185,4,8,16,32,64,224,174,
128,0,221,60,16,24,10,8,196,4,232,254,78,16,88,85,192,251,98,85,41,215,17,32,64,128,0,1,2,4,8,16,32,64,128,0,129,190,4,4,232,125,245,219,110,9,16,32,64,160,49,1,1,122,99,13,181,157,100,1,129,152,0,61,
121,136,60,160,27,1,239,139,110,90,109,163,4,8,16,32,64,128,0,1,2,4,8,16,32,64,96,45,1,1,250,90,92,46,38,64,128,0,1,2,101,9,8,208,203,234,135,106,242,11,8,196,4,232,249,167,80,5,181,8,120,95,212,210,41,
117,18,32,64,128,0,1,2,4,8,16,32,64,128,0,129,121,5,4,232,243,122,91,141,0,1,2,4,8,140,42,32,64,31,149,211,195,26,16,16,136,9,208,27,24,99,91,152,73,192,251,98,38,104,203,16,32,64,128,0,1,2,4,8,16,32,
64,128,0,129,202,4,4,232,149,53,76,185,4,8,16,32,64,224,174,128,0,221,60,16,24,10,8,196,4,232,254,78,16,88,85,192,251,98,85,41,215,17,32,64,128,0,1,2,4,8,16,32,64,128,0,129,190,4,4,232,125,245,219,110,
9,16,32,64,160,49,1,1,122,99,13,181,157,100,1,129,152,0,61,121,136,60,160,27,1,239,139,110,90,109,163,4,8,16,32,64,128,0,1,2,4,8,16,32,64,96,45,1,1,250,90,92,46,38,64,128,0,1,2,101,9,8,208,203,234,135,
106,242,11,8,196,4,232,249,167,80,5,181,8,120,95,212,210,41,117,18,32,64,128,0,1,2,4,8,16,32,64,128,0,129,121,5,4,232,243,122,91,141,0,1,2,4,8,140,42,32,64,31,149,211,195,26,16,16,136,9,208,27,24,99,91,
152,73,192,251,98,38,104,203,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,202,4,4,232,149,53,76,185,4,8,16,32,64,224,174,128,0,221,60,16,24,10,8,196,4,232,254,78,16,88,85,192,251,98,85,41,215,17,32,64,128,
0,1,2,4,8,16,32,64,128,0,129,190,4,4,232,125,245,219,110,9,16,32,64,160,49,1,1,122,99,13,181,157,100,1,129,152,0,61,121,136,60,160,27,1,239,139,110,90,109,163,4,8,16,32,64,128,0,1,2,4,8,16,32,64,96,45,
1,1,250,90,92,46,38,64,128,0,1,2,101,9,8,208,203,234,135,106,242,11,8,196,4,232,249,167,80,5,181,8,120,95,212,210,41,117,18,32,64,128,0,1,2,4,8,16,32,64,128,0,129,121,5,4,232,243,122,91,141,0,1,2,4,8,
140,42,32,64,31,149,211,195,26,16,16,136,9,208,27,24,99,91,152,73,192,251,98,38,104,203,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,202,4,4,232,149,53,76,185,4,8,16,32,64,224,174,128,0,221,60,16,24,10,8,
196,4,232,254,78,16,88,85,192,251,98,85,41,215,17,32,64,128,0,1,2,4,8,16,32,64,128,0,129,190,4,4,232,125,245,219,110,9,16,32,64,160,49,1,1,122,99,13,181,157,100,1,129,152,0,61,121,136,60,160,27,1,239,
139,110,90,109,163,4,8,16,32,64,128,0,1,2,4,8,16,32,64,96,45,1,1,250,90,92,46,38,64,128,0,1,2,101,9,8,208,203,234,135,106,242,11,8,196,4,232,249,167,80,5,181,8,120,95,212,210,41,117,18,32,64,128,0,1,2,
4,8,16,32,64,128,0,129,121,5,4,232,243,122,91,141,0,1,2,4,8,140,42,32,64,31,149,211,195,26,16,16,136,9,208,27,24,99,91,152,73,192,251,98,38,104,203,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,202,4,4,232,
149,53,76,185,4,8,16,32,64,224,174,128,0,221,60,16,24,10,8,196,4,232,254,78,16,88,85,192,251,98,85,41,215,17,32,64,128,0,1,2,4,8,16,32,64,128,0,129,190,4,4,232,125,245,219,110,9,16,32,64,160,49,1,1,122,
99,13,181,157,100,1,129,152,0,61,121,136,60,160,27,1,239,139,110,90,109,163,4,8,16,32,64,128,0,1,2,4,8,16,32,64,96,45,1,1,250,90,92,46,38,64,128,0,1,2,101,9,8,208,203,234,135,106,242,11,8,196,4,232,249,
167,80,5,181,8,120,95,212,210,41,117,18,32,64,128,0,1,2,4,8,16,32,64,128,0,129,121,5,4,232,243,122,91,141,0,1,2,4,8,140,42,32,64,31,149,211,195,26,16,16,136,9,208,27,24,99,91,152,73,192,251,98,38,104,
203,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,202,4,4,232,149,53,76,185,4,8,16,32,64,224,174,128,0,221,60,16,24,10,8,196,4,232,254,78,16,88,85,192,251,98,85,41,215,17,32,64,128,0,1,2,4,8,16,32,64,128,
0,129,190,4,4,232,125,245,219,110,9,16,32,64,160,49,1,1,122,99,13,181,157,100,1,129,152,0,61,121,136,60,160,27,1,239,139,110,90,109,163,4,8,16,32,64,128,0,1,2,4,8,16,32,64,96,45,1,1,250,90,92,46,38,64,
128,0,1,2,101,9,8,208,203,234,135,106,242,11,8,196,4,232,249,167,80,5,181,8,120,95,212,210,41,117,18,32,64,128,0,1,2,4,8,16,32,64,128,0,129,121,5,4,232,243,122,91,141,0,1,2,4,8,140,42,32,64,31,149,211,
195,26,16,16,136,9,208,27,24,99,91,152,73,192,251,98,38,104,203,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,202,4,4,232,149,53,76,185,4,8,16,32,64,224,174,128,0,221,60,16,24,10,8,196,4,232,254,78,16,88,
85,192,251,98,85,41,215,17,32,64,128,0,1,2,4,8,16,32,64,128,0,129,190,4,4,232,125,245,219,110,9,16,32,64,160,49,1,1,122,99,13,181,157,100,1,129,152,0,61,121,136,60,160,27,1,239,139,110,90,109,163,4,8,
16,32,64,128,0,1,2,4,8,16,32,64,96,45,1,1,250,90,92,46,38,64,128,0,1,2,101,9,8,208,203,234,135,106,242,11,8,196,4,232,249,167,80,5,181,8,120,95,212,210,41,117,18,32,64,128,0,1,2,4,8,16,32,64,128,0,129,
121,5,4,232,243,122,91,141,0,1,2,4,8,140,42,32,64,31,149,211,195,26,16,16,136,9,208,27,24,99,91,152,73,192,251,98,38,104,203,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,202,4,4,232,149,53,76,185,4,8,16,
32,64,224,174,128,0,221,60,16,24,10,8,196,4,232,254,78,16,88,85,192,251,98,85,41,215,17,32,64,128,0,1,2,4,8,16,32,64,128,0,129,190,4,4,232,125,245,219,110,9,16,32,64,160,49,1,1,122,99,13,181,157,100,1,
129,152,0,61,121,136,60,160,27,1,239,139,110,90,109,163,4,8,16,32,64,128,0,1,2,4,8,16,32,64,96,45,1,1,250,90,92,46,38,64,128,0,1,2,101,9,8,208,203,234,135,106,242,11,8,196,4,232,249,167,80,5,181,8,120,
95,212,210,41,117,18,32,64,128,0,1,2,4,8,16,32,64,128,0,129,121,5,4,232,243,122,91,141,0,1,2,4,8,140,42,32,64,31,149,211,195,26,16,16,136,9,208,27,24,99,91,152,73,192,251,98,38,104,203,16,32,64,128,0,
1,2,4,8,16,32,64,128,0,129,202,4,4,232,149,53,76,185,4,8,16,32,64,224,174,128,0,221,60,16,24,10,8,196,4,232,254,78,16,88,85,192,251,98,85,41,215,17,32,64,128,0,1,2,4,8,16,32,64,128,0,129,190,4,4,232,125,
245,219,110,9,16,32,64,160,49,1,1,122,99,13,181,157,100,1,129,152,0,61,121,136,60,160,27,1,239,139,110,90,109,163,4,8,16,32,64,224,255,216,187,163,227,184,142,44,93,212,0,56,156,215,203,182,224,176,61,
32,131,36,34,248,116,36,11,134,180,96,36,11,174,218,2,117,91,160,110,11,36,15,200,177,64,60,79,140,24,80,1,30,11,154,215,2,241,190,182,26,56,55,139,64,223,80,65,218,172,172,170,220,153,43,51,63,69,40,
52,51,220,149,185,242,91,171,114,4,252,42,128,0,1,2,4,8,16,32,64,96,47,1,1,250,94,92,30,38,64,128,0,1,2,177,4,4,232,177,250,161,154,246,2,2,49,1,122,251,41,84,65,47,2,238,139,94,58,165,78,2,4,8,16,32,
64,128,0,1,2,4,8,16,32,80,87,64,128,94,215,219,110,4,8,16,32,64,160,168,128,0,189,40,167,197,6,16,16,136,9,208,7,24,99,71,168,36,224,190,168,4,109,27,2,4,8,16,32,64,128,0,1,2,4,8,16,32,208,153,128,0,189,
179,134,41,151,0,1,2,4,8,252,90,64,128,110,30,8,108,11,8,196,4,232,222,19,4,114,5,220,23,185,82,158,35,64,128,0,1,2,4,8,204,43,176,249,190,203,47,191,252,242,240,236,236,236,97,250,247,199,205,63,255,
199,230,159,73,228,193,173,202,230,159,255,250,123,94,168,122,39,255,152,182,250,245,223,39,169,31,255,59,253,253,225,244,244,244,195,63,255,249,207,15,207,159,63,255,80,175,28,59,17,32,48,170,128,0,125,
212,206,58,23,1,2,4,8,76,33,32,64,159,162,205,14,185,135,128,64,108,25,235,191,255,251,191,31,165,111,246,92,238,193,233,81,2,67,11,184,47,134,110,175,195,17,32,64,128,0,1,2,4,14,18,184,253,62,203,23,
41,140,253,159,233,223,23,191,72,139,60,76,127,255,43,44,63,104,77,47,106,34,240,122,19,172,167,157,223,60,123,246,236,77,147,10,108,74,128,64,215,2,2,244,174,219,167,120,2,4,8,16,152,93,64,128,62,251,
4,56,255,93,1,129,216,242,76,8,208,189,95,8,108,11,184,47,76,4,1,2,4,8,16,32,64,128,192,70,224,226,226,226,139,244,143,77,104,254,31,233,159,143,168,12,41,240,41,80,79,159,80,255,193,39,212,135,236,175,
67,17,40,46,32,64,47,78,106,65,2,4,8,16,32,80,79,64,128,94,207,218,78,125,8,8,196,150,251,36,64,239,99,134,85,89,79,192,125,81,207,218,78,4,8,16,32,64,128,0,129,104,2,111,223,190,125,248,111,255,246,111,
95,9,205,163,117,166,74,61,175,175,175,175,255,235,252,252,252,135,42,187,217,132,0,129,46,5,4,232,93,182,77,209,4,8,16,32,64,224,70,64,128,110,18,8,108,11,8,196,150,39,66,128,238,221,66,192,125,97,6,
8,16,32,64,128,0,1,2,179,11,108,62,109,158,66,243,239,146,131,79,154,207,62,12,233,252,105,22,254,250,143,127,252,227,111,62,149,110,24,8,16,184,43,32,64,55,19,4,8,16,32,64,160,99,1,1,122,199,205,83,250,
42,2,2,116,1,250,42,131,101,209,33,5,220,23,67,182,213,161,8,16,32,64,128,0,1,2,191,17,216,124,239,36,253,232,238,71,130,115,195,177,36,144,102,227,135,20,164,255,69,144,110,70,8,16,248,151,128,0,221,
44,16,32,64,128,0,129,142,5,4,232,29,55,79,233,171,8,8,196,4,232,171,12,150,69,135,20,112,95,12,217,86,135,34,64,128,0,1,2,4,8,108,9,188,123,247,238,69,250,63,124,155,254,246,137,115,179,145,35,240,250,
151,95,126,249,147,32,61,135,202,51,4,198,22,16,160,143,221,95,167,35,64,128,0,129,193,5,4,232,131,55,216,241,246,22,16,136,9,208,247,30,26,47,152,86,192,125,49,109,235,29,156,0,1,2,4,8,16,152,64,224,
246,87,88,109,130,243,77,128,238,47,2,123,9,108,126,180,251,147,39,79,254,180,215,139,60,76,128,192,80,2,2,244,161,218,233,48,4,8,16,32,48,155,128,0,125,182,142,59,239,46,1,129,216,178,144,223,129,190,
107,122,252,249,108,2,238,139,217,58,238,188,4,8,16,32,64,128,192,12,2,155,239,147,92,95,95,127,155,254,93,239,171,116,222,7,51,156,217,25,87,19,248,152,102,233,79,231,231,231,63,172,182,131,133,9,16,
8,43,32,64,15,219,26,133,17,32,64,128,0,129,221,2,2,244,221,70,158,152,75,64,32,182,220,111,1,250,92,239,5,167,221,45,224,190,216,109,228,9,2,4,8,16,32,64,128,64,79,2,23,23,23,95,164,79,14,127,159,106,
126,216,83,221,106,13,47,240,230,222,189,123,47,31,63,126,252,49,124,165,10,36,64,160,152,128,0,189,24,165,133,8,16,32,64,128,64,125,1,1,122,125,115,59,198,22,16,136,45,247,71,128,30,123,118,85,87,95,
192,125,81,223,220,142,4,8,16,32,64,128,0,129,181,4,82,120,254,77,10,207,55,63,178,221,167,206,215,66,158,123,221,143,233,235,135,151,207,158,61,123,51,55,131,211,19,152,71,64,128,62,79,175,157,148,0,
1,2,4,6,20,16,160,15,216,84,71,58,74,64,32,38,64,63,106,128,188,120,42,1,247,197,84,237,118,88,2,4,8,16,32,64,96,80,129,219,239,139,108,62,117,238,119,157,15,218,227,72,199,74,95,67,252,37,133,232,127,
142,84,147,90,8,16,88,71,64,128,190,142,171,85,9,16,32,64,128,64,21,1,1,122,21,102,155,116,36,32,16,91,110,150,79,160,119,52,200,74,173,34,224,190,168,194,108,19,2,4,8,16,32,64,128,192,106,2,183,95,227,
188,74,27,60,92,109,19,11,19,248,173,192,155,167,79,159,126,9,134,0,129,177,5,4,232,99,247,215,233,8,16,32,64,96,112,1,1,250,224,13,118,188,189,5,4,98,203,100,2,244,189,199,201,11,6,23,112,95,12,222,96,
199,35,64,128,0,1,2,4,134,22,184,253,125,231,155,240,220,143,108,31,186,211,97,15,247,62,253,94,244,47,253,94,244,176,253,81,24,129,163,5,4,232,71,19,90,128,0,1,2,4,8,180,19,16,160,183,179,183,115,76,
1,129,152,0,61,230,100,170,42,162,128,251,34,98,87,212,68,128,0,1,2,4,8,16,216,45,144,254,227,224,175,206,206,206,190,19,158,239,182,242,196,170,2,31,174,175,175,95,158,159,159,191,95,117,23,139,19,32,
208,68,64,128,222,132,221,166,4,8,16,32,64,160,140,128,0,189,140,163,85,198,17,16,136,45,247,210,39,208,199,153,115,39,41,35,224,190,40,227,104,21,2,4,8,16,32,64,128,64,77,129,244,201,243,111,78,79,79,
191,77,123,250,228,121,77,120,123,45,9,124,76,33,250,151,66,116,3,66,96,60,1,1,250,120,61,117,34,2,4,8,16,152,72,64,128,62,81,179,29,53,75,64,32,38,64,207,26,20,15,17,72,2,238,11,99,64,128,0,1,2,4,8,16,
232,75,224,54,60,223,124,242,220,95,4,34,9,8,209,35,117,67,45,4,10,9,8,208,11,65,90,134,0,1,2,4,8,180,16,16,160,183,80,183,103,100,1,129,216,114,119,124,2,61,242,228,170,173,133,128,251,162,133,186,61,
9,16,32,64,128,0,1,2,135,9,188,123,247,238,69,122,229,247,233,111,159,60,63,140,208,171,214,21,248,152,126,39,250,31,253,78,244,117,145,173,78,160,166,128,0,189,166,182,189,8,16,32,64,128,64,97,1,1,122,
97,80,203,117,47,32,16,91,110,161,0,189,251,241,118,128,194,2,238,139,194,160,150,35,64,128,0,1,2,4,8,172,36,112,251,181,204,143,105,121,225,249,74,198,150,45,34,240,254,233,211,167,143,139,172,100,17,
2,4,154,11,8,208,155,183,64,1,4,8,16,32,64,224,112,1,1,250,225,118,94,57,166,128,64,108,185,175,2,244,49,103,222,169,14,23,112,95,28,110,231,149,4,8,16,32,64,128,0,129,90,2,111,223,190,125,120,255,254,
253,203,180,159,240,188,22,186,125,142,17,120,147,66,244,47,143,89,192,107,9,16,136,33,32,64,143,209,7,85,16,32,64,128,0,129,131,4,4,232,7,177,121,209,192,2,2,177,229,230,10,208,7,30,124,71,59,72,192,
125,113,16,155,23,17,32,64,128,0,1,2,4,170,9,220,126,207,227,85,218,240,139,106,155,218,136,192,145,2,167,167,167,63,60,121,242,228,235,35,151,241,114,2,4,26,11,8,208,27,55,192,246,4,8,16,32,64,224,24,
1,1,250,49,122,94,59,162,128,64,108,185,171,2,244,17,39,222,153,142,17,112,95,28,163,231,181,4,8,16,32,64,128,0,129,245,5,126,250,233,167,239,210,191,179,125,179,254,78,118,32,80,92,224,101,250,36,250,
235,226,171,90,144,0,129,106,2,2,244,106,212,54,34,64,128,0,1,2,229,5,4,232,229,77,173,216,183,128,64,108,185,127,2,244,190,103,91,245,229,5,220,23,229,77,173,72,128,0,1,2,4,8,16,40,37,144,190,126,249,
234,236,236,236,251,82,235,89,135,64,101,129,143,191,252,242,203,227,231,207,159,127,168,188,175,237,8,16,40,36,32,64,47,4,105,25,2,4,8,16,32,208,66,64,128,222,66,221,158,145,5,4,98,203,221,17,160,71,
158,92,181,181,16,112,95,180,80,183,39,1,2,4,8,16,32,64,96,183,128,223,123,190,219,200,19,93,8,188,79,159,66,127,220,69,165,138,36,64,224,55,2,2,116,67,65,128,0,1,2,4,58,22,16,160,119,220,60,165,175,34,
32,16,19,160,175,50,88,22,29,82,192,125,49,100,91,29,138,0,1,2,4,8,16,24,64,224,221,187,119,155,223,123,254,98,128,163,56,194,228,2,190,230,152,124,0,28,191,107,1,1,122,215,237,83,60,1,2,4,8,204,46,32,
64,159,125,2,156,255,174,128,47,78,5,232,222,21,4,114,5,220,23,185,82,158,35,64,128,0,1,2,4,8,212,19,72,225,249,38,56,223,4,232,254,34,48,130,128,31,229,62,66,23,157,97,74,1,1,250,148,109,119,104,2,4,
8,16,24,69,64,128,62,74,39,157,163,148,128,64,108,89,210,143,112,47,53,101,214,25,69,192,125,49,74,39,157,131,0,1,2,4,8,16,24,69,224,246,123,28,63,166,243,60,26,229,76,206,65,32,9,188,78,63,202,253,37,
9,2,4,250,18,16,160,247,213,47,213,18,32,64,128,0,129,45,1,1,186,129,32,176,45,32,16,91,158,8,1,186,119,11,1,247,133,25,32,64,128,0,1,2,4,8,68,22,184,184,184,248,243,233,233,233,183,145,107,84,27,129,
3,5,94,166,16,253,245,129,175,245,50,2,4,26,8,8,208,27,160,219,146,0,1,2,4,8,148,18,16,160,151,146,180,206,40,2,2,244,229,78,10,208,71,153,114,231,40,37,224,190,40,37,105,29,2,4,8,16,32,64,128,192,241,
2,111,223,190,125,120,255,254,253,203,180,210,131,227,87,179,2,129,112,2,31,82,128,254,199,112,85,41,136,0,129,69,1,1,186,225,32,64,128,0,1,2,29,11,8,208,59,110,158,210,87,17,16,136,45,179,10,208,87,25,
57,139,118,44,224,190,232,184,121,74,39,64,128,0,1,2,4,134,19,240,233,243,225,90,234,64,119,4,174,175,175,191,62,63,63,255,1,12,1,2,125,8,8,208,251,232,147,42,9,16,32,64,128,192,239,10,8,208,13,6,129,
109,1,129,152,0,221,123,130,64,174,128,251,34,87,202,115,4,8,16,32,64,128,0,129,117,5,110,191,183,241,247,180,139,79,159,175,75,109,245,182,2,62,133,222,214,223,238,4,246,18,16,160,239,197,229,97,2,4,
8,16,32,16,75,64,128,30,171,31,170,105,47,32,16,91,238,129,79,160,183,159,79,21,196,18,112,95,196,57,17,72,167,0,0,32,0,73,68,65,84,234,135,106,8,16,32,64,128,0,129,121,5,124,250,124,222,222,79,120,114,
191,11,125,194,166,59,114,159,2,2,244,62,251,166,106,2,4,8,16,32,240,73,64,128,110,16,8,108,11,8,196,4,232,222,19,4,114,5,220,23,185,82,158,35,64,128,0,1,2,4,8,172,39,224,211,231,235,217,90,57,164,192,
251,244,187,208,31,135,172,76,81,4,8,108,9,8,208,13,4,1,2,4,8,16,232,88,64,128,222,113,243,148,190,138,128,64,76,128,190,202,96,89,116,72,1,247,197,144,109,117,40,2,4,8,16,32,64,160,51,129,244,233,243,
111,78,79,79,191,235,172,108,229,18,56,88,224,151,95,126,249,227,243,231,207,63,28,188,128,23,18,32,80,69,64,128,94,133,217,38,4,8,16,32,64,96,29,1,1,250,58,174,86,237,87,64,32,182,220,59,63,194,189,223,
185,86,249,58,2,238,139,117,92,173,74,128,0,1,2,4,8,16,216,71,224,221,187,119,63,166,231,191,216,231,53,158,37,208,179,64,250,15,70,254,250,228,201,147,63,245,124,6,181,19,152,65,64,128,62,67,151,157,
145,0,1,2,4,134,21,16,160,15,219,90,7,59,80,64,32,182,12,39,64,63,112,168,188,108,88,1,247,197,176,173,117,48,2,4,8,16,32,64,160,19,1,95,163,116,210,40,101,150,22,248,152,126,140,251,31,74,47,106,61,2,
4,202,10,8,208,203,122,90,141,0,1,2,4,8,84,21,16,160,87,229,182,89,7,2,2,49,1,122,7,99,170,196,32,2,238,139,32,141,80,6,1,2,4,8,16,32,48,173,64,250,241,237,127,78,159,198,253,118,90,0,7,159,89,224,101,
10,209,95,207,12,224,236,4,162,11,8,208,163,119,72,125,4,8,16,32,64,224,51,2,2,116,227,65,96,91,64,32,38,64,247,158,32,144,43,224,190,200,149,242,28,1,2,4,8,16,32,64,96,29,129,244,227,219,255,158,86,126,
184,206,234,86,37,16,87,32,253,135,35,63,164,31,227,254,117,220,10,85,70,128,128,0,221,12,16,32,64,128,0,129,142,5,4,232,29,55,79,233,171,8,8,196,150,89,253,120,196,85,70,206,162,29,11,184,47,58,110,158,
210,9,16,32,64,128,0,129,238,5,124,125,210,125,11,29,224,56,1,63,198,253,56,63,175,38,176,186,128,0,125,117,98,27,16,32,64,128,0,129,245,4,4,232,235,217,90,185,79,1,129,152,0,189,207,201,85,117,11,1,247,
69,11,117,123,18,32,64,128,0,1,2,4,110,4,210,143,111,255,38,125,10,247,59,30,4,102,21,248,229,151,95,254,248,252,249,243,15,179,158,223,185,9,68,23,16,160,71,239,144,250,8,16,32,64,128,192,103,4,4,232,
198,131,192,182,128,64,108,121,34,124,194,195,187,133,128,251,194,12,16,32,64,128,0,1,2,4,162,8,164,31,223,254,42,213,242,34,74,61,234,32,80,91,192,247,47,106,139,219,143,192,126,2,2,244,253,188,60,77,
128,0,1,2,4,66,9,8,208,67,181,67,49,1,4,124,1,186,220,4,1,122,128,1,85,66,40,1,247,69,168,118,40,134,0,1,2,4,8,16,152,76,192,239,63,159,172,225,142,251,123,2,175,159,62,125,250,18,13,1,2,49,5,4,232,49,
251,162,42,2,4,8,16,32,144,37,32,64,207,98,242,208,68,2,2,49,1,250,68,227,238,168,71,10,184,47,142,4,244,114,2,4,8,16,32,64,128,192,129,2,254,227,222,3,225,188,108,52,1,191,7,125,180,142,58,207,80,2,2,
244,161,218,233,48,4,8,16,32,48,155,128,0,125,182,142,59,239,46,1,129,152,0,125,215,140,248,115,2,255,18,112,95,152,5,2,4,8,16,32,64,128,64,27,129,20,160,127,117,118,118,246,125,155,221,237,74,32,142,
128,223,131,30,167,23,42,33,112,87,64,128,110,38,8,16,32,64,128,64,199,2,2,244,142,155,167,244,85,4,4,98,2,244,85,6,203,162,67,10,184,47,134,108,171,67,17,32,64,128,0,1,2,29,8,92,92,92,124,115,122,122,
250,93,7,165,42,145,192,170,2,233,107,146,47,159,61,123,246,102,213,77,44,78,128,192,65,2,2,244,131,216,188,136,0,1,2,4,8,196,16,16,160,199,232,131,42,226,8,8,196,150,123,225,199,36,198,153,83,149,196,
16,112,95,196,232,131,42,8,16,32,64,128,0,129,249,4,210,239,63,127,149,78,253,98,190,147,59,49,129,109,1,95,147,152,8,2,113,5,4,232,113,123,163,50,2,4,8,16,32,176,83,64,128,190,147,200,3,147,9,248,226,
83,128,62,217,200,59,238,17,2,238,139,35,240,188,148,0,1,2,4,8,16,32,112,132,64,10,208,255,158,94,254,240,136,37,188,148,192,40,2,175,159,62,125,250,114,148,195,56,7,129,145,4,4,232,35,117,211,89,8,16,
32,64,96,58,1,1,250,116,45,119,224,29,2,2,177,101,32,159,64,247,246,33,176,45,224,190,48,17,4,8,16,32,64,128,0,129,54,2,2,244,54,238,118,13,41,240,38,5,232,95,134,172,76,81,4,38,23,16,160,79,62,0,142,
79,128,0,1,2,125,11,8,208,251,238,159,234,203,11,8,196,4,232,229,167,202,138,163,10,184,47,70,237,172,115,17,32,64,128,0,1,2,145,5,222,190,125,251,240,254,253,251,155,79,160,251,139,0,129,147,147,143,
41,64,255,3,8,2,4,226,9,8,208,227,245,68,69,4,8,16,32,64,32,91,64,128,158,77,229,193,73,4,4,98,203,141,246,9,244,73,222,4,142,153,45,224,190,200,166,242,32,1,2,4,8,16,32,64,160,152,128,0,189,24,165,133,
198,16,16,160,143,209,71,167,24,80,64,128,62,96,83,29,137,0,1,2,4,230,17,16,160,207,211,107,39,205,19,16,136,9,208,243,38,197,83,4,78,78,220,23,166,128,0,1,2,4,8,16,32,80,95,192,127,216,91,223,220,142,
177,5,210,39,208,229,116,177,91,164,186,73,5,188,49,39,109,188,99,19,32,64,128,192,24,2,2,244,49,250,232,20,229,4,4,98,2,244,114,211,100,165,209,5,220,23,163,119,216,249,8,16,32,64,128,0,129,136,2,23,
23,23,95,156,158,158,254,24,177,54,53,17,104,33,112,239,222,189,63,60,126,252,248,99,139,189,237,73,128,192,178,128,0,221,116,16,32,64,128,0,129,142,5,4,232,29,55,79,233,171,8,8,196,4,232,171,12,150,69,
135,20,112,95,12,217,86,135,34,64,128,0,1,2,4,130,11,8,208,131,55,72,121,213,5,4,232,213,201,109,72,32,75,64,128,158,197,228,33,2,4,8,16,32,16,83,64,128,30,179,47,170,106,39,32,16,19,160,183,155,62,59,
247,38,224,190,232,173,99,234,37,64,128,0,1,2,4,70,16,72,63,194,253,171,179,179,179,239,71,56,139,51,16,40,33,240,203,47,191,252,241,249,243,231,31,74,172,101,13,2,4,202,9,8,208,203,89,90,137,0,1,2,4,
8,84,23,16,160,87,39,183,97,112,1,129,216,114,131,252,174,193,224,195,171,188,234,2,238,139,234,228,54,36,64,128,0,1,2,4,8,156,8,208,13,1,129,109,1,1,186,137,32,16,83,64,128,30,179,47,170,34,64,128,0,
1,2,89,2,2,244,44,38,15,77,36,32,16,19,160,79,52,238,142,122,164,128,251,226,72,64,47,39,64,128,0,1,2,4,8,28,32,32,64,63,0,205,75,134,22,16,160,15,221,94,135,235,88,64,128,222,113,243,148,78,128,0,1,2,
4,4,232,102,128,192,182,128,64,76,128,238,61,65,32,87,192,125,145,43,229,57,2,4,8,16,32,64,128,64,57,1,1,122,57,75,43,141,33,32,64,31,163,143,78,49,158,128,0,125,188,158,58,17,1,2,4,8,76,36,32,64,159,
168,217,142,154,37,32,16,19,160,103,13,138,135,8,36,1,247,133,49,32,64,128,0,1,2,4,8,212,23,16,160,215,55,183,99,108,1,1,122,236,254,168,110,94,1,1,250,188,189,119,114,2,4,8,16,24,64,64,128,62,64,19,29,
161,168,128,64,76,128,94,116,160,44,54,180,128,251,98,232,246,58,28,1,2,4,8,16,32,16,84,64,128,30,180,49,202,106,38,32,64,111,70,111,99,2,159,21,16,160,27,16,2,4,8,16,32,208,177,128,0,189,227,230,41,125,
21,1,129,152,0,125,149,193,178,232,144,2,238,139,33,219,234,80,4,8,16,32,64,128,64,112,1,1,122,240,6,41,175,186,128,0,189,58,185,13,9,100,9,8,208,179,152,60,68,128,0,1,2,4,98,10,8,208,99,246,69,85,237,
4,4,98,2,244,118,211,103,231,222,4,220,23,189,117,76,189,4,8,16,32,64,128,192,8,2,2,244,17,186,232,12,37,5,4,232,37,53,173,69,160,156,128,0,189,156,165,149,8,16,32,64,128,64,117,1,1,122,117,114,27,6,23,
16,136,9,208,131,143,168,242,2,9,184,47,2,53,67,41,4,8,16,32,64,128,192,52,2,2,244,105,90,237,160,153,2,2,244,76,40,143,17,168,44,32,64,175,12,110,59,2,4,8,16,32,80,82,64,128,94,82,211,90,35,8,8,196,4,
232,35,204,177,51,212,17,112,95,212,113,182,11,1,2,4,8,16,32,64,224,215,2,2,116,243,64,96,91,64,128,110,34,8,196,20,16,160,199,236,139,170,8,16,32,64,128,64,150,128,0,61,139,201,67,19,9,8,196,4,232,19,
141,187,163,30,41,224,190,56,18,208,203,9,16,32,64,128,0,1,2,7,8,8,208,15,64,243,146,161,5,4,232,67,183,215,225,58,22,16,160,119,220,60,165,19,32,64,128,0,1,1,186,25,32,176,45,32,16,19,160,123,79,16,200,
21,112,95,228,74,121,142,0,1,2,4,8,16,32,80,78,64,128,94,206,210,74,99,8,8,208,199,232,163,83,140,39,32,64,31,175,167,78,68,128,0,1,2,19,9,8,208,39,106,182,163,102,9,8,196,4,232,89,131,226,33,2,73,192,
125,97,12,8,16,32,64,128,0,1,2,245,5,4,232,245,205,237,24,91,64,128,30,187,63,170,155,87,64,128,62,111,239,157,156,0,1,2,4,6,16,16,160,15,208,68,71,40,42,32,16,19,160,23,29,40,139,13,45,224,190,24,186,
189,14,71,128,0,1,2,4,8,4,21,16,160,7,109,140,178,154,9,8,208,155,209,219,152,192,103,5,4,232,6,132,0,1,2,4,8,116,44,32,64,239,184,121,74,95,69,64,32,38,64,95,101,176,44,58,164,128,251,98,200,182,58,20,
1,2,4,8,16,32,16,92,64,128,30,188,65,202,171,46,32,64,175,78,110,67,2,89,2,2,244,44,38,15,17,32,64,128,0,129,152,2,2,244,152,125,81,85,59,1,129,152,0,189,221,244,217,185,55,1,247,69,111,29,83,47,1,2,4,
8,16,32,48,130,128,0,125,132,46,58,67,73,1,1,122,73,77,107,17,40,39,32,64,47,103,105,37,2,4,8,16,32,80,93,64,128,94,157,220,134,193,5,4,98,2,244,224,35,170,188,64,2,238,139,64,205,80,10,1,2,4,8,16,32,
48,141,128,0,125,154,86,59,104,166,128,0,61,19,202,99,4,42,11,8,208,43,131,219,142,0,1,2,4,8,148,20,16,160,151,212,180,214,8,2,2,49,1,250,8,115,236,12,117,4,220,23,117,156,237,66,128,0,1,2,4,8,16,248,
181,128,0,221,60,16,216,22,16,160,155,8,2,49,5,4,232,49,251,162,42,2,4,8,16,32,144,37,32,64,207,98,242,208,68,2,2,49,1,250,68,227,238,168,71,10,184,47,142,4,244,114,2,4,8,16,32,64,128,192,1,2,2,244,3,
208,188,100,104,1,1,250,208,237,117,184,142,5,4,232,29,55,79,233,4,8,16,32,64,64,128,110,6,8,108,11,8,196,4,232,222,19,4,114,5,220,23,185,82,158,35,64,128,0,1,2,4,8,148,19,16,160,151,179,180,210,24,2,
2,244,49,250,232,20,227,9,8,208,199,235,169,19,17,32,64,128,192,68,2,2,244,137,154,237,168,89,2,2,49,1,122,214,160,120,136,64,18,112,95,24,3,2,4,8,16,32,64,128,64,125,1,1,122,125,115,59,198,22,16,160,
199,238,143,234,230,21,16,160,207,219,123,39,39,64,128,0,129,1,4,4,232,3,52,209,17,138,10,8,196,4,232,69,7,202,98,67,11,184,47,134,110,175,195,17,32,64,128,0,1,2,65,5,4,232,65,27,163,172,102,2,2,244,102,
244,54,38,240,89,1,1,186,1,33,64,128,0,1,2,29,11,8,208,59,110,158,210,87,17,16,136,9,208,87,25,44,139,14,41,224,190,24,178,173,14,69,128,0,1,2,4,8,4,23,16,160,7,111,144,242,170,11,8,208,171,147,219,144,
64,150,128,0,61,139,201,67,4,8,16,32,64,32,166,128,0,61,102,95,84,213,78,64,32,38,64,111,55,125,118,238,77,192,125,209,91,199,212,75,128,0,1,2,4,8,140,32,32,64,31,161,139,206,80,82,64,128,94,82,211,90,
4,202,9,8,208,203,89,90,137,0,1,2,4,8,84,23,16,160,87,39,183,97,112,1,129,152,0,61,248,136,42,47,144,128,251,34,80,51,148,66,128,0,1,2,4,8,76,35,32,64,159,166,213,14,154,41,32,64,207,132,242,24,129,202,
2,2,244,202,224,182,35,64,128,0,1,2,37,5,4,232,37,53,173,53,130,128,64,76,128,62,194,28,59,67,29,1,247,69,29,103,187,16,32,64,128,0,1,2,4,126,45,32,64,55,15,4,182,5,4,232,38,130,64,76,1,1,122,204,190,
168,138,0,1,2,4,8,100,9,8,208,179,152,60,52,145,128,64,76,128,62,209,184,59,234,145,2,238,139,35,1,189,156,0,1,2,4,8,16,32,112,128,128,0,253,0,52,47,25,90,64,128,62,116,123,29,174,99,1,1,122,199,205,83,
58,1,2,4,8,16,16,160,155,1,2,219,2,2,49,1,186,247,4,129,92,1,247,69,174,148,231,8,16,32,64,128,0,1,2,229,4,4,232,229,44,173,52,134,128,0,125,140,62,58,197,120,2,2,244,241,122,234,68,4,8,16,32,48,145,128,
0,125,162,102,59,106,150,128,64,76,128,158,53,40,30,34,144,4,220,23,198,128,0,1,2,4,8,16,32,80,95,64,128,94,223,220,142,177,5,4,232,177,251,163,186,121,5,4,232,243,246,222,201,9,16,32,64,96,0,1,1,250,
0,77,116,132,162,2,2,49,1,122,209,129,178,216,208,2,238,139,161,219,235,112,4,8,16,32,64,128,64,80,1,1,122,208,198,40,171,153,128,0,189,25,189,141,9,124,86,64,128,110,64,8,16,32,64,128,64,199,2,2,244,
142,155,167,244,85,4,4,98,2,244,85,6,203,162,67,10,184,47,134,108,171,67,17,32,64,128,0,1,2,193,5,4,232,193,27,164,188,234,2,2,244,234,228,54,36,144,37,32,64,207,98,242,16,1,2,4,8,16,136,41,32,64,143,
217,23,85,181,19,16,136,9,208,219,77,159,157,123,19,112,95,244,214,49,245,18,32,64,128,0,1,2,35,8,8,208,71,232,162,51,148,20,16,160,151,212,180,22,129,114,2,2,244,114,150,86,34,64,128,0,1,2,213,5,4,232,
213,201,109,24,92,64,32,38,64,15,62,162,202,11,36,224,190,8,212,12,165,16,32,64,128,0,1,2,211,8,8,208,167,105,181,131,102,10,8,208,51,161,60,70,160,178,128,0,189,50,184,237,8,16,32,64,128,64,73,1,1,122,
73,77,107,141,32,32,16,19,160,143,48,199,206,80,71,192,125,81,199,217,46,4,8,16,32,64,128,0,129,95,11,8,208,205,3,129,109,1,1,186,137,32,16,83,64,128,30,179,47,170,34,64,128,0,1,2,89,2,2,244,44,38,15,
77,36,32,16,19,160,79,52,238,142,122,164,128,251,226,72,64,47,39,64,128,0,1,2,4,8,28,32,32,64,63,0,205,75,134,22,16,160,15,221,94,135,235,88,64,128,222,113,243,148,78,128,0,1,2,4,4,232,102,128,192,182,
128,64,76,128,238,61,65,32,87,192,125,145,43,229,57,2,4,8,16,32,64,128,64,57,1,1,122,57,75,43,141,33,32,64,31,163,143,78,49,158,128,0,125,188,158,58,17,1,2,4,8,76,36,32,64,159,168,217,142,154,37,32,16,
19,160,103,13,138,135,8,36,1,247,133,49,32,64,128,0,1,2,4,8,212,23,16,160,215,55,183,99,108,1,1,122,236,254,168,110,94,1,1,250,188,189,119,114,2,4,8,16,24,64,64,128,62,64,19,29,161,168,128,64,76,128,94,
116,160,44,54,180,128,251,98,232,246,58,28,1,2,4,8,16,32,16,84,64,128,30,180,49,202,106,38,32,64,111,70,111,99,2,159,21,16,160,27,16,2,4,8,16,32,208,177,128,0,189,227,230,41,125,21,1,129,152,0,125,149,
193,178,232,144,2,238,139,33,219,234,80,4,8,16,32,64,128,64,112,1,1,122,240,6,41,175,186,128,0,189,58,185,13,9,100,9,8,208,179,152,60,68,128,0,1,2,4,98,10,8,208,99,246,69,85,237,4,4,98,2,244,118,211,103,
231,222,4,220,23,189,117,76,189,4,8,16,32,64,128,192,8,2,2,244,17,186,232,12,37,5,4,232,37,53,173,69,160,156,128,0,189,156,165,149,8,16,32,64,128,64,117,1,1,122,117,114,27,6,23,16,136,9,208,131,143,168,
242,2,9,184,47,2,53,67,41,4,8,16,32,64,128,192,52,2,2,244,105,90,237,160,153,2,2,244,76,40,143,17,168,44,32,64,175,12,110,59,2,4,8,16,32,80,82,64,128,94,82,211,90,35,8,8,196,4,232,35,204,177,51,212,17,
112,95,212,113,182,11,1,2,4,8,16,32,64,224,215,2,2,116,243,64,96,91,64,128,110,34,8,196,20,16,160,199,236,139,170,8,16,32,64,128,64,150,128,0,61,139,201,67,19,9,8,196,4,232,19,141,187,163,30,41,224,190,
56,18,208,203,9,16,32,64,128,0,1,2,7,8,8,208,15,64,243,146,161,5,4,232,67,183,215,225,58,22,16,160,119,220,60,165,19,32,64,128,0,1,1,186,25,32,176,45,32,16,19,160,123,79,16,200,21,112,95,228,74,121,142,
0,1,2,4,8,16,32,80,78,64,128,94,206,210,74,99,8,8,208,199,232,163,83,140,39,32,64,31,175,167,78,68,128,0,1,2,19,9,8,208,39,106,182,163,102,9,8,196,4,232,89,131,226,33,2,73,192,125,97,12,8,16,32,64,128,
0,1,2,245,5,4,232,245,205,237,24,91,64,128,30,187,63,170,155,87,64,128,62,111,239,157,156,0,1,2,4,6,16,16,160,15,208,68,71,40,42,32,16,19,160,23,29,40,139,13,45,224,190,24,186,189,14,71,128,0,1,2,4,8,
4,21,16,160,7,109,140,178,154,9,8,208,155,209,219,152,192,103,5,4,232,6,132,0,1,2,4,8,116,44,32,64,239,184,121,74,95,69,64,32,38,64,95,101,176,44,58,164,128,251,98,200,182,58,20,1,2,4,8,16,32,16,92,64,
128,30,188,65,202,171,46,32,64,175,78,110,67,2,89,2,2,244,44,38,15,17,32,64,128,0,129,152,2,2,244,152,125,81,85,59,1,129,152,0,189,221,244,217,185,55,1,247,69,111,29,83,47,1,2,4,8,16,32,48,130,128,0,125,
132,46,58,67,73,1,1,122,73,77,107,17,40,39,32,64,47,103,105,37,2,4,8,16,32,80,93,64,128,94,157,220,134,193,5,4,98,2,244,224,35,170,188,64,2,238,139,64,205,80,10,1,2,4,8,16,32,48,141,128,0,125,154,86,59,
104,166,128,0,61,19,202,99,4,42,11,8,208,43,131,219,142,0,1,2,4,8,148,20,16,160,151,212,180,214,8,2,2,49,1,250,8,115,236,12,117,4,220,23,117,156,237,66,128,0,1,2,4,8,16,248,181,128,0,221,60,16,216,22,
16,160,155,8,2,49,5,4,232,49,251,162,42,2,4,8,16,32,144,37,32,64,207,98,242,208,68,2,2,49,1,250,68,227,238,168,71,10,184,47,142,4,244,114,2,4,8,16,32,64,128,192,1,2,2,244,3,208,188,100,104,1,1,250,208,
237,117,184,142,5,4,232,29,55,79,233,4,8,16,32,64,64,128,110,6,8,108,11,8,196,4,232,222,19,4,114,5,220,23,185,82,158,35,64,128,0,1,2,4,8,148,19,16,160,151,179,180,210,24,2,2,244,49,250,232,20,227,9,8,
208,199,235,169,19,17,32,64,128,192,68,2,2,244,137,154,237,168,89,2,2,49,1,122,214,160,120,136,64,18,112,95,24,3,2,4,8,16,32,64,128,64,125,1,1,122,125,115,59,198,22,16,160,199,238,143,234,230,21,16,160,
207,219,123,39,39,64,128,0,129,1,4,4,232,3,52,209,17,138,10,8,196,4,232,69,7,202,98,67,11,184,47,134,110,175,195,17,32,64,128,0,1,2,65,5,4,232,65,27,163,172,102,2,2,244,102,244,54,38,240,89,1,1,186,1,
33,64,128,0,1,2,29,11,8,208,59,110,158,210,87,17,16,136,9,208,87,25,44,139,14,41,224,190,24,178,173,14,69,128,0,1,2,4,8,4,23,16,160,7,111,144,242,170,11,8,208,171,147,219,144,64,150,128,0,61,139,201,67,
4,8,16,32,64,32,166,128,0,61,102,95,84,213,78,64,32,38,64,111,55,125,118,238,77,192,125,209,91,199,212,75,128,0,1,2,4,8,140,32,32,64,31,161,139,206,80,82,64,128,94,82,211,90,4,202,9,8,208,203,89,90,137,
0,1,2,4,8,84,23,16,160,87,39,183,97,112,1,129,152,0,61,248,136,42,47,144,128,251,34,80,51,148,66,128,0,1,2,4,8,76,35,32,64,159,166,213,14,154,41,32,64,207,132,242,24,129,202,2,2,244,202,224,182,35,64,
128,0,1,2,37,5,4,232,37,53,173,53,130,128,64,76,128,62,194,28,59,67,29,1,247,69,29,103,187,16,32,64,128,0,1,2,4,126,45,32,64,55,15,4,182,5,4,232,38,130,64,76,1,1,122,204,190,168,138,0,1,2,4,8,100,9,8,
208,179,152,60,52,145,128,64,76,128,62,209,184,59,234,145,2,238,139,35,1,189,156,0,1,2,4,8,16,32,112,128,128,0,253,0,52,47,25,90,64,128,62,116,123,29,174,99,1,1,122,199,205,83,58,1,2,4,8,16,16,160,155,
1,2,219,2,2,49,1,186,247,4,129,92,1,247,69,174,148,231,8,16,32,64,128,0,1,2,229,4,4,232,229,44,173,52,134,128,0,125,140,62,58,197,120,2,2,244,241,122,234,68,4,8,16,32,48,145,128,0,125,162,102,59,106,150,
128,64,76,128,158,53,40,30,34,144,4,220,23,198,128,0,1,2,4,8,16,32,80,95,64,128,94,223,220,142,177,5,4,232,177,251,163,186,121,5,4,232,243,246,222,201,9,16,32,64,96,0,1,1,250,0,77,116,132,162,2,2,49,1,
122,209,129,178,216,208,2,238,139,161,219,235,112,4,8,16,32,64,128,64,80,1,1,122,208,198,40,171,153,128,0,189,25,189,141,9,124,86,64,128,110,64,8,16,32,64,128,64,199,2,2,244,142,155,167,244,85,4,4,98,
2,244,85,6,203,162,67,10,184,47,134,108,171,67,17,32,64,128,0,1,2,193,5,4,232,193,27,164,188,234,2,2,244,234,228,54,36,144,37,32,64,207,98,242,16,1,2,4,8,16,136,41,32,64,143,217,23,85,181,19,16,136,9,
208,219,77,159,157,123,19,112,95,244,214,49,245,18,32,64,128,0,1,2,35,8,8,208,71,232,162,51,148,20,16,160,151,212,180,22,129,114,2,2,244,114,150,86,34,64,128,0,1,2,213,5,4,232,213,201,109,24,92,64,32,
38,64,15,62,162,202,11,36,224,190,8,212,12,165,16,32,64,128,0,1,2,211,8,8,208,167,105,181,131,102,10,8,208,51,161,60,70,160,178,128,0,189,50,184,237,8,16,32,64,128,64,73,1,1,122,73,77,107,141,32,32,16,
19,160,143,48,199,206,80,71,192,125,81,199,217,46,4,8,16,32,64,128,0,129,95,11,8,208,205,3,129,109,1,1,186,137,32,16,83,64,128,30,179,47,170,34,64,128,0,1,2,89,2,2,244,44,38,15,77,36,32,16,19,160,79,52,
238,142,122,164,128,251,226,72,64,47,39,64,128,0,1,2,4,8,28,32,32,64,63,0,205,75,134,22,16,160,15,221,94,135,235,88,64,128,222,113,243,148,78,128,0,1,2,4,4,232,102,128,192,182,128,64,76,128,238,61,65,
32,87,192,125,145,43,229,57,2,4,8,16,32,64,128,64,57,1,1,122,57,75,43,141,33,32,64,31,163,143,78,49,158,128,0,125,188,158,58,17,1,2,4,8,76,36,32,64,159,168,217,142,154,37,32,16,19,160,103,13,138,135,8,
36,1,247,133,49,32,64,128,0,1,2,4,8,212,23,16,160,215,55,183,99,108,1,1,122,236,254,168,110,94,1,1,250,188,189,119,114,2,4,8,16,24,64,64,128,62,64,19,29,161,168,128,64,76,128,94,116,160,44,54,180,128,
251,98,232,246,58,28,1,2,4,8,16,32,16,84,64,128,30,180,49,202,106,38,32,64,111,70,111,99,2,159,21,16,160,27,16,2,4,8,16,32,208,177,128,0,189,227,230,41,125,21,1,129,152,0,125,149,193,178,232,144,2,238,
139,33,219,234,80,4,8,16,32,64,128,64,112,1,1,122,240,6,41,175,186,128,0,189,58,185,13,9,100,9,8,208,179,152,60,68,128,0,1,2,4,98,10,8,208,99,246,69,85,237,4,4,98,2,244,118,211,103,231,222,4,220,23,189,
117,76,189,4,8,16,32,64,128,192,8,2,2,244,17,186,232,12,37,5,4,232,37,53,173,69,160,156,128,0,189,156,165,149,8,16,32,64,128,64,117,1,1,122,117,114,27,6,23,16,136,9,208,131,143,168,242,2,9,184,47,2,53,
67,41,4,8,16,32,64,128,192,52,2,2,244,105,90,237,160,153,2,2,244,76,40,143,17,168,44,32,64,175,12,110,59,2,4,8,16,32,80,82,64,128,94,82,211,90,35,8,8,196,4,232,35,204,177,51,212,17,112,95,212,113,182,
11,1,2,4,8,16,32,64,224,215,2,2,116,243,64,96,91,64,128,110,34,8,196,20,16,160,199,236,139,170,8,16,32,64,128,64,150,128,0,61,139,201,67,19,9,8,196,4,232,19,141,187,163,30,41,224,190,56,18,208,203,9,16,
32,64,128,0,1,2,7,8,8,208,15,64,243,146,161,5,4,232,67,183,215,225,58,22,16,160,119,220,60,165,19,32,64,128,0,1,1,186,25,32,176,45,32,16,19,160,123,79,16,200,21,112,95,228,74,121,142,0,1,2,4,8,16,32,80,
78,64,128,94,206,210,74,99,8,8,208,199,232,163,83,140,39,32,64,31,175,167,78,68,128,0,1,2,19,9,8,208,39,106,182,163,102,9,8,196,4,232,89,131,226,33,2,73,192,125,97,12,8,16,32,64,128,0,1,2,245,5,4,232,
245,205,237,24,91,64,128,30,187,63,170,155,87,64,128,62,111,239,157,156,0,1,2,4,6,16,16,160,15,208,68,71,40,42,32,16,19,160,23,29,40,139,13,45,224,190,24,186,189,14,71,128,0,1,2,4,8,4,21,16,160,7,109,
140,178,154,9,8,208,155,209,219,152,192,103,5,4,232,6,132,0,1,2,4,8,116,44,32,64,239,184,121,74,95,69,64,32,38,64,95,101,176,44,58,164,128,251,98,200,182,58,20,1,2,4,8,16,32,16,92,64,128,30,188,65,202,
171,46,32,64,175,78,110,67,2,89,2,2,244,44,38,15,17,32,144,35,176,9,242,210,255,195,127,120,118,118,246,48,125,67,114,243,207,255,113,251,186,7,233,127,127,144,254,231,205,223,254,90,87,224,227,102,249,
211,211,211,79,255,188,190,190,254,127,110,183,219,252,239,239,255,249,207,127,126,120,254,252,249,135,117,75,176,122,77,1,1,122,77,109,123,245,32,32,16,91,238,82,250,70,213,163,244,255,155,47,123,232,
163,26,9,212,16,112,95,212,80,182,7,1,2,4,8,16,32,64,96,91,64,128,110,34,8,108,11,8,208,77,4,129,152,2,2,244,152,125,81,21,129,240,2,155,208,46,133,177,143,82,161,95,164,176,246,127,166,127,62,188,253,
59,124,237,10,252,36,240,33,253,253,62,125,227,248,127,167,191,95,159,159,159,191,231,210,167,128,0,189,207,190,169,122,61,1,129,216,178,173,0,125,189,185,179,114,159,2,238,139,62,251,166,106,2,4,8,16,
32,64,160,111,1,1,122,223,253,83,125,121,1,1,122,121,83,43,18,40,33,32,64,47,161,104,13,2,147,8,92,92,92,124,145,142,186,9,204,255,35,253,243,97,250,219,39,202,199,234,253,235,244,141,228,255,149,254,
195,136,215,62,165,222,79,99,5,232,253,244,74,165,117,4,4,98,203,206,2,244,58,51,104,151,126,4,220,23,253,244,74,165,4,8,16,32,64,128,192,56,2,2,244,113,122,233,36,101,4,4,232,101,28,173,66,160,180,128,
0,189,180,168,245,8,12,38,176,249,102,123,10,204,95,220,134,230,155,79,156,251,107,14,129,215,233,199,191,255,87,250,100,250,15,115,28,183,223,83,10,208,251,237,157,202,215,17,16,136,45,187,10,208,215,
153,57,171,246,43,224,190,232,183,119,42,39,64,128,0,1,2,4,250,21,16,160,247,219,59,149,175,35,32,64,95,199,213,170,4,142,21,16,160,31,43,232,245,4,6,20,248,215,143,103,79,161,249,119,233,120,66,243,1,
123,188,231,145,94,167,127,145,251,147,79,165,239,169,86,233,113,1,122,37,104,219,116,35,32,16,19,160,119,51,172,10,109,46,224,190,104,222,2,5,16,32,64,128,0,1,2,19,10,8,208,39,108,186,35,127,86,64,128,
110,64,8,196,20,16,160,199,236,139,170,8,52,17,216,4,113,233,255,97,191,56,59,59,251,191,5,231,77,90,16,125,211,55,169,192,191,61,125,250,244,117,244,66,103,170,79,128,62,83,183,157,53,71,64,32,182,172,
228,19,232,57,19,228,153,153,4,220,23,51,117,219,89,9,16,32,64,128,0,129,40,2,2,244,40,157,80,71,20,1,1,122,148,78,168,131,192,182,128,0,221,68,16,32,112,114,251,137,243,111,210,39,206,255,51,113,60,68,
66,96,135,192,251,244,227,221,255,230,199,187,199,152,19,1,122,140,62,168,34,142,128,64,76,128,30,103,26,85,18,93,192,125,17,189,67,234,35,64,128,0,1,2,4,70,20,16,160,143,216,85,103,58,70,64,128,126,140,
158,215,18,88,79,64,128,190,158,173,149,9,116,33,112,113,113,241,133,31,213,222,69,171,34,22,249,38,253,11,222,215,126,180,123,219,214,8,208,219,250,219,61,158,128,64,76,128,30,111,42,85,20,85,192,125,
17,181,51,234,34,64,128,0,1,2,4,70,22,16,160,143,220,93,103,59,68,64,128,126,136,154,215,16,88,95,64,128,190,190,177,29,8,132,20,216,132,110,233,83,196,223,166,111,28,126,19,178,64,69,117,35,144,254,3,
140,191,62,121,242,228,79,221,20,60,88,161,2,244,193,26,234,56,71,11,8,196,4,232,71,15,145,5,166,17,112,95,76,211,106,7,37,64,128,0,1,2,4,2,9,8,208,3,53,67,41,33,4,4,232,33,218,160,8,2,191,17,16,160,27,
10,2,19,10,220,254,139,234,119,233,232,15,38,60,190,35,175,35,176,249,177,238,95,167,31,235,254,126,157,229,173,186,36,32,64,55,27,4,182,5,4,98,203,19,225,119,160,123,183,16,112,95,152,1,2,4,8,16,32,64,
128,64,107,1,1,122,235,14,216,63,154,128,0,61,90,71,212,67,224,70,64,128,110,18,8,76,36,112,251,169,243,239,82,184,240,213,68,199,118,212,138,2,130,171,138,216,183,91,9,208,235,155,219,49,182,128,123,
104,185,63,2,244,216,179,171,186,250,2,238,139,250,230,118,36,64,128,0,1,2,4,8,8,208,205,0,129,109,1,1,186,137,32,16,83,64,128,30,179,47,170,34,80,92,224,246,155,230,175,210,194,15,139,47,110,65,2,219,
2,111,238,221,187,247,242,241,227,199,31,193,172,47,32,64,95,223,216,14,125,9,8,196,150,251,37,64,239,107,150,85,187,190,128,251,98,125,99,59,16,32,64,128,0,1,2,4,238,10,8,208,205,4,129,109,1,1,186,137,
32,16,83,64,128,30,179,47,170,34,80,84,224,226,226,226,155,244,123,170,191,77,139,250,145,237,69,101,45,246,25,129,143,233,71,186,127,233,71,186,175,63,35,2,244,245,141,237,208,151,128,64,76,128,222,215,
196,170,182,165,128,251,162,165,190,189,9,16,32,64,128,0,129,89,5,4,232,179,118,222,185,151,4,4,232,102,131,64,76,1,1,122,204,190,168,138,64,49,129,219,240,124,243,251,206,253,69,160,186,64,250,198,244,
151,207,158,61,123,83,125,227,137,54,20,160,79,212,108,71,205,18,16,136,45,51,249,4,122,214,8,121,104,34,1,247,197,68,205,118,84,2,4,8,16,32,64,32,140,128,0,61,76,43,20,18,68,64,128,30,164,17,202,32,112,
71,64,128,110,36,8,12,44,240,211,79,63,109,126,223,249,55,3,31,209,209,58,16,72,159,68,255,58,125,18,253,135,14,74,237,178,68,1,122,151,109,83,244,138,2,2,49,1,250,138,227,101,233,193,4,220,23,131,53,
212,113,8,16,32,64,128,0,129,46,4,4,232,93,180,73,145,21,5,4,232,21,177,109,69,96,15,1,1,250,30,88,30,37,208,139,192,38,80,75,161,229,38,60,255,170,151,154,213,57,182,128,111,80,175,215,95,1,250,122,182,
86,238,83,192,125,35,64,239,115,114,85,221,66,192,125,209,66,221,158,4,8,16,32,64,128,192,236,2,2,244,217,39,192,249,239,10,8,208,205,4,129,152,2,2,244,152,125,81,21,129,131,5,132,231,7,211,121,225,202,
2,190,73,189,14,176,0,125,29,87,171,246,43,224,174,17,160,247,59,189,42,175,45,224,190,168,45,110,63,2,4,8,16,32,64,128,192,201,137,0,221,20,16,216,22,16,160,155,8,2,49,5,4,232,49,251,162,42,2,7,11,248,
177,237,7,211,121,97,5,1,63,206,189,60,178,0,189,188,169,21,251,22,16,136,9,208,251,158,96,213,215,20,112,95,212,212,182,23,1,2,4,8,16,32,64,224,70,64,128,110,18,8,108,11,8,208,77,4,129,152,2,2,244,152,
125,81,21,129,131,4,46,46,46,190,57,61,61,253,238,160,23,123,17,129,74,2,233,155,213,95,62,123,246,236,77,165,237,134,223,70,128,62,124,139,29,112,79,1,129,216,50,88,250,70,213,163,179,179,179,203,61,
73,61,78,96,88,1,247,197,176,173,117,48,2,4,8,16,32,64,32,176,128,0,61,112,115,148,214,68,64,128,222,132,221,166,4,118,10,8,208,119,18,121,128,64,31,2,194,243,62,250,164,202,27,1,33,122,185,73,16,160,
151,179,180,210,24,2,2,177,229,62,10,208,199,152,113,167,40,39,224,190,40,103,105,37,2,4,8,16,32,64,128,64,174,128,0,61,87,202,115,179,8,8,208,103,233,180,115,246,38,32,64,239,173,99,234,37,240,59,2,183,
223,16,255,49,253,209,3,64,4,58,17,248,120,239,222,189,63,62,126,252,248,99,39,245,134,45,83,128,30,182,53,10,107,36,32,16,91,134,23,160,55,26,74,219,134,21,112,95,132,109,141,194,8,16,32,64,128,0,129,
129,5,4,232,3,55,215,209,14,18,16,160,31,196,74,117,95,196,0,0,32,0,73,68,65,84,230,69,4,86,23,16,160,175,78,108,3,2,235,10,220,134,103,155,240,252,209,186,59,89,157,64,113,129,55,79,159,62,253,178,248,
170,147,45,40,64,159,172,225,142,187,83,64,32,182,76,36,64,223,57,62,30,152,76,192,125,49,89,195,29,151,0,1,2,4,8,16,8,33,32,64,15,209,6,69,4,18,16,160,7,106,134,82,8,252,74,64,128,110,28,8,116,46,240,
238,221,187,87,233,8,47,58,63,134,242,39,21,240,141,235,227,27,47,64,63,222,208,10,99,9,184,87,4,232,99,77,180,211,172,41,224,190,88,83,215,218,4,8,16,32,64,128,0,129,223,23,16,160,155,12,2,219,2,2,116,
19,65,32,166,128,0,61,102,95,84,69,32,75,192,239,61,207,98,242,80,112,1,191,15,253,184,6,9,208,143,243,243,234,241,4,4,98,2,244,241,166,218,137,214,18,112,95,172,37,107,93,2,4,8,16,32,64,128,192,103,191,
46,249,234,236,236,236,123,70,4,8,220,8,8,208,77,2,129,152,2,2,244,152,125,81,21,129,157,2,111,223,190,125,120,255,254,253,203,244,160,223,123,190,83,203,3,193,5,62,166,31,229,254,135,224,53,134,45,79,
128,30,182,53,10,107,36,32,16,251,236,55,170,30,165,111,84,109,254,221,193,95,4,8,36,1,247,133,49,32,64,128,0,1,2,4,8,212,23,240,9,244,250,230,118,140,45,32,64,143,221,31,213,205,43,32,64,159,183,247,
78,222,185,128,31,221,222,121,3,149,191,37,144,190,129,253,151,103,207,158,253,25,203,254,2,2,244,253,205,188,98,108,1,129,216,114,127,253,14,244,177,103,223,233,246,23,112,95,236,111,230,21,4,8,16,32,
64,128,0,129,99,5,4,232,199,10,122,253,104,2,2,244,209,58,234,60,163,8,8,208,71,233,164,115,76,37,144,194,243,205,239,60,223,252,238,115,127,17,24,70,192,191,44,30,214,74,1,250,97,110,94,53,174,128,64,
108,185,183,2,244,113,231,222,201,14,19,112,95,28,230,230,85,4,8,16,32,64,128,0,129,99,4,4,232,199,232,121,237,136,2,190,39,58,98,87,157,105,4,1,1,250,8,93,116,134,169,4,110,195,178,31,211,161,31,77,117,
112,135,157,65,224,77,250,81,238,95,206,112,208,146,103,20,160,151,212,180,214,8,2,2,49,1,250,8,115,236,12,117,4,220,23,117,156,237,66,128,0,1,2,4,8,16,248,181,128,0,221,60,16,216,22,16,160,155,8,2,49,
5,4,232,49,251,162,42,2,139,2,23,23,23,127,62,61,61,253,22,17,129,65,5,94,166,16,253,245,160,103,91,229,88,2,244,85,88,45,218,177,128,64,76,128,222,241,248,42,189,178,128,251,162,50,184,237,8,16,32,64,
128,0,1,2,73,64,128,110,12,8,8,208,205,0,129,30,4,4,232,61,116,73,141,4,110,5,110,131,178,191,167,255,245,1,20,2,131,10,124,72,1,250,31,7,61,219,42,199,18,160,175,194,106,209,142,5,4,98,203,205,243,35,
220,59,30,108,165,175,34,224,190,88,133,213,162,4,8,16,32,64,128,0,129,207,10,8,208,13,8,129,109,1,159,64,55,17,4,98,10,8,208,99,246,69,85,4,126,87,192,167,207,13,198,36,2,62,133,190,71,163,5,232,123,
96,121,116,10,1,129,152,0,125,138,65,119,200,34,2,238,139,34,140,22,33,64,128,0,1,2,4,8,236,37,32,64,223,139,203,195,19,8,8,208,39,104,178,35,118,41,32,64,239,178,109,138,158,81,224,54,36,187,76,103,127,
56,227,249,157,121,42,129,247,233,83,232,143,167,58,241,17,135,21,160,31,129,231,165,67,10,8,196,150,219,234,19,232,67,142,188,67,29,33,224,190,56,2,207,75,9,16,32,64,128,0,1,2,7,10,8,208,15,132,243,178,
97,5,4,232,195,182,214,193,58,23,16,160,119,222,64,229,207,35,144,62,125,254,77,250,221,231,223,205,115,98,39,157,89,224,250,250,250,241,249,249,249,251,153,13,114,207,46,64,207,149,242,220,44,2,2,49,
1,250,44,179,238,156,199,11,184,47,142,55,180,2,1,2,4,8,16,32,64,96,95,1,1,250,190,98,158,31,93,64,128,62,122,135,157,175,87,1,1,122,175,157,83,247,116,2,239,222,189,219,124,250,252,209,116,7,119,224,
89,5,94,167,79,161,191,156,245,240,251,156,91,128,190,143,150,103,103,16,16,136,9,208,103,152,115,103,44,35,224,190,40,227,104,21,2,4,8,16,32,64,128,192,62,2,2,244,125,180,60,59,131,128,0,125,134,46,59,
99,143,2,2,244,30,187,166,230,233,4,252,200,213,233,90,238,192,39,39,31,239,221,187,247,199,199,143,31,127,132,241,121,1,1,186,9,33,176,45,32,16,19,160,123,79,16,200,21,112,95,228,74,121,142,0,1,2,4,8,
16,32,80,78,64,128,94,206,210,74,99,8,8,208,199,232,163,83,140,39,32,64,31,175,167,78,52,160,64,250,241,237,127,78,63,190,253,219,1,143,230,72,4,22,5,124,83,59,111,56,4,232,121,78,158,154,71,192,221,33,
64,159,103,218,157,244,88,1,247,197,177,130,94,79,128,0,1,2,4,8,16,216,95,64,128,190,191,153,87,140,45,32,64,31,187,191,78,215,175,128,0,189,223,222,169,124,18,129,219,112,108,243,227,219,31,78,114,100,
199,36,240,47,129,247,233,199,184,63,198,241,121,1,1,186,9,33,176,45,32,16,91,158,8,63,209,198,187,133,128,251,194,12,16,32,64,128,0,1,2,4,90,11,8,208,91,119,192,254,209,4,4,232,209,58,162,30,2,55,2,2,
116,147,64,32,184,64,250,221,231,47,82,137,175,130,151,169,60,2,171,8,248,23,200,221,172,2,244,221,70,158,152,75,64,128,190,220,111,1,250,92,239,5,167,221,45,224,190,216,109,228,9,2,4,8,16,32,64,128,64,
105,1,1,122,105,81,235,245,46,224,251,159,189,119,80,253,163,10,8,208,71,237,172,115,13,35,240,211,79,63,125,159,190,185,247,213,48,7,114,16,2,123,8,248,198,246,110,44,1,250,110,35,79,204,37,224,222,16,
160,207,53,241,78,123,140,128,251,226,24,61,175,37,64,128,0,1,2,4,8,28,38,32,64,63,204,205,171,198,21,16,160,143,219,91,39,235,91,64,128,222,119,255,84,63,129,64,250,4,250,223,211,49,31,78,112,84,71,36,
240,123,2,175,211,143,113,127,137,102,89,64,128,110,58,8,108,11,8,196,150,39,194,39,208,189,91,8,184,47,204,0,1,2,4,8,16,32,64,160,181,128,0,189,117,7,236,31,77,64,128,30,173,35,234,33,112,35,32,64,55,
9,4,2,11,248,70,119,224,230,40,173,150,192,199,20,160,255,161,214,102,61,238,35,64,239,177,107,106,94,83,64,128,190,172,235,223,43,214,156,60,107,247,40,224,190,232,177,107,106,38,64,128,0,1,2,4,122,23,
16,160,247,222,65,245,151,22,16,160,151,22,181,30,129,50,2,2,244,50,142,86,33,176,138,128,127,161,92,133,213,162,157,9,92,95,95,63,62,63,63,127,223,89,217,213,202,21,160,87,163,182,81,39,2,2,49,1,122,
39,163,170,204,0,2,238,139,0,77,80,2,1,2,4,8,16,32,48,157,128,239,119,78,215,114,7,222,33,32,64,55,34,4,98,10,8,208,99,246,69,85,4,62,9,164,31,223,254,42,253,227,5,14,2,51,11,248,230,246,231,187,47,64,
159,249,221,225,236,191,39,224,206,88,158,11,159,64,247,158,33,176,45,224,190,48,17,4,8,16,32,64,128,0,129,250,2,2,244,250,230,118,140,45,32,64,143,221,31,213,205,43,32,64,159,183,247,78,222,129,128,223,
127,222,65,147,148,88,67,192,239,65,255,140,178,0,189,198,8,218,163,39,1,129,152,0,189,167,121,85,107,91,1,247,69,91,127,187,19,32,64,128,0,1,2,115,10,8,208,231,236,187,83,47,11,8,208,77,7,129,152,2,2,
244,152,125,81,21,129,79,2,41,64,255,63,40,8,16,56,241,123,208,5,232,222,6,4,178,5,4,98,2,244,236,97,241,224,244,2,238,139,233,71,0,0,1,2,4,8,16,32,208,64,64,128,222,0,221,150,161,5,4,232,161,219,163,
184,137,5,4,232,19,55,223,209,99,11,248,49,171,177,251,163,186,170,2,2,116,1,122,213,129,179,89,223,2,2,49,1,122,223,19,172,250,154,2,238,139,154,218,246,34,64,128,0,1,2,4,8,220,8,8,208,77,2,129,109,1,
1,186,137,32,16,83,64,128,30,179,47,170,34,112,114,113,113,241,197,233,233,233,143,40,8,16,56,57,241,47,146,203,83,224,71,184,123,135,16,216,22,16,136,45,79,132,255,56,207,187,133,128,251,194,12,16,32,
64,128,0,1,2,4,90,11,8,208,91,119,192,254,209,4,124,223,51,90,71,212,67,224,70,64,128,110,18,8,4,21,72,1,250,55,41,64,255,46,104,121,202,34,80,85,32,5,98,95,62,123,246,236,77,213,77,59,217,76,128,222,
73,163,148,89,77,64,128,190,76,45,64,175,54,134,54,234,68,192,125,209,73,163,148,73,128,0,1,2,4,8,12,37,32,64,31,170,157,14,83,64,64,128,94,0,209,18,4,86,16,16,160,175,128,106,73,2,37,4,126,250,233,167,
239,211,55,245,190,42,177,150,53,8,244,46,224,27,220,203,29,20,160,247,62,221,234,47,45,224,190,88,22,21,160,151,158,54,235,245,46,224,190,232,189,131,234,39,64,128,0,1,2,4,122,20,16,160,247,216,53,53,
175,41,32,64,95,83,215,218,4,14,23,16,160,31,110,231,149,4,86,21,16,160,175,202,107,241,206,4,210,55,184,255,146,62,129,254,231,206,202,174,82,174,0,189,10,179,77,58,18,16,136,45,55,75,128,222,209,32,
43,181,138,128,251,162,10,179,77,8,16,32,64,128,0,1,2,91,2,2,116,3,65,96,91,64,128,110,34,8,196,20,16,160,199,236,139,170,8,156,188,123,247,238,85,98,120,129,130,0,129,147,19,1,250,242,20,8,208,189,67,
8,108,11,8,196,4,232,222,19,4,114,5,220,23,185,82,158,35,64,128,0,1,2,4,8,148,19,16,160,151,179,180,210,24,2,2,244,49,250,232,20,227,9,8,208,199,235,169,19,13,34,144,2,244,31,211,81,190,24,228,56,142,
65,224,40,129,211,211,211,31,158,60,121,242,245,81,139,12,250,98,1,250,160,141,117,172,131,5,4,98,203,116,62,129,126,240,88,121,225,160,2,238,139,65,27,235,88,4,8,16,32,64,128,64,104,1,1,122,232,246,40,
174,129,128,0,189,1,186,45,9,100,8,8,208,51,144,60,66,160,133,64,10,208,47,211,190,143,90,236,109,79,2,1,5,94,63,125,250,244,101,192,186,154,151,36,64,111,222,2,5,4,19,16,136,45,55,68,128,30,108,88,149,
211,92,192,125,209,188,5,10,32,64,128,0,1,2,4,38,20,16,160,79,216,116,71,254,172,128,0,221,128,16,136,41,32,64,143,217,23,85,17,216,252,8,247,191,39,134,135,40,8,16,248,36,32,64,95,24,4,1,186,119,8,129,
109,1,129,216,242,68,8,208,189,91,8,184,47,204,0,1,2,4,8,16,32,64,160,181,128,0,189,117,7,236,31,77,64,128,30,173,35,234,33,112,35,32,64,55,9,4,130,10,8,208,131,54,70,89,173,4,4,232,11,242,2,244,86,35,
105,223,168,2,2,244,229,206,8,208,163,78,173,186,90,9,184,47,90,201,219,151,0,1,2,4,8,16,152,89,64,128,62,115,247,157,253,247,4,4,232,230,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,2,2,116,
1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,109,1,
1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,2,2,
116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,109,
1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,2,
2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,116,91,18,32,64,128,0,1,2,211,11,8,208,167,31,1,0,119,4,4,232,70,130,64,76,1,1,122,204,190,168,138,128,79,160,155,1,2,219,
2,2,116,1,186,247,4,129,44,1,129,152,0,61,107,80,60,68,32,9,184,47,140,1,1,2,4,8,16,32,64,160,190,128,0,189,190,185,29,99,11,8,208,99,247,71,117,243,10,8,208,231,237,189,147,7,23,240,9,244,224,13,82,94,
109,1,1,186,0,189,246,204,217,175,83,1,129,152,0,189,211,209,85,118,3,1,247,69,3,244,21,183,188,188,188,124,144,190,249,248,240,236,236,236,97,234,237,163,244,207,255,43,109,247,32,253,207,15,54,255,188,
253,123,197,10,44,253,43,129,143,233,127,222,252,125,114,122,122,250,233,127,190,190,190,254,127,211,63,223,252,243,159,255,252,240,252,249,243,15,180,8,16,32,64,96,94,1,1,250,188,189,119,242,223,23,16,
160,155,12,2,49,5,4,232,49,251,162,42,2,62,129,110,6,8,108,11,8,208,23,38,98,243,205,226,171,171,171,159,13,12,1,2,55,2,2,177,229,73,72,223,168,218,4,74,151,102,133,0,1,247,69,239,51,176,249,247,159,20,
196,62,74,231,248,34,5,180,255,145,254,249,48,253,189,9,201,253,213,143,192,135,84,234,251,244,255,183,255,87,250,251,205,249,249,249,251,126,74,87,41,1,2,4,8,28,35,32,64,63,70,207,107,71,20,16,160,143,
216,85,103,26,65,64,128,62,66,23,157,97,72,1,159,64,31,178,173,14,117,184,128,0,125,193,78,128,126,248,80,121,229,152,2,2,244,229,190,10,208,199,156,121,167,58,92,192,125,113,184,93,139,87,110,238,176,
20,150,191,16,152,183,208,175,178,231,230,147,234,111,210,39,213,255,43,133,233,63,84,217,209,38,4,8,16,32,208,68,64,128,222,132,221,166,129,5,4,232,129,155,163,180,169,5,4,232,83,183,223,225,35,11,8,
208,35,119,71,109,13,4,4,232,11,232,2,244,6,211,104,203,208,2,2,177,229,246,8,208,67,143,174,226,26,8,184,47,26,160,239,185,229,237,39,205,191,74,161,249,127,166,151,110,62,113,238,175,121,4,94,11,211,
231,105,182,147,18,32,48,151,128,0,125,174,126,59,237,110,1,1,250,110,35,79,16,104,33,32,64,111,161,110,79,2,25,2,2,244,12,36,143,204,36,32,64,95,232,182,0,125,166,183,129,179,230,8,8,196,150,149,4,232,
57,19,228,153,153,4,220,23,113,187,125,113,113,241,69,250,149,19,255,153,122,244,34,85,233,71,179,199,109,85,149,202,210,127,64,241,215,127,252,227,31,127,243,187,211,171,112,219,132,0,1,2,171,11,8,208,
87,39,182,65,103,2,2,244,206,26,166,220,105,4,4,232,211,180,218,65,123,19,16,160,247,214,49,245,174,44,32,64,23,160,175,60,98,150,31,69,64,32,38,64,31,101,150,157,99,125,1,247,197,250,198,251,238,176,
9,206,83,88,250,93,122,157,79,155,239,139,55,193,243,130,244,9,154,236,136,4,8,76,33,32,64,159,162,205,14,185,135,128,0,125,15,44,143,18,168,40,32,64,175,136,109,43,2,251,8,8,208,247,209,242,236,4,2,2,
116,1,250,4,99,238,136,37,4,4,98,2,244,18,115,100,141,57,4,220,23,113,250,44,56,143,211,139,30,42,73,65,250,15,233,19,233,127,241,137,244,30,186,165,70,2,4,8,252,86,64,128,110,42,8,108,11,8,208,77,4,129,
152,2,2,244,152,125,81,21,129,19,1,186,33,32,176,37,32,64,23,160,123,75,16,200,18,16,136,9,208,179,6,197,67,4,146,128,251,162,253,24,188,125,251,246,225,191,255,251,191,127,155,122,241,85,251,106,84,208,
155,192,230,19,233,79,158,60,249,83,111,117,171,151,0,1,2,179,11,8,208,103,159,0,231,191,43,32,64,55,19,4,98,10,8,208,99,246,69,85,4,4,232,102,128,192,182,128,0,93,128,238,61,65,32,75,64,32,38,64,207,
26,20,15,17,16,160,55,157,129,203,203,203,7,215,215,215,255,10,206,253,142,243,166,221,232,126,243,247,105,150,254,118,126,126,254,67,247,39,113,0,2,4,8,76,34,32,64,159,164,209,142,153,45,32,64,207,166,
242,32,129,170,2,2,244,170,220,54,35,144,47,224,19,232,249,86,158,156,66,64,128,190,208,230,205,55,160,175,174,174,126,158,98,10,28,146,64,134,128,0,125,25,41,125,163,234,209,217,217,217,101,6,163,71,
8,76,33,224,190,104,211,230,219,187,232,251,180,187,223,115,222,166,5,67,238,186,249,177,238,233,211,232,95,15,121,56,135,34,64,128,192,96,2,2,244,193,26,234,56,71,11,8,208,143,38,180,0,129,85,4,4,232,
171,176,90,148,192,241,2,2,244,227,13,173,48,148,128,0,125,161,157,2,244,161,230,220,97,10,8,8,196,150,17,5,232,5,6,204,18,67,9,184,47,234,183,51,253,174,243,111,82,208,249,109,218,217,167,206,235,243,
207,176,227,135,244,105,244,151,233,211,232,239,103,56,172,51,18,32,64,160,87,1,1,122,175,157,83,247,90,2,2,244,181,100,173,75,224,56,1,1,250,113,126,94,77,96,53,1,1,250,106,180,22,238,83,64,128,46,64,
239,115,114,85,93,93,64,32,38,64,175,62,116,54,236,86,192,125,81,175,117,183,63,178,253,59,191,235,188,158,249,204,59,121,111,207,220,125,103,39,64,160,7,1,1,122,15,93,82,99,77,1,1,122,77,109,123,17,200,
23,16,160,231,91,121,146,64,85,1,1,122,85,110,155,197,23,16,160,11,208,227,79,169,10,67,8,248,166,185,0,61,196,32,42,162,11,1,247,69,157,54,221,254,244,139,87,105,183,135,117,118,180,11,129,79,2,111,158,
62,125,250,37,11,2,4,8,16,136,39,32,64,143,215,19,21,181,21,16,160,183,245,183,59,129,37,1,1,186,217,32,16,84,64,128,30,180,49,202,106,37,32,64,95,144,247,35,220,91,141,164,125,163,10,8,196,150,59,227,
71,184,71,157,90,117,181,18,112,95,172,47,47,60,95,223,216,14,159,21,120,127,239,222,189,47,31,63,126,252,145,19,1,2,4,8,196,17,16,160,199,233,133,74,98,8,8,208,99,244,65,21,4,238,10,8,208,205,4,129,160,
2,2,244,160,141,81,86,43,1,1,186,0,189,213,236,217,183,51,1,129,152,0,189,179,145,85,110,67,1,247,197,186,248,233,247,157,127,145,126,223,249,230,147,231,126,223,249,186,212,86,255,188,192,251,244,77,
233,151,207,159,63,255,0,138,0,1,2,4,98,8,8,208,99,244,65,21,113,4,4,232,113,122,161,18,2,191,22,16,160,155,7,2,65,5,4,232,65,27,163,172,86,2,2,244,5,121,159,64,111,53,146,246,141,42,32,16,91,238,140,
79,160,71,157,90,117,181,18,112,95,172,39,127,251,141,241,239,210,14,194,243,245,152,173,156,47,240,241,250,250,250,203,243,243,243,247,249,47,241,36,1,2,4,8,172,37,32,64,95,75,214,186,189,10,8,208,123,
237,156,186,71,23,16,160,143,222,97,231,235,86,64,128,222,109,235,20,190,142,128,0,93,128,190,206,100,89,117,56,1,129,152,0,125,184,161,118,160,213,4,220,23,235,208,10,207,215,113,181,234,209,2,66,244,
163,9,45,64,128,0,129,50,2,2,244,50,142,86,25,71,64,128,62,78,47,157,100,44,1,1,250,88,253,116,154,129,4,4,232,3,53,211,81,74,8,8,208,5,232,37,230,200,26,19,8,8,196,4,232,19,140,185,35,22,18,112,95,20,
130,252,213,50,183,63,233,226,199,244,127,242,201,243,242,188,86,60,94,224,67,250,157,232,233,87,162,251,157,232,199,83,90,129,0,1,2,135,11,8,208,15,183,243,202,49,5,4,232,99,246,213,169,250,23,16,160,
247,223,67,39,24,84,64,128,62,104,99,29,235,80,1,1,186,0,253,208,217,241,186,201,4,4,98,2,244,201,70,222,113,143,16,112,95,28,129,247,59,47,21,158,151,245,180,218,106,2,239,159,62,125,250,120,181,213,
45,76,128,0,1,2,59,5,4,232,59,137,60,48,153,128,0,125,178,134,59,110,55,2,2,244,110,90,165,208,217,4,4,232,179,117,220,121,119,8,8,208,5,232,222,36,4,178,4,4,98,2,244,172,65,241,16,129,36,224,190,40,55,
6,111,223,190,125,120,255,254,253,205,39,207,31,150,91,213,74,4,86,19,120,147,66,244,47,87,91,221,194,4,8,16,32,240,89,1,1,186,1,33,176,45,12,104,28,211,0,0,32,0,73,68,65,84,32,64,55,17,4,98,10,8,208,
99,246,69,85,4,78,4,232,134,128,192,150,128,0,125,97,32,46,47,47,31,92,93,93,253,108,94,8,16,184,17,16,136,45,79,194,237,167,67,47,205,10,1,2,238,139,146,51,112,251,239,34,223,167,53,95,148,92,215,90,
4,214,20,56,61,61,253,235,147,39,79,254,180,230,30,214,38,64,128,0,129,223,23,16,160,155,12,2,219,2,2,116,19,65,32,166,128,0,61,102,95,84,69,64,128,110,6,8,108,11,8,208,23,38,66,128,238,173,66,96,91,64,
128,190,60,17,2,116,239,22,2,238,139,53,102,224,226,226,226,207,41,140,252,118,141,181,173,73,96,101,129,151,233,147,232,175,87,222,195,242,4,8,16,32,112,71,64,128,110,36,8,8,208,205,0,129,30,4,4,232,
61,116,73,141,83,10,248,4,250,148,109,119,232,101,1,1,186,0,221,251,131,64,150,128,0,93,128,158,53,40,30,34,144,4,220,23,199,143,65,250,154,101,243,169,243,87,199,175,100,5,2,77,4,62,166,79,124,61,126,
254,252,249,135,38,187,219,148,0,1,2,147,10,8,208,39,109,188,99,47,10,248,4,186,225,32,16,83,64,128,30,179,47,170,34,224,19,232,102,128,192,182,128,0,125,97,34,124,2,221,91,133,192,182,128,64,108,121,
34,124,2,221,187,133,128,251,162,228,12,220,254,222,243,205,175,133,120,80,114,93,107,17,168,44,224,247,161,87,6,183,29,1,2,4,4,232,102,128,192,182,128,0,221,68,16,136,41,32,64,143,217,23,85,17,16,160,
155,1,2,2,244,172,25,16,160,103,49,121,104,34,1,1,186,0,125,162,113,119,212,35,5,220,23,199,1,254,244,211,79,223,39,195,175,142,91,197,171,9,180,23,112,23,180,239,129,10,8,16,152,75,64,128,62,87,191,157,
118,183,128,0,125,183,145,39,8,180,16,16,160,183,80,183,39,129,12,1,63,194,61,3,201,35,51,9,248,4,250,66,183,5,232,51,189,13,156,53,71,192,55,193,151,149,124,2,61,103,130,60,51,147,128,251,226,240,110,
251,209,237,135,219,121,101,72,1,63,202,61,100,91,20,69,128,192,168,2,2,244,81,59,235,92,135,10,8,208,15,149,243,58,2,235,10,8,208,215,245,181,58,129,131,5,4,232,7,211,121,225,152,2,2,116,1,250,152,147,
237,84,197,5,4,98,2,244,226,67,101,193,97,5,220,23,135,181,246,246,63,222,251,49,189,250,209,97,43,120,21,129,144,2,190,222,8,217,22,69,17,32,48,162,128,0,125,196,174,58,211,49,2,2,244,99,244,188,150,
192,122,2,2,244,245,108,173,76,224,40,1,1,250,81,124,94,60,158,128,111,104,45,244,212,39,208,199,27,118,39,58,78,64,32,182,236,231,19,232,199,205,150,87,143,39,224,190,56,172,167,23,23,23,127,62,61,61,
253,246,176,87,123,21,129,208,2,47,159,62,125,250,58,116,133,138,35,64,128,192,0,2,2,244,1,154,232,8,69,5,4,232,69,57,45,70,160,152,128,0,189,24,165,133,8,148,21,16,160,151,245,180,90,247,2,2,244,133,
22,10,208,187,159,109,7,40,44,32,16,91,6,21,160,23,30,54,203,117,47,224,190,216,191,133,183,255,222,241,247,244,202,7,251,191,218,43,8,132,23,248,144,2,244,63,134,175,82,129,4,8,16,232,92,64,128,222,121,
3,149,95,92,64,128,94,156,212,130,4,138,8,8,208,139,48,90,132,64,121,1,1,122,121,83,43,118,45,32,64,95,104,159,0,189,235,185,86,252,10,2,2,177,101,84,1,250,10,3,103,201,174,5,220,23,251,183,207,167,207,
247,55,243,138,190,4,174,175,175,191,62,63,63,255,161,175,170,85,75,128,0,129,190,4,4,232,125,245,75,181,235,11,8,208,215,55,182,3,129,67,4,4,232,135,168,121,13,129,10,2,2,244,10,200,182,232,73,64,128,
190,208,45,1,122,79,99,172,214,26,2,2,177,101,101,1,122,141,9,180,71,79,2,238,139,253,186,229,211,231,251,121,121,186,91,1,159,66,239,182,117,10,39,64,160,23,1,1,122,47,157,82,103,45,1,1,122,45,105,251,
16,216,79,64,128,190,159,151,167,9,84,19,16,160,87,163,182,81,31,2,2,116,1,122,31,147,170,202,230,2,2,49,1,122,243,33,84,64,55,2,238,139,253,90,229,211,231,251,121,121,186,107,1,191,11,189,235,246,41,
158,0,129,232,2,2,244,232,29,82,95,109,1,1,122,109,113,251,17,200,19,16,160,231,57,121,138,64,117,1,1,122,117,114,27,198,22,16,160,11,208,99,79,168,234,194,8,8,196,4,232,97,134,81,33,225,5,220,23,249,
45,186,253,244,249,101,122,197,195,252,87,121,146,64,183,2,239,211,239,66,127,220,109,245,10,39,64,128,64,112,1,1,122,240,6,41,175,186,128,0,189,58,185,13,9,100,9,8,208,179,152,60,68,160,190,128,0,189,
190,185,29,67,11,8,208,23,218,227,71,184,135,158,91,197,53,16,16,136,45,163,251,17,238,13,6,210,150,161,5,220,23,249,237,73,95,155,188,72,79,191,202,127,133,39,9,244,45,224,27,217,125,247,79,245,4,8,196,
22,16,160,199,238,143,234,234,11,248,247,142,250,230,118,36,144,35,32,64,207,81,242,12,129,6,2,2,244,6,232,182,140,44,32,64,95,232,142,0,61,242,216,170,173,133,128,64,108,89,93,128,222,98,34,237,25,89,
192,125,145,223,157,244,181,201,38,60,223,132,232,254,34,48,133,192,233,233,233,95,159,60,121,242,167,41,14,235,144,4,8,16,168,44,32,64,175,12,110,187,240,2,2,244,240,45,82,224,164,2,2,244,73,27,239,216,
241,5,4,232,241,123,164,194,170,2,2,244,5,110,1,122,213,57,180,89,7,2,2,177,229,38,9,208,59,24,96,37,86,21,112,95,228,113,191,125,251,246,225,253,251,247,255,158,247,180,167,8,12,35,240,49,253,24,247,
63,12,115,26,7,33,64,128,64,32,1,1,122,160,102,40,37,132,128,0,61,68,27,20,65,224,55,2,2,116,67,65,32,168,128,0,61,104,99,148,213,74,64,128,46,64,111,53,123,246,237,76,64,32,38,64,239,108,100,149,219,
80,192,125,145,135,127,113,113,241,77,250,52,238,119,121,79,123,138,192,80,2,47,83,136,254,122,168,19,57,12,1,2,4,2,8,8,208,3,52,65,9,161,4,4,232,161,218,161,24,2,255,191,128,0,221,48,16,8,42,32,64,15,
218,24,101,181,18,16,160,11,208,91,205,158,125,59,19,16,136,9,208,59,27,89,229,54,20,112,95,228,225,167,175,75,126,76,79,126,145,247,180,167,8,140,35,144,254,195,145,31,210,143,113,255,122,156,19,57,9,
1,2,4,98,8,8,208,99,244,65,21,113,4,4,232,113,122,161,18,2,191,22,16,160,155,7,2,65,5,4,232,65,27,163,172,86,2,2,244,5,121,63,194,189,213,72,218,55,170,128,64,108,185,51,126,132,123,212,169,85,87,43,1,
247,197,110,121,63,190,125,183,145,39,134,22,240,99,220,135,110,175,195,17,32,208,74,64,128,222,74,222,190,81,5,4,232,81,59,163,174,217,5,4,232,179,79,128,243,135,21,16,160,135,109,141,194,218,8,8,208,
5,232,109,38,207,174,221,9,8,196,4,232,221,13,173,130,155,9,184,47,118,211,251,6,247,110,35,79,140,45,224,27,218,99,247,215,233,8,16,104,35,224,223,47,218,184,219,53,174,128,127,223,136,219,27,149,205,
45,32,64,159,187,255,78,31,88,64,128,30,184,57,74,107,33,32,64,23,160,183,152,59,123,118,40,32,16,19,160,119,56,182,74,110,36,224,190,216,13,159,190,38,121,149,158,122,177,251,73,79,16,24,83,192,61,49,
102,95,157,138,0,129,182,2,2,244,182,254,118,143,39,32,64,143,215,19,21,17,216,8,8,208,205,1,129,160,2,2,244,160,141,81,86,43,1,1,250,130,188,31,225,222,106,36,237,27,85,192,55,186,151,59,227,71,184,71,
157,90,117,181,18,112,95,236,150,247,53,201,110,35,79,12,47,224,235,144,225,91,236,128,4,8,212,22,16,160,215,22,183,95,116,1,1,122,244,14,169,111,86,1,1,250,172,157,119,238,240,2,190,89,21,190,69,10,172,
43,224,27,87,2,244,186,19,103,183,110,5,4,98,2,244,110,135,87,225,213,5,220,23,159,39,247,31,221,84,31,73,27,198,20,240,123,208,99,246,69,85,4,8,116,44,32,64,239,184,121,74,95,69,64,128,190,10,171,69,
9,28,45,32,64,63,154,208,2,4,214,17,16,160,175,227,106,213,110,5,4,232,2,244,110,135,87,225,117,5,4,98,2,244,186,19,103,183,158,5,220,23,59,3,244,175,206,206,206,190,239,185,199,106,39,80,66,224,250,250,
250,241,249,249,249,251,18,107,89,131,0,1,2,4,78,78,4,232,166,128,192,182,128,0,221,68,16,136,41,32,64,143,217,23,85,17,56,17,160,27,2,2,91,2,2,116,1,186,183,4,129,44,1,129,152,0,61,107,80,60,68,32,9,
184,47,62,63,6,23,23,23,223,156,158,158,126,103,88,8,16,56,121,249,244,233,211,215,28,8,16,32,64,160,140,128,0,189,140,163,85,198,17,16,160,143,211,75,39,25,75,64,128,62,86,63,157,102,32,1,1,250,64,205,
116,148,18,2,2,116,1,122,137,57,178,198,4,2,2,49,1,250,4,99,238,136,133,4,220,23,159,135,252,233,167,159,190,79,70,95,21,226,182,12,129,110,5,220,21,221,182,78,225,4,8,4,21,16,160,7,109,140,178,154,9,
8,208,155,209,219,152,192,103,5,4,232,6,132,64,80,1,1,122,208,198,40,171,149,128,0,93,128,222,106,246,236,219,153,128,111,114,11,208,59,27,89,229,54,20,112,95,124,30,63,125,61,242,99,122,226,139,134,45,
178,53,129,40,2,190,22,137,210,9,117,16,32,48,132,128,0,125,136,54,58,68,65,1,1,122,65,76,75,17,40,40,32,64,47,136,105,41,2,37,5,4,232,37,53,173,53,128,128,111,90,45,52,241,242,242,242,193,213,213,213,
207,3,244,216,17,8,20,17,16,136,45,51,166,111,84,61,74,191,207,248,178,8,180,69,8,12,32,224,190,248,124,19,125,61,50,192,144,59,66,41,129,55,233,71,184,127,89,106,49,235,16,32,64,96,118,1,1,250,236,19,
224,252,119,5,4,232,102,130,64,76,1,1,122,204,190,168,138,128,223,129,110,6,8,108,11,8,208,5,232,222,19,4,178,4,4,98,2,244,172,65,241,16,129,36,224,190,88,30,3,255,129,158,183,8,129,45,129,143,41,64,255,
3,19,2,4,8,16,40,35,32,64,47,227,104,149,113,4,4,232,227,244,210,73,198,18,16,160,143,213,79,167,25,72,192,39,62,6,106,166,163,148,16,16,160,11,208,75,204,145,53,38,16,16,136,9,208,39,24,115,71,44,36,
224,190,88,134,124,251,246,237,195,251,247,239,255,189,16,181,101,8,244,46,32,64,239,189,131,234,39,64,32,148,128,0,61,84,59,20,19,64,64,128,30,160,9,74,32,240,59,2,2,116,99,65,32,168,128,0,61,104,99,
148,213,74,64,128,46,64,111,53,123,246,237,76,64,32,38,64,239,108,100,149,219,80,192,125,225,190,104,56,126,182,238,76,32,125,2,221,247,207,58,235,153,114,9,16,136,43,32,64,143,219,27,149,181,17,16,160,
183,113,183,43,129,93,2,190,0,216,37,228,207,9,52,18,16,160,55,130,183,109,84,1,1,186,0,61,234,108,170,43,152,128,64,76,32,22,108,36,149,19,88,192,125,225,190,8,60,158,74,11,38,112,239,222,189,63,60,126,
252,248,99,176,178,148,67,128,0,129,46,5,4,232,93,182,77,209,43,10,8,208,87,196,181,52,129,35,4,4,232,71,224,121,41,129,53,5,4,232,107,234,90,187,67,1,1,186,0,189,195,177,85,114,11,1,129,152,64,172,197,
220,217,179,79,1,247,197,114,223,46,46,46,190,56,61,61,253,177,207,206,170,154,64,121,1,223,216,46,111,106,69,2,4,230,21,16,160,207,219,123,39,255,125,1,255,158,97,50,8,196,20,16,160,199,236,139,170,8,
156,8,208,13,1,129,45,1,1,186,0,221,91,130,64,150,128,64,76,128,158,53,40,30,34,144,4,220,23,203,99,144,190,22,121,145,254,244,149,65,33,64,224,70,224,250,250,250,241,249,249,249,123,30,4,8,16,32,112,
188,128,0,253,120,67,43,140,37,32,64,31,171,159,78,51,142,128,0,125,156,94,58,201,96,2,2,244,193,26,234,56,199,10,8,208,23,4,47,47,47,31,92,93,93,253,124,44,176,215,19,24,69,64,32,182,220,201,244,141,
170,71,103,103,103,151,163,244,218,57,8,28,43,224,190,88,22,20,160,31,59,93,94,63,154,128,0,125,180,142,58,15,1,2,45,5,4,232,45,245,237,29,81,64,128,30,177,43,106,34,112,114,34,64,55,5,4,130,10,8,208,
131,54,70,89,173,4,4,232,2,244,86,179,103,223,206,4,4,98,2,244,206,70,86,185,13,5,220,23,2,244,134,227,103,235,206,4,4,232,157,53,76,185,4,8,132,22,16,160,135,110,143,226,26,8,8,208,27,160,219,146,64,
134,128,0,61,3,201,35,4,90,8,8,208,91,168,219,51,176,128,0,93,128,30,120,60,149,22,73,64,32,38,64,143,52,143,106,137,45,224,190,16,160,199,158,80,213,69,18,16,160,71,234,134,90,8,16,232,93,64,128,222,
123,7,213,95,90,64,128,94,90,212,122,4,202,8,8,208,203,56,90,133,64,113,1,1,122,113,82,11,246,45,32,64,23,160,247,61,193,170,175,38,32,16,19,160,87,27,54,27,117,47,224,190,16,160,119,63,196,14,80,77,64,
128,94,141,218,70,4,8,76,32,32,64,159,160,201,142,184,151,128,0,125,47,46,15,19,168,38,32,64,175,70,109,35,2,251,9,8,208,247,243,242,244,240,2,2,116,1,250,240,67,238,128,101,4,4,98,2,244,50,147,100,149,
25,4,220,23,2,244,25,230,220,25,203,8,8,208,203,56,90,133,0,1,2,27,1,1,186,57,32,176,45,32,64,55,17,4,98,10,8,208,99,246,69,85,4,78,4,232,134,128,192,150,128,0,93,128,238,45,65,32,75,64,32,38,64,207,26,
20,15,17,72,2,238,11,1,186,55,2,129,92,1,1,122,174,148,231,8,16,32,176,91,64,128,190,219,200,19,115,9,8,208,231,234,183,211,246,35,32,64,239,167,87,42,157,76,64,128,62,89,195,29,119,151,128,0,93,128,190,
107,70,252,57,129,79,2,2,177,229,65,72,223,168,122,116,118,118,118,105,84,8,16,184,17,112,95,44,79,66,250,90,228,69,250,211,87,102,133,0,129,27,1,1,186,73,32,64,128,64,57,1,1,122,57,75,43,141,33,32,64,
31,163,143,78,49,158,128,0,125,188,158,58,209,32,2,2,244,65,26,233,24,165,4,4,232,11,146,151,151,151,15,174,174,174,126,46,5,109,29,2,189,11,8,196,150,59,40,64,239,125,186,213,95,90,192,125,177,44,42,
64,47,61,109,214,235,93,64,128,222,123,7,213,79,128,64,36,1,1,122,164,110,168,37,130,128,0,61,66,23,212,64,224,183,2,2,116,83,65,32,168,128,0,61,104,99,148,213,74,64,128,46,64,111,53,123,246,237,76,64,
32,38,64,239,108,100,149,219,80,192,125,33,64,111,56,126,182,238,76,64,128,222,89,195,148,75,128,64,104,1,1,122,232,246,40,174,129,128,0,189,1,186,45,9,100,8,8,208,51,144,60,66,160,133,128,0,189,133,186,
61,3,11,8,208,5,232,129,199,83,105,145,4,4,98,2,244,72,243,168,150,216,2,238,11,1,122,236,9,85,93,36,1,1,122,164,110,168,133,0,129,222,5,4,232,189,119,80,253,165,5,4,232,165,69,173,71,160,140,128,0,189,
140,163,85,8,20,23,16,160,23,39,181,96,223,2,2,116,1,122,223,19,172,250,106,2,2,49,1,122,181,97,179,81,247,2,238,11,1,122,247,67,236,0,213,4,4,232,213,168,109,68,128,192,4,2,2,244,9,154,236,136,123,9,
8,208,247,226,242,48,129,106,2,2,244,106,212,54,34,176,159,128,0,125,63,47,79,15,47,32,64,23,160,15,63,228,14,88,70,64,32,38,64,47,51,73,86,153,65,192,125,33,64,159,97,206,157,177,140,128,0,189,140,163,
85,8,16,32,176,17,16,160,155,3,2,219,2,2,116,19,65,32,166,128,0,61,102,95,84,69,224,68,128,110,8,8,108,9,8,208,5,232,222,18,4,178,4,4,98,2,244,172,65,241,16,129,36,224,190,16,160,123,35,16,200,21,16,160,
231,74,121,142,0,1,2,187,5,4,232,187,141,60,49,151,128,0,125,174,126,59,109,63,2,2,244,126,122,165,210,201,4,4,232,147,53,220,113,119,9,8,208,5,232,187,102,196,159,19,248,36,32,16,91,30,132,244,141,170,
71,103,103,103,151,70,133,0,129,27,1,247,197,242,36,164,175,69,94,164,63,125,101,86,8,16,184,17,16,160,155,4,2,4,8,148,19,16,160,151,179,180,210,24,2,2,244,49,250,232,20,227,9,8,208,199,235,169,19,13,
34,32,64,31,164,145,142,81,74,64,128,190,32,121,121,121,249,224,234,234,234,231,82,208,214,33,208,187,128,64,108,185,131,2,244,222,167,91,253,165,5,220,23,203,162,2,244,210,211,102,189,222,5,4,232,189,
119,80,253,4,8,68,18,16,160,71,234,134,90,34,8,8,208,35,116,65,13,4,126,43,32,64,55,21,4,130,10,8,208,131,54,70,89,173,4,4,232,2,244,86,179,103,223,206,4,4,98,2,244,206,70,86,185,13,5,220,23,2,244,134,
227,103,235,206,4,4,232,157,53,76,185,4,8,132,22,16,160,135,110,143,226,26,8,8,208,27,160,219,146,64,134,128,0,61,3,201,35,4,90,8,8,208,91,168,219,51,176,128,0,93,128,30,120,60,149,22,73,64,32,38,64,143,
52,143,106,137,45,224,190,16,160,199,158,80,213,69,18,16,160,71,234,134,90,8,16,232,93,64,128,222,123,7,213,95,90,64,128,94,90,212,122,4,202,8,8,208,203,56,90,133,64,113,1,1,122,113,82,11,246,45,32,64,
23,160,247,61,193,170,175,38,32,16,19,160,87,27,54,27,117,47,224,190,16,160,119,63,196,14,80,77,64,128,94,141,218,70,4,8,76,32,32,64,159,160,201,142,184,151,128,0,125,47,46,15,19,168,38,32,64,175,70,109,
35,2,251,9,8,208,247,243,242,244,240,2,2,116,1,250,240,67,238,128,101,4,4,98,2,244,50,147,100,149,25,4,220,23,2,244,25,230,220,25,203,8,8,208,203,56,90,133,0,1,2,27,1,1,186,57,32,176,45,32,64,55,17,4,
98,10,8,208,99,246,69,85,4,78,4,232,134,128,192,150,128,0,93,128,238,45,65,32,75,64,32,38,64,207,26,20,15,17,72,2,238,11,1,186,55,2,129,92,1,1,122,174,148,231,8,16,32,176,91,64,128,190,219,200,19,115,
9,8,208,231,234,183,211,246,35,32,64,239,167,87,42,157,76,64,128,62,89,195,29,119,151,128,0,93,128,190,107,70,252,57,129,79,2,2,177,229,65,72,223,168,122,116,118,118,118,105,84,8,16,184,17,112,95,44,79,
66,250,90,228,69,250,211,87,102,133,0,129,27,1,1,186,73,32,64,128,64,57,1,1,122,57,75,43,141,33,32,64,31,163,143,78,49,158,128,0,125,188,158,58,209,32,2,2,244,65,26,233,24,165,4,4,232,11,146,151,151,151,
15,174,174,174,126,46,5,109,29,2,189,11,8,196,150,59,40,64,239,125,186,213,95,90,192,125,177,44,42,64,47,61,109,214,235,93,64,128,222,123,7,213,79,128,64,36,1,1,122,164,110,168,37,130,128,0,61,66,23,212,
64,224,183,2,2,116,83,65,32,168,128,0,61,104,99,148,213,74,64,128,46,64,111,53,123,246,237,76,64,32,38,64,239,108,100,149,219,80,192,125,33,64,111,56,126,182,238,76,64,128,222,89,195,148,75,128,64,104,
1,1,122,232,246,40,174,129,128,0,189,1,186,45,9,100,8,8,208,51,144,60,66,160,133,128,0,189,133,186,61,3,11,8,208,5,232,129,199,83,105,145,4,4,98,2,244,72,243,168,150,216,2,238,11,1,122,236,9,85,93,36,
1,1,122,164,110,168,133,0,129,222,5,4,232,189,119,80,253,165,5,4,232,165,69,173,71,160,140,128,0,189,140,163,85,8,20,23,16,160,23,39,181,96,223,2,2,116,1,122,223,19,172,250,106,2,2,49,1,122,181,97,179,
81,247,2,238,11,1,122,247,67,236,0,213,4,4,232,213,168,109,68,128,192,4,2,2,244,9,154,236,136,123,9,8,208,247,226,242,48,129,106,2,2,244,106,212,54,34,176,159,128,0,125,63,47,79,15,47,32,64,23,160,15,
63,228,14,88,70,64,32,38,64,47,51,73,86,153,65,192,125,33,64,159,97,206,157,177,140,128,0,189,140,163,85,8,16,32,176,17,16,160,155,3,2,219,2,2,116,19,65,32,166,128,0,61,102,95,84,69,224,68,128,110,8,8,
108,9,8,208,5,232,222,18,4,178,4,4,98,2,244,172,65,241,16,129,36,224,190,16,160,123,35,16,200,21,16,160,231,74,121,142,0,1,2,187,5,4,232,187,141,60,49,151,128,0,125,174,126,59,109,63,2,2,244,126,122,165,
210,201,4,4,232,147,53,220,113,119,9,8,208,5,232,187,102,196,159,19,248,36,32,16,91,30,132,244,141,170,71,103,103,103,151,70,133,0,129,27,1,247,197,242,36,164,175,69,94,164,63,125,101,86,8,16,184,17,16,
160,155,4,2,4,8,148,19,16,160,151,179,180,210,24,2,2,244,49,250,232,20,227,9,8,208,199,235,169,19,13,34,32,64,31,164,145,142,81,74,64,128,190,32,121,121,121,249,224,234,234,234,231,82,208,214,33,208,187,
128,64,108,185,131,2,244,222,167,91,253,165,5,220,23,203,162,2,244,210,211,102,189,222,5,4,232,189,119,80,253,4,8,68,18,16,160,71,234,134,90,34,8,8,208,35,116,65,13,4,126,43,32,64,55,21,4,130,10,8,208,
131,54,70,89,173,4,4,232,2,244,86,179,103,223,206,4,4,98,2,244,206,70,86,185,13,5,220,23,2,244,134,227,103,235,206,4,4,232,157,53,76,185,4,8,132,22,16,160,135,110,143,226,26,8,8,208,27,160,219,146,64,
134,128,0,61,3,201,35,4,90,8,8,208,91,168,219,51,176,128,0,93,128,30,120,60,149,22,73,64,32,38,64,143,52,143,106,137,45,224,190,16,160,199,158,80,213,69,18,16,160,71,234,134,90,8,16,232,93,64,128,222,
123,7,213,95,90,64,128,94,90,212,122,4,202,8,8,208,203,56,90,133,64,113,1,1,122,113,82,11,246,45,32,64,23,160,247,61,193,170,175,38,32,16,19,160,87,27,54,27,117,47,224,190,16,160,119,63,196,14,80,77,64,
128,94,141,218,70,4,8,76,32,32,64,159,160,201,142,184,151,128,0,125,47,46,15,19,168,38,32,64,175,70,109,35,2,251,9,8,208,247,243,242,244,240,2,2,116,1,250,240,67,238,128,101,4,4,98,2,244,50,147,100,149,
25,4,220,23,2,244,25,230,220,25,203,8,8,208,203,56,90,133,0,1,2,27,1,1,186,57,32,176,45,32,64,55,17,4,98,10,8,208,99,246,69,85,4,78,4,232,134,128,192,150,128,0,93,128,238,45,65,32,75,64,32,38,64,207,26,
20,15,17,72,2,238,11,1,186,55,2,129,92,1,1,122,174,148,231,8,16,32,176,91,64,128,190,219,200,19,115,9,8,208,231,234,183,211,246,35,32,64,239,167,87,42,157,76,64,128,62,89,195,29,119,151,128,0,93,128,190,
107,70,252,57,129,79,2,2,177,229,65,72,223,168,122,116,118,118,118,105,84,8,16,184,17,112,95,44,79,66,250,90,228,69,250,211,87,102,133,0,129,27,1,1,186,73,32,64,128,64,57,1,1,122,57,75,43,141,33,32,64,
31,163,143,78,49,158,128,0,125,188,158,58,209,32,2,2,244,65,26,233,24,165,4,4,232,11,146,151,151,151,15,174,174,174,126,46,5,109,29,2,189,11,8,196,150,59,40,64,239,125,186,213,95,90,192,125,177,44,42,
64,47,61,109,214,235,93,64,128,222,123,7,213,79,128,64,36,1,1,122,164,110,168,37,130,128,0,61,66,23,212,64,224,183,2,2,116,83,65,32,168,128,0,61,104,99,148,213,74,64,128,46,64,111,53,123,246,237,76,64,
32,38,64,239,108,100,149,219,80,192,125,33,64,111,56,126,182,238,76,64,128,222,89,195,148,75,128,64,104,1,1,122,232,246,40,174,129,128,0,189,1,186,45,9,100,8,8,208,51,144,60,66,160,133,128,0,189,133,186,
61,3,11,8,208,5,232,129,199,83,105,145,4,4,98,2,244,72,243,168,150,216,2,238,11,1,122,236,9,85,93,36,1,1,122,164,110,168,133,0,129,222,5,4,232,189,119,80,253,165,5,4,232,165,69,173,71,160,140,128,0,189,
140,163,85,8,20,23,16,160,23,39,181,96,223,2,2,116,1,122,223,19,172,250,106,2,2,49,1,122,181,97,179,81,247,2,238,11,1,122,247,67,236,0,213,4,4,232,213,168,109,68,128,192,4,2,2,244,9,154,236,136,123,9,
8,208,247,226,242,48,129,106,2,2,244,106,212,54,34,176,159,128,0,125,63,47,79,15,47,32,64,23,160,15,63,228,14,88,70,64,32,38,64,47,51,73,86,153,65,192,125,33,64,159,97,206,157,177,140,128,0,189,140,163,
85,8,16,32,176,17,16,160,155,3,2,219,2,2,116,19,65,32,166,128,0,61,102,95,84,69,224,68,128,110,8,8,108,9,8,208,5,232,222,18,4,178,4,4,98,2,244,172,65,241,16,129,36,224,190,16,160,123,35,16,200,21,16,160,
231,74,121,142,0,1,2,187,5,4,232,187,141,60,49,151,128,0,125,174,126,59,109,63,2,2,244,126,122,165,210,201,4,4,232,147,53,220,113,119,9,8,208,5,232,187,102,196,159,19,248,36,32,16,91,30,132,244,141,170,
71,103,103,103,151,70,133,0,129,27,1,247,197,242,36,164,175,69,94,164,63,125,101,86,8,16,184,17,16,160,155,4,2,4,8,148,19,16,160,151,179,180,210,24,2,2,244,49,250,232,20,227,9,8,208,199,235,169,19,13,
34,32,64,31,164,145,142,81,74,64,128,190,32,121,121,121,249,224,234,234,234,231,82,208,214,33,208,187,128,64,108,185,131,2,244,222,167,91,253,165,5,220,23,203,162,2,244,210,211,102,189,222,5,4,232,189,
119,80,253,4,8,68,18,16,160,71,234,134,90,34,8,8,208,35,116,65,13,4,126,43,32,64,55,21,4,130,10,8,208,131,54,70,89,173,4,4,232,2,244,86,179,103,223,206,4,4,98,2,244,206,70,86,185,13,5,220,23,2,244,134,
227,103,235,206,4,4,232,157,53,76,185,4,8,132,22,16,160,135,110,143,226,26,8,8,208,27,160,219,146,64,134,128,0,61,3,201,35,4,90,8,8,208,91,168,219,51,176,128,0,93,128,30,120,60,149,22,73,64,32,38,64,143,
52,143,106,137,45,224,190,16,160,199,158,80,213,69,18,16,160,71,234,134,90,8,16,232,93,64,128,222,123,7,213,95,90,64,128,94,90,212,122,4,202,8,8,208,203,56,90,133,64,113,1,1,122,113,82,11,246,45,32,64,
23,160,247,61,193,170,175,38,32,16,19,160,87,27,54,27,117,47,224,190,16,160,119,63,196,14,80,77,64,128,94,141,218,70,4,8,76,32,32,64,159,160,201,142,184,151,128,0,125,47,46,15,19,168,38,32,64,175,70,109,
35,2,251,9,8,208,247,243,242,244,240,2,2,116,1,250,240,67,238,128,101,4,4,98,2,244,50,147,100,149,25,4,220,23,2,244,25,230,220,25,203,8,8,208,203,56,90,133,0,1,2,27,1,1,186,57,32,176,45,32,64,55,17,4,
98,10,8,208,99,246,69,85,4,78,4,232,134,128,192,150,128,0,93,128,238,45,65,32,75,64,32,38,64,207,26,20,15,17,72,2,238,11,1,186,55,2,129,92,1,1,122,174,148,231,8,16,32,176,91,64,128,190,219,200,19,115,
9,8,208,231,234,183,211,246,35,32,64,239,167,87,42,157,76,64,128,62,89,195,29,119,151,128,0,93,128,190,107,70,252,57,129,79,2,2,177,229,65,72,223,168,122,116,118,118,118,105,84,8,16,184,17,112,95,44,79,
66,250,90,228,69,250,211,87,102,133,0,129,27,1,1,186,73,32,64,128,64,57,1,1,122,57,75,43,141,33,32,64,31,163,143,78,49,158,128,0,125,188,158,58,209,32,2,2,244,65,26,233,24,165,4,4,232,11,146,151,151,151,
15,174,174,174,126,46,5,109,29,2,189,11,8,196,150,59,40,64,239,125,186,213,95,90,192,125,177,44,42,64,47,61,109,214,235,93,64,128,222,123,7,213,79,128,64,36,1,1,122,164,110,168,37,130,128,0,61,66,23,212,
64,224,183,2,2,116,83,65,32,168,128,0,61,104,99,148,213,74,64,128,46,64,111,53,123,246,237,76,64,32,38,64,239,108,100,149,219,80,192,125,33,64,111,56,126,182,238,76,64,128,222,89,195,148,75,128,64,104,
1,1,122,232,246,40,174,129,128,0,189,1,186,45,9,100,8,8,208,51,144,60,66,160,133,128,0,189,133,186,61,3,11,8,208,5,232,129,199,83,105,145,4,4,98,2,244,72,243,168,150,216,2,238,11,1,122,236,9,85,93,36,
1,1,122,164,110,168,133,0,129,222,5,4,232,189,119,80,253,165,5,4,232,165,69,173,71,160,140,128,0,189,140,163,85,8,20,23,16,160,23,39,181,96,223,2,2,116,1,122,223,19,172,250,106,2,2,49,1,122,181,97,179,
81,247,2,238,11,1,122,247,67,236,0,213,4,4,232,213,168,109,68,128,192,4,2,2,244,9,154,236,136,123,9,8,208,247,226,242,48,129,106,2,2,244,106,212,54,34,176,159,128,0,125,63,47,79,15,47,32,64,23,160,15,
63,228,14,88,70,64,32,38,64,47,51,73,86,153,65,192,125,33,64,159,97,206,157,177,140,128,0,189,140,163,85,8,16,32,176,17,16,160,155,3,2,219,2,2,116,19,65,32,166,128,0,61,102,95,84,69,224,68,128,110,8,8,
108,9,8,208,5,232,222,18,4,178,4,4,98,2,244,172,65,241,16,129,36,224,190,16,160,123,35,16,200,21,16,160,231,74,121,142,0,1,2,187,5,4,232,187,141,60,49,151,128,0,125,174,126,59,109,63,2,2,244,126,122,165,
210,201,4,4,232,147,53,220,113,119,9,8,208,5,232,187,102,196,159,19,248,36,32,16,91,30,132,244,141,170,71,103,103,103,151,70,133,0,129,27,1,247,197,242,36,164,175,69,94,164,63,125,101,86,8,16,184,17,16,
160,155,4,2,4,8,148,19,16,160,151,179,180,210,24,2,2,244,49,250,232,20,227,9,8,208,199,235,169,19,13,34,32,64,31,164,145,142,81,74,64,128,190,32,121,121,121,249,224,234,234,234,231,82,208,214,33,208,187,
128,64,108,185,131,2,244,222,167,91,253,165,5,220,23,203,162,2,244,210,211,102,189,222,5,4,232,189,119,80,253,4,8,68,18,16,160,71,234,134,90,34,8,8,208,35,116,65,13,4,126,43,32,64,55,21,4,130,10,8,208,
131,54,70,89,173,4,4,232,2,244,86,179,103,223,206,4,4,98,2,244,206,70,86,185,13,5,220,23,2,244,134,227,103,235,206,4,4,232,157,53,76,185,4,8,132,22,16,160,135,110,143,226,26,8,8,208,27,160,219,146,64,
134,128,0,61,3,201,35,4,90,8,8,208,91,168,219,51,176,128,0,93,128,30,120,60,149,22,73,64,32,38,64,143,52,143,106,137,45,224,190,16,160,199,158,80,213,69,18,16,160,71,234,134,90,8,16,232,93,64,128,222,
123,7,213,95,90,64,128,94,90,212,122,4,202,8,8,208,203,56,90,133,64,113,1,1,122,113,82,11,246,45,32,64,23,160,247,61,193,170,175,38,32,16,19,160,87,27,54,27,117,47,224,190,16,160,119,63,196,14,80,77,64,
128,94,141,218,70,4,8,76,32,32,64,159,160,201,142,184,151,128,0,125,47,46,15,19,168,38,32,64,175,70,109,35,2,251,9,8,208,247,243,242,244,240,2,2,116,1,250,240,67,238,128,101,4,4,98,2,244,50,147,100,149,
25,4,220,23,2,244,25,230,220,25,203,8,8,208,203,56,90,133,0,1,2,27,1,1,186,57,32,176,45,32,64,55,17,4,98,10,8,208,99,246,69,85,4,78,4,232,134,128,192,150,128,0,93,128,238,45,65,32,75,64,32,38,64,207,26,
20,15,17,72,2,238,11,1,186,55,2,129,92,1,1,122,174,148,231,8,16,32,176,91,64,128,190,219,200,19,115,9,8,208,231,234,183,211,246,35,32,64,239,167,87,42,157,76,64,128,62,89,195,29,119,151,128,0,93,128,190,
107,70,252,57,129,79,2,2,177,229,65,72,223,168,122,116,118,118,118,105,84,8,16,184,17,112,95,44,79,66,250,90,228,69,250,211,87,102,133,0,129,27,1,1,186,73,32,64,128,64,57,1,1,122,57,75,43,141,33,32,64,
31,163,143,78,49,158,128,0,125,188,158,58,209,32,2,2,244,65,26,233,24,165,4,4,232,11,146,151,151,151,15,174,174,174,126,46,5,109,29,2,189,11,8,196,150,59,40,64,239,125,186,213,95,90,192,125,177,44,42,
64,47,61,109,214,235,93,64,128,222,123,7,213,79,128,64,36,1,1,122,164,110,168,37,130,128,0,61,66,23,212,64,224,183,2,2,116,83,65,32,168,128,0,61,104,99,148,213,74,64,128,46,64,111,53,123,246,237,76,64,
32,38,64,239,108,100,149,219,80,192,125,33,64,111,56,126,182,238,76,64,128,222,89,195,148,75,128,64,104,1,1,122,232,246,40,174,129,128,0,189,1,186,45,9,100,8,8,208,51,144,60,66,160,133,128,0,189,133,186,
61,3,11,8,208,5,232,129,199,83,105,145,4,4,98,2,244,72,243,168,150,216,2,238,11,1,122,236,9,85,93,36,1,1,122,164,110,168,133,0,129,222,5,4,232,189,119,80,253,165,5,4,232,165,69,173,71,160,140,128,0,189,
140,163,85,8,20,23,16,160,23,39,181,96,223,2,2,116,1,122,223,19,172,250,106,2,2,49,1,122,181,97,179,81,247,2,238,11,1,122,247,67,236,0,213,4,4,232,213,168,109,68,128,192,4,2,2,244,9,154,236,136,123,9,
8,208,247,226,242,48,129,106,2,2,244,106,212,54,34,176,159,128,0,125,63,47,79,15,47,32,64,23,160,15,63,228,14,88,70,64,32,38,64,47,51,73,86,153,65,192,125,33,64,159,97,206,157,177,140,128,0,189,140,163,
85,8,16,32,176,17,16,160,155,3,2,219,2,2,116,19,65,32,166,128,0,61,102,95,84,69,224,68,128,110,8,8,108,9,8,208,5,232,222,18,4,178,4,4,98,2,244,172,65,241,16,129,36,224,190,16,160,123,35,16,200,21,16,160,
231,74,121,142,0,1,2,187,5,4,232,187,141,60,49,151,128,0,125,174,126,59,109,63,2,2,244,126,122,165,210,201,4,4,232,147,53,220,113,119,9,8,208,5,232,187,102,196,159,19,248,36,32,16,91,30,132,244,141,170,
71,103,103,103,151,70,133,0,129,27,1,247,197,242,36,164,175,69,94,164,63,125,101,86,8,16,184,17,16,160,155,4,222,163,161,95,0,0,32,0,73,68,65,84,2,4,8,148,19,16,160,151,179,180,210,24,2,2,244,49,250,232,
20,227,9,8,208,199,235,169,19,13,34,32,64,31,164,145,142,81,74,64,128,190,32,121,121,121,249,224,234,234,234,231,82,208,214,33,208,187,128,64,108,185,131,2,244,222,167,91,253,165,5,220,23,203,162,2,244,
210,211,102,189,222,5,4,232,189,119,80,253,4,8,68,18,16,160,71,234,134,90,34,8,8,208,35,116,65,13,4,126,43,32,64,55,21,4,130,10,8,208,131,54,70,89,173,4,4,232,2,244,86,179,103,223,206,4,4,98,2,244,206,
70,86,185,13,5,220,23,2,244,134,227,103,235,206,4,4,232,157,53,76,185,4,8,132,22,16,160,135,110,143,226,26,8,8,208,27,160,219,146,64,134,128,0,61,3,201,35,4,90,8,8,208,91,168,219,51,176,128,0,93,128,30,
120,60,149,22,73,64,32,38,64,143,52,143,106,137,45,224,190,16,160,199,158,80,213,69,18,16,160,71,234,134,90,8,16,232,93,64,128,222,123,7,213,95,90,64,128,94,90,212,122,4,202,8,8,208,203,56,90,133,64,113,
1,1,122,113,82,11,246,45,32,64,23,160,247,61,193,170,175,38,32,16,19,160,87,27,54,27,117,47,224,190,16,160,119,63,196,14,80,77,64,128,94,141,218,70,4,8,76,32,32,64,159,160,201,142,184,151,128,0,125,47,
46,15,19,168,38,32,64,175,70,109,35,2,251,9,8,208,247,243,242,244,240,2,2,116,1,250,240,67,238,128,101,4,4,98,2,244,50,147,100,149,25,4,220,23,2,244,25,230,220,25,203,8,8,208,203,56,90,133,0,1,2,27,1,
1,186,57,32,176,45,32,64,55,17,4,98,10,8,208,99,246,69,85,4,78,4,232,134,128,192,150,128,0,93,128,238,45,65,32,75,64,32,38,64,207,26,20,15,17,72,2,238,11,1,186,55,2,129,92,1,1,122,174,148,231,8,16,32,
176,91,64,128,190,219,200,19,115,9,8,208,231,234,183,211,246,35,32,64,239,167,87,42,157,76,64,128,62,89,195,29,119,151,128,0,93,128,190,107,70,252,57,129,79,2,2,177,229,65,72,223,168,122,116,118,118,118,
105,84,8,16,184,17,112,95,44,79,66,250,90,228,69,250,211,87,102,133,0,129,27,1,1,186,73,32,64,128,64,57,1,1,122,57,75,43,141,33,32,64,31,163,143,78,49,158,128,0,125,188,158,58,209,32,2,2,244,65,26,233,
24,165,4,4,232,11,146,151,151,151,15,174,174,174,126,46,5,109,29,2,189,11,8,196,150,59,40,64,239,125,186,213,95,90,192,125,177,44,42,64,47,61,109,214,235,93,64,128,222,123,7,213,79,128,64,36,1,1,122,164,
110,168,37,130,128,0,61,66,23,212,64,224,183,2,2,116,83,65,32,168,128,0,61,104,99,148,213,74,64,128,46,64,111,53,123,246,237,76,64,32,38,64,239,108,100,149,219,80,192,125,33,64,111,56,126,182,238,76,64,
128,222,89,195,148,75,128,64,104,1,1,122,232,246,40,174,129,128,0,189,1,186,45,9,100,8,8,208,51,144,60,66,160,133,128,0,189,133,186,61,3,11,8,208,5,232,129,199,83,105,145,4,4,98,2,244,72,243,168,150,216,
2,238,11,1,122,236,9,85,93,36,1,1,122,164,110,168,133,0,129,222,5,4,232,189,119,80,253,165,5,4,232,165,69,173,71,160,140,128,0,189,140,163,85,8,20,23,16,160,23,39,181,96,223,2,2,116,1,122,223,19,172,250,
106,2,2,49,1,122,181,97,179,81,247,2,238,11,1,122,247,67,236,0,213,4,4,232,213,168,109,68,128,192,4,2,2,244,9,154,236,136,123,9,8,208,247,226,242,48,129,106,2,2,244,106,212,54,34,176,159,128,0,125,63,
47,79,15,47,32,64,23,160,15,63,228,14,88,70,64,32,38,64,47,51,73,86,153,65,192,125,33,64,159,97,206,157,177,140,128,0,189,140,163,85,8,16,32,176,17,16,160,155,3,2,219,2,2,116,19,65,32,166,128,0,61,102,
95,84,69,224,68,128,110,8,8,108,9,8,208,5,232,222,18,4,178,4,4,98,2,244,172,65,241,16,129,36,224,190,16,160,123,35,16,200,21,16,160,231,74,121,142,0,1,2,187,5,4,232,187,141,60,49,151,128,0,125,174,126,
59,109,63,2,2,244,126,122,165,210,201,4,4,232,147,53,220,113,119,9,8,208,5,232,187,102,196,159,19,248,36,32,16,91,30,132,244,141,170,71,103,103,103,151,70,133,0,129,27,1,247,197,242,36,164,175,69,94,164,
63,125,101,86,8,16,184,17,16,160,155,4,2,4,8,148,19,16,160,151,179,180,210,24,2,2,244,49,250,232,20,227,9,8,208,199,235,169,19,13,34,32,64,31,164,145,142,81,74,64,128,190,32,121,121,121,249,224,234,234,
234,231,82,208,214,33,208,187,128,64,108,185,131,2,244,222,167,91,253,165,5,220,23,203,162,2,244,210,211,102,189,222,5,4,232,189,119,80,253,4,8,68,18,16,160,71,234,134,90,34,8,8,208,35,116,65,13,4,126,
43,32,64,55,21,4,130,10,8,208,131,54,70,89,173,4,4,232,2,244,86,179,103,223,206,4,4,98,2,244,206,70,86,185,13,5,220,23,2,244,134,227,103,235,206,4,4,232,157,53,76,185,4,8,132,22,16,160,135,110,143,226,
26,8,8,208,27,160,219,146,64,134,128,0,61,3,201,35,4,90,8,8,208,91,168,219,51,176,128,0,93,128,30,120,60,149,22,73,64,32,38,64,143,52,143,106,137,45,224,190,16,160,199,158,80,213,69,18,16,160,71,234,134,
90,8,16,232,93,64,128,222,123,7,213,95,90,64,128,94,90,212,122,4,202,8,8,208,203,56,90,133,64,113,1,1,122,113,82,11,246,45,32,64,23,160,247,61,193,170,175,38,32,16,19,160,87,27,54,27,117,47,224,190,16,
160,119,63,196,14,80,77,64,128,94,141,218,70,4,8,76,32,32,64,159,160,201,142,184,151,128,0,125,47,46,15,19,168,38,32,64,175,70,109,35,2,251,9,8,208,247,243,242,244,240,2,2,116,1,250,240,67,238,128,101,
4,4,98,2,244,50,147,100,149,25,4,220,23,2,244,25,230,220,25,203,8,8,208,203,56,90,133,0,1,2,27,1,1,186,57,32,176,45,32,64,55,17,4,98,10,252,127,236,221,95,174,38,87,86,166,113,231,177,64,92,38,35,232,
98,6,182,252,71,226,174,106,4,109,102,0,35,232,234,17,0,35,168,102,4,84,143,32,233,17,80,125,85,23,150,117,170,71,64,205,192,190,68,136,35,117,164,211,72,156,118,127,185,98,101,198,249,98,175,120,127,
37,33,132,98,101,196,94,207,187,214,198,153,79,157,52,129,190,102,46,78,133,192,39,4,186,33,64,224,25,1,2,157,64,183,18,8,236,34,64,136,17,232,187,6,69,17,2,27,1,247,5,129,110,17,16,216,75,128,64,223,
75,74,29,2,8,32,80,19,32,208,107,70,42,178,8,16,232,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,2,157,64,175,102,196,115,4,126,36,64,136,221,30,132,237,15,170,62,123,120,120,120,
52,42,8,32,240,142,128,251,226,246,36,108,191,23,249,102,123,250,198,172,32,128,192,59,2,4,186,73,64,0,1,4,142,35,64,160,31,199,210,155,174,65,128,64,191,70,142,186,184,30,1,2,253,122,153,234,232,34,4,
8,244,139,4,169,141,163,8,16,232,55,72,62,62,62,190,126,122,122,250,254,40,208,222,131,192,116,2,132,216,237,4,9,244,233,211,237,252,71,19,112,95,220,38,74,160,31,61,109,222,55,157,0,129,62,61,65,231,
71,0,129,149,8,16,232,43,165,225,44,43,16,32,208,87,72,193,25,16,248,57,1,2,221,84,32,176,40,1,2,125,209,96,28,235,44,2,4,58,129,126,214,236,249,238,48,2,132,24,129,62,108,100,29,247,68,2,238,11,2,253,
196,241,243,233,97,4,8,244,97,129,57,46,2,8,44,77,128,64,95,58,30,135,59,129,0,129,126,2,116,159,68,96,7,1,2,125,7,36,37,8,156,65,128,64,63,131,186,111,46,76,128,64,39,208,23,30,79,71,91,137,0,33,70,160,
175,52,143,206,178,54,1,247,5,129,190,246,132,58,221,74,4,8,244,149,210,112,22,4,16,152,78,128,64,159,158,160,243,31,77,128,64,63,154,168,247,33,112,12,1,2,253,24,142,222,130,192,225,4,8,244,195,145,122,
225,108,2,4,58,129,62,123,130,157,254,110,4,8,49,2,253,110,195,230,67,227,9,184,47,8,244,241,67,172,129,187,17,32,208,239,134,218,135,16,64,32,128,0,129,30,16,178,22,91,4,8,244,22,46,197,8,220,141,0,129,
126,55,212,62,132,64,143,0,129,222,227,165,250,242,4,8,116,2,253,242,67,174,193,99,8,16,98,4,250,49,147,228,45,9,4,220,23,4,122,194,156,235,241,24,2,4,250,49,28,189,5,1,4,16,120,75,128,64,55,7,8,60,39,
64,160,155,8,4,214,36,64,160,175,153,139,83,33,240,9,129,110,8,16,120,70,128,64,39,208,173,4,2,187,8,16,98,4,250,174,65,81,132,192,70,192,125,65,160,91,4,4,246,18,32,208,247,146,82,135,0,2,8,212,4,8,244,
154,145,138,44,2,4,122,86,222,186,157,67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,129,31,9,16,98,183,7,97,251,131,170,207,30,30,30,30,141,10,2,8,188,35,224,190,
184,61,9,219,239,69,190,217,158,190,49,43,8,32,240,142,0,129,110,18,16,64,0,129,227,8,16,232,199,177,244,166,107,16,32,208,175,145,163,46,174,71,128,64,191,94,166,58,186,8,1,2,253,34,65,106,227,40,2,4,
250,13,146,143,143,143,175,159,158,158,190,63,10,180,247,32,48,157,0,33,118,59,65,2,125,250,116,59,255,209,4,220,23,183,137,18,232,71,79,155,247,77,39,64,160,79,79,208,249,17,64,96,37,2,4,250,74,105,56,
203,10,4,8,244,21,82,112,6,4,126,78,128,64,55,21,8,44,74,128,64,95,52,24,199,58,139,0,129,78,160,159,53,123,190,59,140,0,33,70,160,15,27,89,199,61,145,128,251,130,64,63,113,252,124,122,24,1,2,125,88,96,
142,139,0,2,75,19,32,208,151,142,199,225,78,32,64,160,159,0,221,39,17,216,65,128,64,223,1,73,9,2,103,16,32,208,207,160,238,155,11,19,32,208,9,244,133,199,211,209,86,34,64,136,17,232,43,205,163,179,172,
77,192,125,65,160,175,61,161,78,183,18,1,2,125,165,52,156,5,1,4,166,19,32,208,167,39,232,252,71,19,32,208,143,38,234,125,8,28,67,128,64,63,134,163,183,32,112,56,1,2,253,112,164,94,56,155,0,129,78,160,
207,158,96,167,191,27,1,66,140,64,191,219,176,249,208,120,2,238,11,2,125,252,16,107,224,110,4,8,244,187,161,246,33,4,16,8,32,64,160,7,132,172,197,22,1,2,189,133,75,49,2,119,35,64,160,223,13,181,15,33,
208,35,64,160,247,120,169,190,60,1,2,157,64,191,252,144,107,240,24,2,132,24,129,126,204,36,121,75,2,1,247,5,129,158,48,231,122,60,134,0,129,126,12,71,111,65,0,1,4,222,18,32,208,205,1,2,207,9,16,232,38,
2,129,53,9,16,232,107,230,226,84,8,124,66,160,27,2,4,158,17,32,208,9,116,43,129,192,46,2,132,24,129,190,107,80,20,33,176,17,112,95,16,232,22,1,129,189,4,8,244,189,164,212,33,128,0,2,53,1,2,189,102,164,
34,139,0,129,158,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,224,71,2,132,216,237,65,216,254,160,234,179,135,135,135,71,163,130,0,2,239,8,184,47,110,
79,194,246,123,145,111,182,167,111,204,10,2,8,188,35,64,160,155,4,4,16,64,224,56,2,4,250,113,44,189,233,26,4,8,244,107,228,168,139,235,17,32,208,175,151,169,142,46,66,128,64,191,72,144,218,56,138,0,129,
126,131,228,227,227,227,235,167,167,167,239,143,2,237,61,8,76,39,64,136,221,78,144,64,159,62,221,206,127,52,1,247,197,109,162,4,250,209,211,230,125,211,9,16,232,211,19,116,126,4,16,88,137,0,129,190,82,
26,206,178,2,1,2,125,133,20,156,1,129,159,19,32,208,77,5,2,139,18,32,208,23,13,198,177,206,34,64,160,19,232,103,205,158,239,14,35,64,136,17,232,195,70,214,113,79,36,224,190,32,208,79,28,63,159,30,70,128,
64,31,22,152,227,34,128,192,210,4,8,244,165,227,113,184,19,8,16,232,39,64,247,73,4,118,16,32,208,119,64,82,130,192,25,4,8,244,51,168,251,230,194,4,8,116,2,125,225,241,116,180,149,8,16,98,4,250,74,243,
232,44,107,19,112,95,16,232,107,79,168,211,173,68,128,64,95,41,13,103,65,0,129,233,4,8,244,233,9,58,255,209,4,8,244,163,137,122,31,2,199,16,32,208,143,225,232,45,8,28,78,128,64,63,28,169,23,206,38,64,
160,19,232,179,39,216,233,239,70,128,16,35,208,239,54,108,62,52,158,128,251,130,64,31,63,196,26,184,27,1,2,253,110,168,125,8,1,4,2,8,16,232,1,33,107,177,69,128,64,111,225,82,140,192,221,8,16,232,119,67,
237,67,8,244,8,16,232,61,94,170,47,79,128,64,39,208,47,63,228,26,60,134,0,33,70,160,31,51,73,222,146,64,192,125,65,160,39,204,185,30,143,33,64,160,31,195,209,91,16,64,0,129,183,4,8,116,115,128,192,115,
2,4,186,137,64,96,77,2,4,250,154,185,56,21,2,159,16,232,134,0,129,103,4,8,116,2,221,74,32,176,139,0,33,70,160,239,26,20,69,8,108,4,220,23,4,186,69,64,96,47,1,2,125,47,41,117,8,32,128,64,77,128,64,175,
25,169,200,34,64,160,103,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,248,145,0,33,118,123,16,182,63,168,250,236,225,225,225,209,168,32,128,192,59,2,238,139,
219,147,176,253,94,228,155,237,233,27,179,130,0,2,239,8,16,232,38,1,1,4,16,56,142,0,129,126,28,75,111,186,6,1,2,253,26,57,234,226,122,4,8,244,235,101,170,163,139,16,32,208,47,18,164,54,142,34,64,160,223,
32,249,248,248,248,250,233,233,233,251,163,64,123,15,2,211,9,16,98,183,19,36,208,167,79,183,243,31,77,192,125,113,155,40,129,126,244,180,121,223,116,2,4,250,244,4,157,31,1,4,86,34,64,160,175,148,134,179,
172,64,128,64,95,33,5,103,64,224,231,4,8,116,83,129,192,162,4,8,244,69,131,113,172,179,8,16,232,4,250,89,179,231,187,195,8,16,98,4,250,176,145,117,220,19,9,184,47,8,244,19,199,207,167,135,17,32,208,135,
5,230,184,8,32,176,52,1,2,125,233,120,28,238,4,2,4,250,9,208,125,18,129,29,4,8,244,29,144,148,32,112,6,1,2,253,12,234,190,185,48,1,2,157,64,95,120,60,29,109,37,2,132,24,129,190,210,60,58,203,218,4,220,
23,4,250,218,19,234,116,43,17,32,208,87,74,195,89,16,64,96,58,1,2,125,122,130,206,127,52,1,2,253,104,162,222,135,192,49,4,8,244,99,56,122,11,2,135,19,32,208,15,71,234,133,179,9,16,232,4,250,236,9,118,
250,187,17,32,196,8,244,187,13,155,15,141,39,224,190,32,208,199,15,177,6,238,70,128,64,191,27,106,31,66,0,129,0,2,4,122,64,200,90,108,17,32,208,91,184,20,35,112,55,2,4,250,221,80,251,16,2,61,2,4,122,143,
151,234,203,19,32,208,9,244,203,15,185,6,143,33,64,136,17,232,199,76,146,183,36,16,112,95,16,232,9,115,174,199,99,8,16,232,199,112,244,22,4,16,64,224,45,1,2,221,28,32,240,156,0,129,110,34,16,88,147,0,
129,190,102,46,78,133,192,39,4,186,33,64,224,25,1,2,157,64,183,18,8,236,34,64,136,17,232,187,6,69,17,2,27,1,247,5,129,110,17,16,216,75,128,64,223,75,74,29,2,8,32,80,19,32,208,107,70,42,178,8,16,232,89,
121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,2,157,64,175,102,196,115,4,126,36,64,136,221,30,132,237,15,170,62,123,120,120,120,52,42,8,32,240,142,128,251,226,246,36,108,191,23,249,102,
123,250,198,172,32,128,192,59,2,4,186,73,64,0,1,4,142,35,64,160,31,199,210,155,174,65,128,64,191,70,142,186,184,30,1,2,253,122,153,234,232,34,4,8,244,139,4,169,141,163,8,16,232,55,72,62,62,62,190,126,
122,122,250,254,40,208,222,131,192,116,2,132,216,237,4,9,244,233,211,237,252,71,19,112,95,220,38,74,160,31,61,109,222,55,157,0,129,62,61,65,231,71,0,129,149,8,16,232,43,165,225,44,43,16,32,208,87,72,193,
25,16,248,57,1,2,221,84,32,176,40,1,2,125,209,96,28,235,44,2,4,58,129,126,214,236,249,238,48,2,132,24,129,62,108,100,29,247,68,2,238,11,2,253,196,241,243,233,97,4,8,244,97,129,57,46,2,8,44,77,128,64,95,
58,30,135,59,129,0,129,126,2,116,159,68,96,7,1,2,125,7,36,37,8,156,65,128,64,63,131,186,111,46,76,128,64,39,208,23,30,79,71,91,137,0,33,70,160,175,52,143,206,178,54,1,247,5,129,190,246,132,58,221,74,4,
8,244,149,210,112,22,4,16,152,78,128,64,159,158,160,243,31,77,128,64,63,154,168,247,33,112,12,1,2,253,24,142,222,130,192,225,4,8,244,195,145,122,225,108,2,4,58,129,62,123,130,157,254,110,4,8,49,2,253,
110,195,230,67,227,9,184,47,8,244,241,67,172,129,187,17,32,208,239,134,218,135,16,64,32,128,0,129,30,16,178,22,91,4,8,244,22,46,197,8,220,141,0,129,126,55,212,62,132,64,143,0,129,222,227,165,250,242,4,
8,116,2,253,242,67,174,193,99,8,16,98,4,250,49,147,228,45,9,4,220,23,4,122,194,156,235,241,24,2,4,250,49,28,189,5,1,4,16,120,75,128,64,55,7,8,60,39,64,160,155,8,4,214,36,64,160,175,153,139,83,33,240,9,
129,110,8,16,120,70,128,64,39,208,173,4,2,187,8,16,98,4,250,174,65,81,132,192,70,192,125,65,160,91,4,4,246,18,32,208,247,146,82,135,0,2,8,212,4,8,244,154,145,138,44,2,4,122,86,222,186,157,67,128,64,159,
147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,129,31,9,16,98,183,7,97,251,131,170,207,30,30,30,30,141,10,2,8,188,35,224,190,184,61,9,219,239,69,190,217,158,190,49,43,8,32,240,
142,0,129,110,18,16,64,0,129,227,8,16,232,199,177,244,166,107,16,32,208,175,145,163,46,174,71,128,64,191,94,166,58,186,8,1,2,253,34,65,106,227,40,2,4,250,13,146,143,143,143,175,159,158,158,190,63,10,180,
247,32,48,157,0,33,118,59,65,2,125,250,116,59,255,209,4,220,23,183,137,18,232,71,79,155,247,77,39,64,160,79,79,208,249,17,64,96,37,2,4,250,74,105,56,203,10,4,8,244,21,82,112,6,4,126,78,128,64,55,21,8,
44,74,128,64,95,52,24,199,58,139,0,129,78,160,159,53,123,190,59,140,0,33,70,160,15,27,89,199,61,145,128,251,130,64,63,113,252,124,122,24,1,2,125,88,96,142,139,0,2,75,19,32,208,151,142,199,225,78,32,64,
160,159,0,221,39,17,216,65,128,64,223,1,73,9,2,103,16,32,208,207,160,238,155,11,19,32,208,9,244,133,199,211,209,86,34,64,136,17,232,43,205,163,179,172,77,192,125,65,160,175,61,161,78,183,18,1,2,125,165,
52,156,5,1,4,166,19,32,208,167,39,232,252,71,19,32,208,143,38,234,125,8,28,67,128,64,63,134,163,183,32,112,56,1,2,253,112,164,94,56,155,0,129,78,160,207,158,96,167,191,27,1,66,140,64,191,219,176,249,208,
120,2,238,11,2,125,252,16,107,224,110,4,8,244,187,161,246,33,4,16,8,32,64,160,7,132,172,197,22,1,2,189,133,75,49,2,119,35,64,160,223,13,181,15,33,208,35,64,160,247,120,169,190,60,1,2,157,64,191,252,144,
107,240,24,2,132,24,129,126,204,36,121,75,2,1,247,5,129,158,48,231,122,60,134,0,129,126,12,71,111,65,0,1,4,222,18,32,208,205,1,2,207,9,16,232,38,2,129,53,9,16,232,107,230,226,84,8,124,66,160,27,2,4,158,
17,32,208,9,116,43,129,192,46,2,132,24,129,190,107,80,20,33,176,17,112,95,16,232,22,1,129,189,4,8,244,189,164,212,33,128,0,2,53,1,2,189,102,164,34,139,0,129,158,149,183,110,231,16,32,208,231,100,229,164,
97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,224,71,2,132,216,237,65,216,254,160,234,179,135,135,135,71,163,130,0,2,239,8,184,47,110,79,194,246,123,145,111,182,167,111,204,10,2,8,188,35,64,160,
155,4,4,16,64,224,56,2,4,250,113,44,189,233,26,4,8,244,107,228,168,139,235,17,32,208,175,151,169,142,46,66,128,64,191,72,144,218,56,138,0,129,126,131,228,227,227,227,235,167,167,167,239,143,2,237,61,8,
76,39,64,136,221,78,144,64,159,62,221,206,127,52,1,247,197,109,162,4,250,209,211,230,125,211,9,16,232,211,19,116,126,4,16,88,137,0,129,190,82,26,206,178,2,1,2,125,133,20,156,1,129,159,19,32,208,77,5,2,
139,18,32,208,23,13,198,177,206,34,64,160,19,232,103,205,158,239,14,35,64,136,17,232,195,70,214,113,79,36,224,190,32,208,79,28,63,159,30,70,128,64,31,22,152,227,34,128,192,210,4,8,244,165,227,113,184,
19,8,16,232,39,64,247,73,4,118,16,32,208,119,64,82,130,192,25,4,8,244,51,168,251,230,194,4,8,116,2,125,225,241,116,180,149,8,16,98,4,250,74,243,232,44,107,19,112,95,16,232,107,79,168,211,173,68,128,64,
95,41,13,103,65,0,129,233,4,8,244,233,9,58,255,209,4,8,244,163,137,122,31,2,199,16,32,208,143,225,232,45,8,28,78,128,64,63,28,169,23,206,38,64,160,19,232,179,39,216,233,239,70,128,16,35,208,239,54,108,
62,52,158,128,251,130,64,31,63,196,26,184,27,1,2,253,110,168,125,8,1,4,2,8,16,232,1,33,107,177,69,128,64,111,225,82,140,192,221,8,16,232,119,67,237,67,8,244,8,16,232,61,94,170,47,79,128,64,39,208,47,63,
228,26,60,134,0,33,70,160,31,51,73,222,146,64,192,125,65,160,39,204,185,30,143,33,64,160,31,195,209,91,16,64,0,129,183,4,8,116,115,128,192,115,2,4,186,137,64,96,77,2,4,250,154,185,56,21,2,159,16,232,134,
0,129,103,4,8,116,2,221,74,32,176,139,0,33,70,160,239,26,20,69,8,108,4,220,23,4,186,69,64,96,47,1,2,125,47,41,117,8,32,128,64,77,128,64,175,25,169,200,34,64,160,103,229,173,219,57,4,8,244,57,89,57,105,
24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,248,145,0,33,118,123,16,182,63,168,250,236,225,225,225,209,168,32,128,192,59,2,238,139,219,147,176,253,94,228,155,237,233,27,179,130,0,2,239,8,16,232,
38,1,1,4,16,56,142,0,129,126,28,75,111,186,6,1,2,253,26,57,234,226,122,4,8,244,235,101,170,163,139,16,32,208,47,18,164,54,142,34,64,160,223,32,249,248,248,248,250,233,233,233,251,163,64,123,15,2,211,9,
16,98,183,19,36,208,167,79,183,243,31,77,192,125,113,155,40,129,126,244,180,121,223,116,2,4,250,244,4,157,31,1,4,86,34,64,160,175,148,134,179,172,64,128,64,95,33,5,103,64,224,231,4,8,116,83,129,192,162,
4,8,244,69,131,113,172,179,8,16,232,4,250,89,179,231,187,195,8,16,98,4,250,176,145,117,220,19,9,184,47,8,244,19,199,207,167,135,17,32,208,135,5,230,184,8,32,176,52,1,2,125,233,120,28,238,4,2,4,250,9,208,
125,18,129,29,4,8,244,29,144,148,32,112,6,1,2,253,12,234,190,185,48,1,2,157,64,95,120,60,29,109,37,2,132,24,129,190,210,60,58,203,218,4,220,23,4,250,218,19,234,116,43,17,32,208,87,74,195,89,16,64,96,58,
1,2,125,122,130,206,127,52,1,2,253,104,162,222,135,192,49,4,8,244,99,56,122,11,2,135,19,32,208,15,71,234,133,179,9,16,232,4,250,236,9,118,250,187,17,32,196,8,244,187,13,155,15,141,39,224,190,32,208,199,
15,177,6,238,70,128,64,191,27,106,31,66,0,129,0,2,4,122,64,200,90,108,17,32,208,91,184,20,35,112,55,2,4,250,221,80,251,16,2,61,2,4,122,143,151,234,203,19,32,208,9,244,203,15,185,6,143,33,64,136,17,232,
199,76,146,183,36,16,112,95,16,232,9,115,174,199,99,8,16,232,199,112,244,22,4,16,64,224,45,1,2,221,28,32,240,156,0,129,110,34,16,88,147,0,129,190,102,46,78,133,192,39,4,186,33,64,224,25,1,2,157,64,183,
18,8,236,34,64,136,17,232,187,6,69,17,2,27,1,247,5,129,110,17,16,216,75,128,64,223,75,74,29,2,8,32,80,19,32,208,107,70,42,178,8,16,232,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,
2,157,64,175,102,196,115,4,126,36,64,136,221,30,132,237,15,170,62,123,120,120,120,52,42,8,32,240,142,128,251,226,246,36,108,191,23,249,102,123,250,198,172,32,128,192,59,2,4,186,73,64,0,1,4,142,35,64,160,
31,199,210,155,174,65,128,64,191,70,142,186,184,30,1,2,253,122,153,234,232,34,4,8,244,139,4,169,141,163,8,16,232,55,72,62,62,62,190,126,122,122,250,254,40,208,222,131,192,116,2,132,216,237,4,9,244,233,
211,237,252,71,19,112,95,220,38,74,160,31,61,109,222,55,157,0,129,62,61,65,231,71,0,129,149,8,16,232,43,165,225,44,43,16,32,208,87,72,193,25,16,248,57,1,2,221,84,32,176,40,1,2,125,209,96,28,235,44,2,4,
58,129,126,214,236,249,238,48,2,132,24,129,62,108,100,29,247,68,2,238,11,2,253,196,241,243,233,97,4,8,244,97,129,57,46,2,8,44,77,128,64,95,58,30,135,59,129,0,129,126,2,116,159,68,96,7,1,2,125,7,36,37,
8,156,65,128,64,63,131,186,111,46,76,128,64,39,208,23,30,79,71,91,137,0,33,70,160,175,52,143,206,178,54,1,247,5,129,190,246,132,58,221,74,4,8,244,149,210,112,22,4,16,152,78,128,64,159,158,160,243,31,77,
128,64,63,154,168,247,33,112,12,1,2,253,24,142,222,130,192,225,4,8,244,195,145,122,225,108,2,4,58,129,62,123,130,157,254,110,4,8,49,2,253,110,195,230,67,227,9,184,47,8,244,241,67,172,129,187,17,32,208,
239,134,218,135,16,64,32,128,0,129,30,16,178,22,91,4,8,244,22,46,197,8,220,141,0,129,126,55,212,62,132,64,143,0,129,222,227,165,250,242,4,8,116,2,253,242,67,174,193,99,8,16,98,4,250,49,147,228,45,9,4,
220,23,4,122,194,156,235,241,24,2,4,250,49,28,189,5,1,4,16,120,75,128,64,55,7,8,60,39,64,160,155,8,4,214,36,64,160,175,153,139,83,33,240,9,129,110,8,16,120,70,128,64,39,208,173,4,2,187,8,16,98,4,250,174,
65,81,132,192,70,192,125,65,160,91,4,4,246,18,32,208,247,146,82,135,0,2,8,212,4,8,244,154,145,138,44,2,4,122,86,222,186,157,67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,
241,28,129,31,9,16,98,183,7,97,251,131,170,207,30,30,30,30,141,10,2,8,188,35,224,190,184,61,9,219,239,69,190,217,158,190,49,43,8,32,240,142,0,129,110,18,16,64,0,129,227,8,16,232,199,177,244,166,107,16,
32,208,175,145,163,46,174,71,128,64,191,94,166,58,186,8,1,2,253,34,65,106,227,40,2,4,250,13,146,143,143,143,175,159,158,158,190,63,10,180,247,32,48,157,0,33,118,59,65,2,125,250,116,59,255,209,4,220,23,
183,137,18,232,71,79,155,247,77,39,64,160,79,79,208,249,17,64,96,37,2,4,250,74,105,56,203,10,4,8,244,21,82,112,6,4,126,78,128,64,55,21,8,44,74,128,64,95,52,24,199,58,139,0,129,78,160,159,53,123,190,59,
140,0,33,70,160,15,27,89,199,61,145,128,251,130,64,63,113,252,124,122,24,1,2,125,88,96,142,139,0,2,75,19,32,208,151,142,199,225,78,32,64,160,159,0,221,39,17,216,65,128,64,223,1,73,9,2,103,16,32,208,207,
160,238,155,11,19,32,208,9,244,133,199,211,209,86,34,64,136,17,232,43,205,163,179,172,77,192,125,65,160,175,61,161,78,183,18,1,2,125,165,52,156,5,1,4,166,19,32,208,167,39,232,252,71,19,32,208,143,38,234,
125,8,28,67,128,64,63,134,163,183,32,112,56,1,2,253,112,164,94,56,155,0,129,78,160,207,158,96,167,191,27,1,66,140,64,191,219,176,249,208,120,2,238,11,2,125,252,16,107,224,110,4,8,244,187,161,246,33,4,
16,8,32,64,160,7,132,172,197,22,1,2,189,133,75,49,2,119,35,64,160,223,13,181,15,33,208,35,64,160,247,120,169,190,60,1,2,157,64,191,252,144,107,240,24,2,132,24,129,126,204,36,121,75,2,1,247,5,129,158,48,
231,122,60,134,0,129,126,12,71,111,65,0,1,4,222,18,32,208,205,1,2,207,9,16,232,38,2,129,53,9,16,232,107,230,226,84,8,124,66,160,27,2,4,158,17,32,208,9,116,43,129,192,46,2,132,24,129,190,107,80,20,33,176,
17,112,95,16,232,22,1,129,189,4,8,244,189,164,212,33,128,0,2,53,1,2,189,102,164,34,139,0,129,158,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,224,71,
2,132,216,237,65,216,254,160,234,179,135,135,135,71,163,130,0,2,239,8,184,47,110,79,194,246,123,145,111,182,167,111,204,10,2,8,188,35,64,160,155,4,4,16,64,224,56,2,4,250,113,44,189,233,26,4,8,244,107,
228,168,139,235,17,32,208,175,151,169,142,46,66,128,64,191,72,144,218,56,138,0,129,126,131,228,227,227,227,235,167,167,167,239,143,2,237,61,8,76,39,64,136,221,78,144,64,159,62,221,206,127,52,1,247,197,
109,162,4,250,209,211,230,125,211,9,16,232,211,19,116,126,4,16,88,137,0,129,190,82,26,206,178,2,1,2,125,133,20,156,1,129,159,19,32,208,77,5,2,139,18,32,208,23,13,198,177,206,34,64,160,19,232,103,205,158,
239,14,35,64,136,17,232,195,70,214,113,79,36,224,190,32,208,79,28,63,159,30,70,128,64,31,22,152,227,34,128,192,210,4,8,244,165,227,113,184,19,8,16,232,39,64,247,73,4,118,16,32,208,119,64,82,130,192,25,
4,8,244,51,168,251,230,194,4,8,116,2,125,225,241,116,180,149,8,16,98,4,250,74,243,232,44,107,19,112,95,16,232,107,79,168,211,173,68,128,64,95,41,13,103,65,0,129,233,4,8,244,233,9,58,255,209,4,8,244,163,
137,122,31,2,199,16,32,208,143,225,232,45,8,28,78,128,64,63,28,169,23,206,38,64,160,19,232,179,39,216,233,239,70,128,16,35,208,239,54,108,62,52,158,128,251,130,64,31,63,196,26,184,27,1,2,253,110,168,125,
8,1,4,2,8,16,232,1,33,107,177,69,128,64,111,225,82,140,192,221,8,16,232,119,67,237,67,8,244,8,16,232,61,94,170,47,79,128,64,39,208,47,63,228,26,60,134,0,33,70,160,31,51,73,222,146,64,192,125,65,160,39,
204,185,30,143,33,64,160,31,195,209,91,16,64,0,129,183,4,8,116,115,128,192,115,2,4,186,137,64,96,77,2,4,250,154,185,56,21,2,159,16,232,134,0,129,103,4,8,116,2,221,74,32,176,139,0,33,70,160,239,26,20,69,
8,108,4,220,23,4,186,69,64,96,47,1,2,125,47,41,117,8,32,128,64,77,128,64,175,25,169,200,34,64,160,103,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,248,145,0,
33,118,123,16,182,63,168,250,236,225,225,225,209,168,32,128,192,59,2,238,139,219,147,176,253,94,228,155,237,233,27,179,130,0,2,239,8,16,232,38,1,1,4,16,56,142,0,129,126,28,75,111,186,6,1,2,253,26,57,234,
226,122,4,8,244,235,101,170,163,139,16,32,208,47,18,164,54,142,34,64,160,223,32,249,248,248,248,250,233,233,233,251,163,64,123,15,2,211,9,16,98,183,19,36,208,167,79,183,243,31,77,192,125,113,155,40,129,
126,244,180,121,223,116,2,4,250,244,4,157,31,1,4,86,34,64,160,175,148,134,179,172,64,128,64,95,33,5,103,64,224,231,4,8,116,83,129,192,162,4,8,244,69,131,113,172,179,8,16,232,4,250,89,179,231,187,195,8,
16,98,4,250,176,145,117,220,19,9,184,47,8,244,19,199,207,167,135,17,32,208,135,5,230,184,8,32,176,52,1,2,125,233,120,28,238,4,2,4,250,9,208,125,18,129,29,4,8,244,29,144,148,32,112,6,1,2,253,12,234,190,
185,48,1,2,157,64,95,120,60,29,109,37,2,132,24,129,190,210,60,58,203,218,4,220,23,4,250,218,19,234,116,43,17,32,208,87,74,195,89,16,64,96,58,1,2,125,122,130,206,127,52,1,2,253,104,162,222,135,192,49,4,
8,244,99,56,122,11,2,135,19,32,208,15,71,234,133,179,9,16,232,4,250,236,9,118,250,187,17,32,196,8,244,187,13,155,15,141,39,224,190,32,208,199,15,177,6,238,70,128,64,191,27,106,31,66,0,129,0,2,4,122,64,
200,90,108,17,32,208,91,184,20,35,112,55,2,4,250,221,80,251,16,2,61,2,4,122,143,151,234,203,19,32,208,9,244,203,15,185,6,143,33,64,136,17,232,199,76,146,183,36,16,112,95,16,232,9,115,174,199,99,8,16,232,
199,112,244,22,4,16,64,224,45,1,2,221,28,32,240,156,0,129,110,34,16,88,147,0,129,190,102,46,78,133,192,39,4,186,33,64,224,25,1,2,157,64,183,18,8,236,34,64,136,17,232,187,6,69,17,2,27,1,247,5,129,110,17,
16,216,75,128,64,223,75,74,29,2,8,32,80,19,32,208,107,70,42,178,8,16,232,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,2,157,64,175,102,196,115,4,126,36,64,136,221,30,132,237,15,170,
62,123,120,120,120,52,42,8,32,240,142,128,251,226,246,36,108,191,23,249,102,123,250,198,172,32,128,192,59,2,4,122,206,36,60,62,62,190,126,219,237,191,254,235,191,254,248,191,253,231,229,8,252,217,159,
253,217,15,159,127,254,249,15,105,52,188,153,0,0,32,0,73,68,65,84,47,247,5,111,94,149,0,129,190,106,50,206,117,22,1,2,253,44,242,190,139,192,251,9,16,232,38,4,129,69,9,16,232,139,6,227,88,103,17,32,208,
111,144,127,251,7,60,79,79,79,223,159,21,140,239,34,176,26,1,66,236,118,34,4,250,106,211,234,60,103,19,112,95,220,78,128,64,63,123,58,125,127,53,2,4,250,106,137,124,216,121,222,254,222,105,147,20,191,
216,254,11,133,191,216,254,127,192,219,255,98,225,127,121,251,191,183,183,189,149,229,255,33,204,137,243,15,195,251,177,191,234,173,72,255,143,255,249,227,150,203,255,249,233,255,254,195,191,255,251,191,
255,241,47,255,242,47,255,248,177,31,240,235,215,33,64,160,175,147,133,147,172,65,128,64,95,35,7,167,64,224,255,37,64,160,155,9,4,22,37,64,160,47,26,140,99,157,69,128,64,191,65,158,64,63,107,36,125,119,
85,2,132,216,237,100,8,244,85,167,214,185,206,34,224,190,184,77,158,64,63,107,42,125,119,85,2,4,250,170,201,188,255,92,111,127,175,180,201,215,183,130,252,151,175,94,189,250,175,219,255,254,197,246,63,
4,249,204,56,223,202,245,223,109,255,191,251,127,111,255,243,187,175,191,254,250,15,51,219,112,234,183,4,8,116,115,128,192,115,2,4,186,137,64,96,77,2,4,250,154,185,56,21,2,254,29,232,102,0,129,231,4,8,
244,27,19,65,160,91,21,4,158,19,32,196,110,79,4,129,110,91,16,112,95,236,157,1,2,125,47,41,117,41,4,8,244,57,73,255,36,205,127,77,152,207,201,236,3,79,250,195,150,241,111,183,221,252,95,95,125,245,213,
239,62,240,29,126,217,73,4,8,244,147,192,251,236,178,4,8,244,101,163,113,176,112,2,4,122,248,0,104,127,93,2,126,2,125,221,108,156,236,20,2,4,58,129,126,202,224,249,232,60,2,4,58,129,62,111,106,157,248,
44,2,238,139,219,228,9,244,179,166,210,119,87,37,64,160,175,154,204,187,115,253,199,79,154,111,66,245,55,219,255,249,139,237,127,252,148,249,218,145,29,125,186,63,110,217,255,211,191,253,219,191,253,131,
191,234,253,104,180,47,243,62,2,253,101,184,122,235,92,2,4,250,220,236,156,252,218,4,8,244,107,231,171,187,193,4,8,244,193,225,57,250,75,16,32,208,111,80,245,19,232,47,49,110,222,57,153,0,33,118,59,61,
63,129,62,121,178,157,253,37,8,184,47,110,83,37,208,95,98,226,188,115,50,1,2,125,205,244,222,254,94,104,203,230,111,183,251,252,175,73,243,53,51,58,225,84,191,219,102,226,127,110,127,197,251,111,79,248,
182,79,238,36,64,160,239,4,165,44,134,0,129,30,19,181,70,135,17,32,208,135,5,230,184,57,4,8,244,156,172,117,186,139,0,129,126,3,19,129,190,107,126,20,5,17,32,196,110,135,77,160,7,45,130,86,119,17,112,
95,220,198,68,160,239,26,33,69,65,4,8,244,181,194,254,253,239,127,255,139,63,253,211,63,253,111,196,249,90,185,44,118,154,63,108,123,251,15,68,250,98,169,252,116,28,2,125,205,92,156,234,60,2,4,250,121,
236,125,25,129,247,17,32,208,205,7,2,139,18,32,208,23,13,198,177,206,34,64,160,19,232,103,205,158,239,14,35,64,136,17,232,195,70,214,113,79,36,224,190,32,208,79,28,63,159,30,70,128,64,95,35,48,63,113,
190,70,14,195,78,65,164,47,24,24,129,190,96,40,142,116,42,1,2,253,84,252,62,142,192,77,2,4,186,225,64,96,81,2,4,250,162,193,56,214,89,4,8,116,2,253,172,217,243,221,97,4,8,49,2,125,216,200,58,238,137,4,
220,23,4,250,137,227,231,211,195,8,16,232,231,7,246,147,112,123,251,239,56,247,239,55,63,63,142,113,39,216,254,29,233,191,221,254,29,233,127,239,223,145,190,70,116,4,250,26,57,56,197,58,4,8,244,117,178,
112,18,4,254,51,1,2,221,60,32,176,40,1,2,125,209,96,28,235,44,2,4,58,129,126,214,236,249,238,48,2,132,24,129,62,108,100,29,247,68,2,238,11,2,253,196,241,243,233,97,4,8,244,243,2,251,246,219,111,127,185,
201,207,183,226,252,179,243,78,225,203,87,33,176,253,255,254,191,255,234,171,175,254,238,42,253,76,237,131,64,159,154,156,115,191,20,1,2,253,165,200,122,47,2,31,71,128,64,255,56,126,126,53,2,47,70,128,
64,127,49,180,94,60,147,0,129,126,35,55,255,14,244,153,3,237,212,47,71,128,16,187,205,214,191,3,253,229,230,206,155,103,18,112,95,220,206,205,191,3,125,230,76,59,245,203,17,32,208,95,142,237,251,222,188,
201,243,191,219,228,249,127,219,106,252,212,249,57,17,92,245,171,127,216,100,213,95,249,105,244,243,226,37,208,207,99,239,203,107,18,32,208,215,204,197,169,16,32,208,205,0,2,139,18,32,208,23,13,198,177,
206,34,64,160,19,232,103,205,158,239,14,35,64,136,17,232,195,70,214,113,79,36,224,190,32,208,79,28,63,159,30,70,128,64,191,111,96,63,253,151,132,255,113,251,234,55,247,253,178,175,37,17,216,246,250,111,
190,254,250,235,223,38,245,188,74,175,4,250,42,73,56,199,42,4,8,244,85,146,112,14,4,158,19,32,208,77,4,2,139,18,32,208,23,13,198,177,206,34,64,160,223,32,239,39,208,207,26,73,223,93,149,0,33,118,59,25,
63,129,190,234,212,58,215,89,4,220,23,183,201,251,9,244,179,166,210,119,87,37,64,160,223,47,153,159,254,202,246,183,242,252,23,247,251,170,47,165,18,216,254,134,131,255,241,197,23,95,252,247,212,254,207,
234,155,64,63,139,188,239,174,74,128,64,95,53,25,231,74,39,64,160,167,79,128,254,151,37,64,160,47,27,141,131,157,67,128,64,39,208,207,153,60,95,29,71,128,16,35,208,199,13,173,3,159,70,192,125,65,160,159,
54,124,62,60,142,0,129,126,159,200,54,121,254,235,77,104,254,237,246,53,127,101,251,125,144,251,202,59,2,127,248,244,211,79,127,245,249,231,159,255,0,200,125,8,16,232,247,225,236,43,115,8,16,232,115,178,
114,210,44,2,4,122,86,222,186,29,68,128,64,31,20,150,163,222,131,0,129,126,131,178,159,64,191,199,248,249,198,36,2,132,216,237,180,252,4,250,164,73,118,214,123,16,112,95,220,166,236,39,208,239,49,129,
190,49,137,0,129,254,242,105,253,244,239,59,127,43,207,253,7,129,51,8,252,113,219,243,191,218,254,74,247,63,156,241,241,180,111,18,232,105,137,235,183,34,64,160,87,132,60,71,224,28,2,4,250,57,220,125,
21,129,146,0,129,94,34,82,144,69,128,64,191,145,55,129,158,181,8,186,173,9,16,98,183,25,17,232,245,252,168,200,34,224,190,184,157,55,129,158,181,11,186,173,9,16,232,53,163,15,173,120,251,251,153,141,239,
111,182,59,249,175,63,244,29,126,29,2,7,17,248,97,155,197,95,145,232,7,209,124,207,107,8,244,151,103,236,11,179,8,16,232,179,242,114,218,28,2,4,122,78,214,58,29,70,128,64,31,22,152,227,190,52,1,2,253,
6,97,2,253,165,71,207,251,167,17,32,196,110,39,70,160,79,155,102,231,125,105,2,238,139,219,132,9,244,151,158,62,239,159,70,128,64,127,153,196,200,243,151,225,234,173,31,71,96,251,231,131,95,125,245,213,
87,191,251,184,183,248,213,239,35,64,160,155,15,4,158,19,32,208,77,4,2,107,18,32,208,215,204,197,169,16,248,132,64,55,4,8,60,35,64,160,19,232,86,2,129,93,4,8,49,2,125,215,160,40,66,96,35,224,190,184,61,
6,4,186,21,65,224,57,1,2,253,101,38,226,187,239,190,251,71,63,121,254,50,108,189,245,227,8,216,249,143,227,87,253,106,2,189,34,228,121,26,1,2,61,45,113,253,78,33,64,160,79,73,202,57,227,8,16,232,113,145,
107,248,253,4,8,116,2,221,142,32,176,139,0,33,70,160,239,26,20,69,8,16,232,239,157,1,2,221,138,32,64,160,191,244,12,248,119,158,191,52,97,239,255,72,2,254,58,247,143,4,248,190,95,78,160,191,32,92,175,
30,73,128,64,31,25,155,67,7,16,32,208,3,66,214,226,76,2,4,250,204,220,156,250,197,8,16,232,4,250,139,13,151,23,95,139,0,129,78,160,95,107,162,117,243,146,4,220,23,183,233,18,232,47,57,121,222,61,145,128,
159,70,61,54,181,77,158,255,250,213,171,87,191,57,246,173,222,134,192,225,4,126,248,244,211,79,255,226,243,207,63,255,225,240,55,135,191,144,64,15,31,0,237,255,140,0,129,110,40,16,88,147,0,129,190,102,
46,78,133,128,191,194,221,12,32,240,156,0,129,78,160,219,9,4,118,17,32,196,8,244,93,131,162,8,129,141,128,251,130,64,183,8,8,236,37,64,160,239,37,85,215,145,231,53,35,21,75,17,248,195,151,95,126,249,249,
82,39,186,192,97,8,244,11,132,168,133,67,9,16,232,135,226,244,50,4,14,35,64,160,31,134,210,139,16,56,150,128,159,64,63,150,167,183,141,39,64,160,223,136,240,241,241,241,245,211,211,211,247,227,19,214,
0,2,7,17,32,196,110,131,220,254,160,234,179,135,135,135,199,131,80,123,13,2,227,9,184,47,110,71,232,39,208,199,143,183,6,14,38,64,160,31,3,244,167,127,22,249,231,237,109,175,143,121,163,183,32,112,23,
2,254,60,226,96,204,4,250,193,64,189,110,60,1,2,125,124,132,26,184,40,1,2,253,162,193,106,107,62,1,2,125,126,134,58,56,148,128,223,176,222,192,73,160,31,58,103,94,118,1,2,132,24,129,126,129,49,214,194,
157,8,184,47,8,244,59,141,154,207,92,128,0,129,254,241,33,254,244,251,150,55,219,155,126,249,241,111,243,6,4,238,78,224,175,182,159,68,255,167,187,127,245,162,31,36,208,47,26,172,182,62,152,0,129,254,
193,232,252,66,4,94,148,0,129,254,162,120,189,28,129,15,39,64,160,127,56,59,191,242,146,4,8,244,27,177,18,232,151,156,119,77,125,4,1,66,236,54,60,63,129,254,17,131,229,151,94,146,128,251,226,118,172,126,
2,253,146,35,175,169,143,32,64,160,127,4,188,159,126,233,119,223,125,247,155,237,222,253,245,199,191,201,27,16,56,135,128,123,224,56,238,4,250,113,44,189,233,26,4,8,244,107,228,168,139,235,17,32,208,175,
151,169,142,46,66,128,64,191,72,144,218,56,138,0,129,78,160,31,53,75,222,115,113,2,132,24,129,126,241,17,215,222,129,4,220,23,4,250,129,227,228,85,23,39,64,156,125,92,192,254,75,57,31,199,207,175,94,134,
192,31,183,159,66,255,139,101,78,51,248,32,4,250,224,240,28,253,69,8,16,232,47,130,213,75,17,248,104,2,4,250,71,35,244,2,4,94,134,0,129,254,50,92,189,117,44,1,2,157,64,31,59,188,14,126,95,2,132,24,129,
126,223,137,243,181,201,4,220,23,4,250,228,249,117,246,251,18,32,208,63,156,247,79,127,99,214,191,108,111,240,239,61,255,112,140,126,229,34,4,182,127,118,248,251,175,190,250,234,239,22,57,206,216,99,16,
232,99,163,115,240,23,34,64,160,191,16,88,175,69,224,35,9,16,232,31,9,208,47,71,224,165,8,16,232,47,69,214,123,135,18,32,208,111,4,231,175,112,31,58,209,142,253,98,4,8,177,219,104,253,21,238,47,54,118,
94,60,148,128,251,226,118,112,126,90,116,232,80,59,246,139,17,32,208,63,28,173,191,186,253,195,217,249,149,107,18,32,186,62,62,23,2,253,227,25,122,195,181,8,184,87,174,149,167,110,174,67,128,64,191,78,
150,58,185,24,1,2,253,98,129,106,231,99,9,16,232,4,250,199,206,144,95,31,66,128,16,35,208,67,70,93,155,7,16,112,95,16,232,7,140,145,87,132,16,32,208,63,44,232,111,191,253,246,151,175,94,189,122,179,253,
106,63,125,254,97,8,253,170,53,9,252,110,251,171,220,127,181,230,209,102,156,138,64,159,145,147,83,222,143,0,129,126,63,214,190,132,64,135,0,129,222,161,165,22,129,59,18,32,208,239,8,219,167,38,16,32,
208,111,164,228,39,208,39,140,175,51,222,147,0,33,118,155,182,159,64,191,231,36,250,214,4,2,238,139,219,41,249,9,244,9,19,236,140,247,36,64,160,127,24,237,237,46,249,231,237,87,254,242,195,126,181,95,
133,192,210,4,254,106,147,232,255,180,244,9,23,62,28,129,190,112,56,142,118,10,1,2,253,20,236,62,138,64,73,128,64,47,17,41,64,224,28,2,4,250,57,220,125,117,89,2,4,250,141,104,8,244,101,103,214,193,78,
34,64,136,221,6,79,160,159,52,148,62,187,44,1,247,197,237,104,8,244,101,199,214,193,78,34,64,160,247,193,187,71,250,204,252,138,81,4,126,216,4,250,159,143,58,241,66,135,37,208,23,10,195,81,150,32,64,160,
47,17,131,67,32,240,51,2,4,186,161,64,96,81,2,4,250,162,193,56,214,89,4,8,116,2,253,172,217,243,221,97,4,8,49,2,125,216,200,58,238,137,4,220,23,4,250,137,227,231,211,195,8,16,232,253,192,252,244,121,159,
153,95,49,139,192,118,47,252,205,215,95,127,253,219,89,167,94,227,180,4,250,26,57,56,197,58,4,8,244,117,178,112,18,4,254,51,1,2,221,60,32,176,40,1,2,125,209,96,28,235,44,2,4,58,129,126,214,236,249,238,
48,2,132,24,129,62,108,100,29,247,68,2,238,11,2,253,196,241,243,233,97,4,8,244,94,96,126,250,188,199,75,245,88,2,127,220,126,10,253,47,198,158,254,196,131,19,232,39,194,247,233,37,9,16,232,75,198,226,
80,8,124,66,160,27,2,4,22,37,64,160,47,26,140,99,157,69,128,64,39,208,207,154,61,223,29,70,128,16,35,208,135,141,172,227,158,72,192,125,65,160,159,56,126,62,61,140,0,129,222,11,204,79,159,247,120,169,
158,75,192,79,161,127,88,118,4,250,135,113,243,171,174,75,128,64,191,110,182,58,155,77,128,64,159,157,159,211,95,152,0,129,126,225,112,181,246,33,4,8,116,2,253,67,230,198,175,9,36,64,136,17,232,129,99,
175,229,15,36,224,190,32,208,63,112,116,252,178,64,2,4,250,254,208,253,244,249,126,86,42,47,65,192,79,161,127,64,140,4,250,7,64,243,75,46,77,128,64,191,116,188,154,27,76,128,64,31,28,158,163,95,155,0,
129,126,237,124,117,215,38,64,160,19,232,237,161,241,11,50,9,16,98,4,122,230,228,235,250,67,8,184,47,8,244,15,153,27,191,38,147,0,129,190,63,247,237,207,50,222,108,213,223,236,255,21,42,17,152,77,128,
248,234,231,71,160,247,153,249,21,215,38,224,30,185,118,190,186,155,75,128,64,159,155,157,147,95,156,0,129,126,241,128,181,215,37,64,160,19,232,221,153,81,31,74,128,16,35,208,67,71,95,219,31,64,192,125,
65,160,127,192,216,248,37,161,4,8,244,125,193,63,62,62,190,126,122,122,250,151,173,250,245,190,95,161,10,129,249,4,94,189,122,245,219,47,190,248,226,111,230,119,114,191,14,8,244,251,177,246,165,25,4,8,
244,25,57,57,101,30,1,2,61,47,115,29,15,33,64,160,15,9,202,49,239,69,128,64,39,208,239,53,107,190,51,156,0,33,70,160,15,31,97,199,191,35,1,247,5,129,126,199,113,243,169,225,4,8,244,125,1,250,235,219,247,
113,82,117,57,2,63,124,249,229,151,127,126,185,174,94,176,33,2,253,5,225,122,245,72,2,4,250,200,216,28,58,128,0,129,30,16,178,22,103,18,32,208,103,230,230,212,47,70,128,64,39,208,95,108,184,188,248,90,
4,8,49,2,253,90,19,173,155,151,36,224,190,32,208,95,114,190,188,251,90,4,8,244,125,121,250,235,219,247,113,82,117,61,2,219,29,241,55,95,127,253,245,111,175,215,217,203,116,68,160,191,12,87,111,157,75,
128,64,159,155,157,147,95,155,0,129,126,237,124,117,55,152,0,129,62,56,60,71,127,9,2,4,58,129,254,18,115,229,157,23,36,64,136,17,232,23,28,107,45,189,16,1,247,5,129,254,66,163,229,181,23,36,64,160,215,
161,254,254,247,191,255,197,159,252,201,159,188,253,235,219,253,7,129,56,2,254,26,247,94,228,4,122,143,151,234,235,19,32,208,175,159,177,14,103,18,32,208,103,230,230,212,1,4,8,244,128,144,181,216,33,64,
160,19,232,157,121,81,27,76,128,16,35,208,131,199,95,235,77,2,238,11,2,189,57,50,202,131,9,16,232,117,248,132,88,205,72,197,165,9,248,107,220,27,241,186,47,26,176,148,70,16,32,208,35,98,214,228,64,2,4,
250,192,208,28,57,131,0,129,158,145,179,46,119,19,32,208,9,244,221,195,162,48,155,0,33,70,160,103,111,128,238,59,4,220,23,4,122,103,94,212,102,19,32,208,235,252,253,245,237,53,35,21,215,38,64,128,237,
207,151,64,223,207,74,101,6,1,247,71,70,206,186,156,71,128,64,159,151,153,19,135,16,32,208,67,130,214,230,94,2,4,58,129,190,119,86,212,133,19,32,196,8,244,240,21,208,126,131,128,251,130,64,111,140,139,
210,112,2,4,122,61,0,254,12,163,102,164,226,218,4,252,115,197,254,124,9,244,253,172,84,102,16,32,208,51,114,214,229,60,2,4,250,188,204,156,56,132,128,223,124,134,4,173,205,189,4,8,116,2,125,239,172,168,
11,39,224,15,174,8,244,240,21,208,126,131,128,251,130,64,111,140,139,210,112,2,4,250,251,7,96,147,97,159,61,60,60,60,134,143,137,246,17,240,231,22,59,103,128,64,223,9,74,89,12,1,2,61,38,106,141,14,35,
64,160,15,11,204,113,115,8,16,232,57,89,235,116,23,1,191,17,37,208,119,13,138,34,4,8,49,2,221,22,32,176,151,128,251,130,64,223,59,43,234,16,32,208,223,63,3,223,126,251,237,175,95,189,122,245,27,147,130,
64,56,1,255,30,244,157,3,64,160,239,4,165,44,134,0,129,30,19,181,70,135,17,32,208,135,5,230,184,57,4,8,244,156,172,117,186,139,0,129,78,160,239,26,20,69,8,16,98,4,186,45,64,96,47,1,247,5,129,190,119,86,
212,33,64,160,191,127,6,190,251,238,187,127,220,238,212,191,54,41,8,164,19,32,193,246,77,0,129,190,143,147,170,28,2,238,142,156,172,117,58,139,0,129,62,43,47,167,13,34,64,160,7,133,173,213,61,4,8,116,
2,125,207,156,168,65,224,19,66,140,64,183,6,8,236,37,224,190,32,208,247,206,138,58,4,8,244,247,207,192,246,231,23,111,182,138,111,76,10,2,233,4,182,127,182,248,213,87,95,125,245,187,116,14,85,255,4,122,
69,200,243,52,2,4,122,90,226,250,157,66,128,64,159,146,148,115,198,17,32,208,227,34,215,240,251,9,16,232,4,186,29,65,96,23,1,66,140,64,223,53,40,138,16,216,8,184,47,110,143,193,246,123,145,183,34,236,
173,16,243,31,4,16,216,8,16,232,239,31,3,127,126,97,77,16,120,71,192,63,91,236,155,4,2,125,31,39,85,57,4,8,244,156,172,117,58,139,0,129,62,43,47,167,13,34,224,55,160,65,97,107,117,15,1,2,253,6,165,199,
199,199,215,79,79,79,223,239,129,168,6,129,4,2,254,208,234,118,202,219,31,84,125,246,240,240,240,152,48,7,122,68,96,15,1,247,197,109,74,4,250,158,9,82,147,68,128,64,191,157,182,223,143,36,109,130,94,43,
2,175,94,189,250,31,95,124,241,197,127,175,234,210,159,19,232,233,19,160,255,255,151,0,129,110,38,16,88,147,0,129,190,102,46,78,133,192,39,4,186,33,64,224,25,1,2,157,64,183,18,8,236,34,64,136,17,232,187,
6,69,17,2,27,1,247,5,129,110,17,16,216,75,128,64,247,207,23,123,103,69,93,60,1,127,118,177,99,4,8,244,29,144,148,68,17,32,208,163,226,214,236,32,2,4,250,160,176,28,53,139,0,129,158,149,183,110,75,2,126,
19,74,160,151,67,162,0,129,183,4,8,49,127,192,109,19,16,216,75,192,125,65,160,239,157,21,117,8,16,232,183,103,224,219,111,191,253,229,246,83,183,255,108,74,16,64,224,71,2,127,252,242,203,47,255,2,139,
247,19,32,208,77,8,2,207,9,16,232,38,2,129,53,9,16,232,107,230,226,84,8,248,9,116,51,128,192,115,2,4,250,141,137,240,87,38,90,21,4,158,19,32,196,110,79,132,191,194,221,182,32,224,190,216,59,3,254,10,247,
189,164,212,165,16,32,208,223,251,207,23,127,189,253,43,98,254,49,101,22,244,137,64,65,224,135,77,160,255,57,74,4,186,25,64,160,67,128,64,239,208,82,139,192,253,8,16,232,247,99,237,75,8,180,8,248,9,244,
22,46,197,215,39,64,160,223,200,152,64,191,254,240,235,176,71,128,64,127,239,31,112,251,119,160,247,198,73,245,197,9,184,47,110,7,76,160,95,124,248,181,215,38,64,160,191,247,159,47,8,244,246,68,249,5,
23,38,64,160,239,8,215,79,160,239,128,164,36,138,0,129,30,21,183,102,7,17,32,208,7,133,229,168,89,4,8,244,172,188,117,91,18,32,208,9,244,114,72,20,32,240,150,0,33,70,160,219,4,4,246,18,112,95,16,232,123,
103,69,29,2,4,250,237,25,216,254,10,247,95,111,127,133,251,111,76,9,2,8,188,35,176,253,4,186,63,111,47,134,129,64,183,45,8,60,39,64,160,155,8,4,214,36,224,255,161,175,153,139,83,33,224,175,112,55,3,8,
60,39,64,160,223,152,8,63,129,110,85,16,120,78,128,16,187,61,17,254,10,119,219,130,128,251,98,239,12,248,9,244,189,164,212,165,16,32,208,111,39,189,9,244,191,219,4,250,223,166,204,130,62,17,168,8,124,
250,233,167,127,254,249,231,159,255,80,213,37,63,39,208,147,211,215,251,255,143,0,129,110,46,16,88,147,0,129,190,102,46,78,133,0,129,110,6,16,32,208,119,205,0,129,190,11,147,162,32,2,4,58,129,30,52,238,
90,253,72,2,238,139,219,0,9,244,143,28,46,191,252,114,4,8,244,219,145,126,247,221,119,191,217,238,211,95,95,46,116,13,33,240,129,4,8,244,26,28,129,94,51,82,145,69,128,64,207,202,91,183,115,8,16,232,115,
178,114,210,48,2,254,10,247,176,192,181,91,17,240,19,232,55,8,17,232,213,232,120,158,70,128,16,35,208,211,102,94,191,31,78,192,125,65,160,127,248,244,248,149,105,4,8,116,2,61,109,230,245,251,225,4,136,
176,154,29,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,224,71,2,132,24,129,110,21,16,216,75,192,125,65,160,239,157,
21,117,8,16,232,4,186,45,64,96,47,1,34,172,38,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,139,25,240,239,64,183,
36,8,60,39,64,160,19,232,118,2,129,189,4,8,116,2,125,239,172,168,67,128,8,171,103,128,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,210,48,2,4,122,88,224,218,173,8,16,232,4,122,
53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,67,128,64,159,147,149,147,134,17,32,208,195,
2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,8,184,55,178,242,214,237,28,2,4,250,156,172,
156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,26,23,129,94,51,82,145,69,192,189,145,149,
183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,122,1,52,223,34,64,132,213,184,8,244,154,
145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,192,40,142,38,64,160,19,232,209,11,160,249,
22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,128,64,139,0,129,78,160,183,6,70,113,52,1,2,
157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,140,120,142,0,129,78,160,219,2,4,90,4,8,116,
2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,2,157,64,175,102,196,115,4,8,116,2,221,22,
32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,210,48,2,4,122,88,224,218,173,8,16,232,4,122,
53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,67,128,64,159,147,149,147,134,17,32,208,195,
2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,8,184,55,178,242,214,237,28,2,4,250,156,172,
156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,26,23,129,94,51,82,145,69,192,189,145,149,
183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,122,1,52,223,34,64,132,213,184,8,244,154,
145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,192,40,142,38,64,160,19,232,209,11,160,249,
22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,128,64,139,0,129,78,160,183,6,70,113,52,1,2,
157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,140,120,142,0,129,78,160,219,2,4,90,4,8,116,
2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,2,157,64,175,102,196,115,4,8,116,2,221,22,
32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,210,48,2,4,122,88,224,218,173,8,16,232,4,122,
53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,67,128,64,159,147,149,147,134,17,32,208,195,
2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,8,184,55,178,242,214,237,28,2,4,250,156,172,
156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,26,23,129,94,51,82,145,69,192,189,145,149,
183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,122,1,52,223,34,64,132,213,184,8,244,154,
145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,192,40,142,38,64,160,19,232,209,11,160,249,
22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,128,64,139,0,129,78,160,183,6,70,113,52,1,2,
157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,140,120,142,0,129,78,160,219,2,4,90,4,8,116,
2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,2,157,64,175,102,196,115,4,8,116,2,221,22,
32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,210,48,2,4,122,88,224,218,173,8,16,232,4,122,
53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,67,128,64,159,147,149,147,134,17,32,208,195,
2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,8,184,55,178,242,214,237,28,2,4,250,156,172,
156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,26,23,129,94,51,82,145,69,192,189,145,149,
183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,122,1,52,223,34,64,132,213,184,8,244,154,
145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,192,40,142,38,64,160,19,232,209,11,160,249,
22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,128,64,139,0,129,78,160,183,6,70,113,52,1,2,
157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,140,120,142,0,129,78,160,219,2,4,90,4,8,116,
2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,2,157,64,175,102,196,115,4,8,116,2,221,22,
32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,210,48,2,4,122,88,224,218,173,8,16,232,4,122,
53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,67,128,64,159,147,149,147,134,17,32,208,195,
2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,8,184,55,178,242,214,237,28,2,4,250,156,172,
156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,26,23,129,94,51,82,145,69,192,189,145,149,
183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,122,1,52,223,34,64,132,213,184,8,244,154,
145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,192,40,142,38,64,160,19,232,209,11,160,249,
22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,128,64,139,0,129,78,160,183,6,70,113,52,1,2,
157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,140,120,142,0,129,78,160,219,2,4,90,4,8,116,
2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,2,157,64,175,102,196,115,4,8,116,2,221,22,
32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,210,48,2,4,122,88,224,218,173,8,16,232,4,122,
53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,67,128,64,159,147,149,147,134,17,32,208,195,
2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,203,241,82,100,0,0,32,0,73,68,65,84,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,8,184,
55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,26,23,
129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,122,
1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,192,
40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,128,
64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,140,
120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,
2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,210,
48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,67,
128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,
8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,
26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,
122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,
192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,
128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,
140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,
1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,
210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,
67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,
8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,
26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,
122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,
192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,
128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,
140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,
1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,
210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,
67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,
8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,
26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,
122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,
192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,
128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,
140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,
1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,
210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,
67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,
8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,
26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,
122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,
192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,
128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,
140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,
1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,
210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,
67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,
8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,
26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,
122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,
192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,
128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,
140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,
1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,
210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,
67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,
8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,
26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,
122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,
192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,
128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,
140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,
1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,
210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,
67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,
8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,
26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,
122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,
192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,
128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,
140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,
1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,
210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,
67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,
8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,
26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,
122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,
192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,
128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,
140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,
1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,
210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,
67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,
8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,
26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,
122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,
192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,
128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,
140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,
1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,
210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,
67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,
8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,
26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,
122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,
192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,
128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,
140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,
1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,
210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,
67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,
8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,
26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,
122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,
192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,
128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,
140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,
1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,
210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,
67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,
8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,
26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,
122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,
192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,
128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,
140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,
1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,
210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,
67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,
8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,
26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,
122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,
192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,
128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,
140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,
1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,
210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,
67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,
8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,
26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,
122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,
192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,
128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,
140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,
1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,
210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,
67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,14,97,64,190,0,0,32,0,73,68,65,84,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,
139,0,17,86,227,34,208,107,70,42,178,8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,
129,78,160,71,47,128,230,91,4,136,176,26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,
4,58,129,222,26,24,197,209,4,8,116,2,61,122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,
58,129,110,11,16,104,17,32,208,9,244,214,192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,
116,2,189,154,17,207,17,32,208,9,116,91,128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,
16,232,97,129,107,183,34,64,160,19,232,213,140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,
2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,
222,200,202,91,183,115,8,16,232,115,178,114,210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,
92,4,122,205,72,69,22,1,247,70,86,222,186,157,67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,
5,208,124,139,0,17,86,227,34,208,107,70,42,178,8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,
56,154,0,129,78,160,71,47,128,230,91,4,136,176,26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,
1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,
57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,
86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,73,
195,8,16,232,97,129,107,183,34,64,160,19,232,213,140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,118,
14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,34,
224,222,200,202,91,183,115,8,16,232,115,178,114,210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,194,
106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,
232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,91,
3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,208,
109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,87,51,
226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,
237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,201,202,
73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,121,235,
118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,25,169,200,
34,224,222,200,202,91,183,115,8,16,232,115,178,114,210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,111,17,32,
194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,19,32,208,
9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,64,39,208,
91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,128,64,39,
208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,78,160,
87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,1,2,61,
44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,160,207,
201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,27,89,
121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,175,
25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,154,
111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,71,
19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,128,
64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,71,
128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,0,129,
78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,24,
1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,64,
160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,4,220,
27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,139,64,
175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,189,0,
154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,96,20,
71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,160,69,
128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,70,60,
71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,138,
0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,57,105,
24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,206,33,
64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,21,89,
4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,88,141,
139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,129,30,
189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,122,107,
96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,45,64,
160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,244,106,
70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,5,174,221,
138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,244,57,89,
57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,111,221,
206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,53,35,
21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,2,68,
88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,2,4,58,
129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,232,4,
122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,4,186,
45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,208,9,
244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,135,
5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,4,8,
244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,35,43,
111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,17,232,
53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,243,45,
2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,104,
2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,8,16,
232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,16,232,
4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,17,32,
208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,64,160,
135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,219,57,
4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,123,
35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,113,
17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,64,
243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,226,
104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,180,
8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,8,
16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,91,
17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,35,
64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,
219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,
123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,
113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,
64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,
226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,
180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,
8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,
91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,
35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,
219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,
123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,
113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,
64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,
226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,
180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,
8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,
91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,
35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,
219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,
123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,
113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,163,23,
64,243,45,2,68,88,141,139,64,175,25,169,200,34,224,222,200,202,91,183,115,8,16,232,115,178,114,210,48,2,4,122,88,224,218,173,8,16,232,4,122,53,35,158,35,64,160,19,232,182,0,129,22,1,2,157,64,111,13,140,
226,104,2,4,58,129,30,189,0,154,111,17,32,194,106,92,4,122,205,72,69,22,1,247,70,86,222,186,157,67,128,64,159,147,149,147,134,17,32,208,195,2,215,110,69,128,64,39,208,171,25,241,28,1,2,157,64,183,5,8,
180,8,16,232,4,122,107,96,20,71,19,32,208,9,244,232,5,208,124,139,0,17,86,227,34,208,107,70,42,178,8,184,55,178,242,214,237,28,2,4,250,156,172,156,52,140,0,129,30,22,184,118,43,2,4,58,129,94,205,136,231,
8,16,232,4,186,45,64,160,69,128,64,39,208,91,3,163,56,154,0,129,78,160,71,47,128,230,91,4,136,176,26,23,129,94,51,82,145,69,192,189,145,149,183,110,231,16,32,208,231,100,229,164,97,4,8,244,176,192,181,
91,17,32,208,9,244,106,70,60,71,128,64,39,208,109,1,2,45,2,4,58,129,222,26,24,197,209,4,8,116,2,61,122,1,52,223,34,64,132,213,184,8,244,154,145,138,44,2,238,141,172,188,117,59,135,0,129,62,39,43,39,13,
35,64,160,135,5,174,221,138,0,129,78,160,87,51,226,57,2,4,58,129,110,11,16,104,17,32,208,9,244,214,192,40,142,38,64,160,19,232,209,11,160,249,22,1,34,172,198,69,160,215,140,84,100,17,112,111,100,229,173,
219,57,4,8,244,57,89,57,105,24,1,2,61,44,112,237,86,4,8,116,2,189,154,17,207,17,32,208,9,116,91,128,64,139,0,129,78,160,183,6,70,113,52,1,2,157,64,143,94,0,205,183,8,16,97,53,46,2,189,102,164,34,139,128,
123,35,43,111,221,206,33,64,160,207,201,202,73,195,8,16,232,97,129,107,183,34,64,160,19,232,213,140,120,142,0,129,78,160,219,2,4,90,4,8,116,2,189,53,48,138,163,9,16,232,4,122,244,2,104,190,69,128,8,171,
113,17,232,53,35,21,89,4,220,27,89,121,235,118,14,1,2,125,78,86,78,26,70,128,64,15,11,92,187,21,1,2,157,64,175,102,196,115,4,8,116,2,221,22,32,208,34,64,160,19,232,173,129,81,28,77,128,64,39,208,255,47,
123,119,151,28,199,113,166,11,88,2,77,199,220,29,122,5,7,90,193,16,65,128,17,188,50,181,2,139,43,176,184,2,139,43,144,180,2,210,43,16,189,2,209,43,16,124,197,8,201,14,210,43,16,103,5,198,185,155,48,37,
234,100,17,77,153,144,0,100,103,119,86,85,102,126,15,34,20,242,76,215,79,230,243,101,149,186,235,205,170,10,125,0,232,124,145,128,32,44,207,37,64,207,27,89,34,150,128,243,70,172,122,235,109,63,2,2,244,
126,106,165,165,193,4,4,232,193,10,174,187,57,1,1,186,0,61,55,70,124,78,64,128,46,64,119,20,16,40,18,16,160,11,208,139,6,140,133,67,11,8,208,5,232,161,15,0,157,47,18,16,132,229,185,4,232,121,35,75,196,
18,112,222,136,85,111,189,237,71,64,128,222,79,173,180,52,152,128,0,61,88,193,117,55,39,32,64,23,160,231,198,136,207,9,8,208,5,232,142,2,2,69,2,2,116,1,122,209,128,177,112,104,1,1,186,0,61,244,1,160,243,
69,2,130,176,60,151,0,61,111,100,137,88,2,206,27,177,234,173,183,253,8,8,208,251,169,149,150,6,19,16,160,7,43,184,238,230,4,4,232,2,244,220,24,241,57,1,1,186,0,221,81,64,160,72,64,128,46,64,47,26,48,22,
14,45,32,64,23,160,135,62,0,116,190,72,64,16,150,231,18,160,231,141,44,17,75,192,121,35,86,189,245,182,31,1,1,122,63,181,210,210,96,2,2,244,96,5,215,221,156,128,0,93,128,158,27,35,62,39,32,64,23,160,59,
10,8,20,9,8,208,5,232,69,3,198,194,161,5,4,232,2,244,208,7,128,206,23,9,8,194,242,92,2,244,188,145,37,98,9,56,111,196,170,183,222,246,35,32,64,239,167,86,90,26,76,64,128,30,172,224,186,155,19,16,160,11,
208,115,99,196,231,4,4,232,2,116,71,1,129,34,1,1,186,0,189,104,192,88,56,180,128,0,93,128,30,250,0,208,249,34,1,65,88,158,75,128,158,55,178,68,44,1,231,141,88,245,214,219,126,4,4,232,253,212,74,75,131,
9,8,208,131,21,92,119,115,2,2,116,1,122,110,140,248,156,128,0,93,128,238,40,32,80,36,32,64,23,160,23,13,24,11,135,22,16,160,11,208,67,31,0,58,95,36,32,8,203,115,9,208,243,70,150,136,37,224,188,17,171,
222,122,219,143,128,0,189,159,90,105,105,48,1,1,122,176,130,235,110,78,64,128,46,64,207,141,17,159,19,16,160,11,208,29,5,4,138,4,4,232,2,244,162,1,99,225,208,2,2,116,1,122,232,3,64,231,139,4,4,97,121,
46,1,122,222,200,18,177,4,156,55,98,213,91,111,251,17,16,160,247,83,43,45,13,38,32,64,15,86,112,221,205,9,8,208,5,232,185,49,226,115,2,2,116,1,186,163,128,64,145,128,0,93,128,94,52,96,44,28,90,64,128,
46,64,15,125,0,232,124,145,128,32,44,207,37,64,207,27,89,34,150,128,243,70,172,122,235,109,63,2,2,244,126,106,165,165,193,4,4,232,193,10,174,187,57,1,1,186,0,61,55,70,124,78,64,128,46,64,119,20,16,40,
18,16,160,11,208,139,6,140,133,67,11,8,208,5,232,161,15,0,157,47,18,16,132,229,185,4,232,121,35,75,196,18,112,222,136,85,111,189,237,71,64,128,222,79,173,180,52,152,128,0,61,88,193,117,55,39,32,64,23,
160,231,198,136,207,9,8,208,5,232,142,2,2,69,2,2,116,1,122,209,128,177,112,104,1,1,186,0,61,244,1,160,243,69,2,130,176,60,151,0,61,111,100,137,88,2,206,27,177,234,173,183,253,8,8,208,251,169,149,150,6,
19,16,160,7,43,184,238,230,4,4,232,2,244,220,24,241,57,1,1,186,0,221,81,64,160,72,64,128,46,64,47,26,48,22,14,45,32,64,23,160,135,62,0,116,190,72,64,16,150,231,18,160,231,141,44,17,75,192,121,35,86,189,
245,182,31,1,1,122,63,181,210,210,96,2,2,244,96,5,215,221,156,128,0,93,128,158,27,35,62,39,32,64,23,160,59,10,8,20,9,8,208,5,232,69,3,198,194,161,5,4,232,2,244,208,7,128,206,23,9,8,194,242,92,2,244,188,
145,37,98,9,56,111,196,170,183,222,246,35,32,64,239,167,86,90,26,76,64,128,30,172,224,186,155,19,16,160,11,208,115,99,196,231,4,4,232,2,116,71,1,129,34,1,1,186,0,189,104,192,88,56,180,128,0,93,128,30,
250,0,208,249,34,1,65,88,158,75,128,158,55,178,68,44,1,231,141,88,245,214,219,126,4,4,232,253,212,74,75,131,9,8,208,131,21,92,119,115,2,2,116,1,122,110,140,248,156,128,0,93,128,238,40,32,80,36,32,64,23,
160,23,13,24,11,135,22,16,160,11,208,67,31,0,58,95,36,32,8,203,115,9,208,243,70,150,136,37,224,188,17,171,222,122,219,143,128,0,189,159,90,105,105,48,1,1,122,176,130,235,110,78,64,128,46,64,207,141,17,
159,19,16,160,11,208,29,5,4,138,4,4,232,2,244,162,1,99,225,208,2,2,116,1,122,232,3,64,231,139,4,4,97,121,46,1,122,222,200,18,177,4,240,159,226,41,0,0,32,0,73,68,65,84,156,55,98,213,91,111,251,17,16,160,
247,83,43,45,13,38,32,64,15,86,112,221,205,9,8,208,5,232,185,49,226,115,2,2,116,1,186,163,128,64,145,128,0,93,128,94,52,96,44,28,90,64,128,46,64,15,125,0,232,124,145,128,32,44,207,37,64,207,27,89,34,150,
128,243,70,172,122,235,109,63,2,2,244,126,106,165,165,193,4,4,232,193,10,174,187,57,1,1,186,0,61,55,70,124,78,64,128,46,64,119,20,16,40,18,16,160,11,208,139,6,140,133,67,11,8,208,5,232,161,15,0,157,47,
18,16,132,229,185,4,232,121,35,75,196,18,112,222,136,85,111,189,237,71,64,128,222,79,173,180,52,152,128,0,61,88,193,117,55,39,32,64,23,160,231,198,136,207,9,8,208,5,232,142,2,2,69,2,2,116,1,122,209,128,
177,112,104,1,1,186,0,61,244,1,160,243,69,2,130,176,60,151,0,61,111,100,137,88,2,206,27,177,234,173,183,253,8,8,208,251,169,149,150,6,19,16,160,7,43,184,238,230,4,4,232,2,244,220,24,241,57,1,1,186,0,221,
81,64,160,72,64,128,46,64,47,26,48,22,14,45,32,64,23,160,135,62,0,116,190,72,64,16,150,231,18,160,231,141,44,17,75,192,121,35,86,189,245,182,31,1,1,122,63,181,210,210,96,2,2,244,96,5,215,221,156,128,0,
93,128,158,27,35,62,39,32,64,23,160,59,10,8,20,9,8,208,5,232,69,3,198,194,161,5,4,232,2,244,208,7,128,206,23,9,8,194,242,92,2,244,188,145,37,98,9,56,111,196,170,183,222,246,35,32,64,239,167,86,90,26,76,
64,128,30,172,224,186,155,19,16,160,11,208,115,99,196,231,4,4,232,2,116,71,1,129,34,1,1,186,0,189,104,192,88,56,180,128,0,93,128,30,250,0,208,249,34,1,65,88,158,75,128,158,55,178,68,44,1,231,141,88,245,
214,219,126,4,4,232,253,212,74,75,131,9,8,208,131,21,92,119,115,2,2,116,1,122,110,140,248,156,128,0,93,128,238,40,32,80,36,32,64,23,160,23,13,24,11,135,22,16,160,11,208,67,31,0,58,95,36,32,8,203,115,9,
208,243,70,150,136,37,224,188,17,171,222,122,219,143,128,0,189,159,90,105,105,48,1,1,122,176,130,235,110,78,64,128,46,64,207,141,17,159,19,16,160,11,208,29,5,4,138,4,4,232,2,244,162,1,99,225,208,2,2,116,
1,122,232,3,64,231,139,4,4,97,121,46,1,122,222,200,18,177,4,156,55,98,213,91,111,251,17,16,160,247,83,43,45,13,38,32,64,15,86,112,221,205,9,8,208,5,232,185,49,226,115,2,2,116,1,186,163,128,64,145,128,
0,93,128,94,52,96,44,28,90,64,128,46,64,15,125,0,232,124,145,128,32,44,207,37,64,207,27,89,34,150,128,243,70,172,122,235,109,63,2,2,244,126,106,165,165,193,4,4,232,193,10,174,187,57,1,1,186,0,61,55,70,
124,78,64,128,46,64,119,20,16,40,18,16,160,11,208,139,6,140,133,67,11,8,208,5,232,161,15,0,157,47,18,16,132,229,185,4,232,121,35,75,196,18,112,222,136,85,111,189,237,71,64,128,222,79,173,180,52,152,128,
0,61,88,193,117,55,39,32,64,23,160,231,198,136,207,9,8,208,5,232,142,2,2,69,2,2,116,1,122,209,128,177,112,104,1,1,186,0,61,244,1,160,243,69,2,130,176,60,151,0,61,111,100,137,88,2,206,27,177,234,173,183,
253,8,8,208,251,169,149,150,6,19,16,160,7,43,184,238,230,4,4,232,2,244,220,24,241,57,1,1,186,0,221,81,64,160,72,64,128,46,64,47,26,48,22,14,45,32,64,23,160,135,62,0,116,190,72,64,16,150,231,18,160,231,
141,44,17,75,192,121,35,86,189,245,182,31,1,1,122,63,181,210,210,96,2,2,244,96,5,215,221,156,128,0,93,128,158,27,35,62,39,32,64,23,160,59,10,8,20,9,8,208,5,232,69,3,198,194,161,5,4,232,2,244,208,7,128,
206,23,9,8,194,242,92,2,244,188,145,37,98,9,56,111,196,170,183,222,246,35,32,64,239,167,86,90,26,76,64,128,30,172,224,186,155,19,16,160,11,208,115,99,196,231,4,4,232,2,116,71,1,129,34,1,1,186,0,189,104,
192,88,56,180,128,0,93,128,30,250,0,208,249,34,1,65,88,158,75,128,158,55,178,68,44,1,231,141,88,245,214,219,126,4,4,232,253,212,74,75,131,9,8,208,131,21,92,119,115,2,2,116,1,122,110,140,248,156,128,0,
93,128,238,40,32,80,36,32,64,23,160,23,13,24,11,135,22,16,160,11,208,67,31,0,58,95,36,32,8,203,115,9,208,243,70,150,136,37,224,188,17,171,222,122,219,143,128,0,189,159,90,105,105,48,1,1,122,176,130,235,
110,78,64,128,46,64,207,141,17,159,19,16,160,11,208,29,5,4,138,4,4,232,2,244,162,1,99,225,208,2,2,116,1,122,232,3,64,231,139,4,4,97,121,46,1,122,222,200,18,177,4,156,55,98,213,91,111,251,17,16,160,247,
83,43,45,13,38,32,64,15,86,112,221,205,9,8,208,5,232,185,49,226,115,2,2,116,1,186,163,128,64,145,128,0,93,128,94,52,96,44,28,90,64,128,46,64,15,125,0,232,124,145,128,32,44,207,37,64,207,27,89,34,150,128,
243,70,172,122,235,109,63,2,2,244,126,106,165,165,193,4,4,232,193,10,174,187,57,1,1,186,0,61,55,70,124,78,64,128,46,64,119,20,16,40,18,16,160,11,208,139,6,140,133,67,11,8,208,5,232,161,15,0,157,47,18,
16,132,229,185,4,232,121,35,75,196,18,112,222,136,85,111,189,237,71,64,128,222,79,173,180,52,152,128,0,61,88,193,117,55,39,32,64,23,160,231,198,136,207,9,8,208,5,232,142,2,2,69,2,2,116,1,122,209,128,177,
112,104,1,1,186,0,61,244,1,160,243,69,2,130,176,60,151,0,61,111,100,137,88,2,206,27,177,234,173,183,253,8,8,208,251,169,149,150,6,19,16,160,7,43,184,238,230,4,4,232,2,244,220,24,241,57,1,1,186,0,221,81,
64,160,72,64,128,46,64,47,26,48,22,14,45,32,64,23,160,135,62,0,116,190,72,64,16,150,231,18,160,231,141,44,17,75,192,121,35,86,189,245,182,31,1,1,122,63,181,210,210,96,2,2,244,96,5,215,221,156,128,0,93,
128,158,27,35,62,39,32,64,23,160,59,10,8,20,9,8,208,5,232,69,3,198,194,161,5,4,232,2,244,208,7,128,206,23,9,8,194,242,92,2,244,188,145,37,98,9,56,111,196,170,183,222,246,35,32,64,239,167,86,90,26,76,64,
128,30,172,224,186,155,19,16,160,11,208,115,99,196,231,4,4,232,2,116,71,1,129,34,1,1,186,0,189,104,192,88,56,180,128,0,93,128,30,250,0,208,249,34,1,65,88,158,75,128,158,55,178,68,44,1,231,141,88,245,214,
219,126,4,4,232,253,212,74,75,131,9,8,208,131,21,92,119,115,2,2,116,1,122,110,140,248,156,128,0,93,128,238,40,32,80,36,32,64,23,160,23,13,24,11,135,22,16,160,11,208,67,31,0,58,95,36,32,8,203,115,9,208,
243,70,150,136,37,224,188,17,171,222,122,219,143,128,0,189,159,90,105,105,48,1,1,122,176,130,235,110,78,64,128,46,64,207,141,17,159,19,16,160,11,208,29,5,4,138,4,4,232,2,244,162,1,99,225,208,2,2,116,1,
122,232,3,64,231,139,4,4,97,121,46,1,122,222,200,18,177,4,156,55,98,213,91,111,251,17,16,160,247,83,43,45,13,38,32,64,15,86,112,221,205,9,8,208,5,232,185,49,226,115,2,2,116,1,186,163,128,64,145,128,0,
93,128,94,52,96,44,28,90,64,128,46,64,15,125,0,232,124,145,128,32,44,207,37,64,207,27,89,34,150,128,243,70,172,122,235,109,63,2,2,244,126,106,165,165,193,4,4,232,193,10,174,187,57,1,1,186,0,61,55,70,124,
78,64,128,46,64,119,20,16,40,18,16,160,11,208,139,6,140,133,67,11,8,208,5,232,161,15,0,157,47,18,16,132,229,185,4,232,121,35,75,196,18,112,222,136,85,111,189,237,71,64,128,222,79,173,180,52,152,128,0,
61,88,193,117,55,39,32,64,23,160,231,198,136,207,9,8,208,5,232,142,2,2,69,2,2,116,1,122,209,128,177,112,104,1,1,186,0,61,244,1,160,243,69,2,130,176,60,151,0,61,111,100,137,88,2,206,27,177,234,173,183,
253,8,8,208,251,169,149,150,6,19,16,160,7,43,184,238,230,4,4,232,2,244,220,24,241,57,1,1,186,0,221,81,64,160,72,64,128,46,64,47,26,48,22,14,45,32,64,23,160,135,62,0,116,190,72,64,16,150,231,18,160,231,
141,44,17,75,192,121,35,86,189,245,182,31,1,1,122,63,181,210,210,96,2,2,244,96,5,215,221,156,128,0,93,128,158,27,35,62,39,32,64,23,160,59,10,8,20,9,8,208,5,232,69,3,198,194,161,5,4,232,2,244,208,7,128,
206,23,9,8,194,242,92,2,244,188,145,37,98,9,56,111,196,170,183,222,246,35,32,64,239,167,86,90,26,76,64,128,30,172,224,186,155,19,16,160,11,208,115,99,196,231,4,4,232,2,116,71,1,129,34,1,1,186,0,189,104,
192,88,56,180,128,0,93,128,30,250,0,208,249,34,1,65,88,158,75,128,158,55,178,68,44,1,231,141,88,245,214,219,126,4,4,232,253,212,74,75,131,9,8,208,131,21,92,119,115,2,2,116,1,122,110,140,248,156,128,0,
93,128,238,40,32,80,36,32,64,23,160,23,13,24,11,135,22,16,160,11,208,67,31,0,58,95,36,32,8,203,115,9,208,243,70,150,136,37,224,188,17,171,222,122,219,143,128,0,189,159,90,105,105,48,1,1,122,176,130,235,
110,78,64,128,46,64,207,141,17,159,19,16,160,11,208,29,5,4,138,4,4,232,2,244,162,1,99,225,208,2,2,116,1,122,232,3,64,231,139,4,4,97,121,46,1,122,222,200,18,177,4,156,55,98,213,91,111,251,17,16,160,247,
83,43,45,13,38,32,64,15,86,112,221,205,9,8,208,5,232,185,49,226,115,2,2,116,1,186,163,128,64,145,128,0,93,128,94,52,96,44,28,90,64,128,46,64,15,125,0,232,124,145,128,32,44,207,37,64,207,27,89,34,150,128,
243,70,172,122,235,109,63,2,2,244,126,106,165,165,193,4,4,232,193,10,174,187,57,1,1,186,0,61,55,70,124,78,64,128,46,64,119,20,16,40,18,16,160,11,208,139,6,140,133,67,11,8,208,5,232,161,15,0,157,47,18,
16,132,229,185,4,232,121,35,75,196,18,112,222,136,85,111,189,237,71,64,128,222,79,173,180,52,152,128,0,61,88,193,117,55,39,32,64,23,160,231,198,136,207,9,8,208,5,232,142,2,2,69,2,2,116,1,122,209,128,177,
112,104,1,1,186,0,61,244,1,160,243,69,2,130,176,60,151,0,61,111,100,137,88,2,206,27,177,234,173,183,253,8,8,208,251,169,149,150,6,19,16,160,7,43,184,238,230,4,4,232,2,244,220,24,241,57,1,1,186,0,221,81,
64,160,72,64,128,46,64,47,26,48,22,14,45,32,64,23,160,135,62,0,116,190,72,64,16,150,231,18,160,231,141,44,17,75,192,121,35,86,189,245,182,31,1,1,122,63,181,210,210,96,2,2,244,96,5,215,221,156,128,0,93,
128,158,27,35,62,39,32,64,23,160,59,10,8,20,9,8,208,5,232,69,3,198,194,161,5,4,232,2,244,208,7,128,206,23,9,8,194,242,92,2,244,188,145,37,98,9,56,111,196,170,183,222,246,35,32,64,239,167,86,90,26,76,64,
128,30,172,224,186,155,19,16,160,11,208,115,99,196,231,4,4,232,2,116,71,1,129,34,1,1,186,0,189,104,192,88,56,180,128,0,93,128,30,250,0,208,249,34,1,65,88,158,75,128,158,55,178,68,44,1,231,141,88,245,214,
219,126,4,4,232,253,212,74,75,131,9,8,208,131,21,92,119,115,2,2,116,1,122,110,140,248,156,128,0,93,128,238,40,32,80,36,32,64,23,160,23,13,24,11,135,22,16,160,11,208,67,31,0,58,95,36,32,8,203,115,9,208,
243,70,150,136,37,224,188,17,171,222,122,219,143,128,0,189,159,90,105,105,48,1,1,122,176,130,235,110,78,64,128,46,64,207,141,17,159,19,16,160,11,208,29,5,4,138,4,4,232,2,244,162,1,99,225,208,2,2,116,1,
122,232,3,64,231,139,4,4,97,121,46,1,122,222,200,18,177,4,156,55,98,213,91,111,251,17,16,160,247,83,43,45,13,38,32,64,15,86,112,221,205,9,8,208,5,232,185,49,226,115,2,2,116,1,186,163,128,64,145,128,0,
93,128,94,52,96,44,28,90,64,128,46,64,15,125,0,232,124,145,128,32,44,207,37,64,207,27,89,34,150,128,243,70,172,122,235,109,63,2,2,244,126,106,165,165,193,4,4,232,193,10,174,187,57,1,1,186,0,61,55,70,124,
78,64,128,46,64,119,20,16,40,18,16,160,11,208,139,6,140,133,67,11,8,208,5,232,161,15,0,157,47,18,16,132,229,185,4,232,121,35,75,196,18,112,222,136,85,111,189,237,71,64,128,222,79,173,180,52,152,128,0,
61,88,193,117,55,39,32,64,23,160,231,198,136,207,9,8,208,5,232,142,2,2,69,2,2,116,1,122,209,128,177,112,104,1,1,186,0,61,244,1,160,243,69,2,130,176,60,151,0,61,111,100,137,88,2,206,27,177,234,173,183,
253,8,8,208,251,169,149,150,6,19,16,160,7,43,184,238,230,4,4,232,2,244,220,24,241,57,1,1,186,0,221,81,64,160,72,64,128,46,64,47,26,48,22,14,45,32,64,23,160,135,62,0,116,190,72,64,16,150,231,18,160,231,
141,44,17,75,192,121,35,86,189,245,182,31,1,1,122,63,181,210,210,96,2,2,244,96,5,215,221,156,128,0,93,128,158,27,35,62,39,32,64,23,160,59,10,8,20,9,8,208,5,232,69,3,198,194,161,5,4,232,2,244,208,7,128,
206,23,9,8,194,242,92,2,244,188,145,37,98,9,56,111,196,170,183,222,246,35,32,64,239,167,86,90,26,76,64,128,30,172,224,186,155,19,16,160,11,208,115,99,196,231,4,4,232,2,116,71,1,129,34,1,1,186,0,189,104,
192,88,56,180,128,0,93,128,30,250,0,208,249,34,1,65,88,158,75,128,158,55,178,68,44,1,231,141,88,245,214,219,126,4,4,232,253,212,74,75,131,9,8,208,131,21,92,119,115,2,2,116,1,122,110,140,248,156,128,0,
93,128,238,40,32,80,36,32,64,23,160,23,13,24,11,135,22,16,160,11,208,67,31,0,58,95,36,32,8,203,115,9,208,243,70,150,136,37,224,188,17,171,222,122,219,143,128,0,189,159,90,105,105,48,1,1,122,176,130,235,
110,78,64,128,46,64,207,141,17,159,19,16,160,11,208,29,5,4,138,4,4,232,2,244,162,1,99,225,208,2,2,116,1,122,232,3,64,231,139,4,4,97,121,46,1,122,222,200,18,177,4,156,55,98,213,91,111,251,17,16,160,247,
83,43,45,13,38,32,64,15,86,112,221,205,9,8,208,5,232,185,49,226,115,2,2,116,1,186,163,128,64,145,128,0,93,128,94,52,96,44,28,90,64,128,46,64,15,125,0,232,124,145,128,32,44,207,37,64,207,27,89,34,150,128,
243,70,172,122,235,109,63,2,2,244,126,106,165,165,193,4,4,232,193,10,174,187,57,1,1,186,0,61,55,70,124,78,64,128,46,64,119,20,16,40,18,16,160,11,208,139,6,140,133,67,11,8,208,5,232,161,15,0,157,47,18,
16,132,229,185,4,232,121,35,75,196,18,112,222,136,85,111,189,237,71,64,128,222,79,173,180,52,152,128,0,61,88,193,117,55,39,32,64,23,160,231,198,136,207,9,8,208,5,232,142,2,2,69,2,2,116,1,122,209,128,177,
112,104,1,1,186,0,61,244,1,160,243,69,2,130,176,60,151,0,61,111,100,137,88,2,206,27,177,234,173,183,253,8,8,208,251,169,149,150,6,19,16,160,7,43,184,238,230,4,4,232,2,244,220,24,241,57,1,1,186,0,221,81,
64,160,72,64,128,46,64,47,26,48,22,14,45,32,64,23,160,135,62,0,116,190,72,64,16,150,231,18,160,231,141,44,17,75,192,121,35,86,189,245,182,31,1,1,122,63,181,210,210,96,2,2,244,96,5,215,221,156,128,0,93,
128,158,27,35,62,39,32,64,23,160,59,10,8,20,9,8,208,5,232,69,3,198,194,161,5,4,232,2,244,208,7,128,206,23,9,8,194,242,92,2,244,188,145,37,98,9,56,111,196,170,183,222,246,35,32,64,239,167,86,90,26,76,64,
128,30,172,224,186,155,19,16,160,11,208,115,99,196,231,4,4,232,2,116,71,1,129,34,1,1,186,0,189,104,192,88,56,180,128,0,93,128,30,250,0,208,249,34,1,65,88,158,75,128,158,55,178,68,44,1,231,141,88,245,214,
219,126,4,4,232,253,212,74,75,131,9,8,208,131,21,92,119,115,2,2,116,1,122,110,140,248,156,128,0,93,128,238,40,32,80,36,32,64,23,160,23,13,24,11,135,22,16,160,11,208,67,31,0,58,95,36,32,8,203,115,9,208,
243,70,150,136,37,224,188,17,171,222,122,219,143,128,0,189,159,90,105,105,48,1,1,122,176,130,235,110,78,64,128,46,64,207,141,17,159,19,16,160,11,208,29,5,4,138,4,4,232,2,244,162,1,99,225,208,2,2,116,1,
122,232,3,64,231,139,4,4,97,121,46,1,122,222,200,18,177,4,156,55,98,213,91,111,251,17,16,160,247,83,43,45,13,38,32,64,15,86,112,221,205,9,8,208,5,232,185,49,226,115,2,2,116,1,186,163,128,64,145,128,0,
93,128,94,52,96,44,28,90,64,128,46,64,15,125,0,232,124,145,128,32,44,207,37,64,207,27,89,34,150,128,243,70,172,122,235,109,63,2,2,244,126,106,165,165,193,4,82,128,254,34,117,249,118,176,110,235,46,129,
171,4,4,232,215,140,141,116,190,248,201,208,33,64,224,92,64,32,118,245,72,120,254,252,249,225,205,155,55,191,55,86,8,16,112,190,200,141,129,244,221,226,147,180,204,215,185,229,124,78,32,138,128,11,219,
87,87,250,31,255,248,199,227,244,253,235,179,40,99,65,63,9,228,4,156,47,114,66,31,124,224,123,70,222,200,18,177,4,156,55,98,213,91,111,251,17,16,160,247,83,43,45,13,38,32,64,15,86,112,221,189,86,224,195,
15,63,124,122,231,206,157,135,152,46,23,72,231,139,127,165,79,110,241,33,64,224,131,15,210,29,98,15,239,222,189,251,148,197,175,5,94,188,120,113,235,199,31,127,156,206,23,254,8,16,72,2,206,23,87,15,131,
239,190,251,238,126,250,254,245,141,129,66,128,192,185,128,11,219,215,158,47,190,72,231,139,207,141,21,2,4,206,5,110,220,184,241,187,163,163,163,51,30,87,11,8,208,141,14,2,23,5,124,207,48,34,8,180,41,
32,64,111,179,46,90,69,96,154,141,57,93,176,186,143,130,0,129,15,62,72,23,100,158,164,0,253,17,139,203,5,4,232,70,6,129,11,2,15,142,143,143,159,49,249,181,128,0,221,168,32,240,43,1,231,139,43,6,69,122,
180,234,237,131,131,131,233,137,88,254,8,16,72,2,2,177,171,135,65,154,112,243,89,250,189,246,216,64,33,64,224,92,32,253,22,113,189,61,51,24,76,212,115,180,16,184,40,224,188,97,68,16,104,83,192,127,208,
219,172,139,86,17,152,2,244,233,145,137,211,163,19,253,17,8,47,32,64,191,126,8,120,98,69,248,67,4,192,69,1,129,216,53,35,194,43,31,28,46,4,46,8,56,95,92,49,32,188,242,193,145,66,192,133,237,109,199,128,
119,25,111,43,101,185,32,2,103,41,8,251,93,144,190,238,220,77,223,51,118,166,179,226,160,2,2,244,65,11,171,91,221,11,8,208,187,47,161,14,140,42,144,222,35,246,85,122,143,216,167,163,246,79,191,8,148,8,
164,99,225,203,147,147,147,47,74,214,137,180,172,0,61,82,181,245,53,39,144,206,23,31,167,243,197,105,110,185,168,159,123,98,69,212,202,235,247,101,2,206,23,87,143,11,79,172,112,204,16,184,40,224,194,246,
213,35,194,163,152,29,45,4,46,8,188,74,231,139,143,152,92,47,224,123,134,17,66,192,121,195,24,32,208,131,128,0,189,135,42,105,99,72,129,20,160,63,78,23,245,62,11,217,121,157,38,240,11,1,239,40,189,126,
72,120,229,131,67,134,192,127,4,188,59,44,123,190,152,222,129,126,203,152,33,64,192,59,141,175,27,3,46,108,59,66,8,184,176,189,237,24,16,160,111,43,101,185,32,2,47,83,128,126,20,164,175,59,119,211,247,
140,157,233,172,56,166,128,137,55,99,214,85,175,6,16,16,160,15,80,68,93,24,83,32,189,15,232,139,244,216,234,207,199,236,157,94,17,40,22,240,136,213,107,200,76,184,41,30,79,86,24,88,64,128,158,13,208,191,
73,75,220,31,120,8,232,26,129,173,5,188,211,56,123,190,48,225,102,235,209,100,193,193,5,78,83,32,246,241,224,125,220,185,123,130,176,157,233,172,56,166,192,179,116,190,120,48,102,215,234,246,202,147,177,
234,122,218,90,215,2,190,103,116,93,62,141,31,89,64,128,62,114,117,245,173,107,1,179,184,187,46,159,198,87,22,16,136,93,15,106,194,77,229,1,103,115,61,11,152,185,157,169,158,9,55,61,15,111,109,175,44,
224,14,177,12,168,39,220,84,30,113,54,215,173,64,154,216,254,228,206,157,59,143,186,237,192,2,13,23,132,45,128,108,23,93,8,56,95,108,95,38,223,51,182,183,178,228,216,2,206,27,99,215,87,239,250,22,16,160,
247,93,63,173,31,88,192,44,238,129,139,171,107,197,2,222,57,120,61,153,9,55,197,67,202,10,227,10,152,185,157,169,173,9,55,227,14,126,61,43,22,112,190,200,144,153,112,83,60,166,172,48,168,64,122,181,218,
163,147,147,147,39,131,118,175,74,183,210,239,145,23,105,67,183,171,108,204,70,8,116,44,224,245,115,219,23,207,247,140,237,173,44,57,182,128,243,198,216,245,213,187,190,5,4,232,125,215,79,235,7,23,48,
139,123,240,2,235,222,182,2,238,16,203,72,153,112,179,237,80,178,220,232,2,102,110,231,43,108,194,77,222,200,18,49,4,156,47,242,117,54,225,38,111,100,137,48,2,94,39,149,41,117,10,194,190,74,19,13,62,13,
51,34,116,148,192,21,2,233,56,248,56,77,184,57,5,148,23,240,61,35,111,100,137,48,2,190,103,132,41,181,142,246,38,32,64,239,173,98,218,27,74,192,44,238,80,229,214,217,171,5,188,67,108,139,209,145,206,23,
63,109,177,152,69,8,12,45,96,230,118,190,188,38,220,228,141,44,17,67,192,249,34,95,103,19,110,242,70,150,136,33,224,117,82,249,58,11,194,242,70,150,136,33,224,124,177,125,157,125,207,216,222,202,146,99,
11,56,111,140,93,95,189,235,91,64,128,222,119,253,180,126,112,1,143,51,26,188,192,186,183,149,64,154,193,253,101,154,193,253,197,86,11,7,94,200,132,155,192,197,215,245,159,5,220,241,177,221,96,240,132,
155,237,156,44,53,182,128,11,85,249,250,154,112,147,55,178,68,8,129,179,244,58,169,223,133,232,233,30,157,20,132,237,129,103,213,145,4,60,61,175,160,154,190,103,20,96,89,116,100,1,231,141,145,171,171,
111,221,11,8,208,187,47,161,14,140,44,224,71,232,200,213,213,183,109,5,4,98,219,73,153,112,179,157,147,165,134,22,112,129,123,203,242,122,204,234,150,80,22,27,89,192,249,98,203,234,166,223,35,223,167,
69,15,183,92,220,98,4,70,20,240,52,172,45,170,42,8,219,2,201,34,195,11,120,61,76,121,137,125,207,40,55,179,198,88,2,233,188,241,244,206,157,59,15,199,234,149,222,16,24,71,64,128,62,78,45,245,100,64,1,
63,66,7,44,170,46,149,10,184,192,189,165,152,9,55,91,66,89,108,100,1,23,184,183,172,238,183,223,126,251,233,193,193,193,87,91,46,110,49,2,35,10,56,95,108,89,85,19,244,182,132,178,216,176,2,94,247,176,
125,105,61,17,107,123,43,75,14,43,224,61,198,133,165,245,61,163,16,204,226,35,10,56,111,140,88,85,125,26,70,64,128,62,76,41,117,100,84,1,179,49,71,173,172,126,109,41,224,2,247,150,80,38,220,108,9,101,
177,97,5,188,238,97,251,210,58,95,108,111,101,201,49,5,4,98,219,215,213,4,189,237,173,44,57,166,128,215,61,108,95,87,65,216,246,86,150,28,83,192,249,162,188,174,190,103,148,155,89,99,44,1,231,141,177,
234,169,55,227,9,8,208,199,171,169,30,13,38,224,71,232,96,5,213,157,34,1,23,184,139,184,62,72,63,62,191,73,107,220,47,91,203,210,4,198,16,240,195,179,172,142,38,232,149,121,89,122,44,1,231,139,237,235,
105,194,205,246,86,150,28,82,192,123,73,11,202,42,8,43,192,178,232,136,2,206,23,59,84,213,247,140,29,208,172,50,146,128,243,198,72,213,212,151,33,5,4,232,67,150,85,167,70,18,248,238,187,239,238,167,247,
161,76,161,152,63,2,225,4,92,224,46,43,185,199,50,151,121,89,122,40,1,63,60,11,203,105,130,94,33,152,197,71,18,112,190,40,172,102,10,197,190,78,171,124,82,184,154,197,9,116,47,224,125,198,229,37,52,65,
175,220,204,26,99,8,120,26,214,238,117,116,35,192,238,118,214,236,91,192,121,163,239,250,105,125,12,1,1,122,140,58,235,101,231,2,126,132,118,94,64,205,223,85,192,227,219,11,229,204,222,46,4,179,248,48,
2,126,120,150,151,242,249,243,231,135,55,111,222,252,190,124,77,107,16,232,91,192,249,162,188,126,38,232,149,155,89,99,12,129,116,190,248,248,228,228,228,116,140,222,44,211,11,19,244,150,113,182,151,246,
4,76,254,223,189,38,190,103,236,110,103,205,190,5,210,83,55,143,238,222,189,251,178,239,94,104,61,129,177,5,4,232,99,215,87,239,6,17,240,35,116,144,66,234,70,169,192,131,227,227,227,103,165,43,69,95,62,
157,47,190,74,23,251,62,141,238,160,255,177,4,92,176,218,173,222,38,232,237,230,102,173,190,5,156,47,202,235,103,130,94,185,153,53,134,16,240,180,138,29,202,104,130,222,14,104,86,25,65,192,228,255,61,
170,232,123,198,30,120,86,237,89,192,247,140,158,171,167,237,97,4,4,232,97,74,173,163,61,11,248,50,217,115,245,180,125,71,129,179,27,55,110,124,116,116,116,116,182,227,250,97,87,51,123,59,108,233,35,119,
220,5,171,29,171,159,94,19,243,69,122,60,237,231,59,174,110,53,2,61,10,56,95,236,88,53,19,244,118,132,179,90,183,2,158,86,177,123,233,76,208,219,221,206,154,125,10,164,187,72,31,166,187,72,159,246,217,
250,54,90,237,123,70,27,117,208,138,229,4,124,207,88,206,218,158,8,236,35,32,64,223,71,207,186,4,22,20,240,35,116,65,108,187,106,65,192,5,238,29,171,176,153,112,51,61,150,249,214,142,155,176,26,129,174,
4,210,15,207,71,233,241,170,79,186,106,116,35,141,53,65,175,145,66,104,198,146,2,158,110,179,163,118,154,112,115,63,77,184,249,102,199,213,173,70,160,59,1,79,171,216,189,100,233,124,241,89,58,95,60,222,
125,11,214,36,208,149,128,201,255,21,202,229,123,70,5,68,155,232,73,224,44,125,207,56,186,119,239,222,171,158,26,173,173,4,34,10,8,208,35,86,93,159,187,20,112,87,105,151,101,211,232,29,5,188,111,112,71,
184,205,106,94,251,176,159,159,181,187,18,112,193,106,207,114,185,219,99,79,64,171,247,36,240,42,61,221,38,61,220,198,211,109,118,45,154,9,189,187,202,89,175,67,1,147,121,247,40,154,9,122,123,224,89,181,
59,129,52,89,228,201,157,59,119,30,117,215,240,6,27,236,123,70,131,69,209,164,89,4,210,121,227,105,58,111,60,156,101,227,54,74,128,64,85,1,1,122,85,78,27,35,48,175,128,47,147,243,250,218,122,51,2,46,88,
237,89,10,23,173,246,4,180,122,55,2,30,123,182,127,169,188,171,116,127,67,91,232,67,192,249,98,255,58,153,208,187,191,161,45,244,33,144,30,199,124,148,30,199,252,178,143,214,182,217,74,19,122,219,172,
139,86,85,23,112,23,105,69,82,223,51,42,98,218,84,203,2,103,233,123,198,199,190,103,180,92,34,109,35,240,31,1,1,186,209,64,160,35,1,95,38,59,42,150,166,238,44,224,238,243,157,233,46,172,232,162,85,29,
71,91,105,90,192,221,231,149,202,147,38,232,125,157,54,245,73,165,205,217,12,129,22,5,156,47,42,85,197,132,222,74,144,54,211,178,128,201,188,21,170,99,66,111,5,68,155,104,94,192,93,164,245,75,228,123,
70,125,83,91,108,78,192,247,140,230,74,162,65,4,174,22,16,160,27,29,4,58,19,240,101,178,179,130,105,110,169,128,47,146,165,98,87,44,239,162,85,37,72,155,105,86,192,221,164,245,74,147,38,232,221,62,56,
56,120,81,111,139,182,68,160,45,1,231,139,122,245,48,161,183,158,165,45,181,41,96,50,111,189,186,120,77,76,61,75,91,106,83,192,211,42,234,215,197,247,140,250,166,182,216,150,128,243,70,91,245,208,26,2,
57,1,1,122,78,200,231,4,26,19,240,101,178,177,130,104,78,85,1,23,172,170,114,126,224,162,85,93,79,91,107,74,192,221,164,149,203,225,46,244,202,160,54,215,146,128,243,69,229,106,152,208,91,25,212,230,90,
18,48,153,183,98,53,76,232,173,136,105,83,45,10,56,95,204,84,21,223,51,102,130,181,217,22,4,156,55,90,168,130,54,16,40,16,16,160,23,96,89,148,64,43,2,233,203,228,116,151,216,237,86,218,163,29,4,42,9,248,
34,89,9,242,221,102,54,23,173,190,79,255,247,173,202,155,182,57,2,171,10,184,155,180,62,191,119,161,215,55,181,197,54,4,210,249,226,209,201,201,201,147,54,90,51,70,43,190,251,238,187,251,233,177,181,223,
140,209,27,189,32,240,179,128,119,146,206,48,24,210,249,226,139,116,190,248,124,134,77,219,36,129,53,5,76,206,155,81,63,93,243,156,94,45,53,189,98,202,31,129,145,4,206,94,191,126,125,116,239,222,189,87,
35,117,74,95,8,140,46,32,64,31,189,194,250,55,164,128,71,173,14,89,214,232,157,242,3,116,166,17,224,169,21,51,193,218,236,154,2,167,55,110,220,120,112,116,116,116,182,102,35,70,220,119,122,106,197,227,
20,54,126,54,98,223,244,41,172,192,233,241,241,241,199,97,123,63,99,199,61,181,98,70,92,155,94,69,192,228,188,249,216,221,77,58,159,173,45,175,35,96,114,222,252,238,190,103,204,111,108,15,203,10,248,158,
177,172,183,189,17,168,37,32,64,175,37,105,59,4,22,22,240,104,230,133,193,237,110,86,1,63,64,103,229,253,192,83,43,230,245,181,245,101,5,188,234,97,62,239,205,83,43,166,167,220,28,206,183,23,91,38,176,
152,192,89,58,95,60,72,119,159,159,46,182,199,64,59,242,104,230,64,197,142,209,213,87,105,114,94,154,155,103,114,222,28,229,246,212,138,57,84,109,115,69,1,147,121,23,192,247,61,99,1,100,187,88,82,224,
101,250,158,241,177,239,25,75,146,219,23,129,58,2,2,244,58,142,182,66,96,113,1,143,102,94,156,220,14,231,19,240,3,116,62,219,183,91,246,104,230,153,129,109,126,49,129,244,8,208,39,119,238,220,121,180,
216,14,3,238,200,35,19,3,22,125,208,46,59,95,204,95,88,143,102,158,223,216,30,150,17,48,57,111,126,103,119,147,206,111,108,15,203,8,56,95,44,227,60,237,197,247,140,229,172,237,105,94,1,231,141,121,125,
109,157,192,156,2,2,244,57,117,109,155,192,204,2,102,114,207,12,108,243,75,8,120,215,224,18,202,126,124,46,164,108,55,51,11,184,59,108,102,224,119,155,119,145,123,33,104,187,153,83,192,93,30,115,234,190,
183,109,79,185,89,8,218,110,102,19,48,217,102,54,218,11,27,246,148,155,101,156,237,101,94,1,231,139,121,125,47,219,186,239,25,203,155,219,99,93,1,231,141,186,158,182,70,96,105,1,1,250,210,226,246,71,160,
178,128,71,185,87,6,181,185,69,5,60,186,125,81,238,233,81,238,223,164,61,222,95,118,175,246,70,160,138,128,71,49,87,97,220,110,35,155,139,220,211,249,226,246,118,107,88,138,64,83,2,38,231,45,88,14,79,
197,90,16,219,174,230,16,48,217,102,14,213,43,182,233,6,128,5,177,237,106,14,1,79,206,155,67,53,179,77,223,51,86,64,183,203,154,2,206,27,53,53,109,139,192,10,2,2,244,21,208,237,146,64,109,1,51,50,107,
139,218,222,18,2,102,97,46,161,124,113,31,238,252,88,222,220,30,235,8,152,108,83,199,177,100,43,94,253,80,162,101,217,150,4,222,188,121,243,240,238,221,187,79,91,106,211,232,109,17,138,141,94,225,97,251,
103,178,205,10,165,245,72,230,21,208,237,178,134,192,89,122,127,241,71,222,95,92,131,178,124,27,190,103,148,155,89,163,9,129,179,215,175,95,31,221,187,119,239,85,19,173,209,8,2,4,118,18,16,160,239,196,
102,37,2,109,9,108,66,177,127,181,213,42,173,33,112,173,128,187,61,86,26,32,126,124,174,4,111,183,59,11,164,201,54,79,211,123,207,31,238,188,1,43,238,44,224,125,232,59,211,89,113,37,1,147,243,86,130,79,
187,77,79,197,122,156,38,59,125,182,94,11,236,153,64,177,192,131,227,227,227,103,197,107,89,97,111,1,79,197,218,155,208,6,150,23,112,190,88,222,252,194,30,125,207,88,185,0,118,191,139,128,243,198,46,106,
214,33,208,152,128,0,189,177,130,104,14,129,93,5,132,98,187,202,89,111,5,1,179,48,87,64,127,127,151,223,126,251,237,167,7,7,7,95,173,220,12,187,39,176,141,128,201,54,219,40,205,184,140,87,197,204,136,
107,211,181,5,156,47,106,139,22,110,79,40,86,8,102,241,213,4,76,182,89,141,254,237,142,189,42,102,93,127,123,47,19,240,36,172,50,175,57,151,246,61,99,78,93,219,174,41,224,188,81,83,211,182,8,172,43,32,
64,95,215,223,222,9,84,21,16,162,87,229,180,177,121,4,188,199,120,30,215,226,173,154,193,93,76,102,133,229,5,132,97,203,155,95,186,71,33,122,35,133,208,140,235,4,156,47,26,25,31,94,45,213,72,33,52,227,
74,1,225,121,27,131,195,171,165,218,168,131,86,92,47,224,124,209,222,8,241,61,163,189,154,104,209,69,1,231,13,35,130,192,88,2,2,244,177,234,169,55,4,62,72,33,250,103,233,63,214,143,81,16,104,80,224,44,
181,233,161,71,37,182,83,25,161,88,59,181,208,146,95,9,120,82,69,99,131,194,29,31,141,21,68,115,222,23,16,158,55,52,30,220,89,218,80,49,52,229,87,2,211,69,237,244,20,166,47,189,199,184,141,193,241,252,
249,243,195,155,55,111,190,72,173,185,213,70,139,180,130,192,127,4,132,96,109,142,6,223,51,218,172,139,86,157,11,56,111,24,9,4,198,19,16,160,143,87,83,61,34,224,29,132,198,64,139,2,194,243,22,171,146,
218,148,66,177,175,211,191,62,105,180,121,154,21,83,192,147,42,26,173,187,59,62,26,45,76,236,102,153,108,211,96,253,221,89,218,96,81,52,219,139,185,254,0,0,32,0,73,68,65,84,105,18,120,118,227,198,141,
135,194,243,182,6,67,122,181,212,237,52,169,97,10,209,253,17,104,70,32,133,96,79,211,184,124,228,124,209,76,73,46,52,100,243,61,227,251,244,255,52,249,166,205,18,133,108,149,243,70,200,178,235,116,0,1,
1,122,128,34,235,98,76,129,116,39,250,23,233,63,222,159,199,236,189,94,55,38,32,60,111,172,32,191,108,142,59,209,27,47,80,172,230,57,95,52,92,239,205,197,170,105,210,205,253,134,155,169,105,113,4,94,190,
126,253,250,193,189,123,247,94,197,233,114,63,61,117,135,88,63,181,10,210,82,225,121,195,133,222,132,232,223,8,195,26,46,82,160,166,121,82,69,31,197,246,61,163,143,58,69,105,165,243,70,148,74,235,103,
68,1,1,122,196,170,235,115,24,129,244,67,244,211,52,107,246,171,48,29,214,209,22,5,132,97,45,86,229,146,54,121,39,122,39,133,26,187,153,194,176,78,234,235,201,21,157,20,106,236,102,58,95,116,80,95,23,
183,59,40,82,128,38,186,168,221,71,145,133,232,125,212,105,244,86,58,95,244,85,97,223,51,250,170,215,168,173,245,216,246,81,43,171,95,4,206,5,4,232,70,2,129,193,5,210,157,232,247,211,127,204,167,217,220,
254,8,44,45,224,49,204,75,139,239,185,63,79,174,216,19,208,234,251,8,8,195,246,209,91,97,93,147,110,86,64,183,203,119,2,167,233,49,204,15,60,86,181,159,1,145,38,221,76,191,69,238,247,211,98,45,29,69,224,
167,159,126,250,242,228,228,228,139,81,250,51,122,63,132,97,163,87,184,237,254,165,243,197,163,116,190,120,210,118,43,181,238,50,1,223,51,140,139,181,4,156,55,214,146,183,95,2,203,9,8,208,151,179,182,
39,2,171,9,152,205,189,26,125,228,29,159,166,199,170,62,244,88,213,254,134,64,250,241,57,189,15,125,122,68,179,63,2,75,9,8,195,150,146,174,188,159,52,233,230,179,52,73,239,113,229,205,218,28,129,43,5,
220,25,214,239,224,48,233,166,223,218,117,218,242,179,55,111,222,60,186,123,247,238,211,78,219,31,182,217,155,16,125,122,138,222,244,155,196,31,129,37,4,156,47,150,80,158,121,31,190,103,204,12,108,243,
191,20,112,222,48,38,8,4,17,16,160,7,41,180,110,18,240,222,82,99,96,41,1,23,183,151,146,158,111,63,155,73,55,211,133,171,219,243,237,197,150,9,124,48,61,165,98,186,51,204,157,30,29,15,134,205,249,98,154,
116,115,216,113,55,52,189,125,1,23,169,218,175,81,182,133,38,233,101,137,44,80,71,224,101,10,207,31,166,240,252,101,157,205,217,202,26,2,158,140,181,134,122,200,125,122,10,214,64,101,247,26,203,129,138,
217,118,87,156,55,218,174,143,214,17,168,42,32,64,175,202,105,99,4,218,23,240,67,180,253,26,117,220,66,239,59,239,184,120,151,53,221,44,238,193,10,218,86,119,166,139,218,95,30,31,31,63,107,171,89,90,179,
139,128,187,197,118,81,179,78,129,128,139,84,5,88,173,47,106,146,94,235,21,234,187,125,38,242,246,93,191,95,182,222,36,189,177,234,217,90,111,156,47,90,171,72,157,246,248,158,81,199,209,86,46,23,112,222,
48,50,8,196,19,16,160,199,171,185,30,19,248,192,15,81,131,96,6,1,143,108,159,1,181,133,77,110,102,113,127,158,218,114,216,66,123,180,97,8,129,103,233,253,197,15,189,191,120,136,90,94,232,132,71,186,143,
87,211,149,123,244,246,41,21,191,249,205,111,158,58,95,172,92,137,25,118,111,82,239,12,168,177,55,233,41,21,131,214,127,154,164,151,158,40,240,56,253,247,224,211,65,187,168,91,203,11,56,95,44,111,190,
248,30,221,12,176,56,249,232,59,116,222,24,189,194,250,71,224,10,1,1,186,161,65,32,176,128,11,221,129,139,95,175,235,175,210,5,141,47,189,95,176,30,104,171,91,242,3,180,213,202,116,213,174,211,205,35,
219,79,187,106,181,198,22,9,184,208,93,196,101,225,171,5,78,55,239,47,246,8,230,129,71,137,187,196,6,46,238,114,93,59,75,119,131,61,59,56,56,120,100,162,205,114,232,107,236,201,77,0,107,168,15,183,79,
19,243,134,43,233,245,29,242,61,35,88,193,231,233,174,243,198,60,174,182,74,160,27,1,1,122,55,165,210,80,2,243,8,184,208,61,143,107,128,173,250,18,25,160,200,191,236,162,31,160,1,139,94,167,203,206,23,
117,28,187,218,138,11,221,93,149,171,165,198,190,61,95,156,156,156,60,105,169,81,218,50,175,192,102,82,239,244,180,155,91,243,238,201,214,7,19,48,209,102,176,130,110,211,29,55,1,108,163,100,153,75,4,156,
47,2,15,11,223,51,2,23,127,191,174,59,111,236,231,103,109,2,67,8,8,208,135,40,163,78,16,216,95,32,125,161,188,159,102,238,255,209,163,209,246,183,28,124,11,111,239,242,248,241,199,31,255,156,238,58,119,
87,216,224,197,190,170,123,127,255,251,223,63,73,159,61,78,255,28,6,37,208,237,237,4,166,32,236,207,63,252,240,195,211,123,247,238,189,218,110,21,75,141,38,176,185,96,245,39,231,139,209,42,91,189,63,38,
218,84,39,237,111,131,130,177,254,106,182,82,139,167,39,218,252,213,235,29,86,210,111,96,183,110,2,104,160,8,253,52,193,19,176,250,169,213,236,45,245,61,99,118,226,81,118,112,154,58,242,231,227,227,227,
103,163,116,72,63,8,16,216,93,64,128,190,187,157,53,9,12,41,48,221,49,150,222,77,251,39,65,250,144,229,221,167,83,130,176,125,244,6,93,119,19,164,79,119,140,221,30,180,139,186,181,155,192,219,243,69,186,
176,253,196,227,84,119,3,28,113,45,65,250,136,85,173,210,167,87,155,243,133,247,156,87,225,28,99,35,206,23,99,212,113,134,94,8,194,102,64,237,125,147,2,177,222,43,56,91,251,221,57,58,27,109,255,27,246,
61,163,255,26,206,212,3,223,51,102,130,181,89,2,61,11,8,208,123,174,158,182,19,152,81,64,144,62,35,110,95,155,126,57,221,225,225,14,210,190,138,182,116,107,61,193,98,105,241,102,247,231,142,176,102,75,
211,78,195,166,137,55,233,73,38,127,48,81,175,157,154,172,208,146,179,180,207,183,223,47,220,65,186,130,126,71,187,220,92,224,254,67,106,242,253,142,154,173,169,117,5,166,243,197,20,132,125,233,233,87,
117,97,71,219,154,64,108,180,138,238,212,31,79,203,219,137,45,238,74,190,103,196,173,253,123,61,247,61,195,48,32,64,224,90,1,1,186,1,66,128,64,86,192,197,238,44,209,104,11,76,63,60,159,166,199,180,255,
197,133,170,209,74,59,127,127,252,8,157,223,184,177,61,188,189,219,60,253,243,204,249,162,177,202,116,208,156,205,249,226,143,169,169,158,98,209,65,189,42,52,113,154,100,243,55,231,139,10,146,193,54,241,
252,249,243,195,52,217,98,154,124,227,117,16,49,106,111,146,77,140,58,207,210,203,105,98,111,218,240,253,205,249,226,214,44,59,177,209,150,4,222,158,47,210,36,155,191,220,188,121,243,153,167,95,181,84,
154,126,218,226,123,70,63,181,170,212,82,223,51,42,65,218,12,129,8,2,2,244,8,85,214,71,2,21,5,54,97,250,239,211,197,207,233,135,169,11,222,21,109,87,220,212,187,47,143,111,47,106,167,31,158,175,252,240,
92,177,26,131,236,122,122,55,225,235,215,175,63,73,175,132,248,239,205,157,166,46,96,141,81,91,231,139,49,234,216,84,47,166,243,69,122,210,201,167,233,98,247,239,167,139,222,233,31,231,139,166,42,180,
115,99,46,156,47,76,178,217,217,209,138,239,9,108,194,177,219,211,147,44,54,231,11,62,99,8,188,76,221,120,149,66,176,191,166,127,191,116,190,24,163,168,107,247,98,186,118,145,126,135,76,231,139,119,223,
47,214,110,146,253,215,17,120,153,106,122,154,38,252,255,83,104,94,7,212,86,254,35,224,123,198,176,163,225,231,243,70,58,119,156,222,187,119,239,213,176,61,213,49,2,4,170,10,8,208,171,114,218,24,129,88,
2,239,2,178,244,227,229,112,243,163,244,48,9,76,255,248,107,87,96,186,152,61,125,81,156,222,57,250,207,244,239,211,116,71,207,75,129,121,187,5,27,165,101,211,172,238,20,166,79,119,131,56,95,244,83,212,
11,231,11,19,108,250,41,92,239,45,125,119,225,234,224,224,96,154,128,51,125,175,152,38,236,9,213,219,46,236,219,176,60,157,227,167,0,236,127,156,47,218,46,214,72,173,219,4,100,135,239,157,47,238,143,212,
191,1,251,50,157,43,126,62,95,76,1,216,116,238,16,152,15,88,233,6,187,244,46,80,79,231,139,255,187,249,126,225,124,209,96,157,222,107,210,207,191,69,166,239,23,206,23,109,23,107,212,214,249,158,209,93,
101,157,55,186,43,153,6,19,104,91,64,128,222,118,125,180,142,64,151,2,83,80,150,102,2,223,78,23,80,223,94,236,78,63,118,166,127,191,253,223,233,199,234,255,233,178,83,157,53,122,186,120,61,53,57,93,24,
56,75,230,211,35,150,207,210,221,125,175,204,178,236,172,144,1,154,251,237,183,223,222,78,99,244,240,189,243,197,161,115,197,178,133,119,190,88,214,219,222,118,23,152,46,96,77,107,59,95,236,110,184,239,
154,191,60,95,164,255,251,149,39,215,236,171,106,253,57,4,166,137,56,211,111,16,231,139,57,116,243,219,76,238,255,47,45,245,246,55,200,187,223,34,211,255,118,190,200,219,89,98,89,129,119,215,46,222,125,
191,112,237,98,89,255,141,251,219,243,197,187,235,23,83,88,238,124,177,124,29,236,177,76,192,247,140,50,175,218,75,251,158,81,91,212,246,8,16,184,74,64,128,110,108,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,36,32,64,55,12,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,231,2,238,64,55,18,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,128,0,221,24,32,64,32,39,240,226,197,139,91,255,251,
191,255,123,235,198,141,27,183,166,101,15,14,14,14,115,235,248,188,127,129,159,126,250,233,108,234,197,244,239,31,127,252,241,236,191,254,235,191,206,142,142,142,222,254,255,252,17,184,74,192,249,34,230,
216,120,119,190,248,225,135,31,94,77,2,247,238,221,123,251,111,127,4,174,19,248,229,249,226,195,15,63,188,53,253,67,109,108,1,231,139,177,235,59,87,239,166,243,197,180,237,119,191,73,156,47,230,146,110,
103,187,126,139,180,83,139,222,90,226,124,209,91,197,246,111,239,47,207,23,126,139,236,111,26,105,11,174,97,68,170,246,249,53,206,169,199,174,93,196,170,187,222,18,216,71,192,29,232,251,232,89,151,192,
64,2,211,151,198,244,5,226,118,234,210,253,116,81,234,191,211,191,15,55,255,184,152,61,80,157,43,116,229,52,141,143,87,111,222,188,249,159,180,173,211,147,147,147,211,10,219,180,137,206,4,222,59,95,220,
78,147,106,254,111,250,17,114,223,249,162,179,34,206,223,220,87,105,23,47,211,249,226,204,249,98,126,236,150,247,112,201,249,98,250,174,241,238,59,70,203,77,215,182,229,4,222,157,47,222,126,191,72,255,
77,57,189,123,247,238,203,229,118,111,79,45,9,124,251,237,183,183,211,127,59,238,111,190,95,76,231,139,233,183,200,116,206,240,155,164,165,66,173,215,150,183,231,139,116,158,248,103,26,39,47,211,36,239,
83,147,124,215,43,198,218,123,158,190,99,164,201,222,247,211,120,152,206,27,191,119,190,88,187,34,205,237,255,153,223,34,205,213,100,181,6,253,226,55,201,127,79,231,13,223,47,86,43,71,107,59,190,112,237,
34,141,141,103,126,139,180,86,34,237,33,176,158,128,0,125,61,123,123,38,176,186,192,119,223,125,119,63,53,98,10,204,255,224,139,227,234,229,232,185,1,207,166,139,88,190,100,246,92,194,124,219,157,47,242,
70,150,216,74,224,237,249,34,77,216,122,234,238,144,173,188,186,92,104,115,129,234,211,205,247,139,119,1,88,151,125,209,232,213,4,206,210,248,121,150,130,145,191,165,11,88,79,87,107,133,29,207,46,240,
46,0,155,206,23,155,139,217,211,57,195,31,129,18,129,105,130,239,20,170,255,237,248,248,248,89,201,138,150,237,75,224,23,147,254,167,107,24,206,23,125,149,176,133,214,250,45,210,66,21,22,106,131,107,24,
11,65,143,187,155,233,124,241,183,116,227,208,147,113,187,168,103,4,8,228,4,4,232,57,33,159,19,24,76,224,249,243,231,135,191,249,205,111,222,191,168,61,88,15,117,103,101,129,233,226,213,95,211,24,123,
226,110,144,149,43,81,97,247,239,133,96,127,116,129,170,2,168,77,252,82,224,89,186,219,244,175,194,177,49,6,198,187,16,44,245,230,243,244,207,97,250,199,221,162,99,148,182,137,94,164,112,236,105,58,95,
252,197,147,111,154,40,199,222,141,120,23,130,165,187,204,167,208,252,83,231,139,189,73,109,224,61,129,116,190,120,242,239,127,255,251,207,38,234,141,51,44,166,16,108,115,190,248,100,243,29,99,156,206,
233,201,154,2,167,211,181,11,225,216,154,37,168,191,239,205,119,140,207,222,155,200,91,127,39,182,24,81,192,181,139,136,85,215,103,2,73,64,128,110,24,16,8,34,48,61,14,49,61,226,238,143,46,82,5,41,120,
3,221,116,241,170,129,34,236,216,132,233,71,103,10,42,62,119,190,216,17,208,106,197,2,211,249,226,206,157,59,143,138,87,180,194,234,2,239,93,164,250,147,16,108,245,114,68,104,192,203,244,223,167,63,155,
120,211,111,169,167,32,44,157,243,31,167,30,184,115,180,223,50,246,210,242,211,215,175,95,63,20,164,247,82,174,95,183,211,249,162,223,218,245,214,114,191,69,122,171,216,175,219,59,221,44,244,219,223,254,
246,79,174,97,244,95,203,198,123,48,189,162,238,145,223,34,141,87,73,243,8,84,20,16,160,87,196,180,41,2,45,10,8,194,90,172,74,172,54,249,49,218,79,189,157,47,250,169,213,160,45,245,99,180,163,194,190,
119,199,249,20,132,29,118,212,116,77,29,67,96,122,226,205,35,119,164,247,83,76,65,88,63,181,26,173,165,211,19,44,210,29,233,95,10,210,251,169,236,123,147,255,63,235,167,213,90,58,130,128,107,23,253,85,
209,53,140,254,106,54,72,139,77,234,29,164,144,186,65,32,39,32,64,207,9,249,156,64,167,2,190,68,118,90,184,129,155,157,102,105,62,52,75,179,205,2,79,231,139,116,135,206,39,233,209,136,239,30,189,220,102,
67,181,42,138,128,31,163,141,87,90,16,214,120,129,98,53,239,89,250,239,215,35,193,88,187,69,159,130,176,205,247,139,233,209,203,254,8,172,38,48,5,99,105,44,126,233,53,83,171,149,32,187,99,215,48,178,68,
22,88,70,192,164,222,101,156,247,218,139,167,96,237,197,103,229,122,2,211,181,139,233,90,231,203,122,155,180,37,2,4,90,18,16,160,183,84,13,109,33,80,65,64,16,86,1,209,38,230,20,16,140,205,169,187,195,
182,5,97,59,160,89,101,41,1,63,70,151,146,222,114,63,155,243,197,52,209,230,254,150,171,88,140,192,34,2,94,27,179,8,115,209,78,4,97,69,92,22,94,80,192,29,166,11,98,111,185,43,231,139,45,161,44,182,180,
128,107,23,75,139,111,177,63,79,193,218,2,201,34,107,8,152,212,187,134,186,125,18,88,64,64,128,190,0,178,93,16,88,74,96,243,69,242,171,180,63,119,120,44,133,110,63,187,10,156,30,31,31,127,188,235,202,
214,219,95,96,115,161,234,241,230,29,97,251,111,208,22,8,204,36,144,198,232,151,233,49,205,95,204,180,121,155,221,82,32,133,231,159,165,208,97,10,207,111,109,185,138,197,8,44,45,112,150,206,23,15,60,214,
125,105,246,95,239,111,51,217,230,107,231,139,245,107,161,5,87,10,188,76,79,175,120,224,233,21,235,143,144,205,83,42,166,243,197,225,250,173,209,2,2,151,10,60,75,215,46,30,176,89,95,192,53,207,245,107,
160,5,215,11,108,94,49,245,132,19,1,2,227,8,8,208,199,169,165,158,4,23,240,195,51,248,0,232,179,251,46,92,173,84,55,63,60,87,130,183,219,125,4,76,186,217,71,111,143,117,77,182,217,3,207,170,171,8,184,
112,181,10,251,207,59,53,217,102,93,127,123,47,18,48,233,166,136,171,254,194,38,219,212,55,181,197,217,4,94,222,184,113,227,99,175,128,152,205,55,187,97,215,60,179,68,22,104,68,192,13,0,141,20,66,51,8,
84,18,16,160,87,130,180,25,2,107,10,248,225,185,166,190,125,239,41,224,194,213,158,128,165,171,251,225,89,42,102,249,134,4,76,186,89,184,24,38,219,44,12,110,119,213,4,60,162,185,26,229,214,27,122,239,
17,204,159,109,189,146,5,9,52,32,96,210,205,58,69,48,217,102,29,119,123,221,75,96,122,55,250,199,222,117,188,151,225,78,43,187,230,185,19,155,149,214,21,112,3,192,186,254,246,78,160,154,128,0,189,26,165,
13,17,88,71,192,15,207,117,220,237,181,174,128,11,87,117,61,175,218,218,223,255,254,247,233,245,14,211,107,30,60,130,121,25,114,123,169,47,224,194,85,125,211,75,183,104,178,205,66,208,118,51,167,128,187,
197,230,212,125,111,219,38,219,44,4,109,55,179,9,152,116,51,27,237,175,54,108,178,205,114,214,246,52,155,192,131,244,72,247,103,179,109,221,134,47,8,184,230,105,64,116,44,224,6,128,142,139,167,233,4,222,
9,8,208,141,5,2,157,10,120,164,106,167,133,211,236,43,5,92,184,154,119,112,164,31,158,95,108,222,95,60,239,142,108,157,192,2,2,38,221,204,139,156,194,243,79,15,14,14,30,167,189,152,108,51,47,181,173,207,
47,240,42,221,45,246,192,221,98,243,65,155,108,51,159,173,45,47,46,112,154,30,209,252,192,35,154,231,115,55,217,102,62,91,91,94,86,192,35,154,231,247,54,217,102,126,99,123,88,68,192,83,55,23,97,182,19,
2,243,9,8,208,231,179,181,101,2,179,9,248,225,57,27,173,13,175,47,240,44,205,230,126,176,126,51,198,106,193,63,254,241,143,199,233,71,190,71,170,142,85,214,240,189,73,161,216,195,20,138,61,13,15,81,25,
96,115,151,199,20,158,251,35,48,138,128,39,87,204,84,201,77,120,254,77,218,188,201,54,51,25,219,236,226,2,175,210,111,145,143,22,223,107,128,29,110,174,97,76,231,139,219,1,186,171,139,1,4,210,228,244,
167,119,238,220,121,24,160,171,171,116,49,61,61,239,235,180,227,233,9,122,254,8,116,47,144,174,199,125,124,114,114,114,218,125,71,116,128,64,64,1,1,122,192,162,235,114,255,2,194,176,254,107,168,7,87,11,
184,179,180,238,232,16,134,213,245,180,181,182,4,252,16,173,91,15,97,88,93,79,91,107,74,224,85,186,179,52,221,88,122,116,214,84,171,58,110,140,48,172,227,226,105,122,78,192,123,75,115,66,133,159,187,1,
160,16,204,226,221,8,152,208,59,79,169,60,61,111,30,87,91,93,85,192,132,222,85,249,237,156,192,238,2,2,244,221,237,172,73,96,21,1,97,216,42,236,118,186,188,128,247,138,85,48,79,231,139,251,105,102,252,
52,115,219,157,97,21,60,109,162,73,1,63,68,43,149,229,249,243,231,135,55,111,222,124,225,124,81,9,212,102,90,20,16,138,85,170,138,48,172,18,164,205,52,43,224,213,82,117,75,227,6,128,186,158,182,214,150,
128,9,189,117,235,225,154,103,93,79,91,107,74,192,83,110,154,42,135,198,16,216,78,64,128,190,157,147,165,8,52,33,32,12,107,162,12,26,177,140,128,80,108,79,103,97,216,158,128,86,239,73,192,15,209,61,171,
181,9,195,166,201,54,247,247,220,148,213,9,52,45,224,113,171,117,202,35,12,171,227,104,43,205,11,152,208,91,161,68,194,176,10,136,54,209,186,192,217,235,215,175,143,238,221,187,247,170,245,134,182,222,
62,79,195,106,189,66,218,87,65,192,132,222,10,136,54,65,96,73,1,1,250,146,218,246,69,96,15,1,95,36,247,192,179,106,175,2,103,233,113,171,31,121,220,106,121,249,60,86,181,220,204,26,221,11,248,33,186,71,
9,189,99,112,15,60,171,118,39,224,113,171,251,149,76,24,182,159,159,181,251,18,72,231,139,163,187,119,239,190,236,171,213,237,180,214,13,0,237,212,66,75,102,23,48,161,119,79,226,205,13,0,223,164,205,28,
238,185,41,171,19,104,90,192,83,110,154,46,143,198,17,248,149,128,0,221,160,32,208,129,128,48,172,131,34,105,226,92,2,66,177,66,89,143,85,45,4,179,248,48,2,126,136,238,86,74,97,216,110,110,214,234,91,
192,227,86,119,171,159,48,108,55,55,107,117,45,224,206,210,29,203,231,105,88,59,194,89,173,103,1,215,46,118,172,158,167,97,237,8,103,181,110,5,76,232,237,182,116,26,30,80,64,128,30,176,232,186,220,159,
128,59,195,250,171,153,22,215,19,240,184,213,50,203,116,113,251,139,100,246,121,217,90,150,38,48,140,128,199,173,22,148,50,125,191,248,36,45,62,61,186,221,31,129,104,2,66,177,194,138,111,46,110,127,159,
86,187,85,184,170,197,9,244,46,240,242,248,248,248,168,247,78,44,217,126,55,0,44,169,109,95,45,9,164,9,122,143,78,78,78,158,180,212,166,30,218,226,213,48,61,84,73,27,107,11,120,202,77,109,81,219,35,48,
143,128,0,125,30,87,91,37,80,77,192,197,237,106,148,54,212,177,64,122,167,216,71,222,41,150,47,160,59,61,242,70,150,24,94,224,44,93,228,254,221,240,189,172,208,65,23,183,43,32,218,68,215,2,38,232,149,
149,207,4,189,50,47,75,143,37,224,78,177,178,122,122,186,77,153,151,165,135,18,48,65,175,176,156,155,167,219,76,143,110,247,71,32,154,128,167,86,68,171,184,254,118,41,32,64,239,178,108,26,29,73,32,5,232,
211,23,201,251,145,250,172,175,4,46,17,120,150,66,177,7,100,174,23,48,115,219,8,33,240,193,7,46,114,111,55,10,92,220,222,206,201,82,99,11,152,160,183,93,125,77,208,219,206,201,82,67,11,152,160,183,101,
121,55,19,244,94,164,197,15,183,92,197,98,4,134,18,48,65,175,172,156,174,121,150,121,89,122,56,1,79,208,27,174,164,58,52,154,128,0,125,180,138,234,207,80,2,238,62,31,170,156,58,179,167,128,199,27,93,15,
232,226,246,158,3,204,234,35,9,184,200,157,169,166,139,219,35,13,119,125,217,83,192,4,189,45,0,211,4,189,175,210,99,105,63,221,98,81,139,16,24,86,192,4,189,237,74,235,105,21,219,57,89,106,108,1,19,244,
182,171,175,107,158,219,57,89,106,104,129,87,233,102,161,143,134,238,161,206,17,232,92,64,128,222,121,1,53,127,92,1,143,86,29,183,182,122,182,179,128,247,15,94,67,231,226,246,206,227,202,138,3,10,164,
160,231,203,244,254,193,47,6,236,90,149,46,185,184,93,133,209,70,6,17,48,65,239,250,66,122,180,234,32,3,93,55,106,8,152,160,151,81,220,92,195,248,62,45,118,171,6,184,109,16,232,88,192,4,189,45,138,231,
238,243,45,144,44,50,188,128,9,122,195,151,88,7,59,23,16,160,119,94,64,205,31,87,192,163,85,199,173,173,158,237,37,224,241,70,151,240,185,184,189,215,152,178,242,152,2,222,63,120,69,93,61,173,98,204,1,
175,87,123,9,152,160,119,13,159,139,219,123,141,45,43,15,38,96,130,222,245,5,245,58,169,193,6,188,238,236,37,96,130,222,245,124,238,62,223,107,120,89,121,44,1,19,244,198,170,167,222,12,38,32,64,31,172,
160,186,51,134,128,153,219,99,212,81,47,102,17,240,120,163,75,88,93,220,158,101,172,217,104,231,2,222,63,120,121,1,93,220,238,124,96,107,254,92,2,38,232,93,254,253,226,147,244,255,254,122,46,116,219,37,
208,161,128,9,122,87,20,205,4,189,14,71,179,38,207,45,112,154,30,205,252,241,220,59,233,113,251,158,184,217,99,213,180,121,78,1,119,161,207,169,107,219,4,246,19,16,160,239,231,103,109,2,179,8,120,180,
234,44,172,54,58,136,128,47,150,23,11,105,230,246,32,3,91,55,102,17,240,254,193,139,172,46,110,207,50,204,108,116,12,1,19,244,46,169,163,9,122,99,12,110,189,168,43,96,130,222,229,158,94,39,85,119,156,
217,218,48,2,38,232,93,82,74,79,220,28,102,124,235,72,61,1,119,161,215,179,180,37,2,85,5,4,232,85,57,109,140,64,29,129,116,177,106,122,111,216,97,157,173,217,10,129,225,4,60,106,245,189,146,166,243,197,
116,103,216,116,135,152,63,2,4,126,33,224,34,247,69,16,19,244,28,34,4,174,22,48,225,230,162,205,183,223,126,123,251,224,224,224,133,49,67,128,192,175,4,92,228,254,5,137,39,232,57,74,8,92,46,224,183,200,
229,46,38,232,57,98,8,252,90,192,205,66,70,5,129,54,5,4,232,109,214,69,171,2,11,184,155,52,112,241,117,125,107,1,23,185,207,169,92,172,218,122,200,88,48,174,128,139,220,239,213,222,4,189,184,7,130,158,
231,5,92,228,190,104,100,194,77,126,204,88,34,174,128,139,220,191,58,95,124,150,206,161,143,227,142,8,61,39,112,165,192,217,141,27,55,62,58,58,58,58,99,116,46,96,130,158,145,64,224,74,1,55,11,25,28,104,
193,188,24,0,0,32,0,73,68,65,84,4,26,20,16,160,55,88,20,77,138,45,224,110,210,216,245,215,251,237,4,126,250,233,167,71,39,39,39,79,182,91,122,220,165,60,250,108,220,218,234,89,61,1,23,185,207,45,77,208,
171,55,166,108,105,88,1,19,110,222,43,173,9,55,195,142,115,29,171,35,240,44,189,219,248,65,157,77,245,191,21,119,147,246,95,67,61,152,79,192,111,145,139,182,38,232,205,55,214,108,185,127,1,55,11,245,95,
67,61,24,79,64,128,62,94,77,245,168,99,1,119,147,118,92,60,77,95,90,192,69,238,243,64,236,155,244,175,251,75,227,219,31,129,158,4,220,85,122,94,45,239,38,237,105,212,106,235,90,2,46,114,159,203,155,112,
179,214,8,180,223,158,4,92,228,62,175,150,187,73,123,26,181,218,186,146,128,9,55,239,193,155,160,183,210,40,180,219,46,4,220,44,212,69,153,52,50,152,128,0,61,88,193,117,183,109,1,23,171,218,174,143,214,
181,37,16,253,162,213,102,194,205,191,218,170,138,214,16,104,82,192,132,155,243,64,236,251,244,175,195,38,43,164,81,4,26,17,48,225,230,188,16,238,14,107,100,64,106,70,211,2,38,220,252,124,190,240,248,
246,166,71,170,198,181,32,144,30,227,254,59,143,113,55,225,166,133,177,168,13,205,11,152,112,211,124,137,52,48,154,128,0,61,90,197,245,183,105,1,23,171,154,46,143,198,53,38,16,125,102,166,9,55,141,13,
72,205,105,90,32,250,132,27,119,135,53,61,60,53,174,45,1,19,110,82,61,60,225,166,173,65,169,53,109,10,152,112,115,94,23,175,160,107,115,124,106,85,91,2,233,218,197,199,233,21,116,167,109,181,106,249,214,
120,5,221,242,230,246,216,157,192,89,154,112,243,145,9,55,221,213,77,131,7,22,16,160,15,92,92,93,235,79,192,197,170,254,106,166,197,171,10,132,158,153,233,113,204,171,142,61,59,239,76,32,250,132,27,23,
171,58,27,176,154,187,170,64,244,9,55,158,112,179,234,240,179,243,190,4,76,184,57,15,208,61,225,166,175,113,171,181,43,8,164,223,34,95,166,0,253,139,21,118,221,212,46,77,184,105,170,28,26,211,168,128,
9,55,141,22,70,179,194,10,8,208,195,150,94,199,91,19,112,177,170,181,138,104,79,7,2,161,47,90,185,88,213,193,8,213,196,150,4,66,79,184,113,177,170,165,161,168,45,173,11,68,159,112,227,9,55,173,143,80,
237,107,73,32,250,132,27,79,184,105,105,52,106,75,227,2,47,143,143,143,143,26,111,227,236,205,115,13,99,118,98,59,24,64,192,132,155,1,138,168,11,67,9,8,208,135,42,167,206,244,44,224,199,103,207,213,211,
246,181,4,34,191,75,44,253,248,252,105,45,119,251,37,208,161,128,9,55,222,127,222,225,176,213,228,53,4,162,95,180,242,196,138,53,70,157,125,246,42,16,253,46,177,116,13,227,211,131,131,131,175,122,173,
159,118,19,88,80,32,244,111,145,201,249,249,243,231,135,55,111,222,156,158,88,225,143,0,129,235,5,66,79,254,55,56,8,180,38,32,64,111,173,34,218,19,86,192,143,207,176,165,215,241,61,4,222,188,121,115,116,
247,238,221,151,123,108,162,203,85,77,184,233,178,108,26,189,178,64,186,235,35,236,247,94,119,123,172,60,248,236,190,55,129,208,23,173,188,34,166,183,225,170,189,107,10,68,127,98,133,9,55,107,142,62,251,
238,77,32,242,228,255,169,86,233,124,113,255,195,15,63,252,166,183,186,105,47,129,21,4,194,79,184,89,193,220,46,9,92,41,16,246,66,162,49,65,160,53,1,63,62,91,171,136,246,244,32,16,245,162,149,199,171,
246,48,58,181,177,53,129,168,143,89,117,183,71,107,35,81,123,58,16,8,125,209,42,125,199,152,46,110,223,239,160,78,154,72,96,117,129,20,6,61,185,115,231,206,163,213,27,178,82,3,188,34,102,37,120,187,237,
82,32,250,19,43,92,243,236,114,216,106,244,74,2,145,39,255,175,68,110,183,4,4,232,198,0,129,214,5,252,248,108,189,66,218,215,162,64,212,199,172,250,241,217,226,104,212,166,214,5,162,94,180,114,183,71,
235,35,83,251,26,20,136,30,160,79,143,87,61,108,176,46,154,68,160,69,129,208,79,172,240,132,155,22,135,164,54,181,42,16,117,242,255,187,122,120,194,77,171,35,83,187,90,20,136,58,249,191,197,90,104,19,
1,119,160,27,3,4,26,17,112,183,71,35,133,208,140,174,4,210,93,31,79,211,93,31,15,187,106,116,133,198,166,64,236,139,212,247,207,43,108,202,38,8,132,17,136,122,209,202,43,98,194,12,113,29,173,40,16,249,
49,171,233,55,201,79,21,41,109,138,192,232,2,47,211,93,98,71,163,119,242,170,254,9,208,163,86,94,191,119,17,136,58,249,95,128,190,203,104,177,78,116,129,168,147,255,163,215,93,255,219,20,16,160,183,89,
23,173,10,40,144,126,124,190,72,221,190,29,176,235,186,76,96,31,129,144,119,125,152,189,189,207,144,177,110,84,1,1,122,212,202,235,55,129,114,129,168,119,125,188,120,241,226,214,143,63,254,248,175,114,
49,107,16,8,43,240,42,5,232,31,69,237,125,186,134,49,157,47,110,69,237,191,126,19,40,17,136,30,160,123,234,102,201,104,177,108,116,1,1,122,244,17,160,255,45,9,8,208,91,170,134,182,132,22,48,123,59,116,
249,117,126,119,1,1,250,238,118,214,36,16,74,32,234,69,43,175,124,8,53,204,117,182,146,192,155,55,111,142,238,222,189,251,178,210,230,186,217,204,243,231,207,15,111,222,188,57,61,194,221,31,1,2,219,9,
68,127,229,131,39,86,108,55,78,44,69,224,131,168,79,207,123,87,122,79,221,116,16,16,216,94,32,253,22,121,152,126,139,60,221,126,13,75,18,32,48,151,128,0,125,46,89,219,37,80,40,32,64,47,4,179,56,129,115,
129,211,116,215,199,199,209,48,204,222,142,86,113,253,173,33,16,56,64,247,202,135,26,3,200,54,66,9,68,13,208,211,43,31,110,31,28,28,76,79,197,242,71,128,192,118,2,97,3,116,79,172,216,110,128,88,138,192,
123,2,33,39,255,191,235,191,167,110,58,22,8,108,47,16,245,233,121,219,11,89,146,192,114,2,2,244,229,172,237,137,192,181,2,30,127,102,128,16,216,73,64,128,190,19,155,149,8,196,19,72,119,125,60,185,115,
231,206,163,104,61,79,119,160,11,208,163,21,93,127,247,22,136,250,216,68,1,250,222,67,199,6,2,10,164,201,188,33,175,171,9,208,3,14,118,93,222,75,192,29,232,94,91,185,215,0,178,114,40,1,119,160,135,42,
183,206,54,46,16,242,139,126,227,53,209,188,160,2,102,99,6,45,188,110,239,43,16,50,64,247,14,244,125,135,141,245,35,10,184,3,61,98,213,245,153,192,110,2,81,239,64,23,136,237,54,94,172,21,90,32,250,59,
208,61,194,61,244,240,215,249,18,1,1,250,223,191,73,94,247,75,204,44,75,32,176,192,131,52,65,239,89,224,254,235,58,129,102,4,4,232,205,148,66,67,162,11,8,208,163,143,0,253,223,81,32,228,99,208,82,128,
254,56,133,129,159,237,104,102,53,2,33,5,162,62,6,45,221,81,250,105,122,36,243,87,33,139,174,211,4,118,20,120,253,250,245,71,247,238,221,123,181,227,234,221,174,38,64,239,182,116,26,190,158,64,244,0,253,
95,137,254,214,122,252,246,76,160,31,129,168,79,195,122,87,33,239,64,239,103,172,106,105,19,2,2,244,38,202,160,17,4,62,248,64,128,110,20,16,104,68,192,151,201,70,10,161,25,93,9,68,157,197,45,64,239,106,
152,106,108,35,2,81,31,131,150,190,95,124,146,74,240,117,35,101,208,12,2,93,8,68,13,208,167,226,164,115,134,59,74,187,24,165,26,217,136,192,203,116,135,216,81,35,109,89,188,25,94,67,183,56,185,29,118,
44,16,245,105,88,239,74,230,41,122,29,15,94,77,95,92,32,234,235,164,22,135,182,67,2,91,8,8,208,183,64,178,8,129,37,4,210,143,207,233,226,246,116,145,219,31,1,2,91,10,68,157,197,237,157,198,91,14,16,139,
17,184,40,16,114,22,183,0,221,97,64,160,92,32,234,59,141,39,41,129,88,249,120,177,70,104,129,144,175,147,122,87,113,79,209,11,61,246,117,190,80,32,234,100,222,119,76,110,2,40,28,48,22,15,45,16,121,50,
111,232,194,235,124,147,2,2,244,38,203,162,81,17,5,124,153,140,88,117,125,222,87,32,234,143,80,129,216,190,35,199,250,17,5,162,254,8,245,72,230,136,163,93,159,247,20,136,126,71,233,139,228,119,123,79,
67,171,19,8,33,16,245,105,88,239,5,232,222,105,28,98,164,235,100,37,129,144,147,121,223,217,185,9,160,210,40,178,153,16,2,81,175,93,132,40,174,78,118,39,32,64,239,174,100,26,60,170,128,64,108,212,202,
234,215,204,2,33,127,132,62,127,254,252,240,230,205,155,223,207,108,107,243,4,134,18,136,250,35,84,128,62,212,48,214,153,101,4,66,223,81,234,17,171,203,12,50,123,25,67,32,61,98,245,209,201,201,201,147,
49,122,83,222,11,55,1,148,155,89,35,174,64,212,223,34,239,77,184,241,90,169,184,195,95,207,203,4,94,165,167,97,125,84,182,138,165,9,16,152,75,64,128,62,151,172,237,18,40,20,72,179,49,239,167,25,236,211,
12,110,127,4,8,108,41,16,245,71,168,64,108,203,1,98,49,2,255,17,8,253,35,52,77,210,155,38,220,28,26,16,4,8,228,5,162,190,30,230,157,140,64,44,63,70,44,65,224,61,129,144,147,121,223,245,223,77,0,142,5,
2,219,11,68,126,61,204,164,228,26,198,246,99,197,146,225,5,66,79,230,13,95,125,0,205,9,8,208,155,43,137,6,69,21,240,101,50,106,229,245,123,15,129,179,244,35,244,119,123,172,223,245,170,2,177,174,203,167,
241,203,11,132,254,17,154,206,23,30,177,186,252,152,179,199,78,5,162,190,30,70,32,214,233,128,213,236,85,5,162,78,230,117,190,88,117,216,217,121,159,2,161,95,15,243,222,57,227,167,62,203,167,213,4,150,
19,136,62,153,119,57,105,123,34,176,157,128,0,125,59,39,75,17,88,68,64,32,182,8,179,157,140,35,240,44,5,232,15,198,233,78,89,79,60,98,181,204,203,210,177,5,210,35,86,191,76,143,88,253,34,170,130,119,14,
70,173,188,126,239,34,16,61,16,51,169,119,151,81,99,157,160,2,161,39,243,78,53,119,190,8,58,242,117,187,88,64,32,118,78,102,82,111,241,208,177,66,76,129,208,79,183,137,89,114,189,110,89,64,128,222,114,
117,180,45,156,128,71,38,134,43,185,14,239,33,16,61,16,251,246,219,111,63,61,56,56,248,106,15,66,171,18,136,36,16,250,71,168,11,220,145,134,186,190,238,41,16,250,117,15,239,236,76,234,221,115,20,89,61,
138,64,232,201,188,239,157,47,60,229,38,202,136,215,207,125,4,66,255,22,121,7,103,82,239,62,67,200,186,81,4,162,79,230,141,82,103,253,236,71,64,128,222,79,173,180,52,128,128,119,136,5,40,178,46,86,19,
72,1,250,199,233,142,210,211,106,27,236,108,67,2,177,206,10,166,185,107,10,156,221,184,113,227,163,163,163,163,179,53,27,177,246,190,211,119,140,127,165,54,220,90,187,29,246,79,160,113,1,129,88,42,144,
73,189,141,143,82,205,107,66,32,250,235,30,4,98,77,12,67,141,232,68,64,32,118,94,40,215,60,59,25,176,154,185,166,128,215,61,172,169,111,223,4,46,17,16,160,27,22,4,26,18,16,136,53,84,12,77,105,93,32,252,
35,19,55,63,64,191,79,255,62,108,189,88,218,71,96,101,1,129,216,121,32,246,85,154,120,244,233,202,181,176,123,2,77,11,8,196,92,224,110,122,128,106,92,83,2,2,177,243,114,164,59,74,239,167,199,83,79,119,
161,251,35,64,224,114,1,129,216,123,46,38,245,58,76,8,92,45,224,117,15,70,7,129,246,4,4,232,237,213,68,139,130,11,184,192,29,124,0,232,254,86,2,190,84,158,51,185,67,108,171,225,98,33,2,30,153,152,198,
128,215,62,56,16,8,100,5,206,82,32,118,116,239,222,189,87,217,37,7,95,192,164,222,193,11,172,123,53,4,4,98,23,3,49,147,122,107,140,42,219,24,82,32,250,171,231,126,89,84,215,60,135,28,230,58,85,73,32,250,
147,54,43,49,218,12,129,170,2,2,244,170,156,54,70,96,127,1,23,184,247,55,180,133,241,5,124,169,60,175,177,11,220,227,143,117,61,220,91,192,227,219,55,132,155,243,197,116,129,219,99,220,247,30,86,54,48,
168,128,167,85,188,87,88,23,184,7,29,229,186,85,69,64,32,118,145,209,164,222,42,195,202,70,6,21,240,180,138,139,133,245,24,247,65,7,186,110,213,16,48,57,175,134,162,109,16,168,44,32,64,175,12,106,115,
4,246,21,112,129,123,95,65,235,7,16,240,165,242,189,34,167,31,160,238,248,8,48,232,117,113,103,1,129,152,64,108,231,193,99,197,112,2,158,86,113,241,251,197,39,233,255,252,58,220,40,208,97,2,91,8,8,196,
46,34,153,212,187,197,160,177,72,84,1,191,69,46,169,188,107,24,81,15,7,253,190,78,192,228,60,227,131,64,155,2,2,244,54,235,162,85,193,5,220,241,17,124,0,232,254,181,2,190,84,94,228,241,212,10,7,12,129,
171,5,60,173,226,87,231,139,219,7,7,7,47,140,25,2,4,126,37,224,105,21,46,112,59,44,8,108,43,32,16,187,252,124,49,125,191,184,189,45,162,229,8,68,16,120,243,230,205,195,187,119,239,62,141,208,215,146,62,
122,106,69,137,150,101,131,8,120,149,84,144,66,235,102,127,2,2,244,254,106,166,197,1,4,204,224,14,80,100,93,220,85,192,5,110,23,184,119,29,59,214,139,39,224,2,247,229,231,139,233,142,210,233,206,82,127,
4,8,108,4,76,206,187,124,40,152,164,231,16,33,240,107,1,147,243,174,60,95,152,164,231,128,33,112,81,224,213,141,27,55,142,210,223,25,152,139,2,174,121,26,17,4,46,10,124,248,225,135,79,238,220,185,243,
136,11,1,2,237,9,8,208,219,171,137,22,17,120,43,224,46,116,3,129,192,165,23,172,190,60,57,57,249,130,205,69,1,23,184,141,8,2,46,112,111,59,6,158,63,127,126,120,243,230,205,233,213,15,254,8,16,56,23,112,
129,251,154,145,224,49,171,14,19,2,23,4,76,206,187,254,124,97,146,158,3,134,192,70,192,221,231,215,15,133,239,190,251,238,139,20,26,126,110,192,16,32,240,129,27,133,12,2,2,13,11,8,208,27,46,142,166,197,
22,240,46,244,216,245,215,251,75,5,92,224,190,254,130,149,199,38,58,112,8,252,71,192,5,238,107,70,131,73,122,14,21,2,255,17,112,129,251,250,209,144,2,116,239,66,119,192,16,56,23,56,75,231,139,143,211,
227,152,95,2,185,92,192,36,61,35,131,192,207,2,167,199,199,199,31,243,184,90,96,115,205,115,186,134,113,200,137,64,100,1,79,194,138,92,125,125,239,65,64,128,222,67,149,180,49,172,64,154,145,249,89,154,
145,249,56,44,128,142,19,120,79,192,5,238,235,135,67,58,95,220,79,231,139,111,12,26,2,4,92,224,206,141,1,143,77,204,9,249,60,144,128,11,220,91,20,59,133,232,38,233,109,225,100,145,177,5,92,224,222,174,
190,38,233,109,231,100,169,177,5,188,234,97,187,250,122,146,222,118,78,150,26,90,192,141,66,67,151,87,231,70,16,16,160,143,80,69,125,24,90,192,99,19,135,46,175,206,109,47,224,2,247,22,86,233,124,225,177,
137,91,56,89,100,108,1,239,15,219,174,190,46,112,111,231,100,169,177,5,92,224,222,174,190,233,2,183,119,27,111,71,101,169,113,5,60,94,117,203,218,154,164,183,37,148,197,70,22,240,36,172,130,234,186,230,
89,128,101,209,225,4,210,111,145,71,233,53,149,79,134,235,152,14,17,24,72,64,128,62,80,49,117,101,76,1,51,50,199,172,171,94,149,9,184,192,189,157,151,199,38,110,231,100,169,161,5,92,224,222,178,188,94,
21,179,37,148,197,70,22,112,129,187,160,186,38,233,21,96,89,116,56,1,119,159,151,149,212,187,141,203,188,44,61,150,64,122,114,222,145,87,61,108,95,83,175,138,217,222,202,146,195,9,184,251,124,184,146,
234,208,136,2,2,244,17,171,170,79,195,9,120,108,226,112,37,213,161,50,1,23,184,11,188,220,85,90,128,101,209,225,4,92,224,46,43,169,87,197,148,121,89,122,40,129,179,116,190,120,144,238,248,56,29,170,87,
51,118,198,36,189,25,113,109,186,117,1,23,184,11,43,228,221,198,133,96,22,31,70,192,147,176,118,43,165,107,158,187,185,89,171,123,129,7,199,199,199,207,186,239,133,14,16,24,92,64,128,62,120,129,117,111,
12,129,205,5,171,233,221,131,183,198,232,145,94,16,216,90,192,5,171,173,169,206,23,220,92,176,154,222,133,126,187,112,85,139,19,232,90,32,93,176,122,122,112,112,240,232,232,232,232,172,235,142,44,220,
120,119,149,46,12,110,119,77,8,120,92,226,110,101,112,151,216,110,110,214,234,90,192,100,155,29,203,151,38,233,221,79,223,205,166,223,36,254,8,68,17,120,121,227,198,141,143,253,22,41,47,183,39,99,149,
155,89,163,111,1,147,109,250,174,159,214,199,18,16,160,199,170,183,222,118,44,224,7,104,199,197,211,244,93,5,92,176,218,81,206,164,155,29,225,172,214,179,128,11,86,59,86,207,164,155,29,225,172,214,173,
128,11,86,251,149,206,147,110,246,243,179,118,95,2,233,81,204,15,211,163,152,159,246,213,234,118,90,235,117,116,237,212,66,75,102,23,56,123,253,250,245,209,189,123,247,94,205,190,167,65,119,144,206,23,
183,211,100,232,233,198,33,127,4,134,22,48,241,127,232,242,234,220,128,2,2,244,1,139,170,75,227,10,248,1,58,110,109,245,236,82,1,143,51,218,99,96,152,116,179,7,158,85,123,19,56,75,23,184,63,246,174,193,
221,203,230,174,143,221,237,172,217,157,192,105,186,59,236,129,187,195,246,171,91,186,19,125,186,171,244,254,126,91,177,54,129,182,5,76,182,169,83,31,147,110,234,56,218,74,211,2,211,211,175,30,122,20,
243,254,53,242,164,155,253,13,109,161,121,1,19,255,155,47,145,6,18,184,40,32,64,55,34,8,116,38,224,7,104,103,5,211,220,157,4,92,176,218,137,237,87,43,153,116,83,199,209,86,154,22,112,193,170,82,121,76,
186,169,4,105,51,45,11,120,45,76,165,234,120,114,69,37,72,155,105,86,192,221,97,117,75,99,210,77,93,79,91,107,75,192,107,97,234,214,195,53,207,186,158,182,214,148,128,137,255,77,149,67,99,8,108,39,32,
64,223,206,201,82,4,154,18,240,3,180,169,114,104,76,101,1,225,121,93,80,63,64,235,122,218,90,91,2,46,88,213,173,135,187,62,234,122,218,90,83,2,46,88,85,46,199,230,117,49,223,87,222,172,205,17,104,65,192,
221,97,149,171,96,210,77,101,80,155,107,70,192,181,139,121,74,145,126,147,124,157,182,252,201,60,91,183,85,2,171,8,152,248,191,10,187,157,18,216,95,64,128,190,191,161,45,16,88,92,192,15,208,197,201,237,
112,57,1,23,172,102,176,54,233,102,6,84,155,92,93,192,5,171,121,74,96,210,205,60,174,182,186,186,128,215,194,204,80,2,79,174,152,1,213,38,215,22,48,217,102,166,10,152,116,51,19,172,205,174,41,224,181,
48,51,233,187,230,57,19,172,205,174,38,96,226,255,106,244,118,76,96,111,1,1,250,222,132,54,64,96,29,1,95,40,215,113,183,215,89,5,252,0,157,145,215,44,238,25,113,109,122,113,129,41,60,63,56,56,248,210,
123,140,231,161,79,33,250,227,244,35,255,179,121,182,110,171,4,22,21,152,194,176,71,119,239,222,125,186,232,94,3,237,76,136,30,168,216,227,119,245,85,250,111,223,195,147,147,147,211,241,187,186,78,15,
211,235,165,110,167,239,111,223,164,189,223,90,167,5,246,74,160,154,128,107,23,213,40,47,223,144,107,158,51,3,219,252,82,2,103,233,187,197,151,233,187,197,147,165,118,104,63,4,8,212,21,16,160,215,245,
180,53,2,139,11,8,197,22,39,183,195,25,4,132,97,51,160,94,178,73,161,216,50,206,246,50,171,128,48,108,86,222,255,108,60,133,98,159,165,115,243,227,133,118,103,55,4,230,16,16,134,205,161,122,201,54,55,
161,216,244,184,213,195,133,118,105,55,4,106,11,8,195,106,139,94,177,61,161,216,66,208,118,51,155,128,107,23,179,209,94,186,97,215,48,150,245,182,183,170,2,30,219,94,149,211,198,8,172,35,32,64,95,199,
221,94,9,84,21,72,23,185,191,72,95,226,63,175,186,81,27,35,176,140,128,217,152,203,56,255,188,23,239,56,94,24,220,238,106,10,248,1,90,83,115,139,109,185,83,108,11,36,139,180,42,112,250,250,245,235,135,
247,238,221,123,213,106,3,71,107,151,80,108,180,138,198,233,143,48,108,157,90,11,197,214,113,183,215,189,4,76,228,221,139,111,247,149,93,243,220,221,206,154,171,9,188,76,191,69,30,248,45,178,154,191,29,
19,168,38,32,64,175,70,105,67,4,214,21,240,248,196,117,253,237,125,39,1,97,216,78,108,251,175,36,20,219,223,208,22,22,23,240,3,116,113,242,243,29,10,197,86,130,183,219,157,5,132,97,59,211,85,89,81,40,
86,133,209,70,150,17,48,145,119,25,231,43,247,34,20,91,185,0,118,95,34,224,218,69,137,214,12,203,186,230,57,3,170,77,206,37,224,169,54,115,201,218,46,129,21,4,4,232,43,160,219,37,129,185,4,60,62,113,46,
89,219,157,65,64,24,54,3,106,201,38,133,98,37,90,150,93,89,224,217,141,27,55,30,122,223,249,186,85,240,202,152,117,253,237,125,43,1,97,216,86,76,243,47,36,20,155,223,216,30,246,22,16,134,237,77,88,103,
3,66,177,58,142,182,50,171,128,107,23,179,242,110,191,113,215,60,183,183,178,228,58,2,38,242,174,227,110,175,4,230,20,16,160,207,169,107,219,4,86,16,152,66,177,55,111,222,60,254,233,167,159,62,93,97,247,
118,73,32,39,48,93,220,254,243,111,126,243,155,39,194,176,28,213,50,159,123,207,241,50,206,246,178,147,128,48,108,39,182,249,86,218,156,47,254,148,246,112,56,223,94,108,153,192,78,2,167,233,251,197,151,
39,39,39,167,59,173,109,165,234,2,46,114,87,39,181,193,122,2,94,241,80,207,178,202,150,166,243,69,154,44,249,39,215,48,170,112,218,72,61,129,183,191,69,210,181,139,167,174,93,212,67,173,177,165,244,180,
155,175,156,47,106,72,218,70,69,129,151,233,90,252,159,239,222,189,251,180,226,54,109,138,0,129,6,4,4,232,13,20,65,19,8,204,33,224,71,232,28,170,182,185,135,192,116,151,199,116,177,234,145,119,0,237,161,
56,211,170,38,222,204,4,107,179,187,10,184,88,181,171,220,66,235,153,120,179,16,180,221,108,35,240,50,93,64,253,75,10,206,159,108,179,176,101,150,23,72,191,73,62,61,56,56,248,60,237,249,112,249,189,219,
35,129,11,2,167,233,226,246,163,116,113,251,37,151,54,5,54,19,111,190,74,173,187,221,102,11,181,42,136,192,89,186,139,244,233,191,255,253,239,63,187,118,209,110,197,93,243,108,183,54,193,90,230,218,69,
176,130,235,110,60,1,1,122,188,154,235,113,48,129,205,143,208,233,162,213,39,193,186,174,187,237,8,184,88,213,78,45,174,109,137,31,161,157,20,106,220,102,122,66,69,103,181,245,174,227,206,10,54,86,115,
93,172,234,172,158,158,96,209,89,193,198,106,238,105,234,206,159,143,143,143,159,141,213,173,113,123,147,94,27,51,93,187,120,156,254,57,28,183,151,122,214,168,128,107,23,141,22,230,170,102,185,134,209,
89,193,198,105,174,223,34,227,212,82,79,8,92,43,32,64,55,64,8,4,17,240,35,52,72,161,219,234,166,31,159,109,213,99,235,214,248,17,186,53,149,5,235,8,76,79,168,152,222,45,248,208,93,30,117,64,151,220,202,
243,231,207,15,127,251,219,223,126,238,49,138,75,170,135,222,151,139,85,157,151,223,19,44,58,47,96,95,205,119,190,232,171,94,191,106,173,137,55,157,23,176,175,230,187,118,209,87,189,46,59,95,220,79,79,
14,152,158,96,113,216,121,87,52,191,109,129,183,79,168,72,79,87,250,210,171,29,218,46,148,214,17,168,37,32,64,175,37,105,59,4,58,17,152,130,244,244,31,251,63,184,208,221,73,193,250,107,230,244,101,242,
217,143,63,254,56,189,251,199,227,17,251,171,223,133,22,167,139,86,247,211,15,131,233,124,241,89,231,93,209,252,54,5,94,77,143,94,78,255,60,115,190,104,179,64,37,173,154,38,222,164,243,255,244,29,227,
143,46,92,149,200,89,118,75,129,233,29,231,127,245,30,210,45,181,58,88,108,19,140,253,33,53,245,126,7,205,213,196,126,4,222,78,202,75,143,106,255,203,205,155,55,159,185,184,221,79,225,174,107,233,230,
102,128,63,57,95,140,81,207,134,122,241,54,8,75,215,46,254,226,183,72,67,85,217,179,41,174,121,238,9,104,245,171,4,166,215,70,253,213,181,11,3,132,64,60,1,1,122,188,154,235,49,129,159,5,54,23,174,126,
159,254,31,30,239,110,92,236,35,240,246,253,230,233,66,213,95,93,168,218,135,177,237,117,223,251,33,58,157,47,110,181,221,90,173,107,88,224,101,186,80,117,58,93,168,74,231,139,87,46,108,55,92,169,61,154,
182,57,95,252,62,93,96,184,159,54,227,61,166,123,88,6,94,245,109,8,150,198,208,223,92,168,26,123,20,188,55,249,102,250,77,50,157,51,252,17,40,21,120,119,190,248,235,15,63,252,240,204,211,108,74,249,250,
90,222,228,155,190,234,213,96,107,223,94,187,72,255,252,229,198,141,27,167,126,139,52,88,161,138,77,218,76,190,153,38,247,78,223,47,92,195,168,104,27,100,83,63,95,187,48,201,38,72,197,117,147,192,37,2,
2,116,195,130,0,129,183,2,211,157,166,233,95,183,211,221,166,255,157,46,84,30,110,190,96,210,33,240,75,129,233,7,231,171,233,159,52,78,254,233,162,118,204,1,50,61,178,57,221,5,248,137,243,69,204,250,23,
244,250,237,5,237,20,152,191,76,129,249,63,167,255,237,135,103,129,222,32,139,190,120,241,226,86,122,60,255,39,233,34,229,244,253,98,10,211,167,239,24,211,63,254,8,188,19,152,206,21,239,206,23,175,166,
9,121,233,191,49,47,93,212,142,57,64,166,139,221,211,185,34,253,183,99,10,212,157,47,98,14,131,235,122,253,171,223,34,38,228,197,29,36,206,23,113,107,191,101,207,223,158,47,166,223,34,233,187,197,255,
184,118,177,165,218,160,139,185,230,57,104,97,235,117,235,194,181,11,55,7,213,131,181,37,2,189,11,8,208,123,175,160,246,19,152,81,96,19,146,29,166,31,28,111,103,106,166,31,29,183,222,253,239,25,119,107,
211,141,8,164,31,152,103,41,32,157,222,29,56,125,145,252,32,221,209,241,202,29,29,141,20,167,193,102,76,33,89,26,35,211,5,111,231,139,6,235,51,119,147,222,63,95,76,255,219,197,236,185,197,251,223,254,
116,17,235,253,243,197,212,35,223,49,250,175,235,54,61,112,190,216,70,201,50,239,11,188,255,155,100,250,61,226,124,17,103,124,76,231,139,244,223,134,87,83,143,125,191,136,83,247,125,122,234,124,177,143,
94,191,235,250,110,209,111,237,214,108,185,107,158,107,234,175,183,111,231,139,245,236,237,153,64,143,2,2,244,30,171,166,205,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,
32,80,93,64,128,94,157,212,6,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,160,71,1,1,122,143,85,211,102,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,
128,0,1,2,4,8,16,168,46,32,64,175,78,106,131,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,208,163,128,0,189,199,170,105,51,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,4,8,84,23,16,160,87,39,181,65,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,232,81,64,128,222,99,213,180,153,0,1,2,4,8,16,32,64,128,0,1,2,4,
8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,170,11,8,208,171,147,218,32,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,244,40,32,64,239,177,106,218,76,128,0,1,2,4,8,16,
32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,213,5,4,232,213,73,109,144,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,122,20,16,160,247,88,53,109,38,64,
128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,234,2,2,244,234,164,54,72,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,61,10,8,208,123,
172,154,54,19,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,117,1,1,122,117,82,27,36,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,
30,5,4,232,61,86,77,155,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,160,186,128,0,189,58,169,13,18,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,
16,32,64,128,64,143,2,2,244,30,171,166,205,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,80,93,64,128,94,157,212,6,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,
64,128,0,1,2,4,8,16,32,64,160,71,1,1,122,143,85,211,102,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,168,46,32,64,175,78,106,131,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,208,163,128,0,189,199,170,105,51,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,84,23,16,160,87,39,181,65,2,4,8,16,32,64,128,0,1,2,
4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,232,81,64,128,222,99,213,180,153,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,170,11,8,208,171,147,218,32,1,2,4,8,16,
32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,244,40,32,64,239,177,106,218,76,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,213,5,4,232,213,73,109,
144,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,122,20,16,160,247,88,53,109,38,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,234,2,
2,244,234,164,54,72,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,61,10,8,208,123,172,154,54,19,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,
64,128,64,117,1,1,122,117,82,27,36,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,30,5,4,232,61,86,77,155,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,160,186,128,0,189,58,169,13,18,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,143,2,2,244,30,171,166,205,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,
1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,80,93,64,128,94,157,212,6,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,160,71,1,1,122,143,85,211,102,2,4,8,16,32,64,128,0,1,2,4,
8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,168,46,32,64,175,78,106,131,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,208,163,128,0,189,199,170,105,51,1,2,4,8,16,
32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,84,23,16,160,87,39,181,65,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,232,81,64,128,222,99,213,180,153,
0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,170,11,8,208,171,147,218,32,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,244,40,32,64,239,177,
106,218,76,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,213,5,4,232,213,73,109,144,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,122,20,
16,160,247,88,53,109,38,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,234,2,2,244,234,164,54,72,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,
128,0,1,2,61,10,8,208,123,172,154,54,19,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,117,1,1,122,117,82,27,36,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,129,30,87,178,50,103,0,0,27,138,73,68,65,84,5,4,232,61,86,77,155,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,160,186,128,0,189,58,169,13,18,
32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,143,2,2,244,30,171,166,205,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,80,93,64,128,
94,157,212,6,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,160,71,1,1,122,143,85,211,102,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,
168,46,32,64,175,78,106,131,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,208,163,128,0,189,199,170,105,51,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,
64,128,0,1,2,4,8,84,23,16,160,87,39,181,65,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,232,81,64,128,222,99,213,180,153,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,4,170,11,8,208,171,147,218,32,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,244,40,32,64,239,177,106,218,76,128,0,1,2,4,8,16,32,64,128,0,1,2,
4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,213,5,4,232,213,73,109,144,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,122,20,16,160,247,88,53,109,38,64,128,0,1,2,4,8,16,
32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,234,2,2,244,234,164,54,72,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,61,10,8,208,123,172,154,54,19,32,
64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,117,1,1,122,117,82,27,36,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,30,5,4,232,61,
86,77,155,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,160,186,128,0,189,58,169,13,18,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
64,143,2,2,244,30,171,166,205,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,80,93,64,128,94,157,212,6,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,160,71,1,1,122,143,85,211,102,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,168,46,32,64,175,78,106,131,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,
16,32,64,128,0,1,2,4,8,16,32,208,163,128,0,189,199,170,105,51,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,84,23,16,160,87,39,181,65,2,4,8,16,32,64,128,0,1,2,4,8,16,32,
64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,232,81,64,128,222,99,213,180,153,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,170,11,8,208,171,147,218,32,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,244,40,32,64,239,177,106,218,76,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,213,5,4,232,213,73,109,144,0,1,2,
4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,122,20,16,160,247,88,53,109,38,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,234,2,2,244,234,
164,54,72,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,61,10,8,208,123,172,154,54,19,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,
117,1,1,122,117,82,27,36,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,30,5,4,232,61,86,77,155,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,
8,16,32,64,160,186,128,0,189,58,169,13,18,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,143,2,2,244,30,171,166,205,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,
16,32,64,128,0,1,2,4,8,16,32,80,93,64,128,94,157,212,6,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,160,71,1,1,122,143,85,211,102,2,4,8,16,32,64,128,0,1,2,4,8,16,32,
64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,168,46,32,64,175,78,106,131,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,208,163,128,0,189,199,170,105,51,1,2,4,8,16,32,64,
128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,84,23,16,160,87,39,181,65,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,232,81,64,128,222,99,213,180,153,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,170,11,8,208,171,147,218,32,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,244,40,32,64,239,177,106,
218,76,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,213,5,4,232,213,73,109,144,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,122,20,16,
160,247,88,53,109,38,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,234,2,2,244,234,164,54,72,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,61,10,8,208,123,172,154,54,19,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,117,1,1,122,117,82,27,36,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,129,30,5,4,232,61,86,77,155,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,160,186,128,0,189,58,169,13,18,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,
8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,143,2,2,244,30,171,166,205,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,80,93,64,128,94,157,212,6,9,16,32,64,128,0,1,2,4,8,16,
32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,160,71,1,1,122,143,85,211,102,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,168,46,32,64,175,78,106,131,4,8,16,32,64,
128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,208,163,128,0,189,199,170,105,51,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,84,23,16,160,87,39,181,65,
2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,232,81,64,128,222,99,213,180,153,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,170,11,8,208,
171,147,218,32,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,244,40,32,64,239,177,106,218,76,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,213,5,4,232,213,73,109,144,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,122,20,16,160,247,88,53,109,38,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,
16,32,64,128,0,129,234,2,2,244,234,164,54,72,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,61,10,8,208,123,172,154,54,19,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,
32,64,128,0,1,2,4,8,16,32,64,128,64,117,1,1,122,117,82,27,36,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,30,5,4,232,61,86,77,155,9,16,32,64,128,0,1,2,4,8,16,32,64,
128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,160,186,128,0,189,58,169,13,18,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,143,2,2,244,30,171,166,205,4,8,16,248,255,
237,217,49,9,0,0,0,2,193,254,173,45,241,139,112,5,68,206,81,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,185,128,3,61,39,21,72,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,143,2,14,244,199,213,116,38,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,92,192,129,158,147,10,36,64,128,0,1,2,4,8,16,32,64,128,0,1,2,
4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,71,1,7,250,227,106,58,19,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,46,224,64,207,73,5,18,32,64,128,0,1,2,4,8,16,32,
64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,192,163,128,3,253,113,53,157,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,23,112,160,231,164,2,9,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,224,81,192,129,254,184,154,206,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,144,11,56,208,115,82,129,
4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,240,40,224,64,127,92,77,103,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,200,5,28,232,57,
169,64,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,120,20,112,160,63,174,166,51,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,228,2,14,
244,156,84,32,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,60,10,56,208,31,87,211,153,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,114,1,
7,122,78,42,144,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,30,5,28,232,143,171,233,76,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,185,
128,3,61,39,21,72,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,143,2,14,244,199,213,116,38,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,129,92,192,129,158,147,10,36,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,71,1,7,250,227,106,58,19,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,
4,8,16,32,64,128,64,46,224,64,207,73,5,18,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,192,163,128,3,253,113,53,157,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,
32,64,128,0,1,2,4,8,16,32,64,32,23,112,160,231,164,2,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,224,81,192,129,254,184,154,206,4,8,16,32,64,128,0,1,2,4,8,16,32,64,
128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,144,11,56,208,115,82,129,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,240,40,224,64,127,92,77,103,2,4,8,16,32,64,128,0,1,2,
4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,200,5,28,232,57,169,64,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,120,20,112,160,63,174,166,51,1,2,4,8,16,32,64,
128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,228,2,14,244,156,84,32,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,60,10,56,208,31,87,211,153,0,1,2,4,8,16,
32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,114,1,7,122,78,42,144,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,30,5,28,232,143,171,233,76,128,0,1,2,
4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,185,128,3,61,39,21,72,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,143,2,14,244,199,213,116,38,64,
128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,92,192,129,158,147,10,36,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,71,1,7,250,227,
106,58,19,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,46,224,64,207,73,5,18,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,192,163,
128,3,253,113,53,157,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,23,112,160,231,164,2,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,
64,224,81,192,129,254,184,154,206,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,144,11,56,208,115,82,129,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,240,40,224,64,127,92,77,103,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,200,5,28,232,57,169,64,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,
32,64,128,0,1,2,4,8,16,120,20,112,160,63,174,166,51,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,228,2,14,244,156,84,32,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,16,32,64,128,0,1,2,4,8,60,10,56,208,31,87,211,153,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,114,1,7,122,78,42,144,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,4,30,5,28,232,143,171,233,76,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,185,128,3,61,39,21,72,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,
64,128,0,1,2,4,8,16,32,64,128,0,1,2,143,2,14,244,199,213,116,38,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,92,192,129,158,147,10,36,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,71,1,7,250,227,106,58,19,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,46,224,64,207,73,5,18,32,64,128,0,1,2,4,8,
16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,192,163,128,3,253,113,53,157,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,23,112,160,231,164,2,9,16,32,
64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,224,81,192,129,254,184,154,206,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,144,11,56,208,115,
82,129,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,240,40,224,64,127,92,77,103,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,200,5,28,
232,57,169,64,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,120,20,112,160,63,174,166,51,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,228,
2,14,244,156,84,32,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,60,10,56,208,31,87,211,153,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,
114,1,7,122,78,42,144,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,30,5,28,232,143,171,233,76,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,
1,2,185,128,3,61,39,21,72,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,143,2,14,244,199,213,116,38,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,
64,128,0,129,92,192,129,158,147,10,36,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,71,1,7,250,227,106,58,19,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,64,46,224,64,207,73,5,18,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,192,163,128,3,253,113,53,157,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,
4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,23,112,160,231,164,2,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,224,81,192,129,254,184,154,206,4,8,16,32,64,128,0,1,2,4,8,16,
32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,144,11,56,208,115,82,129,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,240,40,224,64,127,92,77,103,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,200,5,28,232,57,169,64,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,120,20,112,160,63,174,166,51,1,2,4,8,16,
32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,228,2,14,244,156,84,32,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,60,10,56,208,31,87,211,153,0,1,2,4,
8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,114,1,7,122,78,42,144,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,30,5,28,232,143,171,233,76,128,0,
1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,185,128,3,61,39,21,72,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,143,2,14,244,199,213,116,38,
64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,92,192,129,158,147,10,36,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,71,1,7,250,
227,106,58,19,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,46,224,64,207,73,5,18,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,192,
163,128,3,253,113,53,157,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,23,112,160,231,164,2,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,
16,32,64,224,81,192,129,254,184,154,206,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,144,11,56,208,115,82,129,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,
64,128,0,1,2,4,8,16,32,240,40,224,64,127,92,77,103,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,200,5,28,232,57,169,64,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,
4,8,16,32,64,128,0,1,2,4,8,16,120,20,112,160,63,174,166,51,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,228,2,14,244,156,84,32,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,8,16,32,64,128,0,1,2,4,8,60,10,56,208,31,87,211,153,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,114,1,7,122,78,42,144,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,
128,0,1,2,4,8,16,32,64,128,0,1,2,4,30,5,28,232,143,171,233,76,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,185,128,3,61,39,21,72,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,
16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,143,2,14,244,199,213,116,38,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,92,192,129,158,147,10,36,64,128,0,1,2,4,8,16,32,
64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,129,71,1,7,250,227,106,58,19,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,64,46,224,64,207,73,5,18,32,64,128,0,
1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,192,163,128,3,253,113,53,157,9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,32,23,112,160,231,164,2,
9,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,224,81,192,129,254,184,154,206,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,144,11,56,
208,115,82,129,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,240,40,224,64,127,92,77,103,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,
200,5,28,232,57,169,64,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,120,20,112,160,63,174,166,51,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,
2,4,8,228,2,14,244,156,84,32,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,60,10,56,208,31,87,211,153,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,
0,1,2,4,114,1,7,122,78,42,144,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,30,5,28,232,143,171,233,76,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,
64,128,0,1,2,185,128,3,61,39,21,72,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,143,2,14,244,199,213,116,38,64,128,0,1,2,4,8,16,32,64,128,0,1,2,4,8,16,32,64,128,0,1,2,
4,8,16,32,64,128,0,129,92,96,204,25,43,174,108,76,49,49,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MainContentComponent::logo_png = (const char*) resource_MainContentComponent_logo_png;
const int MainContentComponent::logo_pngSize = 113759;


//[EndFile] You can add extra defines here...
//[/EndFile]

