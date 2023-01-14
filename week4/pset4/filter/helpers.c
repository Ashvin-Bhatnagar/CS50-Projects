#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int p = 0; p < width; p++)
        {
            int r = image[i][p].rgbtRed;
            int g = image[i][p].rgbtGreen;
            int b = image[i][p].rgbtBlue;
            
            int average = round(((float)r + (float)g + (float)g)/3);
            
            image[i][p].rgbtRed = image[i][p].rgbtGreen = image[i][p].rgbtBlue = average;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
     for (int i = 0; i < height; i++)
    {
        for (int p = 0; p < width; p++)
        {
            int r = image[i][p].rgbtRed;
            int g = image[i][p].rgbtGreen;
            int b = image[i][p].rgbtBlue;
            
            int redSepia = round(0.393 * r + 0.769 * g + 0.189 * b);
            int greenSepia = round(0.349 * r + 0.686 * g + 0.168 * b);
            int blueSepia = round(0.272 * r + 0.534 * g + 0.131 * b);
            
            if (redSepia > 255)
            {
                image[i][p].rgbtRed = 255;
            }
            else
            {
                image[i][p].rgbtRed = redSepia;
            }
            
            if (greenSepia > 255)
            {
                image[i][p].rgbtGreen = 255;
            }
            else
            {
                image[i][p].rgbtGreen = greenSepia;
            }
            
            if (blueSepia > 255)
            {
                image[i][p].rgbtBlue = 255;
            }
            else
            {
                image[i][p].rgbtBlue = blueSepia;
            }
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int p = 0; p < width/2; p++)
        {
            RGBTRIPLE temp = image[i][p];
            image[i][p] = image[i][width - (p + 1)];
            image[i][width - (p + 1)] = temp;
        }
    }
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //creating a temporary image to be blurred
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int p = 0; p < width; p++)
        {
            temp[i][p] = image[i][p];
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int p = 0; p < width; p++)
        {
            int blue_sum;
            int red_sum;
            int green_sum;
            
            float counter;
            blue_sum = green_sum = red_sum = counter = 0;
            
            //CORNERS
            //corner pixel on bottom right
            if (i >= 0 && p >= 0)
            {
                red_sum += temp[i][p].rgbtRed;
                green_sum += temp[i][p].rgbtGreen;
                blue_sum += temp[i][p].rgbtBlue;
                counter++;
            }
            //corner pixel on bottom left
            if (i >= 0 && p - 1 >= 0)
            {
                red_sum += temp[i][p - 1].rgbtRed;
                green_sum += temp[i][p - 1].rgbtGreen;
                blue_sum += temp[i][p - 1].rgbtBlue;
                counter++;
            }
            //corner pixel on top left
            if (i - 1 >= 0 && p >= 0)
            {
                red_sum += temp[i - 1][p].rgbtRed;
                green_sum += temp[i - 1][p].rgbtGreen;
                blue_sum += temp[i - 1][p].rgbtBlue;
                counter++;
            }
            //corner pixel on top right
            if (i - 1 >= 0 && p - 1 >= 0)
            {
                red_sum += temp[i - 1][p - 1].rgbtRed;
                green_sum += temp[i - 1][p - 1].rgbtGreen;
                blue_sum += temp[i - 1][p - 1].rgbtBlue;
                counter++;
            }
            
            //FOUR EDGES
            //pixels on bottom edge
            if ((i >= 0 && p + 1 >= 0) && (i >= 0 && p + 1 < width))
            {
                red_sum += temp[i][p + 1].rgbtRed;
                green_sum += temp[i][p + 1].rgbtGreen;
                blue_sum += temp[i][p + 1].rgbtBlue;
                counter++;
            }
            //pixels on top edge
            if ((i - 1 >= 0 && p + 1 >= 0) && (i - 1 >= 0 && p + 1 < width))
            {
                red_sum += temp[i - 1][p + 1].rgbtRed;
                green_sum += temp[i - 1][p + 1].rgbtGreen;
                blue_sum += temp[i - 1][p + 1].rgbtBlue;
                counter++;
            }
            //pixels on left edge
            if ((i + 1 >= 0 && p >= 0) && (i + 1 < height && p >= 0))
            {
                red_sum += temp[i + 1][p].rgbtRed;
                green_sum += temp[i + 1][p].rgbtGreen;
                blue_sum += temp[i + 1][p].rgbtBlue;
                counter++;
            }
            //pixels on right edge
            if ((i + 1 >= 0 && p - 1 >= 0) && (i + 1 < height && p - 1 >= 0))
            {
                red_sum += temp[i + 1][p - 1].rgbtRed;
                green_sum += temp[i + 1][p - 1].rgbtGreen;
                blue_sum += temp[i + 1][p - 1].rgbtBlue;
                counter++;
            }
            //MIDDLE PIXELS
            if ((i + 1 >= 0 && p + 1 >= 0) && (i + 1 < height && p + 1 < width))
            {
                red_sum += temp[i + 1][p + 1].rgbtRed;
                green_sum += temp[i + 1][p + 1].rgbtGreen;
                blue_sum += temp[i + 1][p + 1].rgbtBlue;
                counter++;
            }
            //find average colour value
            image[i][p].rgbtBlue = round(blue_sum / counter);
            image[i][p].rgbtRed = round(red_sum / counter);
            image[i][p].rgbtGreen = round(green_sum / counter);
        }
    }
    return;
}
