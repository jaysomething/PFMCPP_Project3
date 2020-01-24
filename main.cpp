/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On a new branch:

 1) Add a constructor for each User-Defined-Type.
 
 2) Instantiate a few of your user-defined types in the main function at the bottom of that file, and call some of those member functions.
 
 3) make them print out something interesting via std::cout
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 
 example:
 */

#include <iostream>
#include <iomanip>

namespace Example 
{
struct UDT  // my user defined type
{
    int a; //a member variable
    UDT() { a = 0; }             //3) the constructor
    void printThing()            //1) the member function
    {
        std::cout << "UDT::printThing() " << a << std::endl;  //5) printing out something interesting
    }
};

int main()
{
    UDT foo;              //4) instantiating a UDT in main()
    foo.printThing();     //4) calling a member function of the instance that was instantiated.
    
    return 0;
}
}

//insert  into main() of user's repo.


/*
 example:
 */
struct CarWash            //1) a U.D.T. with a random number of member variables
{
    int numSponges = 3;
    double amountOfSoapUsedPerCar = 2.6; //2) relevant data types
    unsigned int numCarsProcessed = 0;
    
    struct Car                             //4) nested class
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        //2) relevant data types
    };
    
    void washAndWaxCar( Car car );         //3) member function with a user-defined type as the parameter.  The user-defined type parameter happens to be the nested class.
    
    Car myCar;  //5) a member variable whose type is a UDT.
};


/*
 1)
 */
#include <string>
struct Speaker
{
    bool isOn;
    float coneSize;
    bool isPorted;
    std::string brand;

    Speaker()
    {
        isOn = false;
        coneSize = 6.f;
        isPorted = true;
        brand = "ADAM";
    }

    struct Eq
    {
        bool isOn;
        std::string shape;
        double freq;
        double gain;

        Eq()
        {
            isOn = false;
            shape = "Bell";
            freq = 200.0;
            gain = 0.0;
        }

        void setFreq(double bandFreq)
        {
            freq = bandFreq;
            std::cout << "Frequency set to " << freq << std::endl;
        }

        void setGain(double bandGain)
        {
            gain = bandGain;
            std::cout << "Gain set to " << gain << std::endl;
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
    std::cout << "EQ is turned ON" << std::endl;
}

/*
 2)
 */

struct Bass
{
    std::string brand;
    int numberOfStrings;
    int scale;
    bool isActive;

    Bass()
    {
        brand = "Fender";
        numberOfStrings = 5;
        scale = 4;
        isActive = true;
    }

    void playInstrument();
};

void Bass::playInstrument()
{
    std::cout << "Playing bass" << std::endl;
}
/*
 3)
 */

struct Chair
{
    std::string color;
    int price;
    bool hasWheels;

    Chair()
    {
        color = "Black";
        price = 100;
        hasWheels = true;
    }
};
/*
 4)
 */

struct Mixer
{
    std::string name;
    bool isOn;
    std::string manufacturer;
    int numberOfChannels;

    Mixer()
    {
        isOn = false;
        manufacturer = "Midas";
        numberOfChannels = 32;
    }

    struct Channel
    {
        struct Eq
        {
            std::string shape;
            double freq;
            double gain;

            Eq()
            {
                shape = "Bell";
                freq = 200.0;
                gain = 0.0;
            }

            void setFreq(double freq);
            void setGain(double gain);
        };

        struct Fader
        {
            double position;

            Fader()
            {
                position = 0.0;
            }
        };

        void adjustEq(Eq eq1);
    };
};

void Mixer::Channel::Eq::setFreq(double bandFreq)
{
    freq = bandFreq;
    std::cout << "Frequency is set to " << bandFreq << std::endl;
}

void Mixer::Channel::Eq::setGain(double bandGain)
{ 
    gain = bandGain;
    std::cout << "Gain is set to " << bandGain << std::endl;
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

    Synth()
    {
        numberOfFilters = 3;
        numberOfFilters = 2;
        hasKB = false;
    }
};
/*
 6)
 */

struct Room
{
    float length;
    float width;
    float height;
    int numberOfDoors;

    Room()
    {
        length = 6.5f;
        width = 5.f;
        height = 3.f;
        numberOfDoors = 2;
    }
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

    Mic()
    {
        brand = "Neumann";
        micType = "condenser";
        polarPattern = "cardioid";
        needsPhantom = true;
    }
};
/*
 8)
 */
struct AudioInterface
{
    std::string name;
    bool isOn;
    int numberOfMicPres;
    int numberOfInputs;
    int numberOfOutputs;
    int numberOfHpOuts;
    bool hasDSP;

    AudioInterface()
    {
        isOn = false;
        numberOfMicPres = 4;
        numberOfInputs = 8;
        numberOfOutputs = 8;
        numberOfHpOuts = 2;
        hasDSP = true;
    }
};
/*
 9)
 */
struct Cable
{
    std::string type;
    std::string connector;
    float length;

    Cable()
    {
        type = "audio";
        connector = "XLR";
        length = 5.f;
    }
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
    eq1.setFreq(150.0);
    eq1.setGain(3.0);
    std::cout << std::endl;

    Bass fender5;
    fender5.playInstrument();
    std::cout << std::endl;

    Mixer midas32;
    midas32.name = "Midas 32";
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

