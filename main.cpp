/*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

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
    float coneSize;
    bool isPorted = true;
    std::string brand;

    struct Eq
    {
        std::string shape;
        double freq = 0.0;
        double gain = 0.0;

        void setFreq(double freq);
        void setGain(double gain);
    };

    bool toggleOnOff();
    void turnOnEq(Eq eq1);
};

/*
 2)
 */

struct Bass
{
    std::string brand;
    int numberOfStrings = 5;
    int scale = 34;
    bool isActive = true;

    void playInstrument();
};

/*
 3)
 */

struct Chair
{
    std::string color = "black";
    int price;
    bool hasWheels = true;
};

/*
 4)
 */

struct Mixer
{
    std::string manufacturer;
    int numberOfChannels = 32;

    struct Channel
    {
        struct Eq
        {
            std::string shape;
            double freq = 0.0;
            double gain = 0.0;

            void setFreq(double freq);
            void setGain(double gain);
        };

        struct Fader
        {
            double position = 0.0;
        };

        void adjustEq(Eq eq1);
    };
};

/*
 5)
 */

struct Synth
{
    int numberOfOscs = 3;
    int numberOfFilters = 2;
    bool hasKB = false;
};

/*
 6)
 */

struct Room
{
    float length;
    float width;
    float height;
    int numberOfDoors = 1;
};

/*
 7)
 */
struct Mic
{
    std::string brand;
    std::string micType = "condenser";
    std::string polarPattern = "cardioid";
    bool needsPhantom = true;
};

/*
 8)
 */
struct AudioInterface
{
    int numberOfMicPres = 4;
    int numberOfInputs = 8;
    int numberOfOutputs = 8;
    int numberOfHpOuts = 2;
    bool hasDSP = true;
};


/*
 9)
 */
struct Cable
{
    std::string type = "audio";
    std::string connector = "XLR";
    float length;
};


/*
 10)
 */

struct Studio
{
    Mic vocalMic;
    Synth synth1;
    Bass bass1;

    void switchOn (AudioInterface aInterface1);
    void switchOn (Mixer mixer1);

};

#include <iostream>

int main()
{
    std::cout << "good to go!" << std::endl;
}
