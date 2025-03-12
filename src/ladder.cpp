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

}

bool is_adjacent(const string& word1, const string& word2)
{

}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list)
{
    queue<vector<string>> ladderQ;
    ladderQ.push([begin_word]);
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
    return empty vector??;
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
    for (auto word : ladder)
    {
        cout << word << " ";
    }
    cout << endl;
}

void verify_word_ladder()
{

}
