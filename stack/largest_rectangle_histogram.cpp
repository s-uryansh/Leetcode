#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

#define log(x) cout<<x<<endl;

using namespace std;

class Solution{
	public:
		int largestRectangleArea(vector<int>& heights){
			int n = heights.size();
			vector<int>leftMost(n,-1);
			vector<int>rightMost(n,n);
			stack<int> stack;

			for(int i = 0 ; i < n ; i++){
				while(!stack.empty() && heights[stack.top()] >= heights[i]){
					stack.pop();
				}
				if(!stack.empty()){
					leftMost[i] = stack.top();
				}
				stack.push(i);
			}		
			while(!stack.empty()){
				stack.pop();
			}
			for(int i = n-1 ; i >= 0 ; i--){
				while(!stack.empty() && heights[stack.top()] >= heights[i]){
					stack.pop();
				}
				if(!stack.empty()){
					rightMost[i] = stack.top();
				}
				stack.push(i);
			}
			int maxArea = 0;
			for (int i = 0; i < n; i++) {
         			leftMost[i] += 1;
            			rightMost[i] -= 1;
            			maxArea = max(maxArea, heights[i] * (rightMost[i] - leftMost[i] + 1));
        		}
			return maxArea;
		}
};

int main(){
	vector<int> heights = {2,1,5,6,2,3};
	Solution s;
	int result = s.largestRectangleArea(heights);
	log(result);
	return 0;
}
