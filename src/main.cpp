#include <iostream>
#include <string>
#include <stdlib.h>
#include<set>
#include<vector>

#include <hashlibpp.h>
#include "FileHandler.h"
#include "DictAttack.h"
#include "NumModifier.h"
#include "SpecialCharModifier.h"

using namespace std;

string DICT_FOLDER = "../dicts/";

vector<string> DICTIONARIES = {"english_unix", "10k_most_common.txt", "elitehacker.txt", "german.txt"};

int main(int argc, char* argv[]){
    /*string s = "string to hash1";
    hashwrapper *wrap = new md5wrapper();
    string m5Hash = wrap->getHashFromString(s);
    */

    if(argc < 2){
        cout << "Error: No file given!" << endl;
        exit(-1);
    }

    string inputFile = argv[1];

    FileHandler fHandler;

    //Read hashes
    set<string>* hashList = new set<string>();
    int fileReading = fHandler.readList(inputFile, hashList);

    if(fileReading == -1){
        cout << "Error: failed reading file " << inputFile << endl;
        exit(-1);
    }

    // ---- Attacks ----
    DictAttack dAtt;

    NumModifer numMod;
    numMod.setLimit(10);
    dAtt.addModifier(&numMod);

    SpecialCharModifier charMod;
    dAtt.addModifier(&charMod);

    //Add dicts
    for(string dict : DICTIONARIES){
        dAtt.addDict(DICT_FOLDER + dict);
    }

    dAtt.findHashes(*hashList, cout);
}
