#include <iostream>
using namespace std;

const double KG_PER_LB = 0.453592;
const double M_PER_IN = 0.0254;

int main()
{
    double weight_lb, height_in, weight_kg, height_m, bmi;
    string status;

    cout << "Please enter weight(in pounds) : ";
    cin >> weight_lb;
    cout << "Please enter height(in inches) : ";
    cin >> height_in;

    weight_kg = weight_lb * KG_PER_LB;
    height_m = height_in * M_PER_IN;

    bmi = weight_kg / height_m / height_m;
    
    if (bmi < 18.5) status = "Underweight";
    else if (bmi >= 18.5 && bmi < 25) status = "Normal";
    else if (bmi >= 25 && bmi < 30) status = "Overweight";
    else "Obese";

    cout << "The weight status is: " << status;
}