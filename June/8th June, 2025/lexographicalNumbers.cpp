// Leetcode question no 386 (Daily Challenge -> 8th June, 2025)

/*
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space.
*/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> answer(n);
        int num = 1;
        for(int i = 0; i < n; i++) {
            answer[i] = num;
            if(num * 10 > n) {
                if(num == n) num /= 10;
                num++;
                while(num % 10 == 0) num /= 10;
            } else num *= 10;
        }
        return answer;
    }
};