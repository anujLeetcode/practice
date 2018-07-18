You have n super washing machines on a line. Initially, each washing machine has some dresses or is empty.

For each move, you could choose any m (1 ≤ m ≤ n) washing machines, and pass one dress of each washing machine to one of its adjacent washing machines at the same time .

Given an integer array representing the number of dresses in each washing machine from left to right on the line, you should find the minimum number of moves to make all the washing machines have the same number of dresses. If it is not possible to do it, return -1.

Example1

Input: [1,0,5]

Output: 3

Explanation: 
1st move:    1     0 <-- 5    =>    1     1     4
2nd move:    1 <-- 1 <-- 4    =>    2     1     3    
3rd move:    2     1 <-- 3    =>    2     2     2   
Example2

Input: [0,3,0]

Output: 2

Explanation: 
1st move:    0 <-- 3     0    =>    1     2     0    
2nd move:    1     2 --> 0    =>    1     1     1     
Example3

Input: [0,2,0]

Output: -1

Explanation: 
It's impossible to make all the three washing machines have the same number of dresses. 
Note:
The range of n is [1, 10000].
The range of dresses number in a super washing machine is [0, 1e5].
public class Solution {
    public int findMinMoves(int[] machines) {
        int n = machines.length;
        int sum = 0;
        for (int num : machines) {
            sum += num;
        }
        if (sum % n != 0) {
            return -1;
        }
        int avg = sum / n;
        int[] leftSums = new int[n];
        int[] rightSums = new int[n];
        for (int i = 1; i < n; i ++) {
            leftSums[i] = leftSums[i-1] + machines[i-1];
        }
        for (int i = n - 2; i >= 0; i --) {
            rightSums[i] = rightSums[i+1] + machines[i+1];
        }
        int move = 0;
        for (int i = 0; i < n; i ++) {
            int expLeft = i * avg;
            int expRight = (n - i - 1) * avg;
            int left = 0;
            int right = 0;
            if (expLeft > leftSums[i]) {
                left = expLeft - leftSums[i];
            } 
            if (expRight > rightSums[i]) {
                right = expRight - rightSums[i];
            }
            move = Math.max(move, left + right);
        }
        return move;
    }
}
