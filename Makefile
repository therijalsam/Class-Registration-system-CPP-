program3.out: program3_driver.o student.o course.o utils.o
	g++ -g -std=c++17 program3_driver.o student.o course.o utils.o -o program3.out

utils.o: utils.cpp program3.h
	g++ -g -std=c++17 -c utils.cpp

course.o: course.cpp program3.h
	g++ -g -std=c++17 -c course.cpp

student.o: student.cpp program3.h
	g++ -g -std=c++17 -c student.cpp

program2.o: program3_driver.cpp program3.h
	g++ -g -std=c++17 -c program3_driver.cpp

run:
	./program3.out ./course_and_student_data.txt

test_run:
	./program3.out ./test_data.txt

valrun:
	valgrind --leak-check=full ./program3.out ./test_data.txt

clean:
	rm *.o *.out