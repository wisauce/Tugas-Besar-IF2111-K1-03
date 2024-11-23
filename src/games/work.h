#ifndef JOBS_H
#define JOBS_H

#include <stdio.h>

// Definisi struktur Job
typedef struct {
    char name[50];   // Nama pekerjaan
    int income;      // Pendapatan pekerjaan
    int duration;    // Durasi pekerjaan dalam detik
} Job;

// Deklarasi dan definisi array pekerjaan
static const Job jobList[] = {
    {"Evil Lab Assistant", 1000, 2},
    {"OWCA Hiring Manager", 4200, 3},
    {"Cikapundunginator Caretaker", 7000, 5},
    {"Mewing Specialist", 10000, 10},
    {"Inator Connoisseur", 9997, 8}
};

// Jumlah pekerjaan
static const int totalJobs = sizeof(jobList) / sizeof(jobList[0]);

#endif // JOBS_H
