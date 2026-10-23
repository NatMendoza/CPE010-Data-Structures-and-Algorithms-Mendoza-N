#ifndef EYDIS_PLAYLIST_H
#define EYDIS_PLAYLIST_H

#include <iostream>
#include <string>

template <typename T>
class SongNode {
    public:
    T data;
    SongNode<T>* next = nullptr;
    SongNode<T>* prev = nullptr;
};


template <typename T>
SongNode<T>* CreateSongNode(T newData) {
    SongNode<T>* newNode = new SongNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

template <typename T>
void playlistInsert(SongNode<T>** head, T newData) {
    SongNode<T>* newNode = CreateSongNode(newData);

    if (*head == nullptr) {
        // First song in the playlist points to itself both ways
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
        return;
    }

    SongNode<T>* tail = (*head)->prev; // in a circular list, head->prev IS the tail

    tail->next = newNode;
    newNode->prev = tail;

    newNode->next = *head;
    (*head)->prev = newNode;
}

template <typename T>
void playlistRemove(SongNode<T>** head, T findData) {
    if (*head == nullptr) {
        std::cout << "The playlist is empty" << std::endl;
        return;
    }

    SongNode<T>* current = *head;
    bool found = false;

    do {
        if (current->data == findData) {
            found = true;
            break;
        }
        current = current->next;
    } while (current != *head);

    if (!found) {
        std::cout << "Song not found in playlist" << std::endl;
        return;
    }

    if (current->next == current) {
        // Only one song in the playlist
        *head = nullptr;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        if (current == *head) {
            *head = current->next;
        }
    }

    delete current;
}

template <typename T>
void playAll(SongNode<T>* head) {
    if (head == nullptr) {
        std::cout << "The playlist is empty" << std::endl;
        return;
    }

    SongNode<T>* current = head;
    do {
        std::cout << current->data << " -> ";
        current = current->next;
    } while (current != head);

    std::cout << "(back to " << head->data << ")" << std::endl;
}

template <typename T>
void nextSong(SongNode<T>** current) {
    if (*current == nullptr) return;
    *current = (*current)->next;
}

template <typename T>
void previousSong(SongNode<T>** current) {
    if (*current == nullptr) return;
    *current = (*current)->prev;
}

#endif
