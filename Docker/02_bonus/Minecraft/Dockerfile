FROM debian

MAINTAINER fshanaha <fshanaha@student.21-school.ru>

WORKDIR /minecraft/

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install -y curl openssh-server wget lib32gcc1 screen default-jdk

RUN wget https://launcher.mojang.com/v1/objects/f1a0073671057f01aa843443fef34330281333ce/server.jar


RUN echo "eula=true" > eula.txt

EXPOSE 25565

ENTRYPOINT java -Xmx1024M -Xms1024M -jar server.jar nogui

# docker build -t mk .

# docker run --name mk -it -p 25565:25565 mk
