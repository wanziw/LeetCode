class Solution {
public:
    void nextPermutation(vector<int>& nums) {
	int num = nums.size();
	if(num == 1)
	    return ;
	int p = num - 2;
	while(p >= 0 && nums[p] >= nums[p + 1])
	    p--;
	if(p == -1) {
	    sort(nums.begin(), nums.end());
	    return ;
	}else{
	    int q = p + 1;
	    while(q < num && nums[q] > nums[p])
		q++;
	    swap(nums[p], nums[q - 1]);
	    sort(nums.begin() + p + 1, nums.end());
	}
    }
};
