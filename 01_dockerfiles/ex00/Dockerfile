FROM alpine

RUN apk upgrade	&& \
	apk update	&& \
	apk add vim

ENTRYPOINT vim

# makes the container image things, like when you pull
# docker build -t <name> .

# docker run <name>
