class Solution {
public:
int helper(string s,int n){
    int ans=0;
    int len=s.length();
    map<char,int> m;
    for(int i=n;i<len;i++){
        if(m[s[i]]) return ans;
        m[s[i]]++;
        ans++;
    }
    return ans;
}
    int lengthOfLongestSubstring(string s) {
        int len=s.length();
        int ans=0;
        for(int i=0;i<len;i++){
            ans=max(ans,helper(s,i));
        }
        return ans;
    }
};