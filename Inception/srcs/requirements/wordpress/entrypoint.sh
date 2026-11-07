#!/usr/bin/env bash

DB_PASSWORD=$(cat /run/secrets/db_password)
WORDPRESS_ADMIN_PASSWORD=$(cat /run/secrets/wp_admin_password)
WORDPRESS_USER_PASSWORD=$(cat /run/secrets/wp_user_password)

while ! nc -zv mariadb 3306; do
    sleep 2
done

chown -R www-data:www-data /var/www/html

if [ ! -f /var/www/html/index.php ]; then
    su -s /bin/bash www-data -c "wp core download --path=/var/www/html"
fi

if [ ! -f /var/www/html/wp-config.php ]; then
    su -s /bin/bash www-data -c "wp config create --dbname=${WORDPRESS_DB_NAME} \
                                                  --dbuser=${WORDPRESS_DB_USER} \
                                                  --dbpass=${DB_PASSWORD} \
                                                  --dbhost=${WORDPRESS_DB_HOST}"

    su -s /bin/bash www-data -c "wp core install --url=https://ahalifa.42.fr \
                                                 --title=wordpress --admin_user=${WORDPRESS_ADMIN} \
                                                 --admin_password=${WORDPRESS_ADMIN_PASSWORD} \
                                                 --admin_email=${WORDPRESS_MAIL_ADMIN}"
    su -s /bin/bash www-data -c "wp user create ${WORDPRESS_USER} \
                                                ${WORDPRESS_MAIL_USER} \
                                                --user_pass=${WORDPRESS_USER_PASSWORD} \
                                                --role=author"

fi

exec php-fpm8.2 -F