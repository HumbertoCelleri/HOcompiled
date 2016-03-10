.PHONY: default help object executable all clean

CC = gcc
FC = gfortran

LD = $(FC)

SOURCE_C = $(wildcard *.c)
OBJECTS_C = $(patsubst %.c, %_c.o, $(SOURCE_C))
SOURCE_F = $(wildcard *.f90)
OBJECTS_F = $(patsubst %.f90, %_f90.o, $(SOURCE_F))

EXECUTABLE = c-from-f-main.e

default: help

help:
	@echo "\
Options:\n\n\
  make objects:       compiler makes objects for every *.c and *.f90\n\
  make executable:    compiler makes executable\n\
  make all:           build all previous\n\
  make clean:         delete output files\n\
  make help:          display this help"

objects: $(OBJECTS_C) $(OBJECTS_F)

executable: $(EXECUTABLE)

all: objects executable

%_f90.o: %.f90
	$(FC) -c $^ -o $@

%_c.o: %.c
	$(CC) -c $^ -o $@

%.e: $(OBJECTS_C) $(OBJECTS_F)
	$(LD) $^ -o $@

clean:
	rm -rfv $(OBJECTS_C) $(OBJECTS_F) $(EXECUTABLE)
