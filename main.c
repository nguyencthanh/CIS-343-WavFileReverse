// Created by Thanh Nguyen and Hunter Sutton

//Take a file name to read from the command line
//Take a file name to write to from the command line
//Read a .wav and validate it meets our criteria
//Reverse the data section as described above
//Save a new .wav file with the reversed data

#include <stdio.h>
#include <stdlib.h>
#include "file_lib.h"
#include "wav.h"

/* A function used print out all of the important information that is required.*/
void print_information(char* input, char* output, int16_t channel, size_t size, int32_t sample){
    printf("Printing Information\n");
    printf("Input File: %s\n", input);
    printf("Output File: %s\n",output);
    printf("Number of Channels: %d\n", channel);
    printf("Size: %zu\n", size);
    printf("Sample Rate: %d\n", sample);
}

int main(int argc, char** argv){
    size_t size;
    char* file_contents = read_file(argv[1], &size);
    struct wav_header header;
    struct wav_file file;
    file.data = malloc(size);    

    if(file_contents == NULL){
        printf("Error No Contents in File!");
        exit(1);
    }

    header_create(file_contents, header);
    create_wave_file(file_contents, file, size, header);
    create_audio_file(argv[2], file, size);
    print_information(argv[1], argv[2], header.number_channels, size, header.sample_rate);

    free(file.data);
    //free(file_contents);
}

//int main(int argc, char** argv){
    //size_t size;
    //char* contents = read_file(argv[1], &size);
    //if(contents == NULL){
        //printf("sorry yo.\n");
        //exit(1);
    //}
    //char* reversed = malloc(size);
    //size_t count = 0;
    //for(int i=size - 1; i > 0; --i){
        //reversed[count++] = contents[i];
    //}
    //int success = write_file(argv[2], reversed, size);
    //free(contents);
    //free(reversed);
//}