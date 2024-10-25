#include"KJSon.h"
#include<iostream>
#include <fstream>

class JsonServer{
public:
    void Init(const std::string& file) {
        std::string str;
        KJSon::ReadJsonFile(file,str);
        KJSon::Parser(str,m_kjson);

    }
    void Loop(){
        std::string input;
        while(1){
            usage();
            std::getline(std::cin,input);
            Execute(input);
//            std::cout<<input<<std::endl;

        }
    }
    void close(){
        std::ofstream ofs(R"(D:\BITE\jsondeserialize\out.json)",std::ios::binary|std::ios::out);
        if(!ofs.is_open()){
            std::cout<<"file open failure\n";
            return;
        }
        ofs<<m_kjson;
        ofs.close();
    }
private:
    KJSon m_kjson;

    void usage(){
        std::cout<<"ʹ��˵����\n  key1 key2 ...(�ո�ָ�keyֵ)"<<std::endl;
        std::cout<<"please enter#";
    }
    //ִ������
    void Execute(std::string& str){
        //��������
        std::vector<std::string>cmds;
        Desrialize(str,cmds);
        //ִ����������������´�����
        KJSon temp = m_kjson;
        for(auto&e:cmds){
            ExecuteOneCmd(e,&temp);
        }

    }
    void Desrialize(const std::string& str,std::vector<std::string>&cmds);

    void ExecuteOneCmd(std::string&cmd,KJSon*kjson);
};

void JsonServer::Desrialize(const std::string &str, std::vector<std::string> &cmds) {

    std::string temp;
    for (char c :str) {
        if (c == ' ') {
            if (!temp.empty()) {
                cmds.push_back(temp);
                temp = "";
            }
        } else {
            temp += c;
        }
    }
    if (!temp.empty()) {
        cmds.push_back(temp);
    }
}

void JsonServer::ExecuteOneCmd(std::string &cmd, KJSon *kjson) {
    if(std::)
}


int main(){
    JsonServer jsonServer;
    jsonServer.Init(R"(D:\BITE\jsondeserialize\input.json)");


    jsonServer.Loop();
    jsonServer.close();




    return 0;
}