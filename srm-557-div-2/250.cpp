#include<iostream>
#include<vector>
using namespace std;

class GreatFairyWar{
public:
	int minHP(vector<int> dps, vector<int> hp){
		int res = 0;
		int cur_val=0;
		for(int i = dps.size()-1; i>=0; i--){
			cur_val += dps[i];
			res += hp[i]*cur_val;
		}
		return res;
	}
};
