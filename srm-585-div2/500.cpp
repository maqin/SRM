#include<iostream>
using namespace std;

class TrafficCongestionDivTwo{
public:
	long long theMinCars(int treeHeight){
		if(treeHeight==0) return 1;
		if(treeHeight==1) return 1;
		if(treeHeight%2==0) return 1+2*theMinCars(treeHeight-1);
		else return 1+4*theMinCars(treeHeight-2);
	}
};
