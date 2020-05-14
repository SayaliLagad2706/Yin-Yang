#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>
#include "PGMImage.h"
using namespace std;

void error(const char *err)
{
    cerr << err << endl;
    exit(1);
} // error

array2D :: array2D(int xResolution, int yResolution)
{
    if(xResolution < 0 || yResolution < 0)
        error("Bad dimensions");

    xRes = xResolution;
    yRes = yResolution;
    xtable = new float*[yRes]; // a ("column") array to hold 'float *' type pointers
    if(xtable == nullptr)
        error("Out of memory");

    // each element of the above array points to a 'row' of xRes elements
    for(int i=0; i < yRes; i++)
    {
        xtable[i] = new float[xRes];
        if(xtable[i] == nullptr)
            error("Out of memory");
    }

    for(int i = 0; i < yRes; i++)
    {
        for(int j = 0; j < xRes; j++)
        {
            xtable[i][j] = 128; // store default pixel data in gray color
        }
    }
} // array2D

array2D :: ~array2D()
{
    for(int i = 0; i < yRes; i++)
        delete []xtable[i]; // delete each row
    delete []xtable; // delete all columns
} // ~array2D

void array2D :: getSize(int &xResolution, int &yResolution)
{
    xResolution = xRes;
    yResolution = yRes;
} // getSize

void array2D :: setValue(int x, int y, float val)
{
    if(x < 0 || x >= xRes || y < 0 || y >= yRes)
        error("Out of range");
    xtable[y][x] = val;
} // setValue

float array2D :: getValue(int x, int y)
{
    if(x < 0 || x >= xRes || y < 0 || y >= yRes)
        error("Out of range");
    return(xtable[y][x]);
} // getValue

PGMImage :: PGMImage(int xResolution, int yResolution, string imageFileName) : array2D(xResolution, yResolution)
{
    filename = imageFileName;
} // PGMImage

void PGMImage :: getResolution(int &xResolution, int &yResolution)
{
    getSize(xResolution, yResolution);
} // getSize

void PGMImage :: setPixel(int x, int y, float val)
{
    setValue(x, y, val);
} // setPixel

float PGMImage :: getPixel(int x, int y)
{
    return(getValue(x, y));
} // getPixel

void PGMImage :: writeFile()
{
    ofstream fractal(filename);

    // header
    fractal << "P2" << endl; // for PPM image
    fractal << xRes << " " << yRes << endl; // how many columns, how many rows
    fractal << 255 << endl; // largest pixel value we'll be outputting (below)

    // pixel data
    for(int i = 0; i < yRes; i++)
    {
        for(int j = 0; j < xRes; j++)
        {
            float val = getPixel(j, i);
            fractal << val << " ";
        } // next column
    } // next row

    fractal.close();
} // writeFile

int main()
{
    int xRes, yRes;

    PGMImage *p = new PGMImage(512, 512, "yinyang.pgm");
    p->getResolution(xRes, yRes);
    p->writeFile();

    for(int y = 0; y < yRes; y++)
    {
        for(int x = 0; x < xRes; x++)
        {
            if(x <= xRes/2)
            {
		// create white semicircle
                if(sqrt(((256-y)*(256-y))+((256-x)*(256-x))) <= 256)
                    p->setPixel(x,y,255);
                if(y <= yRes/2)
                {
		    // create smaller white semicircle
                    if(sqrt(((128-y)*(128-y))+((256-x)*(256-x))) <= 128)
                        p->setPixel(x,y,255);
		    // create smaller black semicircle
                    if(sqrt(((128-y)*(128-y))+((256-x)*(256-x))) <= 32)
                        p->setPixel(x,y,0);
                }
                else
                {
		    // create smaller black semicircle
                    if(sqrt(((384-y)*(384-y))+((256-x)*(256-x))) <= 128)
                        p->setPixel(x,y,0);
		    // create smaller white semicircle
                    if(sqrt(((384-y)*(384-y))+((256-x)*(256-x))) <= 32)
                        p->setPixel(x,y,255);
                }
            }
            else
            {
		// create black semicircle
                if(sqrt(((256-y)*(256-y))+((256-x)*(256-x))) <= 256)
                    p->setPixel(x,y,0);
                if(y <= yRes/2)
                {
		    // create smaller white semicircle
                    if(sqrt(((128-y)*(128-y))+((256-x)*(256-x))) <= 128)
                        p->setPixel(x,y,255);
		    // create smaller black semicircle
                    if(sqrt(((128-y)*(128-y))+((256-x)*(256-x))) <= 32)
                        p->setPixel(x,y,0);
                }
                else
                {
		    // create smaller black semicircle
                    if(sqrt(((384-y)*(384-y))+((256-x)*(256-x))) <= 128)
                        p->setPixel(x,y,0);
		    // create smaller white semicircle
                    if(sqrt(((384-y)*(384-y))+((256-x)*(256-x))) <= 32)
                        p->setPixel(x,y,255);
                }
            }
        }
    }
    p->writeFile();

    delete p;
} // main

