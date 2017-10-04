#include <iostream>
#include <string>
using namespace std;

class Set{

private:
	struct Node{
		string data;
		Node * next;
	};

	Node * head;
	int numNodes;

public:
	Set(){ //Constructor
		head = 0;
		numNodes = 0;
	}

	bool add(string item){
		if(has(item)){
			return false;
		}
		else{
			Node * temp = new Node;
			temp->data = item;
			temp->next = head;
			head = temp;
			//delete temp;
			numNodes++;
			return true;
		}

	}

	bool remove(string item){
		Node * ptr = head;
		int index = 0;

		while(ptr != 0 && ptr->data != item){
			index++;
			ptr = ptr->next;
		}

		if(ptr == 0){
			return false;
		}
		
		else{
			Node * temp;

			if(index == 0){
				temp = head;
				head = head->next;
			}
			else{
				Node * ptr2 = head;
				index--;

				while(index != 0){
					ptr2 = ptr2->next;
					index--;
				}

				temp = ptr2->next;
				ptr2->next = ptr2->next->next;

				delete temp;
			}
			numNodes--;
			return true;
		}
		
	}

	bool has(string item){
		Node * ptr = head;
		while(ptr != 0 && ptr->data != item){
			ptr = ptr->next;
		}
		if(ptr == 0)
			return false;
		else
			return true;
	}

	int size(){
		return numNodes;
	}
};

int main(){
	Set s;
	string option, item;
	cout << "Select an option:\n"
			"a. Add to set\n"
			"r. Remove from set\n"
			"h. Check if set has item\n"
			"e. Exit program\n"
			"Option: ";
	cin >> option;

	while(option != "e"){
		if(option == "a"){
			cout << "Item: ";
			cin >> item;
			if(s.add(item))
				cout << "Item was added to set. \n";
			else
				cout << "Item is already in the set, not added. \n";
		}
		else if(option == "r"){
			cout << "Item: ";
			cin >> item;
			s.remove(item);
			cout << "Operation completed.\n";
		}
		else if(option == "h"){
			cout << "Item: ";
			cin >> item;
			if(s.has(item))
				cout << "Item is in the set.\n";
			else
				cout << "Item is not in the set.\n";
		}
		else{
			cout << "Invalid selection.\n";
		}

		cout << "Select an option:\n"
			"a. Add to set\n"
			"r. Remove from set\n"
			"h. Check if set has item\n"
			"e. Exit program\n"
			"Option: ";
		cin >> option;
	}
}
