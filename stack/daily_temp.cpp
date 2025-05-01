#include<iostream>
#include<stack>
#include<vector>

#define log(x) cout<<x<<endl;

using namespace std;

class Solution{
	public:
	vector<int> dailyTemperatures(vector<int>& temperatures){
		int size = temperatures.size();
		vector<int> result(size,0);
		stack<int> days;
		for(int i = 0 ; i < size ; i++){
			while(!days.empty() && temperatures[i] > temperatures[days.top()]){
				int index = days.top();
				days.pop();
				result[index] = i - index;
			}
			days.push(i);
		}
		return result;
	}	
};

int main(){
	vector<int>temps = {30,60,90};

	Solution s;

	vector<int> temp = s.dailyTemperatures(temps);

	for(int i = 0; i < temp.size(); i++){
		log(temp[i]);
	}
}
