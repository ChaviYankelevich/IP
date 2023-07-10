#pragma once
#include <vector>
#include <stdint.h>
#include <string>
#include <stdexcept>
#include <functional>

class GrayImage
{
private:
	// TODO: Rename your private members as follows: (click on the variable and use Ctrl+R+R shortcut)
	uint8_t* _data;

	int _width;
	int _height;
	int _stride;
	size_t* _refCount;

public:
	// Default c'tor. sets _data and _refCount to nullptr:
	GrayImage();
	// The usual c'tor gets another (optional) argument: valus of image to set.
	// if this last "data" parameter is given, it must be of size width*height, and its values
	// are copied to the _data member.
	//
	GrayImage(int img_width, int img_height, std::vector<uint8_t> const& data);
	// View c'tor stays the same
	GrayImage(GrayImage const& other, int row, int col, int ROI_width, int ROI_height);
	// copy c'tor
	GrayImage(GrayImage const& other);
	// Assignment operator: does the same as copy c'tor. 
	// NOTE: you might be a valid image already...
	GrayImage const& operator=(GrayImage const& other);
	// Assignment operator to a value - sets all _data to be equal to value
	// NOTE: you might be a view. can you use memset?!
	GrayImage const& operator=(uint8_t const& value);
	// Move c'tor
	GrayImage(GrayImage&& other)noexcept;

	~GrayImage();

	// Implicit conversion to std::vector
	// (if you haven't done implicit conversions lesson & exercise in C++, that's the time.)
	//operator std::vector<uint8_t>() const;

	int getWidth() const;
	int getHeight() const;
	size_t getRefCount() const; // NEW
	int getStride() const;

	uint8_t const* data() const;
	uint8_t getPixel(int row, int col) const;
	void setPixel(int row, int col, uint8_t value);

	GrayImage operator +(GrayImage const& other) const; // by element
	GrayImage operator -(GrayImage const& other) const; // by element
	GrayImage mul(GrayImage const& other) const; // by element *
	GrayImage absdiff(GrayImage const& other) const; // by element absdiff
	GrayImage operator *(GrayImage const& other) const; // matrix multiplication
	GrayImage operator *(uint8_t const& value) const; // by element multiply by value.

	bool operator ==(GrayImage const& other) const; // compare by element to other image
	bool operator ==(uint8_t const& value) const; // compare all elements to value

	void saveToBMP(std::string const& filepath) const;
};
