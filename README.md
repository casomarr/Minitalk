<a href="https://www.linux.org/"><img src="https://img.shields.io/badge/Linux-CCAC00?style=for-the-badge&logo=Linux&logoColor=white" height="25em" alt="Linux"/></a>
<a href="https://www.cprogramming.com"><img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" height="25em" alt="C"/></a>

# Minitalk

## Goal
Create a simplified client-server communication system using signals (SIGUSR1 and SIGUSR2) to transmit messages as binary data. This project is designed to introduce the concept of bit manipulation and signal handling in Unix systems.

## Key Features
- Client: Sends a message as a sequence of bits to the server.
- Server: Receives the bits, reconstructs the message, and displays it.
- Signal Handling: Uses SIGUSR1 and SIGUSR2 to represent binary data (1 and 0).

## Implementation Details
While the project is intended to teach bit shifting for encoding and decoding messages, I implemented it differently at the time. 
The project consists of two programs: a client and a server.

- Client:
    - Sends a message character by character to the server.
    - Each character is broken down into its 8-bit binary representation using a static array of binary weights (128, 64, 32, etc.).
    - Each bit is sent to the server as a signal (SIGUSR1 for 1 and SIGUSR2 for 0).
    - Waits for the server to acknowledge receipt of each bit (SIGUSR1) before sending the next one.

- Server:
    - Listens for incoming signals from the client.
    - Accumulates 8 bits to reconstruct each character using a reverse lookup of binary weights.
    - Once a full character is received, it is appended to the message.
    - Signals the client when it is ready to receive the next bit (SIGUSR1).
    - Prints the complete message when the null terminator (\0) is received.
  
Signal handling is implemented using the sigaction system call to ensure reliable communication between processes.

## Challenges
- Bit Manipulation: Implementing binary encoding/decoding without bit shifting required careful handling of binary weights.
- Synchronization: Ensuring the server and client stayed in sync during communication.
- Error Handling: Managing edge cases like invalid PIDs or interrupted signals.

## Skills Developed
- Signal Handling: Mastering Unix signals and inter-process communication.
- Binary Data Processing: Understanding how characters are represented and transmitted as binary data.
- Debugging: Troubleshooting communication issues between processes.

## Installation

1. **Clone the repository to your local machine:**
	```sh
	git clone git@github.com:casomarr/42-Minitalk.git
	```

2. **Navigate to the project directory:**
	```sh
	cd 42-Minitalk
	```

3. **Compile the project:**
	```sh
   make

4. **Start the server:**
```sh
./server  
```
The server will display its PID, which is needed for the client to connect.

5. **Use the client to send a message to the server:**
```sh
./client <server_PID> <message>  
```
Example:
```sh
./client 12345 "Hello, World!"  
```
The server will display the received message.

