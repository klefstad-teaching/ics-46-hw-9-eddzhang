#include "ladder.h"

int main()
{
    // Step 1: Load dictionary (word list)
    set<string> word_list;
    load_words(word_list, "../src/words.txt");

    // Step 2: Get user input (or use predefined words)
    string begin_word = "goodbye";
    string end_word = "hello";

    // Step 3: Generate and print the word ladder
    vector<string> ladder = generate_word_ladder(begin_word, end_word, word_list);

    if (!ladder.empty())
    {
        cout << "Word Ladder found: ";
        print_word_ladder(ladder);
    }
    else
    {
        cout << "No ladder found from " << begin_word << " to " << end_word << endl;
    }

    return 0;
}