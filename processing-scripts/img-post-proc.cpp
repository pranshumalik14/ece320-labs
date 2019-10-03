//
// Created by pranshumalik14 on 2019-10-02.
// Takes a folder as an input argument and inverts each image's color and converts
// it to grayscale based on a threshold.
//

#include <iostream>
#include <vector>
#include <sys/stat.h>
#include <opencv2/opencv.hpp>

// global constants variables
int THRESH_VAL_INVRT = 20;
const int CLR_MAX_VAL = 255;

// function prototypes
void proc_folder(const cv::String&, const cv::String&);
void proc_img(const cv::String&, const cv::String&);

int main(int argc, const char* argv[])
{
    // args: <folder to process> <folder to save> <grayscale threshold (optional)>
    if (argc == 3)
        proc_folder(argv[1], argv[2]);
    else if (argc == 4)
    {
        THRESH_VAL_INVRT = std::stoi(argv[3]);
        proc_folder(argv[1], argv[2]);
    }
    else if (argc < 3)
        std:: cout << "Too few arguments!" << std::endl;
    else if (argc > 4)
        std:: cout << "Too many arguments!" << std::endl;

    return 0;
}

void proc_folder(const cv::String& input_folder, const cv::String& output_folder)
{
    std::vector<cv::String> images;
    cv::glob(input_folder, images);
    struct stat path_exists{};

    // create output directory if does not exist
    if (stat(output_folder.c_str(), &path_exists) != 0)
        std::system(("mkdir " + output_folder).c_str());

    for (const cv::String& img : images)
        proc_img(img, output_folder);
}

void proc_img(const cv::String& file_name, const cv::String& out_folder)
{
    cv::Mat img = cv::imread(file_name);

    cv::bitwise_not(img, img);
    cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
    cv::threshold(img, img, THRESH_VAL_INVRT, CLR_MAX_VAL, cv::THRESH_BINARY);

    cv::imwrite(out_folder + file_name.substr(file_name.rfind("/")), img);
}