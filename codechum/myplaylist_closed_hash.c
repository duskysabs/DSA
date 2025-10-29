#include<stdio.h>
#include<string.h>
#include "cldi.h"

String genreTable[16] = {
    "Ballad", "Pop Rock", "Pop", "R&B", "Rock", "Country Pop", "J-Pop", "K-Pop",
    "Classical", "Theater", "EDM", "OPM", "Reggae","Dance", "Jazz",  "Indie"
};

//Write your functions here...

int allocSpace(VirtualHeap *VH){
    int ret = VH->avail;
    if(ret!=-1){
        VH->avail = VH->H[ret].next;
    }
    return ret;
}
void deallocSpace(VirtualHeap *VH, int index){
    VH->H[index].next = VH->avail;
    VH->avail = index;
}
// void insert(VirtualHeap *VH,Song song){
//     int pos = hash(song.genre);
    
//     if(strcmp(VH->H[pos].elem.genre, "Empty") == 0){
//         VH->H[pos].elem = song;
//         return;
//     }
    
//     else{
//         int newCell = allocSpace(VH);
//         if(newCell!=-1){
//             VH->H[newCell].next = -1;
//             VH->H[newCell].elem = song;
//             if(VH->H[pos].next == -1){
//                 VH->H[pos].next = newCell;
//             }
//             else{
//                 int *trav = &pos;
//                 while(*trav!=-1){
//                     trav = &VH->H[*trav].next;
//                 }
//                 *trav = newCell;
//             }
//         }
//     }
// }
void insert(VirtualHeap *VH,Song song){
    int pos = hash(song.genre);
    
    if(strcmp(VH->H[pos].elem.genre, "Empty") == 0){
        VH->H[pos].elem = song;
        return;
    }
    
    int *trav = &pos;
    
    while(*trav!=-1){
        trav = &VH->H[*trav].next;
    }
    
    int newCell = allocSpace(VH);
    if(newCell!=-1){
        VH->H[newCell].next = -1;
        VH->H[newCell].elem = song;
        *trav = newCell;
    }
}

void deleteMember(VirtualHeap *VH,Song song){
    int pos = hash(song.genre);
    int *trav = &pos;
    
    while(*trav!=-1 && strcmp(VH->H[*trav].elem.songName, song.songName)!=0){
        trav = &VH->H[*trav].next;
    }
    
    int temp = *trav;
    if(temp == pos){
        if(VH->H[temp].next == -1){
            strcpy(VH->H[temp].elem.genre, "Empty");
            return;
        }
        else{
            int newCell = VH->H[temp].next;
            VH->H[temp].next = VH->H[newCell].next;
            VH->H[temp].elem = VH->H[newCell].elem;
            deallocSpace(VH, newCell);
            return;
        }
    }
    
    *trav = VH->H[temp].next;
    deallocSpace(VH, temp);
}

int search(VirtualHeap VH,Song song){
    int pos = hash(song.genre);
    int trav = pos;
    while(trav!=-1){
        if(strcmp(VH.H[trav].elem.songName, song.songName) == 0){
            return 1;
        }
        trav = VH.H[trav].next;
    }
    return 0;
}

int hash(String genre){
    for(int i=0; i<16; i++){
        if(strcmp(genre, genreTable[i]) == 0){
            return i;
        }
    }
}
