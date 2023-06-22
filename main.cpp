#include <iostream>
#include <ctime>
#include <random>
#include <string>
#include <vector>

std::string get_random_word(const std::vector<std::string>& words);
void play();

std::vector<std::string> words = {"programming", "hangman", "games", "learn", "hero", "fun", "coding"};

std::string hangman_art[7] = {
        " +---+\n"
        " |   |\n"
        "     |\n"
        "     |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "     |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        " |   |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "/|   |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "/|\\  |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "/|\\  |\n"
        "/    |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "/|\\  |\n"
        "/ \\  |\n"
        "     |\n"
        "=========="
};

int main()
{
    srand(time(0));
    std::cout << "Welcome to Hangman Game!\n";
    play();
    return 0;
}

void play()
{
    std::string secret_word = get_random_word(words);
    std::string guess_word(secret_word.length(), '_');

    int try_no = 0;
    char guess;

    while (true)
    {
        std::cout << hangman_art[try_no] << "\n";
        std::cout << guess_word << std::endl;
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        bool guessed_correctly = false;

        for (int i = 0; i < secret_word.length(); ++i)
        {
            if (secret_word[i] == guess)
            {
                guess_word[i] = guess;
                guessed_correctly = true;
            }
        }

        if (!guessed_correctly)
        {
            ++try_no;
        }

        if (try_no >= 6)
        {
            std::cout << hangman_art[try_no] << "\n";
            std::cout << "Hangman Died! You LOST! The word was " << secret_word << "\n";
            break;
        }

        if (guess_word == secret_word)
        {
            std::cout << hangman_art[try_no] << "\n";
            std::cout << "You win! The word was " << secret_word << "\n";
            break;
        }
    }
}

std::string get_random_word(const std::vector<std::string>& words)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, words.size() - 1);
    return words[dis(gen)];
}
