/*
  ==============================================================================

    HelpComponent.h
    Created: 8 Aug 2017 12:52:13pm
    Author:  frv

  ==============================================================================
*/

#ifndef HELPCOMPONENT_H_INCLUDED
#define HELPCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
//#include "/JUCE/modules/juce_gui_basics/mouse/juce_TooltipClient.h"

class HelpComponent : public TextEditor,
                      private Timer
{
    
    public:
        explicit HelpComponent () : TextEditor("Help") {
            if (Desktop::getInstance().getMainMouseSource().canHover())
                startTimer (123);
        }
        
        ~HelpComponent() {
            stopTimer();
        }
        
        void displayHelp(const String& text) {
            setText(text, dontSendNotification);
        }
        
    private:
        void timerCallback() override {
            Desktop& desktop = Desktop::getInstance();
            const MouseInputSource mouseSource(desktop.getMainMouseSource());
            
            Component * const comp = mouseSource.isMouse() ? mouseSource.getComponentUnderMouse() : nullptr;
            const String help(getHelpFor(comp));
            
            displayHelp(help);
        }
        
        static String getHelpFor(Component * c) {
            if (TooltipClient * const ttc = dynamic_cast<TooltipClient*> (c))
                if (! c->isCurrentlyBlockedByAnotherModalComponent())
                    return ttc->getTooltip();
                    
            return String();
        }
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HelpComponent)
};

#endif  // HELPCOMPONENT_H_INCLUDED
