GreensOnly — Demo & Integration Test README

This file documents how to run the interactive demo and the integration test runner (itests) for this project.

Prerequisites
- A C++17 toolchain (g++/clang) with make.
- Python 3 (for `tests/checker.py`).
- On Windows: WSL is recommended for running the bash-based itest runner. PowerShell runner is available too.

Build
From the repository root:

WSL / Linux / macOS
```bash
make -j4
```

Windows (PowerShell)
```powershell
make -j4
```

This creates `build/main` (the interactive demo binary) and object files under `build/`.

Run the interactive demo
To start the interactive TUI/demo:

WSL / Linux / macOS
```bash
./build/main
# or
make run
```

Windows (PowerShell)
```powershell
.\build\main
# or
make run
```

Notes:
- The program currently prints a set of internal unit/integration test outputs before the interactive menu. Scroll until you see the main menu heading ("=== WELCOME TO GREENSONLY ===").
- Use the menu numbers to navigate (Customer, Staff, Settings, Exit). Inputs accept compact forms such as `i1` or `i 1` where indicated.

Integration tests (itests)
The repository includes a small integration test harness under `tests/`.

- Inputs: `tests/inputs/*.txt` (each file contains the newline-separated stdin sequence for a test case)
- Expected patterns: `tests/expected/*.txt` (one regex per line, blank lines and lines starting with `#` are ignored). The checker strips ANSI before matching.
- Test runners:
  - `tests/run_and_check.sh` — bash/WSL runner
  - `tests/run_and_check.ps1` — PowerShell runner

Run the default itests target (WSL-friendly):

WSL / Linux / macOS
```bash
make itests
```

This runs `./tests/run_and_check.sh case2` by default (the repository's `itests` target is configured to run `case2`).

To run a specific case manually:

WSL / bash
```bash
cd /path/to/repo
./tests/run_and_check.sh case2
# or any other case id, e.g. case3
./tests/run_and_check.sh case3
```

PowerShell
```powershell
cd $PSScriptRoot\..\
.\tests\run_and_check.ps1 -case case2
```

Adding a new test case
1. Create `tests/inputs/caseN.txt` with the exact stdin sequence (one answer per line, include final newline/EOF as appropriate).
2. Create `tests/expected/caseN.txt` containing ordered regex patterns (one per line) to match the program output after ANSI stripping. Lines starting with `#` or blank lines are ignored.
3. Run the runner as shown above: `./tests/run_and_check.sh caseN`.

Troubleshooting
- "Pattern X not found" from `checker.py` means the expected regex didn't match the captured stdout. Open `tests/outputs/caseN.out` to inspect the actual program output and update the expected regex accordingly.
- If you see `make: warning: Clock skew detected. Your build may be incomplete.` it can be caused by system clock/timezone differences between Windows and WSL; re-run `touch` on files or `make clean` then `make` to restore proper timestamps.
- Ensure `python3` is on PATH in WSL when using the bash runner.
