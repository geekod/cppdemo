#include <iostream>
#include <vector>
#include <iterator>

namespace l001_two_sum {
class Solution {
public:
    std::vector<unsigned int> twoSum(std::vector<unsigned int>& nums, int target) {
        

        unsigned int ret_arr[] = {0, 0};
        std::vector<unsigned int> nums(ret_arr, std::end(ret_arr));
        return nums;
    }
};

void dump(const std::vector<unsigned int>& vec) {
    unsigned int i = 0;
    for (const auto& elem : vec) {
        std::cout << (i != 0 ? "," : "") << elem << std::endl;
    }
}

}

int main() {
    unsigned int nums_arr[] = {2, 7, 11, 15};
    std::vector<unsigned int> nums(nums_arr, std::end(nums_arr));
    unsigned int target = 9;

    std::cout << "nums:";
    l001_two_sum::dump(nums);
    std::cout << "target:" << target << std::endl;

    l001_two_sum::Solution solution;
    const auto answer = solution.twoSum(nums, target);

    std::cout << "answer:";
    l001_two_sum::dump(answer);

    return 0;
}
