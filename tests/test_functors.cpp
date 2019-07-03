#include <iostream>
#include <functional>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

class NoNegative : public exception{
public:
    NoNegative(long long int n) : badnum(n){}
    const char* what() const throw(){
        return " Argument cannot be negative!";
    }
private:
    long long int badnum;
};

class Sin {
public:
    double operator()(double r) {
        return sin(r);
    }
};

class Fib {
public:
    Fib() {
        for(int i = 0; i < MAX_FIB; i++){
            memo[i] = NOT_CALCED;
        }
    }
    
    long long int operator()(long long int n) {
        if(n < 0) throw (NoNegative(n));

        if(memo[n] != NOT_CALCED) return memo[n];
        long long int ret = NOT_CALCED;
        if (n <= 1) return 1;
        else ret = operator()(n - 1) + operator()(n - 2);
        memo[n] = ret;
        return ret;
    }
    
    const int MAX_FIB = 100;
    const int NOT_CALCED = -1;
private:
    long long int* memo = new long long int[MAX_FIB];
};


double cube_func(double d, function<double(double)> f) {
    return f(d) * f(d) * f(d);
}


double square_func(double d, function<double(double)> f) {
    return f(d) * f(d);
}


int main() {
    const long long int FIB_NUM = -1;
    
    // first functors:
    Sin sine = Sin();
    double d = sine(PI / 2);
    cout << "sin pi / 2 == " << d << endl;
    d = sine(0);
    cout << "sin 0 == " << d << endl;
    
    Fib fib = Fib();
    try{
        long long int f = fib(FIB_NUM);
        cout << "fib(" << FIB_NUM << ") == " << f << endl;
    }
    catch(NoNegative& e){
        cerr << "Fib Num cannot be negative!" << e.what() << endl;
    }
    // then lambdas -- use several functions from cmath here:
    d = square_func(0, [](double arg) { return sin(arg); });
    cout << "Square of sin 0 = " << d << endl;
    d = square_func(1, [](double arg) { return sin(arg); });
    cout << "Square of sin 1 = " << d << endl;
    
    d = cube_func(2, [](double args){return args;});
     // you're call here!
    cout << "Cubic of 2 = " << d << endl;
     // you're call here!
    d = cube_func(2, [](double args){return sin(args);});

    cout << "Cubic of sin 2 = " << d << endl;
    
}
