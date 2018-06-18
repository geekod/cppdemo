#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>

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
                std::vector<unsigned int> ret = {(it->second), i};
                return ret;
            } 

            // put non-exists element into the map
            num_index_map[nums[i]] = i;
        } 

        std::vector<unsigned int> ret = {0, 0}; 
        return ret;
    }

    std::vector<unsigned int> twoSum2(std::vector<unsigned int>& nums, int target) {
        for (unsigned int i = 0; i < nums.size(); ++i) {
            for (unsigned int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    std::vector<unsigned int> ret = {i, j};
                    return ret;
                }
            }
        } 

        std::vector<unsigned int> ret = {0, 0};
        return ret;
    }
};

void dump(const std::vector<unsigned int>& vec) {
    unsigned int i = 0;
    for (const auto& elem : vec) {
        std::cout << (i++ != 0 ? "," : "") << elem;
    }
}

}

int main() {
    std::vector<unsigned int> nums = {2, 7, 11, 15};
    unsigned int target = 9;

    std::cout << " nums:";
    l001_two_sum::dump(nums);
    std::cout << " target:" << target << std::endl;

    l001_two_sum::Solution solution;
    const auto answer = solution.twoSum(nums, target);

    std::cout << " answer:";
    l001_two_sum::dump(answer);

    return 0;
}
