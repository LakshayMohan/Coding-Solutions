#include<iostream>
#include<vector>
using namespace std;

//#Brute Force Solution
class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> result;

        // Process each query individually
        for (const auto& query : queries) {
            int start = query[0], end = query[1];
            int count = 0;

            // Iterate through the range [start, end]
            for (int i = start; i <= end; ++i) {
                // Check if the word starts and ends with a vowel
                if (isVowel(words[i][0]) && isVowel(words[i].back())) {
                    ++count;
                }
            }

            // Store the result for the current query
            result.push_back(count);
        }

        return result;
    }
};


//#Optimized Solution
class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix_sum(n + 1, 0); // Prefix sum array

        // Build the prefix sum array
        for (int i = 0; i < n; ++i) {
            if (isVowel(words[i][0]) && isVowel(words[i].back())) {
                prefix_sum[i + 1] = prefix_sum[i] + 1; // Increment count
            } else {
                prefix_sum[i + 1] = prefix_sum[i]; // Carry forward the count
            }
        }

        vector<int> result;

        // Process each query
        for (const auto& query : queries) {
            int li = query[0], ri = query[1];
            // Use the prefix sum array to calculate the count in O(1)
            result.push_back(prefix_sum[ri + 1] - prefix_sum[li]);
        }

        return result;
    }
};
