#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>

/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 */

namespace l002 {
    
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = addTwoNumbers(l1, l2, 0);
        if (p == NULL) {
            p = new ListNode(0);
        }
        return p;
    }

    /**
     * define a recursive add func for l1 node, l2 node and carry number
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry_number) {
        int val = (l1 == NULL ? 0 : l1->val) + (l2 ==NULL ? 0 : l2->val) + carry_number;
        if (val == 0) {
            return NULL;
        }

        // recursive add children
        ListNode* p = new ListNode(val % 10);
        p->next = addTwoNumbers(l1 == NULL ? NULL : l1->next, l2 == NULL ? NULL : l2->next, val / 10);
        return p;
    }
};

ListNode* vectorToListNode(const std::vector<int>& vec) {
    ListNode* head = NULL;
    ListNode* last = NULL;
    ListNode* curr = NULL;

    for (auto elem : vec) {
        curr = new ListNode(elem);
        if (head == NULL) {
            head = curr;
        } else {
            last->next = curr;
        }
        last = curr;
    }
    return head;
}

void del(ListNode* list) {
    for (ListNode* p = list; p != NULL; ) {
        ListNode* q = p;
        p = p->next;
        delete q;
    }
}

void dump(ListNode* list) {
    for (ListNode* p = list; p != NULL; p = p->next) {
        std::cout << (p != list ? "->" : "")  << p->val;       
    }
}

}

int main() {
    // init question
    std::vector<int> vec1 = {2, 4, 3};
    l002::ListNode* l1 = l002::vectorToListNode(vec1);
    std::vector<int> vec2 = {5, 6, 4};
    l002::ListNode* l2 = l002::vectorToListNode(vec2);

    // print the question
    std::cout << " l1:";
    l002::dump(l1);
    std::cout << std::endl;
    std::cout << " l2:";
    l002::dump(l2);
    std::cout << std::endl;

    // resolve the question
    l002::Solution solution;
    const auto answer = solution.addTwoNumbers(l1, l2);

    // print the answer
    std::cout << " answer:";
    l002::dump(answer);
    std::cout << std::endl;

    l002::del(l1);
    l002::del(l2);
    l002::del(answer);

    return 0;
}
