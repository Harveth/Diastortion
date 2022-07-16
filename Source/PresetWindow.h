#pragma once
#include <JuceHeader.h>
#include "preset.h"
#include <string>
#include <iostream>
#include <filesystem>
#include "PresetListBox.h"


namespace fs = std::filesystem;

using namespace juce;

class presetWindow : public Component {
	Label presetLabel;
	Label presetSearchBar;
	Label nl;
	std::vector<preset> presetList;
	std::vector< TextButton> presetBtns;
	ListBox lb;
	PresetListBox plb;
	

public:
	presetWindow() {
		this->setBounds(220, 15, 750, 200);
		presetSearchBar.setEditable(true);
		presetSearchBar.setColour(juce::Label::backgroundColourId, juce::Colours::grey);
		presetSearchBar.setBounds(35, 20, 300, 20);
		presetSearchBar.onTextChange = [&]() {
			
		};
		addAndMakeVisible(presetSearchBar);

		juce::String Text;
		Text << "Search Presets ";
		presetLabel.setText(Text, juce::dontSendNotification);
		presetLabel.setBounds(35, 3, 100, 15);
		//addAndMakeVisible(presetLabel);


		//addAndMakeVisible(lb);
		//lb.setRowHeight(5);
		////lb.setModel(this);   // Tell the listbox where to get its data model
		//lb.setColour(ListBox::textColourId, Colours::white);
		//lb.setColour(ListBox::backgroundColourId, Colours::black);
		//lb.setBounds(0, 100, 750, 140);

		plb.setBounds(0, 40, 720, 140);
		addAndMakeVisible(plb);

		std::string path = "C:/ProgramData/Diastortion/presets";
		for (const auto& entry : fs::directory_iterator(path)) {
			juce::String TextL;
			std::string curPath = entry.path().string();
			TextL << curPath;
			nl.setText(TextL, juce::dontSendNotification);
			nl.setBounds(0, 0, 300, 15);
			nl.setColour(juce::Label::backgroundColourId, juce::Colours::black);
			//addAndMakeVisible(nl);
			//lb.addAndMakeVisible(nl);
			//lb.addChildComponent(nl);
			
		}
		
	}
	void paint(juce::Graphics& g) override {
		g.fillAll(juce::Colour::fromFloatRGBA(0.0f, 0.0f, 0.0f, 0.7f));
	}

	void makeInvisible() {
		this->setVisible(false);
	}

	void makeVisible() {
		this->setVisible(true);
	}

	void initPresetList() {
		
			

	}
};