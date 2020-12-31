#ifndef LEETCODE_SOLUTIONS_H
#define LEETCODE_SOLUTIONS_H

#include "ListNode.h"
#include <string>
#include <vector>

// https://leetcode.com/problems/add-two-numbers/
ListNode* add_two_numbers(ListNode*, ListNode*);

// https://leetcode.com/problems/longest-substring-without-repeating-characters/
int len_longest_substr(std::string str);

// https://leetcode.com/problems/median-of-two-sorted-arrays/
double median_sorted_arrays(std::vector<int>&, std::vector<int>&);


#endif      // LEETCODE_SOLUTIONS_H
