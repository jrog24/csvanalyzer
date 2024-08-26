#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <time.h>

#define MAX_LINE_LENGTH 10000
#define MAX_ROWS 1000000
#define MAX_FILE_SIZE 1073741824 // 1 GB

void analyze_csv(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char *buffer = NULL;
    size_t buffer_size = 0;
    size_t num_rows = 0;
    size_t num_columns = 0;
    long file_size = 0;

    // Get file size
    if (fseek(file, 0, SEEK_END) != 0) {
        perror("Error seeking to end of file");
        fclose(file);
        return;
    }
    file_size = ftell(file);
    if (file_size == -1 || file_size > MAX_FILE_SIZE) {
        perror("Error getting file size or file too large");
        fclose(file);
        return;
    }
    if (fseek(file, 0, SEEK_SET) != 0) {
        perror("Error seeking to start of file");
        fclose(file);
        return;
    }

    // Read headers
    ssize_t read = getline(&buffer, &buffer_size, file);
    if (read == -1) {
        free(buffer);
        fclose(file);
        printf("Empty file or error reading file.\n");
        return;
    }

    printf("Columns: ");
    char *token = strtok(buffer, ",\n");
    while (token != NULL) {
        num_columns++;
        printf("%s", token);
        token = strtok(NULL, ",\n");
        if (token != NULL) {
            printf(", ");
        }
    }
    printf("\n");

    // Count rows
    while ((read = getline(&buffer, &buffer_size, file)) != -1) {
        if (++num_rows > MAX_ROWS) {
            printf("Maximum number of rows exceeded.\n");
            break;
        }
    }

    free(buffer);
    fclose(file);

    printf("\e[1mNumber of rows\e[m: %zu\n", num_rows);
    printf("\e[1mNumber of columns\e[m: %zu\n", num_columns);
    if (file_size >= 1048576) {
        printf("\e[1mFile size\e[m: %.2f MB\n", (float)file_size / 1048576);
    } else {
        printf("\e[1mFile size\e[m: %.2f KB\n", (float)file_size / 1024);
    }
}

double processing_time(clock_t start, clock_t end)
{
    return((double) (end - start)) / CLOCKS_PER_SEC;
}
int main(int argc, char *argv[]) {

    clock_t start, end;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Basic input validation
    if (strlen(argv[1]) > PATH_MAX) {
        fprintf(stderr, "File path is too long!\n");
        return EXIT_FAILURE;
    }

    printf("*********\n");
    printf("Analyzing file: %s\n", argv[1]);
    start=clock();
    analyze_csv(argv[1]);
    end=clock();
    printf("Analysis complete.\n");
    printf("Processing time: %f seconds\n", processing_time(start, end));
    printf("*********\n");
    return EXIT_SUCCESS;
}
