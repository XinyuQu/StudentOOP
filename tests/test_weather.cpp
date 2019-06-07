#include <cassert>
#include <iostream>
<<<<<<< HEAD
#include <fstream>
=======
>>>>>>> bd6845170c2eb41e567b105458afae8efdc627f1
#include "../my_code/weather.h"

using namespace std;

<<<<<<< HEAD
void get_wreadings(string filenm, Weather& w) {
    ifstream rfile(filenm);
    if (!rfile) {
        cout << "Could not read input file: " << filenm << endl;
        exit(1);
    }
    int m, d, y;
    double temp, hum, ws;
    while (rfile >> m >> d >> y >> temp >> hum >> ws) {
        WReading wr = WReading(Date(d, m, y), temp, hum, ws);
        w.add_reading(wr);
    }
    rfile.close();
}


int main() {
    Weather irkutsk = Weather("Irkutsk", GPS(46.3,67.2), -1);
    
    string filenm;
    cout << "Input the name of the new readings file:\n";
    cin >> filenm;
    
    get_wreadings(filenm, irkutsk);
    
    cout << irkutsk << endl;
}
=======
int main() {
    Date test_date = Date(15,12,2019);
    cout << test_date << endl;
    GPS loc = GPS(46.3, 67.2);
    Weather irkutsk = Weather("Irkutsk", loc, -1);
    cout << irkutsk << endl;
}

>>>>>>> bd6845170c2eb41e567b105458afae8efdc627f1
