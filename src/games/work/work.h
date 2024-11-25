#ifndef JOBS_H
#define JOBS_H

#include <stdio.h>

// Definisi struktur Job
typedef struct {
    char name[50];   // Nama pekerjaan
    int income;      // Pendapatan pekerjaan
    int duration;    // Durasi pekerjaan dalam detik
} Job;

extern Job jobList[];

extern const int totalJobs;

#endif // JOBS_H
