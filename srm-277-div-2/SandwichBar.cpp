#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;

class SandwichBar{
public:
    int whichOrder(vector<string> available, vector<string> orders){
        set<string> toppings;
        for(int i = 0; i<available.size(); i++)
            toppings.insert(available[i]);

        for(int i = 0; i<orders.size(); i++){
            string target = orders[i];
            target += " ";
            string s = "";
            for(int j = 0; j<target.length(); j++){
                if(target[j]==' '){
                    if(toppings.find(s)==toppings.end())
                        break;
                    s = "";
                }else
                    s.push_back(target[j]);
                if(j==target.length()-1)
                    return i;
            }
        }
        return -1;
    }
};
