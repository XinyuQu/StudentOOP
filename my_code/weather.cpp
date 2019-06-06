#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

Date::Date(int d, int m, int y){
    if((d < 1) || (d > 31)) throw (d);
    if((m < 1) || (m > 12)) throw (m);
    if((y < 1800) || (y > 2200)) throw (y);
    day = d;
    month = m;
    year = y;
}

ostream& operator<<(ostream& os, const Date& date){
    os << date.month << "/" << date.day << "/" << date.year;
    return os;
}

/*
 * Output GPS
 **/

ostream& operator<<(ostream& os, const GPS& gps){
    os << "latitude : " << gps.latitude << "; longitude: " << gps.longitude;
    return os;
}

/*
 * A constructor for weather class.
 * */
Weather::Weather(std::string nm, GPS loc, int rating) :
station_nm(nm), my_loc(loc), rating(rating) {
}



string Weather::get_name() const {
    return station_nm;
}

int Weather::get_rating() const{
    return rating;
}

void Weather::set_rating(int new_rating){
    rating = new_rating;
}

ostream& operator<<(ostream& os, const Weather& w){
    os << w.get_name() << "rating : " << w.get_rating() << "; location: "
    << w.my_loc;
    return os;
}

