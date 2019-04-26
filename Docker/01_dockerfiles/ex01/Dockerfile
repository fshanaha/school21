FROM debian

MAINTAINER fshanaha <fshanaha@student.21-school.ru>

WORKDIR /home/ts

ENV TS3SERVER_LICENSE=accept

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install wget -y
RUN apt-get install bzip2 -y
RUN wget http://dl.4players.de/ts/releases/3.7.0/teamspeak3-server_linux_amd64-3.7.0.tar.bz2
RUN tar xvf teamspeak3-server_linux_amd64-3.7.0.tar.bz2

EXPOSE 9987:9987/udp
EXPOSE 10011:10011
EXPOSE 30033:30033

WORKDIR teamspeak3-server_linux_amd64

ENTRYPOINT sh ts3server_minimal_runscript.sh


# docker build -t ex01 .
# docker run -it --rm -p 10011:10011 -p 30033:30033 -p 9987:9987/udp ex01
