#include<stdio.h>
#include<string.h>
#include "cldi.h"

String genreTable[16] = {
    "Ballad", "Pop Rock", "Pop", "R&B", "Rock", "Country Pop", "J-Pop", "K-Pop",
    "Classical", "Theater", "EDM", "OPM", "Reggae","Dance", "Jazz",  "Indie"
};

//Write your functions here...

// DONE
int allocSpace(VirtualHeap *VH){
    int ret = VH->avail;
    if(ret!=-1){
        VH->avail = VH->H[ret].next;
    }
    return ret;
}

// DONE
void deallocSpace(VirtualHeap *VH, int index){
    VH->H[index].next = VH->avail;
    VH->avail = index;
}

int isSongEqual(Song s1, Song s2){
    return strcmp(s1.songName, s2.songName) == 0 && strcmp(s1.singer, s2.singer) == 0 && strcmp(s1.genre, s2.genre) == 0;
}

// DONE
void insert(VirtualHeap *VH,Song song){
    int pos = hash(song.genre);
    
    if(strcmp(VH->H[pos].elem.genre, "Empty") == 0){
        VH->H[pos].elem = song;
    }
    
    else{
        int newCell = allocSpace(VH);
        if(newCell!=-1){
            VH->H[newCell].elem = song;
            VH->H[newCell].next = -1;
            if(VH->H[pos].next == -1){
                VH->H[pos].next = newCell;
            }
            else{
                int *trav = &pos;
                while(*trav!=-1){
                    trav = &VH->H[*trav].next;
                }
                *trav = newCell;
            }
        }
    }
}

//DONE
void deleteMember(VirtualHeap *VH,Song song){
    int pos = hash(song.genre); //hash
    int *trav = &pos; //assign trav to hash
    
    while(*trav!=-1 && !isSongEqual(VH->H[*trav].elem, song)){
        trav = &VH->H[*trav].next; //traversal
    }
    
    int temp = *trav; //hold trav
    if(temp == pos){
        if(VH->H[temp].next == -1){
            strcpy(VH->H[temp].elem.genre, "Empty");
        }
        else{
            int newCell = VH->H[temp].next;
            VH->H[temp].next = VH->H[newCell].next;
            VH->H[temp].elem = VH->H[newCell].elem;
            deallocSpace(VH, newCell);
        }
    }
    else{
        *trav = VH->H[*trav].next;
        deallocSpace(VH, temp);
    }
    
}

int search(VirtualHeap VH,Song song){
    int pos = hash(song.genre);
    int trav = pos;
    
    while(trav!=-1){
        if(isSongEqual(VH.H[trav].elem, song)){
            return -1;
        }
        trav = VH.H[trav].next;
    }
    
    return 0;
}


// DONE
int hash(String genre){
    for(int i=0; i<16; i++){
        if(strcmp(genre, genreTable[i]) == 0){
            return i;
        }
    }
    
    return -1;
}