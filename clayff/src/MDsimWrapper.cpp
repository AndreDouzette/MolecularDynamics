#include "MDcalculation.h"
using namespace std;

//Python wrapper for the c++ simulation program
int main(int argc, char** argv){
	//Test wether there are enough command line arguments
	if(argc < 5){
		//Insert not enough arguments exception?
		cout << argc << "\n";
		return 1;
	}
		
	//////////////////////
	// Input parameters //
	//////////////////////
	//get path
	string path = argv[1];
	//get simulation length
	int length = atoi(argv[2]);
	//get save step
	int step = atoi(argv[3]);
	//get dt
	double dt = atof(argv[4]);
	
	length = length*step;
	
	/////////////////
	// Calculation //
	/////////////////
	MDcalculation* calculator = new MDcalculation(path, 0);
	calculator->run(length, dt, path, step);
	calculator->finalize();
	return 0;
	
}