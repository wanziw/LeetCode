class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer("");
        
        if(strs.size() == 0)
            return "";
        else if(strs.size() == 1)
            return strs[0];
        else {
            answer = strs[0];
            for(int i = 1; i < strs.size(); i++) {
                if(answer.length() > strs[i].length())
                    answer = answer.substr(0, strs[i].length());
                for(int j = 0; j < min(answer.length(), strs[i].length()); j++) {
                    if(answer[j] != strs[i][j]) 
                        answer = answer.substr(0, j);
                }
            }
            return answer;
        }
    }
};



