/** Requirements:
-Linked list to be used for insertion sort
-File in/out to be used for reading integers and building a linked list
in the order that matches the file, and then sort that linked list.
-All movement to be done by pointers
-Data in nodes may not be changed after initially stored
**/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

struct Node{

  long data;
  Node *link;
};

class linkedList{

private:
  Node *head, *tail;

public:
  linkedList(){

    head = NULL;
    tail = NULL;
  }

  void insertHead(float value);

  void createNode(float value);

  void display();
};

using namespace std;

/*TODO:
*Specify path for data to be sorted, located in /sortingalgorithms/data/
*/
int main(){
  // string inFile, outFile;
  // ifstream in_s;
  // ofstream out_s;
  //
  // cout << "Enter the name of the file to be sorted:" << endl;
  // cin >> inFile;
  //
  // cout << "Enter the name of the desired sorted output file:" << endl;
  // cin >> outFile;
  //
  // in_s.open(inFile);
  // if(in_s.fail()){
  //
  //   cout << "Input file opening failed." << endl;
  //   exit(1); //If the file could not be opened and read, exit
  // }
  //
  // out_s.open(outFile);
  // if(out_s.fail()){
  //
  //   cout << "Output file opening failed." << endl;
  //   exit(1);
  // }

  linkedList list;

  for(int i = 0; i < 11; i++){

    list.insertHead(i);
  }

  list.display();

  return 0;
}


void linkedList::createNode(float value){

  Node *temp = new Node;
  temp -> data = value;
  temp -> link = NULL;

  if(head == NULL){

    head = temp;
    tail = temp;
    temp = NULL;
  }else{

    tail -> link = temp;
    tail = temp;
  }
}

void linkedList::insertHead(float value){

  Node *temp = new Node;
  temp -> data = value;
  temp -> link = head;
  head = temp;
}

void linkedList::display(){

  Node *temp = new Node;
  temp = head;
  while (temp != NULL){

    cout << temp -> data << "\n";
    temp = temp -> link;
  }
}
