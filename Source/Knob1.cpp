/*
  ==============================================================================

    Knob1.cpp
    Created: 19 May 2022 11:32:28pm
    Author:  Joe

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Knob1.h"


//==============================================================================
Knob1::Knob1() : Slider()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    setLookAndFeel(&knob1LookAndFeel);
}

Knob1::~Knob1()
{
    setLookAndFeel(nullptr);
}

void Knob1::mouseDown(const MouseEvent& event)
{
    Slider::mouseDown(event);
    setMouseCursor(MouseCursor::NoCursor);
    mousePosition = Desktop::getMousePosition();
}

void Knob1::mouseUp(const MouseEvent& event)
{
    Slider::mouseUp(event);
    Desktop::setMousePosition(mousePosition);
    setMouseCursor(MouseCursor::NormalCursor);
}


