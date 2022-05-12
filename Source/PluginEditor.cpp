/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "BinaryData.h"
#include <string>


juce::Array<juce::Image> front;
std::string frontNames[1202];
unsigned short frontCounter = 0;
unsigned short frontLoadCounter = 0;
juce::Image getNextFront(int num);

//==============================================================================
DiastortionAudioProcessorEditor::DiastortionAudioProcessorEditor (DiastortionAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (1200, 223);


    //for (int i = 100; i <= 1300; i++) {
    //    std::string path;
    //    if (i < 1000)
    //        path = "L:/projects/Pluginz/Diaa-stortion/Prototypes/renders/post-comp/front.0" + std::to_string(i) + ".png";
    //    else
    //        path = "L:/projects/Pluginz/Diaa-stortion/Prototypes/renders/post-comp/front." + std::to_string(i) + ".png";

    //    juce::File f(path);
    //    juce::Image image = juce::ImageFileFormat::loadFrom(f);
    //    front.add(image);
    //}

    for (int i = 0; i <= 1201; i++) {
        if (i + 100 < 1000)
            frontNames[i] = "L:/projects/Pluginz/Diaa-stortion/Prototypes/renders/post-comp/front.0" + std::to_string(i + 100) + ".png";
        else
            frontNames[i] = "L:/projects/Pluginz/Diaa-stortion/Prototypes/renders/post-comp/front." + std::to_string(i + 100) + ".png";
    }

    startTimer(40);
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

    //g.drawImageAt(front[frontCounter], 0, 0);

    //std::string path = "L:/projects/Pluginz/Diaa-stortion/Prototypes/renders/post-comp/front.0113.png";
    //juce::File f(path);
    //juce::Image image = juce::ImageFileFormat::loadFrom(f);
    //g.drawImageAt(image, 0, 0);


   //juce::Image currFront =  getNextFront(frontCounter);

    /*if (frontLoadCounter < 1301) {
        if (frontCounter < frontLoadCounter) {
            g.drawImageAt(front[frontCounter], 0, 0);
        }
    }
    else {
        g.drawImageAt(front[frontCounter], 0, 0);
    }*/

    juce::File f2(frontNames[frontCounter]);
    juce::Image currFront = juce::ImageFileFormat::loadFrom(f2);
    g.drawImageAt(currFront, 0, 0);



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

    //if (frontLoadCounter < 1301) {
    //    std::string path;
    //    if (frontLoadCounter < 1000)
    //        path = "L:/projects/Pluginz/Diaa-stortion/Prototypes/renders/post-comp/front.0" + std::to_string(frontLoadCounter) + ".png";
    //    else
    //        path = "L:/projects/Pluginz/Diaa-stortion/Prototypes/renders/post-comp/front." + std::to_string(frontLoadCounter) + ".png";

    //    juce::File f(path);
    //    juce::Image image = juce::ImageFileFormat::loadFrom(f);
    //    front.add(image);
    //    frontLoadCounter++;
    //}

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
