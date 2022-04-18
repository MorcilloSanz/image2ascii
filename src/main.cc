/*
Convert an image to ASCII art

Dev: MorcilloSanz
Email: amorcillosanz@gmail.com
GitHub: https://github.com/MorcilloSanz

Thanks to: http://paulbourke.net/dataformats/asciiart/

Usage: ./image2ascii image.png
*/

#include <iostream>
#include <vector>
#include <fstream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

class Image {
private:
    std::string path;
    int width, height, bpp;
    std::vector<unsigned char> buffer;
    Image(const std::string& _path, const std::vector<unsigned char>& _buffer, int _width, int _height, int _bpp);
public:
    Image();
    ~Image() = default;
    std::string toAscii();
    static Image loadPNG(const std::string& path);
public:
    inline const std::string& getPath()                 { return path; }
    inline int getWidth() const                         { return width; }
    inline int getHeight() const                        { return height; }
    inline int getBpp() const                           { return bpp; }
    inline std::vector<unsigned char>& getBuffer()      { return buffer; }
};

int main(int argc, char** argv) {

    if(argc < 2) {
        std::cout << "No input image\nTry ./image2ascii image.png" << std::endl;
        return 0;
    }
    // Read image
    Image image = Image::loadPNG(argv[1]);
    // Write to file
    std::ofstream file;
    file.open("output.txt");
    file << image.toAscii();
    file.close();
    // Bye
    std::cout << "Image saved in output.txt" << std::endl;
    return 0;
}

Image::Image(const std::string& _path, const std::vector<unsigned char>& _buffer, int _width, int _height, int _bpp)
    : path(_path), buffer(_buffer), width(_width), height(_height), bpp(_bpp) {
}

Image::Image() 
    : width(0), height(0), bpp(0) {
}

std::string Image::toAscii() {

    const std::string asciiSet = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
    const size_t asciiSetLength = 70;

    auto greyFilter = [&](unsigned char r, unsigned char g, unsigned char b) {
        return 0.3 * r + 0.59 * g + 0.11 * b;
    };

    auto getSymbol = [&](unsigned char color) {
        if(color < 0)           color = 0;
        else if(color > 255)    color = 255;
        unsigned int pos = static_cast<int>(asciiSetLength * static_cast<float>(color) / 255);
        if(pos < 0)                         pos = 0;
        else if(pos > asciiSetLength - 1)   pos = asciiSetLength - 1;
        return asciiSet[pos];
    };

    std::string output = "";
    for(int j = 0; j < height; j ++) {
        for(int i = 0; i < width; i ++) {
            unsigned char grey = greyFilter(buffer[4 * (i + j * width)], buffer[4 * (i + j * width) + 1], buffer[4 * (i + j * width) + 2]);
            output += getSymbol(grey);
        }
        output += "\n";
    }
    return output;
}

Image Image::loadPNG(const std::string& path) {
    // Load image
    int width, height, bpp;
    std::vector<unsigned char> buffer;
    unsigned char* buff = stbi_load(path.c_str(), &width, &height, &bpp, STBI_rgb_alpha);
    // Copy to buffer
    size_t bufferSize = width * height * 4;
    buffer.resize(bufferSize);
    memcpy(&buffer[0], buff, bufferSize);
    // Free first buffer
    stbi_image_free(buff);
    // Return image
    return Image(path, buffer, width, height, bpp);
}