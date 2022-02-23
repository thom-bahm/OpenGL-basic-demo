# OpenGLv2
Personal OpenGL Demo for 3D objects / primitives, might expand into more complex topics, particularly interested in Gerstner/Fast Fourier Transform waves.
### Project Information/ Documentation:
- Written in c++, using visual studio community, 2019
- stb_image, GLFW, GLAD, GLM and OpenGL functions are used (Maybe more to come later)
- Used CMake to build source code.
- 64 bit
## Sources / Information

#### Articles
* [Tessendorf Paper](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.161.9102&rep=rep1&type=pdf)
* [1986 Article "A Simple Model Of Ocean Waves" Written by Fournier](http://users.encs.concordia.ca/~grogono/Graphics/waves-1.pdf) - basically about gerstner waves
* [partial C++ Adaptation of Tessendorf Paper](https://www.scratchapixel.com/lessons/procedural-generation-virtual-worlds/simulating-odean-waves/simulating-surface-ocean)
* [Nvidia GPU Gems, Gerstner Waves](https://developer.nvidia.com/gpugems/gpugems/part-i-natural-effects/chapter-1-effective-water-simulation-physical-models)

#### Videos
* [Fourier Transform concept 3blue1brown](https://www.youtube.com/watch?v=spUNpyF58BY&list=PLJPAgezdQHRH8PKECjIxSL-CBmB8k-2nR&index=2)
* [Intro to Fast Fourier Transform](https://www.youtube.com/watch?v=P4G0hn5QhMs), 
[Slideshow Associated With Video](https://www.slideshare.net/Codemotion/an-introduction-to-realistic-ocean-rendering-through-fft-fabio-suriano-codemotion-rome-2017)
* [Brief Video About Gerstner Waves](https://www.youtube.com/watch?v=V4yZigMSLiU&list=PLJPAgezdQHRH8PKECjIxSL-CBmB8k-2nR&index=1)
* [Gerstner Waves using blueprint in ue4.](https://www.youtube.com/watch?v=ANaER2rvd9M&list=PLJPAgezdQHREuUxXIzpBaGWLBYRJomN_l&index=2)
* [Mathematical Ocean For Buoyancy, Blueprint in ue4](https://www.youtube.com/watch?v=spUNpyF58BY&list=PLJPAgezdQHRH8PKECjIxSL-CBmB8k-2nR&index=2)
* [Goal video, what I'd ideall be able to acheive (Ocean rendering done in OpenGL)](https://www.youtube.com/watch?v=CeJCNmI-B7s&list=PLJPAgezdQHREseDfQ5LaUd5Sn3ONhlXEL&index=1)
* [Another goal video](https://www.youtube.com/watch?v=OQ3D0Q5BlOs&list=PLJPAgezdQHREseDfQ5LaUd5Sn3ONhlXEL&index=2)


##### To-Do
* Learn ImGui
* Figure out how to import .FBX, ultimate goal would be to import a WorldCreator 1000mx1000m or larger terrain
* Look into skybox / atmosphere shaders, maybe browse on shadertoy for anything useful.
* Create wireframe mode, I'm pretty sure it's only one line of code but maybe make it a parameter so I could edit lit vs wireframe in real time.
* Figure out how to offset individual and group vertices.
* Try to offset individual and group vertices over some time and have it repeat the process, just to be more prepared for Gerstner waves.
* Begin trying to apply the Gerstner wave equations to the plane to create 1-Directional waves, Amp, Freq, Length, everything should be parameter adjustable (Doesn't have to be real time). This part Will 100% take the longest since it's essentially the final part. This will follow the Nvidia GPU Gems equations.
* Make sure things are optimized
* (Not sure when to start this part) Figure out texture tiling and Apply textures to plane (or wait until final wave model is done to do this, could just use a color during 'development')

* ... To be continued, worry about this in a while
