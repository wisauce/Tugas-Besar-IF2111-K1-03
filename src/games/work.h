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
    {"Evil Lab Assistant", 100, 5},
    {"OWCA Hiring Manager", 4200, 5},
    {"Cikapundunginator Caretaker", 7000, 5},
    {"Mewing Specialist", 10000, 5},
    {"Inator Connoisseur", 997, 5}
};

// Jumlah pekerjaan
static const int totalJobs = sizeof(jobList) / sizeof(jobList[0]);

#endif // JOBS_H
