# SoalShiftSISOP20_modul2_D08

05111840000001 KANA REKHA

05111740000169	MUHAMMAD FARHAN HAYKAL
- [SoalShiftSISOP20_modul2_D08](#soalshiftsisop20modul2d08)
	- [Soal 1](#soal-1)
	- [Soal 2](#soal-2)
		- [Soal a (line 75-79, 133)](#soal-a-line-75-79-133)
		- [Soal b (line 81-84, 86-108)](#soal-b-line-81-84-86-108)
		- [Soal c (line 109-131)](#soal-c-line-109-131)
		- [Soal d(line 56-72)](#soal-dline-56-72)
		- [Soal e(line 18-25, 85)](#soal-eline-18-25-85)
	- [Soal 3](#soal-3)
		- [3A](#3a)
		- [3B](#3b)
		- [3C](#3c)
		- [3D](#3d)
## Soal 1 
```
Buatlah program C yang menyerupai crontab untuk menjalankan script bash dengan
ketentuan sebagai berikut:
a. Program menerima 4 argumen berupa:
i. Detik: 0-59 atau * (any value)
ii. Menit: 0-59 atau * (any value)
iii. Jam: 0-23 atau * (any value)
iv. Path file .sh
b. Program akan mengeluarkan pesan error jika argumen yang diberikan tidak
sesuai
c. Program hanya menerima 1 config cron
d. Program berjalan di background (daemon)
e. Tidak boleh menggunakan fungsi system()
Contoh: ./program \* 34 7 /home/somi/test.sh
Program dengan argumen seperti contoh di atas akan menjalankan script test.sh setiap
detik pada jam 07:34.
```
* Pertama saya membuat proses untuk menjalankan exec bash seperti di modul (line 15-28)
* Lalu saya membuat fungsi untuk mengecek argumennya, argumen hanya boleh ada 5
* If selanjutnya ngecek detiknya (line 33-43)
* If selanjutnya ngecek menitnya (line 44-54)
* If selanjutnya ngecek jamnya (line 55-65)
* Lalu jika argumennya salah maka keluar "Argumen salah!"
* Pada line 73-109 ada penjelasannya di modul 2 bedanya pada line 75-79, ada pengecekan file apakah ada (Revisi sebelumnya tidak ada)
*  Lalu di dalam while ada pengecekan local time dengan argumen yang sudah dibuat, jika benar semua maka lakukan program .sh pada argumen
  
## Soal 2 
```
Shisoppu mantappu! itulah yang selalu dikatakan Kiwa setiap hari karena sekarang dia
merasa sudah jago materi sisop. Karena merasa jago, suatu hari Kiwa iseng membuat
sebuah program.
a. Pertama-tama, Kiwa membuat sebuah folder khusus, di dalamnya dia membuat
sebuah program C yang per 30 detik membuat sebuah folder dengan nama
timestamp [YYYY-mm-dd_HH:ii:ss].
b. Tiap-tiap folder lalu diisi dengan 20 gambar yang di download dari
https://picsum.photos/, dimana tiap gambar di download setiap 5 detik. Tiap
gambar berbentuk persegi dengan ukuran (t%1000)+100 piksel dimana t adalah

detik Epoch Unix. Gambar tersebut diberi nama dengan format timestamp [YYYY-
mm-dd_HH:ii:ss].

c. Agar rapi, setelah sebuah folder telah terisi oleh 20 gambar, folder akan di zip dan
folder akan di delete(sehingga hanya menyisakan .zip).

d. Karena takut program tersebut lepas kendali, Kiwa ingin program tersebut men-
generate sebuah program "killer" yang siap di run(executable) untuk

menterminasi semua operasi program tersebut. Setelah di run, program yang
menterminasi ini lalu akan mendelete dirinya sendiri.
e. Kiwa menambahkan bahwa program utama bisa dirun dalam dua mode, yaitu
MODE_A dan MODE_B. untuk mengaktifkan MODE_A, program harus dijalankan
dengan argumen -a. Untuk MODE_B, program harus dijalankan dengan argumen
-b. Ketika dijalankan dalam MODE_A, program utama akan langsung
menghentikan semua operasinya ketika program killer dijalankan. Untuk
MODE_B, ketika program killer dijalankan, program utama akan berhenti tapi
membiarkan proses di setiap folder yang masih berjalan sampai selesai(semua
folder terisi gambar, terzip lalu di delete).
Kiwa lalu terbangun dan sedih karena menyadari programnya hanya sebuah mimpi.
Buatlah program dalam mimpi Kiwa jadi nyata!
Catatan:
- Tidak boleh memakai system().
- Program utama harus ter-detach dari terminal
Hint:
- Gunakan fitur picsum.photos untuk mendapatkan gambar dengan ukuran
tertentu
- Epoch Unix bisa didapatkan dari time()
```
### Soal a (line 75-79, 133)
* Pertama membuat char dirname untuk nama foldernya
* Lalu ambil local time sekarang agar dapat digunakan nama foldernya
* Masukkan nama foldernya di line 78 lalu buat file yang bernama timestamp(dirname)
* Agar selalu jalan setiap 30 detik maka pada line 133 disleep 30 detik
### Soal b (line 81-84, 86-108)
* Pertama saya ngefork dulu agar jalan setelah foldernya sudah dibuat
* Lalu pada line 91-94 tidak beda jauh dengan soal a, hanya tempat meletakkan nama filenya
* Pada line 95, saya membuat variable "nanti" berisi tempat yang akan di-wget dengan ketentuan (t%1000)+100 seperti di soal
* Lalu pada line 96, mengisi variable "filename" dengan timestamp sekarang
* Pada line 97-100, saya membuat char "jadi" agar dapat dimasukkan ke wget letak dan nama file yang di-wget
* Pada line 101-104, saya membuat wget dengan folder & nama file di variabel "jadi" dan variable "nanti" untuk tempat wget-nya
* Pada line 105 cnt akan bertambah terus hingga while line 88 selesai
* Pada line 106 proses semua ini disleep selama 5 detik

### Soal c (line 109-131)
* Pada line 109 proses ini menunggu agar soal b selesai terlebih dahulu
* Pada line 110-111 membuat fork
* Lalu pada line 112-120 tidak beda jauh dengan sebelumnya hanya beda di zip saja
* Lalu di pada line 122-131 sama saja juga hanya beda di rm nya (revisi karena salah menaruh child_id nya)

### Soal d(line 56-72) (Revisi karena masih gagal)
* Pertama pada line 56 buat file killer.c
* Lalu dalamnya berisi kill current pid terus diremove file killernya
* Lalu sisanya ga beda jauh dengan soal sebelumnya hanya di gcc nya untuk mengcompile file killer
* Setelah itu remove killer.c nya
### Soal e(line 18-25, 85) (Revisi karena belum mengerjakan)
* Pertama saya ingin membedakan mode a dan mode b
* Lalu jika mode a maka mode = 0, mode b maka mode= 1. Selain itu keluar "Argumen Salah"
* Lalu pada line 85, saya mengubah kalau proses wget dan seterusnya berbeda dengan membuat direktori

## Soal 3 
  ```
Jaya adalah seorang programmer handal mahasiswa informatika. Suatu hari dia
memperoleh tugas yang banyak dan berbeda tetapi harus dikerjakan secara bersamaan
(multiprocessing).
a. Program buatan jaya harus bisa membuat dua direktori di
“/home/[USER]/modul2/”. Direktori yang pertama diberi nama “indomie”, lalu
lima detik kemudian membuat direktori yang kedua bernama “sedaap”.
b. Kemudian program tersebut harus meng-ekstrak file jpg.zip di direktori
“/home/[USER]/modul2/”. Setelah tugas sebelumnya selesai, ternyata tidak
hanya itu tugasnya.
c. Diberilah tugas baru yaitu setelah di ekstrak, hasil dari ekstrakan tersebut (di
dalam direktori “home/[USER]/modul2/jpg/”) harus dipindahkan sesuai dengan
pengelompokan, semua file harus dipindahkan ke
“/home/[USER]/modul2/sedaap/” dan semua direktori harus dipindahkan ke
“/home/[USER]/modul2/indomie/”.
d. Untuk setiap direktori yang dipindahkan ke “/home/[USER]/modul2/indomie/”
harus membuat dua file kosong. File yang pertama diberi nama “coba1.txt”, lalu
3 detik kemudian membuat file bernama “coba2.txt”.
(contoh : “/home/[USER]/modul2/indomie/{nama_folder}/coba1.txt”).
Karena Jaya terlalu banyak tugas dia jadi stress, jadi bantulah Jaya agar bisa membuat
program tersebut.
Catatan :
- Tidak boleh memakai system().
- Tidak boleh memakai function C mkdir() ataupun rename().
- Gunakan exec dan fork
- Direktori “.” dan “..” tidak termasuk 
```

### 3A
-Pertama membuat proses anak dengan mendeklarasikan child_id dan child_id1 .Saat child_id kurang dari nol maka proses gagal dibuat.Jika child_id sama dengan nol maka akan membuat proses anak .Kemdian didalamnya akan membuat proses anak lagi untuk memproses pembuatan direktori indomie dan sedap.

![awal](https://user-images.githubusercontent.com/57948206/76605117-7eee1300-6542-11ea-9225-6a163cd553b5.png)

-Saat child_id1 sama dengan nol makan akan membuat direktori indomie

![child1](https://user-images.githubusercontent.com/57948206/76604705-c88a2e00-6541-11ea-94c5-3697b66e1c8d.png)

-Kemudian akan masuk ke else dan menunggu selema 5 detik yang ditandai dengan sleep(5) untuk membuat direktori sedaap

![chil1](https://user-images.githubusercontent.com/57948206/76605122-801f4000-6542-11ea-89b2-2b1ff7a0460b.png)

### 3B
-Kemudian melakukan unzip file jpg.zip degan fungsi execv

![else](https://user-images.githubusercontent.com/57948206/76605126-81506d00-6542-11ea-8251-62ce5987a5d3.png)

### 3C
![1](https://user-images.githubusercontent.com/57948206/77226505-839e7100-6bab-11ea-9024-1f6e52cd5e64.png)

-Untuk menjalankan proses tersebut harus menunggu status lebih dari nol , kemudian membuat proses anak lagi menggunakan fork

-Saat child_id sama dengan nol makan proses pemindahan file ke direktori sedap akan berjalan

-"find", "/home/rekha/modul2/jpg/"  artinya mencari direktori jpg

-"-mindepth", "1", "-maxdepth", "1" menandakan bahwa proses masuk ke dalam direktori tujuan sejumlah satu kali saja dan tidak akan mencari ke subdirektori didalam jpg

-"-type", "f" artinya mencari isi dari direktori hanya bertipe file

-mv artinya memindahkan isi file yg di cari

-"-t", "/home/rekha/modul2/sedaap" artinya merunjuk ke file mana yang akan dipindah dan akan dipindah ke direktori sedaap

![2](https://user-images.githubusercontent.com/57948206/77226508-8600cb00-6bab-11ea-96b9-2236e3fa834d.png)

-Penjelasan dari gambar diatas sama seperti sebelumnya.Yang membedakan adalah "-type", "d" yaitu mencari isi dari direktori jpg dengan tipe direktori

### 3D
![5](https://user-images.githubusercontent.com/57948206/77226957-bb5ae800-6bae-11ea-8356-8bdd4505fb09.png)

-Untuk menjalankan proses selanjutnya harus menunggu saat status lebih dari nol , kemudian membuat proses anak.

-find", "/home/rekha/modul2/indomie/" mencari direktori indomie

-"-mindepth", "1", "-maxdepth", "1" menandakan bahwa proses masuk ke dalam direktori tujuan sejumlah satu kali saja dan tidak akan mencari ke subdirektori didalam indomie

-"-type", "d" artinya mencari yang bertipe direktori

-"touch", "{}/coba1.txt" artinya membuat file baru dengan nama coba1.txt

-kemudian menunggu selema 3 detik yang ditandai dengan "sleep(3)" untuk membuat file baru dengan nama coba2.txt didalam direkroti indomie.





