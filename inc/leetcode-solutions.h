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

#endif      // LEETCODE_SOLUTIONS_H
