#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
#include "temperature.h"

using namespace std;









int
main() {

    size_t temperature_count;
    cerr << "Enter temperature count: ";
    cin >> temperature_count;

    cerr << "Enter numbers: ";
    vector<temperature> temperatures(temperature_count);
    for (size_t i = 0; i < temperature_count; i++) {
        cin >> temperatures[i];
        if(!cin){
            cout<<"\nERROR\n";
            return 1;
        }
    }

    size_t column_count;
    cerr << "Enter column count: ";
    cin >> column_count;

    for(int i=0;i<temperature_count;i++) {
        convert(temperatures[i],Kelvin);
    }

    temperature min = temperatures[0];
    temperature max = temperatures[0];
    for (temperature number : temperatures) {
        if (number < min) {
            min = number;
        }
        if (number > max) {
            max = number;
        }
    }

    vector<size_t> counts(column_count);
    for (temperature number : temperatures) {
        size_t column = (size_t)((number.value - min.value) / (max.value - min.value) *
                column_count);
        if (column == column_count) {
            column--;
        }
        counts[column]++;
    }

    const size_t screen_width = 80;
    const size_t axis_width = 4;
    const size_t chart_width = screen_width - axis_width;


    size_t max_count = 0;
    for (size_t count : counts) {
        if (count > max_count) {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > chart_width;

    for (size_t count : counts) {
        if (count < 100) {
            cout << ' ';
        }
        if (count < 10) {
            cout << ' ';
        }
        cout << count << "|";

        size_t height = count;
        if (scaling_needed) {
            // Point: код должен быть в первую очередь понятным.
            const double scaling_factor = (double)chart_width / max_count;
            height = (size_t)(count * scaling_factor);
        }

        for (size_t i = 0; i < height; i++) {
            cout << '*';
        }
        cout << '\n';
    }


    return 0;
}