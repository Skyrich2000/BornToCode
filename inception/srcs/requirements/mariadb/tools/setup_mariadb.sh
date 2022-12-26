#!/bin/sh
chown -R mysql:mysql /var/lib/mysql

cat /var/lib/mysql/.setup 2> /dev/null

if [ $? -ne 0 ]; then
    service mysql start;

    mysql -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE";
    mysql -e "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD'";
    mysql -e "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%'";
    mysql -e "ALTER USER '$MYSQL_ROOT'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD'; FLUSH PRIVILEGES;"

    mysql $MYSQL_DATABASE -u$MYSQL_ROOT -p$MYSQL_ROOT_PASSWORD
    mysqladmin -u$MYSQL_ROOT -p$MYSQL_ROOT_PASSWORD shutdown

    touch /var/lib/mysql/.setup
fi

exec service mysql start | mysqld
