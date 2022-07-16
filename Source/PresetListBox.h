#pragma once
#include <JuceHeader.h>

using namespace juce;


class PresetListBox : public ListBoxModel, public Component
{
public:
    PresetListBox()
    {
        // In your constructor, you should add any child components, and
        // initialise any special settings that your component needs.
        addAndMakeVisible(listBox);
        listBox.setRowHeight(15);
        listBox.setModel(this);   // Tell the listbox where to get its data model
        listBox.setColour(ListBox::textColourId, Colours::white);
        listBox.setColour(ListBox::backgroundColourId, Colours::black);
        listBox.getViewport()->setScrollOnDragEnabled(true);
        listBox.scrollToEnsureRowIsOnscreen(true);

        setSize(750, 140);
    }

    ~PresetListBox()
    {
    }

    void paint(Graphics& g) override
    {
        /* This demo code just fills the component's background and
           draws some placeholder text to get you started.

           You should replace everything in this method with your own
           drawing code..
        */
        g.fillAll(Colours::lightgrey);   // clear the background

    }

    void resized() override
    {
        // This method is where you should set the bounds of any child
        // components that your component contains..

        listBox.setBounds(0, 0, getParentWidth(), getParentHeight());
    }

    // The following methods implement the ListBoxModel virtual methods:
    int getNumRows() override
    {
        return 20; //you should probably derive this from whatever source data you end up using
    }

    void paintListBoxItem(int rowNumber, Graphics& g,
        int width, int height, bool rowIsSelected) override
    {

        if (rowIsSelected)
            g.fillAll(Colours::lightblue);

        g.setColour(Colours::white);
        g.setFont(height * 0.7f);

        g.drawText("Row Number " + String(rowNumber + 1), 5, 0, width, height,
            Justification::centredLeft, true);
    }

    void selectedRowsChanged(int /*lastRowselected*/) override
    {
        //do stuff when selection changes
    }


private:
    ListBox listBox;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PresetListBox)
};