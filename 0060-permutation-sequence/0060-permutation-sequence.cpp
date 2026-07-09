class Solution {
public:
    string getPermutation(int n, int k) {
        /*
            if we fix the first position
            [1] -> {2, 3} //0th block
            [2] -> {1, 3} //1st block -> fixed 2 at index 1
            [3] -> {1, 2} //2nd block

            for k = 3 (2 if connverted to 0 based inndexing)
            Initally n! = 6(these many combination), out of this the kth combination will lie in which bloack after fixing the first element -->
            in each block there will be  2 elemments so the combination will like in k/2=2/2=1

            and soo on check for all other positions
        */
        int fact = 1; // computer fact of n-1 elements
        vector<int>nums;
        for(int i=1; i<n; i++){
            fact *= i;
            nums.push_back(i);
        }   
        nums.push_back(n); //add the last elemment in the options
        string ans = "";
        k = k-1;
        while(true){
            ans += to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);

            if(nums.size() == 0){
                break;
            }

            k = k%fact;
            fact = fact/nums.size();
        }
        return ans;
    }
};