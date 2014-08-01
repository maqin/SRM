#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class CostOfDancing{
public:
    int minimum(int K, vector<int> danceCost){
        priority_queue<int> pq;
        for(int i = 0; i<danceCost.size(); i++){
            pq.push(danceCost[i]);
            if(pq.size()>K)
                pq.pop();
        }
        int res = 0;
        
        while(!pq.empty()){
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};
