#include<iostream>
using namespace	std;

class GuessTheNumber{
public:
    int	noGuesses(int upper, int answer){
        int lower = 1;
        int res = 0;
        while(true){
            res ++;
            int mid = (lower+upper)/2;
            if(mid == answer)
	        break;
            if(mid > answer)
	        upper = mid-1;
            if(mid < answer)
	        lower = mid+1;
        }
        return res;
    }
};
