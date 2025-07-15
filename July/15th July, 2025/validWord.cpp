// Leetcode question 3136

// A word is considered valid if:

// It contains a minimum of 3 characters.
// It contains only digits (0-9), and English letters (uppercase and lowercase).
// It includes at least one vowel.
// It includes at least one consonant.
// You are given a string word.

// Return true if word is valid, otherwise, return false.

// Notes:

// 'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
// A consonant is an English letter that is not a vowel.

class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3) return false;
        int vowel = 0, consonant = 0;
        string vowels = "aeiouAEIOU";
        for(char c : word) {
            if(isalpha(c)) {
                if(vowels.find(c) != string::npos) vowel++;
                else consonant++;
            } else if(!isdigit(c)) return false;
        }
        return vowel >= 1 && consonant >= 1;
    }
};