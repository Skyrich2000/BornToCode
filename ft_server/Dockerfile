FROM	debian:buster

# install dependencies
ENV DEBIAN_FRONTEND="noninteractive"
RUN apt update \
		&& apt install -y nginx \
						  openssl \
					      php7.3-fpm \
						  mariadb-server \
						  php-mysql \
						  wget \
		&& rm -rf /var/lib/{apt,dpkg,cache,log}

WORKDIR /root

# ssl
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Gam/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt \
		&& mv localhost.dev.crt /etc/ssl/certs/ \
		&& mv localhost.dev.key /etc/ssl/private/ \
		&& chmod 600 /etc/ssl/certs/localhost.dev.crt \
		&& chmod 600 /etc/ssl/private/localhost.dev.key

# nginx
COPY ./srcs/default /root
RUN cp -rp /root/default /etc/nginx/sites-available

# phpMyAdmin
COPY ./srcs/config.inc.php /root
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz \
		&& tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz \
		&& mv phpMyAdmin-5.0.2-all-languages /var/www/html/phpmyadmin \
		&& cp -rp /root/config.inc.php /var/www/html/phpmyadmin/

# DB
RUN service mysql start \
		&& mysql < /var/www/html/phpmyadmin/sql/create_tables.sql -u root --skip-password \
		&& echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root --skip-password \
		&& echo "GRANT ALL PRIVILEGES ON *.* TO 'ycha'@'localhost' IDENTIFIED BY 'qwer' WITH GRANT OPTION" | mysql -u root --skip-password

# Wordpress
COPY ./srcs/wp-config.php /root
RUN wget https://wordpress.org/latest.tar.gz \
		&& tar -xvf latest.tar.gz \
		&& mv wordpress/ /var/www/html/ \
		&& chown -R www-data:www-data /var/www/html/wordpress \
		&& cp -rp /root/wp-config.php /var/www/html/wordpress

COPY ./srcs/entrypoint.sh /root
ENTRYPOINT ["/root/entrypoint.sh"]

EXPOSE 80 443
