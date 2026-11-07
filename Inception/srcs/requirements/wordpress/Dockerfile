FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y php curl sudo netcat-openbsd
RUN apt-get install -y php-fpm php-mysql 

COPY www.conf /etc/php/8.2/fpm/pool.d/

WORKDIR /var/www/html 

RUN curl -o wp-cli.phar https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp
RUN chown -R www-data:www-data /usr/local/bin/wp
RUN chmod +x /usr/local/bin/wp

COPY entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
