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

// https://leetcode.com/problems/reverse-integer/
int reverse_int(int x);

// https://leetcode.com/problems/string-to-integer-atoi/
int my_atoi(std::string s);

// https://leetcode.com/problems/palindrome-number/
bool is_palindrome(int x);

// https://leetcode.com/problems/container-with-most-water/
int maxArea(std::vector<int>& height);

// https://leetcode.com/problems/integer-to-roman/
std::string int_to_roman(int num);

// https://leetcode.com/problems/roman-to-integer/
int roman_to_int(std::string s);

// https://leetcode.com/problems/longest-common-prefix/
std::string longestCommonPrefix(std::vector<std::string>& strs);

// https://leetcode.com/problems/3sum/
std::vector<std::vector<int>> threeSum(std::vector<int>& nums);

// https://leetcode.com/problems/3sum-closest/
int threeSumClosest(std::vector<int>& nums, int target);

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
std::vector<std::string> letterCombinations(std::string digits);

// https://leetcode.com/problems/4sum/
std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target);

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
ListNode* removeNthFromEnd(ListNode* head, int n);

// https://leetcode.com/problems/valid-parentheses/
bool brackets_valid(std::string s);

#endif      // LEETCODE_SOLUTIONS_H
