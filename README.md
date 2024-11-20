# 🖥️ Operating Systems II Laboratory

This repository contains implementations for Operating Systems II laboratory experiments, focusing on file operations, process management, and system programming concepts.

## 🛑 Important Note

Experiments 1, 2, 9, and 10 are not included in this repository as they focus on:
- Experiment 1: Linux Command Implementation
- Experiment 2: File Linking and Shell Operations
- Experiment 9: Text Processing and Filtering
- Experiment 10: Shell Scripting

These experiments are practical, hands-on sessions performed directly in the terminal and do not require C programming implementations

## 🗂️ Repository Structure

```bash
.
├── Experiment 3/
│   ├── Exp3a.c    # File read mode operations with error handling
│   ├── Exp3b.c    # File read operations with error checking
│   └── Exp3c.c    # Read-write mode operations
├── Experiment 4/
│   ├── Exp4a.c    # File operations with descriptor handling
│   ├── Exp4b.c    # Write-only mode operations
│   └── Exp4c.c    # Read-write mode with content verification
├── Experiment 5/
│   ├── Exp5a.c    # File holes creation (75kb, 150kb, 12000kb)
│   └── Exp5b.c    # Non-hole file creation and comparison
├── Experiment 6/
│   ├── Exp6a.c    # String writing with 2KB hole
│   └── Exp6b.c    # Character 'A' writing with block analysis
├── Experiment 7/
│   ├── Exp7a.c    # Fork() with process IDs
│   ├── Exp7b.c    # Parent-child variable scope
│   ├── Exp7c.c    # File sharing in processes
│   ├── Exp7d.c    # Vfork() implementation
│   └── Exp7e.c    # Exec command execution
└── Experiment 8/
    ├── Exp8a.c    # Unnamed pipe communication
    ├── Exp8b.c    # Named pipe (FIFO) implementation
    ├── Exp8c.c    # Multi-reader single writer
    ├── Exp8d.c    # Signal handling with file operations
    └── Exp8e.c    # Custom sleep implementation
```

## ✅📋 Prerequisites
- GCC Compiler
- UNIX-based Operating System (Linux/MacOS)
- Make utility

## 🚀 Running the Programs

1. Navigate to specific experiment directory:
```bash
cd Experiment<number>
```
2. Compile the program:
```bash
gcc -o output Exp<number><letter>.c
```
3. Execute the program:
```bash
./output
```
## 🔑🛠️ Special Commands Used
- `fork()`: Creates a new process by duplicating the calling process.
- `ls -ls`: Lists files with detailed information.
- `od -c`: Displays file contents in ASCII characters.
- `pipe()`: Creates a pipe for inter-process communication.
- `mkfifo`: Creates a named pipe (FIFO).
- `alarm()`: Schedules an alarm to trigger a signal.
- `cat`: Displays file contents.
- `pause()`: Pauses the process until a signal is received.
- `signal()`: Sets a signal handler for a specific signal.
- `kill()`: Sends a signal to a process.
- `wait()`: Waits for a child process to terminate.
- `exit()`: Terminates the current process.

## 📝 Notes
- Some programs require root privileges for execution
- File operations should be performed with appropriate permissions
- Signal handling programs require proper signal generation for testing

## 🤝✨ Contributing
This is a personal laboratory work repository. Feel free to fork and use it as reference.

