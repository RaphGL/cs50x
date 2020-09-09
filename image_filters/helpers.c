#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avr;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avr = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
            image[i][j].rgbtBlue = avr;
            image[i][j].rgbtGreen = avr;
            image[i][j].rgbtRed = avr;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            tmp = image[i][j];
            image[i][j] = image[i][width - j];
            image[i][width - j] = tmp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sum_red;
    int sum_blue;
    int sum_green;
    RGBTRIPLE tmp[height][width];
    float counter;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            sum_blue = 0;
            sum_red = 0;
            sum_green = 0;
            counter = 0;
            for (int y = -1; y <= 1; y++)
            {
                for (int x = -1; x <= 1; x++)
                {
                    int row = y + h;
                    int col = x + w;
                    if (row < 0 || row >= height || col < 0 || col >= width) continue;
                    sum_blue += image[row][col].rgbtBlue;
                    sum_red += image[row][col].rgbtRed;
                    sum_green += image[row][col].rgbtGreen;
                    counter++;
                }
            }
            tmp[h][w].rgbtBlue = round(sum_blue / counter);
            tmp[h][w].rgbtRed = round(sum_red / counter);
            tmp[h][w].rgbtGreen = round(sum_green / counter);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
