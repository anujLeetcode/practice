/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

Solution:
Classic binary search problem. One place worth noticing is the termination conditions. Whenever our window has only one element, its value is the answer. When our window has two elements, and the first element is larger than the second one, the second element is our answer. This case falls into the num[mid]>=num[start] condition in the code below. (given that there is no duplicates in the array)

*/



class Solution {
public:
    int findMin(vector<int> &num) {
        int start=0,end=num.size()-1;
 
        while (start<end) {
            if (num[start]<num[end])
                return num[start];
 
            int mid = (start+end)/2;
 
            if (num[mid]>=num[start]) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
 
        return num[start];
    }
};
