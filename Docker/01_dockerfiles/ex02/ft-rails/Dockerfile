FROM ruby:2.6.2

MAINTAINER fshanaha <fshanaha@student.21-school.ru>

RUN apt-get update -y
RUN apt-get upgrade -y
RUN gem install rails
RUN apt-get install sqlite3 -y
RUN apt-get install nodejs -y
RUN gem install bundler

ENV RAILS_ENV=development

WORKDIR /opt/app
ONBUILD ADD app /opt/app
ONBUILD RUN bundle install
ONBUILD RUN rails db:migrate
ONBUILD RUN rails db:seed

# docker build -t ft-rails:on-build .
# docker run -it -d -p 3000:3000 --name ruby --volume /Users/fshanaha/Desktop/Docker/01_dockerfiles/ex02/app:/opt/app ruby
#rails s -b 0.0.0.0 -p 3000