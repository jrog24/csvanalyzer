#ifndef CSVANALYZER_H
#define CSVANALYZER_H

#include <time.h>

#define MAX_LINE_LENGTH 10000
#define MAX_ROWS 1000000
#define MAX_FILE_SIZE 1073741824 // 1 GB

void analyze_csv(const char *file_path);

double processing_time(clock_t start, clock_t end);

#endif
