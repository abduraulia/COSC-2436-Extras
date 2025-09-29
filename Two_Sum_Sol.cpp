//two sum LeetCode
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int sum = 0;
        int size = nums.size();
        vector<int> indices;
            for (int i=0; i<size; i++)
            {
                for (int j=0; j<size; j++)
                {
                    if (j == i)
                    {
                        break;
                    }
                    sum = nums[i] + nums[j];
                    if (sum != target)
                    {
                        sum = 0;
                    }
                    else
                    {
                        indices.push_back(i);
                        indices.push_back(j);
                        return indices;
                    }
                }
            }
        
        return indices;
    }
};