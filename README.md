# M-CUBE Spa Booking System

Welcome to **M-CUBE Spa**, a C-based console application designed to simulate an online spa service booking platform. This program allows users to register, view and choose from a list of spa services, select a session type, and receive discounts and surprise offers based on their birth date.

---

## 💻 Features

- Register customer details (name, email, city, DOB, phone)
- Choose between:
  - **Full Day Session (9 AM – 9 PM)** — 29% Discount
  - **Half Day Session (9 AM – 3 PM)** — 17% Discount
- View and select from a list of luxurious spa services
- Automatically calculates total cost after applicable discounts
- Get surprise offers based on the user's birthday
- Dynamic memory management for flexibility and efficiency

---

## 🧾 Services Offered

Some of the body care options include:
- Full Body Massage
- Hair Care
- Skin Care
- Pedicure
- Sauna Bath
- Herbal Bath

---

## 🎁 Surprise Offers

Birthdate-based surprises:
- Born on **12th** → Free unlimited service voucher (3 weeks)
- Born in **October (10)** → Free unlimited movie passes (15 days)
- Born in **2004** → Free solo trip to Manali

---

## 🛠️ How to Compile and Run

1. **Save the code** in a file, e.g., `mcube_spa.c`
2. **Compile** using GCC:
   ```bash
   gcc mcube_spa.c -o mcube_spa
3. Run the program:
   ./mcube_spa

   
📂 File Structure
mcube_spa.c       // Main program file
README.md         // Program description and usage guide

⚙️ Technical Concepts Used:
Structures (struct) to model User and Service
Singly Linked List for dynamic service listings
Dynamic memory allocation using malloc and realloc
Modular functions for code clarity
Basic input validation
Formatted console output for a user-friendly interface

🧹 Memory Management
The program uses malloc() and realloc() for dynamic memory allocation and includes proper cleanup using free() to prevent memory leaks.

📌 Notes
Max services a user can select:
Full Day Session → up to 6 services
Half Day Session → up to 3 services
Enter 0 to finish service selection early
Input is case-sensitive; follow prompts closely

🙏 Acknowledgements
Thanks for checking out M-CUBE Spa. For feedback or suggestions, feel free to contribute or raise an issue!
