FROM ruby

RUN apt-get update \
	&& apt-get upgrade -y \
	&& apt-get install gems \
	&& apt-get install sqlite3 \
	&& apt-get install nodejs -y \
	&& gem install rails

EXPOSE 3000

ONBUILD COPY app /opt/app
ONBUILD WORKDIR /opt/app

ONBUILD RUN bundle update
ONBUILD RUN bundle install
ONBUILD RUN rake db:migrate
ONBUILD RUN rake db:seed

# build both docker images then do run on ex02
# address will the ip of the docker-machine at
# the specified port
