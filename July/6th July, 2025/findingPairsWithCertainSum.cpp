// Leetcode question 1865

// You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure that supports queries of two types:

// Add a positive integer to an element of a given index in the array nums2.
// Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given value (0 <= i < nums1.length and 0 <= j < nums2.length).
// Implement the FindSumPairs class:

// FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object with two integer arrays nums1 and nums2.
// void add(int index, int val) Adds val to nums2[index], i.e., apply nums2[index] += val.
// int count(int tot) Returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot.

class FindSumPairs {
    vector<int> arr1, arr2;
    unordered_map<int, int> mpp;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        for(int i : arr2) {
            mpp[i]++;
        }
    }
    
    void add(int index, int val) {
        mpp[arr2[index]]--;
        arr2[index] += val;
        mpp[arr2[index]]++;
    }
    
    int count(int tot) {
        int answer = 0;
        for(int i : arr1) {
            answer += mpp[tot - i];
        }
        return answer;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */