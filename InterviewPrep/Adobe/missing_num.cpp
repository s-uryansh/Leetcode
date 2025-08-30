#include<iostream>
#include<vector>
#define log(x) cout<< x << endl;

using namespace std;

class Solution{
    public:
        int missingNumber(vector<int>& nums){
            int n = nums.size(), totalSum = (n * (n+1))/ 2, sum = 0;
            for(int i = 0; i < nums.size(); i++){
                sum += nums[i];
            }
            return totalSum - sum;
        }
};

int main(){
    vector<int> nums = {0,1};
    Solution s;
    log(s.missingNumber(nums));
    return 0;
}