#include<bits/stdc++.h>
using namespace std;
class Solution { 
private: 
    void combine(int n, int k, vector<vector<int>> &output, vector<int> &temp, int start){
        if(temp.size() == k){
            output.push_back(temp);
            return;
        }
        for(int i=start; i<=n; i++){
            temp.push_back(i);
            combine(n, k, output, temp, i+1);
            temp.pop_back();
        }
    }     
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> output;
        vector<int> temp;
        combine(n, k, output, temp, 1);
        return output;
    }
};
int main()
{
    vector<vector<int>> v=Solution().combine(4,3);
    for(auto i : v){
        for(auto j : i){
            cout<<j<<"  ";
        }cout<<endl;
    }

    return 0;
}