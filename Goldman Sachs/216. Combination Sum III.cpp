class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        solve(1,k,n,v);
        return ans;
    }
    void solve(int idx,int k,int sum,vector<int>&v){
        if(v.size()==k && sum==0){
            ans.push_back(v);
            return;
        }
        for(int i=idx;i<=9;i++){
            if(v.size()>k && i>sum) break;
            v.push_back(i);
            solve(i+1,k,sum-i,v);
            v.pop_back();
        }
    }
};