# Windows Setup Guide for Emotion-Based Study Assistant

Since C++ and OpenCV are not natively set up on Windows out-of-the-box, the easiest way to compile this code and avoid hours of building from source is by using **MSYS2**. It provides pre-compiled binaries for both the C++ compiler (`g++`) and `OpenCV`.

Share these instructions with your team members so everyone can successfully compile the project on their Windows machines.

## Step 1: Install MSYS2
1. Go to the [MSYS2 Official Website](https://www.msys2.org/).
2. Download the installer (e.g., `msys2-x86_64-*.exe`) and run it.
3. Follow the installation wizard and keep the default installation folder (`C:\msys64`).

## Step 2: Install Compiler and OpenCV
1. From your Start menu, open **MSYS2 UCRT64** (Look specifically for the **UCRT64** terminal, usually has a yellow/blue icon).
2. Update the package database by running:
   ```bash
   pacman -Syu
   ```
   *(If it asks to close the terminal to finish the update, type `Y`, close it, and reopen the MSYS2 UCRT64 terminal).*
3. Now, install the compiler, OpenCV, and pkg-config by pasting this command:
   ```bash
   pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-opencv mingw-w64-ucrt-x86_64-pkgconf
   ```
4. Press `Enter` to proceed and type `Y` whenever prompted to install the packages. This may take a few minutes as OpenCV is a large library.

## Step 3: Add to System Path
To let your normal Windows Command Prompt or VS Code terminal recognize `g++`, you need to add the newly installed `bin` folder to your System PATH.
1. Press the `Windows Key`, type **Environment Variables**, and select **Edit the system environment variables**.
2. Click the **Environment Variables...** button at the bottom right.
3. Under **System variables** (or User variables), find the `Path` variable and click **Edit**.
4. Click **New** and add the following path exactly: `C:\msys64\ucrt64\bin`
5. Click **OK** on all windows to save it.

> [!WARNING]
> **Important:** Close any currently open VS Code or terminal windows and reopen them so that the new PATH is loaded!

## Step 4: Verify Installation
Open a new normal terminal (like PowerShell or Command Prompt) and type:
```bash
g++ --version
pkg-config --version
```
If both print version numbers, you are perfectly set up!

## Step 5: Compilation
Now you can compile the project!

**Option A: Using MSYS2 Terminal (Recommended)**
If you open the MSYS2 UCRT terminal and navigate to your code folder (e.g., `cd /c/Users/...`), you can use the exact command from the README:
```bash
g++ main.cpp face_detection.cpp emotion_simulator.cpp decision_engine.cpp productivity_tracker.cpp -o app `pkg-config --cflags --libs opencv4`
```

**Option B: Using PowerShell / VS Code Terminal**
PowerShell handles command expansions differently. If you are compiling from PowerShell, use this command:
```powershell
$cflags = (pkg-config --cflags opencv4) -split ' '
$libs = (pkg-config --libs opencv4) -split ' '
g++ main.cpp face_detection.cpp emotion_simulator.cpp decision_engine.cpp productivity_tracker.cpp -o app.exe $cflags $libs
```

## Step 6: Run the App
```bash
./app.exe
```
Make sure that `haarcascade_frontalface_default.xml` is located in the same directory as the executable. Smile at the camera and watch it suggest your study breaks!
