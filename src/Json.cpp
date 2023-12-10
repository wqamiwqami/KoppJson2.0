#include "KoppJson.h"
#include <iostream>
#include <fstream>
#include <string>  

namespace Kopp{

KoppValue* Json::StrToJson (const std::string& str){
    KoppJson json;
    json.setJsonStr(str);
    int ret = json.BuildJson();

    if(ret != KOPP_PARSE_OK){
        std::cerr<<("[Error] Error Code is "+std::to_string(ret)+"! Parse Failed in \n |  "+json.get_error_str()+"  |\n")<<std::endl;
        return nullptr;
    }
    return json.VAL;
};

std::string Json::JsonToStr (KoppValue& val , bool hasLevel){
    return val.get_str(hasLevel);
};

KoppValue* Json::ReadJsonFile (const std::string& path){
    std::fstream file;
    file.open(path);
    if(!file.is_open()){
        std::cerr<< "[ERROR] Open Json File Error! Check Your Path.\n";
    }
    std::string str;
    std::getline(file , str , '\0');
    return (Json::StrToJson(str));
};

void Json::SaveJsonFile (KoppValue& val , const std::string& path , bool hasLevel){
    std::fstream file;
    file.open(path , std::ios::out);
    if(!file.is_open()){
        std::cerr<< "[ERROR] Open Save File Error!\n";
        return;
    }
    // file<<val.get_str(hasLevel);
    file.close();
};

}