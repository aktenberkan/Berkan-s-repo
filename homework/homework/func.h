#include "library.h"

// Kelime yapýlarýný tanýmladým
struct Word {
    string english;  // Ýngilizce kelime
    string turkish;  // Türkçe anlamý
};

const int MAX_WORDS = 100;  // Maksimum kelime sayýsý
Word dictionary[MAX_WORDS];  // Kelime dizisi
int wordCount = 0;  // Kelime sayaçý

// kelimeleri dosyadan yükleyen fonksiyon
void writeDictionary() {
    ifstream file("dictionary.txt");  // dictionary.txt dosyasýný aç
    string line;
    while (getline(file, line) && wordCount < MAX_WORDS) {  // Dosyadan satýr satýr oku
        size_t pos = line.find(':');  // ':' karakterinin pozisyonunu bul
        if (pos != string::npos) {  // Eðer ':' karakteri bulunursa
            dictionary[wordCount].english = line.substr(0, pos);  // Ýngilizce kelimeyi al
            dictionary[wordCount].turkish = line.substr(pos + 1);  // Türkçe anlamýný al
            wordCount++;  // Kelime sayaçýný artýr
        }
    }
    file.close();  // Dosyayý kapat
}

// kelimeleri dosyaya kaydeden fonksiyon
void saveDictionary() {
    ofstream file("dictionary.txt");  // dictionary.txt dosyasýný aç
    for (int i = 0; i < wordCount; i++) {  // Tüm kelimeleri dosyaya yaz
        file << dictionary[i].english << ":" << dictionary[i].turkish << endl;
    }
    file.close();  // Dosyayý kapat
}

//  kelimeleri listeleyen fonksiyon
void listWords() {
    for (int i = 0; i < wordCount; i++) {  // Tüm kelimeleri ekrana yazdýr
        cout << dictionary[i].english << " : " << dictionary[i].turkish << endl;
    }
}

// Yeni kelime ekleyen fonksiyon
void addNewWord() {

    Word newWord;
    cout << "Enter the English word: ";
    cin >> newWord.english;  // Kullanýcýdan Ýngilizce kelimeyi al
    cout << "Enter the Turkish meaning: ";
    cin >> newWord.turkish;  // Kullanýcýdan Türkçe anlamýný al

    int i;
    for (i = wordCount - 1; i >= 0 && dictionary[i].english > newWord.english; i--) {
        dictionary[i + 1] = dictionary[i];  // Yeni kelimeyi alfabetik sýraya göre yerleþtir
    }
    dictionary[i + 1] = newWord;
    wordCount++;  // Kelime sayaçýný artýr
    saveDictionary();  // kelimeyi dosyaya kaydet
}

// Oyunu baþlatan fonksiyon
void startPlaying() {
    int guess = 0;

    int score = 0; // Baþlangýç puaný

    int mistakes = 0;  // Hata sayýsý
    srand(time(0));  // Rastgele sayý üreticisini baþlat
    bool usedIndices[MAX_WORDS] = { false };  // Kullanýlan indeksleri takip eden dizi

    while (mistakes < 3 || guess = 10) {  // 3 hata veya 10 kelimeye kadar devam et
        int index;
        do {
            index = rand() % wordCount;  // Rastgele bir kelime seç
        } while (usedIndices[index]);  // Daha önce kullanýlmamýþ bir kelime seç

        usedIndices[index] = true;  // Bu kelimeyi kullanýlmýþ olarak iþaretle
        Word word = dictionary[index];
        bool askEnglish = rand() % 2 == 0;  // Rastgele olarak Ýngilizce veya Türkçe sor

        if (askEnglish) {
            cout << "Translate the word: " << word.english << endl;  // Ýngilizce kelimeyi sor
        }
        else {
            cout << "Translate the word: " << word.turkish << endl;  // Türkçe kelimeyi sor
        }

        string options[4];
        options[0] = askEnglish ? word.turkish : word.english;  // Doðru cevabý seçeneklere ekle
        for (int i = 1; i < 4; i++) {
            int randomIndex;
            do {
                randomIndex = rand() % wordCount;  // Rastgele yanlýþ cevaplar seç
            } while (randomIndex == index);
            options[i] = askEnglish ? dictionary[randomIndex].turkish : dictionary[randomIndex].english;
        }

        for (int i = 0; i < 4; i++) {  // Seçenekleri karýþtýr
            int j = rand() % 4;
            string temp = options[i];
            options[i] = options[j];
            options[j] = temp;
        }

        for (int i = 0; i < 4; i++) {  // Seçenekleri ekrana yazdýr
            cout << i + 1 << " - " << options[i] << endl;
        }

        int answer;
        cin >> answer;  // Kullanýcýdan cevabý al
        if (options[answer - 1] == (askEnglish ? word.turkish : word.english)) {
            cout << "Correct!" << endl;  // Doðru cevap
            score += 3;  // Puaný artýr
        }
        else {
            cout << "Wrong! The correct answer was: " << (askEnglish ? word.turkish : word.english) << endl;
            score -= 1;  // Puaný azalt
            mistakes += 1;  // Hata sayýsýný artýr
        }
        guess++; // tahmin sayýsýný artýr
    }

    cout << "Game over! Your score is: " << score << endl;  // Oyunun sonu ve puan
    cout << "1 - Replay The Game" << endl;
    cout << "2 - Previous Menu" << endl;
    cout << "3 - Exit" << endl;

    int choice;
    cin >> choice;
    if (choice == 1) {
        startPlaying();  // Oyunu tekrar baþlat
    }
    else if (choice == 2) {
        return;  // Ana menüye dön
    }
    else {
        exit(0);  // Programý sonlandýr
    }
}
