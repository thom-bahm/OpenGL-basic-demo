# Index:

[C++](https://github.com/thom-bahm/OpenGL/blob/master/NOTES.md#c-specific) 
- [General c++ Resources](https://github.com/thom-bahm/OpenGL/blob/master/NOTES.md#general-resources)
- [Pointers](https://github.com/thom-bahm/OpenGL/blob/master/NOTES.md#pointers)
- [References](https://github.com/thom-bahm/OpenGL/blob/master/NOTES.md#references)
- [Const](https://github.com/thom-bahm/OpenGL/blob/master/NOTES.md#const)
- [Memory (Heap/Stack, etc)](https://github.com/thom-bahm/OpenGL/blob/master/NOTES.md#memory-heap-vs-stack-etc)
- [Templates](https://github.com/thom-bahm/OpenGL/blob/master/NOTES.md#templates-in-c)

[General Graphics](https://github.com/thom-bahm/OpenGL/blob/master/NOTES.md#general-graphics)
- [Collision Detection](https://github.com/thom-bahm/OpenGL/blob/master/NOTES.md#collision-detection-aabb)
- [Ray Marching](https://github.com/thom-bahm/OpenGL/blob/master/NOTES.md#ray-marching)



## C++ Specific:
#### General Resources:
[C++ playlist (Cherno)](https://www.youtube.com/playlist?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)

### Pointers:
[Pointers video](https://www.youtube.com/watch?v=DTxHyVn0ODg)
* Pointers are just integers that store a memory address.
* 0 means null with pointers (0 is not a valid memory address) - also every variable has a memory address
* using '&' in front of a variable gets the memory address of said variable:
```cpp
int var = 8;
void* ptr = &var;
```
ptr would return var's memory address, such as: 0x00a0fb64; And if if you went to that address, you would see 08 00 00 00 first (8 is value stored at that memory, int has 4 bytes data, so you get 08 00 00 00)
* types are apparently meaningless in relevance to pointers (they just assist in manipulation)
* If you want to use value in var, you can dereference (* operator before variable) in order to access the data, like so:
```cpp
int var = 8;
int* ptr = &var;
*ptr = 10;
LOG(var);
```
using '*ptr' gives you access to write data to memory at var's location (as you assigned ptr to &var), so output would be:
**10 (var's value)** 

Heap-allocated memory (You should delete when done using when on heap):
```cpp
//This code will allocate 8 bytes of memory (char == 1 byte), and have buffer point to beginning of said memory location.
char* buffer = new char[8];
memset(buffer, 0, 8); // Turns every byte in buffer to 00, so if you looked at memory address it would show: 00 00 00 00 00 00 00 00

delete[] buffer;
```

### References:
[Reference Video](https://www.youtube.com/watch?v=IzoFn3dfsPA)
* ;

### Const:
[Const Video](https://www.youtube.com/watch?v=4fJBrditnJU) || 
[Const Article](https://www.geeksforgeeks.org/const-member-functions-c/)

* const is a promise that some data will be constant (although you can bypass). Simple ie: const int a = 5; a must always equal 5.
  if you use const in class
	```cpp
	class Entity
	{
	private:
	  int m_X, m_Y;
	public:
	  int GetX() const
	  {
	    return m_x
	  }
	};
	```

  The const means that GetX cant modify any of the class member variables.

* mutable int var; -- mutable allows you to modify a class var even inside a const method.
 
### Memory (Heap vs Stack, etc)
[Heap vs Stack Article](https://www.geeksforgeeks.org/stack-vs-heap-memory-allocation/)

[Heap/Stack video](https://www.youtube.com/watch?v=wJ1L2nSIV1s)

How to call stack/heap:
```cpp
int main()
{
	int sVal = 5; //Stack allocation
	
	int* hVal = new int;
	*hVal = 5; // Heap allocation
}
```

### Templates in c++:
[Templates video](https://www.youtube.com/watch?v=wJ1L2nSIV1s)

[Template Article](https://en.cppreference.com/w/cpp/language/templates)

Literal Def:
A template is a C++ entity that defines one of the following:
- a family of classes (class template), which may be nested classes
- a family of functions (function template), which may be member functions
- an alias to a family of types (alias template) (since C++11)
- a family of variables (variable template) (since C++14)
- a concept (constraints and concepts) (since C++20)

##### Template with types:
- Template basically allows you to write code for you, based on set of rules (that you give it)
- If you write func with template, and when u call function you specify certain params to determine what code gets put into template.
- Practical use, if you are trying to print something and it could be a int, string, float, etc, instead of writing a print func with x overloads, create template<typename T> (or any var name), and pass in var with type T into print func:
	```cpp
	template <typename T>
	void Print(T value)
	{
		std::cout << value << std::endl;
	}
	int main()
	{
		Print(5);
		Print("Hello");
		Print(5.0);
	}
	```
Output
	5, Hello, 5.0

- If you choose, you could represent typename by class, same thing.
- You could also do Print<int>(5), Print<std::string>("Hello"), etc. - not necessary since c++ can deduce what type the value you enter is.
- Template doesnt exist until you call it.

##### Template with Classes

```cpp
	template<int N>
	class Array
	{
	private:
		int m_Array[N];
	public:
		int GetSize() const { return N; }
	};
	
	int main()
	{
		Array<5> array;
		std::cout << array.GetSize() << std::endl;
	}
```
Output:
	5

- You can give multiple Templates as well, for example if you want the type of m_Array to be dynamic, you can give a typename template:

```cpp
	template<typename T, int N>
	class Array
	{
	private:
		T m_Array[N];
	public:
		int GetSize() const { return N; }
	};
	
	int main()
	{
		Array<float, 5.0> array;
		std::cout << array.GetSize() << std::endl;
	}
```
Output:
	5.0
	


## General Graphics:
##### Why are pants, different than shirts? and Blankets; How do they work?

### Collision Detection (AABB)
[AABB Collision Detection Article](https://learnopengl.com/In-Practice/2D-Game/Collisions/Collision-detection)

* AABB stands for axis-aligned bounding box
* If the max num of axes (3 in 3D, 2 in 2d) from different objects overlap, there is a collision.

### Ray-Marching
Links:

[Ray-Marching Fractals blog](http://blog.hvidtfeldts.net/index.php/2011/06/distance-estimated-3d-fractals-part-i/) , [Ray Marching Article](https://developer.nvidia.com/gpugems/gpugems/part-vi-beyond-triangles/chapter-39-volume-rendering-techniques), [Ray Marching Video](https://www.youtube.com/watch?v=PGtv-dBi2wE)
