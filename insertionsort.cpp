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

  void insertHead(long value);
  void printList(std::ofstream& os);
  void insertionSort();
};

using namespace std;

/*TODO:
*Specify path for data to be sorted, located in /sortingalgorithms/data/
*/
int main(){
  linkedList list;
  string inFile, outFile;
  ifstream in_s;
  ofstream out_s;
  long a;

  cout << "Enter the name of the file to be sorted." << endl;
  cout << "Please note that any d1000+ files are located in the data folder : " << endl;
  cin >> inFile;

  cout << "Enter the name of the desired sorted output file:" << endl;
  cin >> outFile;

  in_s.open(inFile.c_str());
  //If input file name is invalid, re-prompt the user to enter a correct one
  while(in_s.fail()){

    in_s.clear();
    cout << "Input file opening failed, please try again." << endl;
    cin >> inFile;
    in_s.open(inFile.c_str());
  }

  out_s.open(outFile.c_str());
  //If output file name is invalid, re-prompt the user to enter a correct one
  while(out_s.fail()){

    out_s.clear();
    cout << "Output file opening failed, please try again." << endl;
    cin >> outFile;
    out_s.open(outFile.c_str());
  }

  while(in_s >> a){

    list.insertHead(a);
  }

  list.printList(out_s); //Feed the linked list into the output file

  in_s.close();
  out_s.close();

  return 0;
}


void linkedList::insertHead(long value){

  Node *temp = new Node;
  temp -> data = value;
  temp -> link = head;
  head = temp;
}

void linkedList::printList(std::ofstream& os){

  Node *temp = new Node;
  temp = head;
  while (temp != NULL){

    os << temp -> data << "\n";
    temp = temp -> link;
  }
}
