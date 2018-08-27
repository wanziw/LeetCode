class Solution {
public:
    int myAtoi(string str) {
	long long int answer = 0;
	int sign = 1;
	bool hassign = false;
	bool hasnumber = false;
	for(int i = 0; i < str.length(); i++) {
	    //spaces
	    if(str[i] == ' ' && !hasnumber) {
		if(hassign) break;
		else continue;
	    }
	    
	    //sign and non-number characters
	    if(str[i] == '+' && !hassign)
		hassign = true;
	    else if(str[i] == '-' && !hassign) {
		hassign = true;
		sign = -1;
	    }else if(hassign && (str[i] == '+' || str[i] == '-'))
		break;
	    else if(48 > str[i] || str[i] > 57)
		break;

	    //number
	    if(48 <= str[i] && str[i] <= 57) {
		answer = answer * 10 + int(str[i] - 48);
		hasnumber = true;
	    }

	    if(answer * sign >= 2147483647)
		return 2147483647;
	    else if(answer * sign <= -2147483648)
		return -2147483648;
	}
	return answer * sign;
    }
};

