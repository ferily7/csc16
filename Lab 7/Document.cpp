//
//  Document.cpp
//  analyzer
//

#include "Document.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void Document::readFile(string filename){
    ifstream read_line(filename.c_str());
    string line;

    while(getline(read_line, line)){
        all_lines.push_back(line);
    }
    read_line.close();
}

int Document::numLines(){
    return all_lines.size(); 
}

string Document::get(int index){
    return all_lines[index];
}

vector<string> Document::getWords(int index){  //DON'T TOUCH THIS FUNCTION!!
    vector<string> line_words;
    string line = all_lines[index];
    istringstream linestream(line);
    string word;
    while(linestream >> word)
        line_words.push_back(word);
    return line_words;
}
