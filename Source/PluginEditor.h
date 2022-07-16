/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Knob1.h"
#include "PresetWindow.h"

//==============================================================================
/**
*/
class DiastortionAudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::Timer
{
public:
    DiastortionAudioProcessorEditor (DiastortionAudioProcessor&);
    ~DiastortionAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void timerCallback() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DiastortionAudioProcessor& audioProcessor;
    Knob1 knob1;
    Knob1 knob2;
    TextEditor te;
    Label label;
    Label codeInput;
    TextButton codeButton;
    bool isSignedIn;
    bool isPresetPressed;
    std::vector<std::string> licenseCodes = { "27/6/2022", "La Calin", "Solo Strings"};
    TextButton presetButton;
    presetWindow PW;

    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> driveAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mixAttachment;
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DiastortionAudioProcessorEditor)
};
