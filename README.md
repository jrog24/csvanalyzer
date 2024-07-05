Small C program designed for Unix systems. At this very moment it gives you this info about CSV file that has been pointed:
- headers,
- number of rows,
- number of columns,
- file size.

Back when I was actually working on some CSV files on Linux I was operating on tail, head etc. to get some of this info. I was working as a intern in some analytics project, where the underlying OS was monitored with metrics chosen specifically for the SAP workloads. Sometimes just knowing the size of the file or headers would be useful for debugging purposes. 
This project is also a learning field for me in C/C++, as I've never did any development for Linux in those languages. Who knows, maybe someone will find it useful. 

To run just build it with gcc, maybe copy the file to /usr/bin so you can invoke it directly from the shell with csvanalyzer some-csv-file.csv. 
