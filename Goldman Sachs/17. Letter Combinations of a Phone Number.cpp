class Solution {
public:
    vector<string>ans;
    vector<string>v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        solve(0,"",digits);
        return ans;
    }
    void solve(int idx,string s,string &digits){
        if(idx==digits.size()){
            ans.push_back(s);
            return;
        }
        int temp=digits[idx]-'0';
        for(int i=0;i<v[temp].size();i++){
            s+=v[temp][i];
            solve(idx+1,s,digits);
            s.pop_back();
        }
    }
};
