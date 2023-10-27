#include "Date.h"
void Date::print() const {
    printf("year:%d month:%d day:%d\n",_year,_month,_day);
}
int Date::GetMonthDay(int year, int month) {
    //�·����飬�±꼴Ϊ�·�
    const static int monthArray[]={
            0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    //���2�£���Ϊ����
    if(month==2&&((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
        return 29;
    }
    return monthArray[month];
}
//��ʼ�����캯��
Date::Date(int year, int month, int day) {
    _year=year;
    _month=month;
    _day=day;

    //����Ƿ���ȷ
    if((month<1||month>12)||day<1||day> GetMonthDay(year,month))
    {
        cout<<"�����·ݡ�����"<<endl;
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

// ��ֵ���������
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
        _day
    }
}

