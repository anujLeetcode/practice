class Solution {
public:
    string solveEquation(string equation) {
      int xparam = 0;
      int param = 0;
      int sign = 1;
      int flag = 1;
      int i = 0; 
      while(i < equation.size()) {
        if (equation[i] == '+') {
            sign = 1;
            i++;
        } else if(equation[i] == '-') {
            sign = -1;
            i++; 
        } else if(equation[i] == '=') {
            flag = -1;
            sign = 1;
            i++; 
        } else if(isdigit(equation[i])) {
            int temp = 0;
            while(i < equation.size() && isdigit(equation[i])) {
                temp = temp * 10 +  (equation[i] - '0');
                i++;
            }
            if (equation[i] == 'x') {
                xparam += sign * flag * temp; 
                i++;
                temp = 0;
            } else {
               param += sign * flag * temp; 
               temp = 0;
            }
        }
        else {
            xparam += sign * flag * 1; 
            i++;
        }
          
      }  
        if(param == 0 && xparam == 0) {
            return ("Infinite solutions");
        }
        else if(xparam == 0) {
            return ("No solution");
        }
        else {

            return "x=" + to_string(param / xparam * -1);
        }
    }
};
