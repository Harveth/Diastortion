/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "BinaryData.h"
#include <string>



std::string frontNames[1202];
std::string spiny[80];
std::string screen[80];
unsigned short frontCounter = 0;
unsigned short spinyCounter = 0;
unsigned short screenCounter = 0;
juce::Image getNextFront(int num);

//==============================================================================
DiastortionAudioProcessorEditor::DiastortionAudioProcessorEditor (DiastortionAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (1200, 223);

    for (int i = 0; i <= 1201; i++) {
        if (i + 100 < 1000)
            frontNames[i] = "L:/projects/Pluginz/Diaa-stortion/Prototypes/renders/post-comp/front.0" + std::to_string(i + 100) + ".png";
        else
            frontNames[i] = "L:/projects/Pluginz/Diaa-stortion/Prototypes/renders/post-comp/front." + std::to_string(i + 100) + ".png";
    }

    for (int i = 0; i < 80; i++) {
        if (i + 80 < 100)
            spiny[i] = "L:/projects/Pluginz/Diaa-stortion/Prototypes/renders/spinyPT/spiny.00" + std::to_string(i + 80) + ".png";
        else
            spiny[i] = "L:/projects/Pluginz/Diaa-stortion/Prototypes/renders/spinyPT/spiny.0" + std::to_string(i + 80) + ".png";
    }

    for (int i = 0; i < 80; i++) {
        if (i + 80 < 100)
            screen[i] = "L:/projects/Pluginz/Diaa-stortion/Prototypes/renders/screenPT/screen.00" + std::to_string(i + 80) + ".png";
        else
            screen[i] = "L:/projects/Pluginz/Diaa-stortion/Prototypes/renders/screenPT/screen.0" + std::to_string(i + 80) + ".png";
    }


    startTimer(1);
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

    juce::File ftl("L:/projects/Pluginz/Diaa-stortion/Prototypes/renders/tubes-lights/tl.0001.png");
    juce::Image tl = juce::ImageFileFormat::loadFrom(ftl);
    g.drawImageAt(tl, 0, 0);

    juce::File fs(spiny[spinyCounter]);
    juce::Image currSpiny = juce::ImageFileFormat::loadFrom(fs);
    g.drawImageAt(currSpiny, 0, 0);

    juce::File f2(frontNames[frontCounter]);
    juce::Image currFront = juce::ImageFileFormat::loadFrom(f2);
    g.drawImageAt(currFront, 0, 0);

    juce::File fsc(screen[screenCounter]);
    juce::Image currScr = juce::ImageFileFormat::loadFrom(fsc);
    g.drawImageAt(currScr, 0, 0);

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
    frontCounter = ++frontCounter % 1202;
    spinyCounter = ++spinyCounter % 80;
    screenCounter = ++screenCounter % 80;


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
