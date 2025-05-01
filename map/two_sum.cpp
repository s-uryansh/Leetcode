#include<iostream>
#include<map>
using namespace std;

void two_sum(int num[] , int target, int size){
	map<int,int> numMap;
	for (int i = 0; i < size; i++) {
        int complement = target - num[i];
        
        if (numMap.find(complement) != numMap.end()){
			cout << "[" << numMap[complement] << "," << i << "]" << endl;
			return;	
	}

        
        numMap[num[i]] = i;
    }
}

int main(){
	int nums[] = {2,7,11,15};
	int target = 9;
	int size = sizeof(nums)/sizeof(nums[0]);
	two_sum(nums ,target , size);
}
