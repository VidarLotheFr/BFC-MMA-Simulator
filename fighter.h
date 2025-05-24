// fighter.h
#ifndef FIGHTER_H
#define FIGHTER_H

#include <string>
using std::string;

struct Fighter {
    string name, fight_name, origin, style;
    int health, stamina, fame, money;
    int xp_wrestling = 0;
    int xp_striking = 0;
    int xp_bjj = 0;
    string belt_wrestling = "white";
    string belt_striking = "white";
    string belt_bjj = "white";
    int wins = 0;
    int losses = 0;
};

// Fighter-related functions
Fighter create_fighter();
void print_fighter(const Fighter &f);
void train_fighter(Fighter *f);
void rest_fighter(Fighter *f);
float style_modifier(const Fighter &attacker, const Fighter &defender);
int belt_bonus(const string &belt);
void select_and_train(Fighter fighters[], int fighter_count);
void select_and_rest(Fighter fighters[], int fighter_count);
void show_leaderboard();
int total_xp(const Fighter &f);
int fighter_level(const Fighter &f);
string fighter_title(int level);


enum Belt {
    WHITE,
    BLUE,
    PURPLE,
    BROWN,
    BLACK
};

Belt belt_from_xp(int xp);
string belt_name(Belt b);

#endif
