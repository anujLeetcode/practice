646. Maximum Length of Pair Chain
DescriptionHintsSubmissionsDiscussSolution
Pick One
You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
Note:
The number of given pairs will be in the range [1, 1000].

class Solution {
private:
    //Our compare function to make sure the pairs is in ascending order
    static bool compare(vector<int>& a, vector<int>&b) {
        return a[1] < b[1];
    }
    
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        //Sort the pairs by the second element in the pair
        //Because the chain is based on (a,b)->(c,d) if and only if b<c, so the smallest
        //one in the chain always start with the smallest "b", which is the second element
        //in the pair
        sort(pairs.begin(), pairs.end(), compare);
        //Count the length of chain
        int count = 0;
        for (int i = 0, j = 0; j < pairs.size(); j++) {
            //If it is the first time, we increase the count to 1
            //If for the two pairs (a,b)->(c,d), b is smaller than c, then we find it
            //After increase the count, we make i equal to j because we need to maintain
            //the chain's property, make sure the second smallest one in the chain and 
            //the following third smallest one in the chain in the chain fulfill
            //the property (a,b)->(c,d) if and only if b<c
            if (j == 0 || pairs[i][1] < pairs[j][0]) {
                count++;
                i = j;
            }
        }
        return count;
    }
};
