#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip" 
using namespace std;

using uint = unsigned int;

int ReadFile_Process(ofstream& file_o, ifstream& file, 
			  char separator, 
			  double& budget, 
			  double& rate){
			  	
	    uint n = 0;
	    char s1,s2;
	    if (file.is_open() && file_o.is_open()){
	    	
	    file >> s1 >> separator >> budget;
		file >> s1 >> separator >> n;
		file >> s1 >> separator >> s2;
		
		double * ptr = new double[2*n]; 
        for (uint i = 0; i < n; i++)
            file >> ptr[2*i] >> separator >>  ptr[2*i+1];
            
		cout << "S = " << budget << ", " << "n = " << n << endl;
		file_o << "S = " << budget << ", " << "n = " << n << endl;
		
        cout << "w = [";
        file_o << "w = [";
        cout << ptr[0];
        file_o << ptr[0];
        
        for(uint i = 1; i<n; i++)
		{
        	cout << " " << ptr[2*i];
        	file_o << " " << ptr[2*i];
    	}
    	
        cout << " ]" << endl;
        file_o << " ]" << endl;
        
        cout << "r = [ ";   
		file_o <<  "r = [ "; 
		  
        cout << ptr[1];
        file_o << ptr[1];
        
		for(uint i = 1; i<n; i++){
        	cout << " " << ptr[2*i+1];
        	file_o << " " << ptr[2*i+1];
    	}
    	//
        cout << " ]" << endl; 	
        file_o  << " ]" << endl;
		double counter = 0.0;
		//
        for(uint i = 0; i < n; i++ ){
        	counter+=(budget * ptr[2*i] * (1 + ptr[2*i+1] ));
		}
		//
		delete[] ptr;
		rate = (counter)/((double) budget) - 1;
		//
		cout << " V: " << counter << endl;
		cout << fixed << setprecision(4);
		cout << " Rate of return of portfolio: " << rate << endl;
		//
		file_o << " V: " << counter << endl;
		file_o << fixed << setprecision(4);
		file_o << " Rate of return of portfolio: " << rate << endl;
		//
		file_o.close();
		file.close();
		
        return 0;
	 }
	 else
	{
	 	cout << "Unable to read or open the file." << endl;
	 	return -1;
	}
			  	
    }