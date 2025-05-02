#include<iostream>
#include<vector>

#define log(x) cout<<x<<endl;
using namespace std;

class Solution{
	public:
		int search(vector<int>& nums, int target){
			int result = 0;
			bool found = false;
			int i =0;
			while(!found && i <= (nums.size() - 1)){
				if(nums[i] == target){
					found = true;
					result = i;
				}else{
					i++;
				}
			}
			if(!found){
				return -1;
			}
			return result;
		}
};

int main(){
	vector<int> nums = {-1,0,3,5,9,12};
	int target = 9;

	Solution s;

	log(s.search(nums,target));
	return 0;
}
