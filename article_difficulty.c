// Aaron Bager
// CIS 343-02
// Project 1
#include <unistd.h> // To check if file exists 
#include "read.h" //
#include <stdio.h>

int main (int argc, char *argv[]) {
	int smallestWordSize = 1; // used to keep track of smallest file thus far, intially 1 
	int largestWordSize = 0; // used to keep track of largest file size thus far, initially 0 
	int tempInt; // used for comparing file sizes
	int smallestFile; // index of smallest file in arguments given
	int largestFile; // index number of largest file in arguments given
	if ( argc == 1) {
		printf("Please provide file names"); 
	}
	else if ( argc == 2) {
			if ( access( argv[1], F_OK ) != -1 ) {
				printf("\nMost difficult document: %s\nLeast difficult document: %s", argv[1], argv[1]); 
			}
			else {
				printf("Error: %s does not exist."); 
			}
	}
	else {
		for (int i = 1; i < argc; i++) {
			tempInt = getAverageWordSize(argv[i]);
			if (tempInt > largestFileSize) {
				largestWordSize = tempInt; 
				largestFile = i;
			}	
			
			if (tempInt < smallestWordSize) {
				smallestWordSize = tempInt; 
				smallestFile = i; 
			}
		}	
		
		printf("Most difficult document: %s\nLeast difficult document: %s", argv[largestFile], argv[smallestFile]); 
	}
}
