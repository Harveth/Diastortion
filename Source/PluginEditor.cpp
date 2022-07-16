/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "BinaryData.h"
#include <string>
#include <fstream>






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

        //if (i + 100 < 1000)
        //    combined[i] = "C:/ProgramData/Diastortion/pix/combined.0" + std::to_string(i + 100) + ".png";
        //else
        //    combined[i] = "C:/ProgramData/Diastortion/pix/combined." + std::to_string(i + 100) + ".png";
    }

    driveAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "SLIDER_DRIVE", knob1);
    mixAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "SLIDER_MIX", knob2);

    knob1.setBounds(107, 13, 255, 187);
    knob1.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    knob2.setBounds(820, 13, 255, 187);
    knob2.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);


    label.setBounds(0, 0, 1200, 223);
    label.setColour(juce::Label::backgroundColourId, juce::Colours::black);
    juce::String Text;
    Text << "Welcome to Diastortion !!";
    Text << newLine;
    Text << "Please enter a valid license code";
    label.setText(Text, juce::dontSendNotification);

    codeInput.setEditable(true);
    codeInput.setColour(juce::Label::backgroundColourId, juce::Colours::grey);
    codeInput.setBounds(450, 105, 300, 30);

    codeButton.setButtonText("enter");
    codeButton.setColour(juce::Label::backgroundColourId, juce::Colours::grey);
    codeButton.setBounds(950, 115, 80, 20);
    codeButton.onClick = [&]() {
        for (auto i : licenseCodes) {
            if (codeInput.getText().toStdString() == i) {
                isSignedIn = true;
                label.setBounds(-5000, -5000, 10, 10);
                codeInput.setBounds(-5000, -5000, 10, 10);
                codeButton.setBounds(-5000, -5000, 10, 10);

                std::fstream lFile;
                lFile.open("C:/ProgramData/Diastortion/license.txt", std::ios::out);
                if (lFile.is_open()) {
                    lFile << "6969";
                }
                lFile.close();
            }
        }
    };

    te.setBounds(600, 13, 200, 20);

    addAndMakeVisible(knob1);
    addAndMakeVisible(knob2);

    presetButton.setBounds(25, 20, 80, 20);
    presetButton.setButtonText("Presets");
    presetButton.setColour(juce::Label::backgroundColourId, juce::Colours::grey);
    addAndMakeVisible(PW);
    PW.setVisible(false);

    isPresetPressed = false;
    presetButton.onClick = [&]() {
        if (!isPresetPressed) {
            isPresetPressed = true;
            PW.makeVisible();
        }
        else {
            isPresetPressed = false;
            PW.makeInvisible();
        }
    };

    addAndMakeVisible(presetButton);

    isSignedIn = false;
    std::fstream licFile;
    licFile.open("C:/ProgramData/Diastortion/license.txt");
    if (licFile.is_open(), std::ios::in) {

        std::string fileText;
        getline(licFile, fileText);
        if(fileText == "6969")
            isSignedIn = true;
    }
    licFile.close();

    if (!isSignedIn) {
        addAndMakeVisible(label);
        addAndMakeVisible(codeInput);
        addAndMakeVisible(codeButton);
    }

    //addAndMakeVisible(te);


    startTimer(35);
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
