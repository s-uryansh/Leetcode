#include<iostream>
#include<vector>

#define log(x) cout<<x<<endl;

using namespace std;

class Solution{
	public:
		int findMin(vector<int>& nums){
			int l = 0;
			int r = nums.size()-1;
			while(l<r){
				int m = l+(r-l) /2;
				if(nums[m] <  nums[r]){
					r = m;
				} else{
					l = m+1;
				}
			}
			return nums[l];	
		}
};

int main(){
	vector<int> nums = {3,4,5,1,2};
	Solution s;
	log(s.findMin(nums));
	return 0;
}
