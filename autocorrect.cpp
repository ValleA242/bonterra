/*
This program uses C++ 11 or greater.
Details:
- Implements an autocorrect feature that corrects the spelling of words.
- Initializes a map of incorrect words to their correct spelling.
- tests the autocorrect feature by inputting a word and checking if it is in the map.
*/

// include support for i/o, strings, map, and assert.
#include <iostream>
#include <string>
#include <map>
#include <cassert>

/*
- Define a type of map 'AutoCorrect' with a key of string and value of string.
*/
using AutoCorrect = std::map<std::string, std::string>;

/*
Create a function 'InitializeAutoCorrect'.
Arguments:
- An AutoCorrect map 'autoCorrect'.
Returns:
- nothing
Details:
- Initializes the map with some common misspelled words and their correct spelling.
*/
void InitializeAutoCorrect(AutoCorrect& autoCorrect)
{
    autoCorrect["teh"] = "the";
    autoCorrect["wuz"] = "was";
    autoCorrect["the the"] = "the";
    autoCorrect["dont"] = "don't";
}

/*
Create a function 'AutoCorrectWord'.
Arguments:
- an AutoCorrect map 'autoCorrect'.
- a string 'word'.
Returns:
- A string representing the auto corrected version of the word or the word itself if not found in the map.
Details:
- Search for the word in the map.
- If found, return the correct spelling.
- If not found, return the word itself.
*/
std::string AutoCorrectWord(const AutoCorrect& autoCorrect, const std::string& word)
{
    // Search for the word in the map.
    auto it = autoCorrect.find(word);
    // If found, return the correct spelling.
    if (it != autoCorrect.end())
    {
        return it->second;
    }
    // If not found, return the word itself.
    return word;
}

/*
Create a function 'AutoCorrect_test' to test the autocorrect feature.
Details:
- Initialize the map with some common misspelled words and their correct spelling.
- Test the autocorrect feature by inputting a word and checking if it is in the map.
- if all tests pass, print "All tests passed".
*/
void AutoCorrect_test()
{
    // Initialize the map with some common misspelled words and their correct spelling.
    AutoCorrect autoCorrect;
    InitializeAutoCorrect(autoCorrect);

    // Test the autocorrect feature by inputting a word and checking if it is in the map.
    assert(AutoCorrectWord(autoCorrect, "teh") == "the");
    assert(AutoCorrectWord(autoCorrect, "wuz") == "was");
    assert(AutoCorrectWord(autoCorrect, "the the") == "the");
    assert(AutoCorrectWord(autoCorrect, "dont") == "don't");

    // If all tests pass, print "All tests passed".
    std::cout << "All tests passed" << std::endl;
}

int main()
{
    // Test the autocorrect feature.
    AutoCorrect_test();

    // Write a message indication end of program.
    std::cout << "End of program" << std::endl;

    return 0;
}


