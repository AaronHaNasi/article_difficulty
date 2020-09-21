// Aaron Bager
// CIS 343-02
// Project 1
#include <unistd.h> // To check if file exists 


int main (int argc, char *argv[]) {
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
		
	}
}
