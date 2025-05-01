#include<iostream>
#include<string>
#include<vector>
#include<stack>

#define log(x) cout << x << endl;

using namespace std;

struct State{
	string current;
	int open;
	int close;
};

class Solution{
	public:
		vector<string> generateParenthesis(int n){
			vector<string> generatedBracks;
			stack<State> stk;
			stk.push({"",0,0});
			while(!stk.empty()){
				State s = stk.top();
				stk.pop();

				if(s.open == n && s.close == n){
					generatedBracks.push_back(s.current);
					continue;
				}
				if(s.open < n){
					stk.push({s.current + "(" , s.open + 1, s.close});
				}
				if(s.close < s.open){
					stk.push({s.current + ")" , s.open , s.close + 1});
				}
			}
			return generatedBracks;
		}
};

int main(){
	int n = 3;
	Solution s;

	vector<string> bracks = s.generateParenthesis(n);
	for(int i = 0 ; i < bracks.size() ; i++){
		log(bracks[i]);
	}
	return 0;
}
