//
//  Day2.cpp
//  aoc-2023
//
//  Created by Sanjin Grahovar Sadiković on 02.12.2023.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>

#include <unistd.h> // for getcwd()


class Day2{
private:
    std::vector<std::string> input1;
    std::vector<std::string> input2;
    
public:
    Day2(){
        
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
    
    
    int getNumber(std::string line, int index){
        std::string digit;
        
        for(int i = index - 4; i < index; i++){
            if(isdigit(line[i])){
                digit.push_back(line[i]);
            }
        }
        
        // std::cout << "Digit: " << digit << std::endl;
        
        return std::stoi(digit);
    }
    
    
    bool checkColor(std::string line, std::string substring, int color){
        std::vector<size_t> positions;
        size_t pos = line.find(substring, 0);
        
        while(pos != std::string::npos)
        {
            positions.push_back(pos);
            pos = line.find(substring, pos + 1);
        }
        
        for(int i = 0; i < positions.size(); i++){
            // std::cout << "Positions " << substring << ": " << positions[i] << std::endl;
            int number = getNumber(line, positions[i]);
            if(number > color) return false;
        }
        
        return true;
    }
    
    
    int solveFirst(){
        // this->input1 = loadInput("Day2/input_example.txt");
        this->input1 = loadInput("Day2/input_first.txt");
        
        int sum = 0;
        int redCube = 12;
        int greenCube = 13;
        int blueCube = 14;
        
        for(int i = 0; i < input1.size(); i++){
            int id = std::stoi(input1[i].substr(4, input1[i].find(":")));
            std::cout << "ID: " << id << std::endl;
            
            std::string rest = input1[i].substr(input1[i].find(":") + 1);
            std::cout << "Rest: " << rest << std::endl;
            
            if(checkColor(rest, "red", redCube) && checkColor(rest, "blue", blueCube) && checkColor(rest, "green", greenCube)){
                sum += id;
            }
        }
        
        return sum;
    }
    
    
    int getMaxColor(std::string line, std::string substring){
        std::vector<size_t> positions;
        size_t pos = line.find(substring, 0);
        
        while(pos != std::string::npos)
        {
            positions.push_back(pos);
            pos = line.find(substring, pos + 1);
        }
        
        int maxColor = 0;
        
        for(int i = 0; i < positions.size(); i++){
            // std::cout << "Positions " << substring << ": " << positions[i] << std::endl;
            int number = getNumber(line, positions[i]);
            if(number > maxColor) maxColor = number;
        }
        
        return maxColor;
    }
    
    
    int solveSecond(){
        // this->input1 = loadInput("Day2/input_example.txt");
        this->input1 = loadInput("Day2/input_first.txt");
        
        int sum = 0;
        
        for(int i = 0; i < input1.size(); i++){
            int id = std::stoi(input1[i].substr(4, input1[i].find(":")));
            std::cout << "ID: " << id << std::endl;
            
            std::string rest = input1[i].substr(input1[i].find(":") + 1);
            std::cout << "Rest: " << rest << std::endl;
            
            sum += getMaxColor(rest, "red") * getMaxColor(rest, "blue") * getMaxColor(rest, "green");
        }
        
        return sum;
    }
    
    
};
