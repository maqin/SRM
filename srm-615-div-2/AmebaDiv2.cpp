#include<iostream>
#include<vector>
using namespace std;

class AmebaDiv2{
public:
    int simulate(vector<int> x, int a){
        for(int i = 0; i<x.size(); i++)
            if(x[i]==a)
                a += x[i];
        
        return a;
    }
};
