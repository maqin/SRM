#include<iostream>
#include<string>
using namespace std;

class TypingDistance{
public:
	int minDistance(string keyboard, string word){
		int board[256]={0};
		int r = 0;
		for(int i = 0; i<keyboard.length(); i++){
			int index = keyboard[i];
			board[index] = i;
		}
		for(int i = 1; i<word.length(); i++){
			int pre = word[i-1];
			int next = word[i];
			r += (board[next]>board[pre])? board[next]-board[pre]: board[pre]-board[next];
		}
		return r;
	}
};
