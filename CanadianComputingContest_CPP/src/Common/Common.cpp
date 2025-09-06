// Common.cpp
#include "Common.h"
using namespace std;


Common::Common(const string fileName) {
    filePath = RESOURCE_FOLDER + fileName;
    fileBufferReader.open(filePath);

}

Common::~Common() {
    if (fileBufferReader.is_open()) {
        fileBufferReader.close();
    }
}

void Common::solveAndDisplay() {
    auto start = chrono::high_resolution_clock::now();

    parseData();
    int answer = solveProblem();

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    cout << "Time taken: " << duration << "ms" << std::endl;
    cout << typeid(*this).name() << " Answer: " << answer << std::endl;
}