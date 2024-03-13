**Password_generator.cpp - documentation.**

This program's purpose is generating a password which length is specified by the user.

**How does this program work?**

Firstly, this program takes amount of characters which generated password should have from the user. Then, program randomly generates and converts into signs according to ascii code as many numbers as user specified and adds all of these characters to the passwordChars string. After this step, program displays the final form of passwordChars string (which is a password generated for the user).

**How to use this program?**

If user uses Linux device:

In order to use this program, user has to open terminal, change directory to the location where this program is saved on user's device, compile it by typing 'g++ password_generator.cpp -o password_generator.exe' and run it by typing './password_generator.exe'. Then, user has to insert amount of characters which generated password should have and then program will display generated password. Disclaimer - before folowing these steps, make sure g++, or other c++ compiler, is installed on your device.

If user uses Windows device:

In order to use this program, user has to open Windows Powershell, change directory to the location where this program is saved on user's device, compile it by typing 'g++ password_generator.cpp -o password_generator.exe' and run it by typing './password_generator.exe'. Then, user has to insert amount of characters which generated password should have and then program will display generated password.

**Description of all program's variables:**

| variable name | variable description |
| ------------- | -------------------- |
| amountOfCharacters | Integer, stores amount of characters which generated password should have. Its value is determined by the user. |
| charNumber | Integer, its value is randomly generated and then it's converted into a sign using ascii code. |
| passwordChars | String, stores all the signs converted from previously generated numbers. |

**Description of all program's functions:**

| function name | function description |
| ------------- | -------------------- |
| takeAmountOfCharacters | This function takes amount of characters generated password should be made of from the user. |
| generateChar | This function randomly generates a number, which is then converted into a sign according to ascii code. |