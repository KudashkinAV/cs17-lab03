#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>

using namespace std;


enum Scale {Kelvin='K', Celsiy='C', Farengeit='F'};
struct temperature {
Scale scale;
double value;
}temp;

istream& operator>>(istream& in, temperature& t) {

    in>> t.value;
    char symbol;
    in>> symbol;
    switch(symbol) {
    case'K':
        t.scale = Kelvin;
        break;
    case'C':
        t.scale = Celsiy;
        break;
    case'F':
        t.scale = Farengeit;
        break;
    }
    return in;
}
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
temperature convert(temperature& temp,Scale scale){
    double k;
    temperature result;
    result.scale = scale;
    switch(temp.scale){
    case Kelvin:
        k=temp.value;
        break;
    case Celsiy:
        k=temp.value + 273.15;
        break;
    case Farengeit:
        k=(temp.value-32)/1.8+273.15;
        break;
    }

    switch(scale) {
    case Kelvin:
        break;
    case Celsiy:
        k=k+273.15;
        break;
    case Farengeit:
        k=1.8*(k-273.15)+32;
        break;

    }
    result.value = k;
    return result;
}
int
main() {
    test_input0();
    test_input1();
    test_input2();
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    vector<double> numbers(number_count);
    for (size_t i = 0; i < number_count; i++) {
        cin >> numbers[i];
    }

    size_t column_count;
    cerr << "Enter column count: ";
    cin >> column_count;

    double min = numbers[0];
    double max = numbers[0];
    for (double number : numbers) {
        if (number < min) {
            min = number;
        }
        if (number > max) {
            max = number;
        }
    }

    vector<size_t> counts(column_count);
    for (double number : numbers) {
        size_t column = (size_t)((number - min) / (max - min) * column_count);
        if (column == column_count) {
            column--;
        }
        counts[column]++;
    }

    const size_t screen_width = 80;
    const size_t axis_width = 4;
    const size_t chart_width = screen_width - axis_width;

    // Можно было бы считать в предыдущем цикле, но так более наглядно.
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