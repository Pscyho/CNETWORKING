#include <stdio.h>
#include <string.h>

int main(void) {
    int counter = 0, i = 8, j;
    char ch, array[100] = "01111110"; // Make array larger for stuffing
    char data[50];

    printf("Enter data: ");
    fgets(data, sizeof(data), stdin);

    // Remove newline from input, if present
    data[strcspn(data, "\n")] = 0;

    for (j = 0; data[j] != '\0'; ++j) {
        ch = data[j];
        if (ch == '1')
            counter++;
        else
            counter = 0;

        array[i++] = ch;

        if (counter == 5) {
            array[i++] = '0'; // Stuff a '0' after five consecutive '1's
            counter = 0;
        }
    }
    array[i] = '\0'; // Null terminate string

    strcat(array, "01111110"); // Attach ending flag
    printf("The stuffed data is:\n");
    printf("%s\n", array);

    return 0;
}
