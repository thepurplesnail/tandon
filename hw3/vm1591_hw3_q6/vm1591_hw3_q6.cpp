#include <iostream>
#include <string>
using namespace std;

const double PEAK_HOURS_RATE = 0.4;
const double OFF_PEAK_WEEKDAY_RATE = 0.25;
const double WEEKEND_RATE = 0.15;

int main()
{
    string day, call_start;
    int call_length;
    double cost;
    cout << "Day of the week (Mo/Tu/We/Th/Fr/Sa/Su): ";
    cin >> day;
    cout << "Start time of the call (24-hour notation): ";
    cin >> call_start;
    cout << "Length of the call (minutes): ";
    cin >> call_length;

    if (day.compare("Mo") == 0 ||
        day.compare("Tu") == 0 ||
        day.compare("We") == 0 ||
        day.compare("Th") == 0 ||
        day.compare("Fr") == 0) {
        string hour_str = "";
        string min_str = "";

        if (call_start.length() == 5) {
            hour_str += call_start[0];
            hour_str += call_start[1];
            min_str += call_start[3];
            min_str += call_start[4];
        }
        else {
            hour_str += call_start[0];
            min_str += call_start[2];
            min_str += call_start[3];
        }

        int hour = stoi(hour_str);
        int min = stoi(min_str);

        if (
            (hour >= 8 && hour < 18) || (hour == 18 && min == 0)
            ) {
            cost = PEAK_HOURS_RATE * call_length;
        } 
        else cost = OFF_PEAK_WEEKDAY_RATE * call_length;
    }
    else cost = WEEKEND_RATE * call_length;
    cout << "Total cost of call: " << cost << endl;
}