# Nickvision::System

This module contains various helper namespaces and objects for working with the system shell.

## Table of Contents
- [Environment](#environment)
- [Process](#process)
- [ProcessExitedEventArgs](#processexitedeventargs)
- [SuspendInhibitor](#suspendinhibitor)

## Environment
Description: Helper functions for working with the system shell environment.

Interface: [environment.h](/include/system/environment.h)

Type: `namespace`

Path: `Nickvision::System::Environment`

### Methods
- ```cpp
  std::string getVariable(const std::string& key)
  ```
    - Accepts: The name of the environment variable, key.
    - Returns: The value of the environment variable with name key.
    - Returns: An empty string if no environment variable with the name key was found.
    - Ex: `Environment::getVariable("PATH")` will return the value of the system's path variable.
- ```cpp
  bool setVariable(const std::string& key, const std::string& value)
  ```
    - Accepts: The name of the environment variable, key, and the value to set said variable to, value.
    - Returns: `true` if the environment variable of name key was set to value.
    - Returns: `false` if setting the environment variable failed.
    - Ex: `Environment::setVariable("AURA", "true")` will set `"$AURA:true"`.
- ```cpp
  bool clearVariable(const std::string& key)
  ```
    - Accepts: The name of the environment variable to clear, key.
    - Returns: `true` if the environment variable of name key was cleared.
    - Returns: `false` if clearing the environment variable failed.
- ```cpp
  std::string exec(const std::string& command)
  ```
    - Accepts: The command to executed, command.
    - Returns: The output of the executed command.
    - Ex: `Environment::exec("echo Hello World")` will return `"Hello World"`.

## Process
Description: A managed process.

Interface: [process.h](/include/system/process.h)

Type: `class`

Path: `Nickvision::System::Process`

### Member Variables
- ```cpp
  std::filesystem::path Path: get
  ```
    - The path of the process.
- ```cpp
  bool IsRunning: get
  ```
    - Whether or not the process is running
- ```cpp
  bool HasCompleted: get
  ```
    - Whether or not the process has completed
- ```cpp
  int ExitCode: get
  ```
    - The exit code of the process.
    - NOTE: Will be -1 if the process has not completed.
- ```cpp
  std::string Output: get
  ```
    - The console output of the process.

### Events
- ```cpp
  Event<Nickvision::System::ProcessExitedEventArgs> Exited
  ```
    - Invoked when the process has exited

### Methods
- ```cpp
  Process(const std::filesystem::path& path, const std::vector<std::string>& args)
  ```
    - Constructs a Process.
    - Accepts: The path of the process to run, path, and optional command line arguments to pass to the process, args
    - Throws: std::runtime_error if the process could not be created
- ```cpp
  ~Process()
  ```
    - Destructs a Process.
    - NOTE: This method will wait for the process to exit if it is still running.
- ```cpp
  bool start()
  ```
    - Returns: True if the process was started.
    - Returns: False if the process was not started.
- ```cpp
  bool kill()
  ```
    - Returns: True if the process was killed.
    - Returns: False if the process was not killed.
- ```cpp
  int waitForExit()
  ```
    - Returns: The exit code of the process after it was waited to have completed.

## ProcessExitedEventArgs
Description: Event args for when a process has exited.

Interface: [processexitedeventargs.h](/include/system/processexitedeventargs.h)

Type: `class`

Path: `Nickvision::System::ProcessExitedEventArgs`

### Member Variables
- ```cpp
  int ExitCode: get
  ```
    - The exit code of the process
- ```cpp
  std::string Output: get
  ```
    - The console output of the process

### Methods
- ```cpp
  ProcessExitedEventArgs(int exitCode, const std::string& output)
  ``` 
    - Constructs a ProcessExitedEventArgs.
    - Accepts: The exit code of the process, exitCode, and the console output of the process, output.

## SuspendInhibitor
Description: An object to prevent the system from suspending.

Interface: [suspendinhibitor.h](/include/system/suspendinhibitor.h)

Type: `class`

Path: `Nickvision::System::SuspendInhibitor`

### Member Variables
- ```cpp
  bool IsInhibiting: get
  ```
    - Whether or not the system is being inhibited from suspending.

### Methods
- ```cpp
  SuspendInhibitor()
  ```
    - Constructs a SuspendInhibitor.
    - Note: This will not inhibit the system from suspending until the inhibit() function is called.
- ```cpp
  ~SuspendInhibitor()
  ```
    - Destructs a SuspendInhibitor.
    - Note: If the system is being inhibited, it will uninhibit.
- ```cpp
  bool inhibit()
  ```
    - Returns: True if inhibiting system suspend.
    - Returns: False if error.
- ```cpp
  bool uninhibit()
  ```
    - Returns: True if not inhibiting system suspend.
    - Returns: False if error.