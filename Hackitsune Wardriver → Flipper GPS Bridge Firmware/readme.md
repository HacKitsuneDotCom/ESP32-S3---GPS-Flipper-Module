# 🛰️ Hackitsune Wardriver → Flipper GPS Bridge Firmware

Turn your **Hackitsune Wardriver module** into a dedicated GPS bridge for the Flipper Zero — streaming live position data directly into the Flipper’s **GPIO GPS app**, while also exposing NMEA output over USB for PC use.

---

## ✨ Overview

This firmware repurposes the Hackitsune Wardriver ESP32-S3 module into a **dual-output GPS interface**:

* 📡 **Outputs live NMEA GPS data to Flipper GPIO (UART)**
* 💻 **Mirrors GPS data over USB serial to your computer**
* ⚡ **Simple, lightweight firmware focused purely on GPS passthrough**

Perfect for:

* Portable GPS display via Flipper UI
* Logging or debugging GPS data on your laptop simultaneously

---

## 🔌 How It Works

The firmware reads GPS data from the onboard **L86 GNSS module** and forwards it to:

### 1. Flipper Zero (GPIO UART)

* Sends NMEA over UART → readable by the Flipper GPS app
* Default wiring:

  * **ESP TX (GPIO43)** → Flipper **RX (Pin 14)**
  * **ESP RX (GPIO44)** ← Flipper **TX (Pin 13)** *(optional)*
  * **GND ↔ GND**

### 2. USB Serial (PC)

* Same NMEA stream available via native USB (CDC)
* View using any serial monitor at **115200 baud**

---

## 📟 Supported Output

The firmware outputs standard **NMEA 0183 sentences**, including:

```text
$GNRMC
$GPGGA
$GPGSV
$GNGSA
$GNGLL
$GPVTG
```

This is fully compatible with the Flipper Zero GPS application.

---

## 🚀 Flashing the Firmware

You can flash this firmware directly to your WARDRIVER module using the Hackitsune web flasher:

👉 https://www.hackitsune.com/pages/flasher

### Steps:

1. Connect your Hackitsune Wardriver via USB
2. Open the flasher page in Chrome / Edge
3. Select the Wardriver module
4. select **GPS Bridge Firmware**
5. Click **Flash**
6. Wait for completion and reboot

---

## 📱 Using with Flipper Zero

1. Dont forget to enable GPIO 5v (required to power the GPS module)
2. Launch the **GPS app** on your Flipper
3. Set baud rate to **9600** 
4. You should immediately see:

   * Coordinates
   * Satellites
   * Speed / movement

NOTE: it may take a few minutes to get an initial satelight fix based on location and other variables.
For best results face the module towards the sky.
---

## 💻 Using with a PC

1. Plug the device into your computer via USB
2. Open a serial monitor at **115200 baud**
3. You will see live NMEA output:

```text
$GNRMC,....
$GPGGA,....
```

This is ideal for:

* Logging
* Debugging
* Integration with mapping tools

---

## ⚠️ Important Notes

* This firmware is **GPS-only**
* It **replaces ESP Marauder functionality**

If you want to restore full wireless / Marauder capabilities:

👉 Reflash with ESP32 Marauder firmware

---

## 🧠 Why This Exists

Marauder does support GPS, but this firmware provides:

* ✅ **Instant GPS compatibility with Flipper apps**
* ✅ **No configuration o**
