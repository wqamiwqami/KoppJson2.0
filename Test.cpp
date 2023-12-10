#include<iostream>
#include<fstream>
#include<functional>
#include <chrono>
#include"include/KoppJson.h"

using namespace std ;
using namespace Kopp;

int main(){

    cout<<"Hello world"<<endl;

    auto now = std::chrono::high_resolution_clock::now();
    auto nowms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();

    auto val = (Kopp::Json::ReadJsonFile("../json/china.json"));

    auto now2 = std::chrono::high_resolution_clock::now();
    auto nowms2 = std::chrono::duration_cast<std::chrono::milliseconds>(now2.time_since_epoch()).count();

    printf("Use Time: %ld ms\n",(nowms2 - nowms));

}