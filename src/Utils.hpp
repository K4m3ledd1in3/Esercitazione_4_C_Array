#pragma once

#include <iostream>
using namespace std;

int ReadFile_Process(ofstream& file_o,ifstream& file, 
			  char separator, 
			  double& budget, 
			  double& rate);