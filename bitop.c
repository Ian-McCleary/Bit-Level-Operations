/* course csci 247
lab2.c
Name; Ian McCleary
*/

#include <stdio.h>
#include <iostream>

//forward declarations
void newSanitation();
void getbit(int num);
void getbit_p(int num, int bitInt);
void get_nbits(int num, int bitInt);
void setbit(int num);
void setbit_p(int num, int bitInt);
void set_nbits(int num, int bitInt);
void clearbit(int num);
void clearbit_p(int num, int bitInt);
void clear_nbits(int num, int bitInt);
int getInteger();
int getBitInt();

//main method
//starts the continuous loop by calling newSanitation
int main(int argc, char* argv[]){
    newSanitation();
    return(0);
}

//method for managing method selection
//Also calls user input helper functions for each method
//called at the end of each method to create a continuous loop
void newSanitation(){
    std::cout << "Your options are: \n";
    std::cout << "getbit\n";
    std::cout << "getbit_p\n";
    std::cout << "get_nbits\n";
    std::cout << "setbit\n";
    std::cout << "setbit_p\n";
    std::cout << "set_nbits\n";
    std::cout << "clearbit\n";
    std::cout << "clearbit_p\n";
    std::cout << "clear_nbits\n";
    std::cout << "quit (or press EOF hotkey) \n";

    std::string whichFunction;
    std::getline(std::cin, whichFunction);
    char *cstr = &whichFunction[0];

    if (whichFunction == "getbit"){
        int num = getInteger();
        getbit(num);
    } else if (whichFunction == "getbit_p"){
        int num = getInteger();
        int bitInt = getBitInt();
        getbit_p(num, bitInt);
    }else if (whichFunction == "get_nbits"){
        int num = getInteger();
        int bitInt = getBitInt();
        get_nbits(num, bitInt);
    }else if (whichFunction == "setbit"){
        int num = getInteger();
        setbit(num);
    }else if (whichFunction == "setbit_p"){
        int num = getInteger();
        int bitInt = getBitInt();
        setbit_p(num, bitInt);
    }else if (whichFunction == "set_nbits"){
        int num = getInteger();
        int bitInt = getBitInt();
        set_nbits(num, bitInt);
    }else if (whichFunction == "clearbit"){
        int num = getInteger();
        clearbit(num);
    }else if (whichFunction == "clearbit_p"){
        int num = getInteger();
        int bitInt = getBitInt();
        clearbit_p(num, bitInt);
    }else if (whichFunction == "clear_nbits"){
        int num = getInteger();
        int bitInt = getBitInt();
        clear_nbits(num, bitInt);
    }else if (whichFunction == "quit"){
        exit(1);
    } else {
        printf("%s", "Your input was not recognized");
    }
}

//method for getbit
//get the least significant bit
//1 argument for number
void getbit(int num){

    int bit = num & 1;
    printf("%d\n\n", bit);
    newSanitation();
}

//method for getbits_p
//right shift the number by x and get the least significant bit
//2 arguments for number and bit position
void getbit_p(int num, int bitInt){

    int newNum = num >> bitInt;
    int bit = newNum & 1;
    printf("%d\n\n", bit);
    newSanitation();
}

//method for get_nbits
//2 arguments for number and bit position
void get_nbits(int num, int bitInt){

    for (int i=0; i < bitInt; i++){
        int bit = num & 1;
        std::cout << bit;
        num = num >> 1;
    }
    std::cout << "\n\n";
    newSanitation();
}

//method for setbit
//1 argument for number
void setbit(int num){

    num |= 1;
    std::cout << num << "\n";
    newSanitation();
}

//method for setbit_p
//2 arguments for number and bit position
void setbit_p(int num, int bitInt){

    int newNum = num |= 1 << bitInt;
    std::cout << newNum << "\n";
    newSanitation();
}

//method for set_nbits
//2 arguments for number and bit position
void set_nbits(int num, int bitInt){

    int newNum = num;
    for (int i=0; i < bitInt; i++){
        newNum = newNum |= 1 << i;
    }
    std::cout << newNum << "\n";
    newSanitation();
}

//method for clearbit
//1 argument for number
void clearbit(int num){

    num &= ~1;
    std::cout << num << "\n";
    newSanitation();
}

//method for clearbit_p
//2 arguments for number and bit position
void clearbit_p(int num, int bitInt){

    num &= ~(1 << bitInt);
    std::cout << num << "\n";
    newSanitation();
}

//method for clear_nbits
//2 arguments for number and bit position
void clear_nbits(int num, int bitInt){

    int newNum = num;
    for (int i = 0; i < bitInt; i++){
        newNum &= ~(1 << i);
    }
    std::cout << newNum << "\n";
    newSanitation();
}

//User input functions used for each method 
//returns int specified by user input used as input number
int getInteger(){

    std::cout << "\nPlease enter an integer number:\n";
    std::string strNum;
    std::getline(std::cin, strNum);
    int num = std::stoi(strNum);
    return num;
}

//returns int specified by user input for bit position
int getBitInt(){

    std::cout << "Please enter a bit position as an integer\n";
    std::string bitNum;
    std::getline(std::cin, bitNum);
    int bitInt = std::stoi(bitNum);
    return bitInt;
}
