#include<iostream>
#include<vector>
#include<algorithm>
#define log(x) cout << x << endl;

using namespace std;

class Solution {
public:
//greedy 
    int coinChange(vector<int>& coins, int amount) {
        int result = 0;
        int count = 0;

        sort(coins.begin(), coins.end());
        //1 , 2 , 5
        int size = coins.size();
        for(int i  = size - 1; i >= 0; i--){
            count = amount / coins[i];
            // log(count);
            result += count;
            amount -= count * coins[i];
        }
        if (amount != 0) return -1;
        return result;
    }
};

int main(){
    vector<int> coins = {1,2,5};
    int amount = 11;

    Solution s;
    log(s.coinChange(coins, amount));

    return 0;
}