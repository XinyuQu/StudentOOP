#ifndef WEATHER_H
#define WEATHER_H
#include <vector>

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

class WReading{
friend std::ostream& operator<<(std::ostream& os, const WReading& wr);
public:
    WReading(Date dt, double temp, double hum, double ws):
        date(dt), temperature(temp),humidity(hum),windspeed(ws){}
    
    double get_tempF();
    double get_tempC(){return temperature;};

private:
    Date date;
    double temperature;
    double humidity;
    double windspeed;
};

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
    void add_reading(WReading wr);
    int get_heat_index();
    int get_wind_chill();
private:
    std::vector<WReading> wreadings;
    std::string station_nm;
    GPS my_loc;
    int rating = UNRATED;
};


#endif