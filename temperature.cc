//
// Created by u211-13 on 27.04.2017.
//
#include "temperature.h"
#include <iostream>
std::istream& operator>>(std::istream& in, temperature& t) {

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

bool operator<(temperature& left, temperature& right){
    temperature t1 = convert(left,Kelvin);
    temperature t2 = convert(right,Kelvin);
    return t1.value < t2.value;
}
bool operator>(temperature& left, temperature& right){
    temperature t1 = convert(left,Kelvin);
    temperature t2 = convert(right,Kelvin);
    return t1.value > t2.value;
}
bool operator==(temperature& left, temperature& right) {
    temperature t1 = convert(left, Kelvin);
    temperature t2 = convert(right, Kelvin);
    return t1.value == t2.value;
}

bool correct()