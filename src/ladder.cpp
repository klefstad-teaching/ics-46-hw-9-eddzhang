#include "ladder.h"
#include <queue>
#include <set>
#include <vector>

void error(string word1, string word2, string msg)
{
    cerr << word1 << " " << word2 << " " << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d)
{
    int len1 = str1.size();
    int len2 = str2.size();
    int mismatch = 0;

    if (abs(len1 - len2) > d)
        return false;

    int i = 0; int j = 0;
    while (i < len1 && j < len2)
    {
        if (str1[i] != str2[j])
        {
            mismatch++;
            if (mismatch > d)
                return false;

            if (len1 > len2) {i++;}
            else if (len2 > len1) {j++;}
            else {i++; j++;}
        }
        else
        {
            i++;
            j++;
        }
    }
    mismatch += (len1 - i) + (len2 - j);
    return mismatch <= d;
}

bool is_adjacent(const string& word1, const string& word2)
{
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list)
{
    queue<vector<string>> ladderQ;
    ladderQ.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);

    while (!ladderQ.empty())
    {
        vector<string> ladder = ladderQ.front();
        ladderQ.pop();
        string last_word = ladder[ladder.size() - 1];
        for (auto word : word_list)
        {
            if (is_adjacent(last_word, word))
            {
                if (visited.find(word) == visited.end())
                {
                    visited.insert(word);
                    vector<string> newLadder = ladder;
                    newLadder.push_back(word);
                    if (word == end_word)
                        return newLadder;
                    ladderQ.push(newLadder);
                }
            }
        }
    }
    return vector<string>();
}

void load_words(set<string> & word_list, const string& file_name)
{
    ifstream file(file_name);
    string word;
    while (file >> word)
    {
        word_list.insert(word);
    }
    file.close();
}

void print_word_ladder(const vector<string>& ladder)
{
    if (ladder.empty())
    {
        cout << "No word ladder found." << endl;
        return;
    }

    cout << "Word ladder found: ";
    for (auto word : ladder)
    {
        cout << word << " ";
    }
    cout << endl;
}

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
void verify_word_ladder()
{
    set<string> word_list;

    load_words(word_list, "../src/words.txt");

    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);

    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);

    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);

    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);

    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);

    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}

