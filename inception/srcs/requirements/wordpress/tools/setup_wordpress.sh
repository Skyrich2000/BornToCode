#!/bin/sh

sleep 3
chown -R www-data:www-data /var/www/

if [ ! -f "/var/www/html/wordpress/index.php" ]; then
	sudo -u www-data sh -c " \
	wp core download --locale=ko_KR && \
	wp config create --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=mariadb --dbcharset="utf8"
	wp core install --url=localhost --title=inception --admin_user=$MYSQL_ROOT --admin_password=$MYSQL_ROOT_PASSWORD --admin_email=ycha@student.42seoul.kr --skip-email && \
	wp user create ycha ycha@student.42seoul.kr --role=author --user_pass=1234 && \
	wp plugin update --all
	"
	echo "INSTALL DONE!!!"
fi

exec /usr/sbin/php-fpm7.3 -F