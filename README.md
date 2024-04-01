# TheEye
AI powered VR application for Raspberry PI.

---

### Notes
> AI not implemented yet
> SDL2 needs to be migrated to SDL3 

---

### Requirements:
* Cmake
* Make (optional)
* Git
* GNU Compiler Collection (gcc, g++ etc.)
* Any optional 3Rd dependency


## Preparing Development Environment
```
    # clone the repo
    git clone git@github.com:eheperson/theeye.git

    # change access rights of compile.sh file
    chmod +x bake.sh
```

---

## Development

### Step Zero (Adding Mode 3Rd dependency): 

As a step zero, you must link your 3Rd dependency to the project. There are 2 different options here for that purpose:

* Get the builded binaries and link them.
* Get the source code, build the source code then, link the binaries.

Here are the steps of building 3Rd dependenc from source and link it 
(*Example to build and link SDL2 module*) :

1. If your 3Rd dependency on GitHub, you can add it easily as a git project submodule:
```
    cd ./external/sources
    git submodule add git@github.com:libsdl-org/SDL.git

    # or just use git clone command
    cd ./external/sources
    git clone git@github.com:libsdl-org/SDL.git
```

2. Create a build folder outside of the source code directory :
```
    # create build folder
    mkdir -p ../sdl2_build
```

3. Configure the 3Rd dependency to prepare it for cmake build:
```
    cd ./SDL

    # configure
    cmake -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_INSTALL_PREFIX=../../sdl2 \
      -DCMAKE_C_COMPILER=/usr/bin/gcc \
      -DCMAKE_CXX_COMPILER=/usr/bin/g++ \
      -DCMAKE_C_FLAGS="-Werror,-Wno-declaration-after-statement" \
      -DCMAKE_CXX_FLAGS="-Wno-declaration-after-statement" \
      -S . \
      -B ../sdl2_build 
```

4. Start build process of 3Rd dependency : 
```
    cd ../ # corresponds to ./external/sources

    # option 1
    cmake --build ./sdl2_build -v

    # option 2
    cd ./sdl2_build
    make -j7
```

4. Start install process of 3Rd dependency : 
```
    cd ../ # correspond to ./external directory
    
    # option 1
    cmake --install ./sources/sdl2_build --prefix sdl2

    # option 2 
    cd ./sources/sdl2_build
    make install
```

> If you  dont want build the 3Rd dependencies from source and have binaries of the 3Rd dependency, just create new folder in the `./external/` dir and put them here.

## Start to development (After the step zero)

* Use the `bake.sh` file for developement. 
* Purpose of the `bake.sh` file is handling all *build*, *install* and *packing* procedures in isolated directory named as `out/`.
* `CMAKE_INSTALL_PREFIX` option is modified to install targets in `/out` directory.

### Steps

1. Write your code.
2. Edit the `CMakeLists.txt` file for proper linking, compiling and installing.
3. Run the `bake.sh` file.

---

## Production

* After your development is done, you can follow the steps below to build and pack your application.

### 1. Configure : 

```
    # run this command at the root directory of the project
    cmake -S . -B ./out/build
```

### 2. Build : 

```
    # option 1 : building by cmake
    cd ./out/build && cmake --build . -v 

    # option 2 : building by make itself 
    # ( there is no any major difference between option1 and option 2)
    cd ./out/build && make 

    # alternatively you can use -j parameters with make command to speed up build process
    cd ./out/build && make -j7
```

### 3. Install : 

The project will configured to install common unix install directories like : `usr/slare/local`, `/usr/local` etc.

> you may require run install commands by `sudo`, because installing process will install your project to the one of the root directories.

```
    # option 1 :
    cd ./out/build && cmake --install .

    # option 2 : 
    cd ./out/build && make install
```

### 4. Packing : 

```
    cd ./out/build && cpack -C Release
```