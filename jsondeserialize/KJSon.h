#pragma once
#include<string>
#include<vector>
#include<unordered_map>

enum TYPE{//对象值类型标注
    NOTDINE=-1, //未定义
    NUM=0,      //数字
    STR,        //字符串
    BOOL,       //逻辑
    ARR,        //数组
    OGJ,        //对象
};

class KJSon{
public:
    //读取字符串
    static bool ReadJsonFile(const std::string& filepath,std::string&str);
    //解析字符串
    static bool Parser(const std::string&str,KJSon&kjson);

private:
    //解析函数
    static KJSon parse();
    static KJSon parseObj();
    static KJSon parseBool();
    static KJSon parseStr();
    static KJSon parseNum();
    static KJSon parseArr();

public:
    //构造
    KJSon();
    KJSon(const KJSon&kjson);
    KJSon& operator=(const KJSon&kjson);
    ~KJSon();
    //根据类型初始化
    KJSon(const double num);
    KJSon& operator=(const double &num);
    KJSon(const std::string& str);
    KJSon& operator=(const std::string& str);
    explicit KJSon(bool boolen);
     KJSon& operator=(bool boolen);

    //当kjson为对象时添加/修改数据函数
    KJSon& operator[](const std::string& key);
    //kjson为数组时添加数据
    bool append(const KJSon&kjson);

    //输出函数
    friend std::ostream& operator<<(std::ostream& os,const KJSon&);

    //obj  --   检测key是否存在函数
    std::pair<bool,const KJSon*const> isExist(std::string &key);
    std::pair<bool,const KJSon*const> isExist(unsigned int pos);
private:
    TYPE m_type;     //标识类型
    struct VAL
    {
        double                                 m_num;
        std::string                            m_str;
        bool                                   m_bool;
        std::vector<KJSon>                     m_arr;
        std::unordered_map<std::string,KJSon>  m_obj;
        VAL(){}
        VAL& operator=(const VAL&val)=default;
        ~VAL(){}
    } m_val;        //内容
};


