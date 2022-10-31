all: person mutex raii_mutex

person:
	g++ person.cpp -o person

mutex:
	g++ mutex.cpp -o mutex -std=c++11 -pthread

raii_mutex:
	g++ raii_mutex.cpp -o raii_mutex -std=c++11 -pthread

clean:
	rm person mutex raii_mutex
