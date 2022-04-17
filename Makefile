CC = gcc -std=c99
FLAGS = -Wall -g
TEST_FLAG = $(FLAGS) -Wextra -g3 -D TEST
DEBUG_FLAG = $(FLAGS) -D DEBUG
LIBS = -lcunit

#-----------------------Alias Section-----------------------
#															
# This section list all the file paths in the repository, it 
# puropose is to facilitate and simplify the readability of 
# the targets.

#------------------------TARGETS----------------------------
RUN_TARGETS = linkedlist.o file_manager.o extractor.o stats.o
TEST_TARGETS = test_file_manager test_linkedlist 
DEBUG_TARGETS = debug_linkedlist debug_file_manager debug_extractor debug_stats

#---------------------TEST_TARGETS--------------------------
TESTS_LINKEDLIST = linkedlist_init.o test_linkedlist.o test_push.o test_pop.o test_get_contains.o
TESTS_FILE_MANAGER = file_manager_tests.o test_stats_file.o
TESTS_extractor = 
TESTS_STATS =

main.c = main.c
test_manager.c = ./test/test_manager.c
object_folder = ./objects

#------------------------LinkedList-------------------------

linkedlist.c  = ./src/linkedlist/linkedlist.c 
linkedlist.h  = ./src/linkedlist/linkedlist.h
linkedlist.o  = ./objects/linkedlist.o
#Test files 
linkedlist_init.c = ./test/linkedlist/linkedlist_init.c
linkedlist_init.h = ./test/linkedlist/linkedlist_init.h
linkedlist_init.o = ./objects/linkedlist_init.o
test_linkedlist.c = ./test/linkedlist/test_linkedlist.c
test_linkedlist.o = ./objects/test_linkedlist.o
test_push.c = ./test/linkedlist/test_push.c
test_push.o = ./objects/test_push.o
test_pop.c = ./test/linkedlist/test_pop.c
test_pop.o = ./objects/test_pop.o
test_get_contains.c = ./test/linkedlist/test_get_contains.c
test_get_contains.o = ./objects/test_get_contains.o

#-----------------------File-manager------------------------

file_manager.c = ./src/file_manager/file_manager.c
file_manager.h = ./src/file_manager/file_manager.h
file_manager.o = ./objects/file_manager.o
#Test files 
file_manager_tests.c = ./test/file_manager/file_manager_tests.c
file_manager_tests.o = ./objects/file_manager_tests.o
test_stats_file.c = ./test/file_manager/test_stats_file.c
test_stats_file.o = ./objects/test_stats_file.o

#--------------------------Extractor---------------------------

extractor.h = ./src/extractor/extractor.h
extractor.c = ./src/extractor/extractor.c
extractor.o = ./objects/extractor.o
#Test files

#---------------------------Stats---------------------------
stats.c = ./src/stats/stats.c
stats.h = ./src/stats/stats.h
stats.o = ./objects/stats.o
#Test files

#----------------------END OF ALIAS-------------------------

all : run

object_folder:
	mkdir -p objects

compile: object_folder $(RUN_TARGETS)

compile_test: object_folder $(TEST_TARGETS)

compile_debug: object_folder $(DEBUG_TARGETS)

run : clean compile
	$(CC) ${FLAGS} $(main.c) $(object_folder)/* -o tri

debug : clean compile_debug
	$(CC) ${DEBUG_FLAG} $(main.c) $(object_folder)/* -o tri

test: clean compile_test
	$(CC) ${TEST_FLAG} $(test_manager.c) $(object_folder)/* -o test_exec $(LIBS)

clean: 
	rm -rf ./objects/*
	rm -rf 
	rm -rf tri
	rm -rf test_exec
	rm -rf test_list

#-------------------------LinkedList-------------------------

linkedlist.o: $(linkedlist.c) $(linkedlist.h)
	$(CC) ${FLAGS} -c -o $(linkedlist.o) $< 

debug_linkedlist: $(linkedlist.c) $(linkedlist.h)
	$(CC) ${DEBUG_FLAG} -c -o $(linkedlist.o) $< 

test_linkedlist: $(linkedlist.c) $(linkedlist.h) $(TESTS_LINKEDLIST)
	$(CC) ${TEST_FLAG} -c -o $(linkedlist.o) $< 

linkedlist_init.o: $(linkedlist_init.c) 
	$(CC) ${TEST_FLAG} -c -o $(linkedlist_init.o) $< $(LIBS)

test_get_contains.o: $(test_get_contains.c) 
	$(CC) ${TEST_FLAG} -c -o $(test_get_contains.o) $< $(LIBS)

test_get_contains.o: $(test_get_contains.c) 
	$(CC) ${TEST_FLAG} -c -o $(test_get_contains.o) $< $(LIBS)

test_linkedlist.o: $(test_linkedlist.c) 
	$(CC) ${TEST_FLAG} -c -o $(test_linkedlist.o) $< $(LIBS)

test_pop.o: $(test_pop.c) 
	$(CC) ${TEST_FLAG} -c -o $(test_pop.o) $< $(LIBS)

test_push.o: $(test_push.c) 
	$(CC) ${TEST_FLAG} -c -o $(test_push.o) $< $(LIBS)

#----------------------File-manager------------------------

file_manager.o: $(file_manager.c) $(file_manager.h)
	$(CC) ${FLAGS} -c -o $(file_manager.o) $<

debug_file_manager: $(file_manager.c) $(file_manager.h)
	$(CC) ${DEBUG_FLAG} -c -o $(file_manager.o) $<

test_file_manager: $(file_manager.c) $(file_manager.h) $(TESTS_FILE_MANAGER)
	$(CC) ${TEST_FLAG} -c -o $(file_manager.o) $< $(LIBS)

file_manager_tests.o: $(file_manager_tests.c) 
	$(CC) ${TEST_FLAG} -c -o $(file_manager_tests.o) $< $(LIBS)

test_stats_file.o: $(test_stats_file.c) 
	$(CC) ${TEST_FLAG} -c -o $(test_stats_file.o) $< $(LIBS)

#--------------------------extractor---------------------------

extractor.o: $(extractor.c) $(extractor.h) $(linkedlist.o)
	$(CC) ${FLAGS} -c -o $(extractor.o) $<

debug_extractor: $(extractor.c) $(extractor.h)
	$(CC) ${DEBUG_FLAG} -c -o $(extractor.o) $<

test_extractor: $(extractor.c) $(extractor.h) $(TESTS_extractor)
	$(CC) ${TEST_FLAG} -c -o $(extractor.o) $< $(LIBS)

#---------------------------Stats---------------------------

stats.o: $(stats.c) $(stats.h)
	$(CC) ${FLAGS} -c -o $(stats.o) $<

debug_stats: $(stats.c) $(stats.h)
	$(CC) ${DEBUG_FLAG} -c -o $(stats.o) $<

test_stats: $(stats.c) $(stats.h)
	$(CC) ${TEST_FLAG} -c -o $(stats.o) $< $(LIBS)

#-----------------------------------------------------------