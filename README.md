### Twitch - Simple C++ / OpenGL 2d Game

i created this repo to keep following of what i learn in OpenGL 2d Rendering programming

i'm coding this project like a popular C++/OpenGL game programming live set of tutorials, provided by **@Progrematic (youtube channel)** 

but it seems that the lecturer of this tutorials has had some lack of knowledge in C++ standard programming and clean code, so i'm refactoring as i learning and coding

####  Dependencies

these are three dependencies needed in this project, <u>glfw</u>, <u>soil2</u> and <u>spdlog</u> (spdlog is not that ipmortant, you can comment the spdlog parts and use simple `std::cout` or sth like that), which i grap and built that by use of the great lovely [vcpkg](https://github.com/microsoft/vcpkg) package manager, just use the vcpkg command line tool sugger:

```shell
git clone https://github.com/microsoft/vcpkg
cd vcpkg
./bootstrap-vcpkg.sh
[Optional] export PATH='path/to/vcpkg:$PATH'
./vcpkg install glfw
./vcpkg install soil2
./vcpkg install spdlog
```

and the vcpkg cli will magicaly grep the package and the deps of it, then compiles that.

for more information, you can read vcpkg docs (build for some specific architecture or search in available versions and ...)

#### build environment

you need a proper version of <u>cmake</u>(to make the build system) and a native C/C++ Compiler like <u>gcc</u>, <u>clang</u> or probebly <u>MSVC</u> or <u>Mingw</u> if you are using Microsoft Windows (I recommand just run out of this so-called OS ASAP and live a happy life after that) and the <u>make</u> cli (as an option) if you use a Unix-like OS

Although it might be clear, i prefer to say: *in linux based operating systems you can use the `sudo apt-get install build-essential cmake` or `sudo yum install build-essential cmake` after a repository update.* *in windows you can download a GUI Installer for CMake and one of GCC, mingw or MSVC*. 

but if you're using MacOS you might heared befor that you should install an up-to-date version of Xcode in orther to start programming. well it's recomanded but not actually needed. if you are new to programming in mac, i recommend to install Xcode with the trailing `xcode-select --install` command (<u>and this command is somehow equivalent to install *build-essential* of Linux based operating systems</u>), then use one of the two **crap** package managers: <u>[macports](https://www.macports.org/install.php)</u> or <u>[homebrew](https://brew.sh/)</u> like `port install cmake` or `brew install cmake` but i mostly recommand to download the prebuilt binaries of [cmake](https://cmake.org/download/) and create a symlink of the executable  in the `/usr/local/bin` or install using the **dmg package**

#### building

just hit

```shell
git clone https://github.com/maghorbani/twitch
cd twitch
mkdir build && cd build
cmake .. 
cmake --build .
./Twitch
```

