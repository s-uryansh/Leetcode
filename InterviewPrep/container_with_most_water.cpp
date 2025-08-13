#include<iostream>
#include<vector>

#define log(x) cout << x << endl;
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int size = height.size();
        int j = size - 1;
        bool iSmall = false;
        for (int i = 0; i < size; i++) {
            iSmall = false;
            while (!iSmall && j >= 0) {
                int ar = (j - i) * min(height[i], height[j]);
                if (ar > maxArea) {
                    maxArea = ar;
                }
                if (height[i] < height[j]) {
                    iSmall = true;
                } else {
                    j--;
                }
            }
        }
        return maxArea;
    }
};

int main(){
    Solution s;
    vector<int> vec = {1,8,6,2,5,4,8,3,7};
    log(s.maxArea(vec));
    return 0;  
}