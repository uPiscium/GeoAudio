# About GeoAudio
`GeoAudio` is a basic `OpenAL` handler for `C++`. This library is using `OpenAL` for handling audio system. You can get more information about `OpenAL` at [homepage](https://www.openal.org/). The license is GNU Lesser General Public License v2.1.

# How to Install
Before using this library, you should download `OpenAL` SDK. See [how to install SDK](#install-openal-sdk) and install `OpenAL` SDK. If you already installed it, see [install GeoAudio](#install-geoaudio) and install library.


## Install OpenAL SDK
- [Windows](#windows)

### Windows
1. Download `OpenAL SDK` ZIP file from [download page](https://www.openal.org/downloads/).
2. Extract ZIP file.
3. Run extracted file.


## Install GeoAudio
- [Windows](#windows-1)

### Windows
1. Download `GeoAudio` ZIP file and unzip it.
2. Run following command in terminal.
```
mkdir build
cd build
cmake ..
cmake --build .
```
3. Copy `GeoAudio.dll` and `includes` holder to your project directory.
