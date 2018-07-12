#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>

/**
Given a string, find the length of the longest substring without repeating characters.

Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

namespace l003_longest_substring_without_repeating_characters {
class Solution {
public:
public:
    int lengthOfLongestSubstring(std::string s) {
        auto substr_info = iter_sub_strings(s);
        std::string sub_s = s.substr(substr_info[1], substr_info[0]);
        std::cout << sub_s;
        return sub_s.size();
    }
    
    std::vector<int> iter_sub_strings(std::string s) {
        std::vector<int> longest_substr_info = {0, 0, 0};
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i + 1; j < s.size(); ++j) {
                auto substr_info = calc_repeats(s, i, j);
                if (substr_info[2] == 0 && substr_info[1] - substr_info[0] > longest_substr_info[1] - longest_substr_info[0]) {
                    longest_substr_info = substr_info;
                }
            }
        }
        return longest_substr_info;
    }
    
    std::vector<int> calc_repeats(std::string s, int i, int j) {
        std::vector<int> substr_info = {i, j, 0}; // begin, end, is_repeats
        if (i - (j - i) >= 0) {
            if (s.substr(i - (j - i), j - i) == s.substr(i, j - i)) {
                substr_info[2] = 1;
            }
        }
        if (i + (j - i) * 2 < s.size()) {
            if (s.substr(i + (j - i), j - i) == s.substr(i, j - i)) {
                substr_info[2] = 1;
            }
        }
        return substr_info;
    }
};

}

int main() {

    {
        // init question
        std::string question = "abcabcbb";
        // resolve the question
        std::cout << "question:" << question << " answer:";
        l003_longest_substring_without_repeating_characters::Solution solution;
        const auto answer = solution.lengthOfLongestSubstring(question);
        // print the answer
        std::cout << std::endl;
    }

    {
        // init question
        std::string question = "bbbbb";
        // resolve the question
        std::cout << "question:" << question << " answer:";
        l003_longest_substring_without_repeating_characters::Solution solution;
        const auto answer = solution.lengthOfLongestSubstring(question);
        // print the answer
        std::cout << std::endl;
    }

    {
        // init question
        std::string question = "pwwkew";
        // resolve the question
        std::cout << "question:" << question << " answer:";
        l003_longest_substring_without_repeating_characters::Solution solution;
        const auto answer = solution.lengthOfLongestSubstring(question);
        // print the answer
        std::cout << std::endl;
    }

    return 0;
}
