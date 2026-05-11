#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define FILENAME "user_input.txt"
#define SIZE 1024

int main() {
    int fd;
    char buffer[SIZE];
    int bytes_read, bytes_written;

    
    // Step 1: Get input from user via stdin (fd 0)
    printf("Enter text (max %d characters):\n", SIZE - 1);
    bytes_read = read(0, buffer, SIZE - 1);
    if (bytes_read <= 0) {
        perror("Error reading input");
        return 1;
    }
    buffer[bytes_read] = '\0';  // Null-terminate if needed

    
    int fd = creat("user_input.txt", 0743);





    // Step 2: Get input from user via stdin (fd 0)
    printf("Enter text (max %d characters):\n", SIZE - 1);
    bytes_read = read(0, buffer, SIZE - 1);
    if (bytes_read <= 0) {
        perror("Error reading input");
        return 1;
    }
    buffer[bytes_read] = '\0';  // Null-terminate if needed

    // Step 2: Open file for writing using file descriptor
    fd = open(FILENAME, O_WRONLY | O_CREAT | O_TRUNC, 0644); //owner: write and read, group and everyone: write only
    if (fd == -1) {
        perror("Error opening file for writing");
        return 1;
    }

    // Step 3: Write user input to file
    bytes_written = write(fd, buffer, bytes_read);
    if (bytes_written != bytes_read) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }
    close(fd);

    // Step 4: Open file for reading
    fd = open(FILENAME, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file for reading");
        return 1;
    }

    // Step 5: Read from file
    bytes_read = read(fd, buffer, SIZE - 1);
    if (bytes_read == -1) {
        perror("Error reading from file");
        close(fd);
        return 1;
    }
    close(fd);

    // Step 6: Print to screen using stdout (fd 1)
    printf("\n--- Content read from file ---\n");
    write(1, buffer, bytes_read);

    // Optional: Remove file after use
    // unlink(FILENAME);

    return 0;
}