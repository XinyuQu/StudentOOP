#include <cassert>
#include <iostream>
#include "../my_code/weather.h"

using namespace std;

int main() {
    Date test_date = Date(15,12,2019);
    cout << test_date << endl;
    GPS loc = GPS(46.3, 67.2);
    Weather irkutsk = Weather("Irkutsk", loc, -1);
    cout << irkutsk << endl;
}

