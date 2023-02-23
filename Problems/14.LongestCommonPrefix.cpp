class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        sort(v.begin(),v.end());
        int n=v.size();
        int s=min(v[0].size(),v[n-1].size());
        int i=0;
        string f=v[0];
        string l=v[n-1];
        while(i<s && f[i]==l[i]){
            i++;
        }
        if(i==0) return "";
        string ans=v[0].substr(0,i);
        return ans;
    }
};