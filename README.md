<h1 align="center">🧠🍽️ Philosophers</h1>

<p align="center">
  <i>A concurrency project simulating the Dining Philosophers problem with threads and mutexes.</i>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg" />
  <img src="https://img.shields.io/badge/Concurrency-Threads-red.svg" />
  <img src="https://img.shields.io/badge/Project-Philosophers-yellowgreen.svg" />
  <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" />
</p>

---

## 📌 Project Overview

**Philosophers** is a 42 curriculum project that simulates the classical Dining Philosophers problem. It demonstrates synchronization between multiple threads (philosophers) competing for limited shared resources (forks). The goal is to avoid deadlocks and starvation while ensuring all philosophers can eat.

---

## 🧠 Key Concepts

- Thread creation and lifecycle management  
- Mutex locking and unlocking for resource control  
- Deadlock prevention and starvation avoidance  
- Accurate timing for eating, sleeping, and thinking phases  

---

## 🎯 Goals

- Ensure no deadlocks occur among philosopher threads  
- Prevent starvation by allowing all philosophers to eat fairly  
- Implement precise timing for each philosopher’s actions  
- Handle edge cases and invalid inputs gracefully  

---

## 🚀 Getting Started

### 🔨 Build

```bash
git clone https://github.com/KGalstyan/Philosophers
cd Philosophers
make
