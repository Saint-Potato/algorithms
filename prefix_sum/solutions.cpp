#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long


class Solution{
public:
    vector<int> minOperations(string boxes) {
        vector<int> answer(boxes.length(), 0);

        // left to right pass
        int ballsOnLeft = 0;
        int moves = 0;
        for(int i = 0; i < answer.size(); i++){
            moves+= ballsOnLeft;
            if(boxes[i] == '1'){
                ballsOnLeft++;
            }
            answer[i] = moves;
        }

        int ballsOnRight = 0;
        moves = 0;

        for(int i = answer.size() - 1; i > -1; i--){
            moves+= ballsOnRight;
            if(boxes[i] == '1'){
                ballsOnRight++;
            }
            answer[i] += moves;
        }

        return answer;
    }

    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n , 0);
        vector<int> right(n, 0);

        for(int i = 1, j = n-2; i < n && j > -1; i++, j--){
            left[i] = left[i-1] + nums[i-1];
            right[j] = right[j+1] + nums[j+1];
        }

        vector<int> answer(n, 0);
        for(int i = 0; i < n; i++){
            answer[i] = abs(left[i] - right[i]);
        }

        return answer;
    }

    vector<int> runningSum(vector<int>& nums) {
        vector<int> run(nums.size(), 0);
        run[0] = nums[0];

        for(int i = 1; i < nums.size(); i++){
            run[i] = nums[i] + run[i-1];
        }

        return run;
    }

    int subarraySum(vector<int>& nums) {
        int total = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            for(int start = max(0, i - nums[i]); start <= i; start++){
                total+= nums[start];
            }
        }

        return total;
    }

    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int mtruck = 0, ptruck = 0, gtruck = 0, time = 0;

        int n = garbage.size();
        char g;
        for(int i = 0; i < n; i++){
            while(garbage[i].length() > 0){
                g = garbage[i].at(0);
                time+= 1;
                if(g == 'G'){
                    time+= gtruck;
                    gtruck = 0;
                }
                else if(g == 'P'){
                    time+= ptruck;
                    ptruck = 0;
                }
                else{
                    time+= mtruck;
                    mtruck = 0;
                }
                if(garbage[i].length() == 1){
                    break;
                }
                else{
                    garbage[i] = garbage[i].substr(1, garbage[i].length() - 1);
                }  
            }
            if(i < n-1){
                mtruck+= travel[i];
                ptruck+= travel[i];
                gtruck+= travel[i];
            }
        }

        return time;
    }

    

};


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solution();
}