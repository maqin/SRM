#include<iostream>
using namespace std;

class FibonacciDiv2{
public:
    int find(int n){
        int a = 0;
        int b = 1;

        while(b<n){
            
            int c = a+b;
            a = b;
            b = c;
        }
        return min(n-a, b-n);
    }
};
