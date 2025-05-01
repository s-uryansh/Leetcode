#include<iostream>
#include<string>
#include<unordered_map>

#define log(x) cout << (x ? "true" : "false") << endl;

using namespace std;

class Solution{
	public:
		bool areMapEqual(unordered_map<char , int>& map1 , unordered_map<char , int>& map2){
			if(map1.size() != map2.size()){
				return false;
			}

			for(const auto& pair: map1){
				char ch = pair.first;
				int count = pair.second;

				if(map2.find(ch) == map2.end() || map2.at(ch) != count){
					return false;
				}
			}
			return true;
		}

		bool isAnagram(string s , string t){
			unordered_map<char , int> charFreq1;
			unordered_map<char , int> charFreq2;
			for(char ch : s){
				charFreq1[ch]++;
			}
			for(char ch : t){
				charFreq2[ch]++;
			}

			return areMapEqual(charFreq1 , charFreq2);
						
		}
};

int main(){
	string s = "car";
	string t = "rat";
	Solution so;

	bool sol = so.isAnagram(s , t);
	log(sol);
}
