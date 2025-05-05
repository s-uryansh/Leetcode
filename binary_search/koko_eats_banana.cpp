#include<iostream>
#include<vector>
#include<algorithm>

#define log(x) cout<<x<<endl

using namespace std;

class Solution{
	public:

		int minEatingSpeed(vector<int>& piles, int h){
			int left = 1;
			int right = *max_element(piles.begin() , piles.end());
			int result = right;
			
			while(left <= right){
				int mid = (left+right)/2;

				long long time = 0;
				for(int pile : piles){
					time += (pile+mid-1)/mid;
				}
				if(time <= h){
					result = mid;
					right = mid - 1;
				}else{
					left = mid + 1;
				}
			}
			return result;
		}
};

int main(){
	Solution s;

	vector<int> piles = {3,6,7,11};
	int h = 8;

	log(s.minEatingSpeed(piles, h));
	return 0;
}
