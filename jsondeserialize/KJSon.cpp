#include"KJSon.h"
#include<iostream>
#include <sstream>
#include <fstream>

KJSon::KJSon():m_type(TYPE::NOTDINE){}

KJSon::KJSon(const KJSon&kjson):m_type(kjson.m_type){
    m_val = kjson.m_val;
}

KJSon& KJSon::operator=(const KJSon&kjson) =default;

KJSon::~KJSon(){
    m_type = TYPE::NOTDINE;
}

KJSon::KJSon(const double num){
    m_type = TYPE::NUM;
    m_val.m_num = num;
}
KJSon::KJSon(const std::string& str){
    m_type = TYPE::STR;
    m_val.m_str = str;
}
KJSon::KJSon(const bool boolen){
    m_type = TYPE::BOOL;
    m_val.m_bool = boolen;
}

KJSon& KJSon::operator[](const std::string& key){
    //还未进行定义
    if(m_type==TYPE::NOTDINE){
        m_type = TYPE::OGJ;
        m_val.m_obj = std::unordered_map<std::string,KJSon>();

    }
    //检查是否为对象类型
    if(m_type!=TYPE::OGJ){
        std::cout<<"insert denied\n";
        exit(1);
    }
    return m_val.m_obj[key];
}

KJSon &KJSon::operator=(const double &num) {
    m_type = TYPE::NUM;
    m_val.m_num = num;
    return *this;
}

KJSon &KJSon::operator=(const std::string &str) {
    m_type = TYPE::STR;
    m_val.m_str=str;
    return *this;
}

KJSon &KJSon::operator=(bool boolen) {
    m_type = TYPE::BOOL;
    m_val.m_bool = boolen;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const KJSon&kjson) {
    if(kjson.m_type==TYPE::NUM){
        os<<kjson.m_val.m_num;
    }
    if(kjson.m_type==TYPE::STR){
        os<<'\"'<<kjson.m_val.m_str<<'\"';
    }
    if(kjson.m_type==TYPE::BOOL){
        os<<(kjson.m_val.m_bool ? "true" : "false");
    }
    if(kjson.m_type==TYPE::ARR){
        os<<'[';
        for(auto it = kjson.m_val.m_arr.begin();it!=kjson.m_val.m_arr.end();){
            os<<*it;
            if(++it!=kjson.m_val.m_arr.end())
                os<<',';
        }
        os<<']';
    }
    if(kjson.m_type==TYPE::OGJ){
        os<<'{';
        for(auto it = kjson.m_val.m_obj.begin();it!=kjson.m_val.m_obj.end();){
            os<<'"'<<it->first<<"\":"<<it->second;
            if(++it!=kjson.m_val.m_obj.end())//避免最后一个值后产生逗号，
                os<<',';
        }
        os<<'}';
    }
    return os;
}

bool KJSon::append(const KJSon &kjson) {
    if(kjson.m_type==TYPE::NOTDINE) { return false; }

    if(m_type==TYPE::NOTDINE){
        m_type = TYPE::ARR;
        m_val.m_arr = std::vector<KJSon>();
    }
    m_val.m_arr.push_back(kjson);
    return true;
}

bool KJSon::ReadJsonFile(const std::string& filepath, std::string &str) {
    std::ifstream inputfile;
    inputfile.open(filepath);
    if(!inputfile.is_open()){
        std::cout<<"file open failure"<<std::endl;
        return false;
    }
    std::stringstream ss;
    ss<<inputfile.rdbuf();
    inputfile.close();
    str = ss.str();
    return true;
}
static std::stringstream ss;
bool KJSon::Parser(const std::string &str, KJSon &kjson) {

    ss.clear();
    ss<<str;
    kjson = parse();
    return true;
}
KJSon KJSon::parse() {
    while (ss.peek() != -1) {
        //这些字符直接跳过
        if (ss.peek() == ' ' || ss.peek() == '\n' || ss.peek() == '\t')
            ss.get();
        else if (ss.peek() == '"') {//遇到字符串
            return parseStr();
        }
        else if (ss.peek() == 'f' || ss.peek() == 't') {
            return parseBool();
        }
        else if (ss.peek() == '[') {
            return  parseArr();
        }
        else if (ss.peek() == '{') {//遇到字典对象
            return parseObj();
        }
        else {
            return parseNum();
        }
    }
    return 0;
}

KJSon KJSon::parseObj() {
    ss.get();
    KJSon dict;
    dict.m_type = TYPE::OGJ;
    while (ss.peek() != '}') {
        KJSon key = parse();
        while (ss.peek() == ' ' || ss.peek() == ':')
            ss.get();
        KJSon val = parse();
        dict[key.m_val.m_str] = val;
        while (ss.peek() != '}' && (ss.peek() == ' ' || ss.peek() == '\t' || ss.peek() == '\n' || ss.peek() == ','))
            ss.get();
    }
    ss.get();
    return dict;
};

KJSon KJSon::parseBool() {
    if (ss.peek() == 'f') {
        //移动到false后面
        ss.get(); ss.get(); ss.get(); ss.get(); ss.get();
        return KJSon(false);
    }
    else {
        //true后面
        ss.get(); ss.get(); ss.get(); ss.get();
        return KJSon(true);
    }
}

KJSon KJSon::parseStr() {
    ss.get();
    std::string s;
    while (ss.peek() != '"')
        s.push_back(ss.get());
    ss.get();
    return KJSon(s);
}

KJSon KJSon::parseNum() {
    std::string s;
    while (isdigit(ss.peek()) || ss.peek() == 'e' || ss.peek() == '-' || ss.peek() == '.')
        s.push_back(ss.get());
    return KJSon(20.0);
}

KJSon KJSon::parseArr() {
    //移动到  '['
    ss.get();
    KJSon vec;
    vec.m_type = TYPE::ARR;
    while (ss.peek() != ']') {
        vec.append(parse());
        while (ss.peek() != ']' && (ss.peek() == ' ' || ss.peek() == '\t' || ss.peek() == '\n' || ss.peek() == ','))
            ss.get();
    }
    ss.get();
    return vec;
}

std::pair<bool,const KJSon*const> KJSon::isExist(std::string &key) {
    if(m_type==TYPE::OGJ)
        if(m_val.m_obj.find(key)!=m_val.m_obj.end()){
            return std::make_pair(true, &m_val.m_obj[key]);
        }
    return std::make_pair(false, nullptr);
}

std::pair<bool,const KJSon*const> KJSon::isExist(unsigned int pos) {
    if(m_type==TYPE::ARR){
        if(pos<m_val.m_arr.size())
            return std::make_pair(true,&m_val.m_arr[pos]);
    }
    else
        return std::make_pair(false, nullptr);
}


