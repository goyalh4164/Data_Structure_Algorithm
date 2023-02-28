#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,vector<int>> m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]].push_back(i);
        }
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n-1;
        vector<int> ans;
        while(i<j){
            if(nums[i]+nums[j]==target){
                if(nums[i]==nums[j]){
                vector<int> ans;
                ans.push_back(m[nums[i]].at(0));
                ans.push_back(m[nums[j]].at(1));
                return ans;
                }
                vector<int> ans;
                ans.push_back(m[nums[i]]);
                ans.push_back(m[nums[j]]);
                return ans;
            }
            else if(nums[i]+nums[j]<target){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;


    }
};