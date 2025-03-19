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

        int longestSubarray(vector<int>& arr, int k) {
            // code here
            unordered_map<int,int> hash;
            
            int len = 0, prefix = 0;
            
            for(int i = 0; i < arr.size(); i++){
                prefix+= arr[i];
                if(hash.find(prefix) == hash.end()){
                    hash[prefix] = i;
                }
                if(prefix == k){
                    len = max(len, i+1);
                    continue;
                }
                if(hash.find(prefix - k) != hash.end()){
                    len = max(len , i - hash[prefix - k]);
                }
            }
            
            return len;
        }

        int maxSubArray(vector<int>& nums) {
            int maxsum = INT_MIN;
            int sum = 0;
    
            for(int i = 0; i < nums.size(); i++){
                sum+= nums[i];
    
                if(sum > maxsum){
                    maxsum = sum;
                }
                if(sum < 0){
                    sum = 0;
                }
            }
    
            return maxsum;
        }

        int pairWithMaxSum(vector<int> &arr) {
            // Your code goes here
            int score = INT_MIN;
            
            for(int i = 0; i < arr.size() - 1; i++){
                if(arr[i] + arr[i+1] > score){
                    score = arr[i] + arr[i+1];
                }
            }
            
            return score;
        }

        int maxProfit(vector<int>& prices) {
            int profit = 0;
            int curr = 0;
    
            for(int i = 0; i < prices.size() - 1; i++){
                curr+= prices[i+1] - prices[i];
                if(curr > profit){
                    profit = curr;
                }
                if(curr < 0){
                    curr = 0;
                }
            }
    
            return profit;
        }

        vector<int> rearrangeArray(vector<int>& nums) {
            int n1 = nums.size();
            vector<int> p(n1/2);
            vector<int> n(n1/2);
    
            for(int i = 0, j = 0, k = 0; i < n1; i++){
                if(nums[i] > 0){
                    p[j++] = nums[i];
                }
                else{
                    n[k++] = nums[i];
                }
            }
    
            for(int i = 0, j = 0; i < n1/2; i++){
                nums[j] = p[i];
                nums[j+1] = n[i];
                j+= 2;
            }
            return nums;
        }

    };
int main() {
    
    return 0;
}