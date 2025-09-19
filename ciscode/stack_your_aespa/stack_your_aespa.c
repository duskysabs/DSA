#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char stageName[50];
} MemberName;

typedef struct {
    MemberName members[4]; // Contains the names of the members
    char agencyName[50];
    int debutYear;
} Artist;

typedef struct {
    char songTitle[50];
    int releaseYear;
} Song;

typedef struct SongNode {
    Song songInfo;
    struct SongNode* nextSong;
} SongNode, *SongStack;

typedef struct {
	Song List[20]; // No need to use this
} SongList;

typedef struct {
    SongStack top; // Representation of Stack in a Linked List implementation
    Artist artistInfo;
} Album;

// Completed Functions
void displayAlbum(Album ae);
Song peekSong(Album *ae);

// PROBLEM 0
Album initializeAlbum();
void populateAlbum(Album *ae);
void pushSong(Album *ae, Song newSong);

// PROBLEM 1
void popSong(Album *ae);
int isEmpty(Album *ae);
SongNode *createNode(Song newSong);

int main(){
	Album aespa;
	Song topSong;
	
	// PROBLEM 0
	// Initialize aespa variable by calling initializeAlbum()
    aespa = initializeAlbum();
	// Populate the album;
    populateAlbum(&aespa);
	// Display the contents of the album
    displayAlbum(aespa);
	// Peek the top song and store it in the topSong variable, then print the top song
    topSong = peekSong(&aespa);
	// Implement your code here...
    printf("Peek (Top Song): %s (%d)\n\n", topSong.songTitle, topSong.releaseYear);

	// PROBLEM 1
	// Call the function popSong 5 times
    popSong(&aespa);
    popSong(&aespa);
    popSong(&aespa);
    popSong(&aespa);
    popSong(&aespa);
	// Display the contents of the album
    displayAlbum(aespa);
	// Peek the top song and store it in the topSong variable, then print the top song
    topSong = peekSong(&aespa);
    printf("Peek (Top Song): %s (%d)\n\n", topSong.songTitle, topSong.releaseYear);
	// Implement your code here...
	return 0;
}

// This function will return an initialized album.
// The default value for the top pointer should be NULL.
// The default values for all strings should be "".
// The default value for debutYear should be 0.
// Then, print a message that you have initialized album.
Album initializeAlbum(){
    Album ae;
    ae.top = NULL;
    printf("Initalized Album.\n");
    return ae;
	// Implement your code here...
}

SongNode *createNode(Song newSong){
    SongNode *newNode = malloc(sizeof(SongNode));
    newNode->nextSong = NULL;
    newNode->songInfo = newSong;
    return newNode;
}

// Populate the album's artistInfo and push all the songs from the library to the album.
// Utilize the initialized aespaInfo and library variable.
// Whether you create variables or not is up to you.
void populateAlbum(Album *ae){
	
	// DO NOT TOUCH 
    Artist aespaInfo = {{{"Karina"}, {"Winter"}, {"Ningning"}, {"Giselle"}}, 
                        "SM Entertainment", 2020};

	// DO NOT TOUCH
    SongList library = {{
    	{"Rich Man", 2025},
        {"Dirty Work", 2025},
        {"Supernova", 2024},
        {"Armageddon", 2024},
        {"Whiplash", 2024},
        {"Drama", 2023},
        {"Better Things", 2023},
        {"Welcome To MY World", 2023},
        {"Spicy", 2023},
        {"Illusion", 2022},
        {"Girls", 2022},
        {"Life's Too Short", 2022},
        {"Savage", 2021},
        {"Next Level", 2021},
        {"Black Mamba", 2020}
    }};
    
    ae->artistInfo = aespaInfo;

	// Implement your code here...
    for(int i=0; library.List[i].releaseYear!=0; i++){
        pushSong(ae, library.List[i]);
    }
}

// This function should return 1 if the album is empty, else it returns 0
int isEmpty(Album *ae){
	// Implement your code here...
	if(ae->top == NULL){
	    return 1;
	}
	else{
	    return 0;
	}
}

// This function will push a song to the album.
void pushSong(Album *ae, Song newSong){
	// Implement your code here...
	SongNode *newNode = createNode(newSong);
	if(isEmpty(ae)){
        ae->top = newNode;
    }
    else{
        newNode->nextSong = ae->top;
        ae->top = newNode;
    }
    printf("Added song to album: %s (%d)\n", newSong.songTitle, newSong.releaseYear);
}

// This function will pop the top song from the album
// It first checks if the album is empty.
// If the album is empty, print error message
// If the album is not empty, pop the top song from the album and print the removed song
void popSong(Album *ae){
	// Implement your code here...
	if(!isEmpty(ae)){
        SongNode *temp = ae->top;
        printf("Removed song: %s (%d)\n", temp->songInfo.songTitle, temp->songInfo.releaseYear);
        ae->top = temp->nextSong;
        free(temp);
    }
    else{
        printf("Error.");
    }
}

// DO NOT TOUCH
Song peekSong(Album *ae){
    Song dummy = {"N/A", 0};
    
    if(!isEmpty(ae)){
        return ae->top->songInfo;
    }
    
    return dummy;
}

// DO NOT TOUCH
void displayAlbum(Album ae){
    SongStack trav;
    int track = 1;

    printf("\n========= Album Info ==========\n");
    printf("Group Name   : %s\n", "Aespa");
    printf("Agency       : %s\n", ae.artistInfo.agencyName);
    printf("Debut Year   : %d\n", ae.artistInfo.debutYear);
    printf("Members      : %s, %s, %s, %s\n",
           ae.artistInfo.members[0].stageName,
           ae.artistInfo.members[1].stageName,
           ae.artistInfo.members[2].stageName,
           ae.artistInfo.members[3].stageName);

    printf("\n========== Tracklist ==========\n");
    printf("%-5s %-20s %-10s\n", "No.", "Song Title", "Year");
    for(trav = ae.top; trav != NULL; trav = trav->nextSong){
        printf("%-5d %-20s %-10d\n", track++, trav->songInfo.songTitle, trav->songInfo.releaseYear);
    }
    printf("===============================\n\n");
}