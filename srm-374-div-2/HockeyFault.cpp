#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

class HockeyFault{
public:
    bool circle(int px, int py, double cx, double cy, double radius){
        double x = (px-cx)*(px-cx);
        double y = (py-cy)*(py-cy);
        double r = sqrt(x+y);
        if(r<=radius)
            return true;
        else
            return false;
    }
    int numPlayers(int width, int height, int x, int y, vector<int> px, vector<int> py){
        int res = 0;
        double p1x = x, p1y = y+height/2;
        double p2x = x+width, p2y = y+height/2;
        
        for(int i = 0; i<px.size(); i++){
            if(circle(px[i],py[i], p1x, p1y, height/2)||circle(px[i],py[i],p2x, p2y,height/2))
                res ++;
            else if((px[i]>=x && px[i]<=x+width)&&(py[i]>=y&&py[i]<=y+height))
                res ++;
        }
        return res;
    }
};
