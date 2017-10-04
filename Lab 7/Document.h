//
//  Document.hpp
//  analyzer
//
#include <vector>
#include <string>
using namespace std;

class Document{
	private:
		vector<string> all_lines;
	public:
		void readFile(string textfile);
		int numLines();
		string get(int index);
		vector<string> getWords(int index);
};