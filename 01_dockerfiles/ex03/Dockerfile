# FROM debian

# RUN apt-get update \
# 	&& apt-get install -y curl openssh-server ca-certificates \
# 	&& apt-get install -y postfix

# # stop the machine and then do the below to improve preformance
# # VBoxManage modifyvm Char --cpus 2
# # VBoxManage modifyvm Char --memory 4096

# FROM ubuntu:16.04
# MAINTAINER GitLab Inc. <support@gitlab.com>

# SHELL ["/bin/sh", "-c"],

# # Default to supporting utf-8
# ENV LANG=C.UTF-8

# # Install required packages
# RUN apt-get update -q && \
# 	apt-get install -yq --no-install-recommends \
# 		ca-certificates \
# 		openssh-server \
# 		wget \
# 		apt-transport-https \
# 		tzdata \
# 	&& rm -rf /var/lib/apt/lists/* \
# 	&& sed 's/session\s*required\s*pam_loginuid.so/session optional pam_loginuid.so/g' -i /etc/pam.d/sshd

# # Remove MOTD
# RUN rm -rf /etc/update-motd.d /etc/motd /etc/motd.dynamic
# RUN ln -fs /dev/null /run/motd.dynamic

# # Copy assets
# COPY RELEASE /
# COPY assets/ /assets/
# RUN /assets/setup

# # Allow to access embedded tools
# ENV PATH /opt/gitlab/embedded/bin:/opt/gitlab/bin:/assets:$PATH

# # Resolve error: TERM environment variable not set.
# ENV TERM xterm

# # Expose web & ssh
# EXPOSE 443 80 22

# # Define data volumes
# VOLUME ["/etc/gitlab", "/var/opt/gitlab", "/var/log/gitlab"] --virtualbox-cpu-count "1"

# # Wrapper to handle signal, trigger runit and reconfigure GitLab
# CMD ["/assets/wrapper"]


FROM debian:8

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends apt-utils && apt-get upgrade -y
RUN apt-get install -y wget openssh-server ca-certificates
RUN apt-get install -y postfix
RUN wget https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh
RUN chmod 777 script.deb.sh
RUN ./script.deb.sh
RUN apt-get update && apt-get install -y gitlab-ce

EXPOSE 443 80 22

ENTRYPOINT (/opt/gitlab/embedded/bin/runsvdir-start &) && gitlab-ctl reconfigure && tail -f /dev/null

# to run you build with a tag then run that tag and it should all work
# I got my sources from https://github.com/bigdiggysquiggle/docker/blob/master/01_dockerfiles/ex03/Dockerfile
# and: https://about.gitlab.com/install/#debian
