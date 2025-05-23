#include<iostream>
#include<stack>
#include<string>
#define log(x) cout << x << endl;

using namespace std;

class Solution{
	public:
		bool isValid(string s){
			stack<char> stk;
			
			for(char c: s){
				if(c == '(' || c == '[' || c == '{'){
					stk.push(c);
				}else {
					if(stk.empty()) return false;
					char top = stk.top();
					stk.pop();

					if( (c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[') ){
						return false;
					}
				}
			}
			return stk.empty();
		}
};

int main(){
	Solution s;

	string str = "(})";
	bool validOrNot = s.isValid(str);
	log(validOrNot);
}
