FROM debian

MAINTAINER fshanaha <fshanaha@student.21-school.ru>

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install -y locales

RUN locale-gen en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US:en
ENV LC_ALL en_US.UTF-8

RUN apt-get install -y cmatrix

ENTRYPOINT cmatrix

# docker build -t cmatrix .

# docker run --name cmatrix -it cmatrix
