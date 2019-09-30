FROM debian:9

RUN apt-get update \
	&& apt-get upgrade -y \
	&& apt-get install ruby -y \
	&& apt-get install gems \
	&& gem install oauth2

COPY client.rb client.rb
COPY intra_list.txt intras.txt

ENTRYPOINT ruby client.rb intras.txt

