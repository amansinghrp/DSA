class Solution {
public:
    string longestPalindrome(string s) {
        int n =s.size(), maxLen = 1, start = 0;
        int l, r;
        for(int i =0; i<n; i++){
            l =i, r=i;
            //skip multiple centres if possible
            while(r <n-1 && s[r] == s[r+1]){
                r++;
            }
            i=r;
            
            //expand from centre
            while(l >0 && r < n-1 && s[l-1] == s[r+1]){
                l--;
                r++;
            }

            if(r-l+1 > maxLen){
                maxLen = (r-l+1);
                start = l;
            }
        }
        return s.substr(start, maxLen);
    }
};