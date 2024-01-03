PATH = ${HOME}/.local/bin

install:
	gcc forLockscreen.c -o $(PATH)/forLockscreen
	gcc forWallpaper.c -o $(PATH)/forWallpaper
run:
	$(PATH)/forLockscreen
	$(PATH)/forWallpaper
	py $(PATH)/ColorScheme.py
clean:
	rm -f $(PATH)/forLockscreen
	rm -f $(PATH)/forWallpaper