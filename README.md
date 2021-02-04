# About Game Sorting

Game Sorting is a little C++ application I've wrote to help classify my list of wished games on Windows and Linux. It's main purpose is for games, but it can be used for other uses. It's just a simple app that display a Table with three columns : **Game name**, **Game type** and the **Rate**. It's have also multiple tabs witch you can close or open new one.

# Installation

The app work on both Windows and Linux. The compilation of the program is realy simple, the only dependency you need is Qt 5. The app have been tested with Qt 5.15.

### Windows
-----------
To Compile on Windows, you need a C++11 compiler like [Visual Studio](https://visualstudio.microsoft.com/fr/), the framework [Qt 5](https://www.qt.io/) and [CMake](https://cmake.org/) to configure the project.

To install Visual Studio, go to the [Visual Studio](https://visualstudio.microsoft.com/fr/) website and download Visual Studio Community. On the installation, when the install tool ask you what module you want to install, tick the Desktop C++ module.

To install Qt, go to the [Qt](https://www.qt.io/) website, go to the **Download. Try.**, **Download for Open Source** and then Online installer at bottom of the page. On the installation, when the installer ask you what module you want to download, choose **MSVC 2019 64-bit** (2019 or newer) under `Qt/Qt 5.15.2/` (5.15.2 or newer, but not Qt 6).

You can download the ZIP of the project under the **Code** button on top right, or you can clone it with git.

To configure CMake, you need to set the `Qt5_DIR` cmake variable to the directory where the `Qt5Config.cmake` is stored, something like this `Qt5Dir\compiler\lib\cmake\Qt5`, in my case : `C:\Qt\5.15.2\msvc2019_64\lib\cmake\Qt5`.

Go to the project folder, create a new directory (you can name it like you want :slightly_smiling_face:), open CMake, choose the **Where is the source code** to the source code folder and the **Where to build the binaries** to your newly created folder. Add an **Entry** of type **PATH** to the path where `Qt5Config.cmake` is stored, then click on **configure**.

On your folder, you should have a Visual Studio project name `GameSorting.vcxproj`, open it with visual studio, on toolbar change **Debug** to **Release** and then right click on **ALL_BUILD** on right and click on build.

If everything is Okay, the executable should be in `YourFolder\bin\Release`.

Before executing the program, you need to copy some Qt DLLs, go to `Qt5Dir\compiler\bin` and copy and paste where the program executable is the DLLs **Qt5Core.dll**, **Qt5Gui.dll**, **Qt5Svg.dll**, **Qt5Widgets.dll**. Then create a folder **plugins**, inside it create three folders **imageformats**, **platforms**, **styles**.
Now, you have to copy some DLLs in each folder.
- **imageformats** : **qico.dll** and **qsvg.dll**.
- **platforms** : **qwindows.dll**.
- **styles** : **qwindowsvistastyle.dll**

Now you can enjoy :slightly_smiling_face:.

### Linux
---------
On Linux, you need to install a compiler like `gcc`, the framework `Qt`, `CMake` to configure the project for compilation and `git` to download the project.

##### Ubuntu
------------
On Ubuntu, install the package `build-essential`, `qtdeclarative5-dev`, `cmake`, `git`
```
sudo apt install build-essential qtdeclarative5-dev cmake git
```

##### Arch Linux
----------------
On Arch Linux, install the packages `base-devel`, `qt5-base`, `cmake` and `git`.

```
sudo pacman -S base-devel qt5-base cmake git
```

--------------------------------------------------------------------------------------------------

Open a terminal, and use the git command to download the project :

```
git clone https:\\
```

Now, you can build the project :
```
cd gamesorting
mkdir build
cd build
cmake ../ -DCMAKE_BUILD_TYPE=Release
make -j $(nproc)
make install
```

# Licence
Please see the LICENSE file.