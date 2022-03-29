/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
CFMeterAudioProcessorEditor::CFMeterAudioProcessorEditor (CFMeterAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (80, 400);
    
    look.setColour(foleys::LevelMeter::lmMeterReductionColour, juce::Colours::whitesmoke);
    
    meter.setLookAndFeel(&look);
    meter.setMeterSource(&audioProcessor.meterSource);
    addAndMakeVisible(meter);
}

CFMeterAudioProcessorEditor::~CFMeterAudioProcessorEditor()
{
}

//==============================================================================
void CFMeterAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
//    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

}

void CFMeterAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    meter.setBounds(0, 0, getWidth(), getHeight());
}
