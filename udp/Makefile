.PHONY:all
all:server client
server:server.cc
	g++ server.cc -o server
client:client.cc
	g++ client.cc -o client
.PHONY:clean
clean:
	rm server client
