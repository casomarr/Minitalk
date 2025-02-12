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
While the project is intended to teach bit shifting for encoding and decoding messages, I implemented it differently at the time. Instead of using bit shifting, I:

1. Encoded Bits: Used a static array of binary weights (128, 64, 32, etc.) to convert each character into its 8-bit binary representation.
2. Decoded Bits: Reconstructed the character by summing the weighted bits received from the client.
3. Signal Communication: Sent each bit using kill() and SIGUSR1/SIGUSR2, with the server signaling readiness for the next bit.

## Challenges
- Bit Manipulation: Implementing binary encoding/decoding without bit shifting required careful handling of binary weights.
- Synchronization: Ensuring the server and client stayed in sync during communication.
- Error Handling: Managing edge cases like invalid PIDs or interrupted signals.

## Skills Developed
- Signal Handling: Mastering Unix signals and inter-process communication.
- Binary Data Processing: Understanding how characters are represented and transmitted as binary data.
- Debugging: Troubleshooting communication issues between processes.
