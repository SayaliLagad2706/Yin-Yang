#ifndef PGMImage_H
#define PGMImage_H
using namespace std;

// class declaration
class array2D {
protected:
    int xRes, yRes;
    float **xtable; // pointer to pointer[s]

public:
    array2D(int xResolution = 512, int yResolution = 256);
    ~array2D();
    void getSize(int &xResolution, int &yResolution);
    void setValue(int x, int y, float val);
    float getValue(int x, int y);
}; // class array2D

// class declaration
class PGMImage : public array2D {
private:
    string filename;

public:
    PGMImage(int xResolution = 512, int yResolution = 512, string imageFilename = "test.pgm");
    ~PGMImage() {}
    void getResolution(int &xResolution, int &yResolution);
    void setPixel(int x, int y, float val);
    float getPixel(int x, int y);
    void writeFile();
}; // class PGMImage

#endif // PGMImage_H


