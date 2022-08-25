#include<stdio.h>

int keyInput(){
	char input = getch();
	if (input == -32) {
		input = getch();
		if (input == 72) return input; // Up
		if (input == 80) return input; // Down
		if (input == 75) return input; // Left
		if (input == 77) return input; // Right
	}
	return input;
}

int main(){
  char temp;
  while(1){
    temp = keyInput();
	 if (temp == 'x'){
		 break;
	 }
    printf("Your input: %c => Ascii code = %d\n", temp, (int) temp);
  }
  return 0;
}
