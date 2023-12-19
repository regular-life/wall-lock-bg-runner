install:
	gcc forLockscreen.c -o forLockscreen
	gcc forWallpaper.c -o forWallpaper
run:
	./forLockscreen
	./forWallpaper
clean:
	rm -f forLockscreen
	rm -f forWallpaper