#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#define log(x) cout << x << endl;

using namespace std;

class TimeMap{
    public:
        unordered_map<string,vector<pair<string,int>>> res;
        TimeMap(){
        }
        void set(string key, string value, int timestamp){
            res[key].push_back({value,timestamp});
        }
        string get(string key, int timestamp){
            if(res.find(key) == res.end()) return "";

            auto &vec = res[key];
            int l = 0;
            int r = vec.size();
            string ans = "";
            while(l <= r){
                int mid = l + (r - l) / 2;
                if (vec[mid].second <= timestamp) {
                    ans = vec[mid].first;
                    l = mid + 1;
                }else{
                    r = mid -1;
                }
            }
            return ans;
        }
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
int main(){
    TimeMap* obj  = new TimeMap();
    string key = "foo";
    string value = "bar2";
    int timestamp = 4;
    obj -> set(key,value,timestamp);
    string param_2 = obj->get(key,timestamp);

    return 0;
}
