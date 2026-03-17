# ESP32-S3-GPS-Flipper-Module
A compact Flipper Zero add-on that pairs an ESP32-S3 with an onboard GPS and a microSD slot purpose built for [Marauder](https://github.com/HacKitsuneDotCom/ESP32Marauder) firmware, with the flexibility to flash with custom firmware of your choice. Uses the&nbsp;Flipper’s own screen and controls to navigate menus, run scans, and log results.

# 🦊 ESP Marauder (Flipper Zero) – Hackitsune Integration

## Overview

**ESP Marauder** is an open-source firmware for ESP32-based boards that enables advanced wireless auditing and research capabilities when paired with devices like the Flipper Zero.

When connected via GPIO/UART, the Flipper Zero acts as a controller and UI, while the ESP32 runs Marauder to perform WiFi and Bluetooth scanning, capture, and testing operations.

Typical use cases include:

- Wireless network discovery & analysis  
- Packet capture and logging  
- Controlled security testing of WiFi/Bluetooth environments  

---

## 🔧 Hackitsune Marauder Integration

The **Hackitsune ESP module** enhances Marauder with:

- ESP32 (S3)  
- MicroSD storage  
- GPS module (wardriving support)  
- Native Flipper Zero integration (UART + app control)  

---

## 📡 WiFi Capabilities

ESP Marauder includes a range of WiFi analysis and testing features:

- Access Point & Client scanning  
- Packet capture (PCAP format)  
- SSID enumeration and tracking  
- Frame injection (for controlled testing)  

Captured data can be stored for offline analysis via SD card and reviewed in tools such as Wireshark.

---

## 📶 Bluetooth Capabilities

- Bluetooth device discovery  
- Device logging and tracking  
- Bluetooth wardriving (location-based device mapping)  
- Exportable scan data for analysis  

---

## 💾 SD Card Support (Hackitsune Enhancement)

Hackitsune modules include built-in SD support, enabling:

- Storage of:
  - PCAP captures  
  - Scan results  
  - Wardriving logs  
- Offline analysis workflows (Wireshark, WiGLE, etc.)  

This removes reliance on serial output or reliance on the flipper's SD memory storage.

---

## 🚗 Wardriving (Key Feature)

### What is Wardriving?

Wardriving is the process of collecting wireless network metadata (WiFi/Bluetooth) alongside geographic location data while moving through an area.

This enables:

- Network mapping  
- Coverage analysis  
- Security auditing  

---

### How Marauder Supports Wardriving

With a GPS module connected:

- WiFi networks are continuously scanned  
- GPS coordinates are captured in parallel  
- Data is logged to SD card  

Typical output files:

- `wardrive_*.csv` → WiFi + GPS logs  
- `bt_wardrive_*.csv` → Bluetooth logs  

These can be uploaded to platforms like WiGLE for visualization.

---

### 🦊 Hackitsune Wardriving Module

The Hackitsune wardriving ESP module provides a fully integrated setup:

- ESP32 running Marauder firmware  
- GPS module (L86)  
- MicroSD storage  
- Flipper Zero compatibility  

#### Workflow

1. Power the device (Flipper or external battery)  
2. Launch Marauder via Flipper UI  
3. Start wardriving mode  
4. Device logs:
   - SSIDs / BSSIDs  
   - Signal strength (RSSI)  
   - Channel / encryption type  
   - GPS coordinates  
5. Export logs from SD card  
6. Upload to mapping tools (e.g. WiGLE)  

---

## ⚡ Testing Capabilities (High-Level)

ESP Marauder supports several controlled wireless testing techniques:

### Deauthentication Testing
- Sends crafted frames to disconnect clients from an access point  
- Used to validate detection and resilience  

### Beacon / SSID Simulation
- Broadcasts test SSIDs  
- Useful for detection and awareness testing  

### Probe & Scan Analysis
- Identifies nearby devices and behaviours  
- Helps assess exposure and attack surface  

---

## 🧠 Summary

The combination of:

- ESP Marauder firmware  
- Flipper Zero interface  
- Hackitsune hardware (SD + GPS integration)  

creates a **compact, field-ready wireless research platform** capable of:

- WiFi and Bluetooth environment analysis  
- Wardriving with geolocation logging  
- Packet capture and offline analysis  
- Supporting authorised security testing workflows  

---

## 🌍 Open Source & Community

In the spirit of open hardware and the broader security research community, this repository includes the **full design files** for the Hackitsune wardriving module.

This means you can:

- Review and learn from the design  
- Modify and adapt it for your own use cases  
- Reproduce the hardware yourself  

We strongly believe in contributing back to the community that makes projects like this possible — whether you're building your own tools, experimenting, or extending the platform further.

If you'd prefer a ready-to-use device, the official Hackitsune module is available here:

👉 https://www.hackitsune.com/products/wardriver

---

## ⚠️ Disclaimer

Hackitsune hardware is designed for professional security research, development, and authorised testing purposes only. Users are responsible for ensuring compliance with all applicable laws and regulations in their jurisdiction. Always obtain proper authorisation before interacting with systems, networks, or devices you do not own.  

Hackitsune accepts no liability for misuse of this product. Use responsibly. 🦊
