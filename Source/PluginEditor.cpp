/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "BinaryData.h"
#include <string>




std::string combined[1302];
unsigned short combinedCounter = 0;
juce::Image getNextFront(int num);

//==============================================================================
DiastortionAudioProcessorEditor::DiastortionAudioProcessorEditor (DiastortionAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (1200, 223);

    for (int i = 0; i <= 1301; i++) {
        if (i + 100 < 1000)
            combined[i] = "L:/projects/Pluginz/Diaa-stortion/Prototypes/renders/combined/combined.0" + std::to_string(i + 100) + ".png";
        else
            combined[i] = "L:/projects/Pluginz/Diaa-stortion/Prototypes/renders/combined/combined." + std::to_string(i + 100) + ".png";
    }

    knob1.setBounds(107, 13, 255, 187);
    knob1.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    addAndMakeVisible(knob1);


    startTimer(20);
}

DiastortionAudioProcessorEditor::~DiastortionAudioProcessorEditor()
{
}

//==============================================================================
void DiastortionAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    juce::Image background = juce::ImageCache::getFromMemory(BinaryData::background_png, BinaryData::background_pngSize);
    g.drawImageAt(background, 0, 0);


    juce::File fc(combined[combinedCounter]);
    juce::Image currCombined = juce::ImageFileFormat::loadFrom(fc);
    g.drawImageAt(currCombined, 0, 0);

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void DiastortionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    
}

void DiastortionAudioProcessorEditor::timerCallback()
{
    combinedCounter = ++combinedCounter % 1301;


    repaint();
}

juce::Image getNextFront(int num) {
    int counter = 0;
    for (int i = 0; i < BinaryData::namedResourceListSize; i++) {
        if (juce::String::fromUTF8(BinaryData::namedResourceList[i]).toStdString().find("front") != std::string::npos && counter < num)
            ++counter;
        else if (juce::String::fromUTF8(BinaryData::namedResourceList[i]).toStdString().find("front") != std::string::npos && counter == num)
            return juce::ImageCache::getFromMemory(BinaryData::namedResourceList[i], BinaryData::front_0100_pngSize);
    }
}
