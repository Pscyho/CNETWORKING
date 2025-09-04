#include <stdio.h>
int main() {
  int bucketSize, outputRate, n, i;
  int incoming, stored = 0;
  printf("Enter bucket size (in packets): ");
  scanf("%d", &bucketSize);
  printf("Enter output rate (packets per second): ");
  scanf("%d", &outputRate);
  printf("Enter number of incoming packet batches: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("\nEnter number of packets arriving at time %d: ", i + 1);
    scanf("%d", &incoming);
    // If bucket overflows
    if (stored + incoming > bucketSize) {
      printf("Bucket overflow! %d packet(s) dropped.\n",
             (stored + incoming) - bucketSize);
      stored = bucketSize; // bucket full
    } else {
      stored += incoming;
    }
    // Send packets at output rate
    printf("Packets in bucket before sending: %d\n", stored);
    if (stored <= outputRate) {
      printf("Packets sent: %d\n", stored);
      stored = 0;
    } else {
      printf("Packets sent: %d\n", outputRate);
      stored -= outputRate;
    }
    printf("Packets left in bucket: %d\n", stored);
  }
  // Empty remaining packets
  while (stored > 0) {
    printf("\nPackets in bucket before sending: %d\n", stored);
    if (stored <= outputRate) {
      printf("Packets sent: %d\n", stored);
      stored = 0;
    } else {
      printf("Packets sent: %d\n", outputRate);
      stored -= outputRate;
    }
    printf("Packets left in bucket: %d\n", stored);
  }
  return 0;
}
