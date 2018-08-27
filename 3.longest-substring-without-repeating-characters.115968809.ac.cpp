class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mymap;
        int leftflag = 0, rightflag = 0, maxlength = 0;
        
        for(int rightflag = 0; rightflag < s.size(); rightflag++) {
            if(mymap.find(s[rightflag]) != mymap.end()) {
                leftflag = max(leftflag, mymap[s[rightflag]] + 1);
                mymap[s[rightflag]] = rightflag;
            }else{
                pair<char, int> mypair(s[rightflag], rightflag);
                mymap.insert(mypair);
            }
            maxlength = max(maxlength, rightflag - leftflag + 1);
        }
        return maxlength;
    }
};

