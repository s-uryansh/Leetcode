#include<iostream>
#include<vector>
#include<string>
#include<stack>

#define log(x) cout<<x<<endl;

using namespace std;

class Solution{
	public:
		int cal(int a, int b, char operand){
			int result;
			switch(operand){
				case '+':
					result = a + b;
					break;
				case '*':
					result = a * b;
					break;
				case '-':
					result = b - a;
					break;
				case '/':
					if(a == 0 || b == 0){
						result = 0;
						break;
					}
					result = b/a;
					break;
			}
			return result;
		}
		int evalRPN(vector<string>& tokens){
			stack<int> stkChar;
			for(const string& c : tokens){
				if(c == "+" || c == "-" || c == "*" || c == "/"){
					char operand = c[0];
					int temp1 = stkChar.top();
					stkChar.pop();
					int temp2 = stkChar.top();
					stkChar.pop();
			//		log("Calculation of: " << temp1 << " " << temp2 << " " << operand);
					int result = cal(temp1,temp2,operand);
					stkChar.push(result);
				}else{
					int num = stoi(c);
					//log("pushing: " << num);
					stkChar.push(num);
				}
			}
			return stkChar.top();
		}
};

int main(){
	vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
//	vector<string> tokens = {"18"};
	Solution s;


	int result = s.evalRPN(tokens);
	log("Final result: "<<result);
	return 0;
}
