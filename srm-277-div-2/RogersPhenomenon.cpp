#include<iostream>
#include<vector>
using namespace std;

class RogersPhenomenon{
public:
    int count(double big, double small, vector<int> &set){
        int sum = 0;
        for(int i = 0; i<set.size(); i++)
            sum += (set[i]>small&&set[i]<big)?1:0;
        return sum;
    }
    
    int countTriggers(vector<int> set1, vector<int> set2){
        
        double average1 = 0;
        double average2 = 0;
        for(int i = 0; i<set1.size(); i++)
            average1 += set1[i];
        average1 /= set1.size();
        //cout<<average1<<endl;
        for(int i = 0; i<set2.size(); i++)
            average2 += set2[i];
        average2 /= set2.size();
        //cout<<average2<<endl;
        int res = 0;
        if(average1>average2){
            if(set1.size()<2)
                return 0;
            res = count(average1,average2,set1);
        }
        else if(average1<average2){
            if(set2.size()<2)
                return 0;
            res = count(average2,average1,set2);
        }
        
        return res;
    }
};
