# makefile for the project 1 assignment

C++ = g++ --std=c++11	

SOURCES =  Courses.cpp Student.cpp StudentCourses.cpp \
 Menu.cpp GroupOfStudents.cpp pa1main.cpp

OBJFILES = $(SOURCES:.cpp=.o)

TARGET = proj1


$(TARGET): $(OBJFILES)
	@echo "... linking $(TARGET)"
	$(C++) -Wall -o $(TARGET) $(OBJFILES)

compile_only: $(OBJFILES)

.cpp.o: 
	@echo "... compiling $<"
	$(C++) -Wall -g -c $<

clean:
	@echo "... clean up"
	/bin/rm -f $(OBJFILES) $(TARGET)
