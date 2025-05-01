#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
	unordered_map<int , int> numMap;
	for(int i =0 ; i<nums.size(); i++){
		if(numMap.find(nums[i]) != numMap.end()){
				return true;
				}
			numMap[nums[i]] = i;
		}
		return false;
	}
};

int main(){
	vector<int> nums = {1,2,3,4};
	Solution s;
	bool isDup = false;
	isDup =s.containsDuplicate(nums);
	if(isDup==false){
		cout<<"false"<<endl;
	}else{
		cout<<"true"<<endl;

	}
}
