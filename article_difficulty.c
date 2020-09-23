// Aaron Bager
// CIS 343-02
// Project 1
#include <unistd.h> // To check if file exists TODO use stdio to check instead
// #include "read.h" //
#include <stdio.h>

int getAverageWordSize(char *fileName) {
	int wordSize = 0;
	int average = 0;
	int numberOfWords = 0;
	FILE *fp;
       	char tempChar;

	fp = fopen(fileName, "r"); // open file for reading
	if (fp == NULL) {
		printf("%s does not exist. Exiting...", fileName);
		exit(0);
	}
	// while( ( tempChar = fgetc(fp) ) != EOF ) { // TODO fix this part of the function so that it actually works correctly
	while( !feof(fp) ) {
	      tempChar = fgetc(fp);
		if(tempChar == ' ' || tempChar == '.' || tempChar == '?' || tempChar == '!' || tempChar == ':' || tempChar == ';' || tempChar == ',') {
			average += wordSize;
		       	wordSize = 0;
			numberOfWords++;
		}
		else {
			wordSize++;
		}
	}
	// fseek(fp, 0, SEEK_SET);
	// rewind(fp);
	fclose(fp);
	average = average / numberOfWords;
	return average;
}


int main (int argc, char **argv) {
	int smallestWordSize = 10000; // used to keep track of smallest file thus far, intially 1
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
				printf("Error: %s does not exist.", argv[1]);
			}
	}
	else {
		for (int i = 1; i < argc; i++) {
			tempInt = getAverageWordSize(argv[i]);
			if (tempInt > largestWordSize) {
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
