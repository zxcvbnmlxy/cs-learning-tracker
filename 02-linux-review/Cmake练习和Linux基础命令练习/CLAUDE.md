# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is an **educational repo** for learning Linux basics, CMake, and g++ compilation. It is part of a broader "cs-learning-tracker" that also includes LeetCode solutions. The code is written as tutorial examples with extensive inline comments — treat comments as part of the learning content, not noise.

## Build & Run Commands

### CMake Practice
```bash
cd LinuxCmakeCppPractice/cmake_practice
mkdir -p build && cd build
cmake ..
cmake --build .
./bin/MathDemo
```

### g++ Practice (simple)
```bash
cd LinuxCmakeCppPractice/gpp_practice
g++ helloworld.cpp -o helloworld
./helloworld
```

### g++ Practice (multi-file)
```bash
cd LinuxCmakeCppPractice/gpp_practice
# Option A: one command
g++ multi_file/main.cpp multi_file/greet.cpp -o greet_app
./greet_app

# Option B: Makefile
make run
make clean
```

### Linux Basics (shell scripts)
```bash
cd LinuxCmakeCppPractice/linux_basics
bash 01_file_operations.sh
bash 02_text_processing.sh
# ... etc
```

### Compilation Steps Demo
```bash
cd LinuxCmakeCppPractice/gpp_practice
bash compile_steps/steps_demo.sh
bash compile_steps/compile_flags.sh
```

## Architecture

The project under `LinuxCmakeCppPractice/` has three independent modules:

```
LinuxCmakeCppPractice/
├── linux_basics/         # 🐧 Linux command practice
│   ├── 01-05_*.sh        #   Tutorial scripts (run with bash)
│   ├── score_data.txt    #   Sample data for text processing exercises
│   └── references/       #   grep/sed/awk reference guides (markdown)
├── cmake_practice/       # 📦 CMake build system tutorial
│   ├── CMakeLists.txt    #   Root: defines project, C++11, adds subdirs
│   ├── lib/              #   Static library (MathUtils)
│   │   ├── CMakeLists.txt
│   │   ├── math_util.h   #   namespace math { max, min, is_prime, gcd, ... }
│   │   └── math_util.cpp
│   └── app/              #   Executable linking the library
│       ├── CMakeLists.txt
│       └── main.cpp      #   Demo driver calling math:: functions
└── gpp_practice/         # 🔨 g++ compilation tutorial
    ├── helloworld.cpp    #   Simplest C++ program
    ├── multi_file/       #   Multi-file compilation demo
    │   ├── main.cpp / greet.h / greet.cpp
    ├── compile_steps/    #   Preprocess → Compile → Assemble → Link
    │   ├── steps_demo.sh
    │   └── compile_flags.sh
    ├── gpp_cheatsheet.sh #   g++ flag reference
    └── Makefile          #   Build system for multi_file/ (not cmake)
```

### Key Design Points

- **Each module is independent** — they share no code dependencies. The learning path is: linux_basics → gpp_practice → cmake_practice.
- **`cmake_practice`** demonstrates a real CMake project structure: a static library target (`MathUtils`) with `PUBLIC` include directories, linked (`PRIVATE`) into an executable target (`MathDemo`). The root `CMakeLists.txt` controls subdirectory ordering (lib before app).
- **`gpp_practice`** shows three compilation approaches: single command, step-by-step (`.cpp` → `.i` → `.s` → `.o` → executable), and Makefile.
- **`linux_basics`** contains self-contained bash scripts that teach commands by printing explanations and running them. The `score_data.txt` file is sample data used by the text processing exercises. Reference markdown files under `references/` serve as quick-reference cheatsheets for grep/sed/awk.
- **`math_util.h/cpp`** uses `namespace math` and covers: basic arithmetic, prime checking, GCD/LCM, Fibonacci, statistics (mean/stddev).
