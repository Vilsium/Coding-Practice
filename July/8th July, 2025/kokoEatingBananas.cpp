// Leetcode question 875

// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

class Solution {
private:
    bool isPossible(vector<int> piles, int mid, int h) {
        long long hours = 0;
        for(int i = 0; i < piles.size(); i++) {
            hours += piles[i] / mid;
            piles[i] %= mid;
            if(piles[i] > 0) hours++;
            if(hours > h) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int answer = 0;
        int min = 1;
        int max = *max_element(piles.begin(), piles.end());
        while(min <= max) {
            int mid = (min + max) / 2;
            if(isPossible(piles, mid, h)) {
                answer = mid;
                max = mid-1;
            } else min = mid+1;
        }
        return answer;
    }
};