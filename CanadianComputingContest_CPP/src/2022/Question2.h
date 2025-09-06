// Question2.h

#ifndef Question2_H
#define Question2_H

#include "../Common/Common.h"
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

class Question2 : public Common {
private:
    vector<string> mustTogether;
    vector<string> mustSeparate;
    unordered_map<string, int> groupMap;

    int lengthOfMustTogether = 0;
    int lengthOfMustSeparate = 0;
    int lengthOfGroups = 0;

    bool inSameGroup(const string& condition);

public:
    Question2(const string fileName);

    void parseData() override;
    int solveProblem() override;
};

#endif 
