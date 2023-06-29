# Homelab

Homepage for my homelab with the following features:
- Current status of the homelab.
- Links to services available on the homelab.
- Ability to add bookmarks to synchronise between devices (TBD).

## Installation

### Requirements

CrowCPP
```
git clone https://github.com/CrowCpp/Crow.git
mkdir build && cd build
cmake .. -DCROW_BUILD_EXAMPLES=OFF -DCROW_BUILD_TESTS=OFF
sudo make install
```

Tailwind CLI
```
npm i -g tailwindcss
```

### Build and Run

```
git clone https://github.com/Samuel-Bowden/homelab
cd homelab
make
./build/homelab
```
