#include "pch.h"
#include "../GrayImage/GrayImage.h"

TEST(TestCaseName, TestName) {
    std::vector<uint8_t>data;
    GrayImage image(1000, 1000,data),test(1000,1000,data);
    //string path = "img.BMP";
    for (int y = 0; y < image.getHeight(); y++)
    {
        for (int x = 0; x < image.getWidth(); x++)
        {
            image.setPixel(y, x, (uint8_t)(tan(x / 20.0) * tan(y / 20.0) * 255.) / 2);
            test.setPixel(y, x, (uint8_t)(tan(x / 20.0) * tan(y / 20.0) * 255.)/4);
        }
    }  
    uint8_t p = image.getPixel(1, 1);
    //image.copyTo(test,500,500);
    GrayImage get1 = image * test;
    GrayImage get2 = image - test;
    GrayImage get3 = image.mul(test);
    GrayImage view(image, 100, 100, 500, 500);
    bool f = image == image;
    /*image.saveToBMP(path);
    test.load(path);
    vector<uint8_t>img, tst;
    for (int y = 0; y < image.getHeight(); y++)
    {
        for (int x = 0; x < image.getWidth(); x++)
        {
            img.push_back(image.getPixel(y, x));
            tst.push_back(test.getPixel(y, x));
        }
    }*/
  EXPECT_EQ(1,1);
  EXPECT_TRUE(true);
}