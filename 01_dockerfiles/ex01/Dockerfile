FROM debian

# change the tar strip maybe?

RUN apt-get update \
&& apt-get upgrade -y \
&& apt-get install bzip2 wget -y \
&& wget http://dl.4players.de/ts/releases/3.8.0/teamspeak3-server_linux_amd64-3.8.0.tar.bz2 \
&& tar -xv --strip-components 1 -f teamspeak3-server_linux_amd64-3.8.0.tar.bz2

ENTRYPOINT sh ts3server_minimal_runscript.sh

# to build the image container:
# docker build -t ex01 .
# then do:
# docker run -d -e TS3SERVER_LICENSE=accept -p 9987:9987/udp -p 10011:10011 -p 30033:30033 ex01
# the ip will be the ip of the virtual machine:
#			docker-machine ip Char
# with the port 9987
