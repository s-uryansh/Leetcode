#include<iostream>
#include<vector>
#include<algorithm>
#define log(x) cout << x << endl;

using namespace std;

class Solution{
    public:
        vector<int> twoSum(vector<int>& nums, int target){
            vector<pair<int,int>> arr;

            for(int i = 0; i < nums.size(); i++){
                arr.push_back({nums[i],i});
            }
            sort(arr.begin(), arr.end());
            int l = 0; int r = nums.size() -1;
            while(l < r){
                int sum = arr[l].first + arr[r].first;
                if(sum == target){
                    return{arr[l].second, arr[r].second};
                }else if(sum < target){
                    l++;
                }else{
                    r--;
                }
            }
            return { };
        }
};

int main(){
    vector<int> nums = {3,2,4};
    int target = 6;
    Solution s;
    vector<int> res = s.twoSum(nums, target);
    for(int i =0; i < res.size(); i++){
        log(res[i]);
    }

    return 0;
}