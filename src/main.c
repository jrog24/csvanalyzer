#include "../include/csvanalyzer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

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
    start = clock();
    analyze_csv(argv[1]);
    end = clock();
    printf("Analysis complete.\n");
    printf("Processing time: %f seconds\n", processing_time(start, end));
    printf("*********\n");
    return EXIT_SUCCESS;
}
