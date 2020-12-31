#include "leetcode-solutions.h"
#include <iostream>
#include <set>
#include <unordered_map>

ListNode* add_two_numbers(ListNode *l1, ListNode *l2)
{
    bool carry = false;
    ListNode *list = new ListNode();
    ListNode *itr = list;

    while(l1 != nullptr || l2 != nullptr) {
        itr->val = (l1 != nullptr) ? l1->val : 0;
        itr->val += (l2 != nullptr) ? l2->val : 0;
        if (carry) itr->val++;

        if (itr->val / 10) carry = true;
        else carry = false;

        itr->val = itr->val % 10;

        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
        if (l1 != nullptr || l2 != nullptr) {
            itr->next = new ListNode();
            itr = itr->next;
        }
    }

    if (carry) {
        itr->next = new ListNode();
        itr = itr->next;
        itr->val++;
    }

    return list;
}

// int len_longest_substr(std::string str)
// {
//     int strlen = str.length();
//     int sublen = 0;
//     bool unique;

//     for (int window_end = 0; window_end < strlen; window_end++) {
//         int cnt = 0;
//         for (int j = window_end; j < strlen; j++) {
//             unique = true;
//             for (int k = window_end; k < j; k++) {
//                 if (str[k] == str[j]) {
//                     unique = false;
//                     break;
//                 }
//             }
//             if (unique) cnt++;
//             else break;
//         }
//         sublen = std::std::max(sublen, cnt);
//     }

//     return sublen;
// }


int len_longest_substr(std::string str)
{
    int strlen = str.length();

    if (strlen == 0) return 0;

    int sublen = -1;
    int window_start = 0;
    std::unordered_map<char, int> umap;

    for (int window_end = 0; window_end < strlen; window_end++) {
        if (umap.find(str[window_end]) != umap.end()) {

            /* Need to check if the hashmap val is outside current window since
             * we're not updating all the vals of umap.
             *
             * "Abccbdec"
             * umap = { 'a' : 0, 'b' : 1, 'c' : 2 }; window_start = 0
             * "abcCbdec"
             * umap = { 'a' : 0, 'b' : 1, 'c' : 3 }; window_start = 3
             * and the values of 'a' and 'b' are invalid.
             * We need to keep that in mind.
             *
             * We could remove 'a' and 'b' from umap keys, but that's
             * not necessary and will only add to time complexity.
             */

            window_start = std::max(window_start, umap[str[window_end]] + 1);
        }
        sublen = std::max(sublen, window_end - window_start + 1);
        umap[str[window_end]] = window_end;
    }

    return sublen;
}

double _median_sorted_arrays(int *arr1, int *arr2, int size1, int size2)
{
    int size = size1 + size2;
    int med_idx = size / 2;

    double median = 0.0;
    double prev = 0.0;

    int i = 0;
    int j = 0;
    int k = 0;

    while(j < size1 || k < size2) {
        prev = median;

        if (j < size1 && k < size2)
            median = arr1[j] < arr2[k] ? arr1[j++] : arr2[k++];
        else if (j < size1)
            median = arr1[j++];
        else
            median = arr2[k++];

        if (i == med_idx)
            return size % 2 ? median : (median + prev) / 2.0;

        i++;
    }

    return median;
}

double median_sorted_arrays(int *arr1, int *arr2, int size1, int size2)
{
    int idx1;
    int idx2;
    int start1;
    int start2;
    int cut;
    double med1;
    double med2;

    if (size1 <= 2 || size2 <= 2)
        return _median_sorted_arrays(arr1, arr2, size1, size2);

    idx1 = size1 % 2 ? size1 / 2 : size1 / 2 - 1;
    idx2 = size2 % 2 ? size2 / 2 : size2 / 2 - 1;
    med1 = size1 % 2 ? arr1[idx1] : (arr1[idx1] + arr1[idx1 + 1]) / 2.0;
    med2 = size2 % 2 ? arr2[idx2] : (arr2[idx2] + arr2[idx2 + 1]) / 2.0;

    if (med1 == med2) return med1;

    /*
     * We can't cut both arrays by half.
     * We need to remove equal number of elements from the ends.
     * cut = size - (size - idx) = idx
     *     old_size  (new_size) */
    cut = size1 < size2 ? idx1 : idx2;

    start1 = med1 > med2 ? 0 : cut;
    start2 = med2 > med1 ? 0 : cut;

    return median_sorted_arrays(arr1 + start1, arr2 + start2,
                                size1 - cut, size2 - cut);
}

double median_sorted_arrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
    int size1 = nums1.size();
    int size2 = nums2.size();
    int *arr1 = nums1.data();
    int *arr2 = nums2.data();

    double median = median_sorted_arrays(arr1, arr2, size1, size2);

    return median;
}
