SUBDIRS=bayes common genome intruder kmeans labyrinthlib ssca2 vacation yada

all:
	make -C lib
	for i in $(SUBDIRS); do make -C $$i -f Makefile.stm; done

clean:
	make -C lib clean
	for i in $(SUBDIRS); do make -C $$i -f Makefile.stm clean; done

