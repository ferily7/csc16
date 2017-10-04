//
//  WordMap.cpp
//  analyzer

#include "WordMap.h"

WordInfo WordMap::get(string word){
	int left = 0,
		right = all_words.size() - 1;

	while(left <= right){
		int mid = (left+right) / 2;

		if(word == all_words[mid].word){
			return all_words[mid];
		}
		else if(word < all_words[mid].word){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}

	WordInfo dummy;
	dummy.word = "";
	return dummy;
}

void WordMap::put(WordInfo w){
	int left = 0,
		right = all_words.size() - 1;

	while(left <= right){
		int mid = (left+right) / 2;

		if(w.word == all_words[mid].word){
			all_words[mid] = w;
			return;
		}
		else if(w.word < all_words[mid].word){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}

	all_words.push_back(w);
	for(int prefix=2; prefix <= all_words.size(); prefix++){
		WordInfo newest = all_words[prefix-1];
		int position = prefix-2;

		while(position >= 0 && all_words[position].word > newest.word){
			all_words[position+1] = all_words[position];
			position = position - 1;
		}
		all_words[position+1] = newest;
	}
}
