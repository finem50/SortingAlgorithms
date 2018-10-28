/** Requirements:
-Use bottom up merge sort algorithm
-Use vectors or arrays to hold data
-NOT required to use objects
-Need to accept command line arguments
**/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

static void mergeSort(vector<long> &data, vector<long> temp);
static void merge(vector<long> &data, vector<long> temp, int size, int left, int mid);

int main(int argc, char** argv){

  string inFile = "", outFile = "";
  ifstream in_s;
  ofstream out_s;
  long a;
  std::vector<long> inVec;
  std::vector<long> temp;

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

  mergeSort(inVec, temp);

  //Output all elements from vector, from index 0 -> n, to output file
  for(int i = 0; i < inVec.size(); i++){

    out_s << inVec.at(i) << endl;
  }

  return 0;
}

static void mergeSort(vector<long> &data, vector<long> temp){

  int width;
  int n = data.size();

  if(n == 0 || n == 1){

    return;
  }

  for(width = 1; width < n; width = 2 * width){

    int i;

    for(i = 0; i < n; i = i + 2 * width){

      int left, mid;

      left = i;
      mid = i + width;

      merge(data, temp, n, left, mid);
    }
  }

}

static void merge(vector<long> &data, vector<long> temp, int size, int left, int mid){

  int i, j, k;
  int right = mid + mid - left;

  //Setting the size of vector 'temp' to the size of vector 'data'
  temp.resize(data.size());
  if(right > size){

    right = size;
  }

  i = left;
  j = mid;
  k = left;

  while(i < mid && j < right){

      if(data[i] < data[j]){

        temp[k++] = data[i++];
      }else{

        temp[k++] = data[j++];
      }

  }

  while(i < mid){

    temp[k++] = data[i++];
  }

  while(j < right){

    temp[k++] = data[j++];
  }

  for(i = left; i < right; ++i){

    data[i] = temp[i];
  }

}
