all: main.cpp
	mkdir -p build
	NODE_ENV=production tailwindcss -c ./tailwind.config.js -o ./static/tailwind.css --minify
	g++ -O3 main.cpp -o build/homelab
