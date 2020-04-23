# Trefusis Engine - Newcomer Contributors Guide!

![build](https://github.com/ProjectAras/TrefusisEngine/workflows/build/badge.svg?branch=master)

Hey you! Finally awake! This is the TrefusisEngine, our small in-house game engine wannabe full of memory leaks and occasional runaway bug that will screetch until it gets you. Since we are in early days of development, not all is settled, but here is what you should do: Install the requirements, DO NOT change the CMakeLists.txt file in the root directory, or if you do, branch the repo so we can test it properly, and just start coding.

## Requirments

### Compile Requirments

You will need CMake to compile the project, if you will manually compile it, please compile it to its own directory. To do that, open a directory named `build`, enter that directory and then give the `cmake ..` command, this will compile the project inside the `build` directory you just opened, this directory is ignored by `git` so you won't accidently push it to the main. the file to run is named `TrefusisEngine.exe` for windows or just `TrefusisEngine` for \*nix.

### SDL Requirments

You will need libsdl, libsdl_ttf and libsdl_image to make the repository compile properly.

### Harlequin Requirments

Harlequin, our inhouse scripting engine currently requires Python. Just make seure your PYTHONPATH is set!


## Needs! Styles! Standards!

Here in ProjectAras we adhere to a strict st-- na, just kidding, if you want a style standard tho, try to use Google's C++ style guide. You don't have to know it, none of us, infact do, but it is nice practice to keep things concise.

## DOCUMENTATION

Please document your code man. Also leave some good messages to the Issue about Documention, we cannot seem to shut that down.

# Note about SDL development

We try to keep Harlequin and SDL to their respective compartments, in general, SDL and all graphics code is kept at the `GraphicsManager` and all the Harlequin stuff is kept at `src/harlequin` directory. 
