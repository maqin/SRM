#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class WinterAndMandarins{
public:
    int getNumber(vector<int> bags, int k){
        sort(bags.begin(),bags.end());
        int dif = INT_MAX;;
        for(int i = k-1; i<bags.size(); i++){
            int t = 0;
            int loop = k-1;
            int j = i;
            while(loop--){
                t += (bags[j]-bags[j-1]);
                j--;
            }
            dif = min(dif, t);
        }
        return dif;
    }
};
