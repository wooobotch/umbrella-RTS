# Umbrella Real Time Strategy

## A long time coming

I started studying and searching for solutions to run my all time loved AOE the way I want, modded as I want, when and where I want but I never found any that fullfilled my expectations:

- To be portable.
- To be clear.
- To be modular.
- Not using a cringy language or stack.
- Independent from a company's mood or agenda.

## Previous attempts

As you may have seen in that robocop sequence where they show every wrecked robocop's alpha version, many tools and languages failed:

- Unreal, a flamethrower to toast some bread.
- Unity, 2GB "hello wolrd".
- Pygame, python.
- SDL, not yet there.

That's the oversimplifyed version of the story.

## The choice

For me it was OpenGL and I was making excuses to do something with it at the same time y was posponing it.
BTW, my first programming language ever was C, then I jumped into C++ because someone told me so (I was 15 XD).
2 + 2 ends up adding what we all know.

Regardless what anyone says, that's the winning combo:
[X] Portability 
[X] Easy to read
[X] Modularity
[X] Virile
[X] Phrygian

## So, what now

First we need some dependencies/packages, keep in mind that I'm not using an IDE.

build-essential
cmake
git
libglfw3-dev
libglfw3
libglew-dev
libglm-dev
libxrandr-dev
libxinerama-dev
libxcursor-dev
libxi-dev
mesa-utils

build-essential, cmake and git are quite standard; libglfw3-dev, to manage windows and user inputs; libglm-dev for 3D math; libglew-dev, OpenGL functions.
Then mesa-utils just to test OpenGL.

After installing all that, shoot:
glxinfo | grep "OpenGL version"

You should get anything but an empty line or an error.

## Further considerations

I'm a native castellano speaker and also cordobés, so you should expect not just a spanish-ish writing but also gibberish everywhere, I'll try to keep it as readable as possible.
This is a personal project and I encourage everyone to manage their own things, I'm also helping some friends going further with C++ (assume it's them who are getting more of my attention).
All the code was a mess split across directories, different computers and even handwritten pieces of paper, I'm abusing the power of midlife crisis to get it all togheter, be patient.

Love and regards, yours
Abraham Ezequiel Chalave
