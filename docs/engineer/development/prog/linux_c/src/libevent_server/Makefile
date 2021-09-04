#! /bin/bash
.PHONY:clean

default:
	# sudo apt-get update
	# sudo apt install libevent-dev
	gcc -O server.c -o server -levent
	gcc -O client.c -o client -levent

clean:
	rm server client