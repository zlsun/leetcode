/** 126. Word Ladder II

Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list

For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]

Note:

All words have the same length.
All words contain only lowercase alphabetic characters.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        
    }
};

int main() {
    Solution s;
    return 0;
}
