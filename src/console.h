#ifndef CONSOLE_H
#define CONSOLE_H

#include "ADT/boolean.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/arrayuser/arrayuser.h"
#include "ADT/arrayitems/arrayitems.h"
#include "games/w0rdl3/w0rdl3.h"
#include "games/work/work.h"
#include "ADT/queue/queue.h"
#include "games/tebakangka/tebakangka.h"
#include "games/bioweapon/bioweapon.h"
#include "cart/cart.h"
#include "games/quantum_w0rdl3/quantum_w0rdl3.h"
#include "ADT/setkeranjang/set.h"
#include "ADT/stack/stack.h"
#include "art/art.h"
#include "wishlist/wishlist.h"
#include "ADT/linkedlist/linkedlist.h"
#include "profile/profile.h"

void clearterminal();

boolean isAllDigit(char *str);

void parseInput(char *input, char *command, char *parameter1, char *remaining, const char *menuContext);

void mainMenu(ListofItems *itemlist, ListofUsers *userlist, int *currentUserIndex, Queue *q, boolean *returnToLogin, Set *keranjang);

void game_load(ListofItems *itemlist, ListofUsers *userlist, int *currentUserIndex, Queue *q, boolean *returnToLogin, Set *keranjang);

void handleStartMenu(ListofItems *itemlist, ListofUsers *userlist, int *currentUserIndex, Queue *q, boolean *returnToLoginh, Set *keranjang);

void handleLoadMenu(ListofItems *itemlist, ListofUsers *userlist, int *currentUserIndex, Queue *q, boolean *returnToLogin, Stack *historystack, Set *keranjang, List *wishlist, char *filename);

void handleSaveOnExit(ListofItems itemlist, ListofUsers userlist, Word filenameWord);

void mainstartmenu(ListofItems *itemlist, ListofUsers *userlist);

boolean mainloadmenu(char *filename, ListofItems *itemlist, ListofUsers *userlist);

/* Konversi Word ke Integer
 * Mengubah isi Word (kata) menjadi bilangan integer.
 * I.S. : Word terdefinisi
 * F.S. : Mengembalikan bilangan integer hasil konversi Word
 */
int WordtoInteger(Word word);

/* Salin Word ke String
 * Menyalin isi Word (kata) ke dalam array karakter (string).
 * I.S. : Word terdefinisi, str adalah array char yang cukup besar
 * F.S. : str berisi karakter dari Word dengan tambahan null terminator di akhir
 */
void WordToString(Word word, char *str);

/* Bandingkan Dua String
 * Membandingkan dua string secara leksikografis.
 * I.S. : str1 dan str2 terdefinisi, tidak null
 * F.S. : Mengembalikan 0 jika kedua string sama, <0 jika str1 < str2, dan >0 jika str1 > str2
 */
int StringCompare(const char *str1, const char *str2);

/* Salin String
 * Menyalin isi string source ke destination.
 * I.S. : source terdefinisi, destination adalah array char yang cukup besar
 * F.S. : destination berisi salinan dari source
 */
void StringCopy(char *destination, const char *source);

/* Ubah String ke Huruf Kapital
 * Mengubah semua huruf dalam string menjadi huruf kapital.
 * I.S. : str terdefinisi
 * F.S. : Semua karakter huruf kecil dalam str diubah menjadi huruf besar
 */
void Upperstring(char *str);

void Lowerstring(char *str);

/* Fungsi Load
 * Membaca data item dan pengguna dari file ke dalam list item dan list pengguna.
 * I.S. : filename adalah nama file yang berisi data
 * F.S. : List item dan list pengguna terisi sesuai data dalam file
 */
void Load(char *filename, ListofItems *itemlist, ListofUsers *userlist);

/* Fungsi Save
 * Menyimpan data item dan pengguna dari list item dan list pengguna ke file.
 * I.S. : filename adalah nama file tujuan, itemlist dan userlist terdefinisi
 * F.S. : Data dalam itemlist dan userlist disimpan ke file
 */
void Save(char *filename, ListofItems itemlist, ListofUsers userlist);

/* Input Login
 * Membaca input username dan password dari pengguna menggunakan mesin kata.
 * I.S. : sembarang
 * F.S. : username dan password berisi input dari pengguna
 */
void InputLogin(char *username, char *password);

/* Login User
 * Melakukan proses login pengguna.
 * I.S. : userlist berisi daftar pengguna, currentUserIndex sembarang
 * F.S. : Mengembalikan true jika login berhasil, currentUserIndex berisi indeks pengguna yang login
 */
boolean LoginUser(ListofUsers userlist, int *currentUserIndex);

/* Register User
 * Mendaftarkan pengguna baru ke dalam sistem.
 * I.S. : userlist terdefinisi
 * F.S. : Menambahkan pengguna baru ke userlist jika username belum digunakan
 */
void RegisterUser(ListofUsers *userlist);

void performWork(ListofUsers *userlist, int *currentUserIndex);

void StoreList(ListofItems itemlist);

void StoreRemove(ListofItems *itemlist);

void StoreRequest(ListofItems *itemlist, Queue *q);

void StoreSupply(ListofItems *itemlist, Queue *q);

void trimWhitespace(char *str);

void splitNameQuantity(char *input, char *name, int *quantity); 

void History(Stack S, int N);

void CartPay(Set *keranjang, ListofUsers *userlist, int *currentUserIndex, ListofItems *itemlist);

#endif // CONSOLE_H
