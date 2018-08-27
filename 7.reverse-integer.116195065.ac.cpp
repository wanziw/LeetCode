class Solution {
public:
    int reverse(int x) {
        int sign;
        long long int answer = 0;
        x >= 0 ? sign = 1:sign = -1;
        cout<<x<<endl;
        while(x != 0) {
            answer = answer * 10 + x % 10;
            x = x / 10;
        }
        if(answer > 2147483647 || answer < -2147483647)
            return 0;
        else 
            return answer;
    }
};

