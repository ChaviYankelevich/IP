#include <vector>
using namespace std;
class GrayImage
{
private:
	std::vector<uint8_t>image;
	int width;
	int height;
public:
	GrayImage(int img_width,int img_height);
	int getWidth()const;
	int getHeight()const;
	uint8_t getPixel(int row, int col)const;
	void setPixel(int row, int col, uint8_t value);
	//~GrayImage();

};

