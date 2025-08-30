#include<iostream>
#include<vector>
#define log(x) coout << x << endl;

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        
    }
    
    void update(int index, int val) {
        
    }
    
    int sumRange(int left, int right) {
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main(){
    vector<int> nums = {1,3,5};
    int left = 0;
    int right = 2;
    int index = 1;
    int val = 2;

    NumArray* obj = new NumArray(nums);
    obj->update(index,val);
    int param_2 = obj->sumRange(left,right);
    

    return 0;
}