#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"
#include "../../console.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin()
{
	
	ArrayDin Array;
	Array.A = (ElType*) malloc (sizeof(ElType)*InitialSize);
	Array.Capacity = InitialSize;
	Array.Neff = 0;
	return Array;

}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array)
{
	free(array->A);
	array->Neff = 0;
	array->Capacity = 0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array)
{
	return (array.Neff == 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array)
{
	return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i)
{
	return(array.A[i]);
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array)
{
	return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i)
{
    if (array->Neff == array->Capacity)
    {
        array->Capacity *= 2;
        array->A = (ElType *) realloc (array->A, array->Capacity * sizeof(ElType));
    }
    IdxType temp = array->Neff;
    while (temp > i)
    {
        array->A[temp] = array->A[temp - 1];
        temp--;
    }
    array->A[i] = el;
    array->Neff++;
}

void InsertLast(ArrayDin *array, ElType el)
{
    InsertAt(array, el, array->Neff);
}

void InsertFirst(ArrayDin *array, ElType el)
{
    InsertAt(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i)
{
    int j ;
    for(j = i ; j <= (array->Neff)-1 ; j++)
        {
            array->A[j] = array->A[j+1];
        }
    array->Neff--;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ArrayDin *array)
{
	int deleteAt = Length(*array)-1;
	DeleteAt(array,deleteAt);
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayDin *array)
{
	int j;
	for (j = 0 ; j < array->Neff ; j++)
	{
		array->A[j] = array->A[j+1]; 
	}
	array->Neff -= 1;
}

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin(ArrayDin array)
{
    if (array.Neff == 0)
    {
        printf("[]\n");
    }
    else
    {
        IdxType i;
        printf("[");
        for (i = 0; i < array.Neff - 1; i++)
        {
            printf("%s, ", array.A[i]);
        }
        printf("%s]\n", array.A[array.Neff - 1]);
    }
}
/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin(ArrayDin *array)
{
	ArrayDin Temp;
	Temp = CopyArrayDin(*array);
	
	int i;
	for (i = 0 ; i < array->Neff ; i++)
	{
		array->A[i] = Temp.A[(array->Neff)-1-i];
	}
	DeallocateArrayDin(&Temp);
}
/**
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
ArrayDin CopyArrayDin(ArrayDin array)
{
	ArrayDin copy = MakeArrayDin();
	int i;
	for (i = 0; i < array.Neff; i++) 
	{
		InsertLast(&copy, array.A[i]);
	}
	copy.Capacity = array.Capacity;
	copy.Neff = array.Neff;
	return copy;
}
/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
IdxType SearchArrayDin(ArrayDin array, ElType el)
{
	int i;
	Upperstring(el);
	for (i = 0 ; i < array.Neff ; i++)
	{
		Upperstring(array.A[i]);
		if (StringCompare(array.A[i], el) == true)
		{
			return i;
		}
	}
	return -1;
}


boolean IsMemberArray (ArrayDin array, ElType el)
{
	return (SearchArrayDin(array, el) != -1);
}
