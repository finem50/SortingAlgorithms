/** Requirements:
-THIS ITERATION IS DONE RECURSIVELY
-Use vectors or arrays to hold data
-NOT required to use objects
-Need to accept command line arguments
**/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

static void mergeSort(vector <long> &data);
static void merge(vector<long> &left, vector<long> &right, vector<long> &data);

int main(int argc, char** argv){

  string inFile = "", outFile = "";
  ifstream in_s;
  ofstream out_s;
  long a;
  std::vector<long> inVec;

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

  //Insert all elements from input file into the vector
  while(in_s >> a){

    inVec.push_back(a);
  }

  mergeSort(inVec);

  //Output all elements from vector, from index 0 -> n, to output file
  for(int i = 0; i < inVec.size(); i++){

    out_s << inVec.at(i) << endl;
  }

  return 0;
}

static void mergeSort(vector <long> &data){

  int i, j, n, half;
  n = data.size();
  half = n / 2;
  vector<long> left;
  vector<long> right;


  if(n == 0 || n == 1){

    return;
  }

  for(i = 0; i < half; i++){

    left.push_back(data[i]);
  }

  for(i = 0; i < n - half; i++){

    right.push_back(data[half + i]);
  }


  mergeSort(left);
  mergeSort(right);
  merge(left, right, data);
}

static void merge(vector<long> &left, vector<long> &right, vector<long> &data){

  int left_size = left.size();
  int right_size = right.size();
  int i = 0;
  int j = 0;
  int k = 0;

  while(j < left_size && k < right_size){

    if(left[j] < right[k]){
      data[i] = left[j];
      j++;
    }else{

      data[i] = right[k];
      k++;
    }

    i++;
  }

  while(j < left_size){

    data[i] = left[j];
    i++;
    j++;
  }

  while(k < right_size){

    data[i] = right[k];
    i++;
    k++;
  }
}
