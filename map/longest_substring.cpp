#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
//wrong
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> lolSubMap;
        int length=0 ;
	int start= 0 ;
	for(int i=0 ; i<s.size();i++){
		char ch = s[i];
		if(lolSubMap.count(ch) && lolSubMap[ch] >= start){
			start = lolSubMap[ch] + 1;
		}

		lolSubMap[ch] = i;
		length = max(length , i-start+1);
	}
	return length ;
    }
};

int main(){
	Solution s;
	string s1 ="pwwkew"; 
	int length = s.lengthOfLongestSubstring(s1);
	cout<<length<<endl;
}
