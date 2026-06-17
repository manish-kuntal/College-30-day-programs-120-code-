/*
 * Q102_Voting_Eligibility.c
 * -------------------------
 * A voting eligibility checking system that verifies if a person
 * is eligible to vote based on their age and citizenship.
 *
 * Features:
 *   - Age-based eligibility check (18+ years)
 *   - Citizenship verification
 *   - Voter ID status
 *   - Multiple voter check in one session
 *   - Detailed eligibility report
 *   - Input validation and edge case handling
 */

#include <stdio.h>
#include <string.h>

#define NAME_LEN 50
#define MIN_VOTING_AGE 18
#define MAX_REASONABLE_AGE 150

/* Structure to hold voter information */
typedef struct {
    char name[NAME_LEN];
    int age;
    char citizenship;   /* 'y' or 'n' */
    char hasVoterID;    /* 'y' or 'n' */
} Voter;

/* Display the header */
void displayHeader(void) {
    printf("\n=============================================\n");
    printf("       VOTING ELIGIBILITY CHECKER\n");
    printf("=============================================\n");
}

/* Check and display eligibility status */
void checkEligibility(Voter *v) {
    int eligible = 1;       /* Assume eligible, then check conditions */
    int reasons = 0;        /* Count of ineligibility reasons */

    printf("\n---------------------------------------------\n");
    printf("         ELIGIBILITY REPORT\n");
    printf("---------------------------------------------\n");
    printf("Name         : %s\n", v->name);
    printf("Age          : %d years\n", v->age);
    printf("Citizen      : %s\n", (v->citizenship == 'y' || v->citizenship == 'Y') ? "Yes" : "No");
    printf("Voter ID     : %s\n", (v->hasVoterID == 'y' || v->hasVoterID == 'Y') ? "Yes" : "No");
    printf("---------------------------------------------\n");

    /* Check age eligibility */
    if (v->age < MIN_VOTING_AGE) {
        printf("[X] NOT ELIGIBLE: Age is below %d years.\n", MIN_VOTING_AGE);
        printf("    You need to wait %d more year(s) to be eligible.\n",
               MIN_VOTING_AGE - v->age);
        eligible = 0;
        reasons++;
    } else {
        printf("[OK] Age requirement satisfied (%d years old).\n", v->age);
    }

    /* Check citizenship */
    if (v->citizenship != 'y' && v->citizenship != 'Y') {
        printf("[X] NOT ELIGIBLE: Not a citizen of this country.\n");
        printf("    Only citizens are allowed to vote.\n");
        eligible = 0;
        reasons++;
    } else {
        printf("[OK] Citizenship verified.\n");
    }

    /* Check voter ID (warning, not disqualifying) */
    if (v->hasVoterID != 'y' && v->hasVoterID != 'Y') {
        printf("[!] WARNING: No Voter ID card.\n");
        printf("    Please register for a Voter ID at your nearest election office.\n");
    } else {
        printf("[OK] Voter ID available.\n");
    }

    /* Final verdict */
    printf("\n=============================================\n");
    if (eligible) {
        if (v->hasVoterID == 'y' || v->hasVoterID == 'Y') {
            printf("RESULT: ELIGIBLE TO VOTE\n");
            printf("You are fully eligible. Please exercise your right to vote!\n");
        } else {
            printf("RESULT: CONDITIONALLY ELIGIBLE\n");
            printf("You meet age and citizenship requirements but need a Voter ID.\n");
            printf("Please register for Voter ID before the election date.\n");
        }
    } else {
        printf("RESULT: NOT ELIGIBLE TO VOTE\n");
        printf("Reason(s): %d condition(s) not met.\n", reasons);
    }
    printf("=============================================\n");
}

int main(void) {
    Voter voter;
    char continueCheck;
    int count = 0;

    printf("*********************************************\n");
    printf("*     VOTING ELIGIBILITY SYSTEM v1.0        *\n");
    printf("*********************************************\n");

    do {
        displayHeader();
        count++;
        printf("\n--- Voter #%d ---\n", count);

        /* Get voter name */
        printf("Enter full name: ");
        /* Clear leftover newline */
        if (count > 1) {
            getchar();
        }
        fgets(voter.name, NAME_LEN, stdin);
        /* Remove trailing newline from fgets */
        voter.name[strcspn(voter.name, "\n")] = '\0';

        /* Validate name is not empty */
        if (strlen(voter.name) == 0) {
            printf("Error: Name cannot be empty!\n");
            continue;
        }

        /* Get and validate age */
        printf("Enter age: ");
        if (scanf("%d", &voter.age) != 1) {
            printf("Error: Invalid age input!\n");
            while (getchar() != '\n');
            continue;
        }

        /* Edge case: unreasonable age values */
        if (voter.age < 0) {
            printf("Error: Age cannot be negative!\n");
            continue;
        }
        if (voter.age > MAX_REASONABLE_AGE) {
            printf("Error: Age %d seems unreasonable (max: %d).\n",
                   voter.age, MAX_REASONABLE_AGE);
            continue;
        }
        if (voter.age == 0) {
            printf("Error: Age cannot be zero!\n");
            continue;
        }

        /* Get citizenship status */
        printf("Are you a citizen of this country? (y/n): ");
        scanf(" %c", &voter.citizenship);

        /* Get voter ID status */
        printf("Do you have a Voter ID card? (y/n): ");
        scanf(" %c", &voter.hasVoterID);

        /* Check and display eligibility */
        checkEligibility(&voter);

        /* Ask to check another voter */
        printf("\nCheck another voter? (y/n): ");
        scanf(" %c", &continueCheck);

    } while (continueCheck == 'y' || continueCheck == 'Y');

    printf("\n--- Session Summary ---\n");
    printf("Total voters checked: %d\n", count);
    printf("\nThank you for using the Voting Eligibility System!\n");

    return 0;
}
