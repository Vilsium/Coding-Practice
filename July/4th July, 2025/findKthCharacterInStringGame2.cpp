// Leetcode question 3307

/*
Alice and Bob are playing a game. Initially, Alice has a string word = "a".

You are given a positive integer k. You are also given an integer array operations, where operations[i] represents the type of the ith operation.

Now Bob will ask Alice to perform all operations in sequence:

If operations[i] == 0, append a copy of word to itself.
If operations[i] == 1, generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word. For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".
Return the value of the kth character in word after performing all the operations.

Note that the character 'z' can be changed to 'a' in the second type of operation.
*/

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int shift = 0; //to count the shifts
        for(int i = ceil(log2(k))-1; i >= 0; i--) {
            long long half = 1LL << i;
            if(k > half) {
                k -= half;
                shift += operations[i];
            }
        }
        return 'a' + (shift % 26);
    }
};