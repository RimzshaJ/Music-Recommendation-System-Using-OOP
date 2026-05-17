#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Playlist; // Forward declaration

class Admin {
public:
    void add_song(string songs[], int &index) {
        if (index >= 30) {
            cout << "Playlist is full, cannot add more songs.\n";
            return;
        }

        cout << "Enter the song name, artist, and duration:\n";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, songs[index]);

        index++;

        cout << "Song added successfully.\n";
    }

    void action() {
        cout << "Admin-specific action.\n";
    }

    friend void resetPlaylist(Playlist &playlist);
};

class Playlist {
protected:
    string songs[30];
    int current_index;

public:
    Playlist() : current_index(21) {

        songs[0] = "Bado_badi by Chaht Fateh (duration: 2min)";
        songs[1] = "Lover by Taylor Swift (duration: 2min)";
        songs[2] = "G.O.A.T by Diljit Dosanjh (duration: 2min)";
        songs[3] = "Baarish by Ash King (duration: 2min)";
        songs[4] = "Isq Risk by Chahet Fateh (duration: 2min)";
        songs[5] = "Cheap Thrills by Taylor Swift (duration: 2min)";
        songs[6] = "Unstoppable by Sia (duration: 3min)";
        songs[7] = "Kar Har Maidan Fateh by Sukhwinder Goshal (duration: 1min)";
        songs[8] = "Let Me Down Slowly by Alec Benjamin (duration: 3min)";
        songs[9] = "Yeh Raatein Yeh Mausam by Kishore Kumar (duration: 2.34min)";
        songs[10] = "Moonrise by Guru Randhawa (duration: 1.67min)";
        songs[11] = "Spain by Thiarajxtt (duration: 2min)";
        songs[12] = "Moonlight by Harnoor (duration: 3.1min)";
        songs[13] = "Baarish by Ash King (duration: 2min)";
        songs[14] = "We Rollin by Shubh (duration: 2min)";
        songs[15] = "Afterhours by Thiarajxtt (duration: 4min)";
        songs[16] = "Mercy by Badshah (duration: 1min)";
        songs[17] = "Blank Space by Taylor Swift (duration: 3min)";
        songs[18] = "Down Bad by Taylor Swift (duration: 2min)";
        songs[19] = "O Yarra by Abdul Hanan (duration: 2.2min)";
        songs[20] = "Attention by Charlie Puth (duration: 2min)";

        for (int i = 21; i < 30; i++) {
            songs[i] = " ";
        }
    }

    void display_all_songs() {

        for (int i = 0; i < current_index; i++) {

            if (songs[i] != " ") {
                cout << "-> " << songs[i] << endl;
            }
        }
    }

    friend void resetPlaylist(Playlist &playlist);
};

// Friend Function
void resetPlaylist(Playlist &playlist) {

    for (int i = 21; i < 30; i++) {
        playlist.songs[i] = " ";
    }

    playlist.current_index = 21;

    cout << "Playlist has been reset successfully.\n";
}

class PatternPrinter {
public:
    void printPattern() {

        for (int i = 0; i < 19; i++) {
            cout << "*";
        }

        cout << endl;
        cout << "****WELCOME****" << endl;

        for (int i = 0; i < 19; i++) {
            cout << "*";
        }

        cout << endl;
    }
};

class Person {
public:
    virtual void action() = 0;
};

class User : public Person {

private:
    string mood;
    string genre;
    string weather;

public:
    User() {
        mood = " ";
        genre = " ";
        weather = " ";
    }

    void action() override {
        cout << "User-specific action.\n";
    }
};

class DisplayUpdate : public Playlist {

public:
    void happy_songs() {

        cout << "\nHappy Songs Playlist:\n";

        for (int i = 0; i <= 4; i++) {
            cout << "-> " << songs[i] << endl;
        }
    }

    void motivation() {

        cout << "\nMotivational Songs Playlist:\n";

        for (int i = 5; i <= 7; i++) {
            cout << "-> " << songs[i] << endl;
        }
    }

    void night() {

        cout << "\nNight Songs Playlist:\n";

        for (int i = 8; i <= 13; i++) {
            cout << "-> " << songs[i] << endl;
        }
    }

    void pop() {

        cout << "\nPop Songs Playlist:\n";

        for (int i = 14; i <= 20; i++) {
            cout << "-> " << songs[i] << endl;
        }
    }

    void display_all_songs() {

        cout << "\nComplete Playlist:\n";

        for (int i = 0; i < current_index; i++) {

            if (songs[i] != " ") {
                cout << "-> " << songs[i] << endl;
            }
        }
    }

    void add_song_to_playlist() {

        Admin admin_obj;

        admin_obj.add_song(songs, current_index);
    }
};

class Login {

private:
    string person;
    string username;

    int psdU;
    int psdA;

public:
    int password;

    Login(string a, string d) {

        person = a;
        username = d;

        psdU = 123;
        psdA = 321;
    }

    void func() {

        bool validLogin = false;

        while (!validLogin) {

            if (person == "user") {

                cout << "\nYour username is: "
                     << username << "_108\n";

                cout << "Your password is 123\n";

                cout << "Now Enter The Provided Password:\n";

                cin >> password;

                if (psdU == password) {

                    cout << "You have successfully logged in as a user.\n";

                    validLogin = true;
                }
                else {

                    cout << "Invalid password. Try again.\n";
                }
            }

            else if (person == "admin") {

                cout << "\nYour username is: "
                     << username << "_admin\n";

                cout << "Your password is 321\n";

                cout << "Now Enter The Provided Password:\n";

                cin >> password;

                if (psdA == password) {

                    cout << "You have successfully logged in as an admin.\n";

                    validLogin = true;
                }
                else {

                    cout << "Invalid password. Try again.\n";
                }
            }

            else {

                cout << "Invalid user type.\n";
                cout << "Please enter either user or admin:\n";

                cin >> person;
            }
        }
    }
};

class A {

    Login a;
    DisplayUpdate objp;

public:

    A(string per, string usnme)
        : a(per, usnme) {}

    void loginfun() {

        a.func();
    }

    void display_playlist(string mood,
                          string genre,
                          string weather) {

        if ((mood == "happy" || mood == "motivated")
            && weather == "sunny"
            && (genre == "comedy" || genre == "desi")) {

            objp.happy_songs();
            objp.motivation();
        }

        else if ((mood == "happy"
                  || mood == "gloomy"
                  || mood == "depressed")

                 && (weather == "rainy"
                     || weather == "windy"
                     || weather == "sunny")

                 && (genre == "comedy"
                     || genre == "fresh finds"
                     || genre == "depressed"
                     || genre == "pop music")) {

            objp.night();
            objp.pop();
        }

        else {

            objp.display_all_songs();
        }
    }

    void add_songs_to_playlist() {

        objp.add_song_to_playlist();
    }

    void display_all_songs() {

        objp.display_all_songs();
    }

    void reset_playlist() {

        resetPlaylist(objp);
    }
};

int main() {

    string per;
    string usnme;

    string weather;
    string mood;
    string genre;

    PatternPrinter printer;

    printer.printPattern();

    cout << "Enter your user type (user/admin):\n";
    cin >> per;

    cout << "Enter your username:\n";
    cin >> usnme;

    A obja(per, usnme);

    obja.loginfun();

    // ADMIN PANEL
    if (per == "admin") {

        int choice;

        do {

            cout << "\n===== ADMIN MENU =====\n";

            cout << "1. Add Songs\n";
            cout << "2. Display All Songs\n";
            cout << "3. Reset Playlist\n";
            cout << "4. Exit\n";

            cout << "Enter your choice:\n";

            cin >> choice;

            switch (choice) {

            case 1:

                obja.add_songs_to_playlist();
                break;

            case 2:

                obja.display_all_songs();
                break;

            case 3:

                obja.reset_playlist();
                break;

            case 4:

                cout << "Exiting Program...\n";
                break;

            default:

                cout << "Invalid choice. Try again.\n";
            }

        } while (choice != 4);
    }

    // USER PANEL
    else if (per == "user") {

        cout << "\nEnter mood (happy, gloomy, depressed, motivated):\n";
        cin >> mood;

        cin.ignore();

        cout << "Enter genre (pop music, desi, comedy, fresh finds):\n";
        getline(cin, genre);

        cout << "Enter weather (sunny, rainy, windy):\n";
        cin >> weather;

        User userobj;

        cout << "\nRecommended Songs:\n";

        obja.display_playlist(mood, genre, weather);
    }

    return 0;
}