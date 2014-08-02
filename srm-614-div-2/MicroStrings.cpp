#include<iostream>
#include<string>
using namespace std;

class MicroStrings{
public:
    string makeMicroString(int a, int d){
        string res = "";
        while(a>0){
            res += to_string(a);
            a -= d;
        }
        return res;
    }
};
