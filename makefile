all: build/homelab static/tailwind.css

build/homelab: main.cpp
	mkdir -p build
	g++ -std=c++20 main.cpp -o build/homelab

static/tailwind.css:
	NODE_ENV=production tailwindcss -c ./tailwind.config.js -o ./static/tailwind.css --minify
