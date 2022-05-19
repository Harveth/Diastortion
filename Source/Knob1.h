/*
  ==============================================================================

    Knob1.h
    Created: 19 May 2022 11:32:28pm
    Author:  Joe

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Knob1LookAndFeel.h"

using namespace juce;

//==============================================================================
/*
*/
class Knob1  : public Slider
{
public:
    Knob1();
    ~Knob1();

    /*void paint (juce::Graphics&) override;
    void resized() override;*/
    void mouseDown(const MouseEvent& event) override;
    void mouseUp(const MouseEvent& event) override;


private:
    Knob1LookAndFeel knob1LookAndFeel;
    Point<int> mousePosition;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Knob1)
};
