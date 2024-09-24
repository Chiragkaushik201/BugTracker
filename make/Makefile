# ********************** Compiler *************************** # 
CC       = g++
CFLAGS   = -c -g -Wall -Werror -Wno-unused-variable

# ************************ Paths *************************** # 
OBJ	     = ../obj
SRC	     = ../src
INC	     = ../inc
BIN	     = ../bin
MAKE	 = ../make
REP      = ../report

# ******************* Additional flags ************************ # 
# path
INCDIR   = -I $(INC)

# valgrind
VALFLAG  = --tool=memcheck --show-reachable=yes --leak-check=full \
	--verbose --log-file=valgrind_report.txt

# *********************** File names *************************** # 
UTIL     = utility
MAIN     = main
PROJ     = projects
REPT     = reports
TICK     = tickets
EMP		 = Employee
TRA      = trails

# ********************** Compile & Link ************************* #

# link all
all: $(OBJ)/$(MAIN).o \
	$(OBJ)/$(UTIL).o \
	$(OBJ)/$(PROJ).o \
	$(OBJ)/$(REPT).o \
	$(OBJ)/$(TICK).o \
	$(OBJ)/$(TRA).o 

	$(CC) $(OBJ)/$(MAIN).o \
	$(OBJ)/$(UTIL).o \
	$(OBJ)/$(PROJ).o \
	$(OBJ)/$(REPT).o \
	$(OBJ)/$(TICK).o \
	$(OBJ)/$(TRA).o \
	-o $(BIN)/$(MAIN)

# create main.o
$(OBJ)/$(MAIN).o: $(SRC)/$(MAIN).cpp \
	$(INC)/$(UTIL).h
	
	$(CC) $(CFLAGS) \
	$(SRC)/$(MAIN).cpp \
	$(INCDIR) -o $(OBJ)/$(MAIN).o

# create utility.o
$(OBJ)/$(UTIL).o: $(SRC)/$(UTIL).cpp \
	$(INC)/$(UTIL).h \
	$(INC)/$(EMP).h

	$(CC) $(CFLAGS) \
	$(SRC)/$(UTIL).cpp \
	$(INCDIR) -o $(OBJ)/$(UTIL).o

# create projects.o
$(OBJ)/$(PROJ).o: $(SRC)/$(PROJ).cpp \
	$(INC)/$(UTIL).h
	
	$(CC) $(CFLAGS) \
	$(SRC)/$(PROJ).cpp \
	$(INCDIR) -o $(OBJ)/$(PROJ).o

# create tickets.o
$(OBJ)/$(TICK).o: $(SRC)/$(TICK).cpp \
	$(INC)/$(UTIL).h

	$(CC) $(CFLAGS) \
	$(SRC)/$(TICK).cpp \
	$(INCDIR) -o $(OBJ)/$(TICK).o

# create reports.o
$(OBJ)/$(REPT).o: $(SRC)/$(REPT).cpp \
	$(INC)/$(UTIL).h

	$(CC) $(CFLAGS) \
	$(SRC)/$(REPT).cpp \
	$(INCDIR) -o $(OBJ)/$(REPT).o

# create trails.o
$(OBJ)/$(TRA).o: $(SRC)/$(TRA).cpp \
	$(INC)/$(UTIL).h

	$(CC) $(CFLAGS) \
	$(SRC)/$(TRA).cpp \
	$(INCDIR) -o $(OBJ)/$(TRA).o

# ********************** Run program *************************** # 
run: $(BIN)/$(MAIN)
	$(BIN)/$(MAIN)

# ********************** Delete files *************************** # 
clean:
	rm -f $(OBJ)/*
	rm -f $(BIN)/*
	rm -f $(REP)/*

# ********************** Reports *************************** # 
valgrind: $(BIN)/$(MAIN)
	valgrind $(VALFLAG) $(BIN)/$(MAIN)
	mv valgrind_report.txt $(REP)/