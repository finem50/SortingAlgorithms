/** Requirements:
-
**/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

static void shellSort(vector<long> &data);

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



  return 0;
}
