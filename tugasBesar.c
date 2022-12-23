#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void printan(char nL[], const char nG[], int tH, int jam, bool meminjam){
    puts("\n>> Order telah masuk system. <<\n");
    puts("[Detail penyewaan]");
    printf("-Nama anda: %s\n", nL);
    printf("-Anda akan menyewa game: %s\n", nG); 
    printf("-Dengan harga: %d selama %d jam\n", tH, jam);
    printf("-Anda akan meminjam gaming gear: %s\n\n", meminjam == 1 ? "Ya" : "Tidak");
}
void main()
{
    const char namaGame[] = "Valorant"; //nama game (string,tidak bisa diubah)
    char namaLengkap[100], voucher[500] = "Voucher yang anda masukkan:", sementara[50], yon; //menyimpan data char
    char arrayPeraturan[4][100] = {"Dilarang merokok diruangan ber-ac.","Dilarang merusak komputer/peralatan.","Dilarang memasuki area warnet dengan baju sekolah.","Dilarang mencari kegaduhan dengan orang lain."};
    int konversi, jam, totalHarga, umur; //untuk menyimpan data jam main dan total harganya
    bool meminjamGaminggir;

    //puts dan printf untuk print output, gets dan scanf untuk mengambil input
    puts("\nSelamat datang di WarnetSimulator");
    printf("List game: %s - 15k - 1jam\n\n", namaGame);

    printf("-Masukkan nama lengkap anda: ");
    gets(namaLengkap); //Mengambil input untuk dimasukkan ke variabel "namaLengkap"
    
    printf("-Masukkan umur anda: ");
    scanf("%d", &umur);
    if(umur < 16){ //kondisi if else, jika umur dibawah 16 maka program akan exit. Sesuai dengan peraturan dari Riot Games.
        printf("Maaf, anda belum cukup umur untuk memainkan game ini :(");
        return;
    }

    printf("-Berapa jam anda meminjam: ");
    scanf("%d", &jam);
    totalHarga = jam * 15000; //operasi perkalian untuk menentukan totalharga

    printf("-Apakah anda akan meminjam gaming gear(mouse, keyboard, headset, mousepad)? (0/1): ");
    scanf("%d", &konversi);
    meminjamGaminggir = konversi; // konversi dari int ke bool

    printf("\n-Apakah anda ingin memasukkan voucher Valorant Points untuk dimasukkan ke akun anda? (Y/N): ");
    while(getchar() != '\n');
    scanf("%c", &yon);
    while(yon == 'y' || yon == 'Y'){
        printf("-Masukkan kode voucher anda: ");
        while(getchar() != '\n');
        gets(sementara);
        strcat(voucher, " ");
        strcat(voucher, sementara);
        printf("-Apakah anda ingin menambahkan kode voucher lagi? (Y/N): ");
        scanf("%c", &yon);
        if(yon == 'y' || yon == 'Y'){
            strcat(voucher, ",");
        }
    }
    printf("\n--- %s\n--- Valorant Points anda akan dimasukkan ke dalam akun anda. ---\n", voucher);
    printan(namaLengkap, namaGame, totalHarga, jam, meminjamGaminggir);
    printf("Peraturan yang perlu dipatuhi: \n");
    for(int i = 0; i <= 3; i++){
        printf("%d.%s\n",i+1,arrayPeraturan[i]);
    }
    printf("\n");
}