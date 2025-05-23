🥋 BFC MMA Simulator
BFC MMA (Brutal Fighting Championship) is a terminal-based career simulator for MMA fighters, built in C++ using SplashKit. Players can create and train fighters, simulate tournaments, track wins, manage XP, and progress through a full fight career system — complete with encrypted save files and a dynamic leaderboard.

🎯 Purpose
This project was created for the High Distinction task "Something Awesome" in SIT102 – Introduction to Programming at Deakin University. Its goal is to demonstrate creative design, modular programming, file encryption, and advanced logic beyond the standard curriculum.

🚀 Features:

👤 Create fighters with names, styles, and origin countries
🥋 Train in Wrestling, BJJ, or Striking to earn XP and belts
🛌 Rest and recover stamina and health between matches
🏆 Compete in tournaments using a stat-based fight engine
🎓 Career Progression
📈 Fighters gain XP and level up dynamically
🎖 Titles unlocked: Rookie, Prospect, Contender, Champion, Legend
📊 XP progress bars rendered in ASCII
🔐 Encrypted Save/Load System
Fighter data is saved using XOR encryption
Files are unreadable without going through the program
Load errors handled safely with validation and fallback
📊 Dynamic Leaderboard
Win ratios are calculated and fighters are ranked
Leaderboard is sorted live from decrypted file data
Displays level, fame, wins, and losses
🎨 Terminal UI
ASCII-styled banners, structured menus, and clean formatting
Delayed pacing simulates fight suspense
Minimal dependencies, clean C++ file layout

📂 File Structure
├── main.cpp               // Program entry point and menu
├── fighter.cpp/.h         // Fighter logic, XP, belts, career system
├── fight.cpp/.h           // Tournament system and fight engine
├── storage.cpp/.h         // Encrypted save/load functionality
├── utilities.cpp/.h       // Input handling, progress bars, formatting
├── fighters.txt           // Encrypted fighter data file


🛠️ How to Run
Install SplashKit on your system
Compile with:

clang++ main.cpp fighter.cpp fight.cpp storage.cpp utilities.cpp -l SplashKit -o mma
Run the executable:
./mma


🏅 HD-Level Features

-Encrypted save/load	File I/O + data security with XOR cipher
-Career progression & titles	Derived XP, levels, and dynamic classification
-Leaderboard with win ratio	Advanced use of sorting and comparator lambdas
-Structured UI with pacing	Thoughtful user experience design
-Modular architecture	Split across .cpp/.h files, each with a clear purpose

📸 Screenshots

![image](https://github.com/user-attachments/assets/74608812-f833-4e1d-952d-96e7c00eca77)
![image](https://github.com/user-attachments/assets/8db25b30-fb93-4b35-9548-60e323d09205)
![image](https://github.com/user-attachments/assets/c9fea63d-ffc4-4e54-9fa1-efc23201d69e)
![image](https://github.com/user-attachments/assets/f091aa80-a46c-474f-a9a5-6cdf9c3318a5)




📽️ Video Demo


👋 Author
Vidar – Deakin University
SIT102 HD Task

📃 License
MIT License (or change this to what you prefer)
