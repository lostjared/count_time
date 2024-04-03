
### README.md for Video Directory Analysis Tool

#### Overview
This tool recursively scans a specified directory for video files, matches them against a provided regular expression pattern, and calculates the total runtime (in minutes and seconds) of all matched videos. It is useful for quickly assessing the amount of video content within a directory structure that matches certain criteria.

#### Dependencies
- [OpenCV](https://opencv.org/): Used for video file processing to determine video lengths.
- C++ Compiler (e.g., g++, clang++): For compiling the program.
- Make (optional): For simplifying the compilation process.

#### Compilation
To compile the program, ensure that OpenCV is installed on your system. Then, use the following command in the terminal:

```sh
mkdir build && cd build
cmake ..
make 
sudo make install
```

#### Usage
Run the compiled program from the terminal with two arguments: the path to the directory you want to analyze and the regex pattern to match video files.

```sh
count_time /path/to/directory ".*\.(mp4|avi)$"
```

This example searches for `.mp4` and `.avi` files. Adjust the regex pattern to match the types of video files you're interested in.

#### Output
The program prints the length of each matched video file and the total runtime of all matched video files in the specified directory and its subdirectories.

### Example Output:

jared@iLostSideDead [~/Movies]$ count_time . AC2

./CloudsGlitch-2020.03.11_23.43.22_MPEG-4-1280x720p23.98.AC2.Output.1.mp4 56.8902 seconds...

./Ocean-2020.03.12_04.44.03_AVC-1920x1080p29.97.AC2.Output.1.mp4 27.9633 seconds...

./Coder-2020.03.11_16.12.40_MPEG-4-1920x1080p59.94.AC2.Output.1.mp4 120.621 seconds...

./VideoAC_1-2020.03.12_01.33.57_MPEG-4-1280x720p30.00.AC2.Output.1.mp4 137.4 seconds...

./SlitScan-2020.03.11_22.26.10_MPEG-4-1920x1080p29.00.AC2.Output.1.mp4 62.2414 seconds...

./Untitled.fcpbundle/3-11-20/Original Media/Coder-2020.03.11_16.12.40_MPEG-4-1920x1080p59.94.AC2.Output.1.mp4 120.621 seconds...

./Untitled.fcpbundle/3-11-20/Original Media/NewLogo-2020.03.09_01.56.23_MPEG-4-1920x1080p30.00.AC2.Output.2.mp4 15.8667 seconds...

./JaredMarch11-2020.03.11_18.52.12_MPEG-4-1920x1080p29.00.AC2.Output.1.mp4 62.2414 seconds...

./JaredWebcam-2020.03.11_22.12.53_MPEG-4-1920x1080p29.00.AC2.Output.1.mp4 62.2414 seconds...

        Runtime: 11 minutes 6 seconds..
