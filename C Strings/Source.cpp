#include <stdio.h>



int main() {
	char buffer[30];
	fgets(buffer, 30, stdin);

	printf("%s\n", buffer);

	for (int i = 0; i < 30; i++) {
		printf("arr[%d] = %c (%d)\n", i, buffer[i], int(buffer[i]));
	}

	return 0;
}