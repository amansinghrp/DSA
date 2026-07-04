class Solution {
public:
    double myPow(double x, long long n) {
        double ans =1;
        long long power = n<0 ? -1*n : n;

        while(power){
            if(power & 1){
                ans = ans * x;
            }
            x *= x;
            power >>= 1;
        } 

        if(n < 0) return 1/ans;
        return ans;
    }
};