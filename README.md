# WM361_CW

## Table of contents
* [Introduction](#introduction)
* [Installation](#installation)
* [Compile and Run](#compile-and-run)

## Introduction
This project relates to the WM361 Coursework, a leave management system developed in c++. The functionality of the system depends on the employee's job roll,
for example, only managers will approve or decline leave whilst only HR can change an employees job role.

## Installation

To edit this project and run locally:

* Create a directory where the project will be located
* Make sure that is the current directory in your terminal
* Copy the HTTPS line for this repo in the 'Code' drop-down
* In your terminal type: git clone [paste the https link]


## Compile and Run
* Make sure your terminal is in the project directory
On Mac 
* type: make
* Once compiled type: ./main 
* The main file should be running in your terminal

On Windows
* Run the following commands in the project directory:
* g++ -c Employee.cpp -o Employee.o 
* g++ -c HumanResources.cpp -o HumanResources.o
* g++ -c ITS.cpp -o ITS.o
* g++ -c Manager.cpp -o Manager.o
* g++ -c Login.cpp -o Login.o
* g++ -c main.cpp -o main.o
* g++ main.o ITS.o HumanResources.o Employee.o Manager.o Login.o  -o main.exe
* ./main.exe


## Org Chart
![img.png](misc/org_chart.png)
