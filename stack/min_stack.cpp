#include<iostream>

#define log(x) cout << x << endl;
#define MAX 1000
using namespace std;

typedef struct{
	int arr[MAX];
	int top;
	int size = 0;
}Minstack;

class MinStack{
	public:
		Minstack minstack;
		MinStack(){
			minstack.top = -1;
		}
		void push(int val){
			if(minstack.size >= MAX){
				log("Stack Full");
			}else{
				minstack.arr[minstack.size] = val;
			//	log("pushed: " << minstack.arr[minstack.size]);
				minstack.size++;
			}
		}
		void pop(){
			if(minstack.size <= 0){
				log("Stack empty");
			}
			for(int i = minstack.size - 1; i < minstack.size; ++i){
			//	log("Popping: " << minstack.arr[minstack.size-1]);
				minstack.arr[i] = minstack.arr[i+1];
			//	log("popped: " << minstack.arr[minstack.size-1]);
			}	
			minstack.size--;
		}
		int top(){
			int val;
			val = minstack.arr[minstack.size-1];
			return val;
		}
		int getMin(){
			int min = minstack.arr[0];
			for(int i = 0; i <= minstack.size ;i++){
				if(minstack.arr[i] < min){
					min = minstack.arr[i];
				}	
			}	
			return min;
		}
};

int main(){
	MinStack minstack;
	
	minstack.push(1);
	minstack.push(2);
	minstack.push(0);
	log(minstack.getMin());
	minstack.pop();
	log(minstack.top());
	log(minstack.getMin());
}
