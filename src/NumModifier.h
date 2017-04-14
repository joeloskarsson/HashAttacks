#ifndef NUM_MODIFIER
#define NUM_MODIFIER

#include <vector>
#include "StringModifier.h"

using namespace std;

class NumModifer: public StringModifier{
public:
    vector<string> getWords(string& original) const;
    void setLimit(int lim);
private:
    int limit = 0;
};

#endif
