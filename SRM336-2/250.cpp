#include<iostream>
#include<string>
using namespace std;
        
class VowelLatin{
public:
    string translate(string word){
        string pre = "";	
        string end = "";
        string vowel = "aeiouAEIOU";
        for(int i = 0; i<word.length(); i++){
            char ch = word[i];
            if(vowel.find(ch)!=string::npos)
				end+=ch;
            else
                pre+=ch;
	}
        return pre+end;
    }
};
