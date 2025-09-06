// Question2.cpp
#include "Question2.h"

Question2::Question2(const string fileName) : Common(fileName) {
    return;
}
 
void Question2::parseData() {
    try {
        string line;
        // mustTogether
        getline(fileBufferReader, line);
        lengthOfMustTogether = stoi(line);
        mustTogether.resize(lengthOfMustTogether);
        for (int i = 0; i < lengthOfMustTogether; i++) {
            getline(fileBufferReader, mustTogether[i]);
        }

        // mustSeparate
        getline(fileBufferReader, line);
        lengthOfMustSeparate = stoi(line);
        mustSeparate.resize(lengthOfMustSeparate);
        for (int i = 0; i < lengthOfMustSeparate; i++) {
            getline(fileBufferReader, mustSeparate[i]);
        }

        // groups
        getline(fileBufferReader, line);
        lengthOfGroups = stoi(line);

        for (int i = 0; i < lengthOfGroups; i++) {
            getline(fileBufferReader, line);
            istringstream iss(line);
            string a, b, c;
            iss >> a >> b >> c;
            groupMap[a] = i;
            groupMap[b] = i;
            groupMap[c] = i;
        }

    } catch (...) {
        throw runtime_error("Error parsing Question2 input");
    }
}

bool Question2::inSameGroup(const string& condition) {
    istringstream iss(condition);
    string x, y;
    iss >> x >> y;

    return groupMap[x] == groupMap[y];
}

int Question2::solveProblem() {
    int violations = 0;

    // mustTogether
    for (int i = 0; i < lengthOfMustTogether; i++) {
        if (!inSameGroup(mustTogether[i])) {
            violations++;
        }
    }

    // mustSeparate
    for (int i = 0; i < lengthOfMustSeparate; i++) {
        if (inSameGroup(mustSeparate[i])) {
            violations++;
        }
    }

    return violations;
}
