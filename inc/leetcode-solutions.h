#ifndef LEETCODE_SOLUTIONS_H
#define LEETCODE_SOLUTIONS_H

#include "ListNode.h"
#include <string>
#include <vector>

// https://leetcode.com/problems/add-two-numbers/
ListNode* add_two_numbers(ListNode* list1, ListNode* list2);

// https://leetcode.com/problems/longest-substring-without-repeating-characters/
int len_longest_substr(std::string str);

// https://leetcode.com/problems/median-of-two-sorted-arrays/
double median_sorted_arrays(std::vector<int>& arr1, std::vector<int>& arr2);

// https://leetcode.com/problems/longest-palindromic-substring/solution/
std::string longest_palindrome(std::string str);

// https://leetcode.com/problems/zigzag-conversion/
std::string zigzag_convert(std::string str, int rows);


#endif      // LEETCODE_SOLUTIONS_H
