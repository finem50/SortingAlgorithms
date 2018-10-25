/*Requirements:
-Use arrays or vectors
-NOT required to use classes or objects
-Accept command line parameters
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void shellSort(vector<float> data);

int main(int argc, char** argv){

  string inFile = "", outFile = "";
  ifstream in_s;
  ofstream out_s;
  long a;
  std::vector<float> inVec;

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

    inVec.push_back(a);
  }

  shellSort(inVec);

  for(int i = 0; i < inVec.size(); i++){

    out_s << inVec[i] << "\n";
  }

  in_s.close();
  out_s.close();
  return 0;
}

void shellSort(vector<float> data){

    int i, j, k, temp;
    int n = data.size();

    for(i = n/2; i > 0; i = i/2){

      for(j = i; j < n; j++){

        for(k = j - i; k >= 0; k = k - i){

          if(data[k + i] >= data[k])
          break;

          else{

            temp = data[k];
            data[k] = data[k + i];
            data[k + i] = temp;
          }
        }
      }
    }
}
