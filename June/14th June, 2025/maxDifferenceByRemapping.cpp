// Leetcode question no 2566

/*
You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.

Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.

Notes:

When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
Bob can remap a digit to itself, in which case num does not change.
Bob can remap different digits for obtaining minimum and maximum values respectively.
The resulting number after remapping can contain leading zeroes.
*/

class Solution {
private:
    int makeMax(string num) {
        char firstNonNineNo;
        for(int i = 0; i < num.length(); i++) {
            if(num[i] != '9') {
                firstNonNineNo = num[i];
                break;
            }
        }
        for(int i = 0; i < num.length(); i++) {
            if(num[i] == firstNonNineNo) num[i] = '9';
        }
        return stoi(num);
    }
    int makeMin(string num) {
        char firstNonZeroNo;
        for(int i = 0; i < num.length(); i++) {
            if(num[i] != '0') {
                firstNonZeroNo = num[i];
                break;
            }
        }
        for(int i = 0; i < num.length(); i++) {
            if(num[i] == firstNonZeroNo) num[i] = '0';
        }
        return stoi(num);
    }
public:
    int minMaxDifference(int num) {
        int maxNumber = makeMax(to_string(num));
        int minNumber = makeMin(to_string(num));
        return maxNumber-minNumber;
    }
};