#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

// This file tests the adventurer card in dominion.c

int main() {

	srand(time(NULL));

	int i;
	int player;
	int NumErrors; 
	int NumChecks = 10;
	int cardAmount = 2;
	int checkCount;
	int numItr = 5000;

	printf("--------- TESTING: Adventurer card ----------\n");

	for(i=0; i<numItr; i++){
		int numPlayers = rand() % (MAX_PLAYERS -1) + 2;
		struct gameState G; 
		struct gameState testG;

		int m[10] = {adventurer, province, gardens, smithy, great_hall, remodel, village, embargo, salvager, duchy};


		initializeGame(numPlayers, m, rand(), &G);
		player = rand() % numPlayers;
		G.whoseTurn = player;

		// Copy into new game state
		memcpy(&testG, &G, sizeof(struct gameState));

		// Call the adventurer card with random inputs
		//cardEffect(adventurer, c1, c2, c3, &G, handPos, &bonus);
		cardEffect(adventurer, 0, 0, 0, &testG, 0, 0);

		// Adventurer: Reveal cards from your deck until you reveal 2 Treasure cards. 
		// Put those Treasure cards into yout hand and discard the other reveal cards. 
		int card1 = G.hand[player][G.handCount[player]-1];
		int card2 = G.hand[player][G.handCount[player]-2];
		checkCount = testG.handCount[player];	
	
		// TEST 6: Test drawing cards until you get 2 coin cards
		printf("TEST 1: Testing drawing cards until you get 2 coin cards\n");
		if(testG.handCount[player] - checkCount == 2){
			printf("PASSED. Coin card amount expected: %d, count finish: %d\n", 2, testG.handCount[player] - checkCount);
		}
		else {
			printf("FAILED. Coin card amount expected: %d, count finish: %d\n", 2, testG.handCount[player] - checkCount);
			NumErrors= NumErrors + 1;
		}

		// Test 1: Check to see that player adds two cards to their deck
		printf("TEST 1: Check to see that player adds two cards to their deck\n");
		if(G.handCount[player] != testG.handCount[player] + 2){
			printf("FAILED: Player %d did not draw two cards from the deck\n", player);
			NumErrors = NumErrors + 1; 
		}
		else {
			printf("PASSED: Player %d drew two cards from the deck\n", player);
		}

		// Test 2: Check that they only grabbed 2 coin cards...
		printf("TEST 2: Check that they only grabbed 2 cards on their turn\n");
		if(cardAmount == testG.coins){
			printf("PASSED: Coin cards expected: %d, coin cards found: %d\n", cardAmount, testG.coins);
		}
		else {
			printf("FAILED: Coin cards expected: %d, coin cards found: %d\n", cardAmount, testG.coins);
			NumErrors = NumErrors + 1;
		}	

		// Test 3: Make sure that the first card added is a Treasure card
		printf("Test 3: Make sure that the first card added is a Treasure card\n");
		if(card1 != copper && card1 != silver && card1 != gold){
			printf("FAILED: Player %d first drawn card is not a Treasure card\n", player);
			NumErrors = NumErrors + 1;
		}	
		else {
			printf("PASSED: Player %d's first drawn card is a Treasure card\n", player);
		}
		// Test 4: Make sure that the second card added is a Treasure card
		printf("TEST 4: Make sure that the second card added is a Treasue card\n");
		if(card2 != copper && card2 != silver && card2 != gold){
			printf("FAILED: Player %d second drawn card is not a Treasure card\n", player);
			NumErrors= NumErrors + 1;
		}
		else {
			printf("PASSED: Player %d's second drawn card is a Treasure card\n", player);
		}

		// Test 5: Make sure that the adventurer card was added to the played cards pile
		printf("TEST 5: Make sure that the adventurer card was added to the played cards pile\n");
		if(testG.playedCardCount == 1){
			printf("PASSED: The played card pile increased by 1. Adventurer card was added\n");
		}	
		else {
			printf("FAILED: The Adventurer card was not added to the played card pile\n");
			NumErrors = NumErrors + 1;
		}
		
		// Test 6: Make sure that non-coin cards were discarded.
		printf("TEST 6: Ensure that non-coin cards were discarded\n");
		if(testG.discardCount[player] == 1){
			printf("PASSED. Expected discard amount: %d, Result discarded: %d\n", 1, testG.discardCount[player]);
		}
		else {
			printf("FAILED. Expected discard amount: %d, Result discarded: %d\n", 1, testG.discardCount[player]);
			NumErrors= NumErrors + 1;
		}

		// Test 7: Test for state changes. Make sure victory card counts remain same
		printf("TEST 7: Test for state changes. Make sure victory card counts remain the same\n");
		if(G.supplyCount[estate] != testG.supplyCount[estate]){
			printf("FAILED. Estate count does not match. Expected: %d, Got: %d\n", G.supplyCount[estate], testG.supplyCount[estate]);
			NumErrors= NumErrors + 1;
		}
		if(G.supplyCount[duchy] != testG.supplyCount[duchy]){
			printf("FAILED. Duchy count does not match. Expected: %d, Got: %d\n", G.supplyCount[duchy], testG.supplyCount[duchy]);
			NumErrors= NumErrors + 1;
		}
		if(G.supplyCount[province] != testG.supplyCount[province]){
			printf("FAILED. Province count does not match. Expected: %d, Got: %d\n", G.supplyCount[province], testG.supplyCount[province]);
			NumErrors= NumErrors + 1;
		}
		else {
			printf("PASSED. No state change. Victory card count are the same.\n");
		}

		printf("\n\n");
	}
	printf("\nTotal tests: %d\n", numItr);
	printf("Tests Passed: %d\n", numItr * NumChecks - NumErrors);
	printf("Tests Failed: %d\n\n", NumErrors);

	return 0; 
}
