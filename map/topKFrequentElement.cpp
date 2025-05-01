#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

#define log(x) cout<<x<<endl;

using namespace std;

class Solution {
public:
	/*void printTopKNumbers(priority_queue<pair<int, int>>maxHeap, int k){
		int count = 0;
		while(!maxHeap.empty() &&  count < k){
			auto top = maxHeap.top();
			log(top.second);
			maxHeap.pop();
			count++;
		}
	}*/

    	vector<int> topKFrequent(vector<int>& nums, int k) {
			unordered_map<int , int>numMap;
			for(int num: nums){
				numMap[num]++;
			}
			priority_queue<pair<int,int>>maxHeap;
			for(auto& freq: numMap){
				maxHeap.push({freq.second , freq.first});
			}

			int count = 0;
			vector<int> result;

                	while(!maxHeap.empty() &&  count < k){
                        	auto top = maxHeap.top();
                        	result.push_back(top.second);
                        	maxHeap.pop();
                        	count++;
			}
			return result;
    }
};

int main(){
	vector<int> nums = {1,1,1,1,2,3,4,5,5,5,5,5};
	Solution s;
	vector<int> topkNum = s.topKFrequent(nums , 2);
	for(int i = 0 ; i <= 2 ; i++){
		log(topkNum[i]);
	}
	return 0;
}
