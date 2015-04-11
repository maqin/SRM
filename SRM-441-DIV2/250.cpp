#include<string>
#include<iostream>

using namespace std;

class DifferentStrings{
	public:
		int minimize(string A, string B){
			int n1 = A.length();
			int n2 = B.length();
			int m = n2;
			for(int i = 0; i<=n2-n1; i++){
				int t = 0;
				for(int j = 0; j<n1; j++){
					if(A[j]!=B[i+j])
						t++;
				}
				m = min(m,t);
			}
			return m;
		}
};
