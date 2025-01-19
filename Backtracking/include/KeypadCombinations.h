#ifndef KEYPAD_COMBINATIONS_H
#define KEYPAD_COMBINATIONS_H

// Print all possible words from phone digits
// Given a keypad and an n digit number, list all words which are possible by pressing these numbers.

#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<unsigned int, std::vector<char>> numberToLetter =
    {
        {1, {'a', 'b', 'c'}},
        {2, {'d', 'e', 'f'}}};

std::vector<unsigned int> numbers = {1, 2};

void generateKeypadCombinations(size_t pos, std::string combination = "")
{
    if (numbers.empty())
    {
        std::cout << " No Possible Solution" << std::endl;
        return;
    }
    if (combination.size() == numbers.size())
    {
        std::cout << "Solution Found = " << combination << std::endl;
        return;
    }

    const auto& it = numberToLetter.find(numbers[pos]);
    if (it == numberToLetter.end())
    {
        std::cerr << "Error: Number " << numbers[pos] << " has no associated letters." << std::endl;
        return;
    }

    const auto &letters = numberToLetter[numbers[pos]];
    for (size_t i = 0; i < letters.size(); ++i)
    {
        generateKeypadCombinations(pos + 1, combination + letters[i]);
    }
}

void runKeypadCombinations()
{
    generateKeypadCombinations(0);
}

#endif