//
//  Day1.cpp
//  aoc-2022
//
//  Created by Sanjin Grahovar Sadiković on 01.12.2022..
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
    std::vector<int> input1;
    std::vector<int> input2;
    
public:
    Day1(){
        
    }
    
    std::vector<int> loadInput(std::string inputFile){
        std::vector<int> inputList;
        
        std::ifstream file(inputFile);
        std::string str;
                
        if (file.is_open()) {
            while(std::getline(file, str)){
                if(str != ""){
                    inputList.push_back(std::stoi(str));
                }
                else {
                    inputList.push_back(-1);
                }
            }
        }

        return inputList;
    }
    
    int solveFirst(){
        return NULL;
    }
    
    int solveSecond(){
        return NULL;
    }
};
