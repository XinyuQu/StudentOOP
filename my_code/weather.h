#ifndef WEATHER_H
#define WEATHER_H
<<<<<<< HEAD
#include <vector>
=======
>>>>>>> bd6845170c2eb41e567b105458afae8efdc627f1

#include <string>

struct GPS {
    double latitude;
    double longitude;
    GPS(double la, double lo) : latitude(la),
    longitude(lo) {}
};

std::ostream& operator<<(std::ostream& os, const GPS& gps);

class Date{
friend std::ostream& operator<<(std::ostream& os, const Date& date);
public:
    Date(int d, int m, int );
private:
    int day;
    int month;
    int year;
};
<<<<<<< HEAD

class WReading{
friend std::ostream& operator<<(std::ostream& os, const WReading& wr);
public:
    WReading(Date dt, double temp, double hum, double ws):
        date(dt), temperature(temp),humidity(hum),windspeed(ws){}
private:
    Date date;
    double temperature;
    double humidity;
    double windspeed;
};

=======
>>>>>>> bd6845170c2eb41e567b105458afae8efdc627f1
const int UNRATED = -1;
const int BAD = 0;
const int OK = 1;
const int GOOD = 2;

class Weather {
// << should output name, rating, and use the GPS << to output my_loc

    friend std::ostream& operator<<(std::ostream& os, const Weather& w);
public:
    Weather(std::string nm, GPS loc, int rating);
    std::string get_name() const;
    int get_rating() const;
    void set_rating(int new_rating);
<<<<<<< HEAD
    void add_reading(WReading wr);
private:
    std::vector<WReading> wreadings;
=======
private:
>>>>>>> bd6845170c2eb41e567b105458afae8efdc627f1
    std::string station_nm;
    GPS my_loc;
    int rating = UNRATED;
};


#endif
