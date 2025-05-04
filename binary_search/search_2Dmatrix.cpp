
#include<iostream>
#include<vector>

#define log(x) cout<<x<<endl;

using namespace std;

class Solution{
	public:
		bool searchMatrix(vector<vector<int>>& matrix, int target){
			int size = matrix.size();//1
			for(int i = 0; i < size; i++){
			       int innerSize = matrix[i].size();//1	       
				for(int j = 0; j < innerSize; j++){
					if(matrix[i][j] == target){
						return true;
					}
				}
			}
			return false;
		}
};

int main(){
//	vector<vector<int>> matrix= {{1,3,5,7} , {10,11,16,20} , {23,30,34,60}};
	vector<vector<int>> matrix = {{1}};
	int target = 1;
	Solution s;

	if(s.searchMatrix(matrix , target)){
		log("yes");
	}else{
		log("no");
	}
	return 0;
}
