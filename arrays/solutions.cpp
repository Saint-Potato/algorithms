#include<bits/stdc++.h>
using namespace std; 
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> hash;
    
            for(int i = 0; i < nums.size(); i++){
                hash[nums[i]] = i;
            }
    
            for(int i = 0; i < nums.size(); i++){
                int complement = target - nums[i];
                if (hash.find(complement) != hash.end() && hash[complement] != i){
                    return {i, hash[complement]};
                }
            }
    
            return {};
        }

        int majorityElement(vector<int>& nums) {
            int count = 0;
            int candidate;
            for(int i = 0; i < nums.size(); i++){
                if(count==0){
                    candidate = nums[i];
                }
    
                if(nums[i] == candidate){
                    count++;
                }
                else{
                    count--;
                }
            }
    
            return candidate;
        }

        void sortColors(vector<int>& nums) {
            int n = nums.size();
            vector<int> c(3, 0);
            for(int i = 0; i < n; i++){
                c[nums[i]]++;
            }
    
            for(int i = 0, j = 0; i < 3; i++){
                while(c[i] > 0){
                    nums[j] = i;
                    c[i]--;
                    j++;
                }
            }
        }

    };
int main() {
    
    return 0;
}