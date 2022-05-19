/*
  ==============================================================================

    Knob1LookAndFeel.cpp
    Created: 19 May 2022 11:32:50pm
    Author:  Joe

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Knob1LookAndFeel.h"

//==============================================================================
Knob1LookAndFeel::Knob1LookAndFeel()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    knobRelease = ImageCache::getFromMemory(BinaryData::knobRelease_png, BinaryData::knobRelease_pngSize);
}

void Knob1LookAndFeel::drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
{
    if (knobRelease.isValid())
    {
        const double rotation = (slider.getValue()
            - slider.getMinimum())
            / (slider.getMaximum()
                - slider.getMinimum());

        const int frames = 77;
        const int frameId = (int)ceil(rotation * ((double)frames - 1.0));
        const float radius = jmin(width / 1.0f, height / 1.0f);
        const float centerX = x + width * 0.5f;
        const float centerY = y + height * 0.5f;
        const float rx = centerX - radius - 1.0f;
        const float ry = centerY - radius;

        int imgWidth = knobRelease.getWidth();
        int imgHeight = knobRelease.getHeight() / frames;
        g.drawImage(knobRelease, 0, 0, imgWidth, imgHeight, 0, frameId * imgHeight, imgWidth, imgHeight);
    }
    else
    {
        static const float textPpercent = 0.35f;
        Rectangle<float> text_bounds(1.0f + width * (1.0f - textPpercent) / 2.0f, 0.5f * height, width * textPpercent, 0.5f * height);

        g.setColour(Colours::white);

        g.drawFittedText(String("No Image"), text_bounds.getSmallestIntegerContainer(), Justification::horizontallyCentred | Justification::centred, 1);
    }
}

void Knob1LookAndFeel::drawLabel(Graphics& g, Label& label)
{
    /*g.setColour(Colour(uint8(255), 255, 255, 1.0f));
    g.fillRoundedRectangle(label.getLocalBounds().toFloat(), 3.0f);


    if (!label.isBeingEdited())
    {
        auto alpha = label.isEnabled() ? 1.0f : 0.5f;
        const Font font(getLabelFont(label));

        g.setColour(Colour(uint8(0), 0, 0, 1.0f));
        g.setFont(font);

        auto textArea = getLabelBorderSize(label).subtractedFrom(label.getLocalBounds());

        g.drawFittedText(label.getText(), textArea, label.getJustificationType(),
            jmax(1, (int)(textArea.getHeight() / font.getHeight())),
            label.getMinimumHorizontalScale());

        g.setColour(Colour(uint8(255), 255, 255, 0.1f));
    }
    else if (label.isEnabled())
    {
        g.setColour(label.findColour(Label::outlineColourId));
    }*/
}

