#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void analyze_csv(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[2048];  // Zwiększony rozmiar bufora
    int num_rows = 0;
    int num_columns = 0;
    size_t file_size = 0;

    // Get file size
    if (fseek(file, 0, SEEK_END) != 0) {
        perror("Error seeking to end of file");
        fclose(file);
        return;
    }
    file_size = ftell(file);
    if (file_size == -1) {
        perror("Error getting file size");
        fclose(file);
        return;
    }
    if (fseek(file, 0, SEEK_SET) != 0) {
        perror("Error seeking to start of file");
        fclose(file);
        return;
    }

    // Read headers
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        char *token = strtok(buffer, ",\n");
        printf("Headers: ");
        while (token != NULL) {
            num_columns++;
            printf("%s", token);
            token = strtok(NULL, ",\n");
            if (token!= NULL){
                    printf(", ");
        }

    } printf("\n");}
        else {
        fclose(file);
        printf("Empty file or error reading file.\n");
        return;
    }

    // Count rows
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        num_rows++;
    }

    fclose(file);

    printf("File: %s\n", file_path);
    printf("Number of rows (excluding header): %d\n", num_rows);
    printf("Number of columns: %d\n", num_columns);
    printf("File size: %zu bytes\n", file_size);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Analyzing file: %s\n", argv[1]);
    analyze_csv(argv[1]);
    printf("Analysis complete.\n");

    return EXIT_SUCCESS;
}