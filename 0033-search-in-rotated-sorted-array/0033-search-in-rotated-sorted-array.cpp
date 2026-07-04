class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high =n-1, mid;
        while(low <= high){
            mid = (low+high) >> 1;

            if(nums[mid] == target) return mid;

            // check if left half is sorted
            else if(nums[low] <= nums[mid]){
                //if the target actually lies in that left half
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            //left half not sorted
            else{
                //check if target now lies in the right part
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};