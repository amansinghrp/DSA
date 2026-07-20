class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size();
        int l = 0, r = n-1;
        int cnt =0;
        int isOdd = -1;
        while(l < r){
            if(s[l] == s[r]){
                l++;
                r--;
                continue;
            }
            else{
                int k;
                for(k =l+1; k<r; k++){
                    if(s[k] == s[r]){
                        break;
                    }
                }
                if(k == r){
                    isOdd = r;
                    r--;
                    continue;
                }
                else{
                    for(int j = k; j>l; j--){
                        swap(s[j], s[j-1]);
                        cnt++;
                    }
                    l++;
                    r--;
                }
            }
        }

        if(isOdd != -1){
            cnt += (isOdd - s.size()/2);
        }
        return cnt;
    }
};