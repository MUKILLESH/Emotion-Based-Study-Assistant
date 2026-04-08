# Emotion-Based Study Assistant (C++ & OpenCV)

A beginner-friendly Object-Oriented Programming (OOP) project for first-year students. This application uses your computer's webcam to detect your face, simulates an emotion from a list of possibilities, provides a study suggestion based on that emotion, and tracks your focus productivity over time!

## Features
- **Face Detection:** Uses OpenCV and Haar Cascades.
- **Emotion Simulation:** Randomly cycles through Happy, Sad, Angry, Neutral, Sleepy.
- **Decision Engine:** Gives tips based on your current state (e.g., "Take a short break" if Sad).
- **Productivity Tracker:** Calculates your overall focus percentage.

## File Structure

- `main.cpp` - Entry point that glues all parts together.
- `face_detection.h / .cpp` - Handles OpenCV webcam feed and box drawing.
- `emotion_simulator.h / .cpp` - Logic to generate random emotions.
- `decision_engine.h / .cpp` - Maps an emotion to an actionable string.
- `productivity_tracker.h / .cpp` - Maintains counts to calculate productivity score.

---

## 🛠️ Build and Run Instructions

### 1. Prerequisites
- **C++ Compiler:** Make sure `g++` is installed.
- **OpenCV:** Install OpenCV 4 for your operating system.
- **Haar Cascade File:** You need the `haarcascade_frontalface_default.xml` file. 
  *You can download it securely from the [official OpenCV GitHub repository](https://raw.githubusercontent.com/opencv/opencv/master/data/haarcascades/haarcascade_frontalface_default.xml) and place it in the same folder as `main.cpp`.*

### 2. Compilation
Open your terminal in this directory and execute the following command:

```bash
g++ main.cpp face_detection.cpp emotion_simulator.cpp decision_engine.cpp productivity_tracker.cpp -o app `pkg-config --cflags --libs opencv4`
```

### 3. Execution
Run the compiled application:
**On Linux / Mac OS:**
```bash
./app
```
**On Windows:**
```bash
app.exe
```

---

## 👥 GitHub Group Workflow (4 Members)

This project is perfectly sized for a 4-person team. Here is how your group can divide and conquer using GitHub!

### The Setup
1. **Repository Creation:** One person creates the GitHub repository and invites the other 3 as collaborators.
2. **First Push:** The creator uploads the initial `main.cpp` (which can just be an empty template) and `haarcascade_frontalface_default.xml`.
3. **Branching:** Everyone clones the repository and creates their own branch: `git checkout -b <your-name>-module`

### Division of Labor

**👤 Member 1: The Visionary (Face Detection Module)**
- **Task:** Create `face_detection.h` and `face_detection.cpp`.
- **Goal:** Set up the Haar cascades and the `detectAndDraw()` function.
- **Commit:** `git add face_detection.*`, then `git commit -m "Add face detection module"`, then `git push origin <your-name>-module`.

**👤 Member 2: The AI Engineer (Emotion Simulator Module)**
- **Task:** Create `emotion_simulator.h` and `emotion_simulator.cpp`.
- **Goal:** Use `rand()` to cycle and return a mock string emotion.
- **Commit:** Push your two files just like Member 1.

**👤 Member 3: The Logic Master (Decision Engine Module)**
- **Task:** Create `decision_engine.h` and `decision_engine.cpp`.
- **Goal:** Build a robust `if-else` map matching an emotion string to a tip.
- **Commit:** Push your files to your branch.

**👤 Member 4: The Data Analyst (Productivity Tracker Module)**
- **Task:** Create `productivity_tracker.h` and `productivity_tracker.cpp`.
- **Goal:** Accumulate "focused" counts vs total time and calculate a ratio!
- **Commit:** Push your new `.h` and `.cpp` files.

### Bringing it All Together (The Merge)
1. On GitHub, each person creates a **Pull Request (PR)** from their module branch into the `main` branch.
2. The team reviews the PRs together and merges them one by one.
3. Finally, everyone does `git pull origin main` to get all the files locally.
4. **Integration:** Together, the team updates `main.cpp` to include the new headers (`#include "face_detection.h"`, etc.) and sets up the webcam loop to utilize the classes!
