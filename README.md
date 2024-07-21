
# ITIDA-Final-Project

# Bank System
## Overview
The Bank System is a client-server application designed to manage banking operations. It supports both admin and user roles, providing different functionalities based on the role of the logged-in user. The system handles multiple client requests via sockets and threads, encrypts requests, and includes logging, service integration, and email responses.
## Features
###  Admin Role
 #### • View account numbers for users
 #### • Check user balances
 #### • View transaction history of users
 #### • Create new users
 #### • Update user data
 #### • Delete users
 #### • View entire bank database

###  User Role
#### • View account number
#### • Check balance
#### • View transaction history
#### • Deposit money
#### • Withdraw money
#### • Transfer money

## Architecture
The system follows a client-server architecture. The client application is a GUI application built with Qt/C++, while the server application is a console application handling multiple client requests using threads. The server uses JSON files for user data and logging.

## Class Diagram
![complete-class-diagram](https://github.com/user-attachments/assets/33d45f23-4b43-4d3d-b202-3298149f957f)

## Sequence Diagram
![Complete-sequance-diagram](https://github.com/user-attachments/assets/369b1e28-eec1-44e5-8d42-eb4467f3dfb5)

## State Diagram
![Complete-state-diagram](https://github.com/user-attachments/assets/520d8919-5f60-4550-bf82-87248b69873c)
