#include<iostream>
#include<string>
#include<opencv2/opencv.hpp>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<regex>

void add_directory(std::string path, std::vector<std::string> &files) {
    DIR *dir = opendir(path.c_str());
    if(dir == NULL) {
        std::cerr << "Error could not open directory: " << path << "\n";
        return;
    }
    dirent *file_info;
    while( (file_info = readdir(dir)) != 0 ) {
        std::string f_info = file_info->d_name;
        if(f_info == "." || f_info == "..")  continue;
        std::string fullpath=path+"/"+f_info;
        struct stat s;
        lstat(fullpath.c_str(), &s);
        if(S_ISDIR(s.st_mode)) {
            if(f_info.length()>0 && f_info[0] != '.')
                add_directory(path+"/"+f_info, files);
            
            continue;
        }
        if(f_info.length()>0 && f_info[0] != '.') {
            files.push_back(fullpath);
        }
    }
    closedir(dir);
}


int main(int argc, char **argv) {
    if(argc != 3) {
        std::cerr << "Requires two arguments...\n";
        exit(EXIT_FAILURE);
    }
    std::vector<std::string> files;
    add_directory(argv[1], files);
    std::regex r(argv[2]);
    double seconds = 0;
    for(int i = 0; i < files.size(); ++i) {
        bool is_valid = std::regex_search(files[i], r);
        if(is_valid) {
            cv::VideoCapture cap(files[i]);
            if(cap.isOpened()) {
                double frames = cap.get(cv::CAP_PROP_FPS);
                double total = cap.get(cv::CAP_PROP_FRAME_COUNT);
                double len = total/frames;
                seconds += len;
                std::cout << files[i] << " " << len << " seconds...\n";
            }
        }
    }
 
    unsigned long sec = seconds;
    unsigned long min = 0;
    if(sec > 60) {
        min = seconds/60;
        sec = static_cast<int>(seconds)%60;
    }
    std::cout << "\tRuntime: " << min << " minutes " << sec << " seconds..\n";
    return 0;
}
