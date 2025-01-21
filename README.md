# Multithreaded-Banking-Simulation

## Project Description

This project demonstrates the use of threads in C to simulate banking operations, such as deposits and withdrawals, with synchronization mechanisms (mutexes and condition variables). The program implements a system to secure critical sections and ensure the correctness of operations on a shared resource.

## Files

- `zad1.c`: A basic version of the program that simulates deposits and withdrawals based on critical sections secured by a mutex.
- `zad2.c`: An extended version of the program that adds logic to wait for sufficient balance before processing withdrawals, along with additional synchronization mechanisms.

## Features

1. Simulation of concurrent deposits and withdrawals on a shared account.
2. Protection of critical sections using:
   - **Mutexes (`pthread_mutex_t`)**.
   - **Condition variables (`pthread_cond_t`)**.
3. Handling situations where the balance is insufficient for withdrawal by waiting via condition variables.
