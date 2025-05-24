#include "utilities.h"
#include "splashkit.h"
#include <cstdio>
#include <limits>
#include <string>
#include <stdexcept>
using namespace std;

// ===================================================
//                 STRING INPUT FUNCTION
// ===================================================
string read_string(string prompt)
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}

// ===================================================
//              INTEGER INPUT W/ VALIDATION
// ===================================================
int read_integer(const string &prompt)
{
    while (true)
    {
        if (!prompt.empty()) write(prompt);
        string line = read_line();

        try {
            size_t idx;
            int v = stoi(line, &idx);
            if (idx != line.size()) throw invalid_argument("trailing chars");
            return v;
        }
        catch (...) {
            write_line("Invalid integer. Please try again.");
        }
    }
}

// ===================================================
//          INTEGER INPUT WITH RANGE LIMIT
// ===================================================
int read_integer_in_range(string prompt, int min, int max)
{
    int value = read_integer(prompt);
    while (value < min || value > max)
    {
        write_line("Please enter a number between " + to_string(min) + " and " + to_string(max) + ".");
        value = read_integer(prompt);
    }
    return value;
}

// ===================================================
//               DOUBLE INPUT (C-Style)
// ===================================================
double read_double(const char* prompt)
{
    double value;
    int result;

    while (true)
    {
        printf("%s", prompt);
        result = scanf("%lf", &value);

        if (result == 1)
        {
            break;
        }
        else
        {
            printf("Invalid input. Please enter a number.\n");
            scanf("%*s"); // discard invalid input
        }
    }

    return value;
}

// ===================================================
//              TERMINAL MAIN MENU DISPLAY
// ===================================================
void show_menu()
{
    write_line("\n=================================");
    write_line("         BFC MMA Simulator        ");
    write_line("=================================");
    write_line("1. Create New Fighter");
    write_line("2. View All Fighters");
    write_line("3. Train Fighter");
    write_line("4. Eating and Resting");
    write_line("5. Start Tournament");
    write_line("6. Save Fighters");
    write_line("7. Load Fighters");
    write_line("8. View Leaderboard");
    write_line("9. Exit");
    write_line("=================================");
}

// ===================================================
//               PROGRESS BAR DISPLAY
// ===================================================
string get_bar(int value, int max, int length) 
{
    int filled = (value * length) / max; // Calculate filled length
    int empty = length - filled; // Calculate empty length
    return "[" + string(filled, '#') + string(empty, '-') + "] " + to_string(value) + "%"; // Create progress bar string
}



