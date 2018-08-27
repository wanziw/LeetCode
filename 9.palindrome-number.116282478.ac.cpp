class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        else if(x == 0)
            return true;
        else {
            int tmp = x;
            long long int answer = 0;
            while(x != 0) {
                answer = answer * 10 + x % 10;
                x = x / 10;
            }
            if(answer == tmp)
                return true;
            else
                return false;
        }
    }
};
