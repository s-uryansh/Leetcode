#include<iostream>
#include<vector>

#define log(x) cout<<x<<endl;

using namespace std;

class Solution{
	public:
		int search(vector<int>& nums,int target){
			int l = 0;
			int r = nums.size() - 1;
			while(l < r){
				int k = (l+r)/2;
				if(nums[k] > nums[r]){
					l = k + 1;
				}else{
					r = k;
				}
			}
			int pivot = l;
			int result = binarysearch(nums,target,0,pivot-1);
			if(result != -1){
				return result;
			}
			return binarysearch(nums,target,pivot,nums.size()-1);
		}
		int binarysearch(vector<int>& nums, int target,int l, int r){
			while(l <= r){
				int k = (l+r)/2;
				if(nums[k] == target){
					return k;
				}else if(nums[k] < target){
					l = k + 1;
				}else{
					r = k - 1;
				}
			}
			return -1;
		}
};
int main(){

	vector<int> nums = {4,5,6,7,0,1,2};
	int target = 4;
	Solution s;
	log(s.search(nums,target));
}
