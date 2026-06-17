/*
 * Q104_Quiz_Application.c
 * -----------------------
 * A multiple-choice quiz application with score tracking,
 * answer review, and performance rating.
 *
 * Features:
 *   - 10 multiple choice questions (C programming topic)
 *   - 4 options per question (A, B, C, D)
 *   - Real-time score tracking
 *   - Answer review at the end
 *   - Performance percentage and grade
 *   - Input validation
 */

#include <stdio.h>
#include <ctype.h>

#define TOTAL_QUESTIONS 10
#define OPTIONS 4

/* Structure for a quiz question */
typedef struct {
    char question[200];
    char options[OPTIONS][100];
    char correctAnswer;     /* 'A', 'B', 'C', or 'D' */
} Question;

/* Initialize quiz questions about C programming */
void initQuestions(Question quiz[]) {
    /* Question 1 */
    snprintf(quiz[0].question, 200, "Who is the creator of the C programming language?");
    snprintf(quiz[0].options[0], 100, "A. Bjarne Stroustrup");
    snprintf(quiz[0].options[1], 100, "B. Dennis Ritchie");
    snprintf(quiz[0].options[2], 100, "C. James Gosling");
    snprintf(quiz[0].options[3], 100, "D. Guido van Rossum");
    quiz[0].correctAnswer = 'B';

    /* Question 2 */
    snprintf(quiz[1].question, 200, "Which header file is required for printf() and scanf()?");
    snprintf(quiz[1].options[0], 100, "A. stdlib.h");
    snprintf(quiz[1].options[1], 100, "B. string.h");
    snprintf(quiz[1].options[2], 100, "C. stdio.h");
    snprintf(quiz[1].options[3], 100, "D. math.h");
    quiz[1].correctAnswer = 'C';

    /* Question 3 */
    snprintf(quiz[2].question, 200, "What is the size of 'int' on most 32-bit systems?");
    snprintf(quiz[2].options[0], 100, "A. 1 byte");
    snprintf(quiz[2].options[1], 100, "B. 2 bytes");
    snprintf(quiz[2].options[2], 100, "C. 4 bytes");
    snprintf(quiz[2].options[3], 100, "D. 8 bytes");
    quiz[2].correctAnswer = 'C';

    /* Question 4 */
    snprintf(quiz[3].question, 200, "Which operator is used to access a member of a structure using a pointer?");
    snprintf(quiz[3].options[0], 100, "A. .");
    snprintf(quiz[3].options[1], 100, "B. ->");
    snprintf(quiz[3].options[2], 100, "C. ::");
    snprintf(quiz[3].options[3], 100, "D. #");
    quiz[3].correctAnswer = 'B';

    /* Question 5 */
    snprintf(quiz[4].question, 200, "What does 'sizeof' return in C?");
    snprintf(quiz[4].options[0], 100, "A. The value of a variable");
    snprintf(quiz[4].options[1], 100, "B. The address of a variable");
    snprintf(quiz[4].options[2], 100, "C. The size in bytes of a type or variable");
    snprintf(quiz[4].options[3], 100, "D. The length of a string");
    quiz[4].correctAnswer = 'C';

    /* Question 6 */
    snprintf(quiz[5].question, 200, "Which loop is guaranteed to execute at least once?");
    snprintf(quiz[5].options[0], 100, "A. for loop");
    snprintf(quiz[5].options[1], 100, "B. while loop");
    snprintf(quiz[5].options[2], 100, "C. do-while loop");
    snprintf(quiz[5].options[3], 100, "D. None of the above");
    quiz[5].correctAnswer = 'C';

    /* Question 7 */
    snprintf(quiz[6].question, 200, "What is the default return type of main() in C?");
    snprintf(quiz[6].options[0], 100, "A. void");
    snprintf(quiz[6].options[1], 100, "B. int");
    snprintf(quiz[6].options[2], 100, "C. float");
    snprintf(quiz[6].options[3], 100, "D. char");
    quiz[6].correctAnswer = 'B';

    /* Question 8 */
    snprintf(quiz[7].question, 200, "What is the correct way to declare a pointer to an integer?");
    snprintf(quiz[7].options[0], 100, "A. int p;");
    snprintf(quiz[7].options[1], 100, "B. int *p;");
    snprintf(quiz[7].options[2], 100, "C. *int p;");
    snprintf(quiz[7].options[3], 100, "D. pointer int p;");
    quiz[7].correctAnswer = 'B';

    /* Question 9 */
    snprintf(quiz[8].question, 200, "Which function is used to allocate memory dynamically in C?");
    snprintf(quiz[8].options[0], 100, "A. alloc()");
    snprintf(quiz[8].options[1], 100, "B. new()");
    snprintf(quiz[8].options[2], 100, "C. malloc()");
    snprintf(quiz[8].options[3], 100, "D. create()");
    quiz[8].correctAnswer = 'C';

    /* Question 9 */
    snprintf(quiz[9].question, 200, "What will be the output of: printf(\"%%d\", 5 + 3 * 2);?");
    snprintf(quiz[9].options[0], 100, "A. 16");
    snprintf(quiz[9].options[1], 100, "B. 11");
    snprintf(quiz[9].options[2], 100, "C. 10");
    snprintf(quiz[9].options[3], 100, "D. 13");
    quiz[9].correctAnswer = 'B';
}

/* Display a single question */
void displayQuestion(Question *q, int qNum) {
    int i;
    printf("\n--------------------------------------------\n");
    printf("Question %d: %s\n", qNum, q->question);
    printf("--------------------------------------------\n");
    for (i = 0; i < OPTIONS; i++) {
        printf("  %s\n", q->options[i]);
    }
}

/* Get valid answer from user */
char getAnswer(void) {
    char answer;
    while (1) {
        printf("\nYour answer (A/B/C/D): ");
        scanf(" %c", &answer);
        answer = toupper(answer);
        if (answer >= 'A' && answer <= 'D') {
            return answer;
        }
        printf("Invalid input! Please enter A, B, C, or D.\n");
    }
}

/* Display grade based on percentage */
void displayGrade(float percentage) {
    printf("\n============================================\n");
    printf("           PERFORMANCE GRADE\n");
    printf("============================================\n");

    if (percentage >= 90.0f) {
        printf("  Grade: A+ (Outstanding!)\n");
    } else if (percentage >= 80.0f) {
        printf("  Grade: A  (Excellent!)\n");
    } else if (percentage >= 70.0f) {
        printf("  Grade: B  (Very Good)\n");
    } else if (percentage >= 60.0f) {
        printf("  Grade: C  (Good)\n");
    } else if (percentage >= 50.0f) {
        printf("  Grade: D  (Average)\n");
    } else if (percentage >= 40.0f) {
        printf("  Grade: E  (Below Average)\n");
    } else {
        printf("  Grade: F  (Needs Improvement)\n");
    }
    printf("============================================\n");
}

int main(void) {
    Question quiz[TOTAL_QUESTIONS];
    char userAnswers[TOTAL_QUESTIONS];
    int score = 0;
    int i;
    float percentage;
    char reviewChoice;

    /* Initialize questions */
    initQuestions(quiz);

    printf("*********************************************\n");
    printf("*         C PROGRAMMING QUIZ                *\n");
    printf("*        Total Questions: %d                *\n", TOTAL_QUESTIONS);
    printf("*        Each question: 1 mark              *\n");
    printf("*********************************************\n");
    printf("\nAre you ready? Press Enter to start...");
    getchar();  /* Wait for enter */

    /* Ask each question */
    for (i = 0; i < TOTAL_QUESTIONS; i++) {
        printf("\n[Question %d of %d]", i + 1, TOTAL_QUESTIONS);
        displayQuestion(&quiz[i], i + 1);
        userAnswers[i] = getAnswer();

        /* Immediate feedback */
        if (userAnswers[i] == quiz[i].correctAnswer) {
            printf("CORRECT! +1 point\n");
            score++;
        } else {
            printf("WRONG! The correct answer was: %c\n", quiz[i].correctAnswer);
        }
        printf("Running Score: %d/%d\n", score, i + 1);
    }

    /* Calculate percentage */
    percentage = ((float)score / TOTAL_QUESTIONS) * 100.0f;

    /* Display final results */
    printf("\n\n*********************************************\n");
    printf("*             QUIZ RESULTS                  *\n");
    printf("*********************************************\n");
    printf("  Total Questions  : %d\n", TOTAL_QUESTIONS);
    printf("  Correct Answers  : %d\n", score);
    printf("  Wrong Answers    : %d\n", TOTAL_QUESTIONS - score);
    printf("  Score Percentage : %.1f%%\n", percentage);
    printf("*********************************************\n");

    displayGrade(percentage);

    /* Offer answer review */
    printf("\nWould you like to review all answers? (y/n): ");
    scanf(" %c", &reviewChoice);

    if (reviewChoice == 'y' || reviewChoice == 'Y') {
        printf("\n============================================\n");
        printf("           ANSWER REVIEW\n");
        printf("============================================\n");
        for (i = 0; i < TOTAL_QUESTIONS; i++) {
            printf("\nQ%d: %s\n", i + 1, quiz[i].question);
            printf("   Your Answer   : %c\n", userAnswers[i]);
            printf("   Correct Answer: %c\n", quiz[i].correctAnswer);
            printf("   Result        : %s\n",
                   (userAnswers[i] == quiz[i].correctAnswer) ? "CORRECT" : "WRONG");
        }
    }

    printf("\nThank you for taking the quiz! Keep learning C!\n");

    return 0;
}
