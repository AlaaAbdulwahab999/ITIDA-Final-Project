
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

The system follows a client-server architecture:

- **Client Application**: 
  - A GUI application built with Qt/C++.
  - Utilizes Object-Oriented Programming (OOP) principles.

- **Server Application**: 
  - A console application handling multiple client requests using threads.
  - Utilizes Object-Oriented Programming (OOP) principles.

- **Data Management**: 
  - The server uses JSON files for user data and logging.

### Installation

#### Prerequisites
- Qt6
- C++ compiler
- JSON library
- Git (optional, for version control)

#### Steps

1. Clone the repository:
    ```bash
    git clone < repository-url>
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
3. When prompted, enter the server's IP address and port to connect.
    - Example:
        ```
        Enter server IP: 192.168.1.100
        Enter server port: 12356
        ```
4. Log in as an admin or a user.
5. Perform banking operations based on the logged-in role.
6. Log out and exit the application when done.

### Photos
1- start the application 

![Bank1](https://github.com/user-attachments/assets/c93ca596-1dfb-4fdb-9db0-44f2111b2e30)

2- Enter ip and port to connect to the server

![Connection](https://github.com/user-attachments/assets/74de74be-6042-47d5-970e-368ba8864e7e)

3- Login as User or Admin

![login](https://github.com/user-attachments/assets/d5707e14-dc91-40d0-bed7-dfe844d74bb1)

4- Admin Features

![Admin](https://github.com/user-attachments/assets/8c58950d-c5e4-49b2-b3fc-c2023787a1d9)

5- User Features 

![user](https://github.com/user-attachments/assets/e58cd924-efa3-4294-8cd3-9ea279993d4f)

