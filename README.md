# UE5 Third Person Game

A third-person game project built with Unreal Engine 5 using C++ from an empty project template.

## Project Overview

This project implements a basic third-person character controller with the following features:
- Third-person camera system with spring arm
- Character movement and rotation
- Enhanced Input System integration
- Camera controls for looking around

## Technical Details

### Character Features
- Spring arm camera system with configurable settings
- Character movement with proper rotation
- Jump mechanics with air control
- Enhanced Input System for modern input handling

### Camera System
- Spring arm component for smooth camera movement
- Configurable camera distance (default: 600 units)
- Adjustable camera angle (default: -60 degrees)
- Camera boom attachment to character

### Movement System
- Character movement with proper rotation to movement direction
- Configurable rotation rate (default: 540 degrees/second)
- Jump mechanics with configurable jump velocity (default: 600 units)
- Air control for better movement while jumping (default: 0.2)

## Setup Instructions

1. Clone this repository
2. Open the project in Unreal Engine 5
3. Build the project using Visual Studio 2022
4. Run the project in the editor

## Requirements

- Unreal Engine 5
- Visual Studio 2022
- Windows 10/11

## Controls

- WASD: Movement
- Mouse: Camera control
- Space: Jump

## Development

This project uses C++ for core functionality and can be extended with Blueprints. The main character class is implemented in `MyCharacter.h` and `MyCharacter.cpp`.

## License

This project is licensed under the Unreal Engine EULA.