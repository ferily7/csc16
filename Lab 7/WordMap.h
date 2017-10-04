//
//  WordMap.h
//  analyzer
//
//
#include <vector>
#include <string>
#include "WordInfo.h"

class WordMap{
	private:
		vector<WordInfo> all_words;
	public:
		WordInfo get(string word);
		void put(WordInfo w);
};