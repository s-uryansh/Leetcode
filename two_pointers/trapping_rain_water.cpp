#include<iostream>
#include<vector>

#define log(x) cout<<x<<endl;

using namespace std;

class Solution{
	public:
		int trap(vector<int>& height){
			int result = 0;
			if(height.empty()){
				return 0;
			}

			int left = 0; 
			int right = height.size() - 1;
			int leftH = height[left];
			int rightH = height[right];

			while(left < right){
				if(leftH < rightH){
					left++;
					leftH = max(leftH , height[left]);
					result += leftH - height[left];
				}else{
					right--;
					rightH = max(rightH , height[right]);
					result += rightH - height[right];
				}
			}
			return result;
		}
};
int main(){
	vector<int> height = {4,2,0,3,2,5};
//	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
	Solution s;

	log(s.trap(height));
	return 0;
}
