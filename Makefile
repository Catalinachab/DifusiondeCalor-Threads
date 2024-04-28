CC=c99
CFLAGS=-Wall -Wextra -pedantic -O0 -ggdb -Wno-unused-parameter
LIBS=-lm -lpthread
all: diffusionSerial.out diffusionParallel_2V.out diffusionParallel_2H.out diffusionParallel_4V.out diffusionParallel_4H.out diffusionParallel_4Box.out

diffusionParallel_4Box.out: diffusionParallel_4Box.c common.c common.h
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

diffusionParallel_4H.out: diffusionParallel_4H.c common.c common.h
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

diffusionParallel_4V.out: diffusionParallel_4V.c common.c common.h
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

diffusionParallel_2H.out: diffusionParallel_2H.c common.c common.h
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

diffusionParallel_2V.out: diffusionParallel_2V.c common.c common.h
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

diffusionSerial.out: diffusionSerial.c common.c common.h
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

.PHONY: clean
clean:
	rm -f *.o *.out
