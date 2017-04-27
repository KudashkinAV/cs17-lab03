//
// Created by u211-13 on 27.04.2017.
//

#include <sstream>
#include "temperature.h"

using namespace std;

int main() {

    istringstream in_0 ("4K");
    temperature t;
    in_0 >>t;
    cout << t.value;
    assert(t.value==4);
    assert(t.scale==Kelvin);


    istringstream in_1 ("5C");

    in_1 >>t;
    assert(t.value==5);
    assert(t.scale==Celsiy);


    istringstream in_2 ("2F");

    in_2 >>t;
    assert(t.value==2);
    assert(t.scale==Farengeit);

    istringstream in_3 ("-300C");

    in_3 >>t;
    assert(!in_3);

    istringstream in_4 ("1488S");

    in_4 >>t;
    assert(!in_4);

    istringstream in_5 ("oh");

    in_5 >>t;
    assert(!in_5);



}