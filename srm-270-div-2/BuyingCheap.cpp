#include<iostream>
#include<vector>
using namespace std;

class BuyingCheap{
public:
    int thirdBestPrice(vector<int> prices){
        if(prices.size()<3)
            return -1;
        int first = 1001;
        int second = 1001;
        int third = 1001;
        
        for(int i = 0; i<prices.size(); i++){
            if(prices[i]==first || prices[i]==second || prices[i]==third)
                continue;
            if(prices[i]<first){
                third = second;
                second = first;
                first = prices[i];
               cout<<"first"<<first<<" "<<second<<" "<<third<<endl;
            }
            else if(prices[i]<second){
                third = second;
                second = prices[i];
            }
            else if(prices[i]<third)
                third = prices[i];
        }
        return third!=1001?third:-1;
    }
};
