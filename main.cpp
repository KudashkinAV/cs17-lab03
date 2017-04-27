#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
#include "temperature.h"

using namespace std;







void test_input0() {
    istringstream in ("4K");
    temperature t;
    in >>t;
    cout << t.value;
    assert(t.value==4);
    assert(t.scale==Kelvin);
}
void test_input1() {
    istringstream in ("5C");
    temperature t;
    in >>t;
    assert(t.value==5);
    assert(t.scale==Celsiy);
}
void test_input2() {
    istringstream in ("2F");
    temperature t;
    in >>t;
    assert(t.value==2);
    assert(t.scale==Farengeit);
}

int
main() {
    test_input0();
    test_input1();
    test_input2();
    size_t temperature_count;
    cerr << "Enter temperature count: ";
    cin >> temperature_count;

    cerr << "Enter numbers: ";
    vector<temperature> temperatures(temperature_count);
    for (size_t i = 0; i < temperature_count; i++) {
        cin >> temperatures[i];
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