/*
    The MIT License (MIT)

    Copyright (c) 2016 Nicolas Guillemot

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#ifndef JUSTGL_IMAGE_H
#define JUSTGL_IMAGE_H

#include <cstdint>
#include <string>
#include <memory>
#include <functional>

class Image
{
public:
    // Set this if the built-in image loader isn't fancy enough for you
    static std::function<Image(const std::string&)>* CustomImageLoader;

    Image()
        : BytesPerPixel(0)
        , Width(0)
        , Height(0)
        , Depth(0)
    {
    }

    std::shared_ptr<uint8_t> Data;

    int BytesPerPixel;
    int Width;
    int Height;
    int Depth;
};

// Returns image with NULL Data if it fails.
Image ReadImageFromFile(const std::string& filename);

#endif // JUSTGL_IMAGE_H