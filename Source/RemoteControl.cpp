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

#include "Communicator.h"

//[/Headers]

#include "RemoteControl.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
RemoteControl::RemoteControl ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (getInfoButton = new TextButton ("get info button"));
    getInfoButton->setTooltip (TRANS("This button will fetch and display the connected products version string, number of voices available and the number of tracks on the installed microSD card.\n"
    "\n"
    "This button is not available if there is no active serial port open or available."));
    getInfoButton->setButtonText (TRANS("Get Info"));
    getInfoButton->addListener (this);

    addAndMakeVisible (versionLabel = new Label ("version label",
                                                 String()));
    versionLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    versionLabel->setJustificationType (Justification::centredLeft);
    versionLabel->setEditable (false, false, false);
    versionLabel->setColour (Label::backgroundColourId, Colour (0xff797777));
    versionLabel->setColour (TextEditor::textColourId, Colours::black);
    versionLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (voicesLabel = new Label ("version label",
                                                String()));
    voicesLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    voicesLabel->setJustificationType (Justification::centredLeft);
    voicesLabel->setEditable (false, false, false);
    voicesLabel->setColour (Label::backgroundColourId, Colour (0xff797777));
    voicesLabel->setColour (TextEditor::textColourId, Colours::black);
    voicesLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (filesLabel = new Label ("version label",
                                               String()));
    filesLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    filesLabel->setJustificationType (Justification::centredLeft);
    filesLabel->setEditable (false, false, false);
    filesLabel->setColour (Label::backgroundColourId, Colour (0xff797777));
    filesLabel->setColour (TextEditor::textColourId, Colours::black);
    filesLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Version")));
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Number of Voices")));
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("Number of Tracks on microSD Card")));
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

	m_Com = nullptr;
	enableUI(false);

    //[/Constructor]
}

RemoteControl::~RemoteControl()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    getInfoButton = nullptr;
    versionLabel = nullptr;
    voicesLabel = nullptr;
    filesLabel = nullptr;
    label = nullptr;
    label2 = nullptr;
    label3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..

	if (m_Com != nullptr)
		m_Com->removeChangeListener(this);

    //[/Destructor]
}

//==============================================================================
void RemoteControl::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void RemoteControl::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    getInfoButton->setBounds (40, 32, 80, 24);
    versionLabel->setBounds (192, 32, 184, 24);
    voicesLabel->setBounds (512, 32, 56, 24);
    filesLabel->setBounds (512, 64, 56, 24);
    label->setBounds (133, 32, 63, 24);
    label2->setBounds (389, 32, 120, 24);
    label3->setBounds (280, 64, 231, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void RemoteControl::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == getInfoButton)
    {
        //[UserButtonCode_getInfoButton] -- add your button handler code here..

		if (m_Com != nullptr) {
			if (m_Com->isPortOpen())
				m_Com->getDeviceInfo();
		}

        //[/UserButtonCode_getInfoButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

// **************************************************************************
// setCommunicator
// **************************************************************************
void RemoteControl::setCommunicator(Communicator * com) {

	m_Com = (Communicator *)com;
	if (m_Com != nullptr)
		m_Com->addChangeListener(this);
}

// **************************************************************************
// enableUI
// **************************************************************************
void RemoteControl::enableUI(bool en) {

	if (en) {
		getInfoButton->setEnabled(true);
	}
	else {
		getInfoButton->setEnabled(false);
	}
}

// **************************************************************************
// changeListenerCallback
// **************************************************************************
void RemoteControl::changeListenerCallback(ChangeBroadcaster *) {

unsigned char responseMsg[256];
int msgLen;
int val;

	if (m_Com->isMsgReady()) {
		msgLen = m_Com->getMessage(responseMsg);
		if (msgLen > 0) {

			switch (responseMsg[0]) {
				case 0x81:
					versionLabel->setText(String((char *)&responseMsg[1]), dontSendNotification);
					m_Com->clearMsgReady();
					break;

				case 0x82:
					val = (int)responseMsg[1];
					voicesLabel->setText(String(val), dontSendNotification);
					val = (int)responseMsg[3];
					val = (val << 8) + (int)responseMsg[2];
					filesLabel->setText(String(val), dontSendNotification);
					m_Com->clearMsgReady();
					break;
			}
		}
	}
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="RemoteControl" componentName=""
                 parentClasses="public Component, public ChangeListener" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TEXTBUTTON name="get info button" id="3c4e746a88417843" memberName="getInfoButton"
              virtualName="" explicitFocusOrder="0" pos="40 32 80 24" tooltip="This button will fetch and display the connected products version string, number of voices available and the number of tracks on the installed microSD card.&#10;&#10;This button is not available if there is no active serial port open or available."
              buttonText="Get Info" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="version label" id="5cb47c8f6c47cf1" memberName="versionLabel"
         virtualName="" explicitFocusOrder="0" pos="192 32 184 24" bkgCol="ff797777"
         edTextCol="ff000000" edBkgCol="0" labelText="" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="version label" id="7cd695f0d5dc47e4" memberName="voicesLabel"
         virtualName="" explicitFocusOrder="0" pos="512 32 56 24" bkgCol="ff797777"
         edTextCol="ff000000" edBkgCol="0" labelText="" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="version label" id="298c824447f349eb" memberName="filesLabel"
         virtualName="" explicitFocusOrder="0" pos="512 64 56 24" bkgCol="ff797777"
         edTextCol="ff000000" edBkgCol="0" labelText="" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="f4b6b19603d822a3" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="133 32 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Version" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="1668074f0bca3a9d" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="389 32 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Number of Voices" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="6eeef82bdf130ffc" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="280 64 231 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Number of Tracks on microSD Card" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
