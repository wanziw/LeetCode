class Solution {
public:
    int searchFunc(vector<int>& nums, int start, int end, int target) {
	if(start > end) return -1;

	int mid = (start + end) / 2;

	if(nums[mid] == target) return mid;

	if(nums[start] <= nums[mid]) {
	    if(nums[start] <= target && target <= nums[mid])
		return searchFunc(nums, start, mid - 1, target);
	    else
		return searchFunc(nums, mid + 1, end, target);
	}else{
	    if(nums[mid] <= target && target <= nums[end]) 
		return searchFunc(nums, mid + 1, end, target);
	    else
		return searchFunc(nums, start, mid - 1, target);
	}
    }

    int search(vector<int>& nums, int target) {
	return searchFunc(nums, 0, nums.size() - 1, target);
    }
};
