#include "quantumW0rdl3.h"

// Word bank
const char word_bank[MAX_WORDS][WORD_LENGTH + 1] = {
    "TRULY", "LEAKY", "LUCKY", "SLICK", "BUILD",
    "HEART", "DANCE", "PAUSE", "CROWN", "BEACH"
};

// Helper functions
char upper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

boolean compare(const char* str1, const char* str2, int length) {
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
        if (word_array[i] != NULL && compare(word, word_array[i], WORD_LENGTH)) {
            return true;
        }
    }
    return false;
}

void copy(char* dest, const char* src, int length) {
    int i;
    for (i = 0; i < length; i++) {
        dest[i] = src[i];
    }
    dest[length] = '\0';
}

void checkGuess(const char* target, const char* guess, char* result) {
    int target_count[26] = {0};
    boolean matched_exact[WORD_LENGTH] = {false};
    int i, idx = 0;

    // Count unmatched letters in target
    for (i = 0; i < WORD_LENGTH; i++) {
        if (guess[i] != target[i]) {
            target_count[target[i] - 'A']++;
        } else {
            matched_exact[i] = true;
        }
    }

    // Generate result string
    for (i = 0; i < WORD_LENGTH; i++) {
        if (matched_exact[i]) {
            // Exact match - letter remains unchanged
            result[idx++] = guess[i];
            result[idx++] = ' ';
        } else if (target_count[guess[i] - 'A'] > 0) {
            // Letter exists but wrong position - marked with *
            result[idx++] = guess[i];
            result[idx++] = '*';
            result[idx++] = ' ';
            target_count[guess[i] - 'A']--;
        } else {
            // Letter not in word - marked with %
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

// Function to read a single word
boolean read(char* guess) {
    int count = 0;
    START();
    
    // Skip leading spaces
    while (!IsEOP() && GetCC() == ' ') {
        ADV();
    }
    
    // Read the word
    while (!IsEOP() && GetCC() != ' ' && count < WORD_LENGTH) {
        guess[count] = upper(GetCC());
        count++;
        ADV();
    }
    
    // Skip trailing characters
    while (!IsEOP()) {
        ADV();
    }
    
    // Validate word length
    if (count != WORD_LENGTH) {
        printf("Error: Word must be exactly 5 letters!\n");
        return false;
    }
    
    guess[WORD_LENGTH] = '\0';
    return true;
}

// Main game function
int quantum() {
    srand(time(NULL));
    
    char target_words[TARGET_WORDS][WORD_LENGTH + 1];
    char current_guess[WORD_LENGTH + 1];
    char results[MAX_TRIES][TARGET_WORDS][WORD_LENGTH * 3 + 1];
    boolean word_solved[TARGET_WORDS] = {false};
    int tries = 0;
    int solved_count = 0;
    
    // Select random target words
    const char* selected_words[TARGET_WORDS] = {NULL};
    for (int i = 0; i < TARGET_WORDS; i++) {
        int idx = rand() % MAX_WORDS; // Inisialisasi nilai awal
        while (checkArray(word_bank[idx], selected_words, i)) {
            idx = rand() % MAX_WORDS; // Generate ulang jika kondisi terpenuhi
        }

        
        copy(target_words[i], word_bank[idx], WORD_LENGTH);
        selected_words[i] = target_words[i];
    }
    
    printf("DEBUG: Target words are: %s %s %s %s\n", 
           target_words[0], target_words[1], target_words[2], target_words[3]);

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
    
    printf("You need to guess 4 different target words using a single word each try.\n");
    printf("You have 9 chances to guess all words correctly.\n");
    printf("Input format: Enter a single 5-letter word\n\n");
    
    // Print initial grid showing 4 target word slots
    for (int i = 0; i < MAX_TRIES; i++) {
        //printf("Try %d: ", i + 1);
        for (int j = 0; j < TARGET_WORDS; j++){
            printf(" - - - - -   ");
        }
        printf("\n");
    }
    
    while (tries < MAX_TRIES && solved_count < TARGET_WORDS) {
        printf("\nAttempt %d/%d\n", tries + 1, MAX_TRIES);
        printf("Enter your guess: ");
        
        if (!read(current_guess)) {
            continue;
        }
        
        printf("\nResults for '%s':\n\n", current_guess);
        
        // Check guess against each target word
        for (int i = 0; i < TARGET_WORDS; i++) {
            if (!word_solved[i]) {
                checkGuess(target_words[i], current_guess, results[tries][i]);
                if (compare(current_guess, target_words[i], WORD_LENGTH)) {
                    word_solved[i] = true;
                    solved_count++;
                }
            } else {
                // Copy previous result for solved words
                copy(results[tries][i], results[tries-1][i], WORD_LENGTH * 3);
            }
        }
        
        // Print current game state
        for (int i = 0; i <= tries; i++) {
            printf("Try %d: ", i + 1);
            for (int j = 0; j < TARGET_WORDS; j++) {
                printf("%s  ", results[i][j]);
            }
            printf("\n");
        }
        
        // Print remaining empty lines
        for (int i = tries + 1; i < MAX_TRIES; i++) {
            printf("Try %d: ", i + 1);
            for (int j = 0; j < TARGET_WORDS; j++) {
                printf(" - - - - -   ");
            }
            printf("\n");
        }
        
        // Print status
        //printf("\nStatus:\n");
        //printf("Words solved: %d/4\n", solved_count);
        for (int i = 0; i < TARGET_WORDS; i++) {
            if (word_solved[i]) {
                printf("Word %d: SOLVED!\n", i + 1);
            } else {
                printf("Word %d: Not solved yet\n", i + 1);
            }

        }
        tries++;
    }
    
    // Game end
    printf("\nGame Over!\n");
    printf("Words solved: %d/4\n", solved_count);
    printf("Attempts used: %d/9\n", tries);
    
    if (solved_count == TARGET_WORDS) {
        printf("Congratulations! You solved all words!\n");
        return 3000;
    } else {
        printf("Better luck next time!\n");
        printf("The target words were: %s %s %s %s\n", 
               target_words[0], target_words[1], target_words[2], target_words[3]);
        return 0;
    }
}
