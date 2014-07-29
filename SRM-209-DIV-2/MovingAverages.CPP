#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
using namespace std;

class MovingAverages{
public:
    
    int timeChange(string time){
        string s1 = time.substr(0,2);
        string s2 = time.substr(3,5);
        string s3 = time.substr(6);
        int hh = atoi(s1.c_str());
        int mm = atoi(s2.c_str());
        int ss = atoi(s3.c_str());
        return  hh*60*60 + mm*60+ ss;
    }
    
    vector<int> calculate(vector<string> times, int n){
        vector<int> res;
        for(int i = 0; i<=times.size()-n; i++){
            int sum = 0;
            for(int j = i; j<n+i; j++)
                sum += timeChange(times[j]);
            res.push_back(sum/n);
        }
        return res;
    }
};
