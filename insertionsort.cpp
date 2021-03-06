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

using namespace std;

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


typedef Node* ptr;

int main(int argc, char** argv){
  linkedList list;
  string inFile = "", outFile = "";
  ifstream in_s;
  ofstream out_s;
  long a;

  //Take in command line arguments for input file and output file
  //Argument structure should be: ./cppfile inputFile outputFile
  if(argc == 3){

    inFile = argv[1];
    outFile = argv[2];
  }else{

    cout << "Usage: ./cppfile InputFile OutputFile\n";
    return 1;
  }

  cout << "File to be sorted is:\t" << inFile << endl;
  cout << "Output file name is:\t " << outFile << endl;

  in_s.open(inFile.c_str());
  //If input file name is invalid, re-prompt the user to enter a correct one
  while(in_s.fail()){

    in_s.clear();
    cout << "Input file opening failed, please retry input file name." << endl;
    cin >> inFile;
    in_s.open(inFile.c_str());
  }

  out_s.open(outFile.c_str());
  //If output file name is invalid, re-prompt the user to enter a correct one
  while(out_s.fail()){

    out_s.clear();
    cout << "Output file opening failed, please retry output file name." << endl;
    cin >> outFile;
    out_s.open(outFile.c_str());
  }

  while(in_s >> a){
    //Insert input file date into linked list
    list.insertHead(a);
  }

  list.insertionSort();
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

void linkedList::insertionSort(){

  Node *temp1 = new Node;
  Node *temp2 = new Node;

  if((head == NULL || head -> link == NULL)){

    return;
  }
  temp1 = head -> link;
  while(temp1 != NULL){

    float data2 = temp1 -> data;
    float found = 0;
    temp2 = head;

    while(temp2 != temp1){

      if(temp2 -> data > temp1 -> data && found == 0){

        data2 = temp2 -> data;
        temp2 -> data = temp1 -> data;
        found = 1;
        temp2 = temp2 -> link;
      }else{

        if(found == 1){
          float temp = data2;
          data2 = temp2 -> data;
          temp2 -> data = temp;
        }

        temp2 = temp2 -> link;
      }
    }

    temp2 -> data = data2;
    temp1 = temp1 -> link;
  }
}
