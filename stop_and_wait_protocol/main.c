#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
  int frames, i, ack;
  printf("Enter number of frames to send: ");
  scanf("%d", &frames);
  srand(time(0)); // seed for random number generator
  for (i = 1; i <= frames; i++) {
    printf("\nSending frame %d...", i);
    // simulate random loss (0 = lost, 1 = received)
    int received = rand() % 2;
    if (received) {
      printf(" Frame %d received successfully.\n", i);
      printf("Acknowledgment for frame %d received.\n", i);
    } else {
      printf(" Frame %d lost!\n", i);
      printf("Resending frame %d...", i);
      // assume retransmission is always successful
      printf(" Frame %d received successfully on retransmission.\n", i);
      printf("Acknowledgment for frame %d received.\n", i);
    }
  }
  printf("\nAll frames sent successfully using Stop-and-Wait ARQ.\n");
  return 0;
}
