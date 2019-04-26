FROM debian

MAINTAINER fshanaha <fshanaha@student.21-school.ru>

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install -y telnet

ENTRYPOINT telnet towel.blinkenlights.nl

# docker build -t sw .

# docker run --name sw -it sw
