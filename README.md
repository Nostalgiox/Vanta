# VANTA

**A native game trainer platform for single-player games.**

VANTA is a desktop application designed to manage and run game trainers for supported single-player games. The project aims to provide a clean, modern interface backed by a native C++ engine.

> **Status: Early Development**  
> VANTA is currently under active development. Many planned features are not yet implemented.

## Overview

VANTA is being built with a focus on:

- A modern desktop interface.
- Native C++ engine for game process interaction.
- Automatic detection of installed Steam games.
- Management of game-specific trainers.
- Support for Windows and Linux.
- Single-player and offline gameplay.

## Technology Stack

| Component           | Technology        |
| ------------------- | ----------------- |
| Desktop application | Electron          |
| Frontend            | React, TypeScript |
| Build tool          | Vite              |
| Styling             | Tailwind CSS 4    |
| State management    | Zustand           |
| Animations          | Motion            |
| Icons               | Lucide React      |
| Native engine       | C++20             |
| Build system        | CMake             |
| Build generator     | Ninja             |

## Project Structure

```text
Vanta/
├── apps/
│   └── desktop/
│       ├── electron/
│       └── src/
│           ├── components/
│           ├── data/
│           ├── hooks/
│           ├── pages/
│           ├── stores/
│           └── types/
├── engine/
│   ├── include/
│   ├── src/
│   └── CMakeLists.txt
├── trainers/
└── docs/
```

## Development

### Requirements

- Node.js
- npm
- C++20 compatible compiler
- CMake
- Ninja
- Git

### Frontend

```bash
cd apps/desktop
npm install
npm run dev
```

### Native Engine

From the project root:

```bash
cmake -S engine -B build -G Ninja
cmake --build build
```

Run the engine:

```bash
./build/vanta-engine
```

## Roadmap

- [x] Initial project structure
- [x] Initial C++ engine
- [x] Basic engine command handling
- [x] Initial React dashboard
- [ ] Electron integration
- [ ] JSON communication protocol
- [ ] Steam game detection
- [ ] Game library
- [ ] Process monitoring
- [ ] Trainer management
- [ ] Windows platform support
- [ ] Linux platform support
- [ ] Game overlay

## Project Scope

VANTA is intended for single-player and offline use only. It is not designed to interfere with multiplayer games, anti-cheat systems, or other players' gameplay.

## License

No license has been selected yet. All rights are reserved unless stated otherwise.
