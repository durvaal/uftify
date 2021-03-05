all: playlist_class song_class methods main uftify clean

playlist_class: modules/playlist_class.cpp
	gcc -Wall -c modules/playlist_class.cpp -fsanitize=address -g

song_class: modules/song_class.cpp
	gcc -Wall -c modules/song_class.cpp -fsanitize=address -g

methods: modules/methods.cpp
	gcc -Wall -c modules/methods.cpp -fsanitize=address -g

main: main.cpp
	gcc -Wall -c main.cpp -fsanitize=address -g

uftify:
	gcc playlist_class.o song_class.o methods.o main.o -o uftify -fsanitize=address -static-libasan

clean:
	rm -f playlist_class.o song_class.o methods.o main.o