#include "w0rdl3.h"

const char wordBank[MAX_WORDS][WORD_LENGTH + 1] = {
    "TRULY", "LEAKY", "LUCKY", "SLICK", "BUILD",
    "HEART", "DANCE", "PAUSE", "CROWN", "BEACH"
};

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

void copy(char* dest, const char* src, int length) {
    int i;
    for (i = 0; i < length; i++) {
        dest[i] = src[i];
    }
    dest[length] = '\0';
}

int length(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void checkGuess(const char* target, const char* guess, char* result) {
    int target_count[26] = {0};
    boolean matched_exact[WORD_LENGTH] = {false};
    int i, idx = 0;

    for (i = 0; i < WORD_LENGTH; i++) {
        if (guess[i] != target[i]) {
            target_count[target[i] - 'A']++;
        } else {
            matched_exact[i] = true;
        }
    }

    for (i = 0; i < WORD_LENGTH; i++) {
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

void read(char* buffer) {
    int i = 0;
    START();
    while (!IsEOP() && i < WORD_LENGTH) {
        buffer[i] = upper(GetCC());
        ADV();
        i++;
    }
    buffer[i] = '\0';

    while (!IsEOP()) {
        ADV();
    }
}

int wordl3() {
    srand(time(NULL));
    
    char ans[WORD_LENGTH + 1];
    char guess[WORD_LENGTH + 1];
    char results[MAX_TRIES][WORD_LENGTH * 3 + 1];
    int tries = 0;
    boolean won = false;
    
    copy(ans, wordBank[rand() % MAX_WORDS], WORD_LENGTH);
    printf("DEBUG: Jawaban sebenarnya adalah: %s\n", ans);

    printf("WELCOME TO WORDL3, YOU HAVE 5 CHANCES TO ANSWER BEFORE YOU LOSE!\n\n");
    for (int i = 0; i < MAX_TRIES; i++) {
        printf("- - - - -\n");
    }
    
    while (tries < MAX_TRIES) {
        printf("\nMasukan kata tebakan Anda: ");
        read(guess);
        
        if (length(guess) != WORD_LENGTH) {
            printf("Kata harus terdiri dari 5 huruf!\n");
            continue;
        }
        
        printf("Hasil:\n");
        checkGuess(ans, guess, results[tries]);
        
        for (int j = 0; j <= tries; j++) {
            printf("%s\n", results[j]);
        }
        
        for (int j = tries + 1; j < MAX_TRIES; j++) {
            printf("- - - - -\n");
        }
        
        if (compare(guess, ans, WORD_LENGTH)) {
            printf("\nSelamat, Anda menang!\n");
            won = true;
            return 1500;
        }
        
        tries++;
    }
    
    if (!won) {
        printf("\nBoo! Anda kalah.\n");
    }
    return 0;
}
