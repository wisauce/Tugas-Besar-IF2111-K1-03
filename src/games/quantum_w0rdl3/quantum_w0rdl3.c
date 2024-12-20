#include "../../console.h"
#include "quantum_w0rdl3.h"

char word_bank[QUANTUM_MAX_WORDS][QUANTUM_WORD_LENGTH + 1] = {
    "TRULY", "LEAKY", "LUCKY", "SLICK", "BUILD",
    "HEART", "DANCE", "PAUSE", "CROWN", "BEACH"
};

char upper2(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

boolean compare2(const char* str1, const char* str2, int length) {
    int i;
    for (i = 0; i < length; i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}

boolean checkArray(const char* word, const char* word_array[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        if (word_array[i] != NULL && compare2(word, word_array[i], QUANTUM_WORD_LENGTH)) {
            return true;
        }
    }
    return false;
}

void copy2(char* dest, const char* src, int length) {
    int i;
    for (i = 0; i < length; i++) {
        dest[i] = src[i];
    }
    dest[length] = '\0';
}

void checkGuess2(const char* target, const char* guess, char* result) {
    int target_count[26] = {0};
    boolean matched_exact[QUANTUM_WORD_LENGTH] = {false};
    int i, idx = 0;

    for (i = 0; i < QUANTUM_WORD_LENGTH; i++) {
        if (guess[i] != target[i]) {
            target_count[target[i] - 'A']++;
        } else {
            matched_exact[i] = true;
        }
    }

    for (i = 0; i < QUANTUM_WORD_LENGTH; i++) {
        if (matched_exact[i]) {
            result[idx++] = guess[i];
            result[idx++] = ' ';
        } else if (target_count[guess[i] - 'A'] > 0) {
            result[idx++] = guess[i];
            result[idx++] = '*';
            result[idx++] = ' ';
            target_count[guess[i] - 'A']--;
        } else {
            result[idx++] = guess[i];
            result[idx++] = '%';
            result[idx++] = ' ';
        }
    }

    if (idx > 0 && result[idx - 1] == ' ') {
        idx--;
    }
    result[idx] = '\0';
}

boolean read2(char* guess) {
    int count = 0;
    START();
    
    while (!IsEOP() && GetCC() == ' ') {
        ADV();
    }
    
    while (!IsEOP() && GetCC() != ' ' && count < QUANTUM_WORD_LENGTH) {
        guess[count] = upper2(GetCC());
        count++;
        ADV();
    }
    
    while (!IsEOP()) {
        ADV();
    }
    
    if (count != QUANTUM_WORD_LENGTH) {
        printf("Error: Word must be exactly 5 letters!\n");
        return false;
    }
    
    guess[QUANTUM_WORD_LENGTH] = '\0';
    return true;
}

int QUANTUMW0RDL3(ListofUsers *userlist, int *currentUserIndex) 
{
    clearterminal();
    srand(time(NULL));
    
    char target_words[QUANTUM_TARGET_WORDS][QUANTUM_WORD_LENGTH + 1];
    char current_guess[QUANTUM_WORD_LENGTH + 1];
    char results[QUANTUM_MAX_TRIES][QUANTUM_TARGET_WORDS][QUANTUM_WORD_LENGTH * 3 + 1];
    boolean word_solved[QUANTUM_TARGET_WORDS] = {false};
    int tries = 0;
    int solved_count = 0;
    User *currentUser = &userlist->TI[*currentUserIndex];

    if (currentUser->money < 750) 
    {
        printf("Saldo Anda tidak cukup untuk bermain Quantum W0rdl3.\n");
        return 0;
    }
    
    const char* selected_words[QUANTUM_TARGET_WORDS] = {NULL};
    for (int i = 0; i < QUANTUM_TARGET_WORDS; i++) {
        int idx = rand() % QUANTUM_MAX_WORDS; 
        while (checkArray(word_bank[idx], selected_words, i)) {
            idx = rand() % QUANTUM_MAX_WORDS; 
        }

        
        copy2(target_words[i], word_bank[idx], QUANTUM_WORD_LENGTH);
        selected_words[i] = target_words[i];
    }
    
    // printf("DEBUG: Target words are: %s %s %s %s\n", 
        //    target_words[0], target_words[1], target_words[2], target_words[3]);

    printf(" .-''-.                                                                        \n");
    printf("  //'` `\\|                          _..._                       __  __   ___    \n");
    printf(" '/'    '|                        .'     '.                    |  |/  `.'   `.  \n");
    printf("|'      '|                       .   .-.   .     .|            |   .-.  .-.   ' \n");
    printf("||     /||                 __    |  '   '  |   .' |_           |  |  |  |  |  | \n");
    printf(" \\'. .'/||     _    _   .:--.'.  |  |   |  | .'     |   _    _ |  |  |  |  |  | \n");
    printf("  `--'` ||    | '  / | / |   \\ | |  |   |  |'--.  .-'  | '  / ||  |  |  |  |  | \n");
    printf("        ||   .' | .' | `\" __ | | |  |   |  |   |  |   .' | .' ||  |  |  |  |  | \n");
    printf("        || />/  | /  |  .'.''| | |  |   |  |   |  |   /  | /  ||__|  |__|  |__| \n");
    printf("        ||//|   `'.  | / /   | |_|  |   |  |   |  '.'|   `'.  |                  \n");
    printf("        |'/ '   .'|  '/\\ \\._,\\ '/|  |   |  |   |   / '   .'|  '/                \n");
    printf("        |/   `-'  `--'  `--'  `\" '--'   '--'   `'-'   `-'  `--'                 \n");
    printf("                                    _______      .---...-'''-.                  \n");
    printf("                                    \\  ___ `'.   |   |\\.-''\\ \\                  \n");
    printf("       _     _                       ' |--.\\  \\  |   |       | |                \n");
    printf(" /\\    \\\\   // .-''` ''-.    .-,.--. | |    \\  ' |   |    __/ /                 \n");
    printf(" `\\\\  //\\\\ //.'          '.  |  .-. || |     |  '|   |   |_  '.                 \n");
    printf("   \\`//  \\//              ` | |  | || |     |  ||   |      `.  \\                \n");
    printf("    \\|   |/'                '| |  | || |     ' .'|   |        \\ '.               \n");
    printf("     '     |         .-.    || |  '- | |___.' /' |   |         , |               \n");
    printf("           .        |   |   .| |    /_______.'/  |   |         | |               \n");
    printf("            .       '._.'  / | |    \\_______|/   '---'        / ,'               \n");
    printf("             '._         .'  |_|                      -....--'  /                \n");
    printf("                '-....-'`                             `.. __..-'   \n");

    printf("\n750 COINS HAVE BEEN SPENT TO JOIN THIS CHALLENGE. GO FOR THE WIN!\n\n");
    currentUser->money -= 750;
    
    printf("You need to guess 4 different target words using a single word each try.\n");
    printf("You have 9 chances to guess all words correctly.\n");
    printf("Input format: Enter a single 5-letter word\n\n");
    
    for (int i = 0; i < QUANTUM_MAX_TRIES; i++) {
        //printf("Try %d: ", i + 1);
        for (int j = 0; j < QUANTUM_TARGET_WORDS; j++){
            printf(" - - - - -   ");
        }
        printf("\n");
    }
    
    while (tries < QUANTUM_MAX_TRIES && solved_count < QUANTUM_TARGET_WORDS) {
        printf("\nAttempt %d/%d\n", tries + 1, QUANTUM_MAX_TRIES);
        printf("Enter your guess: ");
        
        if (!read2(current_guess)) {
            continue;
        }
        
        printf("\nResults for '%s':\n\n", current_guess);
        
        for (int i = 0; i < QUANTUM_TARGET_WORDS; i++) {
            if (!word_solved[i]) {
                checkGuess2(target_words[i], current_guess, results[tries][i]);
                if (compare2(current_guess, target_words[i], QUANTUM_WORD_LENGTH)) {
                    word_solved[i] = true;
                    solved_count++;
                }
            } else {
                copy2(results[tries][i], results[tries-1][i], QUANTUM_WORD_LENGTH * 3);
            }
        }
        
        for (int i = 0; i <= tries; i++) {
            printf("Try %d: ", i + 1);
            for (int j = 0; j < QUANTUM_TARGET_WORDS; j++) {
                printf("%s  ", results[i][j]);
            }
            printf("\n");
        }
        
        for (int i = tries + 1; i < QUANTUM_MAX_TRIES; i++) {
            printf("Try %d: ", i + 1);
            for (int j = 0; j < QUANTUM_TARGET_WORDS; j++) {
                printf(" - - - - -   ");
            }
            printf("\n");
        }
        
        //printf("\nStatus:\n");
        //printf("Words solved: %d/4\n", solved_count);
        for (int i = 0; i < QUANTUM_TARGET_WORDS; i++) {
            if (word_solved[i]) {
                printf("Word %d: SOLVED!\n", i + 1);
            } else {
                printf("Word %d: Not solved yet\n", i + 1);
            }

        }
        tries++;
    }
    
    printf("\nGame Over!\n");
    printf("Words solved: %d/4\n", solved_count);
    printf("Attempts used: %d/9\n", tries);
    
    if (solved_count == QUANTUM_TARGET_WORDS) {
        printf("Congratulations! You solved all words! You've earned 15,000 coins as your reward. Enjoy your victory!\n");
        currentUser->money += 15000;
        return 15000;
    } else {
        printf("Better luck next time!\n");
        printf("The target words were: %s %s %s %s\n", 
               target_words[0], target_words[1], target_words[2], target_words[3]);
        return 0;
    }
}
