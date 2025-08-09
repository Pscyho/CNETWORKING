#include <stdio.h>
#include <string.h>

void bitStuffing(char input[], char output[]) {
  int i, j = 0;
  int count = 0;

  for (i = 0; i < strlen(input); i++) {
    output[j++] = input[i];

    if (input[i] == '1') {
      count++;
      if (count == 3) {
        output[j++] = '0';
        count = 0;
      }
    } else {
      count = 0;
    }
  }
  output[j] = '\0';
}

int main() {
  char data[100], stuffed[200];

  printf("Enter binary data (only 0s and 1s): ");
  scanf("%s", data);

  bitStuffing(data, stuffed);

  printf("\nOriginal Data: %s\n", data);
  printf("Bit Stuffed Data: %s\n", stuffed);

  return 0;
}
