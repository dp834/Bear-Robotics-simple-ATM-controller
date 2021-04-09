# Bear-Robotics-simple-ATM-controller

# Installing and running
Clone the git repo and from the root of the folder run
```
mkdir build
cd build
cmake ..
make
```

To run execute the `ATMTester` file in created in the `build` folder
```
./ATMTester
```

# Features
 Testing can be done modularly either by creating a file for the class you want to test, or run certain parts in simulation on the computer while some of the system is talking to hardware.
 This is achieved by the abstraction of classes through the use of interfaces making swapping components as simple as passing the new type that implements the interface into the atm class.
 The ATM class should never need to be aware of the implementation of the classes it uses.

# Limitations/Issues

 Pin is stored as an integer so leading zeros are unused, either swap to an array/list or store as a string.
 Rereading the initial assignment I see that you are supposed to be able to select accounts after entering the card and pin, but the way I set it up a card it linked to an account and has an associated pin. I chose this as that is how my interactions at the atm go. To add multiple accounts in this system the `Account.h` class would need to be updated to know how many separate accounts exist within each person's account. The `BankAPI.h` would deal with the rest of the complication on giving the correct account information based on the account selected.
 The `SimulatedBankAPI` only has hardcoded values and doesn't save changes across reruns, to fix this it can save the config to a file and read it when loading the simulator.
 Some of the io from the user in the Simulated classes could use some polish, but it does work in it's current configuration.
 I'm not the best with C++, but I decided to use this to practice my C++ so I'm sure my style and use of some features may be incorrect.

#Bear Robotics Coding Challenge

Implement a Simple ATM controller

Write code for a simple ATM. It doesn't need any UI (either graphical or console), but a controller should be implemented and tested.


Requirements

At least the following flow should be implemented:

Insert Card => PIN number => Select Account => See Balance/Deposit/Withdraw


For simplification, there are only 1 dollar bills in this world, no cents. Thus account balance can be represented in integer.


Your code doesn't need to integrate with a real bank system, but keep in mind that we may want to integrate it with a real bank system in the future. It doesn't have to integrate with a real cash bin in the ATM, but keep in mind that we'd want to integrate with that in the future. And even if we integrate it with them, we'd like to test our code. Implementing bank integration and ATM hardware like cash bin and card reader is not a scope of this task, but testing the controller part (not including bank system, cash bin etc) is within the scope.


A bank API wouldn't give the ATM the PIN number, but it can tell you if the PIN number is correct or not.


Based on your work, another engineer should be able to implement the user interface. You don't need to implement any REST API, RPC, network communication etc, but just functions/classes/methods, etc.


You can simplify some complex real world problems if you think it's not worth illustrating in the project.


How to submit

Please upload the code for this project to GitHub or anywhere, and post a link to your repository below. Please attach the instruction to clone your project, build and run tests in README.md file in the root directory of the repository.
