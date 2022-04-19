# image2ascii :camera:

Convert an image to ASCII and save it into a file, assigning a symbol to each pixel.

## Explanation
Let **f** be a function which assigns the position of a symbol of a set of symbols to each color (grey scale)

![alt text](https://github.com/MorcilloSanz/image2ascii/blob/main/img/f2.png)
![alt text](https://github.com/MorcilloSanz/image2ascii/blob/main/img/f.png)

Where:

![alt text](https://github.com/MorcilloSanz/image2ascii/blob/main/img/X.png)

![alt text](https://github.com/MorcilloSanz/image2ascii/blob/main/img/Y.png)

* X is the color set (red set in the image) 
* Y set is the positions set (blue set in the image)
* Symbols set S = {$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,"^`'. }

The assignment is given by the function **f**:

![alt text](https://github.com/MorcilloSanz/image2ascii/blob/main/img/fun.png)

[Thanks to:](http://paulbourke.net/dataformats/asciiart/)

## Compilation and usage
Use **C++11** at least for compiling purposes
```
sh compile.sh
./image2ascii image.png
```
It will save it in a file **output.txt**

# Example
![alt text](https://github.com/MorcilloSanz/image2ascii/blob/main/img/saturno.png)

![alt text](https://github.com/MorcilloSanz/image2ascii/blob/main/img/saturnoIDE.png)

![alt text](https://github.com/MorcilloSanz/image2ascii/blob/main/img/anonymous.png)

![alt text](https://github.com/MorcilloSanz/image2ascii/blob/main/img/anonymousIDE.png)