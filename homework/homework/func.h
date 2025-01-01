#include "library.h"

// Kelime yap�lar�n� tan�mlad�m
struct Word {
    string english;  // �ngilizce kelime
    string turkish;  // T�rk�e anlam�
};

const int MAX_WORDS = 100;  // Maksimum kelime say�s�
Word dictionary[MAX_WORDS];  // Kelime dizisi
int wordCount = 0;  // Kelime saya��

// kelimeleri dosyadan y�kleyen fonksiyon
void writeDictionary() {
    ifstream file("dictionary.txt");  // dictionary.txt dosyas�n� a�
    string line;
    while (getline(file, line) && wordCount < MAX_WORDS) {  // Dosyadan sat�r sat�r oku
        size_t pos = line.find(':');  // ':' karakterinin pozisyonunu bul
        if (pos != string::npos) {  // E�er ':' karakteri bulunursa
            dictionary[wordCount].english = line.substr(0, pos);  // �ngilizce kelimeyi al
            dictionary[wordCount].turkish = line.substr(pos + 1);  // T�rk�e anlam�n� al
            wordCount++;  // Kelime saya��n� art�r
        }
    }
    file.close();  // Dosyay� kapat
}

// kelimeleri dosyaya kaydeden fonksiyon
void saveDictionary() {
    ofstream file("dictionary.txt");  // dictionary.txt dosyas�n� a�
    for (int i = 0; i < wordCount; i++) {  // T�m kelimeleri dosyaya yaz
        file << dictionary[i].english << ":" << dictionary[i].turkish << endl;
    }
    file.close();  // Dosyay� kapat
}

//  kelimeleri listeleyen fonksiyon
void listWords() {
    for (int i = 0; i < wordCount; i++) {  // T�m kelimeleri ekrana yazd�r
        cout << dictionary[i].english << " : " << dictionary[i].turkish << endl;
    }
}

// Yeni kelime ekleyen fonksiyon
void addNewWord() {

    Word newWord;
    cout << "Enter the English word: ";
    cin >> newWord.english;  // Kullan�c�dan �ngilizce kelimeyi al
    cout << "Enter the Turkish meaning: ";
    cin >> newWord.turkish;  // Kullan�c�dan T�rk�e anlam�n� al

    int i;
    for (i = wordCount - 1; i >= 0 && dictionary[i].english > newWord.english; i--) {
        dictionary[i + 1] = dictionary[i];  // Yeni kelimeyi alfabetik s�raya g�re yerle�tir
    }
    dictionary[i + 1] = newWord;
    wordCount++;  // Kelime saya��n� art�r
    saveDictionary();  // kelimeyi dosyaya kaydet
}

// Oyunu ba�latan fonksiyon
void startPlaying() {
    int guess = 0;

    int score = 0; // Ba�lang�� puan�

    int mistakes = 0;  // Hata say�s�
    srand(time(0));  // Rastgele say� �reticisini ba�lat
    bool usedIndices[MAX_WORDS] = { false };  // Kullan�lan indeksleri takip eden dizi

    while (mistakes < 3 || guess = 10) {  // 3 hata veya 10 kelimeye kadar devam et
        int index;
        do {
            index = rand() % wordCount;  // Rastgele bir kelime se�
        } while (usedIndices[index]);  // Daha �nce kullan�lmam�� bir kelime se�

        usedIndices[index] = true;  // Bu kelimeyi kullan�lm�� olarak i�aretle
        Word word = dictionary[index];
        bool askEnglish = rand() % 2 == 0;  // Rastgele olarak �ngilizce veya T�rk�e sor

        if (askEnglish) {
            cout << "Translate the word: " << word.english << endl;  // �ngilizce kelimeyi sor
        }
        else {
            cout << "Translate the word: " << word.turkish << endl;  // T�rk�e kelimeyi sor
        }

        string options[4];
        options[0] = askEnglish ? word.turkish : word.english;  // Do�ru cevab� se�eneklere ekle
        for (int i = 1; i < 4; i++) {
            int randomIndex;
            do {
                randomIndex = rand() % wordCount;  // Rastgele yanl�� cevaplar se�
            } while (randomIndex == index);
            options[i] = askEnglish ? dictionary[randomIndex].turkish : dictionary[randomIndex].english;
        }

        for (int i = 0; i < 4; i++) {  // Se�enekleri kar��t�r
            int j = rand() % 4;
            string temp = options[i];
            options[i] = options[j];
            options[j] = temp;
        }

        for (int i = 0; i < 4; i++) {  // Se�enekleri ekrana yazd�r
            cout << i + 1 << " - " << options[i] << endl;
        }

        int answer;
        cin >> answer;  // Kullan�c�dan cevab� al
        if (options[answer - 1] == (askEnglish ? word.turkish : word.english)) {
            cout << "Correct!" << endl;  // Do�ru cevap
            score += 3;  // Puan� art�r
        }
        else {
            cout << "Wrong! The correct answer was: " << (askEnglish ? word.turkish : word.english) << endl;
            score -= 1;  // Puan� azalt
            mistakes += 1;  // Hata say�s�n� art�r
        }
        guess++; // tahmin say�s�n� art�r
    }

    cout << "Game over! Your score is: " << score << endl;  // Oyunun sonu ve puan
    cout << "1 - Replay The Game" << endl;
    cout << "2 - Previous Menu" << endl;
    cout << "3 - Exit" << endl;

    int choice;
    cin >> choice;
    if (choice == 1) {
        startPlaying();  // Oyunu tekrar ba�lat
    }
    else if (choice == 2) {
        return;  // Ana men�ye d�n
    }
    else {
        exit(0);  // Program� sonland�r
    }
}
