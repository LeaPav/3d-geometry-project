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
It was originally named `Game`, but renaming it caused issues with Visual Studio, so we kept the name for stability.

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
- **Arithmetic**: `+`, `-`, `*`, `/`, `==`, `!=`, `this[]` 
- **Static vectors** : `Down`, `Left`, `NegativeInfinity`, `One`, `PositiveInfinity`, `Right`, `Up`, `Zero`  
- **Properties**: `Magnitude`, `Normalized`, `SqrMagnitude`
- **Public Methods**: `Normalize`, `Equals`, `Set`, `ToString`
- **Static methods** : `Angle`, `ClampMagnitude`, `Distance`, `Dot`, `Lerp`, `LerpUnclamped`, `Max`, `Min`, `Reflect`, `Scale`, `Perpendicular`, `MoveTowards`, `SignedAngle`  

Vec3<T>:  
- **Arithmetic**: Same as `Vec2<T>`, `this[]`  
- **Static vectors**: `Back`, `Down`, `Forward`, `Left`, `NegativeInfinity`, `PositiveInfinity`, `One`, `Right`, `Up`, `Zero`  
- **Properties**: `Magnitude`, `Normalized`, `SqrMagnitude`  
- **Public Methods**: `Equals`, `Set`, `ToString`
- **Static methods**: Same as `Vec2` (except `Perpendicular`) plus `Cross`, `OrthoNormalize`, `Project`, `ProjectOnPlane`, `RotateTowards`, `Slerp`, `SlerpUnclamped`  

Quaternion<T>: 
- **Arithmetic**: `*`, `+`, `==`, `this[]` 
- **Static properties**: `Identity`
- **Properties**: `EulerAngles`, `Normalized` 
- **Public methods**: `Equals`, `Set`, `SetFromToRotation`, `SetLookRotation`, `ToAngleAxis`, `ToString`  
- **Static methods**: `Angle`, `AngleAxis`, `Dot`, `Euler`, `FromToRotation`, `Inverse`, `Lerp`, `LerpUnclamped`, `LookRotation`, `Normalize`, `RotateTowards`, `Slerp`, `SlerpUnclamped` 

Mat4x4<T>: 
- **Arithmetic**: `*`, `this()`
- **Static properties**: `Identity`, `Zero`   
- **Properties**: `Determinant`, `Inverse`, `IsIdentity`, `LossyScale`, `Transpose`, `Rotation` 
- **Public methods**: `GetPosition`, `GetColumn`, `GetRow`, `SetColumn`, `SetRow`, `SetTRS`, `MultiplyPoint`, `MultiplyPoint3x4`, `MultiplyVector`, `ToString`, `ValidTRS`  
- **Static methods**: `Frustum`, `Scale`, `Translate`, `Inverse3DAffine`, `LookAt`, `Ortho`, `Perspective`, `Rotate`, `TRS`  

## ✅ Unit Testing
- **Framework**: Visual Studio C++ Unit Test 
- **Coverage**: core methods in `Vec2`, `Vec3`, `Quaternion`, `Mat4x4`

---
## 🎮 SFML Game Demo

- **Game: Breakout**  
- **Graphics: SFML 3.0.2**  
- **Physics**: All collisions use `math::Vec2f::Reflect` for realistic bounce behavior  
- **Gameplay**:   
  - 3 types of bricks with different lives: it takes either 1 hit, 2 hits, or 3 hits to destroy them.
  - You earn `25` points for each brick hit, and `75` points when a brick is destroyed.
  - 3 lives: ball resets when lost.  
  - Paddle movement and collision handled via math library.  

### Controls
`Q` or `<-` = Move paddle left.  
`D` or  `->` = Move paddle right.

---


[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/WaLJfkf3)
