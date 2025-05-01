#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
#define log(x) cout<<x<<endl;

class Solution{
	public:
		vector<vector<string>> groupAnagrams(vector<string>& strs) {
			unordered_map<string,vector<string>> anagramMap;
			for(const auto& str: strs){
				string sortedStr= str;
				sort(sortedStr.begin(),sortedStr.end());
				anagramMap[sortedStr].push_back(str);
			}
			vector<vector<string>> anagramVector;
			for(auto& group: anagramMap){
				anagramVector.push_back(group.second);
			}
			return anagramVector;
		}
};

int main(){
	Solution sol;
	vector<string> s = {"eat","tea","tan","ate","nat","bat"};
	
	vector<vector<string>> groupedAnagram = sol.groupAnagrams(s);
	
	for(const auto& grp: groupedAnagram){
		for(const string& str: grp){
			cout<<str<<" ";
		}
	cout<<endl;
	}
	return 0;
}
