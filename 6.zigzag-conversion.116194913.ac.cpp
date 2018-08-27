class Solution {
public:
    string convert(string s, int numRows) {
        int ud = 1;
        int q  = 0;
        string answer("");
        vector<queue<char>> queues(numRows);
        for(int i = 0; i < s.length(); i++) {
            queues[q].push(s[i]);
            if(numRows == 1) {
                q = 0;
            }else {
                ud == 1?q++:q--;
                if(q == 0) {
                    q = 0;
                    ud = 1;
                }else if(q == numRows - 1) {
                    q = numRows - 1;
                    ud = 0;
                }
            }
        }
        for(int i = 0; i < numRows; i++) {
            while(!queues[i].empty()) {
                answer += queues[i].front();
                queues[i].pop();
            }
        }
        return answer;
        
    }
};

