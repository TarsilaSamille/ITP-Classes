#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ppmp3.h"

typedef struct pixel{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

typedef struct Imagem{
    unsigned int width;
    unsigned int height;
    unsigned char maximum;
    pixel **pixels;
}Imagem;

pixel** create_pixels(unsigned int width, unsigned int height){
	pixel **pixels = malloc(height * sizeof(pixel*));

	if(pixels == NULL){
		exit(255);
	}

	for(unsigned int i = 0; i < height; i++){
		pixels[i] = malloc(width * sizeof(pixel));

		if(pixels[i] == NULL){
			exit(255);
		}
	}

	return pixels;
}

void load_pixels(Imagem *image, FILE *file){
	for(unsigned int i = 0; i < image->height; i++){
		for(unsigned int j = 0; j < image->width; j++){
			fscanf(file, "%d %d %d", &image->pixels[i][j].r, &image->pixels[i][j].g, &image->pixels[i][j].b);
		}
	}
}

Imagem create_image(unsigned int width, unsigned int height, unsigned char maximum, pixel **pixels){
	Imagem image = malloc(sizeof(image));

	if(image == NULL){
		exit(255);
	}

	image->height = height;
	image->width = width;
	image->maximum = maximum;
	image->pixels = pixels;

	return image;
}

Imagem load_image(char path[]){
	FILE *file = fopen(path, "r");

	if(file == NULL){
		return NULL;
	}

	unsigned int width, height, max;
	char type[3];

	fscanf(file, "%s\n%d %d\n%d", &type, &width, &height, &max);

	if(strcmp(type, "P3") != 0){
		return NULL;
	}

	pixel **pixels = create_pixels(width, height);
	Imagem image = create_image(width, height, max, pixels);

	load_pixels(image, file);
	fclose(file);

	return image;
}

void free_image(Imagem image){
	for(unsigned int i = 0; i < image->height; i++){
		free(image->pixels[i]);
	}

	free(image->pixels);
	free(image);
}

void write_image(Imagem image, char destination[]){
	FILE *file = fopen(destination, "w");

	if(file == NULL){
		return;
	}

	fprintf(file, "P3\n%d %d\n%d\n", image->width, image->height, image->maximum);

	for(unsigned int i = 0; i < image->height; i++){
		for(unsigned int j = 0; j < image->width; j++){
			if(j == image->width - 1){
				fprintf(file, "%d %d %d\n", image->pixels[i][j].r, image->pixels[i][j].g, image->pixels[i][j].b);
			}

			else{
				fprintf(file, "%d %d %d ", image->pixels[i][j].r, image->pixels[i][j].g, image->pixels[i][j].b);
			}
		}
	}
	
	fclose(file);
}
/*
ppmp3_image ppmp3_grayscale(ppmp3_image image){
	pixel **pixels = ppmp3_create_pixels(image->width, image->height);
	ppmp3_image new_image = ppmp3_create_image(image->width, image->height, 0, pixels);
	unsigned char average_gray;

	for(unsigned int i = 0; i < new_image->height; i++){
		for (unsigned int j = 0; j < new_image->width; j++){
			average_gray = (int) (image->pixels[i][j].r * 0.3) + (image->pixels[i][j].g * 0.59) + (image->pixels[i][j].b * 0.11);

			if(average_gray > new_image->maximum){
				new_image->maximum = average_gray;
			}

			new_image->pixels[i][j].r = new_image->pixels[i][j].g = new_image->pixels[i][j].b = average_gray;
		}
	}
	return new_image;
}

ppmp3_image ppmp3_rotate(ppmp3_image image, enum ppmp3_rotation mode){
	pixel **pixels;
	ppmp3_image new_image;

	if(mode == CLOCKWISE || mode == COUNTERCLOCKWISE){
		pixels = ppmp3_create_pixels(image->height, image->width);
		new_image = ppmp3_create_image(image->height, image->width, image->maximum, pixels);

		for (unsigned int i = 0, y; i < new_image->width; i++){
			for (unsigned int j = 0, z; j < new_image->height; j++){

				y = mode == CLOCKWISE ? j : new_image->height - j - 1;
				z = mode == CLOCKWISE ? new_image->width - i - 1 : i;

				new_image->pixels[y][z] = image->pixels[i][j];
			}
		}
	}

	else if(mode == REVERSE){
		pixels = ppmp3_create_pixels(image->width, image->height);
		new_image = ppmp3_create_image(image->width, image->height, image->maximum, pixels);

		for (unsigned int i = 0; i < new_image->height; i++){
			for (unsigned int j = 0; j < new_image->width; j++){
				new_image->pixels[new_image->height - i - 1][new_image->width - j - 1] = image->pixels[i][j];
			}
		}
	}

	else{
		return NULL;
	}

	return new_image;
}

ppmp3_image ppmp3_change_brightness(ppmp3_image image, float percent){
	pixel **pixels = ppmp3_create_pixels(image->width, image->height);
	ppmp3_image new_image = ppmp3_create_image(image->width, image->height, image->maximum, pixels);

	percent = percent/100;

	for (unsigned int i = 0; i < new_image->height; i++){
		for (unsigned int j = 0; j < new_image->width; j++){
			new_image->pixels[i][j].r = (int) image->pixels[i][j].r * percent < 255 ? image->pixels[i][j].r * percent : 255;
			new_image->pixels[i][j].g = (int) image->pixels[i][j].g * percent < 255 ? image->pixels[i][j].g * percent : 255;
			new_image->pixels[i][j].b = (int) image->pixels[i][j].b * percent < 255 ? image->pixels[i][j].b * percent : 255;
		}
	}

	return new_image;
}
*/