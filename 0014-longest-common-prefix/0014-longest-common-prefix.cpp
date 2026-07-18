class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string ans = "";
        string w1 = strs[0];
        string w2 = strs[strs.size()-1];
        for(int i =0; i<min(w1.size(), w2.size()); i++){
            if(w1[i] == w2[i]){
                ans += w1[i];
            }
            else{
                break;
            }
        }
        return ans;
    }
};