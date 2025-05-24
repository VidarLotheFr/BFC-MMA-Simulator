// ===================================================
//        BFC MMA SIMULATOR - MAIN PROGRAM FILE
// ===================================================
#include <string>
#include "fighter.h"
#include "fight.h"
#include "storage.h"
#include "utilities.h"
#include "splashkit.h"
using namespace std;

const int MAX_FIGHTERS = 10;
int fighter_count = 0;


int main()
{
    Fighter fighters[MAX_FIGHTERS]; // Array to hold fighters
  

    write_line("==================================");
    write_line(" Welcome to BFC - MMA Simulator! ");
    write_line("==================================");

    while (true)
    {
        show_menu();
        int option = read_integer("Choose an option: ");

        switch (option)
        {
        case 1:
            // -----------------------------------------
            // CREATE NEW FIGHTER
            // -----------------------------------------
            if (fighter_count >= MAX_FIGHTERS)
            {
                write_line("Max fighters reached!");
                break;
            }
            fighters[fighter_count] = create_fighter(); // Create a new fighter
            fighter_count++;
            write_line("Fighter created.");
            break;

        case 2:
            // -----------------------------------------
            // VIEW FIGHTERS
            // -----------------------------------------
            if (fighter_count == 0)
            {
                write_line("No fighters created yet!");
            }
            else
            {
                for (int i = 0; i < fighter_count; i++)
                {
                    write_line("----------------------------------");
                    write_line("Fighter #" + to_string(i + 1)); // Display fighter number
                    print_fighter(fighters[i]); // Print fighter details
                    write_line("----------------------------------");
                }
            }
            break;

        case 3:
            // -----------------------------------------
            // TRAIN FIGHTER
            // -----------------------------------------
            if (fighter_count == 0)
            {
                write_line("No fighters to train!");
            }
            else
            {
                for (int i = 0; i < fighter_count; i++)
                {
                    write_line(to_string(i + 1) + ". " + fighters[i].fight_name); // Display fighter name
                }
                int idx = read_integer("Select fighter (1-" + to_string(fighter_count) + "): ") - 1; // Get fighter index
                if (idx >= 0 && idx < fighter_count) 
                {
                    train_fighter(&fighters[idx]); // Train the selected fighter
                }
                else
                {
                    write_line("Invalid selection!");
                }
            }
            break;

        case 4:
            // -----------------------------------------
            // REST FIGHTER
            // -----------------------------------------
            if (fighter_count == 0)
            {
                write_line("No fighters to rest!");
            }
            else
            {
                for (int i = 0; i < fighter_count; i++)
                {
                    write_line(to_string(i + 1) + ". " + fighters[i].fight_name); // Display fighter name
                }
                int idx = read_integer("Select fighter to rest (1-" + to_string(fighter_count) + "): ") - 1;
                if (idx >= 0 && idx < fighter_count)
                {
                    rest_fighter(&fighters[idx]); // Rest the selected fighter
                }
                else
                {
                    write_line("Invalid selection!");
                }
            }
            break;

        case 5:
            // -----------------------------------------
            // START TOURNAMENT
            // -----------------------------------------
            start_tournament(fighters, fighter_count); // Start a tournament with the fighters
            break;

        case 6:
            // -----------------------------------------
            // SAVE FIGHTERS TO FILE
            // -----------------------------------------
            save_fighters(fighters, fighter_count, "fighters.txt"); // Save fighters to a file
            write_line("Fighters saved to fighters.txt");
            break;

        case 7:
            // -----------------------------------------
            // LOAD FIGHTERS FROM FILE
            // -----------------------------------------
            fighter_count = load_fighters(fighters, MAX_FIGHTERS, "fighters.txt"); // Load fighters from a file
            write_line("Fighters loaded from file.");
            break;

        case 8:
            // -----------------------------------------
            // VIEW LEADERBOARD
            // -----------------------------------------
            show_leaderboard(); // Display the leaderboard
            break;

        case 9:
            // -----------------------------------------
            // EXIT GAME
            // -----------------------------------------
            write_line("Thanks for playing!");
            return 0;

        default:
            write_line("Invalid option!");
            break;
        }
    }
}
