#ifndef CSVANALYZER_H
#define CSVANALYZER_H

#include <time.h>

// Maksymalne wartości
#define MAX_LINE_LENGTH 10000
#define MAX_ROWS 1000000
#define MAX_FILE_SIZE 1073741824 // 1 GB

// Funkcja do analizy pliku CSV
void analyze_csv(const char *file_path);

// Funkcja do obliczania czasu przetwarzania
double processing_time(clock_t start, clock_t end);

#endif // CSVANALYZER_H
