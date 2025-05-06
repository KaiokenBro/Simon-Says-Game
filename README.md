# Simon Says

Simon Says is a desktop application that emulates the classic memory game where players must repeat an ever-growing sequence of colors. 
Built using C++ and the Qt framework, this project showcases a Model-View-Controller (MVC) architecture to separate game logic from the user interface.

## 🎮 Features
- Interactive GUI with colored buttons representing game inputs
- Audio feedback for each button press using .wav sound files
- Randomized color sequences that increase in length with each round
- MVC design pattern for clean separation of concerns
- Built with Qt 6.8.2 and MinGW 64-bit toolchain

## 🛠️ Technologies Used
- C++: Core programming language
- Qt Framework: For GUI components and application structure
- QMake: Build system (Simon-Says.pro project file)
- WAV Audio Files: For button sound effects

## 📁 Project Structure
```bash
Simon-Says/
├── build/                          # Build directory for compiled binaries
├── blueButtonSound.wav             # Sound for blue button
├── redButtonSound.wav              # Sound for red button
├── main.cpp                        # Application entry point
├── mainwindow.cpp/.h/.ui           # Main window implementation and UI layout
├── model.cpp/.h                    # Game logic and state management
├── resources.qrc                   # Qt resource file for bundling assets
├── Simon-Says.pro                  # QMake project file
└── .gitignore                      # Git ignore file
```

## 🚀 Getting Started
**Prerequisites**
- Qt Creator 6.8.2 installed on your system
- C++ compiler (e.g., MinGW 64-bit)

**Build & Run**
1. Clone the repository:
```bash
git clone https://github.com/hdoppelt/Simon-Says.git
cd Simon-Says
```
2. Open Simon-Says.pro in Qt Creator.
3. Configure the project with the appropriate kit (e.g., Desktop Qt 6.8.2 MinGW 64-bit).
4. Build and run the project within Qt Creator.

## 📄 License
This project is licensed under the MIT License. See the LICENSE file for details.

## 👤 Author
hdoppelt
