#include <iostream>
#include <string>
#include <limits>
#include "eydis_playlist.h"

/* FUNCTION DECLARATION AREA*/
void clearScreen(); // CLEARING TERMINAL 

void pauseThenClear(); // FOR PROCEEDING THE NEXT STEP

void printMenu(const std::string& nowPlayingLabel); // MENU PRINTING

int main() {
    SongNode<std::string>* playlist = nullptr;
    SongNode<std::string>* nowPlaying = nullptr;

    int choice = 0;

    do {
        std::string nowPlayingLabel = (nowPlaying == nullptr) ? "(none)" : nowPlaying->data;

        printMenu(nowPlayingLabel);
        std::cin >> choice;

        // Discard the leftover newline so getline works cleanly next
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::cout << "Enter the song name to add: ";
                std::string songName;
                std::getline(std::cin, songName);

                playlistInsert(&playlist, songName);

                // If this was the first song added, it becomes "now playing"
                if (nowPlaying == nullptr) {
                    nowPlaying = playlist;
                }

                std::cout << "\nAdded \"" << songName << "\" to the playlist." << std::endl;
                playAll(playlist);
                break;
            }

            case 2: {
                std::cout << "Enter the song name to remove: ";
                std::string songName;
                std::getline(std::cin, songName);

                // If we're about to delete the song that's "now playing",
                // move now-playing off of it first
                if (nowPlaying != nullptr && nowPlaying->data == songName) {
                    nowPlaying = (nowPlaying->next != nowPlaying) ? nowPlaying->next : nullptr;
                }

                playlistRemove(&playlist, songName);

                if (playlist == nullptr) {
                    nowPlaying = nullptr;
                }

                std::cout << "\nUpdated playlist:" << std::endl;
                playAll(playlist);
                break;
            }

            case 3: {
                std::cout << "\nFull playlist:" << std::endl;
                playAll(playlist);
                break;
            }

            case 4: {
                if (nowPlaying == nullptr) {
                    std::cout << "\nPlaylist is empty - nothing to play." << std::endl;
                } else {
                    nextSong(&nowPlaying);
                    std::cout << "\nSkipped forward. Now playing: " << nowPlaying->data << std::endl;
                }
                break;
            }

            case 5: {
                if (nowPlaying == nullptr) {
                    std::cout << "\nPlaylist is empty - nothing to play." << std::endl;
                } else {
                    previousSong(&nowPlaying);
                    std::cout << "\nWent back. Now playing: " << nowPlaying->data << std::endl;
                }
                break;
            }

            case 6: {
                std::cout << "\nExiting playlist. Goodbye!" << std::endl;
                break;
            }

            default: {
                std::cout << "\nInvalid choice, please pick 1-6." << std::endl;
                break;
            }
        }

        if (choice != 6) {
            pauseThenClear();
        }

    } while (choice != 6);

    return 0;
}

/* FUNCTION DECLARATION AREA */

void clearScreen() { // CLEARNING TERMINAL FOR GOOD OUTPUT I GUESS?
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseThenClear() {
    std::cout << "\nPress ENTER to continue...";
    std::cin.get();
    clearScreen();
}

void printMenu(const std::string& nowPlayingLabel) {
    std::cout << "===== SONG PLAYLIST =====" << std::endl;
    std::cout << "Now playing: " << nowPlayingLabel << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "1. Add a song" << std::endl;
    std::cout << "2. Remove a song" << std::endl;
    std::cout << "3. Play all (show full playlist)" << std::endl;
    std::cout << "4. Next song" << std::endl;
    std::cout << "5. Previous song" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Choice: ";
}