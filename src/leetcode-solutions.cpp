#include "leetcode-solutions.h"
#include <iostream>
#include <set>
#include <unordered_map>
#include <climits>
#include <cassert>
#include <algorithm>

using namespace std;

ListNode* add_two_numbers(ListNode *l1, ListNode *l2)
{
    bool carry = false;
    ListNode *list = new ListNode();
    ListNode *itr = list;

    while (l1 != nullptr || l2 != nullptr) {
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

int len_longest_substr(string str)
{
    int strlen = str.length();

    if (strlen == 0) return 0;

    int sublen = -1;
    int window_start = 0;
    unordered_map<char, int> umap;

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

            window_start = max(window_start, umap[str[window_end]] + 1);
        }
        sublen = max(sublen, window_end - window_start + 1);
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

    while (j < size1 || k < size2) {
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

double median_sorted_arrays(vector<int>& nums1, vector<int>& nums2)
{
    int size1 = nums1.size();
    int size2 = nums2.size();
    int *arr1 = nums1.data();
    int *arr2 = nums2.data();

    double median = median_sorted_arrays(arr1, arr2, size1, size2);

    return median;
}

int expand_around_center(string& s, int l, int r)
{
    int slen = s.length();

    while (l >= 0 && r < slen && s[l] == s[r]) {
            l--;
            r++;
    }

    /* --r - ++l + 1 => r - l - 1; */
    return r - l - 1;
}

string longest_palindrome(string str)
{
    int strlen = str.length();
    if (strlen < 1) return "";

    int start = 0;
    int end = 0;
    for (int i = 0; i < strlen; i++) {
        int len = max(expand_around_center(str, i, i),
                           expand_around_center(str, i, i + 1));
        if (len > end - start + 1) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

    return str.substr(start, end - start + 1);
}

string zigzag_convert(string str, int rows)
{
    int strlen = str.length();

    if (rows == 1 || strlen == 1) return str;

    int jumplen = 2 * rows - 2;
    string zigstr(strlen, 'x');

    int j = 0;
    int k;

    /* PAYPALISHIRING
     *
     * P     I    N             0       6       12
     * A   L S  I G             1    5  7    11 13
     * Y A   H R                2  4    8  10
     * P     I                  3       9
     */

    for (int i = 0; i < rows; i++) {
        k = 0;
        while ( i + k < strlen || i + k - 2*i < strlen) {
            if (i != 0 && i != rows - 1 && k != 0) {
                // if (i + k - 2*i < strlen) is always true
                zigstr[j++] = str[i + k - 2*i];
            }
            if (i + k < strlen) zigstr[j++] = str[i + k];
            k += jumplen;
        }
    }

    return zigstr;
}


int reverse_int(int x)
{
    int rev = 0;
    int pop;

    while(x) {
        pop = x % 10;
        x /= 10;
        /* check for overflow */
        if (rev > INT_MAX/10 || rev < INT_MIN/10
            /* INT_MAX = +2147483647
             * INT_MIN = -2147483648 */
            || (rev == INT_MAX/10 && pop > 7)
            || (rev == INT_MIN/10 && pop < -8)) return 0;
        // rev = rev * 10 + pop;
        rev *= 10;
        rev += pop;
    }

    return rev;
}


int my_atoi(string str)
{
    int strlen = str.length();

    int num = 0;
    bool is_neg = false;
    bool first_char_found = false;

    for (int i = 0; i < strlen; i++) {

        if (str[i] >= '0' && str[i] <= '9') {
            if (!is_neg && (num > INT_MAX/10
                            || (num == INT_MAX/10
                                && (str[i] - '0') > 7))) {
                return INT_MAX;
            }
            if (is_neg && (num < INT_MIN/10
                           || (num == INT_MIN/10
                               && str[i] - '0' > 8))) {
                return INT_MIN;
            }
            if (is_neg) num = num * 10 - (str[i] - '0');
            else num = num * 10 + (str[i] - '0');
            first_char_found = true;
        }
        else if (str[i] == '-') {
            if (first_char_found) return num;
            is_neg = true;
            first_char_found = true;
        }
        else if (str[i] == '+') {
            if (first_char_found) return num;
            first_char_found = true;
        }
        else if (str[i] == ' ') {
            if (first_char_found) return num;
            continue;
        }
        else break;
    }

    return num;
}

bool is_palindrome(int x)
{
    if (x < 0) return false;
    if (x >= 0 && x <=9) return true;

    int rev_x = reverse_int(x);

    return rev_x == x;
}
int maxArea(vector<int>& height)
{
    int max_area = INT_MIN;
    int len = height.size();
    int area;

    int p1 = 0;
    int p2 = len - 1;

    while(p1 < p2) {
        area = (p2 - p1) * min(height[p1], height[p2]);
        max_area = max(max_area, area);
        if (height[p1] == height[p2]) {
            break;
        } else if (height[p1] > height[p2]) {
            p2--;
        } else {
            p1++;
        }
    }

    return max_area;
}

string int_to_roman(int num)
{
    string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L",
        "XL", "X", "IX", "V", "IV", "I"};
    const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10,
        9, 5, 4, 1};

    char* numeral = new char[20];

    int i = 0;
    int j = 0;

    while (num > 0) {
        if (num - values[i] >= 0) {
            for (int m = 0; m < numerals[i].length(); m++) {
                numeral[j++] = numerals[i][m];
            }
            num -= values[i];
        } else {
            i++;
        }
    }
    numeral[j] = '\0';

    string retstr(numeral);
    delete [] numeral;

    return retstr;
}

int roman_to_int(string s)
{
    string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L",
        "XL", "X", "IX", "V", "IV", "I"};
    const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10,
        9, 5, 4, 1};

    int num = 0;

    int s_ptr = 0;
    int s_len = s.length();
    int i = 0;

    while (s_ptr < s_len) {
        if (s[s_ptr] == numerals[i][0]
            && s.compare(s_ptr, numerals[i].length(), numerals[i]) == 0) {
            num += values[i];
            s_ptr += numerals[i].length();
        } else {
            i++;
        }
    }

    return num;
}

string longestCommonPrefix(vector<string>& strs)
{
    int size = strs.size();

    if (size == 0) return "";

    char* prefix = new char[201];

    int i = 0;
    bool ith_char_same;
    char char_to_match;

    while(true) {
        ith_char_same = true;
        if (strs[0].length() <= i) break;
        char_to_match = strs[0][i];
        for (int x = 0; x < size; x++) {
            if (strs[x].length() <= i || strs[x][i] != char_to_match) {
                ith_char_same = false;
                break;
            }
        }
        if (!ith_char_same) break;
        prefix[i] = char_to_match;
        i++;
    }

    prefix[i] = '\0';

    string str(prefix);
    delete[] prefix;

    return str;
}

vector<vector<int>> threeSum(vector<int>& nums)
{
    set<vector<int>> triplets;
    sort(nums.begin(), nums.end());

    vector<int> negatives;
    vector<int> positives;
    int zeroes = 0;

    vector<int>::iterator itr;

    for (itr = nums.begin(); itr != nums.end(); itr++) {
        if (*itr == 0) zeroes++;
        if (*itr < 0) negatives.push_back(*itr);
        else positives.push_back(*itr);
    }

    for (int i = 0; i < zeroes / 3; i++) {
        triplets.insert({0,0,0});
    }

    int neg_size = negatives.size();
    int pos_size = positives.size();
    int complement;
    int idx;

    for (int i = 0; i < pos_size; i++) {
        complement = -1 * positives[i];

        int l = 0;
        int r = neg_size - 1;

        while(l < r) {
            if (negatives[l] + negatives[r] == complement) {
                triplets.insert({negatives[l], negatives[r], positives[i]});
                l++;
                r--;
            }
            else if (negatives[l] + negatives[r] > complement) {
                r--;
            }
            else {
                l++;
            }
        }

        for (int j = i + 1; j < pos_size; j++)
            if (positives[j] == positives[i]) i++;
            else break;
    }

    for (int i = 0; i < neg_size; i++) {
        complement = -1 * negatives[i];

        int l = 0;
        int r = pos_size - 1;

        while(l < r) {
            if (positives[l] + positives[r] == complement) {
                triplets.insert({negatives[i], positives[l], positives[r]});
                l++;
                r--;
            }
            else if (positives[l] + positives[r] > complement) {
                r--;
            }
            else {
                l++;
            }
        }

        for (int j = i + 1; j < neg_size; j++)
            if (negatives[j] == negatives[i]) i++;
            else break;
    }

    vector<vector<int>> vec(triplets.begin(), triplets.end());

    return vec;
}
