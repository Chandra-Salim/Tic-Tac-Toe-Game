#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>

using namespace std;

// Tipe data baru
struct PlayerScore
{
    string nama;
    int win;
    int loss;
};

// Menampilkan board
void drawBoard(char *spaces)
{
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << endl;
    cout << "     |     |     " << endl;
    cout << endl;
}

// Mengeksekusi input user
void playerMove(char *spaces, char player, string nama)
{
    int number;
    do
    {
        cout << nama << "(" << player << "), masukkan spot yang diinginkan (1-9): ";
        cin >> number;
        number--;
        if (number >= 0 && number < 9 && spaces[number] == ' ')
        {
            spaces[number] = player;
            break;
        }
        else
        {
            cout << "Spot tidak valid, coba lagi." << endl;
        }
    } while (true);
}

// Komputer memilih spot secara acak
void computerMove(char *spaces, char computer)
{
    int number;
    srand(time(0));

    while (true)
    {
        number = rand() % 9;
        if (spaces[number] == ' ')
        {
            spaces[number] = computer;
            break;
        }
    }
}

// Mengecek kemenangan kedua player
bool checkWin2Play(char *spaces, char player1, char player2, string nama1, string nama2)
{
    if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2]))
    {
        spaces[0] == player1 ? cout << nama1 << " Menang!!" << endl : cout << nama2 << " Menang!!" << endl;
    }
    else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5]))
    {
        spaces[3] == player1 ? cout << nama1 << " Menang!!" << endl : cout << nama2 << " Menang!!" << endl;
    }
    else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8]))
    {
        spaces[6] == player1 ? cout << nama1 << " Menang!!" << endl : cout << nama2 << " Menang!!" << endl;
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6]))
    {
        spaces[0] == player1 ? cout << nama1 << " Menang!!" << endl : cout << nama2 << " Menang!!" << endl;
    }
    else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7]))
    {
        spaces[1] == player1 ? cout << nama1 << " Menang!!" << endl : cout << nama2 << " Menang!!" << endl;
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8]))
    {
        spaces[2] == player1 ? cout << nama1 << " Menang!!" << endl : cout << nama2 << " Menang!!" << endl;
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8]))
    {
        spaces[0] == player1 ? cout << nama1 << " Menang!!" << endl : cout << nama2 << " Menang!!" << endl;
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6]))
    {
        spaces[2] == player1 ? cout << nama1 << " Menang!!" << endl : cout << nama2 << " Menang!!" << endl;
    }
    else
    {
        return false;
    }
    return true;
}

// Mengecek kemenangan melawan komputer
bool checkWinCom(char *spaces, char player, char computer, string nama)
{
    if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2]))
    {
        spaces[0] == player ? cout << nama << " Menang!!" << endl : cout << nama << " Kalah!!" << endl;
    }
    else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5]))
    {
        spaces[3] == player ? cout << nama << " Menang!!" << endl : cout << nama << " Kalah!!" << endl;
    }
    else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8]))
    {
        spaces[6] == player ? cout << nama << " Menang!!" << endl : cout << nama << " Kalah!!" << endl;
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6]))
    {
        spaces[0] == player ? cout << nama << " Menang!!" << endl : cout << nama << " Kalah!!" << endl;
    }
    else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7]))
    {
        spaces[1] == player ? cout << nama << " Menang!!" << endl : cout << nama << " Kalah!!" << endl;
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8]))
    {
        spaces[2] == player ? cout << nama << " Menang!!" << endl : cout << nama << " Kalah!!" << endl;
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8]))
    {
        spaces[0] == player ? cout << nama << " Menang!!" << endl : cout << nama << " Kalah!!" << endl;
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6]))
    {
        spaces[2] == player ? cout << nama << " Menang!!" << endl : cout << nama << " Kalah!!" << endl;
    }
    else
    {
        return false;
    }
    return true;
}

// Mengecek seri kedua player
bool checkDraw2Play(char *spaces, string nama1, string nama2)
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }
    }
    cout << nama1 << " dan " << nama2 << " Seri!!" << endl;
    return true;
}

// Mengecek seri melawan komputer
bool checkDrawCom(char *spaces)
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }
    }
    cout << "Anda Seri!!" << endl;
    return true;
}

// Menyimpan skor menang dan kalah ke file csv
void saveScoreToFile(PlayerScore player1, PlayerScore player2)
{
    ofstream file("scores.csv", ios::app);
    if (file.is_open())
    {
        file << player1.nama << ", Menang: " << player1.win << ", Kalah: " << player1.loss << endl;
        file << player2.nama << ", Menang: " << player2.win << ", Kalah: " << player2.loss << endl;
        file << endl;
        file.close();
    }
    else
    {
        cout << "Tidak dapat membuka file untuk menyimpan skor" << endl;
    }
}

// Menampilkan skor yang di simpan di file csv
void readScoreFromFile()
{
    ifstream file("scores.csv");
    string line;
    cout << "Skor Sebelumnya:" << endl;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}

// Menghapus semua skor di file csv
void deleteScores()
{
    ofstream ofs("scores.csv", ofstream::out | ofstream::trunc);
    ofs.close();
    cout << "Semua data skor telah dihapus." << endl;
}

int main()
{
    srand(time(0)); // Inisialisasi random number generator
    int pilih;
    char mainLagi;

    do
    {
        cout << "##############################" << endl;
        cout << "Welcome to Tic Tac Toe!" << endl;
        cout << "Bagaimana anda ingin bermain?" << endl;
        cout << "1. Main dengan teman" << endl;
        cout << "2. Main dengan komputer" << endl;
        cout << "3. Lihat skor" << endl;
        cout << "4. Hapus skor" << endl;
        cout << "5. Keluar" << endl;
        cin >> pilih;
        cout << "##############################" << endl;

        if (pilih == 1)
        {
            string nama1, nama2;
            cout << "Player1, masukkan nama anda: ";
            cin >> nama1;
            cout << "Player2, masukkan nama anda: ";
            cin >> nama2;
            cout << "##############################" << endl;

            // Menampilkam nama dan skor awal
            PlayerScore skor1 = {nama1, 0, 0};
            PlayerScore skor2 = {nama2, 0, 0};

            do
            {
                char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
                char player1 = 'X';
                char player2 = 'O';
                bool running = true;
                drawBoard(spaces);

                while (running)
                {
                    playerMove(spaces, player1, nama1);
                    drawBoard(spaces);
                    if (checkWin2Play(spaces, player1, player2, nama1, nama2))
                    {
                        skor1.win++;
                        skor2.loss++;
                        running = false;
                        break;
                    }
                    else if (checkDraw2Play(spaces, nama1, nama2))
                    {
                        running = false;
                        break;
                    }

                    playerMove(spaces, player2, nama2);
                    drawBoard(spaces);
                    if (checkWin2Play(spaces, player1, player2, nama1, nama2))
                    {
                        skor2.win++;
                        skor1.loss++;
                        running = false;
                        break;
                    }
                    else if (checkDraw2Play(spaces, nama1, nama2))
                    {
                        running = false;
                        break;
                    }
                }
                cout << "##############################" << endl;
                cout << "Apakah kalian ingin bermain lagi? (y/n): ";
                cin >> mainLagi;

            } while (mainLagi == 'y' || mainLagi == 'Y');
            saveScoreToFile(skor1, skor2);
        }
        else if (pilih == 2)
        {
            string nama;
            cout << "Player, masukkan nama anda: "; // Input nama player
            cin >> nama;
            cout << "##############################" << endl;

            PlayerScore skor1 = {nama, 0, 0};
            PlayerScore skor2 = {"Komputer", 0, 0};

            do
            {
                char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
                char player = 'X';
                char computer = 'O';
                bool running = true;
                drawBoard(spaces);

                while (running)
                {
                    playerMove(spaces, player, nama);
                    drawBoard(spaces);
                    if (checkWinCom(spaces, player, computer, nama))
                    {
                        skor1.win++;
                        skor2.loss++;
                        running = false;
                        break;
                    }
                    else if (checkDrawCom(spaces))
                    {
                        running = false;
                        break;
                    }

                    computerMove(spaces, computer);
                    drawBoard(spaces);
                    if (checkWinCom(spaces, player, computer, nama))
                    {
                        skor2.win++;
                        skor1.loss++;
                        running = false;
                        break;
                    }
                    else if (checkDrawCom(spaces))
                    {
                        running = false;
                        break;
                    }
                }
                cout << "##############################" << endl;
                cout << "Apakah anda ingin bermain lagi? (y/n): ";
                cin >> mainLagi;
            } while (mainLagi == 'y' || mainLagi == 'Y');
            saveScoreToFile(skor1, skor2);
        }
        else if (pilih == 3)
        {
            readScoreFromFile();
        }
        else if (pilih == 4)
        {
            deleteScores();
        }
        else if (pilih == 5)
        {
            cout << "Terima kasih telah bermain!" << endl;
            cout << "##############################" << endl;
            return 0;
        }
        else
        {
            cout << "Invalid" << endl;
        }
    } while (true);
    return 0;
}