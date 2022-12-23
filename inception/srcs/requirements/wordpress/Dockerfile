FROM	debian:buster

RUN		apt-get update -y && \
		apt-get install -y mariadb-client php7.3-fpm php-mysql tar wget sudo


COPY	./tools/setup_wordpress.sh /tmp/setup_wordpress.sh
COPY	./conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf

RUN	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
        chmod +x wp-cli.phar && \
        mv wp-cli.phar /usr/bin/wp

WORKDIR	/var/www/html/wordpress
RUN	mkdir -p /run/php

EXPOSE	9000

ENTRYPOINT ["sh", "/tmp/setup_wordpress.sh"]