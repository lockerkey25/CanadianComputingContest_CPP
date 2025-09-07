// Common.h
#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;

class Common {
protected:
    string filePath;
    ifstream fileBufferReader;
    const string RESOURCE_FOLDER = "Resources/";

public:
    Common(const string fileName);
    virtual ~Common();

    void solveAndDisplay();

    virtual int solveProblem() = 0;
    virtual void parseData() = 0;

};

#endif
