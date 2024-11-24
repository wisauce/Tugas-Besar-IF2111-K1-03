#include <stdio.h>
#include "queue.h"
#include <stdlib.h>
#include "../mesinkata/mesinkata.h"

void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;

    for (int i = 0; i < QUEUE_MAX_CAPACITY; i++)
    {
        q->buffer[i] = (char *)malloc(QUEUE_ITEM_MAX_LEN * sizeof(char));
    }
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q)
/* Mengirim true jika q kosong: lihat definisi di atas */
{
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(Queue q)
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
{
    return (length(q) == QUEUE_MAX_CAPACITY);
}

int length(Queue q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
{
    if (!isEmpty(q))
    {
        if (IDX_HEAD(q) > IDX_TAIL(q))
        {
            return ((IDX_TAIL(q) + 1) + (QUEUE_MAX_CAPACITY - IDX_HEAD(q)));
        }
        else if (IDX_HEAD(q) <= IDX_TAIL(q))
        {
            return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
        }
    }
    return 0;
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val)
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

{
    if (isEmpty(*q))
    {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else
    {
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % QUEUE_MAX_CAPACITY;
    }

    stringCopy(TAIL(*q), val);
}

void dequeue(Queue *q, ElType *val)
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur"
        q mungkin kosong */
{
    *val = (char *)malloc(QUEUE_ITEM_MAX_LEN * sizeof(char));
    stringCopy(*val, TAIL(*q));
    if (IDX_HEAD(*q) == IDX_TAIL(*q))
    {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
    {
        int i = 0;
        for (i = 0; i < length(*q); i++)
        {
            (*q).buffer[i] = (*q).buffer[i + 1];
        }
        IDX_TAIL(*q)
        --;
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q)
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
{
    int i;

    for (i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
    {
        printf("%d. %s\n", i + 1, q.buffer[i]);
    }
}

int scmp(const char *str1, const char *str2) 
{
    // Iterasi melalui kedua string
    while (*str1 && *str2) 
    {
        if (*str1 != *str2) 
        {
            // Jika karakter tidak cocok, kembalikan perbedaan nilai ASCII
            return (unsigned char)*str1 - (unsigned char)*str2;
        }
        str1++;
        str2++;
    }

    // Jika salah satu string berakhir, kembalikan perbedaan panjang
    return *str1 - *str2;
} 

boolean isIn(Queue q, ElType val)
{
    boolean found = false;
    int i = 0;
    while (!found && i < length(q))
    {
        if (scmp(q.buffer[(q.idxHead + i) % QUEUE_MAX_CAPACITY], val) == 0)
        {
            found = true;
        }
        i++;
    }
    return found;
}
