#include "w0rdl3.h"
#include "../../console.h"
#include "../../art/art.h"

const char wordBank[W0RDL3_MAX_WORDS][W0RDL3_WORD_LENGTH + 1] = {
    "TRULY", "LEAKY", "LUCKY", "SLICK", "BUILD",
    "HEART", "DANCE", "PAUSE", "CROWN", "BEACH"
};

char upper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

boolean compare(const char* str1, const char* str2, int length2) {
    int i;
    for (i = 0; i < length2; i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}

void wordl3_copy(char* dest, const char* src, int length2) {
    int i;
    for (i = 0; i < length2; i++) {
        dest[i] = src[i];
    }
    dest[length2] = '\0';
}

int length2(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void checkGuess(const char* target, const char* guess, char* result) {
    int target_count[26] = {0};
    boolean matched_exact[W0RDL3_WORD_LENGTH] = {false};
    int i, idx = 0;

    for (i = 0; i < W0RDL3_WORD_LENGTH; i++) {
        if (guess[i] != target[i]) {
            target_count[target[i] - 'A']++;
        } else {
            matched_exact[i] = true;
        }
    }

    for (i = 0; i < W0RDL3_WORD_LENGTH; i++) {
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
    while (!IsEOP() && i < W0RDL3_WORD_LENGTH) {
        buffer[i] = upper(GetCC());
        ADV();
        i++;
    }
    buffer[i] = '\0';

    while (!IsEOP()) {
        ADV();
    }
}

int w0rdl3(ListofUsers *userlist, int *currentUserIndex) {
    clearterminal();
    artWordl();
    srand(time(NULL));
    
    char ans[W0RDL3_WORD_LENGTH + 1];
    char guess[W0RDL3_WORD_LENGTH + 1];
    char results[W0RDL3_MAX_TRIES][W0RDL3_WORD_LENGTH * 3 + 1];
    int tries = 0;
    boolean won = false;
    
    wordl3_copy(ans, wordBank[rand() % W0RDL3_MAX_WORDS], W0RDL3_WORD_LENGTH);
    // printf("DEBUG: Jawaban sebenarnya adalah: %s\n", ans);

    User *currentUser = &userlist->TI[*currentUserIndex];

    if (currentUser->money < 500) 
    {
        printf("Saldo Anda tidak cukup untuk bermain W0RDL3.\n");
        return 0;
    }

    printf("WELCOME TO WORDL3!\n\n500 COINS HAVE BEEN SPENT TO JOIN THIS CHALLENGE. GO FOR THE WIN!\n\n");
    currentUser->money -= 500;
    printf("YOU HAVE 5 CHANCES TO ANSWER BEFORE YOU LOSE!\n\n");
    for (int i = 0; i < W0RDL3_MAX_TRIES; i++) {
        printf("- - - - -\n");
    }
    
    while (tries < W0RDL3_MAX_TRIES) {
        printf("\nMasukan kata tebakan Anda: ");
        read(guess);
        
        if (length2(guess) != W0RDL3_WORD_LENGTH) {
            printf("Kata harus terdiri dari 5 huruf!\n");
            continue;
        }
        
        printf("Hasil:\n");
        checkGuess(ans, guess, results[tries]);
        
        for (int j = 0; j <= tries; j++) {
            printf("%s\n", results[j]);
        }
        
        for (int j = tries + 1; j < W0RDL3_MAX_TRIES; j++) {
            printf("- - - - -\n");
        }
        
        if (compare(guess, ans, W0RDL3_WORD_LENGTH)) {
            printf("\nSelamat, Anda menang! Anda mendapatkan 3000 coin!\n");
            won = true;
            return 3000;
        }
        
        tries++;
    }
    
    if (!won) {
        printf("\nBoo! Anda kalah.\n");
    }
    return 0;
}