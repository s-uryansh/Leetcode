#include<iostream>
#include<vector>
#include<algorithm>

#define log(x) cout << x << endl;
using namespace std;

class Solution{
public:
	bool isSum(int i ,int j , int k){
		return i+j+k == 0;
	}
	vector<vector<int>> threeSum(vector<int>& nums){
		vector<vector<int>> result;
		int size = nums.size();
		sort(nums.begin() , nums.end());
		for(int i = 0 ; i < size -2 ; i++){
			if(i>0 && nums[i] == nums[i-1]){
				continue;
			}
			int left = i+1;
			int right = size-1;
			while(left < right){
				if(isSum(nums[i] , nums[left] , nums[right])){
					result.push_back({nums[i] , nums[left] , nums[right]});
					while(left < right && nums[left] == nums[left+1]){
						left++;
					}
					while(left < right && nums[right] == nums[right-1]){
						right--;
					}
					left++;
					right--;
				}else if((nums[i] + nums[left] + nums[right]) < 0){
					left++;
				}else{
					right--;
				}
			}
		}
        return result;
    }
};

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
	Solution s;
	vector<vector<int>> result = s.threeSum(nums);

	for(const auto& row : result){
		for(int val: row){
			log(val << " ");
		}
		log("");
	}
}