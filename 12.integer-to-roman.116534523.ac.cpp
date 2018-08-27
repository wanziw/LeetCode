class Solution {
public:
    string intToRoman(int num) {
        int tmp = num;
        int N[4];
        string answer("");
        for(int i = 3; i >= 0; i--) {
            N[i] = num % 10;
            num = (num - num % 10) / 10;
        }
        
        if(N[0] > 0) {
            for(int i = 0; i < N[0]; i++)
                answer += "M";
        }
        
        if(N[1] >= 5) {
            if(N[1] == 9) {
                answer += "CM";
            }else{
                answer += "D";
                for(int i = 5; i < N[1]; i++)
                    answer += "C";
            }
        }else{
            if(N[1] == 4) {
                answer += "CD";
            }else{
                for(int i = 0; i < N[1]; i++)
                    answer += "C";
            }  
        }
        
        if(N[2] >= 5) {
            if(N[2] == 9) {
                answer += "XC";
            }else{
                answer += "L";
                for(int i = 5; i < N[2]; i++)
                    answer += "X";
            }
        }else{
            if(N[2] == 4) {
                answer += "XL";
            }else{
                for(int i = 0; i < N[2]; i++)
                    answer += "X";
            }  
        }
                
        if(N[3] >= 5) {
            if(N[3] == 9) {
                answer += "IX";
            }else{
                answer += "V";
                for(int i = 5; i < N[3]; i++)
                    answer += "I";
            }
        }else{
            if(N[3] == 4) {
                answer += "IV";
            }else{
                for(int i = 0; i < N[3]; i++)
                    answer += "I";
            }  
        }
        return answer;          
    }
};
