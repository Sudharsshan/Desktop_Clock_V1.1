---
project_id: P2603PE-02
title: Desktop Clock V2
owner: personal
status: ACTIVE
ideation_date: 2026-03-18
domain: "- physical"
subdomains: "- electrical"
repository: NA
hardware: "true"
tags:
  - electrical
  - hardware
  - project
  - LCD_16x2
---

# Desktop Clock V2

## Overview

Desktop Clock V2 is the second-generation iteration of the original ESP8266-powered desktop clock project.

The first version successfully demonstrated internet-synchronized timekeeping using a P10 LED matrix display. While functional, the design was oversized, power-hungry, and heavily dependent on a dedicated power supply.

Version 2 focuses on solving those limitations by introducing:

* Significantly lower power consumption
* Smaller physical footprint
* USB-powered operation
* Battery backup capability
* Improved portability

The result is a practical desktop clock that can remain powered continuously while occupying only a fraction of the space and power budget of its predecessor.

---

## Motivation

The original Desktop Clock served its purpose well but revealed several shortcomings during daily use:

### Problems in V1

* Large physical size due to the P10 LED display
* High power consumption
* Required a dedicated power supply
* Not portable
* Difficult to place on smaller desks

These observations led to the development of a more compact and energy-efficient design.

---

## Design Goals

### Primary Goals

* Reduce overall power consumption
* Minimize physical size
* Allow operation from common USB power sources
* Add battery backup capability
* Retain Wi-Fi based time synchronization

### Secondary Goals

* Improve reliability
* Simplify deployment
* Reduce operating cost
* Create a device suitable for continuous 24/7 operation

---

# Hardware

## Core Components

| Component              | Purpose                               |
| ---------------------- | ------------------------------------- |
| ESP8266 (NodeMCU)      | Main Controller                       |
| LCD 16x2 Display       | Time and Date Display                 |
| USB Type-A Power Input | Primary Power Source                  |
| Battery Backup System  | Power Continuity                      |
| Supporting Components  | Wiring, connectors, mounting hardware |

---

# System Architecture

```text
          Internet
              │
              ▼
        NTP Time Sync
              │
              ▼
         ESP8266
              │
              ▼
         LCD 16x2
              │
              ▼
        Time Display
```

### Power Architecture

```text
USB Power
    │
    ▼
ESP8266
    │
    ├── LCD Display
    │
    └── Battery Backup
```

---

# Key Improvements Over V1

## 1. Display Technology

### V1

* P10 LED Matrix
* Large display area
* High brightness
* High power consumption

### V2

* LCD 16x2
* Compact design
* Readable indoors
* Extremely low power requirement

### Result

Significant reduction in system power consumption.

---

## 2. Power Consumption

### ESP8266 Consumption

| Mode        | Current      |
| ----------- | ------------ |
| Typical     | ~100mA       |
| Wi-Fi Burst | Up to ~300mA |

Compared to the P10 display used in V1, the LCD consumes only a small fraction of the power.

Benefits include:

* Lower heat generation
* Improved efficiency
* Longer battery runtime
* Reduced power supply requirements

---

## 3. Form Factor

One of the largest improvements in V2 is the physical footprint.

### V1

* Large LED display
* Required external PSU
* Occupied significant desk space

### V2

* Palm-sized design
* USB powered
* Easily portable
* Cleaner installation

The device can comfortably fit on a study table, workbench, or bedside desk.

---

## 4. Power Source Flexibility

The clock is powered through a standard USB Type-A connector.

Compatible sources include:

* Mobile chargers
* Power banks
* Laptop USB ports
* Desktop USB ports
* USB hubs

This removes the need for a dedicated power supply.

---

# Features

## Time Synchronization

* Automatic NTP synchronization
* Internet-based time updates
* No manual time adjustment required

## Date Display

* Current date display
* Automatic updates

## Low Power Operation

* Suitable for 24/7 use
* Minimal energy consumption

## Compact Design

* Small desktop footprint
* Portable and lightweight

## Battery Backup

* Continues operation during temporary power interruptions
* Improved reliability

---

# Lessons Learned From V1

Several lessons from the original project directly influenced the design of V2:

### Bigger is not always better

The P10 display looked impressive but consumed unnecessary power for a simple clock.

### Simplicity improves reliability

Reducing component count leads to fewer failure points.

### USB power is everywhere

Designing around common power standards makes a device significantly more practical.

### Efficiency matters

A clock runs continuously, making power efficiency an important consideration.

---

# Future Improvements

## Planned Features

### Battery Status Monitoring

Display:

* Battery percentage
* Charging state
* Estimated runtime

### Wi-Fi Configuration Portal

Allow Wi-Fi credentials to be configured without modifying firmware.

### Temperature Sensor

Add environmental monitoring.

### Alarm Functionality

* Daily alarms
* Scheduled reminders

### Web Dashboard

Remote monitoring and configuration through a browser.

### Automatic Brightness Control

Adjust display visibility based on ambient lighting.

---

# Project Status

| Feature              | Status      |
| -------------------- | ----------- |
| Hardware Design      | Complete    |
| Firmware Development | Complete    |
| Time Synchronization | Complete    |
| LCD Integration      | Complete    |
| USB Power Support    | Complete    |
| Battery Backup       | In Progress |
| Web Configuration    | Planned     |
| Advanced Features    | Planned     |

---

# Gallery

Project Photos:

https://photos.app.goo.gl/xuiCg68TFanPNWjKA

---

# Repository

Source Code:

https://github.com/Sudharsshan/Desktop_Clock_V1.1.git

---

# Related Project

This project is a direct successor to:

**Desktop Clock V1**

The first-generation design utilized a P10 LED matrix display and served as the foundation for all subsequent improvements introduced in V2.
