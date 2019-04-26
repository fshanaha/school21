FROM ubuntu

MAINTAINER fshanaha <fshanaha@student.21-school.ru>

WORKDIR /home/GLab/

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install -y curl openssh-server ca-certificates apt-transport-https
RUN curl https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh | bash

RUN apt-get install -y gitlab-ce tzdata

RUN echo "external_url \"https://192.168.99.100\"" > /etc/gitlab/gitlab.rb
RUN echo "nginx['redirect_http_to_https'] = true" >> /etc/gitlab/gitlab.rb
RUN echo "nginx['ssl_certificate'] = \"/etc/gitlab/ssl/192.168.99.100.crt\"" >> /etc/gitlab/gitlab.rb

RUN mkdir -p /etc/gitlab/ssl
RUN chmod 700 /etc/gitlab/ssl

RUN openssl req -new -x509 -days 365 -nodes \
            -out /etc/gitlab/ssl/192.168.99.100.crt \
            -keyout /etc/gitlab/ssl/192.168.99.100.key \
            -subj "/C=AU/ST=Some-State/L=Some-city/O=Some-Company/CN=Some-Unit"

EXPOSE 80 443 22

ENTRYPOINT service ssh restart && (/opt/gitlab/embedded/bin/runsvdir-start &) && gitlab-ctl reconfigure && tail -f /dev/null

# docker build -t ex03 .

# docker run --name ex03 -it -p 8080:80 -p 8443:443 -p 8022:22 --privileged ex03
# GIT_SSL_NO_VERIFY=true git clone https://192.168.99.100:8443/root/hello.git
# git clone ssh://git@192.168.99.100:8222/root/hello.git
