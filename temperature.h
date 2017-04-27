//
// Created by u211-13 on 27.04.2017.
//

#ifndef LAB01_TEMPERATURE_H
#define LAB01_TEMPERATURE_H

#include <iostream>


enum Scale {Kelvin='K', Celsiy='C', Farengeit='F'};
struct temperature {
    Scale scale;
    double value;
}temp;

std::istream& operator>>(std::istream& in, temperature& t);
temperature convert(temperature& temp,Scale scale);
bool operator<(temperature& left, temperature& right);
bool operator>(temperature& left, temperature& right);
bool operator==(temperature& left, temperature& right);
#endif //LAB01_TEMPERATURE_H
