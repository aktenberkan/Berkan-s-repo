

#include "library.h"
#include "func.h"

int main() {
    writeDictionary();  // kelimeleri y�kle

    while (true) {
        cout << "1 - Start Playing" << endl;
        cout << "2 - List Words" << endl;
        cout << "3 - Add New Word" << endl;
        cout << "4 - Exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            startPlaying();  // Oyunu ba�lat
        }
        else if (choice == 2) {
            listWords();  // Kelimeleri listele
        }
        else if (choice == 3) {
            addNewWord();  // Yeni kelime ekle
        }
        else if (choice == 4) {
            break;  // Program� sonland�r
        }
        else {
            cout << "Invalid choice. Please try again." << endl;  // Ge�ersiz se�im
        }
    }

    return 0;
}