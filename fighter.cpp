#include "fighter.h"
#include "utilities.h"
#include "fight.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#include "splashkit.h"
#include "storage.h"

// ===============================================
//              FIGHTER CREATION
// ===============================================
Fighter create_fighter() {
    write_line("=========================================");
    write_line("|         CREATE YOUR FIGHTER           |");
    write_line("=========================================");

    Fighter f; // Initialize fighter
    f.name = read_string("Enter your name: "); // Get fighter name
    f.fight_name = read_string("Enter your fight name: ");
    f.origin = read_string("Enter your origin: ");
    f.style = read_string("Choose a style (Boxing/Karate/Muay Thai): ");

    f.health = 100;
    f.stamina = 100;
    f.fame = 0;
    f.money = 100;
    f.belt_wrestling = "white";
    f.belt_striking = "white";
    f.belt_bjj = "white";

    return f;
}

// ===============================================
//              FIGHTER PROFILE VIEW
// ===============================================
void print_fighter(const Fighter &f) { // Print fighter stats
    write_line("-----------------------------------------");
    write_line("              FIGHTER STATS              ");
    write_line("-----------------------------------------");
    write_line("Name:        " + f.name);
    write_line("Fight Name:  " + f.fight_name);
    write_line("Origin:      " + f.origin);
    write_line("Style:       " + f.style);
    write_line("Health:      " + get_bar(f.health));
    write_line("Stamina:     " + get_bar(f.stamina));
    write_line("Fame:        " + to_string(f.fame));
    write_line("Money:       $" + to_string(f.money));
    write_line("Belts:       Wrestling: " + f.belt_wrestling +
               ", Striking: " + f.belt_striking +
               ", BJJ: " + f.belt_bjj);
    write_line("Level: " + to_string(fighter_level(f)) + 
           " (" + fighter_title(fighter_level(f)) + ")");
    write_line("XP: " + to_string(total_xp(f)) + "/" + 
           to_string((fighter_level(f)) * 100));
   write_line("Progress: " +
           get_bar(total_xp(f) % 100, 100, 20)); 

    write_line("Wins:        " + to_string(f.wins));
    write_line("Losses:      " + to_string(f.losses));
    write_line("-----------------------------------------");
}

// ===============================================
//              BELT SYSTEM HELPERS
// ===============================================
Belt belt_from_xp(int xp) { // Determine belt color based on XP
    if (xp >= 200) return BLACK;
    if (xp >= 150) return BROWN;
    if (xp >= 100) return PURPLE;
    if (xp >= 50)  return BLUE;
    return WHITE;
}

string belt_name(Belt b) { // Convert belt enum to string
    switch(b) {
        case WHITE:  return "white";
        case BLUE:   return "blue";
        case PURPLE: return "purple";
        case BROWN:  return "brown";
        case BLACK:  return "black";
    }
    return "white";
}

int belt_bonus(const string &belt) { // Get bonus based on belt color
    if (belt == "blue")   return 10;
    if (belt == "purple") return 20;
    if (belt == "brown")  return 30;
    if (belt == "black")  return 40;
    return 0; // white
}

// ===============================================
//                TRAINING SYSTEM
// ===============================================
void train_fighter(Fighter *f) { // Train fighter
    write_line("-----------------------------------------");
    write_line("           TRAINING SESSION              ");
    write_line("-----------------------------------------");

    int before_level = fighter_level(*f); // Get current level

    if (f->stamina < 20) {
        write_line("Too tired to train. Get some rest!");
        return;
    }

    write_line("Choose a discipline to train:");
    write_line("1. Wrestling");
    write_line("2. Striking");
    write_line("3. BJJ");

    int choice = read_integer();

    f->stamina -= 20; // Deduct stamina
    f->money  -= 10; // Deduct money
    const int xp_gain = 30; // XP gain for training

    switch(choice) { // Training options
        case 1:
            f->xp_wrestling += xp_gain;
            f->belt_wrestling = belt_name(belt_from_xp(f->xp_wrestling));
            write_line("Wrestling XP +" + to_string(xp_gain) + 
                       ". New belt: " + f->belt_wrestling);
            break;
        case 2:
            f->xp_striking += xp_gain;
            f->belt_striking = belt_name(belt_from_xp(f->xp_striking));
            write_line("Striking XP +" + to_string(xp_gain) + 
                       ". New belt: " + f->belt_striking);
            break;
        case 3:
            f->xp_bjj += xp_gain;
            f->belt_bjj = belt_name(belt_from_xp(f->xp_bjj));
            write_line("BJJ XP +" + to_string(xp_gain) + 
                       ". New belt: " + f->belt_bjj);
            break;
        default:
            write_line("Invalid option — no training completed.");

    
    }

    int after_level = fighter_level(*f); // Get new level
    if (after_level > before_level) { // Check for level up
        write_line("Congratulations! You leveled up to " +  
                   fighter_title(after_level) + "!"); // Display new title
    }
}

// ===============================================
//               REST AND RECOVERY
// ===============================================
void rest_fighter(Fighter *f) 
{
    write_line("-----------------------------------------");
    write_line("            REST AND RECOVERY            ");
    write_line("-----------------------------------------");

    const int rest_stamina = 30;
    const int rest_health  = 20;

    const int meal_stamina = 100;
    const int meal_health  = 50;
    const int eat_cost     = 20;

    write_line(f->fight_name + " needs recovery. Choose:");
    write_line("1. Quick Rest (+30 Stamina, +20 Health, Free)");
    write_line("2. Full Meal (+100 Stamina, +50 Health, Costs $20)");

    int choice = read_integer("Enter choice (1-2): ");
    if (choice == 1) {
        f->stamina = min(100, f->stamina + rest_stamina); // Recover stamina
        f->health  = min(100, f->health + rest_health); // Recover health
        write_line("Rested!Stamina is now " + to_string(f->stamina) +
                   ", Health is now " + to_string(f->health));
    }
    else if (choice == 2) {
        if (f->money >= eat_cost) { // Check if enough money
            f->money   -= eat_cost; // Deduct cost
            f->stamina = min(100, f->stamina + meal_stamina); // Recover stamina
            f->health  = min(100, f->health + meal_health); // Recover health
            write_line("Yum! Spent $" + to_string(eat_cost) +
                       ". Stamina is now " + to_string(f->stamina) +
                       ", Health is now " + to_string(f->health)); // Display new stats
        } else {
            write_line("Not enough money for a full meal!"); // Display error
            f->stamina = min(100, f->stamina + rest_stamina); // Recover stamina
            f->health  = min(100, f->health + rest_health); // Recover health
            write_line("Quick rest anyway. Stamina is now " + to_string(f->stamina) +
                       ", Health is now " + to_string(f->health)); // Display new stats
        }
    }
    else {
        write_line("Invalid choice—no recovery this time.");
    }
}


// ===============================================
//             STYLE MATCHUP BONUS
// ===============================================
float style_modifier(const Fighter &attacker, const Fighter &defender) {
    // Rock-paper-scissors logic
    if (attacker.style == "Boxing"    && defender.style == "Karate")    return 1.1f; // Boxing beats Karate
    if (attacker.style == "Karate"    && defender.style == "Muay Thai") return 1.1f; // Karate beats Muay Thai
    if (attacker.style == "Muay Thai" && defender.style == "Boxing")    return 1.1f; // Muay Thai beats Boxing
    

    return 1.0f; // No advantage
}

// ===============================================
//             FIGHTER LEADERBOARD
// ===============================================

void show_leaderboard()
{
    Fighter fighters[10]; // Array to hold fighters
    int count = load_fighters(fighters, 10, "fighters.txt"); // Load fighters from file

    if (count == 0)
    {
        write_line("No fighters found.");
        return;
    }
   
    // Lambda function to calculate win ratio
    auto win_ratio = [](const Fighter &f)  
    {
        int total = f.wins + f.losses; // Total fights
        return (total > 0) ? (float)f.wins / total : 0.0f; // Win ratio
        // Return 0 if no fights
    };

    // Sort fighters based on win ratio
    sort(fighters, fighters + count, [&](const Fighter &a, const Fighter &b) 
    {
        return win_ratio(a) > win_ratio(b); // Sort by win ratio
    });

    write_line("=======================================");
    write_line("|          FIGHTER LEADERBOARD        |");
    write_line("=======================================");

    for (int i = 0; i < count; i++)
    {
        const Fighter &f = fighters[i]; // Get fighter reference
        write_line(to_string(i + 1) + ". " + f.fight_name + 
                   " | Fame: " + to_string(f.fame) + 
                   " | Wins: " + to_string(f.wins) + 
                   " | Win Ratio: " + to_string(win_ratio(f))); // Display fighter stats
    }

    write_line("=======================================");
}


// ===============================================
//             FIGHTER LEVEL AND XP
// ===============================================
int total_xp(const Fighter &f) // Calculate total XP
{
    return f.xp_wrestling + f.xp_striking + f.xp_bjj; // Sum of all XP
}


// ================================================
//             FIGHTER LEVEL AND TITLE
// ================================================
int fighter_level(const Fighter &f) // Calculate fighter level
{
    return total_xp(f) / 100 + 1; // Level based on total XP
    // Level 1 starts at 0 XP, level 2 at 100 XP, etc.
}


// ================================================
//             FIGHTER TITLE
// ================================================
string fighter_title(int level) // Get fighter title based on level
{
    if (level < 3) return "Rookie"; 
    if (level < 6) return "Prospect";
    if (level < 9) return "Contender";
    if (level < 12) return "Champion";
    return "Legend";
}
