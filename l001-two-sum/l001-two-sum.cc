#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>

/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * 
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */

namespace l001_two_sum {
class Solution {
public:
    std::vector<unsigned int> twoSum(std::vector<unsigned int>& nums, int target) {
        std::unordered_map<unsigned int, unsigned int> num_index_map;

        for (unsigned int i = 0; i < nums.size(); ++i) {

            // validation
            const int counter_part = target - nums[i];
            if (counter_part < 0) {
                continue;
            } 

            // find the counter_part of the sum from the map
            const auto it = num_index_map.find(counter_part);
            if (it != num_index_map.end()) {
                const std::vector<unsigned int> ret = {(it->second), i};
                return ret;
            } 

            // put non-exists element into the map
            num_index_map[nums[i]] = i;
        } 

        const std::vector<unsigned int> ret = {0, 0}; 
        return ret;
    }

    std::vector<unsigned int> twoSum2(std::vector<unsigned int>& nums, int target) {
        for (unsigned int i = 0; i < nums.size(); ++i) {
            for (unsigned int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    const std::vector<unsigned int> ret = {i, j};
                    return ret;
                }
            }
        } 

        const std::vector<unsigned int> ret = {0, 0};
        return ret;
    }
};

void dump(const std::vector<unsigned int>& vec) {
    std::cout << "{";
    unsigned int i = 0;
    for (const auto& elem : vec) {
        std::cout << (i++ != 0 ? "," : "") << elem;
    }
    std::cout << "}";
}

}

int main() {
    // init question
    std::vector<unsigned int> nums = {2, 7, 11, 15};
    unsigned int target = 9;

    // print the question
    std::cout << " nums:";
    l001_two_sum::dump(nums);
    std::cout << " target:" << target << std::endl;

    // resolve the question
    l001_two_sum::Solution solution;
    const auto answer = solution.twoSum(nums, target);

    // print the answer
    std::cout << " answer:";
    l001_two_sum::dump(answer);

    return 0;
}
