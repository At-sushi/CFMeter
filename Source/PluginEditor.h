/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class CFMeterAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    CFMeterAudioProcessorEditor (CFMeterAudioProcessor&);
    ~CFMeterAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    CFMeterAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CFMeterAudioProcessorEditor)
    
    foleys::LevelMeter meter { foleys::LevelMeter::MeterFlags::Reduction };
    foleys::LevelMeterLookAndFeel look;
};
