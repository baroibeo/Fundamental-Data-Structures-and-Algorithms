/*
Generate 10000 integers to test run time of some sorting algorithms
*/
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include "config.h"

using namespace std;

int main(){
    fstream myfile;
    myfile.open("data.txt",ios::out);
    for(int i = 0;i<NUM;i++){
        myfile<<to_string(rand()%NUM)<<endl;
    }
    myfile.close();
    return 0;
}