class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size();
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int i = 0, j =0;
        int cnt = 0;
        while(i <n && j < m){
            if(g[i] <= s[j]) {
                cnt++;
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return cnt;
    }
};