FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y mariadb-server

EXPOSE 3306

COPY entrypoint.sh /usr/local/bin

RUN chmod +x /usr/local/bin/entrypoint.sh

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]