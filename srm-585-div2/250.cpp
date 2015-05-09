#include<iostream>
#include<vector>
using namespace std;

class LISNumberDivTwo{
public:
	int calculate(vector<int>  seq){
		int cnt = 1;
		for(int i = 1; i<seq.size(); i++)
			if(seq[i]<=seq[i-1]) cnt++;
		return cnt;
	}
};
