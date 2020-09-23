// Aaron Bager
// CIS 351-02
// Project 1

#include <unistd.h> // used for the access() function to check if file exists
#include <stdio.h> // for reading the characters in the file 
#include "read.h"

int getAverageWordSize(char *fileName) {
	int wordSize = 0; 
	int average = 0;
	int numberOfWords = 0; 
	FILE *fp;
       	char tempChar; 	
	
	fp = fopen(fileName, "r"); // open file for reading 
	
	while( ( tempChar = fgetc(fp) ) != EOF ) { // TODO fix this part of the function so that it actually works correctly 
		if(tempChar == ' ' || tempChar == '.' || tempChar == '?' || tempChar == '!' || tempChar == ':' || tempChar == ';' || tempChar == ',') {
			average += wordSize;
		       	wordSize = 0;	
			numberOfWords++; 
		}
		else {
			wordSize++; 
		}
	}
	
	average = average / numberOfWords;
	return average; 
}
