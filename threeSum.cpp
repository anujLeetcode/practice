class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> result;
      if(nums.size() < 3) return result;  
      sort(nums.begin(), nums.end());
      vector<int> temp(3, 0);
      for(int i = 0; i < nums.size(); i++) {
          int start = i + 1;
          int end = nums.size() - 1;
          while(start < end) {
              if(nums[i] + nums[start] + nums[end] == 0) {
                  temp[0] = nums[i];
                  temp[1] = nums[start];
                  temp[2] = nums[end];
                  result.push_back(temp);
                  while(end > start && nums[end] == nums[end-1]) end--;
                  while(end > start && nums[start] == nums[start+1]) start++;
                  start++;
                  end--;
              } else if((nums[i] + nums[start] + nums[end]) > 0) {
                  end--;
              } else {    
                  start++;
              }
          }
          while(i <= nums.size() - 1 && nums[i] == nums[i+1]) i++;     
      }
      return result;  
    }
};

/*
vector<vector<int> > threeSum(vector<int> &num) {
    
    vector<vector<int> > res;

    std::sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {
        
        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        while (front < back) {

            int sum = num[front] + num[back];
            
            // Finding answer which start from number num[i]
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else {
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                res.push_back(triplet);
                
                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2]) rear--;
            }
            
        }

        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;

    }
    
    return res;
    
}
*/
