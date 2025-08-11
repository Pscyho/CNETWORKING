#include <stdio.h>
#include <string.h>
#define FLAG 'F'
#define ESC 'E'

int main() {
  char data[100], stuffed[200];
  int i, j = 0;
  printf("enter the data string(without spaces):\n");
  scanf("%s", data);
  stuffed[j++] = FLAG;
  for (i = 0; i < strlen(data); i++) {
    if (data[i] == FLAG) {
      stuffed[j++] = ESC;
    }
    stuffed[j++] = data[i];
  }
  stuffed[j++] = FLAG;
  stuffed[j] = '\0';
  printf("the origial data is: %s", data);
  printf("\nthe stuffed data is: %s\n", stuffed);
  return 0;
}
