/** 068. Text Justification

Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.


You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:

A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    vector<string> fullJustify(const vector<string>& words, int maxWidth) {
        vector<vector<string>> lines(1);
        vector<int> spaces;
        int len = 0;
        for (const auto& w : words) {
            int l = w.length();
            if (len + l + (int)lines.back().size() > maxWidth) {
                lines.emplace_back();
                spaces.push_back(maxWidth - len);
                len = 0;
            }
            lines.back().push_back(w);
            len += l;
        }
        spaces.push_back(maxWidth - len);
        int l = lines.size();
        vector<string> res(l);
        for (int i = 0; i < l; ++i) {
            auto& li = lines[i];
            auto& sp = spaces[i];
            int wl = li.size();
            res[i] = li[0];
            if (wl == 1 || i == l - 1) {
                for (int j = 1; j < wl; ++j) {
                    res[i] += ' ' + li[j];
                }
                res[i] += string(sp - wl + 1, ' ');
            } else {
                int s = sp / (wl - 1);
                int e = sp % (wl - 1);
                for (int j = 1; j < wl; ++j) {
                    res[i] += string(s + (j <= e), ' ') + li[j];
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    ASSERT s.fullJustify({"This", "is", "an", "example", "of", "text", "justification."}, 16) == vector<string> {
       "This    is    an",
       "example  of text",
       "justification.  "
    };
    ASSERT s.fullJustify({"What", "must", "be", "shall", "be."}, 12) == vector<string> {
        "What must be",
        "shall be.   "
    };
    ASSERT s.fullJustify({"Imagination", "is", "more", "important", "than", "knowledge."}, 14) == vector<string> {
        "Imagination is",
        "more important",
        "than          ",
        "knowledge.    "
    };
    return 0;
}
