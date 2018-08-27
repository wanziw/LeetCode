class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int leftflag = 0, rightflag = 0;
        vector<int>::iterator it;
        vector<int>::iterator low, up;
        for(rightflag = 0; rightflag < nums2.size(); rightflag++) {
            low = lower_bound(nums1.begin(), nums1.end(), nums2[rightflag]);
            nums1.insert(low, nums2[rightflag]);
            
            /*
            if((low - nums1.begin() + 1) != nums1.size()) {
                //nums1.insert(low, nums2[rightflag]);    
            }else{
                if(nums1[low-nums1.begin()] < nums2[rightflag] == false){
                    cout<<"AA";
                    nums1.insert(low, nums2[rightflag]);
                }
                else
                    for(int i = rightflag; i < nums2.size(); i++)
                        nums1.push_back(nums2[i]);
                break;
            }
            */
        }
        
        int m = nums1.size();
        double answer;
        if(m % 2)
            answer = nums1[(m - 1) / 2];
        else
            answer = (double)((nums1[m / 2] + nums1[m / 2 - 1]) * 0.5);
        return answer;
    }
};
