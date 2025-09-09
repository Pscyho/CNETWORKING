#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
  int i, n, windowSize, sent = 0, ack;
  printf("Enter the total number of frames: ");
  scanf("%d", &n);
  printf("Enter the window size: ");
  scanf("%d", &windowSize);
  srand(time(0)); // seed random number generator
  while (sent < n) {
    // send window of frames
    printf("\nSending frames: ");
    for (i = sent + 1; i <= sent + windowSize && i <= n; i++) {
      printf("%d ", i);
    }
    printf("\n");
    // simulate random ack loss
    int success = rand() % 2; // 0 = ACK lost, 1 = ACK received
    if (success) {
      // all frames acknowledged
      printf("Acknowledgment received for frames %d to %d\n", sent + 1,
             (sent + windowSize <= n) ? sent + windowSize : n);
      sent += windowSize;
    } else {
      // simulate ACK lost → retransmit window
      printf("Acknowledgment lost! Resending window starting from frame %d\n",
             sent + 1);
    }
  }
  printf("\nAll frames sent successfully using Sliding Window Protocol.\n");
  return 0;
}
