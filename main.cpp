/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) initialize some of your member variables either in-class or in the Constructor member initializer list.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

#include <iostream>
#include <iomanip>

namespace Example {
struct UDT  
{
    int a; //a member variable
    float b { 2.f }; //3) in-class initialization
    UDT() : a(0) { } //3) 'constructor-initializer-list' member variable initialization
    void printThing()  //the member function
    {
        std::cout << "UDT::printThing() a:" << a << " b: " << b << std::endl;  //4) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printThing(); //calling a member function of the instance that was instantiated.
    return 0;
}
}



/*
 1)
 */
#include <string>
struct Speaker
{
    bool isOn { false };
    float coneSize { 6.0f };
    bool isPorted { true };
    std::string brand { "ADAM" };

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
            if(isOn)
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
            std::cout << "Gain set to " << gain << " dB" <<  std::endl;
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
    std::string brand { "Fender" };
    int numberOfStrings { 5 };
    int scale { 34 };
    bool isActive { true };

    Bass() {}

    void playInstrument();
};

void Bass::playInstrument()
{
    std::cout << "Playing bass" << std::endl;
    std::cout << brand << " " << numberOfStrings << "-string" << std::endl;
    std::cout << scale << "' scale";
    if(isActive)
    {
        std::cout << " active bass" << std::endl;
    }
    else
    {
        std::cout << " passive bass" << std::endl;
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
    bool isOn { false };
    std::string manufacturer { "Midas" };
    int numberOfChannels { 32 };

    Mixer() {}

    void print()
    {
        std::cout << manufacturer << " " << numberOfChannels << "-channel mixer is ";

        if(isOn)
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
            double position { 0.0 };

            Fader() {}
        };

        void adjustEq(Eq eq1);
    };
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

    std::cout << "Set frequency to: ";
    std::cin >> freq;
    eq1.setFreq(freq);

    std::cout << "Set gain to: ";
    std::cin >> gain;
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
    float length { 6.5f };
    float width { 5.0f };
    float height { 3.0f };
    int numberOfDoors { 2 };

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
    bool isOn { false };
    int numberOfMicPres { 4 };
    int numberOfInputs { 8 };
    int numberOfOutputs { 8 };
    int numberOfHpOuts { 2 };
    bool hasDSP { true };

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
    // I thought I'd be able to assign true to eq1.isOn via the following member function...
    speaker1.turnOnEq(eq1);
    // ...but this following function reveals that it's not the case. What have I not understood correctly here?
    eq1.print();
    std::cout << std::endl;
    eq1.setFreq(150);
    eq1.setGain(3.0);
    std::cout << std::endl;

    Bass fender5;
    fender5.playInstrument();
    std::cout << std::endl;

    Mixer midas32;
    midas32.name = "Midas 32";
    midas32.print();
    std::cout << std::endl;

    Mixer::Channel midasChannel1;
    Mixer::Channel::Eq channelEq1;
    midasChannel1.adjustEq(channelEq1);
    std::cout << std::endl;

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
