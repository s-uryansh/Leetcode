#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#define log(x) cout<<x<<endl;

using namespace std;

class Solution{
	public:
		int carFleet(int target, vector<int>& position, vector<int>& speed){
			int n = position.size();
			if(n == 0){
				return 0;
			}

			vector<pair<int , int>> cars;
			for(int i = 0 ; i < n ; i++){
				cars.push_back({position[i] , speed[i]});
			}
			sort(cars.rbegin() , cars.rend());

			stack<double> times;
			for(auto& [pos , spd]: cars){
				double time = (double)(target - pos) / spd;
				
				if(times.empty() || time > times.top()){
					times.push(time);
				}
			}
			return times.size();
		}

};

int main(){
	int target = 100;
	vector<int> position = {0,2,4};
	vector<int> speed = {4,2,1};


	Solution s;

	int fleet = s.carFleet(target, position, speed);
	log(fleet);
	return 0;
}
