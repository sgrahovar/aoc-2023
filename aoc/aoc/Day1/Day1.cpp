//
//  Day1.cpp
//  aoc-2023
//
//  Created by Sanjin Grahovar Sadiković on 01.12.2023.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>

#include <unistd.h> // for getcwd()


class Day1{
private:
    std::vector<std::string> input1;
    std::vector<std::string> input2;
    
public:
    Day1(){
        
    }
    
    std::vector<std::string> loadInput(std::string inputFile){
        std::vector<std::string> inputList;
        
        std::ifstream file(inputFile);
        std::string str;
                        
        if (file.is_open()) {
            while(std::getline(file, str)){
                inputList.push_back(str);
            }
        }

        return inputList;
    }
    
    int solveFirst(){
        // this->input1 = loadInput("Day1/input_example.txt");
        this->input1 = loadInput("Day1/input_first.txt");
        int sum = 0;
        
        for(int i = 0; i < input1.size(); i++){
            for(int j = 0; j < input1[i].size(); j++){
                if(isdigit(input1[i][j])){
                    // std::cout << "Left: " << input1[i][j] << std::endl;
                    for(int k = input1[i].size(); k >= 0; k--){
                        if(isdigit(input1[i][k])){
                            // std::cout << "Right: " << input1[i][k] << std::endl;
                            int number = (input1[i][j] - '0') * 10 + input1[i][k] - '0';
                            sum += number;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        
        return sum;
    }
    
    int isNumber(std::string line, int begin){
        std::vector<std::string> numbers = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        
        for(int j = 0; j < numbers.size(); j++){
            // std::cout << "Word: " << line.substr(i, numbers[j].size() - i) << std::endl;
            std::string word = line.substr(begin, numbers[j].size());
            if( line.substr(begin, numbers[j].size()) == numbers[j] ){
                std::cout << "True " << numbers[j] << std::endl;
                return j+1;
            }
        }
        
        return false;
    }
    
    int solveSecond(){
        // this->input2 = loadInput("Day1/input_example_2.txt");
        this->input2 = loadInput("Day1/input_first.txt");
        
        int sum = 0, left, right;
        int tmpNumber;
        
        for(int i = 0; i < input2.size(); i++){
            left = 0;
            right = 0;
            std::cout << input2[i] << std::endl;
            
            for(int j = 0; j < input2[i].size(); j++){
                tmpNumber = isNumber(input2[i], j);
                
                if(isdigit(input2[i][j]) || tmpNumber != false){
                    if(isdigit(input2[i][j])){
                        left = input2[i][j] - '0';
                    }
                    else {
                        left = tmpNumber;
                    }
                    
                    for(int k = input2[i].size() - 1; k >= j; k--){
                        tmpNumber = isNumber(input2[i], k);
                        
                        if(isdigit(input2[i][k]) || tmpNumber  != false){
                            if(isdigit(input2[i][k])){
                                right  = input2[i][k] - '0';
                            }
                            else {
                                right = tmpNumber;
                            }
                            
                            break;
                        }
                    }
                    
                    sum += (left * 10) + right;
                    break;
                }
            }
        }
        return sum;
    }
};
