#include "storage.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
#include "splashkit.h"

// Simple reversible XOR encryption/decryption
string xor_encrypt_decrypt(const string &input, char key = 'K')
{
    string output = input; // Create a copy of the input string
    for (char &c : output) // Iterate through each character
    {
        c ^= key;  // XOR each character with the key
    }
    return output; // Return the encrypted/decrypted string
}




// ===================================================
//                  SAVE FIGHTERS
// ===================================================
// Writes all fighter data to a CSV file
void save_fighters(const Fighter fighters[], int count, const string &filename)
{
    ofstream file(filename); // Open file for writing
    if (!file.is_open()) { // Check if file opened successfully
        cerr << "Failed to open file for saving: " << filename << endl; // Error message
        return; // Exit if file can't be opened
    }

    for (int i = 0; i < count; ++i) { // Loop through each fighter
        const Fighter &f = fighters[i]; // Get reference to fighter
        // Write fighter data to file in CSV format
    string line = f.name + "," +
              f.fight_name + "," +
              f.origin + "," +
              f.style + "," +
              to_string(f.health) + "," +
              to_string(f.stamina) + "," +
              to_string(f.fame) + "," +
              to_string(f.money) + "," +
              to_string(f.xp_wrestling) + "," +
              to_string(f.xp_striking) + "," +
              to_string(f.xp_bjj) + "," +
              f.belt_wrestling + "," +
              f.belt_striking + "," +
              f.belt_bjj + "," +
              to_string(f.wins) + "," +
              to_string(f.losses);

    file << xor_encrypt_decrypt(line) << "\n"; // Encrypt the line before writing

    }

    file.close(); // Close the file
}

// ===================================================
//                  LOAD FIGHTERS
// ===================================================
// Reads fighter data from a CSV file and populates the array
int load_fighters(Fighter fighters[], int max_count, const string &filename)
{
    ifstream file(filename); // Open file for reading
    if (!file.is_open()) // Check if file opened successfully
    {
        cerr << "Failed to open file for loading: " << filename << endl; // Error message
        return 0; // Exit if file can't be opened
    }

    int count = 0; // Counter for fighters loaded
    string line; // Line buffer for reading file

    while (getline(file, line) && count < max_count) // Read each line until end of file or max count
    {
        line = xor_encrypt_decrypt(line);  // Decrypt first!
        stringstream ss(line); // Create a string stream for parsing
        string token; // Token buffer for parsing
        Fighter f; // Create a new fighter object

        try // Try to parse the line
        {
            getline(ss, f.name, ','); //
            getline(ss, f.fight_name, ',');
            getline(ss, f.origin, ',');
            getline(ss, f.style, ',');


            // Parse fighter stats
            // Note: stoi and stof will throw exceptions if conversion fails
            // These exceptions are caught below
            getline(ss, token, ','); f.health = stoi(token); 
      
            getline(ss, token, ','); f.stamina = stoi(token);
            getline(ss, token, ','); f.fame = stoi(token);
            getline(ss, token, ','); f.money = stof(token);
            getline(ss, token, ','); f.xp_wrestling = stoi(token);
            getline(ss, token, ','); f.xp_striking = stoi(token);
            getline(ss, token, ','); f.xp_bjj = stoi(token);

            getline(ss, f.belt_wrestling, ',');
            getline(ss, f.belt_striking, ',');
            getline(ss, f.belt_bjj, ',');

            getline(ss, token, ','); f.wins = stoi(token);
            getline(ss, token, ','); f.losses = stoi(token);

            fighters[count++] = f; // Add fighter to array
        }
        
        catch (const std::exception &e) 
        {
            write_line("⚠️ Error loading fighter at line " + to_string(count + 1)); // Error message
            write_line("Reason: " + string(e.what())); // Display error reason
            write_line("Raw decrypted line: " + line); // Display raw line
            continue;  // Skip this fighter, try next
        }
    }

    file.close(); // Close the file
    return count; // Return number of fighters loaded
}

