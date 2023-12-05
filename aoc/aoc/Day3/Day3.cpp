//
//  Day3.cpp
//  aoc-2023
//
//  Created by Sanjin Grahovar Sadiković on 03.12.2023.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cctype>


#include <unistd.h> // for getcwd()


class Day3{
private:
    std::vector<std::string> input1;
    std::vector<std::string> input2;
    
public:
    Day3(){
        
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

    
    std::pair<int, int> getNumber(std::string line, int index){
        
        std::string stringLeft;
        std::string stringRight;
        int increment = 0;
        
        // std::cout << "Line: " << line << ", i: " << index << std::endl;
        
        for(int i = index - 1; i >= 0; i--){
            if(isdigit(line[i])){
                stringLeft.push_back(line[i]);
            }
            else{
                break;
            }
        }
                
        for(int i = index; i < line.size(); i++){
            if(isdigit(line[i])){
                stringRight.push_back(line[i]);
                increment++;
            }
            else{
                break;
            }
        }
                
        std::reverse(stringLeft.begin(), stringLeft.end());
        
        return std::pair<int, int>(stoi(stringLeft + stringRight), increment);
    }
    
    int solveFirst(){
        this->input1 = loadInput("Day3/input_first.txt");
        // this->input1 = loadInput("Day3/input_example.txt");
        int sum = 0;
                
        for(int i = 0; i < input1.size(); i++){
            // std::cout << input1[i] << std::endl;
            for(int j = 0; j < input1[i].size(); j++){
                if(ispunct(input1[i][j]) && input1[i][j] != '.'){
                    for(int k = i - 1; k < i + 2; k++){
                        for(int l = j - 1; l < j + 2; l++){
                            if(k != i || l != j){
                                if(isdigit(input1[k][l])){
                                    // std::cout << "char[" << k << "][" << l << "] = " << input1[k][l] << std::endl;
                                    std::pair<int, int> tmpPair = getNumber(input1[k], l);
                                    // std::cout << "Number: " << tmpPair.first << std::endl;
                                    sum += tmpPair.first;
                                    l+=tmpPair.second;
                                    
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return sum;
    }
    
    
    int solveSecond(){
        this->input2 = loadInput("Day3/input_first.txt");
        // this->input2 = loadInput("Day3/input_example.txt");
        int sum = 0;
        
        for(int i = 0; i < input2.size(); i++){
            // std::cout << input2[i] << std::endl;
            for(int j = 0; j < input2[i].size(); j++){
                if(ispunct(input2[i][j]) && input2[i][j] != '.'){
                    int partCount = 0;
                    std::pair<int, int> partNumbers;
                    
                    for(int k = i - 1; k < i + 2; k++){
                        for(int l = j - 1; l < j + 2; l++){
                            if(k != i || l != j){
                                if(isdigit(input2[k][l])){
                                    // std::cout << "char[" << k << "][" << l << "] = " << input2[k][l] << std::endl;
                                    std::pair<int, int> tmpPair = getNumber(input2[k], l);
                                    // std::cout << "Number: " << tmpPair.first << std::endl;
                                    if(partNumbers.first == NULL) partNumbers.first = tmpPair.first;
                                    else partNumbers.second = tmpPair.first;
                                    l+=tmpPair.second;
                                    partCount++;
                                    
                                }
                            }
                        }
                    }
                    if(partCount == 2){
                        sum += partNumbers.first * partNumbers.second;
                    }
                }
            }
        }
        
        return sum;
    }
};
