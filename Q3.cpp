#include <iostream>
#include <limits>

using namespace std;

class Divide {
    int numerator;
    int denominator;

    public:
    Divide(int num, int denom): numerator(num), denominator(denom) {}

    float performDivision() {
        if (denominator == 0) {
            throw runtime_error("Division by zero is not allowed.");
        }

        if (denominator <0){
            cout<<"Warning: Denominator is negative. Result will be negative."<<endl;
            denominator = -denominator; // Make denominator positive for division
            return -static_cast<float>(numerator) / denominator;
        }
        return static_cast<float>(numerator) / denominator;
    }
};

int main(){
    int num, denom;
    //Handle Input , non numeric input and overflow by a whike loop
    while (true) {
        cout << "Enter numerator: ";
        if (!(cin >> num)) {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            continue;
        }

        cout << "Enter denominator: ";
        if (!(cin >> denom)) {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            continue;
        }
        break; // Exit loop if both inputs are valid
    }
    


    Divide division(num, denom);

    try {
        float result = division.performDivision();
        cout << "Result of division: " << result << endl;
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}