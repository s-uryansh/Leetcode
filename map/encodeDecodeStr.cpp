#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

std::string CryptKey = "k"; // or any int works as well

using namespace std;

class Solution{
	public:
		string xorCrypt(const string& str){
			string output = str;
			for(size_t i = 0; i < str.size() ; ++i){
				output[i] ^= CryptKey[0];
			}
			return output;
		}

		string encode(vector<string>& strs){
			if(strs.empty()){
				return "";
			}
			string result;
			unordered_map<string , string> strCrypt; // map will contain string in first and encrypted in second
			bool isFirst = true;
			for(const auto& s : strs){
				if(s.empty()){
					continue;
				}
				string encryptedStr = xorCrypt(s);
				strCrypt[s] = encryptedStr;

				if(!isFirst){
					result += "+";	
				}
				result += encryptedStr;
				isFirst = false;
			}
			return result;
		}

		vector<string> decode(string s){
			vector<string> result;
			if(s.empty()){
				return result;
			}
			string currentWord;

			for(char c : s){
				if(c == '+'){
					result.push_back(xorCrypt(currentWord));
					currentWord.clear();
				}else{
					currentWord += c;
				}
			}

			if(!currentWord.empty()){
				result.push_back(xorCrypt(currentWord));
			}else{
				result.push_back("");
			}
			return result;
		}
};

int main(){
	vector<string> strs =/*{"neet" , "code", ""  , "love" , "you"}*/ {""};

	Solution s;

	string encodedStr = s.encode(strs);
	for(const auto & s : encodedStr){
		cout << (int)s << " ";
	}
	cout << endl;

	vector<string> decodedVector = s.decode(encodedStr);
	
	for(const auto& s : decodedVector){
		cout << s << " ";
	}

	return 0;
}
