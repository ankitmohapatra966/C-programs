#include <iostream>

class Measurement;  // Forward declaration of Measurement class

class Distance {
private:
    int meters;
    int centimeters;

public:
    Distance(int m, int cm)  {
         meters= m;
         centimeters=cm;
    }

    friend void convertToFeetAndInches(const Distance &d, Measurement &m);
};

class Measurement {
private:
    int feet;
    int inches;

public:
    Measurement() {
        feet=0;
         inches=0 ;
    }

    void display() {
        std::cout << "Measurement: " << feet << " feet " << inches << " inches" << std::endl;
    }

    friend void convertToFeetAndInches(const Distance &d, Measurement &m);
};
// Friend function to convert Distance to Measurement
void convertToFeetAndInches(const Distance &d, Measurement &m) {
    // 1 meter = 3.28084 feet
    double totalFeet = d.meters * 3.28084 + d.centimeters / 100.0 / 30.48; // 1 meter = 100 centimeters

    m.feet = int(totalFeet);
    m.inches = int((totalFeet - m.feet) * 12);
}

int main() {
    Distance d(5, 50);  // 5 meters and 50 centimeters
    Measurement m;

    convertToFeetAndInches(d, m);
    m.display();

return 0;
}