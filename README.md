# About GeoAudio
`GeoAudio` is a basic `OpenAL` handler for `C++`. This library is using `OpenAL` for handling audio system. You can get more information about `OpenAL` at [homepage](https://www.openal.org/). The license is GNU Lesser General Public License v2.1.

# How to Install
Before using this library, you should download `OpenAL` SDK. See [how to install SDK](#install-openal-sdk) and install `OpenAL` SDK. If you already installed it, see [install GeoAudio](#install-geoaudio) and install library.


## Install OpenAL SDK
- [Windows](#windows)
- [Linux](#linux)

### Windows
1. Download `OpenAL SDK` ZIP file from [download page](https://www.openal.org/downloads/).
2. Extract ZIP file.
3. Run extracted file.

### Linux
There is two ways to install.
- [Using package manager](#using-package-manager)
- [Using source code](#using-source-code)

#### Using package manager
Run following command in terminal.
```
sudo apt-get install libopenal-dev
```

#### Using source code
(Reference: [StackOverflow](https://stackoverflow.com/questions/11195372/how-to-install-openal-sdk-on-ubuntu))
1. Get current source from github.
```
git clone git://repo.or.cz/openal-soft.git
```
2. Configure and build.
```
cd openal-soft
cd build
cmake ..
make
```
3. Install.
```
sudo make install
```

## Install GeoAudio
- [Windows](#windows-1)
- [Linux](#linux-1)

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

### Linux
1. Download `GeoAudio` ZIP file and unzip it.
2. Copy `OpenAL.a` from your environment to `GeoAudio/lib/` directory.
3. Run following command in terminal.
```
mkdir build
cd build
cmake ..
cmake --build .
```
4. Copy `libGeoAudio.so` and `includes` holder to your project directory.
