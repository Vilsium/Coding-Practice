// Leetcode question no 1432

/*
You are given an integer num. You will apply the following steps to num two separate times:

Pick a digit x (0 <= x <= 9).
Pick another digit y (0 <= y <= 9). Note y can be equal to x.
Replace all the occurrences of x in the decimal representation of num by y.
Let a and b be the two results from applying the operation to num independently.

Return the max difference between a and b.

Note that neither a nor b may have any leading zeros, and must not be 0.
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
        if(num[0] == '1') {
            for(int i = 0; i < num.length(); i++) {
                if(num[i] != '0' && num[i] != '1') {
                    firstNonZeroNo = num[i];
                    break;
                }
            }
            for(int i = 0; i < num.length(); i++) {
                if(num[i] == firstNonZeroNo) num[i] = '0';
            }
        } else {
            firstNonZeroNo = num[0];
            for(int i = 0; i < num.length(); i++) {
                if(num[i] == firstNonZeroNo) num[i] = '1';
            }
        }
        return stoi(num);
    }
public:
    int maxDiff(int num) {
        int maxNumber = makeMax(to_string(num));
        int minNumber = makeMin(to_string(num));
        return maxNumber-minNumber;
    }
};