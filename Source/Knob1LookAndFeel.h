/*
  ==============================================================================

    Knob1LookAndFeel.h
    Created: 19 May 2022 11:32:50pm
    Author:  Joe

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
using namespace juce;

//==============================================================================
/*
*/
class Knob1LookAndFeel  : public LookAndFeel_V4
{
public:
    Knob1LookAndFeel();
    //~Knob1LookAndFeel() override;

    void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider& slider) override;
    void drawLabel(Graphics& g, Label& label);

private:
    Image knobRelease;
    //JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Knob1LookAndFeel)
};
