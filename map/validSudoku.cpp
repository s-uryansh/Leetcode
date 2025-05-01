#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
	bool checkForDup(const unordered_map<char,int>& rowMap){
		for(const auto& [ch , count] : rowMap){
			if(ch != '.' && count > 1){
				return false;
			}
		}
		return true;
	}	

	bool checkColumn(vector<vector<char>>& board){
		int numCol = board[0].size();

                for(const auto& row: board){
                        for(int col = 0 ; col < numCol ; col++){
                                unordered_map<char,int>boardMap;

                                for(int row =0 ; row < board.size() ; row++){
                                        boardMap[board[row][col]]++;
                                }
                                if(!checkForDup(boardMap)){
                                        return false;
                                }

                        }
		}
		return true;
	}

	bool checkBox(vector<vector<char>>& board){
		int numRow = board.size();
		int numCol = board[0].size();

		for(int boxRow = 0 ; boxRow < 3 ; boxRow++){
			for(int boxCol = 0 ; boxCol < 3 ; boxCol++){
				unordered_map<char,int>boxMap;
				for(int i = 0 ; i < 3 ; i++){
					for(int j = 0; j < 3 ; j++){
						char ch = board[boxRow * 3 + i][boxCol * 3 + j];
						boxMap[ch]++;
					}
				}
				if(!checkForDup(boxMap)){
					return false;
				}
			}
		}
		return true;
	}

	bool checkRow(vector<vector<char>>& board){
		for(const auto& row : board){
			unordered_map<char,int>boardMap;
			for(auto& ch : row){
				boardMap[ch]++;
			}
			if(!checkForDup(boardMap)){
				return false;
			}
		}
		return true;
	}

	bool isValidSudoku(vector<vector<char>>& board){

		return checkRow(board) && checkColumn(board) && checkBox(board);	
    	}
};

int main(){
		Solution isSol;
		vector<vector<char>> board = {
			{'.','.','.','.','5','.','.','1','.'},
			{'.','4','.','3','.','.','.','.','.'},
			{'.','.','.','.','.','3','.','.','1'},
			{'8','.','.','.','.','.','.','2','.'},
			{'.','.','2','.','7','.','.','.','.'},
			{'.','1','5','.','.','.','.','.','.'},
			{'.','.','.','.','.','2','.','.','.'},
			{'.','2','.','9','.','.','.','.','.'},
			{'.','.','4','.','.','.','.','.','.'}
    	};
		if(isSol.isValidSudoku(board)){
			cout<<"true"<<endl;
		}else{
			cout<<"false"<<endl;
		}

}
