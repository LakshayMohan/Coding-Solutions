#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        // If there are less than 3 elements, it's impossible to have an increasing triplet
        if (n < 3) return false;

        // Initialize two variables to track the smallest and middle elements in the triplet
        int low = INT_MAX;  // Smallest element found so far
        int mid = INT_MAX;  // Middle element found so far

        // Iterate through the array
        for (int i = 0; i < n; ++i) {
            // If the current element is greater than 'mid', we found a triplet
            if (nums[i] > mid) {
                return true;
            }
            // If the current element is smaller than 'low', update 'low'
            else if (nums[i] < low) {
                low = nums[i];
            }
            // If the current element is greater than 'low' but smaller than 'mid', update 'mid'
            else if (nums[i] > low && nums[i] < mid) {
                mid = nums[i];
            }
        }

        // If no triplet is found after traversing the array, return false
        return false;
    }
};
