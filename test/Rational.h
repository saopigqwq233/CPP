#include "iostream"

class Rational{
private:
    int nume;//分子
    int deno;//分母

public:
    Rational(const int _n,const int _d);
    Rational(double d);
    Rational(const Rational& obj);
    void normalized();
    void output();
};