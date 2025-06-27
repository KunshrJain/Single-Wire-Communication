# 🔌 Single-Wire Text Transmitter (Minimal Arduino Protocol)

A minimal communication protocol to transmit text over a single digital pin using only timing and voltage changes — no libraries, no UART, just pure bit-banging.

This project lets one microcontroller send characters to another over a **single wire** using a custom 6-bit encoding. Ideal for learning low-level communication and timing control with Arduino.

---

## 💡 Features

- 🧠 Simple 6-bit encoding table for `a-z`, `0-9`, space, and newline
- 🔄 Bidirectional switching between Transmit/Receive based on serial input
- ⏱️ Pulse-based data signaling with minimal delays
- 💬 Real-time serial output of decoded characters
- 🔌 Single GPIO wire used for transmission

---

## 🛠️ Supported Platforms

- ✅ **Arduino IDE** (v1.x or v2.x)
- ✅ **PlatformIO** (VS Code extension)

---

## ⚙️ How It Works

1. Each character is represented by a 6-bit binary sequence.
2. To send a bit:
   - Send a **10ms HIGH pulse** to indicate the start.
   - Then send **HIGH (1)** or **LOW (0)** for the actual bit (100ms).
3. Characters are transmitted one bit at a time over the shared pin.
4. Receiver samples the bit during the data window and reconstructs the character.

---

## 🧩 Pin Configuration

| Role         | Pin Number |
|--------------|------------|
| Data (TX/RX) | D23        |
| Optional LED | D2         |

---

## 🧪 Example Usage

- Open Serial Monitor at `115200` baud.
- Type a message to send. Each character is encoded and transmitted.
- On the receiver board, the transmitted characters are printed back to the Serial Monitor.

---

## 📦 PlatformIO Setup

### 🔗 Install PlatformIO

1. Install [Visual Studio Code](https://code.visualstudio.com/)
2. Install the [PlatformIO extension](https://platformio.org/install/ide?install=vscode)

### 🧰 Project Configuration (`platformio.ini`)

ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
monitor_speed = 115200

---
# Upload code
pio run --target upload

# Open serial monitor
pio device monitor

---
🧰 Arduino IDE Setup
Open the .ino file in the Arduino IDE.

Select your board (e.g., ESP32 Dev Module).

Set the baud rate to 115200 in the Serial Monitor.

Upload and open the Serial Monitor to start communication.

---
FILE STRUCTURE:
Single_Wire_Protocol/
├── src/
│   └── main.cpp         # Your main sketch file with class-based logic
├── platformio.ini       # PlatformIO configuration
└── README.md            # This file

---


🚀 Why This Project?
This project is a fun dive into low-level communication — perfect for:

Learning how bits are transmitted manually

Testing timing accuracy on ESP32 or Arduino

Creating minimal inter-device comms without I2C/SPI/UART overhead

Impressing friends with a "protocol from scratch"

🙌 Contributing
Pull requests and feature suggestions are welcome!

📜 License
MIT License

🧠 Author
Made with curiosity by [Kunsh Jain]
Inspired by raw electronics and the joy of blinking bits
