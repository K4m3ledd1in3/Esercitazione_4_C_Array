#include <iostream>
#include <fstream>
#include <sstream>
#include <numbers>
#include <limits>
#include <cmath>
#include <iomanip> 
#include "src/Utils.hpp"

using namespace std;
const string filename = "data.txt";
const string filename_out = "result.txt";
using uint = unsigned int;
int main(void)
{	 	
	  cout << fixed << setprecision(2) << endl;
	  double rate = 0.0;
      char separator = ';';
	  double budget = 0.0;
	  ifstream ifs(filename);
	  ofstream ofs(filename_out);
	  ofs << fixed << setprecision(2);
	  cout << ReadFile_Process(ofs,ifs,separator, budget, rate);
    return 0;
}

