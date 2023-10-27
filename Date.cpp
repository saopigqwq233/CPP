#include "Date.h"
void Date::print() const {
    printf("year:%d month:%d day:%d\n",_year,_month,_day);
}
int Date::GetMonthDay(int year, int month) {
    //月份数组，下标即为月份
    const static int monthArray[]={
            0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    //如果2月，且为闰年
    if(month==2&&((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
        return 29;
    }
    return monthArray[month];
}
//初始化构造函数
Date::Date(int year, int month, int day) {
    _year=year;
    _month=month;
    _day=day;

    //检测是否正确
    if((month<1||month>12)||day<1||day> GetMonthDay(year,month))
    {
        cout<<"错误月份、日期"<<endl;
    }
}
Date::Date(const Date &d) {
    this->_year=d._year;
    this->_month=d._month;
    this->_day=d._day;
}

Date::~Date() {
    _year=_month= _day= 0;
}

Date &Date::operator=(const Date &d){
    if(this!=&d) {
        this->_year = d._year;
        this->_month = d._month;
        this->_day = d._day;
    }
    return *this;
}

Date &Date::operator+=(int day){
    if(day<0)
    {
        return *this-=(-day);
    }
    _day+=day;
    while (_day> GetMonthDay(_year,_month))
    {
        _day-= GetMonthDay(_year,_month);
        _month+=1;
        if(_month==13)
        {
            _year++;
            _month=1;
        }
    }
    return *this;
}

// 赋值运算符重载
Date Date::operator+(int day){
    Date tmp(*this);
    tmp+=day;
    return tmp;
}

Date Date::operator-(int day) {
    Date tmp(*this);
    tmp+=(-day);
    return tmp;
}

Date &Date::operator-=(int day) {
    if(day<0)
        return *this+=(-day);
    _day-=day;
    while (_day<=0)
    {
        _month--;
        _day+= GetMonthDay(_year,_month);
    }
    return *this;
}

Date &Date::operator++() {
    *this+=1;
    return *this;
}

Date Date::operator++(int) {
    Date tmp(*this);
    *this+=1;
    return tmp;
}

Date Date::operator--(int) {
    Date tmp(*this);
    *this-=1;
    return tmp;
}

Date &Date::operator--() {
    *this-=1;
    return *this;
}

bool Date::operator>(const Date &d) {
    if(this->_year>d._year)
        return true;
    else if(this->_year<d._year)
        return false;
    else
    {
        if(this->_month>d._month)
            return true;
        else if(this->_month<d._month)
            return false;
        else
        {
            if(this->_day>d._day)
                return true;
            else
                return false;
        }
    }

}

bool Date::operator==(const Date &d) {
    return (this->_year==d._year)&&(this->_month==d._month)&&(this->_day==d._day);
}

bool Date::operator>=(const Date &d) {
    return *this>d||*this==d;
}

bool Date::operator<(const Date &d) {
    return !(*this>=d);
}

bool Date::operator<=(const Date &d) {
    return !(*this>d);
}

bool Date::operator!=(const Date &d) {
    return !(*this==d);
}

int Date::operator-(const Date &d)
{
    Date bigger=*this;
    Date smaller=d;
    int flag=1;
    if(*this<d)
    {
        bigger=d;
        smaller=*this;
        flag=-1;
    }
    int n=0;
    while (smaller!=bigger)
    {
        smaller++;
        n++;
    }
    return n*flag;
}

