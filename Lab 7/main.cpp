//
//  main.cpp
//  analyzer

#include <iostream>
#include <string>
#include "Document.h"
#include "WordMap.h"

using namespace std;

//THIS FILE IS COMPLETE; DON'T MESS WITH IT

int main()
{
    string filename;
    string command;
    string word;
    Document doc;
    WordMap map;
    
    cout << "Ready> ";
    cin >> command;
    while (command != "quit") {
        if ( command == "analyze")
        {
            cin >> filename;
            cout << "Analyzing " << filename << " ... " ;
            doc.readFile(filename);
            for(int i = 0; i < doc.numLines(); i ++)
            {
                vector<string> words = doc.getWords(i);
                for(int j = 0; j < words.size(); j ++)
                {
                    
                    WordInfo wi = map.get(words[j]);
                    wi.word = words[j];
                    wi.lines.push_back(i);
                    map.put(wi);
                }
            }
            cout << "done.\n";
        }
        else if ( command == "find")
        {
            cin >> word;
            WordInfo wi = map.get(word);
            cout << "Matching lines: ";
            if (wi.lines.size() == 0 )
                cout << "none" << endl;
            else
            {
                cout << endl;
                for(int i = 0; i < wi.lines.size(); i ++)
                {
                    cout << wi.lines[i] << " ";
                }
                cout << endl;
            }
        }
        else if ( command == "context" )
        {
            cin >> word;
            WordInfo wi = map.get(word);
            cout << "Matching lines: ";
            if (wi.lines.size() == 0 )
                cout << "none" << endl;
            else
            {
                cout << endl;
                for(int i = 0; i < wi.lines.size(); i ++)
                {
                    cout << wi.lines[i] << ": " << doc.get(wi.lines[i]) << endl;
                }
                cout << endl;
            }
        }
        else{
            cout << "Unknown command.\n";
        }
        cout << "Ready> ";
        cin >> command;
    }
    return 0;
}

