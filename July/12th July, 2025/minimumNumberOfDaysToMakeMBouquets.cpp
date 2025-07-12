// Leetcode question 1482

// You are given an integer array bloomDay, an integer m and an integer k.

// You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

// The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

// Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

class Solution {
private:
    bool isPossible(vector<int>& bloomDay, int day, int m, int k) {
        int count = 0;
        int noOfBouquets = 0;
        for(int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] <= day) count++;
            else {
                noOfBouquets += (count / k);
                count = 0;
            }
        }
        noOfBouquets += (count / k);
        return noOfBouquets >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL*m*1LL*k > bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isPossible(bloomDay, mid, m, k)) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};