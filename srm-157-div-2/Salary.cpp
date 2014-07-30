#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class Salary{
public:
    int howMuch(vector<string> arrival, vector<string> departure, int wage){
        long long mt = 0;//early morning time
        long long nt= 0;

        for(int i = 0; i<arrival.size(); i++){
            
           /* int times1 = atoi(s1.substr(0,2).c_str())*60*60 + atoi(s1.substr(3,2).c_str())*60 + atoi(s1.substr(6).c_str());
            int times2 = atoi(s2.substr(0,2).c_str())*60*60 + atoi(s2.substr(3,2).c_str())*60 + atoi(s2.substr(6).c_str());
            */
            int h1, m1, s1;
            int h2, m2, s2;
            sscanf(arrival[i].c_str(),"%d:%d:%d",&h1, &m1, &s1);
            sscanf(departure[i].c_str(),"%d:%d:%d",&h2, &m2, &s2);
            int times1 = s1+ m1*60 + h1*3600;
            int times2 = s2+ m2*60 + h2*3600;
            while(times1<21600&&times1<times2){
                mt++;
                times1++;
            }
            while(times1<=64799&&times1<times2){
                nt++;
                times1++;
            }
            while(times1<times2){
                mt++;
                times1++;
            }
        }
        return int(1.0*(mt*3+nt*2)/7200 * wage);
    }
};
