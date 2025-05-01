#include<iostream>
#include<vector>
#include<unordered_map>

#define log(x) cout << x << endl;

using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int>& numbers, int target){
			vector<int> result;
			unordered_map<int,int> numMap;
			for(int i = 0 ; i < numbers.size() ; i++){
				int complement = target - numbers[i];
				if(numMap.find(complement) != numMap.end()){
					result.push_back(numMap[complement] + 1);
					result.push_back(i + 1);
					return result;
				}
				numMap[numbers[i]] = i;
			}
			return result;
		}
};

int main(){
	vector<int> numbers = {-1,0};
	int target = -1;

	Solution s;
	vector<int> result = s.twoSum(numbers,target);
	for(int i = 0 ; i < result.size() ; i++){
		log("Element " << i << ": "<<result[i]);
	}

	return 0;
}
