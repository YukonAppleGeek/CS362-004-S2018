CFLAGS = -Wall -fpic -coverage -lm
BIN = ./bin

$(BIN):
	mkdir $(BIN)

$(BIN)/rngs.o: $(BIN) rngs.h rngs.c
	gcc -o $(BIN)/rngs.o -c rngs.c -g $(CFLAGS)

$(BIN)/dominion.o: $(BIN) dominion.h dominion.c $(BIN)/rngs.o
	gcc -o $(BIN)/dominion.o -c dominion.c -g $(CFLAGS)

$(BIN)/playdom.o: $(BIN) $(BIN)/dominion.o playdom.c
	gcc -o $(BIN)/playdom.o -c playdom.c -g $(BIN)/dominion.o $(BIN)/rngs.o $(CFLAGS)

playdom: $(BIN) $(BIN)/playdom.o
	gcc -o $(BIN)/playdom -g $(BIN)/playdom.o $(BIN)/dominion.o $(BIN)/rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

$(BIN)/testDrawCard.o: $(BIN) testDrawCard.c $(BIN)/dominion.o $(BIN)/rngs.o
	gcc -o $(BIN)/testDrawCard.o -c testDrawCard.c -g $(BIN)/dominion.o $(BIN)/rngs.o $(CFLAGS)

testDrawCard: $(BIN)/testDrawCard.o
	gcc -o $(BIN)/testDrawCard -g $(BIN)/testDrawCard.o $(BIN)/dominion.o $(BIN)/rngs.o $(CFLAGS)

$(BIN)/badTestDrawCard.o: $(BIN) badTestDrawCard.c $(BIN)/dominion.o $(BIN)/rngs.o
	gcc -o $(BIN)/badTestDrawCard.o -c badTestDrawCard.c -g $(BIN)/dominion.o $(BIN)/rngs.o $(CFLAGS)

badTestDrawCard: $(BIN)/badTestDrawCard.o
	gcc -o $(BIN)/badTestDrawCard -g $(BIN)/badTestDrawCard.o $(BIN)/dominion.o $(BIN)/rngs.o $(CFLAGS)

$(BIN)/testBuyCard.o: $(BIN) testBuyCard.c $(BIN)/dominion.o $(BIN)/rngs.o
	gcc -o $(BIN)/testBuyCard.o -c testBuyCard.c -g $(BIN)/dominion.o $(BIN)/rngs.o $(CFLAGS)

testBuyCard: $(BIN)/testBuyCard.o
	gcc -o $(BIN)/testBuyCard -g $(BIN)/testBuyCard.o $(BIN)/dominion.o $(BIN)/rngs.o $(CFLAGS)

$(BIN)/testSuite.o: $(BIN) testSuite.c $(BIN)/dominion.o
	gcc -o $(BIN)/testSuite.o -c testSuite.c -g $(BIN)/dominion.o $(BIN)/rngs.o $(CFLAGS)

testAll: $(BIN)/testSuite.o
	gcc -o $(BIN)/testSuite -g $(BIN)/testSuite.o $(BIN)/dominion.o $(BIN)/rngs.o $(CFLAGS)

$(BIN)/interface.o: $(BIN) interface.h interface.c
	gcc -o $(BIN)/interface.o -c interface.c -g $(CFLAGS)

runtests: $(BIN) testDrawCard
	$(BIN)/testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

$(BIN)/player.o: $(BIN) player.c $(BIN)/interface.o
	gcc -o $(BIN)/player.o -c player.c -g $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/interface.o $(CFLAGS)

player: $(BIN)/player.o
	gcc -o $(BIN)/player -g $(BIN)/player.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -fr $(BIN)/*
