#ifndef WAV_H
#define WAV_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* A struct called "wav_header" that contains all of the information require
   for the WAV file header.*/
struct wav_header{
    char* header_data[44];
    int16_t number_channels;
    int32_t sample_rate;
};

/* A struct called "wav_file" that contains all of the information require
   for the WAV file including the pointer to the header, file size,
   and the data.*/
struct wav_file{
    struct wav_header* header;
    size_t size;
    char* data;
};

/* A function where it loads the first 44 bytes of the file's contents
   and creates the header.*/
void header_create(char* file_contents, struct wav_header header);

/* A function where it creates a new wave file by using "read_file" and
   creates a new wave file by taking the returned bytes and then it set
   the header, data size, and pointer to the new wav_file.*/
void create_wave_file(char* file_contents, struct wav_file file, size_t size, struct wav_header header);

/* A function where it will take a "wav_file" and its file path, and it
   will prepare a byte array of the file. It will then call the
   "write_file" function and create a new audio file*/
void create_audio_file(char* path, struct wav_file file, size_t size);

#endif

