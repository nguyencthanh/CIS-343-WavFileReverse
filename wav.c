#include <stdio.h>
#include <stdlib.h>
#include "wav.h"
#include "file_lib.h"

/*A function used to create the header data for the WAV file using
  the struct called "wav_header" the was created in "wav.h".*/
void header_create(char* file_contents, struct wav_header header){
    size_t count;

    for(count = 0; count < 44; count++){
        header.header_data[count] = &file_contents[count];
    }
    
}

/*A function used to create the WAV file data for the WAV file using
  the struct called "wav_file" the was created in "wav.h".*/
void create_wave_file(char* file_contents, struct wav_file file, size_t size, struct wav_header header){
    file.size = size;
    
    size_t count = 0;
    int i;
        
    //Populate the file data beginning with the header data.
    for(i = 0; i < 44; i++){
        file.data = header.header_data[i];
    }

    //Populate the rest of the file data with the reversed data
    for(int j = size - 1; j > 45; j--){
        file.data = &file_contents[j];
    }
}

/*A function used to create a new WAV file using already created 
  function called "write_file" in "file_lib".*/
void create_audio_file(char* path, struct wav_file file, size_t size){
    int success = write_file(path, file.data, size);
        if(success == 0){
            printf("Writing Success");
        }
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
