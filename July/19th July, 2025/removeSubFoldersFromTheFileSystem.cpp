// Leetcode question 1233

// Given a list of folders folder, return the folders after removing all sub-folders in those folders. You may return the answer in any order.

// If a folder[i] is located within another folder[j], it is called a sub-folder of it. A sub-folder of folder[j] must start with folder[j], followed by a "/". For example, "/a/b" is a sub-folder of "/a", but "/b" is not a sub-folder of "/a/b/c".

// The format of a path is one or more concatenated strings of the form: '/' followed by one or more lowercase English letters.

// For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string and "/" are not.

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> answer;
        answer.push_back(folder[0]);
        for(int i = 1; i < folder.size(); i++) {
            string lastFolderAdded = answer.back();
            lastFolderAdded.push_back('/');
            if(folder[i].compare(0, lastFolderAdded.size(), lastFolderAdded) != 0) answer.push_back(folder[i]);
        }
        return answer;
    }
};