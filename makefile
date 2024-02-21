CC = g++
exe_file = run 

$(exe_file): catalog.o run_catalog.o 
	$(CC) catalog.o run_catalog.o -o $(exe_file) 

catalog.o: catalog.cpp 
	$(CC) -c catalog.cpp 

run_catalog.o: run_catalog.cpp
	$(CC) -c run_catalog.cpp 

clean:
	rm -f .out.o $(exe_file)

leak check: catalog.o run_catalog.o
	$(CC) catalog.o run_catalog.o -o $(exe_file)
	valgrind --leak-check-full ./$(exe_file)

 