# Multithreaded-Banking-Simulation

## Project Description

This project demonstrates the use of threads in C to simulate banking operations, such as deposits and withdrawals, with synchronization mechanisms (mutexes and condition variables). The program implements a system to secure critical sections and ensure the correctness of operations on a shared resource.

## Files

- `zad1.c`: A basic version of the program that simulates deposits and withdrawals using critical sections secured with a mutex.
- `zad2.c`: An extended version of the program that adds logic for waiting until the balance is sufficient before processing a withdrawal and additional synchronization mechanisms.

## Features

1. Simulation of concurrent deposits and withdrawals to a shared account.
2. Protection of critical sections using:
   - **Mutexes (`pthread_mutex_t`)**.
   - **Condition variables (`pthread_cond_t`)**.
3. Handling situations where the balance is insufficient for a withdrawal by waiting using condition variables.
