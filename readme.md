# YSFlight Mod

This repository contains my personal modifications to
YSFlight Community Edition (YSCE).

The project is based on YSCE, with additional changes
and experiments in flight physics and rendering.

This repository is not an official YSCE project.

# New Features

## Flight Physics Improvements

- Improved aircraft ground handling on sloped terrain.

- Reduced unrealistic bouncing and premature liftoff during takeoff rolls on downhill runways.

- Improved ground-contact calculations using terrain surface normals.

- Smoothed aircraft pitch and roll adjustments while maintaining ground contact.

- Adjusted vertical velocity corrections to reduce unnatural aircraft movement.

- Improved tail-strike handling.

- Increased braking effectiveness on the ground.

- Reduced excessive ground-induced shaking at higher speeds.

## Flight Controls and Camera

- Added incremental viewpoint control using keyboard inputs.

- Improved viewpoint behavior when switching between cockpit and external views.

- Adjusted vertical viewing angles and keyboard response.

- Added game speed control using the + and - keys, from 0.125× to 8×.

- Joystick Support (macOS)

- Improved joystick and gamepad detection using the macOS HID interface.

- Fixed joystick initialization and device enumeration issues.

- Improved joystick axis calibration handling.

## Weapons and Radar

- Adjusted missile guidance and maneuverability for different missile types.

- Modified AIM-120 tracking characteristics.

- Adjusted tracking behavior for other missile types.

- Extended selectable radar display ranges.

- macOS Compatibility and Build System

- Fixed the 6 key mapping issue affecting ILS/VOR selection through the modified Public Library.

- Updated CMake configurations for newer build environments.

# Related Project

This modified version of YSFlight CE uses a separately maintained Public Library containing macOS compatibility fixes and rendering improvements.

https://github.com/sekiuhn-tech/ysflight-public-library

