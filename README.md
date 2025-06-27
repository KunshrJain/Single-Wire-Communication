🔌 Single-Wire Text Transmitter – Minimalist Arduino Communication Protocol
One wire. Zero libraries. All communication.
This project is a no-frills, bare-metal protocol to transmit and receive alphanumeric characters (plus space and newline) between two Arduinos using just one digital pin. It’s all done using bit-level control, timing pulses, and custom encoding — proving you don’t need UART, I2C, or SPI to get two microcontrollers talking.

🚀 Why This Exists
Sometimes, you just want to build your own protocol from scratch and see if you can bend hardware to your will. This project is all about:

Learning low-level GPIO communication

Building a 6-bit character protocol

Timing control using delay()

Sending/receiving characters without any serial link between Arduinos

Flexing your firmware fundamentals 💪

🛠️ How It Works
✅ Encoding
Each character (0-9, a-z, space, newline) is mapped to a unique 6-bit binary sequence stored in KJTP.

✅ Transmitting
A HIGH pulse (10ms) starts each bit

The bit value (HIGH or LOW) is held for 100ms

A LOW signal separates each bit

Sent via a function inside sendChar(char c)

✅ Receiving
Listens for 6 pulses

Reads each bit 50ms after HIGH is detected

Matches received bits to the character table

Displays the decoded character

🧪 Serial Terminal Integration
The receiver is always in listening mode. If you type into the serial monitor, it flips into transmit mode, sends the character, then returns to listening — smooth and automatic.

⚙️ Usage
🧰 Hardware
2x Arduino boards (Uno, Nano, ESP32, etc.)

1 jumper wire between GPIO pins on both boards (default: pin 23)

Common GND between devices

💻 Upload the Code
Flash the same sketch to both boards

Open Serial Monitor (115200 baud)

Start typing characters on one board’s monitor

The other board will decode and display them

🧪 Example Output
rust
Copy
Edit
Receiver Mode
Sending-> h
Sending-> e
Sending-> y
Receiver Mode
hey
📦 Features
📡 One-wire, bi-directional character transmission

🧠 6-bit custom encoding

✨ Supports 0–9, a–z, space, newline

🔁 Auto switches between RX/TX based on serial input

⏱️ Pure digitalWrite() and delay() — no external libs

📷 Visual (Optional GIF/Schematic)
(Add a GIF of two Arduinos communicating, or a diagram showing the pulse+bit timings)
Or just a photo of the hardware setup with labels.

🙌 Credit & Inspiration
Crafted for the joy of building something from scratch. Inspired by bit-banging, binary logic, and pushing minimalist boundaries on microcontrollers.

🔖 License
MIT – Go forth and hack.
