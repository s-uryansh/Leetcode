#include<iostream>
#include<map>
#include<string>
using namespace std;

#define log(x) cout<<x<<endl;

class Solution{
	public:
		int firstUniqChar(string s){
			map<char,int> uniqMap;
			for(int i = 0; i<s.length(); i++){
				uniqMap[s[i]]++;
			}
			for(int i =0;i<s.length();i++){
				if(uniqMap[s[i]] == 1){
					return i;
				}
			}
			return -1;
	}		
};

int main(){
	Solution s1;
	string s = "leetcodle";

	log(s1.firstUniqChar(s));

}
