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

# $(BIN)/testDrawCard.o: $(BIN) testDrawCard.c $(BIN)/dominion.o $(BIN)/rngs.o
# 	gcc -o $(BIN)/testDrawCard.o -c testDrawCard.c -g $(BIN)/dominion.o $(BIN)/rngs.o $(CFLAGS)

# testDrawCard: $(BIN)/testDrawCard.o
# 	gcc -o $(BIN)/testDrawCard -g $(BIN)/testDrawCard.o $(BIN)/dominion.o $(BIN)/rngs.o $(CFLAGS)

# $(BIN)/badTestDrawCard.o: $(BIN) badTestDrawCard.c $(BIN)/dominion.o $(BIN)/rngs.o
# 	gcc -o $(BIN)/badTestDrawCard.o -c badTestDrawCard.c -g $(BIN)/dominion.o $(BIN)/rngs.o $(CFLAGS)

# badTestDrawCard: $(BIN)/badTestDrawCard.o
# 	gcc -o $(BIN)/badTestDrawCard -g $(BIN)/badTestDrawCard.o $(BIN)/dominion.o $(BIN)/rngs.o $(CFLAGS)

# $(BIN)/testBuyCard.o: $(BIN) testBuyCard.c $(BIN)/dominion.o $(BIN)/rngs.o
# 	gcc -o $(BIN)/testBuyCard.o -c testBuyCard.c -g $(BIN)/dominion.o $(BIN)/rngs.o $(CFLAGS)

# testBuyCard: $(BIN)/testBuyCard.o
# 	gcc -o $(BIN)/testBuyCard -g $(BIN)/testBuyCard.o $(BIN)/dominion.o $(BIN)/rngs.o $(CFLAGS)

# $(BIN)/testSuite.o: $(BIN) testSuite.c $(BIN)/dominion.o
# 	gcc -o $(BIN)/testSuite.o -c testSuite.c -g $(BIN)/dominion.o $(BIN)/rngs.o $(CFLAGS)

# testAll: $(BIN)/testSuite.o
#	gcc -o $(BIN)/testSuite -g $(BIN)/testSuite.o $(BIN)/dominion.o $(BIN)/rngs.o $(CFLAGS)

$(BIN)/testAssert.o: $(BIN) testAssert.c
	gcc -o $(BIN)/testAssert.o -c testAssert.c

$(BIN)/unittest1.o: $(BIN) unittest1.c
	gcc -o $(BIN)/unittest1.o -c unittest1.c $(CFLAGS)

unittest1: $(BIN)/unittest1.o $(BIN)/unittest1.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/testAssert.o
	gcc -o $(BIN)/unittest1 -g $(BIN)/unittest1.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/testAssert.o $(CFLAGS)

$(BIN)/unittest2.o: $(BIN) unittest2.c
	gcc -o $(BIN)/unittest2.o -c unittest2.c $(CFLAGS)

unittest2: $(BIN)/unittest2.o $(BIN)/unittest2.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/testAssert.o
	gcc -o $(BIN)/unittest2 -g $(BIN)/unittest2.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/testAssert.o $(CFLAGS)

$(BIN)/unittest3.o: $(BIN) unittest3.c
	gcc -o $(BIN)/unittest3.o -c unittest3.c $(CFLAGS)

unittest3: $(BIN)/unittest3.o $(BIN)/unittest3.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/testAssert.o
	gcc -o $(BIN)/unittest3 -g $(BIN)/unittest3.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/testAssert.o $(CFLAGS)

$(BIN)/unittest4.o: $(BIN) unittest4.c
	gcc -o $(BIN)/unittest4.o -c unittest4.c $(CFLAGS)

unittest4: $(BIN)/unittest4.o $(BIN)/unittest4.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/testAssert.o
	gcc -o $(BIN)/unittest4 -g $(BIN)/unittest4.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/testAssert.o $(CFLAGS)

$(BIN)/cardtest1.o: $(BIN) cardtest1.c
	gcc -o $(BIN)/cardtest1.o -c cardtest1.c $(CFLAGS)

cardtest1: $(BIN)/cardtest1.o $(BIN)/cardtest1.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/testAssert.o
	gcc -o $(BIN)/cardtest1 -g $(BIN)/cardtest1.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/testAssert.o $(CFLAGS)

$(BIN)/cardtest2.o: $(BIN) cardtest2.c
	gcc -o $(BIN)/cardtest2.o -c cardtest2.c $(CFLAGS)

cardtest2: $(BIN)/cardtest2.o $(BIN)/cardtest2.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/testAssert.o
	gcc -o $(BIN)/cardtest2 -g $(BIN)/cardtest2.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/testAssert.o $(CFLAGS)

$(BIN)/cardtest3.o: $(BIN) cardtest3.c
	gcc -o $(BIN)/cardtest3.o -c cardtest3.c $(CFLAGS)

cardtest3: $(BIN)/cardtest3.o $(BIN)/cardtest3.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/testAssert.o
	gcc -o $(BIN)/cardtest3 -g $(BIN)/cardtest3.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/testAssert.o $(CFLAGS)

$(BIN)/cardtest4.o: $(BIN) cardtest4.c
	gcc -o $(BIN)/cardtest4.o -c cardtest4.c $(CFLAGS)

cardtest4: $(BIN)/cardtest4.o $(BIN)/cardtest4.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/testAssert.o
	gcc -o $(BIN)/cardtest4 -g $(BIN)/cardtest4.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/testAssert.o $(CFLAGS)

$(BIN)/randomtestadventurer.o: $(BIN) randomtestadventurer.c
	gcc -o $(BIN)/randomtestadventurer.o -c randomtestadventurer.c $(CFLAGS)

randomtestadventurer: $(BIN)/randomtestadventurer.o $(BIN)/randomtestadventurer.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/testAssert.o
	gcc -o $(BIN)/randomtestadventurer -g $(BIN)/randomtestadventurer.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/testAssert.o $(CFLAGS)

$(BIN)/randomtestcard1.o: $(BIN) randomtestcard1.c
	gcc -o $(BIN)/randomtestcard1.o -c randomtestcard1.c $(CFLAGS)

randomtestcard1: $(BIN)/randomtestcard1.o $(BIN)/randomtestcard1.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/testAssert.o
	gcc -o $(BIN)/randomtestcard1 -g $(BIN)/randomtestcard1.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/testAssert.o $(CFLAGS)

$(BIN)/randomtestcard2.o: $(BIN) randomtestcard2.c
	gcc -o $(BIN)/randomtestcard2.o -c randomtestcard2.c $(CFLAGS)

randomtestcard2: $(BIN)/randomtestcard2.o $(BIN)/randomtestcard2.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/testAssert.o
	gcc -o $(BIN)/randomtestcard2 -g $(BIN)/randomtestcard2.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/testAssert.o $(CFLAGS)

unittestresults.out: $(BIN) unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer randomtestcard1 randomtestcard2
	$(BIN)/unittest1 > $(BIN)/unittestresult.out 2>&1
	$(BIN)/unittest2 >> $(BIN)/unittestresult.out 2>&1
	$(BIN)/unittest3 >> $(BIN)/unittestresult.out 2>&1
	$(BIN)/unittest4 >> $(BIN)/unittestresult.out 2>&1
	$(BIN)/cardtest1 >> $(BIN)/unittestresult.out 2>&1
	$(BIN)/cardtest2 >> $(BIN)/unittestresult.out 2>&1
	$(BIN)/cardtest3 >> $(BIN)/unittestresult.out 2>&1
	$(BIN)/cardtest4 >> $(BIN)/unittestresult.out 2>&1
	$(BIN)/randomtestadventurer >> $(BIN)/unittestresult.out 2>&1
	$(BIN)/randomtestcard1 >> $(BIN)/unittestresult.out 2>&1
	$(BIN)/randomtestcard2 >> $(BIN)/unittestresult.out 2>&1
	gcov -o $(BIN) dominion.c >> $(BIN)/unittestresult.out 2>&1
	cat dominion.c.gcov >> $(BIN)/unittestresult.out 2>&1
	rm dominion.c.gcov

$(BIN)/interface.o: $(BIN) interface.h interface.c
	gcc -o $(BIN)/interface.o -c interface.c -g $(CFLAGS)


$(BIN)/player.o: $(BIN) player.c $(BIN)/interface.o
	gcc -o $(BIN)/player.o -c player.c -g $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/interface.o $(CFLAGS)

player: $(BIN)/player.o
	gcc -o $(BIN)/player -g $(BIN)/player.o $(BIN)/dominion.o $(BIN)/rngs.o $(BIN)/interface.o $(CFLAGS)

all: playdom player

clean:
	rm -fr $(BIN)/*
