#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define max amount of movies, name length and genre length
#define MAX_MOVIES 100
#define MAX_NAME_LENGTH 50
#define MAX_GENRE_LENGTH 20

//define a structure for the movie
typedef struct {
    int code;
    char name[MAX_NAME_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    float rating;
} Movie;


//function prototypes
void insertMovie(Movie movies[], int* count);
void searchMovie(const Movie movies[], int count);
void updateMovie(Movie movies[], int count);
void printMovies(const Movie movies[], int count);


int main() {
    Movie movies[MAX_MOVIES];//array for movies
    int count = 0;//count for movies
    char command;//command for user input
    printf("*********************\n");
    printf("* 2211 Movie Cinema *\n");
    printf("*********************\n");

    do {
        printf("Enter a command (i, s, u, p, q): ");
        scanf(" %c", &command);


        //we use a switch statement to handle all different user inputs
        switch (command) {
            case 'i':
                insertMovie(movies, &count);
                break;
            case 's':
                searchMovie(movies, count);
                break;
            case 'u':
                updateMovie(movies, count);
                break;
            case 'p':
                printMovies(movies, count);
                break;
            case 'q':
                printf("Quitting the program.\n");
                exit(0);
            default:
                printf("Invalid command. Try again.\n");
        }

    } while (1);
    return 0;
}
//to insert movie
void insertMovie(Movie movies[], int* count) {
    if (*count == MAX_MOVIES) {//check if array is full
        printf("Database is full. Cannot insert more movies.\n");
        return;
    }


    int code;
    printf("Enter the movie code: ");
    scanf("%d", &code);


    if (code < 0) {//if code is under 0
        printf("Invalid movie code. Must be greater than or equal to 0.\n");
        return;
    }


    for (int i = 0; i < *count; i++) {//go through all movies and check if the code has been used or not
        if (movies[i].code == code) {
            printf("Movie code already exists. Choose a different code.\n");
            return;
        }
    }


    //Set movie count
    movies[*count].code = code;


    printf("Enter the movie name: ");
    scanf("%s", movies[*count].name);


    printf("Enter the movie genre: ");
    scanf("%s", movies[*count].genre);


    printf("Enter the movie rating (0.0-10.0): ");
    scanf("%f", &movies[*count].rating);


    //check if movie rating is under 10 or over 0
    if (movies[*count].rating < 0.0 || movies[*count].rating > 10.0) {
        printf("Invalid rating. Rating must be between 0.0 and 10.0.\n");
        return;
    }


    (*count)++;
    printf("Movie added successfully.\n");
}


//function to search movie
void searchMovie(const Movie movies[], int count) {
    int code;
    printf("Enter the movie code to search: ");
    scanf("%d", &code);


    //go through array and search for the movie
    for (int i = 0; i < count; i++) {
        if (movies[i].code == code) {
            printf("Movie found:\n");
            printf("Movie Code: %d\n", movies[i].code);
            printf("Movie Name: %s\n", movies[i].name);
            printf("Movie Genre: %s\n", movies[i].genre);
            printf("Movie Rating: %.1f\n", movies[i].rating);
            return;
        }
    }


    printf("Movie not found.\n");
}


//function to update movie
void updateMovie(Movie movies[], int count) {
    int code;
    printf("Enter the movie code to update: ");
    scanf("%d", &code);


    //look through the array and find the movie to update
    for (int i = 0; i < count; i++) {
        if (movies[i].code == code) {
            printf("Enter the updated details for the movie:\n");
            insertMovie(movies, &i);
            printf("Movie updated successfully.\n");
            return;
        }
    }


    printf("Movie not found.\n");
}


//function to print movies
void printMovies(const Movie movies[], int count) {
    printf("Movie Code\tMovie Name\tMovie Genre\tMovie Rating\n");//formatting
    for (int i = 0; i < count; i++) {
        printf("%d\t\t%s\t\t%s\t\t%.1f\n", movies[i].code, movies[i].name, movies[i].genre, movies[i].rating);//formating
    }
}
