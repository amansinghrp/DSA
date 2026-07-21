class Solution {
private:
    string RLE(string s){
        string ans = "";
        int cnt = 1;
        for(int i =1; i<s.size(); i++){
            if(s[i] != s[i-1]){
                ans += cnt + '0';
                ans += s[i-1];
                cnt =1;
            }
            else{
                cnt++;
            }
        }
        ans += cnt + '0';
        ans += s[s.size()-1];
        return ans;
    }
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        return RLE(countAndSay(n-1));
    }
};