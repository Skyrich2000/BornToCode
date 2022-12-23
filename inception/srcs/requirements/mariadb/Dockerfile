FROM debian:buster

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install mariadb-server -y

COPY tools/setup_mariadb.sh /setup_mariadb.sh
COPY ./conf/my.cnf /etc/mysql/my.cnf

ENTRYPOINT ["sh", "./setup_mariadb.sh"]

EXPOSE 3306
