class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        for(int k=0; k<nums.size(); k++){
            if(nums[k] == 0 && k>i){
                swap(nums[i], nums[k]);
                i++;
                k--;
            }
            else if(nums[k] == 2 && k<j){
                swap(nums[k], nums[j]);
                j--;
                k--;
            }
        }
        
    }
};
