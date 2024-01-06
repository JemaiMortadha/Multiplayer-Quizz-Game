#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define NUM_QUESTIONS 5
#define MAX_ANSWER_LENGTH 50
#define NUM_TOTAL_QUESTIONS 75

void shuffleAnswers(char answers[3][MAX_ANSWER_LENGTH]) {
    for (int i = 2; i > 0; --i) {
        int j = rand() % (i + 1);
        char temp[MAX_ANSWER_LENGTH];
        strcpy(temp, answers[i]);
        strcpy(answers[i], answers[j]);
        strcpy(answers[j], temp);
    }
}

char getAnswer() {
    char answer;
    printf("Choose an answer (a, b, c): ");
    scanf(" %c", &answer);
    return answer;
}

void displayShuffledQuestion(int questionNumber, char question[MAX_ANSWER_LENGTH], char answers[3][MAX_ANSWER_LENGTH], char playerName[]) {
    printf("%s - Question %d: %s\n", playerName, questionNumber + 1, question);
    printf("a) %s\nb) %s\nc) %s\n", answers[0], answers[1], answers[2]);
}

int getRandomQuestionLineNumber(int *usedLineNumbers, int numUsedLineNumbers) {
    int randomLine;
    do {
        randomLine = (rand() % NUM_TOTAL_QUESTIONS) + 1;
    } while (isLineNumberUsed(usedLineNumbers, numUsedLineNumbers, randomLine));
    return randomLine;
}

int isLineNumberUsed(int *usedLineNumbers, int numUsedLineNumbers, int lineNumber) {
    for (int i = 0; i < numUsedLineNumbers; ++i) {
        if (usedLineNumbers[i] == lineNumber) {
            return 1;
        }
    }
    return 0;
}

void markLineNumberUsed(int *usedLineNumbers, int *numUsedLineNumbers, int lineNumber) {
    usedLineNumbers[*numUsedLineNumbers] = lineNumber;
    (*numUsedLineNumbers)++;
}

int main() {
    char player1Answers[NUM_QUESTIONS];
    char player2Answers[NUM_QUESTIONS];
    char player1Choice, player2Choice;
    int player1Score = 0, player2Score = 0;

    srand((unsigned int)time(NULL));

    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        int usedLineNumbers[NUM_QUESTIONS];
        int numUsedLineNumbers = 0;

        char question1[MAX_ANSWER_LENGTH];
        char question2[MAX_ANSWER_LENGTH];
        char answers1[3][MAX_ANSWER_LENGTH];
        char answers2[3][MAX_ANSWER_LENGTH];

        FILE *file = fopen("q.txt", "r");
        if (file == NULL) {
            fprintf(stderr, "Error: Unable to open the file 'q.txt'\n");
            exit(EXIT_FAILURE);
        }

        int randomLine1 = getRandomQuestionLineNumber(usedLineNumbers, numUsedLineNumbers);

        for (int j = 1; j <= randomLine1; ++j) {
            fscanf(file, "%*[^\n]\n");
        }
        fscanf(file, "%[^/]/%[^/]/%[^/]/%s", question1, answers1[0], answers1[1], answers1[2]);
        markLineNumberUsed(usedLineNumbers, &numUsedLineNumbers, randomLine1);

        int randomLine2;
        do {
            randomLine2 = getRandomQuestionLineNumber(usedLineNumbers, numUsedLineNumbers);
        } while (randomLine2 == randomLine1);

        for (int j = 1; j <= randomLine2; ++j) {
            fscanf(file, "%*[^\n]\n");
        }
        fscanf(file, "%[^/]/%[^/]/%[^/]/%s", question2, answers2[0], answers2[1], answers2[2]);
        markLineNumberUsed(usedLineNumbers, &numUsedLineNumbers, randomLine2);

        shuffleAnswers(answers1);
        shuffleAnswers(answers2);

        fclose(file);

        system("cls || clear");

        displayShuffledQuestion(i, question1, answers1, "Player 1");
        player1Choice = getAnswer();
        player1Answers[i] = player1Choice;

        displayShuffledQuestion(i, question2, answers2, "Player 2");
        player2Choice = getAnswer();
        player2Answers[i] = player2Choice;

        if (player1Choice == 'a' || player1Choice == 'A') {
            player1Score++;
        }

        if (player2Choice == 'a' || player2Choice == 'A') {
            player2Score++;
        }
    }

    printf("\nGame Over!\n\n");
    printf("Player 1's Score: %d\n", player1Score);
    printf("Player 2's Score: %d\n", player2Score);

    if (player1Score > player2Score) {
        printf("Player 1 is the winner!\n");
    } else if (player1Score < player2Score) {
        printf("Player 2 is the winner!\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}
