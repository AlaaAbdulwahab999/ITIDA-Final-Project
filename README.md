
## Bank System
![core-banking-blog-banner](https://github.com/user-attachments/assets/b7371a44-cd92-46a8-b7fd-3e270c980a4b)

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
    git clone < <repository-url>
    ```

2. Build the project:
    ```bash
    qmake
    make
    ```

3. Run the server:
    ```bash
    ./server.exe
    ```

4. Run the client:
    ```bash
    ./client.exe
    ```


### Usage

1. Start the server application.
2. Start the client application.
3. Log in as an admin or a user.
4. Perform banking operations based on the logged-in role.
5. Log out and exit the application when done.
