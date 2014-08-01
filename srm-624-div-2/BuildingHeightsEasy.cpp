#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

class BuildingHeightsEasy{
public:
    int minimum(int M, vector<int> heights){
        if(M<=1) return 0;
        sort(heights.begin(),heights.end());
        int same = 1;
        int res = INT_MAX;
        for(int i = 1; i<heights.size(); i++){
            if(heights[i]==heights[i-1])
                same ++;
            else
                same = 1;
            
            if(same == M)
                return 0;
            
            if(i>=M-1){
                cout<<i<<endl;
                int d = 0;
                int loop = i;
                int n = M;
                while(n>0){
                    d += (heights[i]-heights[loop]);
                    loop--;
                    n--;
                }
                //int d = heights[i]-heights[i-2]+heights[i]-heights[i-1];
                res = min(res,d);
            }
        }
        return res;
    }
};
