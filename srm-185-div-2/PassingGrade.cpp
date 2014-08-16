#include<iostream>
#include<vector>
using namespace std;

class PassingGrade{
public:
    int pointsNeeded(vector<int> pointsEarned,vector<int> pointsPossible, int finalExam){
        double sumpoint = finalExam;
        for(int i = 0; i<pointsPossible.size(); i++)
            sumpoint += pointsPossible[i];
        sumpoint *= 0.65;
        for(int i = 0; i<pointsEarned.size(); i++)
            sumpoint -= pointsEarned[i];
        //double res = 1.0*sumpoint/100 + 0.5;
        int result = (int)(sumpoint+0.9999);
        if(result>finalExam) return -1;
        if(result<=0) return 0;
        return result;
    }
};
