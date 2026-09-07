# TCS-504 Assignment 1 — Movie Ticket Booking System

A menu-driven C++ console application for a single cinema movie ticket booking system.

## Course Details

- **Course:** B.Tech. CSE
- **Semester:** 5
- **Subject:** System Design
- **Subject Code:** TCS-504
- **Assignment:** Assignment 1

## Project Description

This project implements a small movie ticket booking system for a single cinema.

The customer can:

- View currently playing movies
- View shows for a selected movie
- View seat availability
- Book one or more seats
- Calculate ticket price according to seat type
- Pay using UPI, Card, or Cash
- Print a ticket
- Cancel a booking

## Features

1. **Movie Listing**
   - Displays all currently playing movies.

2. **Show Listing**
   - Displays available shows with screen number and start time.

3. **Seat Layout**
   - Displays seats as AVAILABLE or BOOKED.

4. **Seat Booking**
   - Allows booking of one or more seats.
   - Already booked seats are rejected.

5. **Pricing**
   - Silver: ₹150
   - Gold: ₹250
   - Platinum: ₹400

6. **Payment**
   - UPI
   - Card
   - Cash
   - Failed payment does not confirm the booking and releases the selected seats.

7. **Ticket Printing**
   - Displays booking ID, movie, screen, time, seats, amount and status.

8. **Cancellation**
   - Cancelling a booking makes its seats available again.

## OOP Concepts Used

- Encapsulation
- Abstraction
- Inheritance
- Runtime Polymorphism
- Compile-Time Polymorphism
- Static Members
- `this` Keyword
- Composition
- Aggregation
- Association

## SOLID Principles

The project demonstrates:

- **Single Responsibility Principle**
- **Open/Closed Principle**
- **Liskov Substitution Principle**
- **Dependency Inversion Principle**

## Project Structure

```text
TCS504-Assignment-1/
│
├── 01_Movie.cpp
├── 02_Seat.cpp
├── 03_Screen.cpp
├── 04_Cinema.cpp
├── 05_Show.cpp
├── 06_ShowSeat.cpp
├── 07_Customer.cpp
├── 08_Booking.cpp
├── 09_Payment.cpp
├── 10_UpiPayment.cpp
├── 11_CardPayment.cpp
├── 12_CashPayment.cpp
├── 13_PriceCalculator.cpp
├── 14_TicketPrinter.cpp
├── 15_BookingService.cpp
├── main.cpp
│
├── class_diagram.png
├── sequence_diagram.png
├── TEST_CASES.txt
└── README.md
