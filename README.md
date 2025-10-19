# 🎮 Math Library & Breakout Demo

## 📄 Project Presentation

This project is a **playable demo** of a **2D game** created with SFML, using a custom C++ templated **math library**. All transformations, vector operations, and collision calculations are handled exclusively through this library. It includes types like `Vec2<T>`, `Vec3<T>`, `Quaternion<T>` and `Mat4x4<T>`.

---
## ⚙️ Build and Execution Instructions

### Requirements 

- **Visual Studio 2022**  
- **SFML 3.0.2 (statically linked)**  
The project includes the required `include/` and `lib/` folders for SFML. No external installation is needed. Just make sure the paths are correctly set in your project properties:  

  SFML paths use `$(SolutionDir)`:

	- `C/C++ -> General -> Additional Include Directories`: `$(SolutionDir)\include` 
	- `Linker -> General -> Additional Library Directories`: `$(SolutionDir)\lib`  
	- `Linker -> Input -> Additional Dependencies`: Add the required `.lib` files: `sfml-graphics-s.lib`, `sfml-window-s.lib`, `sfml-system-s.lib`, etc.
  
  Math library include path uses `$(ProjectDir)`:
     - `VC++ Directories -> Include Directories: $(ProjectDir)` 
- `MSTest` (for unit testing)

### Setup
1. Clone the repository:

```bash
git clone https://github.com/GamingCampus-MillieBourgois-25-26/3d-geometry-lea-et-maelyne.git
```

2. Open the `.sln` file in Visual Studio.
3. Choose a build configuration:
     - `Debug x64` -> for development and debugging
     - `Release x64` -> for optimized performance
4. Build and run the project.

> Make sure the `assets/` folder is located in the same directory as the `.exe` file. The game uses relative paths to load the resources.

### Project Structure Note

The folder `Maths/` contains the main game project.  
It was originally named `Game`, but renaming it caused issues with Visual Studio, so the name was kept for stability.

The overall structure is:
```
ProjectRoot/
|--Maths/             # SFML demo breakout game 
     |--assets/       # Game textures, font, etc.
|--MathsLibrary/      # Custom math library
|--UnitTest/          # Visual Studio C++ Unit Test
|--include/           # SFML Headers
|--lib/               # SFML libraries
|--3D-Geometry.sln    # Visual Studio solution
|--README.md
```

---
## 📏 Math Conventions

- **Namespace**: `math`  
- **Angle unit** = radians  
- **Matrix format** = column-major  
- **Default type**: float (`Vec2f`, `Mat4x4f`)  

>No external dependencies: all math types and operations are custom-built. 

---
##  🎯 Implemented Functions

Here are some examples of the methods added to the library:

Vec2<T>: 
- **Arithmetic**: `+`, `-`, `*`, `/`, `==`, `!=`  
- **Static vectors** : `Down`, `Left`, `NegativeInfinity`, `One`, `PositiveInfinity`, `Right`, `Up`, `Zero`  
- **Static methods** : `Angle`, `ClampMagnitude`, `Distance`, `Dot`, `Lerp`, `LerpUnclamped`, `Max`, `Min`, `Reflect`, `Scale`, `Perpendicular`, `MoveTowards`  

Vec3<T>:  
- **Arithmetic**: Same as `Vec2<T>`  
- **Static vectors**: `Back`, `Down`, `Forward`, `Left`, `NegativeInfinity`, `PositiveInfinity`, `One`, `Right`, `Up`, `Zero`  
- **Static methods**: Same as `Vec2`, plus `Cross`, `OrthoNormalize`, `Project`, `ProjectOnPlane`, `RotateTowards`, `Slerp`, `SlerpUnclamped`  

Quaternion<T>: 
- **Arithmetic**: `*`, `+`, `==`  
- **Public methods**: `Equals`, `Set`, `SetFromToRotation`, `SetLookRotation`, `ToAngleAxis`, `ToString`  
- **Static methods**: `Angle`, `AngleAxis`, `Dot`, `Euler`, `FromToRotation`, `Inverse`, `Lerp`, `LerpUnclamped`, `LookRotation`, `Normalize`, `RotateTowards` 

Mat4x4<T>: 
- **Arithmetic** : `*`  
- **Public methods**: `GetColumn`, `GetRow`, `SetColumn`, `SetRow`, `MultiplyPoint`, `MultiplyPoint3x4`, `MultiplyVector`, `ToString`, `ValidTRS`  
- **Static methods**: `Frustum`, `Scale`, `Translate`, `Inverse3DAffine`, `LookAt`, `Ortho`, `Perspective`, `Rotate`, `TRS`  

## ✅ Unit Testing
- **Framework**: Visual Studio C++ Unit Test 
- **Coverage**: major methods in `Vec2`, `Vec3`, `Quaternion`, `Mat4x4`

---
## 🎮 SFML Game Demo

- **Game: Breakout**  
- **Graphics: SFML 3.0.2**  
- **Physics**: All collisions use `math::Vec2f::Reflect` for realistic bounce behavior  
- **Gameplay**:   
  - Score increases by 25 per brick destroyed  
  - 3 lives: ball resets when lost  
  - Paddle movement and collision handled via math library  

### Controls
`Q` or `<-` = Move paddle left.  
`D` or  `->` = Move paddle right.

---


[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/WaLJfkf3)
