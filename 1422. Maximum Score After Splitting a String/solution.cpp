#include<iostream>
using namespace std;

//#Brute Force Solution
class Solution {
public:
    int maxScore(string s) {
        int max_score = 0; // To store the maximum score

        // Iterate over all possible split points
        for (int i = 1; i < s.length(); i++) {
            int left_zeros = 0, right_ones = 0;

            // Count zeros in the left substring
            for (int j = 0; j < i; j++) {
                if (s[j] == '0') left_zeros++;
            }

            // Count ones in the right substring
            for (int j = i; j < s.length(); j++) {
                if (s[j] == '1') right_ones++;
            }

            // Calculate the score and update max_score
            int current_score = left_zeros + right_ones;
            max_score = max(max_score, current_score);
        }

        return max_score;
    }
};

//#Optimized Solution
class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int zeros = 0, ones = 0;
        int result = INT_MIN;

        for(int i = 0; i < n - 1; ++i)
        {

            if(s[i] == '0'){
                ++zeros;
            }else{
                ++ones;
            }

            if(result < zeros - ones){
                result = zeros - ones;
            }
        }
        if(s[n - 1] == '1'){
            ++ones;
        } 
        return result + ones;
    }
};