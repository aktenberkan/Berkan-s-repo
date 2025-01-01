

#include "library.h"
#include "func.h"

int main() {
    writeDictionary();  // kelimeleri yükle

    while (true) {
        cout << "1 - Start Playing" << endl;
        cout << "2 - List Words" << endl;
        cout << "3 - Add New Word" << endl;
        cout << "4 - Exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            startPlaying();  // Oyunu baþlat
        }
        else if (choice == 2) {
            listWords();  // Kelimeleri listele
        }
        else if (choice == 3) {
            addNewWord();  // Yeni kelime ekle
        }
        else if (choice == 4) {
            break;  // Programý sonlandýr
        }
        else {
            cout << "Invalid choice. Please try again." << endl;  // Geçersiz seçim
        }
    }

    return 0;
}