#include<iostream>
#include<vector>
#include<unordered_set>

#define log(x) cout<<x<<endl;
using namespace std;

class Solution{
	public:
		int longestConsecutive(vector<int>& nums){
			int result = 0;
			unordered_set<int> numSet(nums.begin() , nums.end());
			for(int num : numSet){
				if(numSet.find(num-1) == numSet.end()){
					int length = 1;
					while(numSet.find(num + length) != numSet.end()){
						length++;
					}
					result = max(result , length);
				}
			}
			return result;
		}
};

int main(){
	vector<int> nums = {100 ,  200 , 1 , 3 , 2};

	Solution s;

	int longestConsec = s.longestConsecutive(nums);
	log(longestConsec);

	return 0;
}
