//1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream ss(sentence);
        string word;
        int index = 1;

        while (ss >> word) {
            if (word.find(searchWord) == 0) {
                return index;
            }
            ++index;
        }
        return -1;
    }
};