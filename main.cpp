/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to your types. 
 
 2) use while() or for() loops to do something interesting inside these new member functions.
         a) for example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 
 example:
 */

#include <iostream>
#include <iomanip>

namespace Example
{
struct Bar
{
    int num = 0;
    Bar(int n) : num(n) {}
};
struct Foo
{
    Bar scopeLifetimeFunc(int threshold, int startingVal) //3), 4c)
    {
        Bar bar(startingVal);       //4a)
        while (bar.num < threshold) //4a)
        {
            bar.num += 1; //4a)

            if (bar.num >= threshold) //4b)
                return bar;
        }

        return Bar{-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1); //5)

    std::cout << "bar.num: " << bar.num << std::endl; //6)
    return 0;
}
} // namespace Example

//call Example::main() in main()

/*
 1)
 */
#include <string>
struct Speaker
{
    bool isOn{false};
    float coneSize{6.0f};
    bool isPorted{true};
    std::string brand{"ADAM"};

    Speaker() {}

    struct Eq
    {
        bool isOn;
        std::string shape;
        double freq;
        double gain;

        Eq() : isOn(false), shape("Bell"), freq(200.0), gain(0.0) {}

        void print()
        {
            if (isOn)
            {
                std::cout << "EQ is ON" << std::endl;
            }
            else
            {
                std::cout << "EQ is OFF" << std::endl;
            }
            std::cout << "Shape is " << shape << std::endl;
            std::cout << "Frequency is " << freq << " Hz" << std::endl;
            std::cout << "Gain is " << gain << " dB" << std::endl;
        }

        void setFreq(double bandFreq)
        {
            freq = bandFreq;
            std::cout << "Frequency set to " << freq << " Hz" << std::endl;
        }

        void setGain(double bandGain)
        {
            gain = bandGain;
            std::cout << "Gain set to " << gain << " dB" << std::endl;
        }

        void sweepFrequency(double freqStart, double freqEnd)
        {
            std::cout << "Begin sweep, starting from " << freqStart << std::endl;

            for (freq = freqStart; freq <= freqEnd; freq++)
            {
                std::cout << freq << std::endl;
            }

            freq = freqEnd;
            std::cout << "End sweep" << std::endl;
        }
    };

    bool toggleOnOff();
    void turnOnEq(Eq eq1);
};

bool Speaker::toggleOnOff()
{
    if (isOn)
    {
        isOn = false;
        std::cout << "Speaker is turned OFF" << std::endl;
        return false;
    }

    isOn = true;
    std::cout << "Speaker is turned ON" << std::endl;
    return true;
}

void Speaker::turnOnEq(Eq eq1)
{
    eq1.isOn = true;
    std::cout << "EQ has been turned ON" << std::endl;
}

/*
 2)
 */

struct Bass
{
    std::string brand{"Fender"};
    int numberOfStrings{5};
    int scale{34};
    bool isActive{true};
    std::string circleOfFourths[12]{"C", "G", "D", "A", "E", "B", "Gb", "Db", "Ab", "Eb", "Bb", "F"};

    Bass() {}

    void playInstrument();
    void playOpenStrings(int numberOfStrings);
};

void Bass::playInstrument()
{
    std::cout << "Playing bass" << std::endl;
    std::cout << brand << " " << numberOfStrings << "-string" << std::endl;
    std::cout << scale << "' scale";
    if (isActive)
    {
        std::cout << " active bass" << std::endl;
    }
    else
    {
        std::cout << " passive bass" << std::endl;
    }
}

void Bass::playOpenStrings(int numStrings)
{
    int index{1};

    if (numStrings == 6)
    {
        index = 0;
    }

    for (int i = 0; i < numStrings; i++)
    {
        std::cout << circleOfFourths[(index + i) % 12] << std::endl;
    }
}
/*
 3)
 */

struct Chair
{
    std::string color;
    int price;
    bool hasWheels;

    Chair() : color("Black"), price(100), hasWheels(true) {}
};
/*
 4)
 */

struct Mixer
{
    std::string name;
    bool isOn{true};
    std::string manufacturer{"Midas"};
    int numberOfChannels{32};

    Mixer() {}

    void print()
    {
        std::cout << manufacturer << " " << numberOfChannels << "-channel mixer is ";

        if (isOn)
        {
            std::cout << "ON" << std::endl;
        }
        else
        {
            std::cout << "OFF" << std::endl;
        }
    }

    struct Channel
    {
        int number{0};
        bool isMuted{false};

        struct Eq
        {
            std::string shape;
            double freq;
            double gain;

            Eq() : shape("Bell"), freq(200.0), gain(0.0) {}

            void setFreq(double freq);
            void setGain(double gain);
        };

        struct Fader
        {
            double position{0.0};

            Fader() {}
        };

        void adjustEq(Eq eq1);
    };

    // create an array of Channels
    Channel channel[64]; FIXME no raw arrays.  use std::vector

    void setChannelNum()
    {
        for (int i = 0; i < numberOfChannels; i++)
        {
            channel[i].number = i + 1;
        }
    }

    void muteChannels(int channelStart, int channelEnd)
    {
        if (channelEnd > numberOfChannels)
        {
            channelEnd = numberOfChannels;
        }

        if (channelStart < 1)
        {
            channelStart = 1;
        }

        for (int i = channelStart - 1; i < channelEnd; i++)
        {
            channel[i].isMuted = true;
        }
    }

    void showMuteStatus()
    {
        for (int i = 0; i < numberOfChannels; i++)
        {
            if (channel[i].isMuted)
            {
                std::cout << "Channel " << channel[i].number << " is muted" << std::endl;
            }
            else
            {
                std::cout << "Channel " << channel[i].number << " is ON" << std::endl;
            }
        }
    }
};

void Mixer::Channel::Eq::setFreq(double bandFreq)
{
    freq = bandFreq;
    std::cout << "Frequency is set to " << bandFreq << " Hz" << std::endl;
}

void Mixer::Channel::Eq::setGain(double bandGain)
{
    gain = bandGain;
    std::cout << "Gain is set to " << bandGain << " dB" << std::endl;
}

void Mixer::Channel::adjustEq(Eq eq1)
{
    double freq;
    double gain;

    std::cout << "Set frequency to: " << std::endl;
    freq = 80.0;
    eq1.setFreq(freq);

    std::cout << "Set gain to: " << std::endl;
    gain = 1.0;
    eq1.setGain(gain);
}

/*
 5)
 */
struct Synth
{
    int numberOfOscs;
    int numberOfFilters;
    bool hasKB;

    Synth() : numberOfOscs(3), numberOfFilters(2), hasKB(false) {}
};
/*
 6)
 */

struct Room
{
    float length{6.5f};
    float width{5.0f};
    float height{3.0f};
    int numberOfDoors{2};

    Room() {}
};
/*
 7)
 */
struct Mic
{
    std::string brand;
    std::string micType;
    std::string polarPattern;
    bool needsPhantom;

    Mic() : brand("Neumann"), micType("condenser"), polarPattern("cardioid"), needsPhantom(true) {}
};
/*
 8)
 */
struct AudioInterface
{
    std::string name;
    bool isOn{false};
    int numberOfMicPres{4};
    int numberOfInputs{8};
    int numberOfOutputs{8};
    int numberOfHpOuts{2};
    bool hasDSP{true};

    AudioInterface() {}
};
/*
 9)
 */
struct Cable
{
    std::string type;
    std::string connector;
    float length;

    Cable() : type("audio"), connector("XLR"), length(5.0f) {}
};
/*
 10)
 */

struct Studio
{
    Mic vocalMic;
    Synth synth1;
    Bass bass1;

    void switchOn(AudioInterface aInterface1);
    void switchOn(Mixer mixer1);
};

void Studio::switchOn(AudioInterface aInterface1)
{
    aInterface1.isOn = true;
    std::cout << aInterface1.name << " is turned ON" << std::endl;
}

void Studio::switchOn(Mixer mixer1)
{
    mixer1.isOn = true;
    std::cout << mixer1.name << " is turned ON" << std::endl;
}

int main()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    Example::main();
    std::cout << std::endl;

    Speaker speaker1;
    Speaker::Eq eq1;
    speaker1.toggleOnOff();
    speaker1.turnOnEq(eq1);
    std::cout << std::endl;

    eq1.sweepFrequency(80.0, 100.0);
    std::cout << std::endl;
    eq1.print();
    std::cout << std::endl;

    eq1.setFreq(150);
    eq1.setGain(3.0);
    std::cout << std::endl;

    Bass fender5;
    fender5.playInstrument();
    fender5.playOpenStrings(fender5.numberOfStrings);
    std::cout << std::endl;

    Mixer midas32;
    midas32.name = "Midas 32";
    midas32.print();
    std::cout << std::endl;

    midas32.setChannelNum();
    midas32.muteChannels(20, 33);
    midas32.showMuteStatus();
    std::cout << std::endl;

    // Mixer::Channel midasChannel1;
    // Mixer::Channel::Eq channelEq1;
    // midasChannel1.adjustEq(channelEq1);
    // std::cout << std::endl;

    Room room1;

    AudioInterface interface1;
    interface1.name = "Apollo 8";

    Cable audioCable;

    Studio studio1;
    studio1.switchOn(interface1);
    studio1.switchOn(midas32);
    std::cout << std::endl;

    std::cout << "good to go!" << std::endl;
}
