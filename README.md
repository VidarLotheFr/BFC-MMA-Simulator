# 🥋 BFC MMA Simulator

**BFC MMA**  is a terminal-based career simulator for MMA fighters, built in C++ using SplashKit. Players can create and train fighters, simulate tournaments, track wins, manage XP, and progress through a full fight career system, complete with encrypted save files and a dynamic leaderboard.


---

## 🎯 Purpose

This project was created for the High Distinction task **"Something Awesome"** in **SIT102** at Deakin University. Its goal is to demonstrate creative design, modular programming, file encryption, and advanced logic beyond the standard curriculum.

---

## 🚀 Features

### 👤 Fighter System
- Create fighters with names, styles, and origin countries
- Train in Wrestling, BJJ, or Striking to earn XP and upgrade belts
- Rest to recover stamina and health between matches

### 🎓 Career Progression
- Fighters gain XP and level up automatically
- Career titles are awarded based on level: *Rookie*, *Prospect*, *Contender*, *Champion*, *Legend*
- XP progress bar rendered using ASCII art

### 🔐 Encrypted Save/Load System
- Fighter data is encrypted with a custom XOR cipher
- Files are unreadable outside the game
- Errors are handled safely with `try/catch` validation

### 📊 Dynamic Leaderboard
- Win ratios are calculated and sorted from encrypted save data
- Leaderboard displays fighter name, fame, wins, losses, and level
- Uses lambda-based sorting with `std::sort`

### 🎨 Terminal UI
- Styled menus and structured ASCII output
- Dramatic pacing using delays for immersion
- Minimal dependencies and clean file structure

---

## 📂 File Structure

├── main.cpp // Program entry point and menu

├── fighter.cpp/.h // Fighter logic, XP, belts, career system

├── fight.cpp/.h // Tournament system and fight engine

├── storage.cpp/.h // Encrypted save/load functionality

├── utilities.cpp/.h // Input handling, progress bars, formatting

├── fighters.txt // Encrypted fighter data file


---

## 🛠️ How to Run

1. **Install SplashKit**: [https://www.splashkit.io/](https://www.splashkit.io/)
2. **Compile with:**
   ```bash
   clang++ main.cpp fighter.cpp fight.cpp storage.cpp utilities.cpp -l SplashKit -o mma



| Feature                 | Description                                              |
| ----------------------- | -------------------------------------------------------- |
| 🔐 Encrypted save/load  | Secure file I/O with XOR encryption and error handling   |
| 🎓 Career progression   | XP-based leveling and title assignment with progress bar |
| 📊 Leaderboard system   | Win ratio calculation and dynamic sorting                |
| 🎨 Terminal UX design   | Structured formatting, delays, and output polish         |
| 🧱 Modular architecture | Separated concerns across `.cpp/.h` files                |


📽️ Video Demo
[![Watch on YouTube]](https://youtu.be/A7sN0Ulpnfs)





👋 Author
Vidar – Deakin University
SIT102 Introduction to Programming




