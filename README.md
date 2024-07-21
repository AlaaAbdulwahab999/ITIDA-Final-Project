# ITIDA-Final-Project

## Bank System

### Overview

The Bank System is a client-server application designed to manage banking operations. It supports both admin and user roles, providing different functionalities based on the role of the logged-in user. The system handles multiple client requests via sockets and threads, encrypts requests, and includes logging, service integration, and email responses.

### Features

#### Admin Role
- View the account number of a client.
- View the balance for a client.
- View the transaction history of a client.
- Create new users
- Update user data
- Delete user
- View entire bank database

#### User Role
- View account number
- Check balance
- View transaction history
- Deposit money
- Withdraw money
- Transfer money

### Architecture
The system follows a client-server architecture. The client application is a GUI application built with Qt/C++, while the server application is a console application handling multiple client requests using threads. The server uses JSON files for user data and logging.

## Sequence Diagram
![Complete-sequance-diagram](https://github.com/user-attachments/assets/369b1e28-eec1-44e5-8d42-eb4467f3dfb5)

### Installation

#### Prerequisites
- Qt6
- C++ compiler
- JSON library
- Git (optional, for version control)

#### Steps

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/bank-system.git
    cd bank-system
    ```

2. Build the project:
    ```bash
    qmake
    make
    ```

3. Run the server:
    ```bash
    ./server_application
    ```

4. Run the client:
    ```bash
    ./client_application
    ```
