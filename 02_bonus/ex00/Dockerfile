FROM debian

RUN apt-get update
RUN	apt-get upgrade -y
RUN	apt-get install build-essential -y
RUN apt-get install libncurses5-dev libncursesw5-dev -y
# RUN	apt-get install make
# RUN	apt-get install ncurses-libs -y
# RUN	apt-get install ncurses -y

COPY R_type/ ./R_type
WORKDIR ./R_type

RUN make
ENTRYPOINT ./beta_game1
