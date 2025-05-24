#include "fight.h"
#include "splashkit.h"
#include <algorithm>
#include <string>
#include "storage.h"


using namespace std;

// ===============================================
//               FIGHTING MECHANICS
// ===============================================
void fight(Fighter &f1, Fighter &f2) 
{
    float p1 = compute_power(f1, f2); // Compute power for fighter 1
    float p2 = compute_power(f2, f1); // Compute power for fighter 2

    write_line("");
    write_line("=========================================");
    delay(300);
    write_line("|           FIGHT COMMENCING            |");
    delay(300);
    write_line("=========================================");
    delay(500);

    write_line(">> Matchup: " + f1.fight_name + " VS " + f2.fight_name); // Display matchup
    delay(1000);

    write_line(">> Preparing the octagon...");
    delay(1000);
    write_line(">> Fighters make their entrances...");
    delay(1000);
    write_line(">> The referee gives the signal!");
    delay(800);

    float odds = p1 / (p1 + p2); // Calculate odds based on power
    write_line(">> Odds: " + f1.fight_name + " " + to_string(odds * 100) + "% | " + f2.fight_name + " " + to_string((1 - odds) * 100) + "%");
    bool f1_wins = (static_cast<float>(rand()) / RAND_MAX < odds);
    string winner = f1_wins ? f1.fight_name : f2.fight_name; // Determine winner

    // ASCII-style winner banner with dramatic delay
    write_line("");
    write_line("*****************************************"); delay(300);
    write_line("*                                       *"); delay(300);
    write_line("*           !!! WINNER !!!             *"); delay(300);
    write_line("*             " + winner + "             *"); delay(300);
    write_line("*                                       *"); delay(300);
    write_line("*****************************************"); delay(800);

    // Update stats
    if (f1_wins) 
    {
        f1.fame += 10;
        f2.fame -= 5;
        f1.wins++;
        f2.losses++;
        f1.money += 100;
    }
    else
    {
        f2.fame += 10;
        f1.fame -= 5;
        f2.wins++;
        f1.losses++;
        f2.money += 100;
    }

    // Apply fatigue and damage
    f1.health  = max(0, f1.health  - (rand() % 20 + 5)); // Random damage
    f2.health  = max(0, f2.health  - (rand() % 20 + 5)); // Random damage
    f1.stamina = max(0, f1.stamina - 10); // Decrease stamina
    f2.stamina = max(0, f2.stamina - 10); // Decrease stamina

}


// ===============================================
//               TOURNAMENT SYSTEM
// ===============================================
// Start a tournament with the given fighters
void start_tournament(Fighter fighters[], int fighter_count) 
{
    if (fighter_count < 2)
    {
        write_line("!! ERROR: You need at least 2 fighters to start a tournament.");

        return;
    }

    write_line("");
    write_line("==============================================="); delay(300);
    write_line("|           BFC TOURNAMENT BEGINS             |"); delay(300);
    write_line("==============================================="); delay(700);

    
    for (int i = 0; i < fighter_count; i++)
    {
        for (int j = i + 1; j < fighter_count; j++)
        {
            string match_title = fighters[i].fight_name + " VS " + fighters[j].fight_name; // Match title

            write_line(""); delay(300);
            write_line("***********************************************"); delay(300);
            write_line("*                 FIGHT NIGHT                *"); delay(300);
            write_line("***********************************************"); delay(300);
            write_line("*              " + match_title + "              *"); delay(300);
            write_line("***********************************************"); delay(500);

            fight(fighters[i], fighters[j]); // Conduct the fight

            write_line("-----------------------------------------------"); delay(300);
            write_line("FIGHT RESULT:"); delay(500);
            write_line(fighters[i].fight_name + " - Health: " + to_string(fighters[i].health) + " | Stamina: " + to_string(fighters[i].stamina)); delay(500); // Display fighter stats
            write_line(fighters[j].fight_name + " - Health: " + to_string(fighters[j].health) + " | Stamina: " + to_string(fighters[j].stamina)); delay(500); // Display fighter stats
            write_line("-----------------------------------------------"); delay(1000);
        }
    }

    write_line(""); delay(300);
    write_line("==============================================="); delay(300);
    write_line("|           TOURNAMENT COMPLETE               |"); delay(300);
    write_line("==============================================="); delay(1000);
}





// Power formula based on stats, health, and style
float compute_power(Fighter &f, Fighter &op)
{
    int total_belt = belt_bonus(f.belt_wrestling) // Get belt bonuses
                   + belt_bonus(f.belt_striking) // Get belt bonuses
                   + belt_bonus(f.belt_bjj); // Get belt bonuses
    float health_factor = static_cast<float>(f.health) / 100.0f; // Health factor
    float style_mul     = style_modifier(f, op); // Style modifier

    return (f.stamina + total_belt) * health_factor * style_mul; // Compute power formula 
    // Power = (Stamina + Belt Bonus) * (Health / 100) * Style Modifier
}
