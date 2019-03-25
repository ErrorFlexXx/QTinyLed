# QTinyLed

A tiny led indicator.
For a simple use case of this project please have a look in the examples folder.

## Showcase
The gif is reducing the color palette -- please ignore the hard transistions.

![](Showcase.gif)

## Installation
Required components:
- qttools5-dev

The following installation methods has been tested:

### Linux
```
git clone url/QTinyLed.git
mkdir build
cd build
qmake ../QTinyLed
make
sudo make install
```

### Windows
Required components: Visual Studio (or MinGW toolchain, but this has not been tested)

- Open Visual Studio Developer CMD
- cd to a folder above the QTinyLed git project dir
- Exec qmake for the project (For some reason I had to tell the full path to qmake.exe)

```
mkdir build
cd build
C:\Qt\5.11.2\msvc2015\bin\qmake.exe ../QTinyLed
nmake
nmake install
```

In my case the plugin got installed to `C:\Qt\5.11.2\msvc2015\plugins\designer\QTinyLed.dll`. But the designer.exe used from my configured QTCreator is located at 
`C:\Qt\Tools\QtCreator\bin`. Therefore I had to copy the `QTinyLed.dll` manually to `C:\Qt\Tools\QtCreator\bin\plugins\designer\QTinyLed.dll`. Do not forget to restart the QTCreator
in order to see, if the new plugin loads correctly.

Additional the genereated QTinyLed.lib file is required on windows to build something with the dynamic lib, but it's not installed by the Qt Project file for some reason.



