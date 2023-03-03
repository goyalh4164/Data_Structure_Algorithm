#include <vector>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;
class Solution {
public:
bool compare(pair<int,string> p1,pair<int,string> p2){
    if(p1.first>p2.first) return true;
    return p1.second<p2.second;
}
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        for(auto i : words){
            m[i]++;
        }
        vector<pair<int,string>> v;
        for(auto i : m){
            v.push_back({i.second,i.first});
        }

        sort(v.begin(),v.end(),compare());
        vector<string> ans;
        if(v.size()<=k){
            
            for(auto i : v){
                ans.push_back(i.second);
            }
        }
        else{
            
                for(int i=0;i<k;i++){
                    ans.push_back(v[i].second);
                }
            
        }
        return ans;
    }
};