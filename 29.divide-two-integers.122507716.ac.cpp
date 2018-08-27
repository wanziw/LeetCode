class Solution {
public:
    int divide(int dividend, int divisor) {
	//if(dividend != 0 && divisor == 0)
	    //return INT_MAX;

	long long int answer = 0;
	long long int a = dividend >= 0 ? dividend : -(long long int)dividend;
	long long int b = divisor  >= 0 ? divisor  : -(long long int)divisor;
	long long int c = b;
	long long int tmp;

	while(a >= b) {
	    tmp = 1;

	    while((b << 2) <= a) {
		tmp <<= 2;
		b   <<= 2;
	    }

	    a -= b;
	    b  = c;
	    answer += tmp;
	}

	answer = (dividend ^ divisor) >> 31 ? -answer : answer;

	if(answer >= INT_MAX)
	    return INT_MAX;
	else
	    return answer;
    }
};

