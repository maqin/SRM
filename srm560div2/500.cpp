#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class TomekPhone{
public:
    int minKeystrokes(vector<int> frequencies, vector<int> keySizes){
        int p = 1;
        int res = 0;
        int f = 0;
        sort(frequencies.begin(), frequencies.end(),greater<int>());
        while(true){
            bool has_space = false;
            for(int i = 0; i<keySizes.size(); i++){
                if(keySizes[i]>=p){
                    res += frequencies[f++]*p;
                    has_space = true;
                    if(f>=frequencies.size())
                        return res;
                }
            }
            if(!has_space)
                return -1;
            p++;
        }
        return res;
    }
};
