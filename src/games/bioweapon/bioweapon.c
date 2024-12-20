#include "../../console.h"
#include "../../art/art.h"

int strLength(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void copy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

char* DNAtoRNA(const char* dna) {
    int len = strLength(dna);
    char* rna = (char*)malloc((len + 1) * sizeof(char));
    
    for (int i = 0; i < len; i++) {
        if (dna[i] == 'A') {
            rna[i] = 'U';
        } else if (dna[i] == 'T') {
            rna[i] = 'A';
        } else if (dna[i] == 'G') {
            rna[i] = 'C';
        } else if (dna[i] == 'C') {
            rna[i] = 'G';
        } else {
            rna[i] = dna[i];
        }
    }
    rna[len] = '\0';
    return rna;
}

char RNAtoProtein(const char* codon) {
    // First letter (U)
    if (codon[0] == 'U') {
        if (codon[1] == 'U') {
            if (codon[2] == 'U' || codon[2] == 'C') return 'F';
            else return 'L';
        }
        else if (codon[1] == 'C') return 'S';
        else if (codon[1] == 'A') {
            if (codon[2] == 'U' || codon[2] == 'C') return 'Y';
            else return '*';
        }
        else if (codon[1] == 'G') {
            if (codon[2] == 'U' || codon[2] == 'C') return 'C';
            else if (codon[2] == 'G') return 'W';
            else return '*';
        }
    }
    // First letter (C)
    else if (codon[0] == 'C') {
        if (codon[1] == 'U') return 'L';
        else if (codon[1] == 'C') return 'P';
        else if (codon[1] == 'A') {
            if (codon[2] == 'U' || codon[2] == 'C') return 'H';
            else return 'Q';
        }
        else if (codon[1] == 'G') return 'R';
    }
    // First letter (A)
    else if (codon[0] == 'A') {
        if (codon[1] == 'U') {
            if (codon[2] == 'G') return 'M';
            else return 'I';
        }
        else if (codon[1] == 'C') return 'T';
        else if (codon[1] == 'A') {
            if (codon[2] == 'U' || codon[2] == 'C') return 'N';
            else return 'K';
        }
        else if (codon[1] == 'G') {
            if (codon[2] == 'U' || codon[2] == 'C') return 'S';
            else return 'R';
        }
    }
    // First letter (G)
    else if (codon[0] == 'G') {
        if (codon[1] == 'U') return 'V';
        else if (codon[1] == 'C') return 'A';
        else if (codon[1] == 'A') {
            if (codon[2] == 'U' || codon[2] == 'C') return 'D';
            else return 'E';
        }
        else if (codon[1] == 'G') return 'G';
    }
    return 'X';
}

int checkCode(const char* protein_sequence, const char* secret_code) {
    int protein_len = strLength(protein_sequence);
    int code_len = strLength(secret_code);

    for (int i = 0; i <= protein_len - code_len; i++) {
        int match = 1;
        for (int j = 0; j < code_len; j++) {
            if (protein_sequence[i + j] != secret_code[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            return 1;
        }
    }
    return 0;
}


void bioweapon() {
    clearterminal();
    artBio();
    char weapon_name[100];
    char dna_seq[100];
    char secret_code[20];
    
    printf("Masukan nama senjata biologis: ");
    STARTWORD();
    int i = 0;
    while (i < currentWord.Length) {
        weapon_name[i] = currentWord.TabWord[i];
        i++;
    }
    weapon_name[i] = '\0';
    printf("Masukan sekuens DNA: ");
    STARTWORD();
    i = 0;
    while (i < currentWord.Length) {
        dna_seq[i] = currentWord.TabWord[i];
        i++;
    }
    dna_seq[i] = '\0';
    printf("Masukan kode rahasia: ");
    STARTWORD();
    i = 0;
    while (i < currentWord.Length) {
        secret_code[i] = currentWord.TabWord[i];
        i++;
    }
    secret_code[i] = '\0';

    char* rna = DNAtoRNA(dna_seq);

    // printf("DEBUG DNA : ");
    for (i = 0; i < strLength(dna_seq); i += 3) {
        if (i + 1 < strLength(dna_seq)) {
            if (i + 2 < strLength(dna_seq)) {
                printf("%c%c%c ", dna_seq[i], dna_seq[i + 1], dna_seq[i + 2]);
            } 
            else {
                printf("%c%c%c ", dna_seq[i], dna_seq[i + 1], ' ');
            }
        } else {
            if (i + 2 < strLength(dna_seq)) {
                printf("%c%c%c ", dna_seq[i], ' ', dna_seq[i + 2]);
            } 
            else {
                printf("%c%c%c ", dna_seq[i], ' ', ' ');
            }
        }
    }
    printf("\n");

    // printf("DEBUG RNA : ");
    for (i = 0; i < strLength(rna); i += 3) {
        if (i + 1 < strLength(rna)) {
            if (i + 2 < strLength(rna)) {
                printf("%c%c%c ", rna[i], rna[i + 1], rna[i + 2]);
            } 
            else {
                printf("%c%c%c ", rna[i], rna[i + 1], ' ');
            }
        } 
        else {
            if (i + 2 < strLength(rna)) {
                printf("%c%c%c ", rna[i], ' ', rna[i + 2]);
            } 
            else {
                printf("%c%c%c ", rna[i], ' ', ' ');
            }
        }
    }
    printf("\n");

    int valid = 0;
    for (int frame = 0; frame < 3 && !valid; frame++) {
        char protein_sequence[100] = "";
        int protein_idx = 0;

        // printf("DEBUG Protein Sequence (Frame %d): ", frame);
        for (i = frame; i < strLength(rna) - 2; i += 3) {
            char codon[4] = {rna[i], rna[i + 1], rna[i + 2], '\0'};
            char aa = RNAtoProtein(codon);
            if (aa != '*') {
                protein_sequence[protein_idx++] = aa;
            }
            if (aa == '*') break;
        }
        protein_sequence[protein_idx] = '\0';
        printf("%s\n", protein_sequence);

        if (checkCode(protein_sequence, secret_code)) {
            // printf("DEBUG: Secret code found in protein sequence: %s\n", protein_sequence);
            valid = 1;
        }
    }

    if (valid) {
        printf("Senjata biologis '%s' mengandung kode, barang akan ditambahkan ke dalam queue!\n", weapon_name);
    } 
    else {
        printf("Kode rahasia tidak ditemukan, maka senjata biologis sudah disabotase, barang ditolak!\n");
    }

    free(rna);
}