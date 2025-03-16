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