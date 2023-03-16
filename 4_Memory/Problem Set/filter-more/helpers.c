#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / (3.0));
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float r = 0.0, g = 0.0, b = 0.0, cnt = 0.0;
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int m = j - 1; m <= j + 1; m++)
                {
                    if (k < 0 || k >= height || m < 0 || m >= width)
                    {
                        continue;
                    }
                    r += image[k][m].rgbtRed;
                    g += image[k][m].rgbtGreen;
                    b += image[k][m].rgbtBlue;
                    cnt++;
                }
            }
            copy[i][j].rgbtRed = round(r / cnt);
            copy[i][j].rgbtGreen = round(g / cnt);
            copy[i][j].rgbtBlue = round(b / cnt);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int rx = 0, gx = 0, bx = 0, ry = 0, gy = 0, by = 0;
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int m = j - 1; m <= j + 1; m++)
                {
                    if (k < 0 || k >= height || m < 0 || m >= width)
                    {
                        continue;
                    }
                    rx += image[k][m].rgbtRed * Gx[k - i + 1][m - j + 1];
                    gx += image[k][m].rgbtGreen * Gx[k - i + 1][m - j + 1];
                    bx += image[k][m].rgbtBlue * Gx[k - i + 1][m - j + 1];

                    ry += image[k][m].rgbtRed * Gy[k - i + 1][m - j + 1];
                    gy += image[k][m].rgbtGreen * Gy[k - i + 1][m - j + 1];
                    by += image[k][m].rgbtBlue * Gy[k - i + 1][m - j + 1];
                }
            }
            int r = round(sqrt(rx * rx + ry * ry));
            int g = round(sqrt(gx * gx + gy * gy));
            int b = round(sqrt(bx * bx + by * by));

            copy[i][j].rgbtRed =  r > 255 ? 255 : r;
            copy[i][j].rgbtGreen = g > 255 ? 255 : g;
            copy[i][j].rgbtBlue = b > 255 ? 255 : b;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }

    return;
}
