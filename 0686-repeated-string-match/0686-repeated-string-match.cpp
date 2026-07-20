class Solution {
private:
    bool rabinKarp(string pat, string txt){
        int m = pat.size();
        int n = txt.size();
        int q = 101;
        int patHash = 0, txtHash = 0;
        int d = 31;

        int h =1;
        for(int i =0; i<m-1; i++){
            h = (h*d)%q;
        }

        for(int i=0; i<m; i++){
            patHash = ((patHash*d) + pat[i])%q;
            txtHash = ((txtHash*d) + txt[i])%q;
        }

        for(int i=0; i<=(n-m); i++){
            if(patHash == txtHash){
                if(txt.substr(i, m) == pat){
                    return true;
                }
            }

            if(i <n-m){
                txtHash = (d*(txtHash - txt[i]*h) + txt[i+m])%q;
                if(txtHash <0){
                    txtHash += q;
                }
            }
        }

        return false;
    }
public:
    int repeatedStringMatch(string a, string b) {
        string source = a;
        int cnt = 1;
        while(source.size() < b.size()){
            source+=a;
            cnt++;
        }
        if(source==b) return cnt;
        if(rabinKarp(b, source)){
            return cnt;
        }
        if(rabinKarp(b, source+a)){
            return cnt+1;
        }
        return -1;
    }
};